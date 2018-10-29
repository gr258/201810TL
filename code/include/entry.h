#ifndef INCLUDE_ENTRY_H
#define INCLUDE_ENTRY_H

#include <string>
#include "digits_account.h"

using namespace std;

#define ENTRY_ROW_NUM_M         (NUM_OF_ROW_IN_THE_DIGIT_M)
#define ENTRY_COLUM_NUM_M       (NUM_OF_COLUM_IN_THE_DIGIT_M*NUM_OF_DIGITS_IN_THE_ACCOUNT_M)

class entry
{
public:
    entry();
    int             addline(char *line, int len, int linenum);
    int             isdone();
    void            clear();
    void            show();

private:
    int             identify();
    int             line_to_rows(char *line, int len, int row);
    
    int             identified;
    string          rows[NUM_OF_ROW_IN_THE_DIGIT_M];
    digits_account  da;
};

#endif
