#include <gtest/gtest.h>

#include "Complex.h"

TEST(myLibTests, Test_ComplexConstructor)
{
	const myLib::Complex c{4, 20};
    const double expected_re = 4;
    const double expected_im = 20;

    ASSERT_DOUBLE_EQ(expected_re, c.Re());
    ASSERT_DOUBLE_EQ(expected_im, c.Im());
}

TEST(myLibTests, Test_ComplexBasicOperations)
{
	const myLib::Complex c1{4.20, 20.4};
	const myLib::Complex c2{3, 4};

	const myLib::Complex c_sum = c1 + c2;
    ASSERT_DOUBLE_EQ(7.20, c_sum.Re());
    ASSERT_DOUBLE_EQ(24.4, c_sum.Im());

	const myLib::Complex c_sub = c2 - c1;
	// ASSERT_EQ(-1.20, c_sub.Re());
    // ASSERT_EQ(-16, c_sub.Im());

	ASSERT_DOUBLE_EQ(-1.20, c_sub.Re());
    ASSERT_DOUBLE_EQ(-16.4, c_sub.Im());
}

TEST(myLibTests, TestIntegerOne_One)
{
    const auto expected = 1;
    const auto actual = myLib::multiply(1, 1);
    ASSERT_EQ(expected, actual);
}

TEST(myLibTests, TestIntegerZero_Zero)
{
    const auto expected = 0;
    const auto actual = myLib::multiply(0, 0);
    ASSERT_EQ(expected, actual);
}

TEST(myLibTests, TestIntegerZero_One)
{
    const auto expected = 0;
    const auto actual = myLib::multiply(0, 1);
    ASSERT_EQ(actual, expected);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();	// TODO: check if neccesary
}