
#include <stdio.h>
#include "csm.h"

int
string_length (str)
    int str;
{
    return strlen (StringTable (str));
}

void
OutStr (fp, str)
    FILE *fp;
    int str;
{
    fprintf (fp, "%s", StringTable (str));
}

void
OutPStr (fp, str, pad)
    FILE *fp;
    int str, pad;
{
    fprintf (fp, "%-*s", pad, StringTable (str));
}

void
OutPSStr (fp, str, space, tail, pad)
    FILE *fp;
    int str, pad;
    char *space, *tail;
{
    char buf[BUFSIZ];

    sprintf (buf, "%s%s%s", StringTable (str), space, tail);
    fprintf (fp, "%-*s", pad, buf);
}

void
mkstr_nodelims (c, l, t, p)
    char *c;
    int l, *t;
    char *p;
{
    *(int *)p = stostr (c+1, l-2);
}
