#include "entry.h"

entry::entry()
{
    clear();
}

void entry::clear()
{
    identified = 0;
    da.clear();
}

int entry::addline(char *line, int len, int linenum)
{
    int row = linenum % (ENTRY_ROW_NUM_M + 1);
    if(row < ENTRY_ROW_NUM_M)
        return line_to_rows(line, len, row);
    else
        return identify();
}

int entry::line_to_rows(char *line, int len, int row)
{
    rows[row] = line;
    int nPos = rows[row].find('\r',0);
    if (nPos != string::npos)
    {
        rows[row].erase(nPos);
    }
    nPos = rows[row].find('\n',0);
    if (nPos != string::npos)
    {
        rows[row].erase(nPos);
    }
    if(rows[row].size() < ENTRY_COLUM_NUM_M)
    {
        rows[row].append(ENTRY_COLUM_NUM_M - rows[row].size(), ' ');
    }
    return 0;
}

int entry::identify()
{
    rows_to_da();
    da.identify();
    identified = 1;
    return 0;
}

void entry::rows_to_da()
{
    for(int i = 0; i < NUM_OF_DIGITS_IN_THE_ACCOUNT_M; i++)
    {
        string strTemp = 
            string(rows[0], i*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M) + 
            string(rows[1], i*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M) + 
            string(rows[2], i*NUM_OF_COLUM_IN_THE_DIGIT_M, NUM_OF_COLUM_IN_THE_DIGIT_M);

        da.string_to_digits(strTemp,i);
    }
}

int entry::isdone()
{
    return identified;
}

void entry::show()
{
    da.show();
}
