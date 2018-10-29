#ifndef INCLUDE_DIGITS_H
#define INCLUDE_DIGITS_H

#include <string>
#include <list>
#include "account.h"

using namespace std;

#define NUM_OF_ROW_IN_THE_DIGIT_M       3
#define NUM_OF_COLUM_IN_THE_DIGIT_M     3
#define NUM_OF_CHAR_IN_THE_DIGIT_M      (NUM_OF_ROW_IN_THE_DIGIT_M*NUM_OF_COLUM_IN_THE_DIGIT_M)
#define NUM_OF_BASIC_DIGITS             10

typedef list<int> LINT;

class digits
{
public:
    digits();
    digits(string &str);
    void    identify(string &str);
    bool    isvalid();
    int     get_int();
    char    get_char();
    bool    maybe(int value);

private:
    int     compare(string &Left,string &Right);
    int     value;
    int     valid;
    LINT    maybe_list;
    const string basic_digits[NUM_OF_BASIC_DIGITS] = {
        {   " _ "
            "| |"
            "|_|"},
        
        {   "   "
            "  |"
            "  |"},
        
        {   " _ "
            " _|"
            "|_ "},
        
        {   " _ "
            " _|"
            " _|"},
        
        {   "   "
            "|_|"
            "  |"},
        
        {   " _ "
            "|_ "
            " _|"},
        
        {   " _ "
            "|_ "
            "|_|"},
        
        {   " _ "
            "  |"
            "  |"},
        
        {   " _ "
            "|_|"
            "|_|"},
        
        {   " _ "
            "|_|"
            " _|"},
    };
};

#endif

