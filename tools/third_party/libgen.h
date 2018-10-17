#ifndef _LIBGEN_H
#define _LIBGEN_H

#include <dirent.h> /* S_ISREG and S_ISDIR */


char  *basename(char *);
char  *dirname(char *);

static char *basename(char *str)
{
    char *p;
	size_t len = strlen(str);
    
	/* skip leading slash.  Case is /usr/, /usr/tst/ is fine */
	if (len > 1) {
		if ((*str == '\\') || (*str == '/')) {
			str += 1;
			len--;
		}
	}

	p = str + len - 1;
	if (len > 1) {
		if ((*p == '\\') || (*p == '/')) {
			if (*(p - 1) == ':')
				return str;
			*p = '\0';
			p--;
		}
	}

	for (; str < p; p--) {
		if ((*p == '\\') || (*p == '/')) {
			p++;
			break;
		}
	}

	return p;
}

static char* dirname(char *path)
{
    return path;
}

#endif