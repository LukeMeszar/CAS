
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR MkChildren ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkTerminal ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkFunction ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkChild ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymbolUse ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkCost ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSignature ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSymbolDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkType ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkNonterms ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkPattern ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkDeclaration ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkInclude ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSource ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2));
#define Mk0rule_16(_coordref) NULLNODEPTR
extern NODEPTR Mk2rule_16 ELI_ARG((POSITION *_coordref, NODEPTR l, NODEPTR r));
extern NODEPTR Mkrule_16 ELI_ARG((POSITION *_coordref, NODEPTR t));
extern NODEPTR Mkrule_17 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_18 ELI_ARG((POSITION *_coordref, int _TERM1));
#define Mk0rule_19(_coordref) NULLNODEPTR
extern NODEPTR Mk2rule_19 ELI_ARG((POSITION *_coordref, NODEPTR l, NODEPTR r));
extern NODEPTR Mkrule_19 ELI_ARG((POSITION *_coordref, NODEPTR t));
#define MkString(pos,val) (val)
#define MkInteger(pos,val) (val)
#define MkIdentifier(pos,val) (val)
#endif
