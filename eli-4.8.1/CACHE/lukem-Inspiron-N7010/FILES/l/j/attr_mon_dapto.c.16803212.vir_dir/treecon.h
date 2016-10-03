
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR MkVariableDeclList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkStatementList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkAxiom ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOptInitialize ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkVarIdList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkVariableDeclSeg ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkParameterDecl ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkVariableDecl ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkUnop ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkBinop ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkNotop ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkShortCircuitOp ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkParameterList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkResultType ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkWhileStmt ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkExpression ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkStatement ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkCompound ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkProgram ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkIdUse ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkIdDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkMonadicExp ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR MkDyadicExp ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR MkIdnVal ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkFloatVal ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR MkIntVal ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR MkFloatParDecl ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkIntParDecl ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkInitialize ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkVarDecl ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR MkFloatVar ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkIntVar ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkUMinusOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkPercentOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkSlashOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkStarOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkMinusOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkPlusOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkGreaterOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkLessOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkEqualOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkExclOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkNotExp ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR MkAmpOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkBarOp ELI_ARG((POSITION *_coordref));
extern NODEPTR MkShortCircuitExp ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR MkCondExp ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR MkAssignExp ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR MkExprStmt ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkFloatResult ELI_ARG((POSITION *_coordref));
extern NODEPTR MkIntResult ELI_ARG((POSITION *_coordref));
extern NODEPTR MkSource ELI_ARG((POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR MkReturnStmt ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR MkContinueStmt ELI_ARG((POSITION *_coordref));
extern NODEPTR MkBreakStmt ELI_ARG((POSITION *_coordref));
extern NODEPTR MkLoop ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR MkTwoSided ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR MkOneSided ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR MkAppliedOccurrence ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR MkDefiningOccurrence ELI_ARG((POSITION *_coordref, int _TERM1));
#define MkIdentifier(pos,val) (val)
#define MkIntDenotation(pos,val) (val)
#define MkFloatDenotation(pos,val) (val)
#endif
