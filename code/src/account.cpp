#include "account.h"

account::account(int v[NUM_OF_DIGITS_IN_THE_ACCOUNT_M])
{
    checksum = 0;
    account_str.clear();
    
    for(int i = 0; i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; i++)
    {
        account_str  += '0' + v[i];
        checksum = checksum + v[i]*(NUM_OF_DIGITS_IN_THE_ACCOUNT_M - i);
    }
    checksum = checksum % 11;
}

bool account::isvalid()
{
    return (checksum == 0);
}

string &account::get_string()
{
    return account_str;
}
