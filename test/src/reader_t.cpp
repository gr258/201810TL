#include "gtest/gtest.h"
#include "reader.h"

TEST(READER,GIVEN_ONE_ENTRY_WITHOUT_ERROR_WHEN_READ_THEN_IDENTIFY_IS_OK)
{
    reader r((char*)"../test/file/entry_without_error_read_ok.txt");

    r.show();
}

TEST(READER,GIVEN_ONE_ENTRY_WITH_ERROR_WHEN_READ_THEN_IDENTIFY_IS_OK)
{
    reader r((char*)"../test/file/entry_with_error_read_ok.txt");

    r.show();
}

TEST(READER,GIVEN_ONE_ENTRY_WITHOUT_ERROR_WHEN_READ_THEN_IDENTIFY_IS_MAYBE)
{
    reader r((char*)"../test/file/entry_without_error_read_maybe.txt");

    r.show();
}

//当出错位置确定时，根据checksum算法，仅存在一个有效检验和，此用例无效
//TEST(READER,GIVEN_ONE_ENTRY_WITH_ERROR_WHEN_READ_THEN_IDENTIFY_IS_MAYBE)
//{
//    reader r((char*)"../test/file/entry_with_error_read_maybe.txt");
//
//    r.show();
//}

//
//TEST(READER,GIVEN_ONE_ENTRY_WITHOUT_ERROR_WHEN_READ_THEN_IDENTIFY_IS_ERROR)
//{
//    reader r((char*)"../test/file/entry_without_error_read_error.txt");
//
//    r.show();
//}

TEST(READER,GIVEN_ONE_ENTRY_WITH_ERROR_WHEN_READ_THEN_IDENTIFY_IS_ILLEGAL)
{
    reader r((char*)"../test/file/entry_without_error_read_illegal.txt");

    r.show();
}

TEST(READER,GIVEN_MORE_ENTRY_WHEN_READ_THEN_IDENTIFY_IS_VALID)
{
    reader r((char*)"../test/file/example_all.txt");

    r.show();
}


