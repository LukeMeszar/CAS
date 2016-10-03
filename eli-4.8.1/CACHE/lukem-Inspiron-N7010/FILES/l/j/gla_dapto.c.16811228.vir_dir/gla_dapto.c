/* Automatically generated by dapto: DO NOT EDIT */

#ifdef MONITOR
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "gla_dapto.h"


#ifdef PROTO_OK
void _dapto_token (const char * type, int linebeg, int colbeg, int cumcolbeg, int lineend, int colend, int cumcolend, const char * lexeme, int len, int val, int code)
#else
void _dapto_token (type, linebeg, colbeg, cumcolbeg, lineend, colend, cumcolend, lexeme, len, val, code)
    const char * type;
    int linebeg;
    int colbeg;
    int cumcolbeg;
    int lineend;
    int colend;
    int cumcolend;
    const char * lexeme;
    int len;
    int val;
    int code;
#endif
{
    DAPTO_INIT_EV;
    DAPTO_RESULT_STR ("token");
    DAPTO_RESULT_LONGVAL (clock ());
#ifdef DAPTO_RESULT_STR
    DAPTO_RESULT_STR (type);
#else
    DAPTO_RESULT_OTHER (type);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (linebeg);
#else
    DAPTO_RESULT_OTHER (linebeg);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (colbeg);
#else
    DAPTO_RESULT_OTHER (colbeg);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (cumcolbeg);
#else
    DAPTO_RESULT_OTHER (cumcolbeg);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (lineend);
#else
    DAPTO_RESULT_OTHER (lineend);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (colend);
#else
    DAPTO_RESULT_OTHER (colend);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (cumcolend);
#else
    DAPTO_RESULT_OTHER (cumcolend);
#endif
#ifdef DAPTO_RESULT_STR
    DAPTO_RESULT_STR (lexeme);
#else
    DAPTO_RESULT_OTHER (lexeme);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (len);
#else
    DAPTO_RESULT_OTHER (len);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (val);
#else
    DAPTO_RESULT_OTHER (val);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (code);
#else
    DAPTO_RESULT_OTHER (code);
#endif
    DAPTO_RESULT_SEND (0);
}

void _dap_gla_init ()
{
}
#else
static int _dapto; /* To avoid messages about empty files. */
#endif
