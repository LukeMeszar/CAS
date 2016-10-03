
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR MkPTGSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG2 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxRoot ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkItem ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkItems ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkPatternName ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkPatternSpec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkElement ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSyms ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxRHS ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxSymbol ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxRule ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxProduction ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxGrammar ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref, int _TERM1, NODEPTR _desc1));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref, int _TERM1, int _TERM2));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref, int _TERM1));
#define Mk0rule_8(_coordref) NULLNODEPTR
extern NODEPTR Mk2rule_8 ELI_ARG((POSITION *_coordref, NODEPTR l, NODEPTR r));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref, NODEPTR t));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
#define Mk0rule_14(_coordref) NULLNODEPTR
extern NODEPTR Mk2rule_14 ELI_ARG((POSITION *_coordref, NODEPTR l, NODEPTR r));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref, NODEPTR t));
#define Mk0rule_15(_coordref) NULLNODEPTR
extern NODEPTR Mk2rule_15 ELI_ARG((POSITION *_coordref, NODEPTR l, NODEPTR r));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref, NODEPTR t));
extern NODEPTR Mkrule_16 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_17 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
#define Mk0rule_18(_coordref) NULLNODEPTR
extern NODEPTR Mk2rule_18 ELI_ARG((POSITION *_coordref, NODEPTR l, NODEPTR r));
extern NODEPTR Mkrule_18 ELI_ARG((POSITION *_coordref, NODEPTR t));
extern NODEPTR Mkrule_26 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_25 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_24 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_23 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_22 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_21 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_20 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_19 ELI_ARG((POSITION *_coordref));
#define MkxLiteral(pos,val) (val)
#define MkCString(pos,val) (val)
#define MkPtgType(pos,val) (val)
#define MkNumber(pos,val) (val)
#define MkxIdentifier(pos,val) (val)
#endif
