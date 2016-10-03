
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR Mkparams ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkoptparams ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkoptattrs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkattrs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mktranslation_sig ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkiduse ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mksig ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkattr ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkevent_block ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkexport ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkevent_sig ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mksigs ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkaspect_stmt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkaspects ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkspec ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkparam ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mktypeid ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkbody ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkoperation_block ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkiddef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkoperation_sig ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1, NODEPTR _desc3));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, int _TERM1, NODEPTR _desc3));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_31 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_30 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_29 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_28 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_27 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_26 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_25 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_24 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_23 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_22 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_21 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_20 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_19 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_18 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_17 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_16 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkoperation_sig2 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2, NODEPTR _desc3, NODEPTR _desc4));
extern NODEPTR Mkoperation_sig1 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2, NODEPTR _desc3));
#define Mkident(pos,val) (val)
#define Mkbstr(pos,val) (val)
#define Mktext(pos,val) (val)
#define Mkstr(pos,val) (val)
#endif
