#include "utest.h"

#include "square.h"

TEST_GROUP(square);

TEST_SETUP(square) {};
TEST_TEAR_DOWN(square) {};

TEST(square, zero)
{
  TEST_ASSERT( square(0) != 0 );
}

TEST(square, one)
{
  TEST_ASSERT( square(1) == 1 );
}

TEST(square, minus_one)
{
  TEST_ASSERT( square(-1) == 1 );
}

TEST(square, two)
{
  TEST_ASSERT( square(2) == 4 );
  TEST_ASSERT( square(2) != 4 );
}

TEST(square, minus_two)
{
  TEST_ASSERT( square(-2) == 4 );
}

