#ifndef INCLUDE_DIGITS_ACCOUNT_H
#define INCLUDE_DIGITS_ACCOUNT_H

#include "digits.h"

typedef list<string> LSTRING;

class digits_account
{
public:
    void        init(string rows[NUM_OF_ROW_IN_THE_DIGIT_M]);
    void        identify();
    void        show();

private:
    bool        identify_first();
    void        identify_maybe();
    bool        add_account();
    void        guess_by_pos(int posOfInvalid);
    bool        pos_maybe(int posOfInvalid, int iMaybe);

    digits      tDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M];    
    int         nDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M];
    char        sDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M+1];
    int         nInvalid;
    int         posOfInvalid;
    LSTRING     account_list;
};

#endif
