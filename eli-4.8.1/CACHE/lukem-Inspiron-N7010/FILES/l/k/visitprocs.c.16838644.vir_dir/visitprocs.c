
#include "HEAD.h"
#include "err.h"
#include "node.h"
#include "visitprocs.h"
#include "attrpredef.h"

#include "visitmap.h"

#ifdef MONITOR
#include "attr_mon_dapto.h"
#include "liga_dapto.h"
#endif

#ifndef _VisitVarDecl
#define _VisitVarDecl()
#endif

#ifndef _VisitEntry
#define _VisitEntry()
#endif

#ifndef _VisitExit
#define _VisitExit()
#endif


#if defined(__STDC__) || defined(__cplusplus)
#define _CALL_VS_(args) (void (*)args)
#else
#define _CALL_VS_(args) 
#endif
DefTableKey* _IG_incl5;
DefTableKey* _IG_incl4;
tOilType* _IG_incl3;
tOilType* _IG_incl2;
Environment* _IG_incl0;
tOilOp _AVUnop_operator;
tOilOp _AVNotop_operator;
tOilOp _AVStatement_operator_RuleAttr_84;
int _AVIdUse_Sym;
int _AVIdDef_Sym;

#if defined(__STDC__) || defined(__cplusplus)
void LIGA_ATTREVAL (NODEPTR _currn)
#else
void LIGA_ATTREVAL (_currn) NODEPTR _currn;
#endif
{(*(VS1MAP[_currn->_prod])) ((NODEPTR)_currn);}
/*SPC(0)*/

#if defined(__STDC__) || defined(__cplusplus)
void _VS0Empty(NODEPTR _currn)
#else
void _VS0Empty(_currn) NODEPTR _currn;
#endif
{ _VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_15(_TPPrule_15 _currn)
#else
void _VS1rule_15(_currn )
_TPPrule_15 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_15(_TPPrule_15 _currn)
#else
void _VS2rule_15(_currn )
_TPPrule_15 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_14(_TPPrule_14 _currn)
#else
void _VS1rule_14(_currn )
_TPPrule_14 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_14(_TPPrule_14 _currn)
#else
void _VS2rule_14(_currn )
_TPPrule_14 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_11(_TPPrule_11 _currn)
#else
void _VS1rule_11(_currn )
_TPPrule_11 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_11(_TPPrule_11 _currn)
#else
void _VS2rule_11(_currn )
_TPPrule_11 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_8(_TPPrule_8 _currn)
#else
void _VS1rule_8(_currn )
_TPPrule_8 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATEnv=NewScope((* _IG_incl0));
/*SPC(28)*/
#ifdef MONITOR
_dapto_attr_Environment((_currn->_desc1->_uid), 1, "Env", _currn->_desc1->_ATEnv, 28, 3);
#endif
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_8(_TPPrule_8 _currn)
#else
void _VS2rule_8(_currn )
_TPPrule_8 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_3(_TPPrule_3 _currn)
#else
void _VS1rule_3(_currn )
_TPPrule_3 _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_3(_TPPrule_3 _currn)
#else
void _VS2rule_3(_currn )
_TPPrule_3 _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_2(_TPPrule_2 _currn)
#else
void _VS1rule_2(_currn )
_TPPrule_2 _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_2(_TPPrule_2 _currn)
#else
void _VS2rule_2(_currn )
_TPPrule_2 _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_1(_TPPrule_1 _currn)
#else
void _VS1rule_1(_currn )
_TPPrule_1 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATEnv=NewEnv();
/*SPC(23)*/
#ifdef MONITOR
_dapto_attr_Environment((_currn->_desc1->_uid), 1, "Env", _currn->_desc1->_ATEnv, 23, 3);
#endif
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1MonadicExp(_TPPMonadicExp _currn)
#else
void _VS1MonadicExp(_currn )
_TPPMonadicExp _currn;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2MonadicExp(_TPPMonadicExp _currn)
#else
void _VS2MonadicExp(_currn )
_TPPMonadicExp _currn;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATpossible=OilIdResultTS1(_currn->_desc1->_ATindication, _currn->_desc2->_ATpossible);
/*SPC(321)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 321, 11);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3MonadicExp(_TPPMonadicExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3MonadicExp(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPMonadicExp _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
_AVUnop_operator=OilIdOpTS1((* _AS0yields), _currn->_desc1->_ATindication, _currn->_desc2->_ATpossible);
/*SPC(325)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_desc1->_uid), 1, "operator", _AVUnop_operator, 325, 11);
#endif
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS2yields=OilGetArgType(_AVUnop_operator, 1);
/*SPC(330)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc2->_uid), 1, "yields", _AS2yields, 330, 11);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2yields)),(&( _AS2operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1DyadicExp(_TPPDyadicExp _currn)
#else
void _VS1DyadicExp(_currn )
_TPPDyadicExp _currn;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2DyadicExp(_TPPDyadicExp _currn)
#else
void _VS2DyadicExp(_currn )
_TPPDyadicExp _currn;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATpossible=OilIdResultTS2(_currn->_desc2->_ATindication, _currn->_desc1->_ATpossible, _currn->_desc3->_ATpossible);
/*SPC(301)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 301, 11);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3DyadicExp(_TPPDyadicExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3DyadicExp(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPDyadicExp _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
_AS2operator=OilIdOpTS2((* _AS0yields), _currn->_desc2->_ATindication, _currn->_desc1->_ATpossible, _currn->_desc3->_ATpossible);
/*SPC(306)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_desc2->_uid), 1, "operator", _AS2operator, 306, 11);
#endif
_AS1yields=OilGetArgType(_AS2operator, 1);
/*SPC(312)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 312, 11);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));
(*(_CALL_VS_((NODEPTR ,tOilOp*)) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2operator)));
_AS3yields=OilGetArgType(_AS2operator, 2);
/*SPC(313)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc3->_uid), 1, "yields", _AS3yields, 313, 11);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3,(&( _AS3yields)),(&( _AS3operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1IdnVal(_TPPIdnVal _currn)
#else
void _VS1IdnVal(_currn )
_TPPIdnVal _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2IdnVal(_TPPIdnVal _currn)
#else
void _VS2IdnVal(_currn )
_TPPIdnVal _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATpossible=OilTypeToSet(GetType(_currn->_desc1->_ATKey, OilTypeunknown_t));
/*SPC(290)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 290, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3IdnVal(_TPPIdnVal _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3IdnVal(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPIdnVal _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2FloatVal(_TPPFloatVal _currn)
#else
void _VS2FloatVal(_currn )
_TPPFloatVal _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATpossible=OilTypeToSet(OilTypefloat_t);
/*SPC(285)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 285, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3FloatVal(_TPPFloatVal _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3FloatVal(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPFloatVal _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2IntVal(_TPPIntVal _currn)
#else
void _VS2IntVal(_currn )
_TPPIntVal _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATpossible=OilTypeToSet(OilTypeint_t);
/*SPC(281)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 281, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3IntVal(_TPPIntVal _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3IntVal(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPIntVal _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2FloatParDecl(_TPPFloatParDecl _currn)
#else
void _VS2FloatParDecl(_currn )
_TPPFloatParDecl _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
SetType(_currn->_desc1->_ATKey, OilTypefloat_t, 0);
/*SPC(274)*/
#ifdef MONITOR
_dapto_void_comp ((_currn->_uid), "GotType", 274, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2IntParDecl(_TPPIntParDecl _currn)
#else
void _VS2IntParDecl(_currn )
_TPPIntParDecl _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
SetType(_currn->_desc1->_ATKey, OilTypeint_t, 0);
/*SPC(269)*/
#ifdef MONITOR
_dapto_void_comp ((_currn->_uid), "GotType", 269, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2Initialize(_TPPInitialize _currn)
#else
void _VS2Initialize(_currn )
_TPPInitialize _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS1yields=(* _IG_incl2);
/*SPC(264)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 264, 9);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1VarDecl(_TPPVarDecl _currn)
#else
void _VS1VarDecl(_currn )
_TPPVarDecl _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
SetType(_currn->_desc1->_ATKey, (* _IG_incl2), 0);
/*SPC(259)*/
#ifdef MONITOR
_dapto_void_comp ((_currn->_uid), "GotType", 259, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1FloatVar(_TPPFloatVar _currn)
#else
void _VS1FloatVar(_currn )
_TPPFloatVar _currn;

#endif
{
tOilType* _IL_incl2;

_VisitVarDecl()
_VisitEntry();
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATtype);
_currn->_ATtype=OilTypefloat_t;
/*SPC(254)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_uid), 1, "type", _currn->_ATtype, 254, 9);
#endif
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl2=_IL_incl2;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2FloatVar(_TPPFloatVar _currn)
#else
void _VS2FloatVar(_currn )
_TPPFloatVar _currn;

#endif
{
tOilType* _IL_incl2;

_VisitVarDecl()
_VisitEntry();
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATtype);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl2=_IL_incl2;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1IntVar(_TPPIntVar _currn)
#else
void _VS1IntVar(_currn )
_TPPIntVar _currn;

#endif
{
tOilType* _IL_incl2;

_VisitVarDecl()
_VisitEntry();
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATtype);
_currn->_ATtype=OilTypeint_t;
/*SPC(250)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_uid), 1, "type", _currn->_ATtype, 250, 9);
#endif
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl2=_IL_incl2;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2IntVar(_TPPIntVar _currn)
#else
void _VS2IntVar(_currn )
_TPPIntVar _currn;

#endif
{
tOilType* _IL_incl2;

_VisitVarDecl()
_VisitEntry();
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATtype);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl2=_IL_incl2;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1UMinusOp(_TPPUMinusOp _currn)
#else
void _VS1UMinusOp(_currn )
_TPPUMinusOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpUMinus;
/*SPC(238)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 238, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2UMinusOp(_TPPUMinusOp _currn)
#else
void _VS2UMinusOp(_currn )
_TPPUMinusOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp(_AVUnop_operator))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1PercentOp(_TPPPercentOp _currn)
#else
void _VS1PercentOp(_currn )
_TPPPercentOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpPercent;
/*SPC(234)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 234, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2PercentOp(_TPPPercentOp _currn,tOilOp* _AS0operator)
#else
void _VS2PercentOp(_currn ,_AS0operator)
_TPPPercentOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1SlashOp(_TPPSlashOp _currn)
#else
void _VS1SlashOp(_currn )
_TPPSlashOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpSlash;
/*SPC(230)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 230, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2SlashOp(_TPPSlashOp _currn,tOilOp* _AS0operator)
#else
void _VS2SlashOp(_currn ,_AS0operator)
_TPPSlashOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1StarOp(_TPPStarOp _currn)
#else
void _VS1StarOp(_currn )
_TPPStarOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpStar;
/*SPC(226)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 226, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2StarOp(_TPPStarOp _currn,tOilOp* _AS0operator)
#else
void _VS2StarOp(_currn ,_AS0operator)
_TPPStarOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1MinusOp(_TPPMinusOp _currn)
#else
void _VS1MinusOp(_currn )
_TPPMinusOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpMinus;
/*SPC(222)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 222, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2MinusOp(_TPPMinusOp _currn,tOilOp* _AS0operator)
#else
void _VS2MinusOp(_currn ,_AS0operator)
_TPPMinusOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1PlusOp(_TPPPlusOp _currn)
#else
void _VS1PlusOp(_currn )
_TPPPlusOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpPlus;
/*SPC(218)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 218, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2PlusOp(_TPPPlusOp _currn,tOilOp* _AS0operator)
#else
void _VS2PlusOp(_currn ,_AS0operator)
_TPPPlusOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1GreaterOp(_TPPGreaterOp _currn)
#else
void _VS1GreaterOp(_currn )
_TPPGreaterOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpGreater;
/*SPC(213)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 213, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2GreaterOp(_TPPGreaterOp _currn,tOilOp* _AS0operator)
#else
void _VS2GreaterOp(_currn ,_AS0operator)
_TPPGreaterOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1LessOp(_TPPLessOp _currn)
#else
void _VS1LessOp(_currn )
_TPPLessOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpLess;
/*SPC(209)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 209, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LessOp(_TPPLessOp _currn,tOilOp* _AS0operator)
#else
void _VS2LessOp(_currn ,_AS0operator)
_TPPLessOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1EqualOp(_TPPEqualOp _currn)
#else
void _VS1EqualOp(_currn )
_TPPEqualOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpEquEqu;
/*SPC(205)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 205, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2EqualOp(_TPPEqualOp _currn,tOilOp* _AS0operator)
#else
void _VS2EqualOp(_currn ,_AS0operator)
_TPPEqualOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1ExclOp(_TPPExclOp _currn)
#else
void _VS1ExclOp(_currn )
_TPPExclOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpExclam;
/*SPC(200)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 200, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2ExclOp(_TPPExclOp _currn)
#else
void _VS2ExclOp(_currn )
_TPPExclOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp(_AVNotop_operator))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1NotExp(_TPPNotExp _currn)
#else
void _VS1NotExp(_currn )
_TPPNotExp _currn;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2NotExp(_TPPNotExp _currn)
#else
void _VS2NotExp(_currn )
_TPPNotExp _currn;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATpossible=OilIdResultTS1(_currn->_desc1->_ATindication, _currn->_desc2->_ATpossible);
/*SPC(186)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 186, 11);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3NotExp(_TPPNotExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3NotExp(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPNotExp _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
_AVNotop_operator=OilIdOpTS1((* _AS0yields), _currn->_desc1->_ATindication, _currn->_desc2->_ATpossible);
/*SPC(190)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_desc1->_uid), 1, "operator", _AVNotop_operator, 190, 11);
#endif
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS2yields=OilGetArgType(_AVNotop_operator, 1);
/*SPC(195)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc2->_uid), 1, "yields", _AS2yields, 195, 11);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2yields)),(&( _AS2operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1AmpOp(_TPPAmpOp _currn)
#else
void _VS1AmpOp(_currn )
_TPPAmpOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpAmpAmp;
/*SPC(179)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 179, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2AmpOp(_TPPAmpOp _currn,tOilOp* _AS0operator)
#else
void _VS2AmpOp(_currn ,_AS0operator)
_TPPAmpOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1BarOp(_TPPBarOp _currn)
#else
void _VS1BarOp(_currn )
_TPPBarOp _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATindication=OilOpBarBar;
/*SPC(175)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 1, "indication", _currn->_ATindication, 175, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2BarOp(_TPPBarOp _currn,tOilOp* _AS0operator)
#else
void _VS2BarOp(_currn ,_AS0operator)
_TPPBarOp _currn;
tOilOp* _AS0operator;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(OilIsValidOp((* _AS0operator)))) {
message(FATAL, "Invalid operator in this context", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 336, 59);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1ShortCircuitExp(_TPPShortCircuitExp _currn)
#else
void _VS1ShortCircuitExp(_currn )
_TPPShortCircuitExp _currn;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2ShortCircuitExp(_TPPShortCircuitExp _currn)
#else
void _VS2ShortCircuitExp(_currn )
_TPPShortCircuitExp _currn;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATpossible=OilIdResultTS2(_currn->_desc2->_ATindication, _currn->_desc1->_ATpossible, _currn->_desc3->_ATpossible);
/*SPC(158)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 158, 11);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3ShortCircuitExp(_TPPShortCircuitExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3ShortCircuitExp(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPShortCircuitExp _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
_AS2operator=OilIdOpTS2((* _AS0yields), _currn->_desc2->_ATindication, _currn->_desc1->_ATpossible, _currn->_desc3->_ATpossible);
/*SPC(163)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_desc2->_uid), 1, "operator", _AS2operator, 163, 11);
#endif
_AS1yields=OilGetArgType(_AS2operator, 1);
/*SPC(169)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 169, 11);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));
(*(_CALL_VS_((NODEPTR ,tOilOp*)) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2operator)));
_AS3yields=OilGetArgType(_AS2operator, 2);
/*SPC(170)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc3->_uid), 1, "yields", _AS3yields, 170, 11);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3,(&( _AS3yields)),(&( _AS3operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1CondExp(_TPPCondExp _currn)
#else
void _VS1CondExp(_currn )
_TPPCondExp _currn;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2CondExp(_TPPCondExp _currn)
#else
void _VS2CondExp(_currn )
_TPPCondExp _currn;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS1yields=OilTypeint_t;
/*SPC(148)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 148, 3);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_currn->_ATpossible=OilTypeToSet(OilBalance(_currn->_desc2->_ATpossible, _currn->_desc3->_ATpossible));
/*SPC(146)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 146, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3CondExp(_TPPCondExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3CondExp(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPCondExp _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{
tOilOp _AS3operator_RuleAttr_79;
tOilType _AS3yields;
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
_AS2yields=(* _AS0yields);
/*SPC(149)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc2->_uid), 1, "yields", _AS2yields, 149, 3);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2yields)),(&( _AS2operator_RuleAttr_79)));
_AS3yields=(* _AS0yields);
/*SPC(150)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc3->_uid), 1, "yields", _AS3yields, 150, 3);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3,(&( _AS3yields)),(&( _AS3operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1AssignExp(_TPPAssignExp _currn)
#else
void _VS1AssignExp(_currn )
_TPPAssignExp _currn;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2AssignExp(_TPPAssignExp _currn)
#else
void _VS2AssignExp(_currn )
_TPPAssignExp _currn;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATpossible_RuleAttr_79=OilTypeToSet(GetType(_currn->_desc1->_ATKey, OilTypeunknown_t));
/*SPC(126)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 0, "possible", _currn->_ATpossible_RuleAttr_79, 126, 3);
#endif
_currn->_ATpossible=OilIdResultTS2(OilOpEqual, _currn->_ATpossible_RuleAttr_79, _currn->_desc2->_ATpossible);
/*SPC(135)*/
#ifdef MONITOR
_dapto_attr_tOilTypeSet((_currn->_uid), 1, "possible", _currn->_ATpossible, 135, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3AssignExp(_TPPAssignExp _currn,tOilType* _AS0yields,tOilOp* _AS0operator_RuleAttr_79)
#else
void _VS3AssignExp(_currn ,_AS0yields,_AS0operator_RuleAttr_79)
_TPPAssignExp _currn;
tOilOp* _AS0operator_RuleAttr_79;
tOilType* _AS0yields;

#endif
{
tOilOp _AS2operator_RuleAttr_79;
tOilType _AS2yields;

_VisitVarDecl()
_VisitEntry();
(* _AS0operator_RuleAttr_79)=OilIdOpTS2((* _AS0yields), OilOpEqual, _currn->_ATpossible_RuleAttr_79, _currn->_desc2->_ATpossible);
/*SPC(129)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 0, "operator", (* _AS0operator_RuleAttr_79), 129, 3);
#endif
_AS2yields=OilGetArgType((* _AS0operator_RuleAttr_79), 2);
/*SPC(140)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc2->_uid), 1, "yields", _AS2yields, 140, 3);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2yields)),(&( _AS2operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1ExprStmt(_TPPExprStmt _currn)
#else
void _VS1ExprStmt(_currn )
_TPPExprStmt _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2ExprStmt(_TPPExprStmt _currn)
#else
void _VS2ExprStmt(_currn )
_TPPExprStmt _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS1yields=OilTypevoid_t;
/*SPC(119)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 119, 9);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1FloatResult(_TPPFloatResult _currn)
#else
void _VS1FloatResult(_currn )
_TPPFloatResult _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATtype=OilTypefloat_t;
/*SPC(115)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_uid), 1, "type", _currn->_ATtype, 115, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1IntResult(_TPPIntResult _currn)
#else
void _VS1IntResult(_currn )
_TPPIntResult _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATtype=OilTypeint_t;
/*SPC(111)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_uid), 1, "type", _currn->_ATtype, 111, 9);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1Source(_TPPSource _currn)
#else
void _VS1Source(_currn )
_TPPSource _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc3->_ATEnv=NewScope(_currn->_ATEnv);
/*SPC(28)*/
#ifdef MONITOR
_dapto_attr_Environment((_currn->_desc3->_uid), 1, "Env", _currn->_desc3->_ATEnv, 28, 3);
#endif
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2Source(_TPPSource _currn)
#else
void _VS2Source(_currn )
_TPPSource _currn;

#endif
{
DefTableKey* _IL_incl5;
DefTableKey* _IL_incl4;
tOilType* _IL_incl3;
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATBreakLbl);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATContinueLbl);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATtype);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATtype=_currn->_desc1->_ATtype;
/*SPC(107)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_uid), 1, "type", _currn->_ATtype, 107, 9);
#endif
_currn->_ATContinueLbl=NoKey;
/*SPC(88)*/
#ifdef MONITOR
_dapto_attr_DefTableKey((_currn->_uid), 1, "ContinueLbl", _currn->_ATContinueLbl, 88, 24);
#endif
_currn->_ATBreakLbl=NoKey;
/*SPC(77)*/
#ifdef MONITOR
_dapto_attr_DefTableKey((_currn->_uid), 1, "BreakLbl", _currn->_ATBreakLbl, 77, 24);
#endif
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;
_IG_incl3=_IL_incl3;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1ReturnStmt(_TPPReturnStmt _currn)
#else
void _VS1ReturnStmt(_currn )
_TPPReturnStmt _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2ReturnStmt(_TPPReturnStmt _currn)
#else
void _VS2ReturnStmt(_currn )
_TPPReturnStmt _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVStatement_operator_RuleAttr_84=OilIdOpTS1((* _IG_incl3), OilOpReturn, _currn->_desc1->_ATpossible);
/*SPC(98)*/
#ifdef MONITOR
_dapto_attr_tOilOp((_currn->_uid), 0, "operator", _AVStatement_operator_RuleAttr_84, 98, 3);
#endif
_AS1yields=OilGetArgType(_AVStatement_operator_RuleAttr_84, 1);
/*SPC(103)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 103, 3);
#endif

if (NOT(OilIsValidOp(_AVStatement_operator_RuleAttr_84))) {
message(FATAL, "Returned value incompatible with program type", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(102)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 102, 16);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1ContinueStmt(_TPPContinueStmt _currn)
#else
void _VS1ContinueStmt(_currn )
_TPPContinueStmt _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2ContinueStmt(_TPPContinueStmt _currn)
#else
void _VS2ContinueStmt(_currn )
_TPPContinueStmt _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ((* _IG_incl4), NoKey)) {
message(FATAL, "continue must be inside an iteration", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(93)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 93, 63);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1BreakStmt(_TPPBreakStmt _currn)
#else
void _VS1BreakStmt(_currn )
_TPPBreakStmt _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2BreakStmt(_TPPBreakStmt _currn)
#else
void _VS2BreakStmt(_currn )
_TPPBreakStmt _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ((* _IG_incl5), NoKey)) {
message(FATAL, "break must be inside an iteration", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(82)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 82, 60);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1Loop(_TPPLoop _currn)
#else
void _VS1Loop(_currn )
_TPPLoop _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2Loop(_TPPLoop _currn)
#else
void _VS2Loop(_currn )
_TPPLoop _currn;

#endif
{
DefTableKey* _IL_incl5;
DefTableKey* _IL_incl4;
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATBreakLbl);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATContinueLbl);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS1yields=OilTypeint_t;
/*SPC(71)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 71, 9);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));
_currn->_ATContinueLbl=NewKey();
/*SPC(87)*/
#ifdef MONITOR
_dapto_attr_DefTableKey((_currn->_uid), 1, "ContinueLbl", _currn->_ATContinueLbl, 87, 26);
#endif
_currn->_ATBreakLbl=NewKey();
/*SPC(76)*/
#ifdef MONITOR
_dapto_attr_DefTableKey((_currn->_uid), 1, "BreakLbl", _currn->_ATBreakLbl, 76, 26);
#endif
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl5=_IL_incl5;
_IG_incl4=_IL_incl4;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1TwoSided(_TPPTwoSided _currn)
#else
void _VS1TwoSided(_currn )
_TPPTwoSided _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2TwoSided(_TPPTwoSided _currn)
#else
void _VS2TwoSided(_currn )
_TPPTwoSided _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS1yields=OilTypeint_t;
/*SPC(67)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 67, 9);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1OneSided(_TPPOneSided _currn)
#else
void _VS1OneSided(_currn )
_TPPOneSided _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2OneSided(_TPPOneSided _currn)
#else
void _VS2OneSided(_currn )
_TPPOneSided _currn;

#endif
{
tOilOp _AS1operator_RuleAttr_79;
tOilType _AS1yields;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AS1yields=OilTypeint_t;
/*SPC(63)*/
#ifdef MONITOR
_dapto_attr_tOilType((_currn->_desc1->_uid), 1, "yields", _AS1yields, 63, 9);
#endif
(*(_CALL_VS_((NODEPTR ,tOilType*,tOilOp*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1yields)),(&( _AS1operator_RuleAttr_79)));
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1AppliedOccurrence(_TPPAppliedOccurrence _currn)
#else
void _VS1AppliedOccurrence(_currn )
_TPPAppliedOccurrence _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVIdUse_Sym=_currn->_ATTERM_1;
/*SPC(9)*/
#ifdef MONITOR
_dapto_attr_int((_currn->_uid), 1, "Sym", _AVIdUse_Sym, 9, 9);
#endif
_currn->_ATKey=KeyInEnv((* _IG_incl0), _AVIdUse_Sym);
/*SPC(38)*/
#ifdef MONITOR
_dapto_attr_DefTableKey((_currn->_uid), 1, "Key", _currn->_ATKey, 38, 3);
#endif

if (EQ(_currn->_ATKey, NoKey)) {
message(FATAL, "Undefined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(57)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 57, 69);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1DefiningOccurrence(_TPPDefiningOccurrence _currn)
#else
void _VS1DefiningOccurrence(_currn )
_TPPDefiningOccurrence _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVIdDef_Sym=_currn->_ATTERM_1;
/*SPC(5)*/
#ifdef MONITOR
_dapto_attr_int((_currn->_uid), 1, "Sym", _AVIdDef_Sym, 5, 9);
#endif
_currn->_ATKey=DefineIdn((* _IG_incl0), _AVIdDef_Sym);
/*SPC(32)*/
#ifdef MONITOR
_dapto_attr_DefTableKey((_currn->_uid), 1, "Key", _currn->_ATKey, 32, 3);
#endif
SetDef(_currn->_ATKey, 1, 2);
/*SPC(49)*/
#ifdef MONITOR
_dapto_void_comp ((_currn->_uid), "Def", 49, 3);
#endif

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2DefiningOccurrence(_TPPDefiningOccurrence _currn)
#else
void _VS2DefiningOccurrence(_currn )
_TPPDefiningOccurrence _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ(GetDef(_currn->_ATKey, 0), 2)) {
message(FATAL, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(52)*/
#ifdef MONITOR
_dapto_computation (_currn->_uid, 52, 16);
#endif

_VisitExit();
}

