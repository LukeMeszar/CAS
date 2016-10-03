
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

typedef struct _TSOperation* _TSPOperation;
typedef struct _TSIdentification* _TSPIdentification;
typedef struct _TSG6* _TSPG6;
typedef struct _TSG5* _TSPG5;
typedef struct _TSG4* _TSPG4;
typedef struct _TSG3* _TSPG3;
typedef struct _TSG2* _TSPG2;
typedef struct _TSSpecificationElement* _TSPSpecificationElement;
typedef struct _TSG12* _TSPG12;
typedef struct _TSG1* _TSPG1;
typedef struct _TSG8* _TSPG8;
typedef struct _TSG9* _TSPG9;
typedef struct _TSG10* _TSPG10;
typedef struct _TSClassOperation* _TSPClassOperation;
typedef struct _TSG11* _TSPG11;
typedef struct _TSG7* _TSPG7;
typedef struct _TSClassCoerce* _TSPClassCoerce;
typedef struct _TSClassOpDefList* _TSPClassOpDefList;
typedef struct _TSClassOper* _TSPClassOper;
typedef struct _TSClassSignature* _TSPClassSignature;
typedef struct _TSClassParameters* _TSPClassParameters;
typedef struct _TSClass* _TSPClass;
typedef struct _TSOpRefList* _TSPOpRefList;
typedef struct _TSIndication* _TSPIndication;
typedef struct _TSCoerce* _TSPCoerce;
typedef struct _TSOpDefList* _TSPOpDefList;
typedef struct _TSOper* _TSPOper;
typedef struct _TSSignatureElement* _TSPSignatureElement;
typedef struct _TSSignature* _TSPSignature;
typedef struct _TSSingleton* _TSPSingleton;
typedef struct _TSxTypeList* _TSPxTypeList;
typedef struct _TSxTypeExpr* _TSPxTypeExpr;
typedef struct _TSEquivalenceClass* _TSPEquivalenceClass;
typedef struct _TSClassBody* _TSPClassBody;
typedef struct _TSOIL* _TSPOIL;
typedef struct _TSSetIdUse* _TSPSetIdUse;
typedef struct _TSSetIdDef* _TSPSetIdDef;
typedef struct _TSOpRef* _TSPOpRef;
typedef struct _TSIndDef* _TSPIndDef;
typedef struct _TSClassParameter* _TSPClassParameter;
typedef struct _TSClassName* _TSPClassName;
typedef struct _TSTypeIdentifier* _TSPTypeIdentifier;
typedef struct _TSClassOpDef* _TSPClassOpDef;
typedef struct _TSOpDef* _TSPOpDef;
typedef struct _TSCostSpecification* _TSPCostSpecification;
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
typedef struct _TPrule_20* _TPPrule_20;
typedef struct _TPrule_21* _TPPrule_21;
typedef struct _TPrule_22* _TPPrule_22;
typedef struct _TPrule_23* _TPPrule_23;
typedef struct _TPrule_24* _TPPrule_24;
typedef struct _TPrule_25* _TPPrule_25;
typedef struct _TPrule_26* _TPPrule_26;
typedef struct _TPrule_27* _TPPrule_27;
typedef struct _TPrule_28* _TPPrule_28;
typedef struct _TPrule_29* _TPPrule_29;
typedef struct _TPrule_30* _TPPrule_30;
typedef struct _TPrule_31* _TPPrule_31;
typedef struct _TPrule_32* _TPPrule_32;
typedef struct _TPrule_33* _TPPrule_33;
typedef struct _TPrule_34* _TPPrule_34;
typedef struct _TPrule_35* _TPPrule_35;
typedef struct _TPrule_76* _TPPrule_76;
typedef struct _TPrule_75* _TPPrule_75;
typedef struct _TPrule_74* _TPPrule_74;
typedef struct _TPrule_73* _TPPrule_73;
typedef struct _TPrule_72* _TPPrule_72;
typedef struct _TPrule_71* _TPPrule_71;
typedef struct _TPrule_70* _TPPrule_70;
typedef struct _TPrule_69* _TPPrule_69;
typedef struct _TPrule_68* _TPPrule_68;
typedef struct _TPrule_67* _TPPrule_67;
typedef struct _TPrule_66* _TPPrule_66;
typedef struct _TPrule_65* _TPPrule_65;
typedef struct _TPrule_64* _TPPrule_64;
typedef struct _TPrule_63* _TPPrule_63;
typedef struct _TPrule_62* _TPPrule_62;
typedef struct _TPrule_61* _TPPrule_61;
typedef struct _TPrule_60* _TPPrule_60;
typedef struct _TPrule_59* _TPPrule_59;
typedef struct _TPrule_58* _TPPrule_58;
typedef struct _TPrule_57* _TPPrule_57;
typedef struct _TPrule_56* _TPPrule_56;
typedef struct _TPrule_55* _TPPrule_55;
typedef struct _TPrule_54* _TPPrule_54;
typedef struct _TPrule_53* _TPPrule_53;
typedef struct _TPrule_52* _TPPrule_52;
typedef struct _TPrule_51* _TPPrule_51;
typedef struct _TPrule_50* _TPPrule_50;
typedef struct _TPrule_49* _TPPrule_49;
typedef struct _TPrule_48* _TPPrule_48;
typedef struct _TPrule_47* _TPPrule_47;
typedef struct _TPrule_46* _TPPrule_46;
typedef struct _TPrule_45* _TPPrule_45;
typedef struct _TPrule_44* _TPPrule_44;
typedef struct _TPrule_43* _TPPrule_43;
typedef struct _TPrule_42* _TPPrule_42;
typedef struct _TPrule_41* _TPPrule_41;
typedef struct _TPrule_40* _TPPrule_40;
typedef struct _TPrule_39* _TPPrule_39;
typedef struct _TPrule_38* _TPPrule_38;
typedef struct _TPrule_37* _TPPrule_37;
typedef struct _TPrule_36* _TPPrule_36;

struct _TSOperation
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSIdentification
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG6
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG5
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG4
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG3
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

struct _TSSpecificationElement
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSClassOperation
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSG7
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSClassCoerce
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilClassArgSig _ATclassSignature;
};

struct _TSClassOpDefList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSClassOper
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilClassArgSig _ATclassSignature;
};

struct _TSClassSignature
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSClassParameters
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSClass
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilClass _ATclass;
};

struct _TSOpRefList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSIndication
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
};

struct _TSCoerce
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilArgSig _ATsignature;
};

struct _TSOpDefList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSOper
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilArgSig _ATsignature;
};

struct _TSSignatureElement
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSSignature
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSSingleton
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSxTypeList
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSxTypeExpr
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSEquivalenceClass
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSClassBody
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
};

struct _TSOIL
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
};

struct _TSSetIdUse
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSSetIdDef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSOpRef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSIndDef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSClassParameter
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSClassName
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
tOilClass _ATclass;
int _ATSym;
};

struct _TSTypeIdentifier
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATIsTypeFirstOcc;
DefTableKey _ATKey;
int _ATDoType;
tOilType _ATtype;
int _ATSym;
};

struct _TSClassOpDef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSOpDef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TSCostSpecification
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilClassArgSig _ATclassSignature;
_TSPClassOpDef _desc1;
_TSPClassSignature _desc2;
_TSPCostSpecification _desc3;
};

struct _TPrule_2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilClassArgSig _ATclassSignature;
_TSPClassOpDefList _desc1;
_TSPClassSignature _desc2;
_TSPCostSpecification _desc3;
};

struct _TPrule_3
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClassSignature _desc1;
_TSPSignatureElement _desc2;
};

struct _TPrule_4
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSignatureElement _desc1;
_TSPClassSignature _desc2;
};

struct _TPrule_5
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSignatureElement _desc1;
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
tOilClass _ATclass;
_TSPClassName _desc1;
_TSPClassBody _desc2;
};

struct _TPrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
tOilOp _ATindication;
_TSPIndDef _desc1;
_TSPOpRefList _desc2;
};

struct _TPrule_9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilArgSig _ATsignature;
_TSPOpDef _desc1;
_TSPSignature _desc2;
_TSPCostSpecification _desc3;
};

struct _TPrule_10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATcost;
tOilArgSig _ATsignature;
_TSPOpDefList _desc1;
_TSPSignature _desc2;
_TSPCostSpecification _desc3;
};

struct _TPrule_11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPTypeIdentifier _desc1;
};

struct _TPrule_12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSignature _desc1;
_TSPSignatureElement _desc2;
};

struct _TPrule_13
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSignatureElement _desc1;
_TSPSignature _desc2;
};

struct _TPrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSignatureElement _desc1;
};

struct _TPrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPTypeIdentifier _desc1;
};

struct _TPrule_17
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxTypeList _desc1;
};

struct _TPrule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxTypeExpr _desc1;
_TSPxTypeExpr _desc2;
};

struct _TPrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxTypeExpr _desc1;
_TSPxTypeExpr _desc2;
};

struct _TPrule_20
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPxTypeExpr _desc1;
_TSPxTypeExpr _desc2;
};

struct _TPrule_21
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSetIdUse _desc1;
POSITION _AT_pos;
};

struct _TPrule_22
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSetIdDef _desc1;
_TSPxTypeExpr _desc2;
};

struct _TPrule_23
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
POSITION _AT_pos;
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
POSITION _AT_pos;
};

struct _TPrule_25
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
POSITION _AT_pos;
int _ATTERM_1;
};

struct _TPrule_26
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
};

struct _TPrule_27
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
POSITION _AT_pos;
};

struct _TPrule_28
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
tOilClass _ATclass;
int _ATSym;
POSITION _AT_pos;
};

struct _TPrule_29
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATIsTypeFirstOcc;
DefTableKey _ATKey;
int _ATDoType;
tOilType _ATtype;
int _ATSym;
};

struct _TPrule_30
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
POSITION _AT_pos;
};

struct _TPrule_31
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
POSITION _AT_pos;
};

struct _TPrule_32
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
POSITION _AT_pos;
};

struct _TPrule_33
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATSym;
POSITION _AT_pos;
};

struct _TPrule_34
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_35
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_76
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG12 _desc1;
};

struct _TPrule_75
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPOperation _desc1;
};

struct _TPrule_74
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPIdentification _desc1;
};

struct _TPrule_73
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPEquivalenceClass _desc1;
};

struct _TPrule_72
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClass _desc1;
};

struct _TPrule_71
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG6 _desc1;
};

struct _TPrule_70
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG2 _desc1;
};

struct _TPrule_69
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG3 _desc1;
};

struct _TPrule_68
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG4 _desc1;
};

struct _TPrule_67
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
_TSPG1 _desc1;
};

struct _TPrule_66
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG5 _desc1;
};

struct _TPrule_65
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG9 _desc1;
_TSPClassOper _desc2;
};

struct _TPrule_64
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClassOper _desc1;
};

struct _TPrule_63
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG8 _desc1;
_TSPClassParameter _desc2;
};

struct _TPrule_62
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClassParameter _desc1;
};

struct _TPrule_61
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG7 _desc1;
_TSPClassOperation _desc2;
};

struct _TPrule_60
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClassOperation _desc1;
};

struct _TPrule_59
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPOpRef _desc1;
};

struct _TPrule_58
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG6 _desc1;
_TSPOpRef _desc2;
};

struct _TPrule_57
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPIndication _desc1;
};

struct _TPrule_56
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG5 _desc1;
_TSPIndication _desc2;
};

struct _TPrule_55
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPOpDef _desc1;
};

struct _TPrule_54
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG4 _desc1;
_TSPOpDef _desc2;
};

struct _TPrule_53
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG3 _desc1;
_TSPCoerce _desc2;
};

struct _TPrule_52
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPCoerce _desc1;
};

struct _TPrule_51
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPOper _desc1;
};

struct _TPrule_50
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG2 _desc1;
_TSPOper _desc2;
};

struct _TPrule_49
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG1 _desc1;
_TSPSpecificationElement _desc2;
};

struct _TPrule_48
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPSingleton _desc1;
};

struct _TPrule_47
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG12 _desc1;
_TSPSingleton _desc2;
};

struct _TPrule_46
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG11 _desc1;
_TSPClassOpDef _desc2;
};

struct _TPrule_45
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClassOpDef _desc1;
};

struct _TPrule_44
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG10 _desc1;
_TSPClassCoerce _desc2;
};

struct _TPrule_43
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPClassCoerce _desc1;
};

struct _TPrule_42
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_41
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG8 _desc1;
};

struct _TPrule_40
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG9 _desc1;
};

struct _TPrule_39
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG10 _desc1;
};

struct _TPrule_38
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPG11 _desc1;
};

struct _TPrule_37
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
_TSPClassParameters _desc1;
_TSPG7 _desc2;
};

struct _TPrule_36
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATEnv;
_TSPG7 _desc1;
};

#undef _NODECOMMON
#endif
