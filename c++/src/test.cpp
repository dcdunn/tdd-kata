#include "gmock/gmock.h"
#include "Soundex.h"

using namespace testing;

class soundex_encoding  : public Test
{
public:
  Soundex soundex;
};

TEST_F(soundex_encoding, zero_pads_word)
{
  auto encoded = soundex.encode("A");
  ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(soundex_encoding, skips_vowels)
{
  ASSERT_THAT(soundex.encode("Ba"), Eq("B000"));
}

TEST_F(soundex_encoding, skips_duplicates)
{
  ASSERT_THAT(soundex.encode("Abc"), Eq("A120"));
}

class ConsonantTest:
  public testing::TestWithParam<std::tuple<const char*, const char*>>
{
public:
  Soundex soundex;
  std::string in;
  std::string out;

  void SetUp()
  {
    std::tie(in, out) = GetParam();
  }
};

TEST_P(ConsonantTest, fred)
{
  ASSERT_THAT(soundex.encode(in), Eq(out));
}

INSTANTIATE_TEST_SUITE_P(BLike, ConsonantTest,
  Combine(Values("Ab", "Af", "Ap", "Av"), Values("A100")));

INSTANTIATE_TEST_SUITE_P(CLike, ConsonantTest,
  Combine(Values("Ac", "Ag", "Aj", "Ak", "Aq", "As", "Ax", "Az"), Values("A200")));

INSTANTIATE_TEST_SUITE_P(DLike, ConsonantTest,
  Combine(Values("Ad", "At"), Values("A300")));

INSTANTIATE_TEST_SUITE_P(LLike, ConsonantTest,
  Values(std::make_tuple("Al", "A400")));

INSTANTIATE_TEST_SUITE_P(MLike, ConsonantTest,
  Combine(Values("Am", "An"), Values("A500")));

INSTANTIATE_TEST_SUITE_P(RLike, ConsonantTest,
  Values(std::make_tuple("Ar", "A600")));
