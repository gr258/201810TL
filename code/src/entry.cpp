#include <memory.h>
#include "entry.h"
#include "digits.h"

entry::entry()
{
    clear();
}

void entry::clear()
{
    identified = 0;
    nInvalid = 0;
    first_isvalid = false;
    account_first.clear();
    account_maybe.clear();
}

int entry::addline(char *line, int len, int linenum)
{
    int raw = linenum % (ENTRY_RAW_NUM_M + 1);

    if(raw < ENTRY_RAW_NUM_M)
    {
        return addraw(line, len, raw);
    }
    else
    {
        return identify();
    }
}

int entry::addraw(char *line, int len, int raw)
{
    if(len < ENTRY_COLUM_NUM_M)
    {
        return 1;
    }
    string_raw[raw] = line;
    return 0;
}

int entry::identify()
{
    digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M];
    get_account_digits(account_digits);
    get_account_first(account_digits);
    get_account_maybe(account_digits);
    identified = 1;
    return 0;
}

void entry::get_digits(int index, digits &account_digits)
{
    string digits_string;
    
    digits_string = string(string_raw[0], index*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M) + 
            string(string_raw[1], index*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M) + 
            string(string_raw[2], index*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M);

    account_digits.identify(digits_string);
}

void entry::get_account_digits(digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M])
{
    for(int i = 0; i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; i++)
    {
        get_digits(i,account_digits[i]);
    }
}

void entry::get_account_first(digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M])
{
}

void entry::get_account_maybe(digits account_digits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M])
{
    int nDigits[NUM_OF_DIGITS_IN_THE_ACCOUNT_M] = {0};
    int indexOfInvalid = 0;

    for(int i = 0; i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; i++)
    {
        if(account_digits[i].isvalid())
        {
            account_first += '0' + account_digits[i].get_first();
            nDigits[i] = account_digits[i].get_first();
        }
        else
        {
            account_first += '?';
            indexOfInvalid = i;
            nInvalid++;
        }
    }

    if(1 == nInvalid)
    {
        for(int i = 0; i <= 9; i++)
        {
            int nTemp = nDigits[indexOfInvalid];
            
            if(account_digits[indexOfInvalid].maybe(i))
            {
                nDigits[indexOfInvalid] = i;
                account a(nDigits);
                if(a.isvalid())
                {
                    account_maybe.push_back(a.get_string());
                }
            }
            nDigits[indexOfInvalid] = nTemp;
        }
    }
    else if(0 == nInvalid)
    {
        account first(nDigits);
        if(first.isvalid())
        {
            first_isvalid = true;
        }
        else
        {
            for(indexOfInvalid = 0; indexOfInvalid < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; indexOfInvalid++)
            {
                for(int i = 0; i <= 9; i++)
                {
                    int nTemp = nDigits[indexOfInvalid];
                    
                    if(account_digits[indexOfInvalid].maybe(i))
                    {
                        nDigits[indexOfInvalid] = i;
                        account a(nDigits);
                        if(a.isvalid())
                        {
                            account_maybe.push_back(a.get_string());
                        }
                    }
                    nDigits[indexOfInvalid] = nTemp;
                }
            }
        }
    }
}

int entry::isdone()
{
    return identified;
}

void entry::show()
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


