/* Automatically generated by dapto: DO NOT EDIT */

#ifndef err_DAPTO_H
#define err_DAPTO_H
#include "dapto.h"
#include "eliproto.h"
#include "err.h"
extern void _dap_err_init ();
#ifdef PROTO_OK
extern void _dapto_message (const char *, const char *, int, int);
#else
extern void _dapto_message ();
#endif
#endif