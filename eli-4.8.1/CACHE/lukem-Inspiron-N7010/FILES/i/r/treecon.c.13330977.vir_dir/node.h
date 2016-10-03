
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

typedef struct _TSLST_Source* _TSPLST_Source;
typedef struct _TSLST_Nonterms* _TSPLST_Nonterms;
typedef struct _TSChildren* _TSPChildren;
typedef struct _TSTerminal* _TSPTerminal;
typedef struct _TSFunction* _TSPFunction;
typedef struct _TSChild* _TSPChild;
typedef struct _TSSymbolUse* _TSPSymbolUse;
typedef struct _TSCost* _TSPCost;
typedef struct _TSSignature* _TSPSignature;
typedef struct _TSSymbolDef* _TSPSymbolDef;
typedef struct _TSType* _TSPType;
typedef struct _TSNonterms* _TSPNonterms;
typedef struct _TSPattern* _TSPPattern;
typedef struct _TSDeclaration* _TSPDeclaration;
typedef struct _TSInclude* _TSPInclude;
typedef struct _TSSource* _TSPSource;
typedef struct _TPLST_Patternrule_19* _TPPLST_Patternrule_19;
typedef struct _TPLST_Declarationrule_19* _TPPLST_Declarationrule_19;
typedef struct _TPLST_Includerule_19* _TPPLST_Includerule_19;
typedef struct _TPLST_0rule_19* _TPPLST_0rule_19;
typedef struct _TPLST_SymbolDefrule_16* _TPPLST_SymbolDefrule_16;
typedef struct _TPLST_0rule_16* _TPPLST_0rule_16;
typedef struct _TPrule_1* _TPPrule_1;
typedef struct _TPrule_2* _TPPrule_2;
typedef struct _TPrule_3* _TPPrule_3;
typedef struct _TPrule_4* _TPPrule_4;
typedef struct _TPrule_5* _TPPrule_5;
typedef struct _TPrule_6* _TPPrule_6;
typedef struct _TPrule_7* _TPPrule_7;
typedef struct _TPrule_8* _TPPrule_8;
typedef struct _TPrule_9* _TPPrule_9;
typedef struct _TPrule_10* _TPPrule_10;
typedef struct _TPrule_11* _TPPrule_11;
typedef struct _TPrule_12* _TPPrule_12;
typedef struct _TPrule_13* _TPPrule_13;
typedef struct _TPrule_14* _TPPrule_14;
typedef struct _TPrule_15* _TPPrule_15;
typedef struct _TPrule_16* _TPPrule_16;
typedef struct _TPrule_17* _TPPrule_17;
typedef struct _TPrule_18* _TPPrule_18;
typedef struct _TPrule_19* _TPPrule_19;

struct _TSLST_Source
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
};

struct _TSLST_Nonterms
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSChildren
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _AT_const1;
};

struct _TSTerminal
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
};

struct _TSFunction
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
};

struct _TSChild
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATtindex_pre;
int _ATntindex_pre;
int _ATSym;
int _ATntcount;
int _ATIsNt;
};

struct _TSSymbolUse
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATFieldSets_post;
PTGNode _ATArgNames_post;
PTGNode _ATArgDecls_post;
PTGNode _ATFieldDecls_post;
int _ATHasKind;
int _ATSym;
DefTableKey _ATKey;
};

struct _TSCost
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATvalue;
};

struct _TSSignature
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATstruct;
int _ATSym;
int _ATComSym;
};

struct _TSSymbolDef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATtype;
};

struct _TSType
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
};

struct _TSNonterms
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSPattern
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
int _ATIsCommutative;
};

struct _TSDeclaration
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATtype;
};

struct _TSInclude
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSSource
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
};

struct _TPLST_Patternrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
_TSPPattern _desc1;
_TSPLST_Source _desc2;
};

struct _TPLST_Declarationrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
_TSPDeclaration _desc1;
_TSPLST_Source _desc2;
};

struct _TPLST_Includerule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
_TSPInclude _desc1;
_TSPLST_Source _desc2;
};

struct _TPLST_0rule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
NODEPTR _desc1;
NODEPTR _desc2;
};

struct _TPLST_SymbolDefrule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSymbolDef _desc1;
_TSPLST_Nonterms _desc2;
};

struct _TPLST_0rule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
NODEPTR _desc1;
NODEPTR _desc2;
};

struct _TPrule_1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATFieldSets_post;
PTGNode _ATArgNames_post;
PTGNode _ATArgDecls_post;
PTGNode _ATFieldDecls_post;
int _ATHasKind;
int _ATSym;
DefTableKey _ATKey;
};

struct _TPrule_2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATtype;
};

struct _TPrule_3
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
POSITION _AT_pos;
};

struct _TPrule_4
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
};

struct _TPrule_5
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATvalue;
};

struct _TPrule_6
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATvalue;
};

struct _TPrule_7
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
};

struct _TPrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _AT_const1;
_TSPChild _desc1;
};

struct _TPrule_9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _AT_const1;
_TSPChildren _desc1;
_TSPChild _desc2;
};

struct _TPrule_10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATtindex_pre;
int _ATntindex_pre;
int _ATSym;
int _ATntcount;
int _ATIsNt;
_TSPTerminal _desc1;
_TSPChildren _desc2;
int _ATHasNt_RuleAttr_67;
};

struct _TPrule_11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATtindex_pre;
int _ATntindex_pre;
int _ATSym;
int _ATntcount;
int _ATIsNt;
_TSPTerminal _desc1;
};

struct _TPrule_12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATtindex_pre;
int _ATntindex_pre;
int _ATSym;
int _ATntcount;
int _ATIsNt;
_TSPSymbolUse _desc1;
};

struct _TPrule_13
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATstruct;
int _ATSym;
int _ATComSym;
_TSPSymbolUse _desc1;
_TSPChild _desc2;
_TSPFunction _desc3;
POSITION _AT_pos;
};

struct _TPrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
int _ATIsCommutative;
_TSPSignature _desc1;
_TSPCost _desc2;
int _ATTERM_1;
PTGNode _ATid_RuleAttr_71;
};

struct _TPrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATindex_pre;
int _ATIsCommutative;
_TSPSignature _desc1;
_TSPCost _desc2;
int _ATTERM_1;
PTGNode _ATid_RuleAttr_72;
};

struct _TPrule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPLST_Nonterms _desc1;
};

struct _TPrule_17
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATtype;
_TSPNonterms _desc1;
_TSPType _desc2;
};

struct _TPrule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TPrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
_TSPLST_Source _desc1;
};

#undef _NODECOMMON
#endif
