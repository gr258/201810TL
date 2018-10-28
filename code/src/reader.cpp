#include "reader.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>

reader::reader(char *filename)
{
    entry_lst.clear();
    entry_cur.clear();
    
    FILE *fp = fopen(filename, "r");
	if (fp == NULL)
    {
        printf("fopen %s fail!\n",filename);
        return ;
    }

    int read = 0, linenum = 0;
    size_t len = 0;
    char *line = NULL;
	while ((read = getline(&line, &len, fp)) != -1)
	{
	    if(addline(line,read,linenum))
        {
            printf("line %d error!\n",linenum);
            break;
        }
		linenum++;
	}

	if (line)
		free(line);

    fclose(fp);
}

reader::~reader()
{
    entry_lst.clear();
}

int reader::addline(char *line, int len, int linenum)
{
    int ret = entry_cur.addline(line, len, linenum);

    if(entry_cur.isdone())
    {
        entry_lst.push_back(entry_cur);
        entry_cur.clear();
    }

    return ret;
}

void reader::show()
{
    LENTRY::iterator i;
    
    for (i = entry_lst.begin(); i != entry_lst.end(); ++i)
    {
        (*i).show();
    }
}

