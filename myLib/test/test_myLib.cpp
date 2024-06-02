#include <gtest/gtest.h>

#include <myLib.h>

TEST(myLibTests, Test_ComplexConstructor)
{
	const myLib::Complex c{4, 20};
    const double expected_re = 4;
    const double expected_im = 20;

    ASSERT_EQ(expected_re, c.Re());
    ASSERT_EQ(expected_im, c.Im());
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