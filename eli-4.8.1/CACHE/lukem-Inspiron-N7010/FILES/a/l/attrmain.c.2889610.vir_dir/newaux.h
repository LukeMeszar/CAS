
#ifndef NEWAUX_H
#define NEWAUX_H

#include <stdio.h>
#include <string.h>
#include "eliproto.h"

#ifdef PROTO_OK
#define _ANSI_ARGS_(x) x
#else
#define _ANSI_ARGS_(x) ()
#endif

#define MAX(a,b) ((a)>(b)?(a):(b))

typedef char *cstr;

/*
 * string_length
 * Return the length of a string table string.
 */

extern int string_length _ANSI_ARGS_((int str));

/*
 * OutStr
 * Output a string table string (for PTG).
 */

extern void OutStr _ANSI_ARGS_((FILE *fp, int str));

/*
 * OutPStr
 * Output a string table string with a particular padding (for PTG).
 */

extern void OutPStr _ANSI_ARGS_((FILE *fp, int str, int pad));

/*
 * OutPSStr
 * Output a string table string with tail with a particular padding (for PTG).
 */

extern void OutPSStr _ANSI_ARGS_((FILE *fp, int str, CONST char *space,
                                  CONST char *tail, int pad));

/*
 * mkstr_nodelims
 * Like mkstr except doesn't save the delimiters.
 */

extern void mkstr_nodelims _ANSI_ARGS_((char *c, int l, int *t, char *p));

#endif
