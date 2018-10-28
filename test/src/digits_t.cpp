#include "gtest/gtest.h"
#include "digits.h"

TEST(DIGITS,GIVEN_STRNG_WHEN_VALID_THEN_RETURN_VALID)
{
    string str( " _ "
                "| |"
                "|_|");

    digits d(str);
    EXPECT_EQ(true,d.isvalid());
}

TEST(DIGITS,GIVEN_STRNG_WHEN_INVALID_THEN_RETURN_INVALID)
{
    string str( "   "
                "| |"
                "|_|");

    digits d(str);
    EXPECT_NE(true,d.isvalid());
}


TEST(DIGITS,GIVEN_STRNG_0_WHEN_COMPARE_WITH_INT_0_THEN_EQUAL)
{
    string str( " _ "
                "| |"
                "|_|");

    digits d(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(0,d.get_first());
}

TEST(DIGITS,GIVEN_STRNG_1_WHEN_COMPARE_WITH_INT_1_THEN_EQUAL)
{
    string str( "   "
                "  |"
                "  |");

    digits d(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(1,d.get_first());
}

TEST(DIGITS,GIVEN_STRNG_2_WHEN_COMPARE_WITH_INT_1_THEN_NOT_EQUAL)
{
    string str( " _ "
                " _|"
                "|_ ");

    digits d(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_NE(1,d.get_first());
}

TEST(DIGITS,GIVEN_STRNG_9_WHEN_COMPARE_WITH_INT_8_THEN_MAYBE_TRUE)
{
    string str( " _ "
                "|_|"
                " _|");

    digits d(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(9,d.get_first());
    EXPECT_EQ(true,d.maybe(8));
}

TEST(DIGITS,GIVEN_STRNG_0_WHEN_COMPARE_WITH_INT_8_THEN_MAYBE_TRUE)
{
    string str( " _ "
                "| |"
                "|_|");

    digits d(str);
    d.identify(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(0,d.get_first());
    EXPECT_EQ(true,d.maybe(8));
}

TEST(DIGITS,GIVEN_STRNG_1_WHEN_COMPARE_WITH_INT_7_THEN_MAYBE_TRUE)
{
    string str( "   "
                "  |"
                "  |");

    digits d(str);
    d.identify(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(1,d.get_first());
    EXPECT_EQ(true,d.maybe(7));
}

TEST(DIGITS,GIVEN_STRNG_5_WHEN_COMPARE_WITH_INT_9_OR_6_THEN_MAYBE_TRUE)
{
    string str( " _ "
                "|_ "
                " _|");

    digits d(str);
    d.identify(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(5,d.get_first());
    EXPECT_EQ(true,d.maybe(9));
    EXPECT_EQ(true,d.maybe(6));
}

TEST(DIGITS,GIVEN_STRNG_9_WHEN_COMPARE_WITH_INT_7_THEN_MAYBE_FALSE)
{
    string str( " _ "
                "|_|"
                " _|");

    digits d(str);
    EXPECT_EQ(true,d.isvalid());
    EXPECT_EQ(9,d.get_first());
    EXPECT_NE(true,d.maybe(7));
}

TEST(DIGITS,GIVEN_STRNG_INVALID_WHEN_COMPARE_WITH_INT_2_OR_3_THEN_MAYBE_TRUE)
{
    string str( " _ "
                " _|"
                " _ ");

    digits d(str);
    EXPECT_NE(true,d.isvalid());
    EXPECT_EQ(true,d.maybe(2));
    EXPECT_EQ(true,d.maybe(3));
}

TEST(DIGITS,GIVEN_STRNG_ILLEGAL_WHEN_COMPARE_WITH_INT_0_TO_9_THEN_MAYBE_NONE)
{
    string str( " _ "
                " _ "
                " _ ");

    digits d(str);
    EXPECT_NE(true,d.isvalid());
    EXPECT_NE(true,d.maybe(0));
    EXPECT_NE(true,d.maybe(1));
    EXPECT_NE(true,d.maybe(2));
    EXPECT_NE(true,d.maybe(3));
    EXPECT_NE(true,d.maybe(4));
    EXPECT_NE(true,d.maybe(5));
    EXPECT_NE(true,d.maybe(6));
    EXPECT_NE(true,d.maybe(7));
    EXPECT_NE(true,d.maybe(8));
    EXPECT_NE(true,d.maybe(9));
}


