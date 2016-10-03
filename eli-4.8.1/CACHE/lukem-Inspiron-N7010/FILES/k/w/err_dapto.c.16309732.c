/* Automatically generated by dapto: DO NOT EDIT */

#ifdef MONITOR
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "err_dapto.h"


#ifdef PROTO_OK
void _dapto_message (const char * severity, const char * text, int line, int col)
#else
void _dapto_message (severity, text, line, col)
    const char * severity;
    const char * text;
    int line;
    int col;
#endif
{
    DAPTO_INIT_EV;
    DAPTO_RESULT_STR ("message");
    DAPTO_RESULT_LONGVAL (clock ());
#ifdef DAPTO_RESULT_STR
    DAPTO_RESULT_STR (severity);
#else
    DAPTO_RESULT_OTHER (severity);
#endif
#ifdef DAPTO_RESULT_STR
    DAPTO_RESULT_STR (text);
#else
    DAPTO_RESULT_OTHER (text);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (line);
#else
    DAPTO_RESULT_OTHER (line);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (col);
#else
    DAPTO_RESULT_OTHER (col);
#endif
    DAPTO_RESULT_SEND (0);
}

#ifdef PROTO_OK
void get_coordinate_infoCmd (char *args)
#else
void get_coordinate_infoCmd (args)
    char *args;
#endif
{
    CoordPtr coord;
    DAPTO_ARG_INIT_OP;
    DAPTO_ARGCoordPtr (&coord);
    DAPTO_INIT_OP;
/* #line 23 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/v/err.dapto.16205522.cpp" */
{
    DAPTO_RESULTPOSITION(*coord);
}
    DAPTO_RESULT_SEND (1);
}

void _dap_err_init ()
{
    _dap_add_command ("get_coordinate_info", get_coordinate_infoCmd );
}
#else
static int _dapto; /* To avoid messages about empty files. */
#endif
