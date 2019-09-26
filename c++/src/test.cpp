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

TEST_F(soundex_encoding, encodes_consonants)
{
  ASSERT_THAT(soundex.encode("Ab"), Eq("A100"));
  ASSERT_THAT(soundex.encode("Ac"), Eq("A200"));
  ASSERT_THAT(soundex.encode("Ad"), Eq("A300"));
}

TEST_F(soundex_encoding, skips_vowels)
{
  ASSERT_THAT(soundex.encode("Ba"), Eq("B000"));
}

TEST_F(soundex_encoding, skips_duplicates)
{
  ASSERT_THAT(soundex.encode("Abc"), Eq("A120"));
}