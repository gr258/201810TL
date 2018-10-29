#include "entry.h"

entry::entry()
{
    clear();
}

void entry::clear()
{
    identified = 0;
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
    da.init(rows);
    da.identify();
    identified = 1;
    return 0;
}

int entry::isdone()
{
    return identified;
}

void entry::show()
{
    da.show();
}

