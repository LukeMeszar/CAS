
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR Mkprog ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkaxiom ELI_ARG((POSITION *_coordref));
#endif
