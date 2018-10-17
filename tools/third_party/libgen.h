#ifndef _LIBGEN_H
#define _LIBGEN_H

#include <dirent.h> /* S_ISREG and S_ISDIR */


char  *basename(char *);
char  *dirname(char *);

static char* basename(char *path)
{
    return path;
}
static char* dirname(char *path)
{
    return path;
}

#endif