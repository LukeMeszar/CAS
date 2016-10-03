/* Automatically generated by dapto: DO NOT EDIT */

#ifdef MONITOR
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "csm_dapto.h"


#ifdef PROTO_OK
void _dapto_string_stored (int index, const char * string)
#else
void _dapto_string_stored (index, string)
    int index;
    const char * string;
#endif
{
    DAPTO_INIT_EV;
    DAPTO_RESULT_STR ("string_stored");
    DAPTO_RESULT_LONGVAL (clock ());
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (index);
#else
    DAPTO_RESULT_OTHER (index);
#endif
#ifdef DAPTO_RESULT_STR
    DAPTO_RESULT_STR (string);
#else
    DAPTO_RESULT_OTHER (string);
#endif
    DAPTO_RESULT_SEND (0);
}

#ifdef PROTO_OK
void get_stringCmd (char *args)
#else
void get_stringCmd (args)
    char *args;
#endif
{
    int index;
    DAPTO_ARG_INIT_OP;
    DAPTO_ARG_INT (&index);
    DAPTO_INIT_OP;
/* #line 33 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/j/j/csm.dapto.14487864.cpp" */
{ 
    if ((index < 0) || (index >= numstr)) {
	DAPTO_RESULT_STR ("*** Illegal string table index ***");
    } else {
	char *s = StringTable (index);
	if (s == (char *) 0) {
	    DAPTO_RESULT_STR ("*** No string at this index ***");
        } else {
	    DAPTO_RESULT_STR (s);
        }
    }
}
    DAPTO_RESULT_SEND (1);
}

#ifdef PROTO_OK
void get_all_stringsCmd (char *args)
#else
void get_all_stringsCmd (args)
    char *args;
#endif
{
    DAPTO_ARG_INIT_OP;
    DAPTO_INIT_OP;
/* #line 48 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/j/j/csm.dapto.14487864.cpp" */
{
    int i;
    char *s;

    for (i = 0; i < numstr; i++) {
        s = StringTable (i);
        if (s == (char *) 0)
            continue;
	DAPTO_RESULT_INT (i);
	DAPTO_RESULT_STR (s);
    }
}
    DAPTO_RESULT_SEND (1);
}

void _dap_csm_init ()
{
    _dap_add_command ("get_string", get_stringCmd );
    _dap_add_command ("get_all_strings", get_all_stringsCmd );
}
#else
static int _dapto; /* To avoid messages about empty files. */
#endif
