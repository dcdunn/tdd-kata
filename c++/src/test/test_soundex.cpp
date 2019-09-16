#include "gmock/gmock.h"
#include "../soundex/Soundex.h"

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
  ASSERT_THAT(soundex.encode("Bac"), Eq("B200"));
}

TEST_F(soundex_encoding, encodes_multiple_consonants)
{
  ASSERT_THAT(soundex.encode("Abc"), Eq("A120"));
  ASSERT_THAT(soundex.encode("Abcd"), Eq("A123"));
}

TEST_F(soundex_encoding, ignores_case)
{
  ASSERT_THAT(soundex.encode("aBC"), Eq("A120"));
  ASSERT_THAT(soundex.encode("aBcD"), Eq("A123"));
}

TEST_F(soundex_encoding, skips_duplicates)
{
  ASSERT_THAT(soundex.encode("Abb"), Eq("A100"));
  ASSERT_THAT(soundex.encode("Abaeiouyb"), Eq("A110"));
  ASSERT_THAT(soundex.encode("Abwhb"), Eq("A100"));
}

TEST_F(soundex_encoding, skips_duplicates_of_first_letter)
{
  ASSERT_THAT(soundex.encode("Bbb"), Eq("B000"));
  ASSERT_THAT(soundex.encode("Baeiouybb"), Eq("B100"));
  ASSERT_THAT(soundex.encode("Bwhbb"), Eq("B000"));
}

TEST_F(soundex_encoding, stops_after_three_digits)
{
  ASSERT_THAT(soundex.encode("Abcdbcdb"), Eq("A123"));
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
