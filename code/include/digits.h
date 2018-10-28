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
typedef list<string> LSTRING;

class digits
{
public:
    digits();
    digits(string &str);
    void    identify(string &str);
    bool    isvalid();
    int     get_first();
    char    get_first_char();
    bool    maybe(int value);

private:
    void    clear();
    int     compare(string &Left,string &Right);
    int     first;
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

class digits_account
{
public:
    void        identify();
    void        show();
    void        clear();
    void        string_to_digits(string &str, int i);

private:
    bool        identify_first();
    void        identify_maybe();
    void        identify_maybe(int indexOfInvalid);
    bool        check_account(bool bPush);

    digits      tDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M];    
    int         nDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M];
    int         nInvalid;
    int         indexOfInvalid;
    bool        first_isvalid;
    string      account_first;
    LSTRING     account_maybe;
};

#endif

