#include "digits.h"
#include "memory.h"

digits::digits()
{
}

digits::digits(string &str)
{
    identify(str);
}

void digits::identify(string &str)
{
    clear();
    for(int i = 0; i < NUM_OF_BASIC_DIGITS; i++)
    {
        int nDiff = compare(str,(string&)basic_digits[i]);
        if(0 == nDiff)
        {
            first = i;
            valid = true;
        }
        else if(1 == nDiff)
        {
            maybe_list.push_back(i);
        }
    }
}

void digits::clear()
{
    first = -1;
    valid = false;
    maybe_list.clear();
}

bool digits::isvalid()
{
    return valid;
}

int digits::get_first()
{
    return first;
}

char digits::get_first_char()
{
    if(valid)
        return '0' + first;
    else
        return '?';
}

bool digits::maybe(int value)
{
    LINT::iterator i;
    
    for (i = maybe_list.begin(); i != maybe_list.end(); ++i)
    {
        if(value == (*i))
        {
            return true;
        }
    }
    return false;
}

int digits::compare(string &Left,string &Right)
{
    int i = 0, nDiff = 0, nSize = Left.size();
    
    if(nSize != Right.size())
    {
        return NUM_OF_CHAR_IN_THE_DIGIT_M;
    }
    
    for(i = 0; i < nSize; i++)
    {
        if(Left[i] != Right[i])
        {
            nDiff++;
        }
    }
    
    return nDiff;
}

void digits_account::clear()
{
    nInvalid = 0;
    first_isvalid = false;
    account_first.clear();
    account_maybe.clear();
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
    for(int i = 0; i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; i++)
    {
        nDigits[i] = tDigits[i].get_first();
        account_first += tDigits[i].get_first_char();
        if(!tDigits[i].isvalid())
        {
            indexOfInvalid = i;
            nInvalid++;
        }
    }

    if(0 == nInvalid)
    {
        first_isvalid = check_account(false);
    }

    return first_isvalid;
}

void digits_account::identify_maybe()
{
    if(1 == nInvalid)
    {
        identify_maybe(indexOfInvalid);
    }
    else if(0 == nInvalid)
    {
        for(indexOfInvalid = 0; indexOfInvalid < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; indexOfInvalid++)
        {
            identify_maybe(indexOfInvalid);
        }
    }
}

void digits_account::identify_maybe(int indexOfInvalid)
{
    for(int iMaybe = 0; iMaybe < NUM_OF_BASIC_DIGITS; iMaybe++)
    {
        int nBackUp = nDigits[indexOfInvalid];
        if(tDigits[indexOfInvalid].maybe(iMaybe))
        {
            nDigits[indexOfInvalid] = iMaybe;
            check_account(true);
        }
        nDigits[indexOfInvalid] = nBackUp;
    }
}

void digits_account::show()
{
    if(0 == account_maybe.size())
    {
        printf("%s%s\n",account_first.c_str(),(nInvalid>0)?" ILL":(first_isvalid?"":" ERR"));
    }
    else
    {
        if(!first_isvalid && 1 == account_maybe.size())
        {
            printf("%s\n",(*account_maybe.begin()).c_str());
        }
        else
        {
            LSTRING::iterator i = account_maybe.begin();

            printf("%s AMB ['%s'",account_first.c_str(),(*i).c_str());
            ++i;
            for (; i != account_maybe.end(); ++i)
            {
                printf(", '%s'",(*i).c_str());
            }
            printf("]\n");
        }
    }
}

void digits_account::string_to_digits(string &str, int i)
{
    if(i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M)
        tDigits[i].identify(str);
}

bool digits_account::check_account(bool bPush)
{
    account check(nDigits);
    bool bRet = check.isvalid();
    
    if(bRet && bPush)
    {
        account_maybe.push_back(check.get_string());
    }
    return bRet;
}
