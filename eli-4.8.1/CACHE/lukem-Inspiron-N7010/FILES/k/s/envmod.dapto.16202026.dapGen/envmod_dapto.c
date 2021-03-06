/* Automatically generated by dapto: DO NOT EDIT */

#ifdef MONITOR
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "envmod_dapto.h"


#ifdef PROTO_OK
void _dapto_env_created (Environment env, Environment parent)
#else
void _dapto_env_created (env, parent)
    Environment env;
    Environment parent;
#endif
{
    DAPTO_INIT_EV;
    DAPTO_RESULT_STR ("env_created");
    DAPTO_RESULT_LONGVAL (clock ());
#ifdef DAPTO_RESULTEnvironment
    DAPTO_RESULTEnvironment (env);
#else
    DAPTO_RESULT_OTHER (env);
#endif
#ifdef DAPTO_RESULTEnvironment
    DAPTO_RESULTEnvironment (parent);
#else
    DAPTO_RESULT_OTHER (parent);
#endif
    DAPTO_RESULT_SEND (0);
}

#ifdef PROTO_OK
void _dapto_binding_made (Environment env, int idn, DefTableKey key)
#else
void _dapto_binding_made (env, idn, key)
    Environment env;
    int idn;
    DefTableKey key;
#endif
{
    DAPTO_INIT_EV;
    DAPTO_RESULT_STR ("binding_made");
    DAPTO_RESULT_LONGVAL (clock ());
#ifdef DAPTO_RESULTEnvironment
    DAPTO_RESULTEnvironment (env);
#else
    DAPTO_RESULT_OTHER (env);
#endif
#ifdef DAPTO_RESULT_INT
    DAPTO_RESULT_INT (idn);
#else
    DAPTO_RESULT_OTHER (idn);
#endif
#ifdef DAPTO_RESULTDefTableKey
    DAPTO_RESULTDefTableKey (key);
#else
    DAPTO_RESULT_OTHER (key);
#endif
    DAPTO_RESULT_SEND (0);
}

#ifdef PROTO_OK
void get_scope_infoCmd (char *args)
#else
void get_scope_infoCmd (args)
    char *args;
#endif
{
    Environment env;
    DAPTO_ARG_INIT_OP;
    DAPTO_ARGEnvironment (&env);
    DAPTO_INIT_OP;
/* #line 38 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/v/envmod.dapto.16202290.cpp" */
{
    Scope s;

    DAPTO_RESULT_PTR (env->parent);
    DAPTO_RESULT_PTR (env->classdescr);
    for (s = env->relate; s != NoScope; s = s->nxt) {
	DAPTO_RESULT_INT (s->idn);
	DAPTO_RESULT_PTR (s->key);
    }   
}
    DAPTO_RESULT_SEND (1);
}

#ifdef PROTO_OK
void get_binding_infoCmd (char *args)
#else
void get_binding_infoCmd (args)
    char *args;
#endif
{
    Binding bind;
    DAPTO_ARG_INIT_OP;
    DAPTO_ARGBinding (&bind);
    DAPTO_INIT_OP;
/* #line 52 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/v/envmod.dapto.16202290.cpp" */
{
    DAPTO_RESULT_INT (bind->idn);
    DAPTO_RESULT_PTR (bind->key);
    DAPTO_RESULT_PTR (bind->env);
}
    DAPTO_RESULT_SEND (1);
}

#ifdef PROTO_OK
void get_inheritance_infoCmd (char *args)
#else
void get_inheritance_infoCmd (args)
    char *args;
#endif
{
    _Class cl;
    DAPTO_ARG_INIT_OP;
    DAPTO_ARG_Class (&cl);
    DAPTO_INIT_OP;
/* #line 61 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/v/envmod.dapto.16202290.cpp" */
{
    InheritPtr i;

    for (i = cl->inhlist; i != NoInherit; i = i->nxt) {
	DAPTO_RESULT_PTR (i->fromcl->env);
    }   
}
    DAPTO_RESULT_SEND (1);
}

void _dap_envmod_init ()
{
    _dap_add_command ("get_scope_info", get_scope_infoCmd );
    _dap_add_command ("get_binding_info", get_binding_infoCmd );
    _dap_add_command ("get_inheritance_info", get_inheritance_infoCmd );
}
#else
static int _dapto; /* To avoid messages about empty files. */
#endif
