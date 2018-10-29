#include "digits_account.h"

void digits_account::init(string rows[NUM_OF_ROW_IN_THE_DIGIT_M])
{
    nInvalid = 0;
    account_list.clear();
    for(int i = 0; i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; i++)
    {
        string str = 
            string(rows[0], i*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M) + 
            string(rows[1], i*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M) + 
            string(rows[2], i*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M);

        tDigits[i].identify(str);
        nDigits[i] = tDigits[i].get_int();
        sDigits[i] = tDigits[i].get_char();
        if(!tDigits[i].isvalid())
        {
            posOfInvalid = i;
            nInvalid++;
        }
    }
    sDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M] = 0;
}

void digits_account::identify()
{
    if(!identify_first())
    {
        identify_maybe();
    }
}

bool digits_account::identify_first()
{
    if(0 == nInvalid)
    {
        return add_account();
    }

    return false;
}

void digits_account::identify_maybe()
{
    if(1 == nInvalid)
    {
        guess_by_pos(posOfInvalid);
    }
    else if(0 == nInvalid)
    {
        for(posOfInvalid = 0; posOfInvalid < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; posOfInvalid++)
        {
            guess_by_pos(posOfInvalid);
        }
    }
}

void digits_account::guess_by_pos(int posOfInvalid)
{
    bool bRet = false;
    for(int iMaybe = 0; iMaybe < NUM_OF_BASIC_DIGITS; iMaybe++)
    {
        if(pos_maybe(posOfInvalid,iMaybe))
            break;
    }
}

bool digits_account::add_account()
{
    account check(nDigits);
    bool bRet = check.isvalid();
    if(bRet)
    {
        account_list.push_back(check.get_string());
    }
    return bRet;
}

bool digits_account::pos_maybe(int posOfInvalid, int iMaybe)
{
    if(!tDigits[posOfInvalid].maybe(iMaybe))
        return false;

    int nBackUp = nDigits[posOfInvalid];
    nDigits[posOfInvalid] = iMaybe;
    bool bRet = add_account();
    nDigits[posOfInvalid] = nBackUp;
    return bRet;
}

void digits_account::show()
{
    int nSize = account_list.size();
    if(nSize == 0)
    {
        printf("%s%s\n",sDigits,(nInvalid>0)?" ILL":" ERR");
    }
    else if(nSize == 1)
    {
        printf("%s\n",(*account_list.begin()).c_str());
    }
    else if(nSize > 1)
    {
        LSTRING::iterator i = account_list.begin();
        printf("%s AMB ['%s'",sDigits,(*i).c_str());
        for (++i; i != account_list.end(); ++i)
        {
            printf(", '%s'",(*i).c_str());
        }
        printf("]\n");
    }
}

