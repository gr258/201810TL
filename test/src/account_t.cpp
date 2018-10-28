#include "gtest/gtest.h"
#include "account.h"

TEST(ACCOUNT,GIVEN_DIGITS_WHEN_CHECKSUM_EQUL_0_THEN_ACCOUNT_IS_VALID)
{
    int d1[] = {3,4,5,8,8,2,8,6,5};
    int d2[] = {7,1,1,1,1,1,1,1,1};
    int d3[] = {7,7,7,7,7,7,1,7,7};
    
    account a1(d1);
    EXPECT_EQ(true,a1.isvalid());

    account a2(d2);
    EXPECT_EQ(true,a2.isvalid());

    account a3(d3);
    EXPECT_EQ(true,a3.isvalid());
}

TEST(ACCOUNT,GIVEN_DIGITS_WHEN_CHECKSUM_NOT_EQUL_0_THEN_ACCOUNT_IS_INVALID)
{
    int d1[] = {8,8,8,8,8,8,8,8,8};
    int d2[] = {5,5,5,5,5,5,5,5,5};
    int d3[] = {6,6,6,6,6,6,6,6,6};
    
    account a1(d1);
    EXPECT_NE(true,a1.isvalid());

    account a2(d2);
    EXPECT_NE(true,a2.isvalid());

    account a3(d3);
    EXPECT_NE(true,a3.isvalid());
}

