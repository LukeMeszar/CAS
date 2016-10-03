
#ifndef _VISITPROCS_H
#define _VISITPROCS_H

#include "HEAD.h"
#include "node.h"
#include "treecon.h"

#include "eliproto.h"


extern void LIGA_ATTREVAL ELI_ARG((NODEPTR));
extern void _VS0Empty ELI_ARG((NODEPTR _currn));
extern void _VS1rule_15 ELI_ARG((_TPPrule_15 _currn));
extern void _VS2rule_15 ELI_ARG((_TPPrule_15 _currn));
extern void _VS1rule_14 ELI_ARG((_TPPrule_14 _currn));
extern void _VS2rule_14 ELI_ARG((_TPPrule_14 _currn));
#define _VS1rule_13 _VS1rule_14

#define _VS2rule_13 _VS2rule_14

#define _VS1rule_12 _VS1rule_15

#define _VS2rule_12 _VS2rule_15

extern void _VS1rule_11 ELI_ARG((_TPPrule_11 _currn));
extern void _VS2rule_11 ELI_ARG((_TPPrule_11 _currn));
#define _VS1rule_10 _VS1rule_15

#define _VS2rule_10 _VS2rule_15

#define _VS1rule_9 _VS1rule_14

#define _VS2rule_9 _VS2rule_14

extern void _VS1rule_8 ELI_ARG((_TPPrule_8 _currn));
extern void _VS2rule_8 ELI_ARG((_TPPrule_8 _currn));
#define _VS1rule_7 _VS0Empty

#define _VS2rule_7 _VS0Empty

#define _VS1rule_6 _VS1rule_15

#define _VS2rule_6 _VS2rule_15

#define _VS1rule_5 _VS1rule_14

#define _VS2rule_5 _VS2rule_14

#define _VS1rule_4 _VS0Empty

#define _VS2rule_4 _VS0Empty

extern void _VS1rule_3 ELI_ARG((_TPPrule_3 _currn));
extern void _VS2rule_3 ELI_ARG((_TPPrule_3 _currn));
extern void _VS1rule_2 ELI_ARG((_TPPrule_2 _currn));
extern void _VS2rule_2 ELI_ARG((_TPPrule_2 _currn));
extern void _VS1rule_1 ELI_ARG((_TPPrule_1 _currn));
extern void _VS1MonadicExp ELI_ARG((_TPPMonadicExp _currn));
extern void _VS2MonadicExp ELI_ARG((_TPPMonadicExp _currn));
extern void _VS3MonadicExp ELI_ARG((_TPPMonadicExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
extern void _VS1DyadicExp ELI_ARG((_TPPDyadicExp _currn));
extern void _VS2DyadicExp ELI_ARG((_TPPDyadicExp _currn));
extern void _VS3DyadicExp ELI_ARG((_TPPDyadicExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
extern void _VS1IdnVal ELI_ARG((_TPPIdnVal _currn));
extern void _VS2IdnVal ELI_ARG((_TPPIdnVal _currn));
extern void _VS3IdnVal ELI_ARG((_TPPIdnVal _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
#define _VS1FloatVal _VS0Empty

extern void _VS2FloatVal ELI_ARG((_TPPFloatVal _currn));
extern void _VS3FloatVal ELI_ARG((_TPPFloatVal _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
#define _VS1IntVal _VS0Empty

extern void _VS2IntVal ELI_ARG((_TPPIntVal _currn));
extern void _VS3IntVal ELI_ARG((_TPPIntVal _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
#define _VS1FloatParDecl _VS1rule_14

extern void _VS2FloatParDecl ELI_ARG((_TPPFloatParDecl _currn));
#define _VS1IntParDecl _VS1rule_14

extern void _VS2IntParDecl ELI_ARG((_TPPIntParDecl _currn));
#define _VS1Initialize _VS1rule_14

extern void _VS2Initialize ELI_ARG((_TPPInitialize _currn));
extern void _VS1VarDecl ELI_ARG((_TPPVarDecl _currn));
#define _VS2VarDecl _VS2rule_15

extern void _VS1FloatVar ELI_ARG((_TPPFloatVar _currn));
extern void _VS2FloatVar ELI_ARG((_TPPFloatVar _currn));
extern void _VS1IntVar ELI_ARG((_TPPIntVar _currn));
extern void _VS2IntVar ELI_ARG((_TPPIntVar _currn));
extern void _VS1UMinusOp ELI_ARG((_TPPUMinusOp _currn));
extern void _VS2UMinusOp ELI_ARG((_TPPUMinusOp _currn));
extern void _VS1PercentOp ELI_ARG((_TPPPercentOp _currn));
extern void _VS2PercentOp ELI_ARG((_TPPPercentOp _currn,tOilOp* _AS0operator));
extern void _VS1SlashOp ELI_ARG((_TPPSlashOp _currn));
extern void _VS2SlashOp ELI_ARG((_TPPSlashOp _currn,tOilOp* _AS0operator));
extern void _VS1StarOp ELI_ARG((_TPPStarOp _currn));
extern void _VS2StarOp ELI_ARG((_TPPStarOp _currn,tOilOp* _AS0operator));
extern void _VS1MinusOp ELI_ARG((_TPPMinusOp _currn));
extern void _VS2MinusOp ELI_ARG((_TPPMinusOp _currn,tOilOp* _AS0operator));
extern void _VS1PlusOp ELI_ARG((_TPPPlusOp _currn));
extern void _VS2PlusOp ELI_ARG((_TPPPlusOp _currn,tOilOp* _AS0operator));
extern void _VS1GreaterOp ELI_ARG((_TPPGreaterOp _currn));
extern void _VS2GreaterOp ELI_ARG((_TPPGreaterOp _currn,tOilOp* _AS0operator));
extern void _VS1LessOp ELI_ARG((_TPPLessOp _currn));
extern void _VS2LessOp ELI_ARG((_TPPLessOp _currn,tOilOp* _AS0operator));
extern void _VS1EqualOp ELI_ARG((_TPPEqualOp _currn));
extern void _VS2EqualOp ELI_ARG((_TPPEqualOp _currn,tOilOp* _AS0operator));
extern void _VS1ExclOp ELI_ARG((_TPPExclOp _currn));
extern void _VS2ExclOp ELI_ARG((_TPPExclOp _currn));
extern void _VS1NotExp ELI_ARG((_TPPNotExp _currn));
extern void _VS2NotExp ELI_ARG((_TPPNotExp _currn));
extern void _VS3NotExp ELI_ARG((_TPPNotExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
extern void _VS1AmpOp ELI_ARG((_TPPAmpOp _currn));
extern void _VS2AmpOp ELI_ARG((_TPPAmpOp _currn,tOilOp* _AS0operator));
extern void _VS1BarOp ELI_ARG((_TPPBarOp _currn));
extern void _VS2BarOp ELI_ARG((_TPPBarOp _currn,tOilOp* _AS0operator));
extern void _VS1ShortCircuitExp ELI_ARG((_TPPShortCircuitExp _currn));
extern void _VS2ShortCircuitExp ELI_ARG((_TPPShortCircuitExp _currn));
extern void _VS3ShortCircuitExp ELI_ARG((_TPPShortCircuitExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
extern void _VS1CondExp ELI_ARG((_TPPCondExp _currn));
extern void _VS2CondExp ELI_ARG((_TPPCondExp _currn));
extern void _VS3CondExp ELI_ARG((_TPPCondExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
extern void _VS1AssignExp ELI_ARG((_TPPAssignExp _currn));
extern void _VS2AssignExp ELI_ARG((_TPPAssignExp _currn));
extern void _VS3AssignExp ELI_ARG((_TPPAssignExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79));
extern void _VS1ExprStmt ELI_ARG((_TPPExprStmt _currn));
extern void _VS2ExprStmt ELI_ARG((_TPPExprStmt _currn));
extern void _VS1FloatResult ELI_ARG((_TPPFloatResult _currn));
extern void _VS1IntResult ELI_ARG((_TPPIntResult _currn));
extern void _VS1Source ELI_ARG((_TPPSource _currn));
extern void _VS2Source ELI_ARG((_TPPSource _currn));
extern void _VS1ReturnStmt ELI_ARG((_TPPReturnStmt _currn));
extern void _VS2ReturnStmt ELI_ARG((_TPPReturnStmt _currn));
extern void _VS1ContinueStmt ELI_ARG((_TPPContinueStmt _currn));
extern void _VS2ContinueStmt ELI_ARG((_TPPContinueStmt _currn));
extern void _VS1BreakStmt ELI_ARG((_TPPBreakStmt _currn));
extern void _VS2BreakStmt ELI_ARG((_TPPBreakStmt _currn));
extern void _VS1Loop ELI_ARG((_TPPLoop _currn));
extern void _VS2Loop ELI_ARG((_TPPLoop _currn));
extern void _VS1TwoSided ELI_ARG((_TPPTwoSided _currn));
extern void _VS2TwoSided ELI_ARG((_TPPTwoSided _currn));
extern void _VS1OneSided ELI_ARG((_TPPOneSided _currn));
extern void _VS2OneSided ELI_ARG((_TPPOneSided _currn));
extern void _VS1AppliedOccurrence ELI_ARG((_TPPAppliedOccurrence _currn));
extern void _VS1DefiningOccurrence ELI_ARG((_TPPDefiningOccurrence _currn));
extern void _VS2DefiningOccurrence ELI_ARG((_TPPDefiningOccurrence _currn));
#endif
