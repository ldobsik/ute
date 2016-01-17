#include "utest.h"

#include "cube.h"

TEST_GROUP(cube);

TEST_SETUP(cube) {};
TEST_TEAR_DOWN(cube) {};

TEST(cube, zero)
{
  TEST_ASSERT( cube(0) == 0 );
}

TEST(cube, one)
{
  TEST_ASSERT( cube(1) == 1 );
}

TEST(cube, minus_one)
{
  TEST_ASSERT( cube(-1) == -1 );
}

TEST(cube, two)
{
  TEST_ASSERT( cube(2) == 8 );
}

TEST(cube, minus_two)
{
  TEST_ASSERT( cube(-2) == -8 );
}

