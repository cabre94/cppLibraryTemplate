#include <gtest/gtest.h>

#include "myLib.h"

TEST(myLibTests, TestIntegerOne_One)
{
    const auto expected = 1;
    const auto actual = multiply(1, 1);
    ASSERT_EQ(expected, actual);
}

TEST(myLibTests, TestIntegerZero_Zero)
{
    const auto expected = 0;
    const auto actual = multiply(0, 0);
    ASSERT_EQ(expected, actual);
}

TEST(myLibTests, TestIntegerZero_One)
{
    const auto expected = 0;
    const auto actual = multiply(0, 1);
    ASSERT_EQ(actual, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();	// TODO: check if neccesary
}