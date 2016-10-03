
/* definition of tree node structure */

#ifndef NODE_H
#define NODE_H
#include "err.h"
#include "nodeptr.h" /* defines NODEPTR */
#include "HEAD.h"

#ifdef MONITOR
#define _NODECOMMON int _prod; POSITION _coord; int _uid;
#else
#define _NODECOMMON int _prod;
#endif
struct NODEPTR_struct {
        _NODECOMMON
#ifdef __cplusplus
        void* operator new(size_t size);
#endif
};

typedef struct _TSVariableDeclList* _TSPVariableDeclList;
typedef struct _TSStatementList* _TSPStatementList;
typedef struct _TSAxiom* _TSPAxiom;
typedef struct _TSOptInitialize* _TSPOptInitialize;
typedef struct _TSVarIdList* _TSPVarIdList;
typedef struct _TSVariableDeclSeg* _TSPVariableDeclSeg;
typedef struct _TSParameterDecl* _TSPParameterDecl;
typedef struct _TSVariableDecl* _TSPVariableDecl;
typedef struct _TSUnop* _TSPUnop;
typedef struct _TSBinop* _TSPBinop;
typedef struct _TSNotop* _TSPNotop;
typedef struct _TSShortCircuitOp* _TSPShortCircuitOp;
typedef struct _TSParameterList* _TSPParameterList;
typedef struct _TSResultType* _TSPResultType;
typedef struct _TSWhileStmt* _TSPWhileStmt;
typedef struct _TSExpression* _TSPExpression;
typedef struct _TSStatement* _TSPStatement;
typedef struct _TSCompound* _TSPCompound;
typedef struct _TSProgram* _TSPProgram;
typedef struct _TSIdUse* _TSPIdUse;
typedef struct _TSIdDef* _TSPIdDef;
typedef struct _TPrule_15* _TPPrule_15;
typedef struct _TPrule_14* _TPPrule_14;
typedef struct _TPrule_13* _TPPrule_13;
typedef struct _TPrule_12* _TPPrule_12;
typedef struct _TPrule_11* _TPPrule_11;
typedef struct _TPrule_10* _TPPrule_10;
typedef struct _TPrule_9* _TPPrule_9;
typedef struct _TPrule_8* _TPPrule_8;
typedef struct _TPrule_7* _TPPrule_7;
typedef struct _TPrule_6* _TPPrule_6;
typedef struct _TPrule_5* _TPPrule_5;
typedef struct _TPrule_4* _TPPrule_4;
typedef struct _TPrule_3* _TPPrule_3;
typedef struct _TPrule_2* _TPPrule_2;
typedef struct _TPrule_1* _TPPrule_1;
typedef struct _TPMonadicExp* _TPPMonadicExp;
typedef struct _TPDyadicExp* _TPPDyadicExp;
typedef struct _TPIdnVal* _TPPIdnVal;
typedef struct _TPFloatVal* _TPPFloatVal;
typedef struct _TPIntVal* _TPPIntVal;
typedef struct _TPFloatParDecl* _TPPFloatParDecl;
typedef struct _TPIntParDecl* _TPPIntParDecl;
typedef struct _TPInitialize* _TPPInitialize;
typedef struct _TPVarDecl* _TPPVarDecl;
typedef struct _TPFloatVar* _TPPFloatVar;
typedef struct _TPIntVar* _TPPIntVar;
typedef struct _TPUMinusOp* _TPPUMinusOp;
typedef struct _TPPercentOp* _TPPPercentOp;
typedef struct _TPSlashOp* _TPPSlashOp;
typedef struct _TPStarOp* _TPPStarOp;
typedef struct _TPMinusOp* _TPPMinusOp;
typedef struct _TPPlusOp* _TPPPlusOp;
typedef struct _TPGreaterOp* _TPPGreaterOp;
typedef struct _TPLessOp* _TPPLessOp;
typedef struct _TPEqualOp* _TPPEqualOp;
typedef struct _TPExclOp* _TPPExclOp;
typedef struct _TPNotExp* _TPPNotExp;
typedef struct _TPAmpOp* _TPPAmpOp;
typedef struct _TPBarOp* _TPPBarOp;
typedef struct _TPShortCircuitExp* _TPPShortCircuitExp;
typedef struct _TPCondExp* _TPPCondExp;
typedef struct _TPAssignExp* _TPPAssignExp;
typedef struct _TPExprStmt* _TPPExprStmt;
typedef struct _TPFloatResult* _TPPFloatResult;
typedef struct _TPIntResult* _TPPIntResult;
typedef struct _TPSource* _TPPSource;
typedef struct _TPReturnStmt* _TPPReturnStmt;
typedef struct _TPContinueStmt* _TPPContinueStmt;
typedef struct _TPBreakStmt* _TPPBreakStmt;
typedef struct _TPLoop* _TPPLoop;
typedef struct _TPTwoSided* _TPPTwoSided;
typedef struct _TPOneSided* _TPPOneSided;
typedef struct _TPAppliedOccurrence* _TPPAppliedOccurrence;
typedef struct _TPDefiningOccurrence* _TPPDefiningOccurrence;

struct _TSVariableDeclList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSStatementList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSAxiom
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSOptInitialize
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSVarIdList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSVariableDeclSeg
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilType _ATtype;
};

struct _TSParameterDecl
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSVariableDecl
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSUnop
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
};

struct _TSBinop
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
};

struct _TSNotop
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
};

struct _TSShortCircuitOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
};

struct _TSParameterList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSResultType
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilType _ATtype;
};

struct _TSWhileStmt
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATContinueLbl;
DefTableKey _ATBreakLbl;
};

struct _TSExpression
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
};

struct _TSStatement
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSCompound
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
};

struct _TSProgram
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
tOilType _ATtype;
DefTableKey _ATContinueLbl;
DefTableKey _ATBreakLbl;
};

struct _TSIdUse
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
};

struct _TSIdDef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
};

struct _TPrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPVarIdList _desc1;
_TSPVariableDecl _desc2;
};

struct _TPrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPVariableDecl _desc1;
};

struct _TPrule_13
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPVariableDeclSeg _desc1;
};

struct _TPrule_12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPVariableDeclList _desc1;
_TSPVariableDeclSeg _desc2;
};

struct _TPrule_11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPWhileStmt _desc1;
};

struct _TPrule_10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPStatementList _desc1;
_TSPStatement _desc2;
};

struct _TPrule_9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPStatement _desc1;
};

struct _TPrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPCompound _desc1;
};

struct _TPrule_7
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_6
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPParameterList _desc1;
_TSPParameterDecl _desc2;
};

struct _TPrule_5
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPParameterDecl _desc1;
};

struct _TPrule_4
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_3
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
_TSPVariableDeclList _desc1;
_TSPStatementList _desc2;
};

struct _TPrule_2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
_TSPStatementList _desc1;
};

struct _TPrule_1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPProgram _desc1;
};

struct _TPMonadicExp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPUnop _desc1;
_TSPExpression _desc2;
};

struct _TPDyadicExp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPExpression _desc1;
_TSPBinop _desc2;
_TSPExpression _desc3;
};

struct _TPIdnVal
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPIdUse _desc1;
};

struct _TPFloatVal
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
};

struct _TPIntVal
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
};

struct _TPFloatParDecl
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPIdDef _desc1;
};

struct _TPIntParDecl
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPIdDef _desc1;
};

struct _TPInitialize
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPExpression _desc1;
};

struct _TPVarDecl
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPIdDef _desc1;
_TSPOptInitialize _desc2;
};

struct _TPFloatVar
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilType _ATtype;
_TSPVarIdList _desc1;
};

struct _TPIntVar
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilType _ATtype;
_TSPVarIdList _desc1;
};

struct _TPUMinusOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPPercentOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPSlashOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPStarOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPMinusOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPPlusOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPGreaterOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPLessOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPEqualOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPExclOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPNotExp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPNotop _desc1;
_TSPExpression _desc2;
};

struct _TPAmpOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPBarOp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
POSITION _AT_pos;
};

struct _TPShortCircuitExp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPExpression _desc1;
_TSPShortCircuitOp _desc2;
_TSPExpression _desc3;
};

struct _TPCondExp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPExpression _desc1;
_TSPExpression _desc2;
_TSPExpression _desc3;
};

struct _TPAssignExp
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilTypeSet _ATpossible;
_TSPIdUse _desc1;
_TSPExpression _desc2;
tOilTypeSet _ATpossible_RuleAttr_79;
};

struct _TPExprStmt
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPExpression _desc1;
};

struct _TPFloatResult
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilType _ATtype;
};

struct _TPIntResult
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilType _ATtype;
};

struct _TPSource
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
tOilType _ATtype;
DefTableKey _ATContinueLbl;
DefTableKey _ATBreakLbl;
_TSPResultType _desc1;
_TSPParameterList _desc2;
_TSPCompound _desc3;
};

struct _TPReturnStmt
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPExpression _desc1;
POSITION _AT_pos;
};

struct _TPContinueStmt
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
POSITION _AT_pos;
};

struct _TPBreakStmt
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
POSITION _AT_pos;
};

struct _TPLoop
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATContinueLbl;
DefTableKey _ATBreakLbl;
_TSPExpression _desc1;
_TSPStatement _desc2;
};

struct _TPTwoSided
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPExpression _desc1;
_TSPStatement _desc2;
_TSPStatement _desc3;
};

struct _TPOneSided
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPExpression _desc1;
_TSPStatement _desc2;
};

struct _TPAppliedOccurrence
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
POSITION _AT_pos;
int _ATTERM_1;
};

struct _TPDefiningOccurrence
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
POSITION _AT_pos;
int _ATTERM_1;
};

#undef _NODECOMMON
#endif
