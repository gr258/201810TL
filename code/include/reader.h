#ifndef INCLUDE_READER_H
#define INCLUDE_READER_H

#include "entry.h"
#include <list>

using namespace std;

typedef list<entry> LENTRY;

class reader
{
public:
    reader(char *filename);
    ~reader();
    int         addline(char *line, int len, int linenum);
    void        show();
private:
    LENTRY      entry_lst;
    entry       entry_cur;
};

#endif

