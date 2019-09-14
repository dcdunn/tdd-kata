#include "gmock/gmock.h"

TEST(first_test, does_nothing)
{
  ASSERT_THAT(2 + 1, testing::Eq(3));
}
