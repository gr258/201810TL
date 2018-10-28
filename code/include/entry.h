#ifndef INCLUDE_ENTRY_H
#define INCLUDE_ENTRY_H

#include <stdio.h>
#include <list>
#include <string>
#include <digits.h>
#include "account.h"

using namespace std;

typedef list<string> LSTRING;

#define ENTRY_RAW_NUM_M         (NUM_OF_RAW_IN_THE_DIGIT_M)
#define ENTRY_COLUM_NUM_M       (NUM_OF_COLUM_IN_THE_DIGIT_M*NUM_OF_DIGITS_IN_THE_ACCOUNT_M)

class entry
{
public:
    entry();
    int         addline(char *line, int len, int linenum);
    int         isdone();
    void        clear();
    void        show();

private:
    int         addraw(char *line, int len, int raw);
    int         identify();
    void        get_digits(int index, digits &account_digits);
    void        get_account_digits(digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M]);
    void        get_account_first(digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M]);
    void        get_account_maybe(digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M]);
    
    int         identified;
    string      string_raw[NUM_OF_RAW_IN_THE_DIGIT_M];
    string      account_first;
    bool        first_isvalid;
    LSTRING     account_maybe;
};

#endif
