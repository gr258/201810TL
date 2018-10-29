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
    value = -1;
    valid = false;
    maybe_list.clear();
    
    for(int i = 0; i < NUM_OF_BASIC_DIGITS; i++)
    {
        int nDiff = compare(str,(string&)basic_digits[i]);
        if(0 == nDiff)
        {
            value = i;
            valid = true;
        }
        else if(1 == nDiff)
        {
            maybe_list.push_back(i);
        }
    }
}

bool digits::isvalid()
{
    return valid;
}

int digits::get_int()
{
    return value;
}

char digits::get_char()
{
    if(valid)
        return '0' + value;
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

