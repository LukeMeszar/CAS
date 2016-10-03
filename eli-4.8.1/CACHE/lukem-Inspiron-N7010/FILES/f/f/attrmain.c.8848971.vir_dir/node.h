
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

typedef struct _TSLST_xGrammar* _TSPLST_xGrammar;
typedef struct _TSLST_xRHS* _TSPLST_xRHS;
typedef struct _TSLST_Syms* _TSPLST_Syms;
typedef struct _TSLST_Items* _TSPLST_Items;
typedef struct _TSPTGSpec* _TSPPTGSpec;
typedef struct _TSG2* _TSPG2;
typedef struct _TSxRoot* _TSPxRoot;
typedef struct _TSItem* _TSPItem;
typedef struct _TSItems* _TSPItems;
typedef struct _TSPatternName* _TSPPatternName;
typedef struct _TSPatternSpec* _TSPPatternSpec;
typedef struct _TSElement* _TSPElement;
typedef struct _TSSyms* _TSPSyms;
typedef struct _TSxRHS* _TSPxRHS;
typedef struct _TSxSymbol* _TSPxSymbol;
typedef struct _TSxRule* _TSPxRule;
typedef struct _TSxProduction* _TSPxProduction;
typedef struct _TSxGrammar* _TSPxGrammar;
typedef struct _TPLST_xProductionrule_18* _TPPLST_xProductionrule_18;
typedef struct _TPLST_0rule_18* _TPPLST_0rule_18;
typedef struct _TPLST_Elementrule_15* _TPPLST_Elementrule_15;
typedef struct _TPLST_0rule_15* _TPPLST_0rule_15;
typedef struct _TPLST_xSymbolrule_14* _TPPLST_xSymbolrule_14;
typedef struct _TPLST_0rule_14* _TPPLST_0rule_14;
typedef struct _TPLST_Itemrule_8* _TPPLST_Itemrule_8;
typedef struct _TPLST_0rule_8* _TPPLST_0rule_8;
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
typedef struct _TPrule_26* _TPPrule_26;
typedef struct _TPrule_25* _TPPrule_25;
typedef struct _TPrule_24* _TPPrule_24;
typedef struct _TPrule_23* _TPPrule_23;
typedef struct _TPrule_22* _TPPrule_22;
typedef struct _TPrule_21* _TPPrule_21;
typedef struct _TPrule_20* _TPPrule_20;
typedef struct _TPrule_19* _TPPrule_19;

struct _TSLST_xGrammar
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSLST_xRHS
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSLST_Syms
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSLST_Items
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSPTGSpec
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSxRoot
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
CharPtr _ATPrefix;
};

struct _TSItem
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSItems
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATIdemPtg;
};

struct _TSPatternName
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATIdemPtg;
DefTableKey _ATKey;
};

struct _TSPatternSpec
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATIdemPtg;
};

struct _TSElement
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATNontermCnt_pre;
};

struct _TSSyms
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSxRHS
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSxSymbol
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
int _ATIsTerminal;
};

struct _TSxRule
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSxProduction
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSxGrammar
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPLST_xProductionrule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxProduction _desc1;
_TSPLST_xGrammar _desc2;
};

struct _TPLST_0rule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
NODEPTR _desc1;
NODEPTR _desc2;
};

struct _TPLST_Elementrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPElement _desc1;
_TSPLST_xRHS _desc2;
};

struct _TPLST_0rule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
NODEPTR _desc1;
NODEPTR _desc2;
};

struct _TPLST_xSymbolrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxSymbol _desc1;
_TSPLST_Syms _desc2;
};

struct _TPLST_0rule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
NODEPTR _desc1;
NODEPTR _desc2;
};

struct _TPLST_Itemrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPItem _desc1;
_TSPLST_Items _desc2;
};

struct _TPLST_0rule_8
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
_TSPItems _desc1;
};

struct _TPrule_2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPItems _desc1;
int _ATTERM_1;
};

struct _TPrule_3
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
int _ATTERM_2;
};

struct _TPrule_4
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_5
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_6
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_7
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATIdemPtg;
_TSPLST_Items _desc1;
};

struct _TPrule_9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATIdemPtg;
DefTableKey _ATKey;
int _ATTERM_1;
};

struct _TPrule_10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATIdemPtg;
_TSPPatternName _desc1;
_TSPItems _desc2;
};

struct _TPrule_11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATNontermCnt_pre;
int _ATTERM_1;
};

struct _TPrule_12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATNontermCnt_pre;
_TSPxSymbol _desc1;
};

struct _TPrule_13
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATNontermCnt_pre;
_TSPxSymbol _desc1;
};

struct _TPrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPLST_Syms _desc1;
};

struct _TPrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPLST_xRHS _desc1;
};

struct _TPrule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxRule _desc1;
_TSPxSymbol _desc2;
_TSPSyms _desc3;
};

struct _TPrule_17
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxRule _desc1;
_TSPxSymbol _desc2;
_TSPxRHS _desc3;
};

struct _TPrule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPLST_xGrammar _desc1;
};

struct _TPrule_26
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
int _ATIsTerminal;
int _ATTERM_1;
};

struct _TPrule_25
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
int _ATIsTerminal;
int _ATTERM_1;
};

struct _TPrule_24
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TPrule_23
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TPrule_22
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
CharPtr _ATPrefix;
_TSPxGrammar _desc1;
_TSPPTGSpec _desc2;
};

struct _TPrule_21
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG2 _desc1;
};

struct _TPrule_20
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG2 _desc1;
_TSPPatternSpec _desc2;
};

struct _TPrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

#undef _NODECOMMON
#endif
