#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int vasprintf(char **strp, const char *fmt, va_list ap)
{
    int r = -1, size;

    va_list ap2;
    va_copy(ap2, ap);

    size = vsnprintf(0, 0, fmt, ap2);

    if ((size >= 0) && (size < INT_MAX))
    {
        *strp = (char *)malloc(size+1);
        if (*strp)
        {
            r = vsnprintf(*strp, size+1, fmt, ap);
            if ((r < 0) || (r > size))
            {
                free(*strp);
                *strp = 0;
                r = -1;
            }
        }
    }
    else
    {
        *strp = 0;
    }

    va_end(ap2);

    return(r);
}

int asprintf(char **strp, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int r = vasprintf(strp, fmt, ap);
    va_end(ap);
    return r;
}
