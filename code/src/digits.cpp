#include "digits.h"

digits::digits()
{
    clear();
}

digits::digits(string &str)
{
    clear();
    identify(str);
}

void digits::identify(string &str)
{
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

