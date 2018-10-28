#ifndef INCLUDE_ACCOUNT_H
#define INCLUDE_ACCOUNT_H

#include <list>
#include <string>

using namespace std;

#define NUM_OF_DIGITS_IN_THE_ACCOUNT_M      9

class account
{
public:
    account(int v[NUM_OF_DIGITS_IN_THE_ACCOUNT_M]);
    bool        isvalid();
    string      &get_string();
private:
    string      account_str;
    int         checksum;
};

#endif

