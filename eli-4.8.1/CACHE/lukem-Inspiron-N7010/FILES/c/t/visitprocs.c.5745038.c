
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
int* _IG_incl17;
tOilArgSig* _IG_incl16;
tOilClass* _IG_incl15;
int* _IG_incl14;
tOilClassArgSig* _IG_incl13;
Environment* _IG_incl12;
tOilOp* _IG_incl9;
Environment* _IG_incl8;
Environment* _IG_incl6;
PTGNode _AVIdentificationOilExterns_post;
PTGNode _AVIdentificationKnownKeys_post;
DefTableKeyList _AVG11SetNames_post;
DefTableKeyList _AVG12partialSet_post;
int _AVG8__const1;
int _AVClassParameterParameterIndex_post;
SetBindingState _AVClassCoerce_SetBinding;
SetBindingState _AVClassOper_SetBinding;
tOilClassArgSig _AVClassSignature_classSignature;
int _AVClassParameters__const1;
SetBindingState _AVCoerce_SetBinding;
SetBindingState _AVOper_SetBinding;
tOilArgSig _AVSignature_signature;
int _AVClassBody__const1;
DefTableKey _AVSetIdUse_Key;
int _AVSetIdUse_Sym;
int _AVSetIdDef_Unique;
DefTableKey _AVOpRef_Key;
int _AVOpRef_Sym;
int _AVIndDef_IsOperFirstOcc;
int _AVIndDef_IsFirstOcc;
PTGNode _AVIndDef_Ptg;
int _AVClassParameter_IsFirstOcc;
int _AVClassParameter_Unique;
PTGNode _AVClassName_Ptg;
int _AVClassName_IsFirstOcc;
int _AVClassName_argNum;
int _AVClassName_Unique;
int _AVTypeIdentifier_IsFirstOcc;
PTGNode _AVTypeIdentifier_Ptg;
PTGNode _AVClassOpDef_Ptg;
int _AVClassOpDef_IsFirstOcc;
int _AVClassOpDef_Unique;
int _AVOpDef_IsOperFirstOcc;
int _AVOpDef_IsFirstOcc;
PTGNode _AVOpDef_Ptg;
int _AVOpDef_Unique;
int _AVCostSpecification_cost;

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
void _VS1rule_1(_TPPrule_1 _currn)
#else
void _VS1rule_1(_currn )
_TPPrule_1 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_1(_TPPrule_1 _currn)
#else
void _VS2rule_1(_currn )
_TPPrule_1 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_1(_TPPrule_1 _currn)
#else
void _VS3rule_1(_currn )
_TPPrule_1 _currn;

#endif
{
int* _IL_incl14;
tOilClassArgSig* _IL_incl13;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATcost);
_IL_incl13=_IG_incl13;_IG_incl13= &(_currn->_ATclassSignature);
_AVG11SetNames_post=NULLDefTableKeyList;
/*SPC(406)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_AVClassCoerce_SetBinding=FirstSetBinding(_AVG11SetNames_post);

_CYCLE0SetBinding:;
;
/*SPC(411)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATcost=_AVCostSpecification_cost;
/*SPC(633)*/
_currn->_ATclassSignature=_AVClassSignature_classSignature;
/*SPC(632)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
AddClassCoercions(_currn->_desc1->_ATKey);
/*SPC(634)*/

if (!(EQ(_AVClassCoerce_SetBinding, NoSetBinding))) {
_AVClassCoerce_SetBinding=NextSetBinding(_AVClassCoerce_SetBinding);

goto _CYCLE0SetBinding;
}
;
/*SPC(413)*/
_IG_incl14=_IL_incl14;
_IG_incl13=_IL_incl13;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_1(_TPPrule_1 _currn)
#else
void _VS4rule_1(_currn )
_TPPrule_1 _currn;

#endif
{
int* _IL_incl14;
tOilClassArgSig* _IL_incl13;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATcost);
_IL_incl13=_IG_incl13;_IG_incl13= &(_currn->_ATclassSignature);
_AVClassOpDef_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl14=_IL_incl14;
_IG_incl13=_IL_incl13;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_2(_TPPrule_2 _currn)
#else
void _VS1rule_2(_currn )
_TPPrule_2 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_2(_TPPrule_2 _currn)
#else
void _VS2rule_2(_currn )
_TPPrule_2 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_2(_TPPrule_2 _currn)
#else
void _VS3rule_2(_currn )
_TPPrule_2 _currn;

#endif
{
int* _IL_incl14;
tOilClassArgSig* _IL_incl13;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATcost);
_IL_incl13=_IG_incl13;_IG_incl13= &(_currn->_ATclassSignature);
_AVG11SetNames_post=NULLDefTableKeyList;
/*SPC(406)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_AVClassOper_SetBinding=FirstSetBinding(_AVG11SetNames_post);

_CYCLE0SetBinding:;
;
/*SPC(411)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATcost=_AVCostSpecification_cost;
/*SPC(626)*/
_currn->_ATclassSignature=_AVClassSignature_classSignature;
/*SPC(625)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (!(EQ(_AVClassOper_SetBinding, NoSetBinding))) {
_AVClassOper_SetBinding=NextSetBinding(_AVClassOper_SetBinding);

goto _CYCLE0SetBinding;
}
;
/*SPC(413)*/
_IG_incl14=_IL_incl14;
_IG_incl13=_IL_incl13;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_2(_TPPrule_2 _currn)
#else
void _VS4rule_2(_currn )
_TPPrule_2 _currn;

#endif
{
int* _IL_incl14;
tOilClassArgSig* _IL_incl13;

_VisitVarDecl()
_VisitEntry();
_IL_incl14=_IG_incl14;_IG_incl14= &(_currn->_ATcost);
_IL_incl13=_IG_incl13;_IG_incl13= &(_currn->_ATclassSignature);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl14=_IL_incl14;
_IG_incl13=_IL_incl13;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_3(_TPPrule_3 _currn)
#else
void _VS1rule_3(_currn )
_TPPrule_3 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_3(_TPPrule_3 _currn)
#else
void _VS2rule_3(_currn )
_TPPrule_3 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_3(_TPPrule_3 _currn)
#else
void _VS3rule_3(_currn )
_TPPrule_3 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_3(_TPPrule_3 _currn)
#else
void _VS4rule_3(_currn )
_TPPrule_3 _currn;

#endif
{
DefTableKey _AS2Key;
tOilType _AS2type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2type)),(&( _AS2Key)));
_AVClassSignature_classSignature=OilAddClassSigArg(GetBindingStatus(_AS2Key, eSpecTypeRef), _AS2type, GetParameterIndex(_AS2Key, 0), _AVClassSignature_classSignature);
/*SPC(595)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_3(_TPPrule_3 _currn)
#else
void _VS5rule_3(_currn )
_TPPrule_3 _currn;

#endif
{
DefTableKey _AS2Key;
tOilType _AS2type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2type)),(&( _AS2Key)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_4(_TPPrule_4 _currn)
#else
void _VS3rule_4(_currn )
_TPPrule_4 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_4(_TPPrule_4 _currn)
#else
void _VS4rule_4(_currn )
_TPPrule_4 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVClassSignature_classSignature=OilAddClassSigArg(GetBindingStatus(_AS1Key, eSpecTypeRef), _AS1type, GetParameterIndex(_AS1Key, 0), _AVClassSignature_classSignature);
/*SPC(585)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_4(_TPPrule_4 _currn)
#else
void _VS5rule_4(_currn )
_TPPrule_4 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_5(_TPPrule_5 _currn)
#else
void _VS1rule_5(_currn )
_TPPrule_5 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_5(_TPPrule_5 _currn)
#else
void _VS2rule_5(_currn )
_TPPrule_5 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_5(_TPPrule_5 _currn)
#else
void _VS3rule_5(_currn )
_TPPrule_5 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_5(_TPPrule_5 _currn)
#else
void _VS4rule_5(_currn )
_TPPrule_5 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));
_AVClassSignature_classSignature=OilAddClassSigArg(GetBindingStatus(_AS1Key, eSpecTypeRef), _AS1type, GetParameterIndex(_AS1Key, 0), OilNewClassSigArg());
/*SPC(575)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_5(_TPPrule_5 _currn)
#else
void _VS5rule_5(_currn )
_TPPrule_5 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_6(_TPPrule_6 _currn)
#else
void _VS4rule_6(_currn )
_TPPrule_6 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassSignature_classSignature=OilNewClassSigArg();
/*SPC(570)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_7(_TPPrule_7 _currn)
#else
void _VS1rule_7(_currn )
_TPPrule_7 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_7(_TPPrule_7 _currn)
#else
void _VS2rule_7(_currn )
_TPPrule_7 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVClassName_argNum=_AVClassBody__const1;
/*SPC(526)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_7(_TPPrule_7 _currn)
#else
void _VS3rule_7(_currn )
_TPPrule_7 _currn;

#endif
{
tOilClass* _IL_incl15;

_VisitVarDecl()
_VisitEntry();
_IL_incl15=_IG_incl15;_IG_incl15= &(_currn->_ATclass);
_currn->_ATclass=_currn->_desc1->_ATclass;
/*SPC(525)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl15=_IL_incl15;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_7(_TPPrule_7 _currn)
#else
void _VS4rule_7(_currn )
_TPPrule_7 _currn;

#endif
{
tOilClass* _IL_incl15;

_VisitVarDecl()
_VisitEntry();
_IL_incl15=_IG_incl15;_IG_incl15= &(_currn->_ATclass);
_AVClassName_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl15=_IL_incl15;

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
void _VS3rule_8(_TPPrule_8 _currn)
#else
void _VS3rule_8(_currn )
_TPPrule_8 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_8(_TPPrule_8 _currn)
#else
void _VS4rule_8(_currn )
_TPPrule_8 _currn;

#endif
{
tOilOp* _IL_incl9;

_VisitVarDecl()
_VisitEntry();
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATindication);
_currn->_ATindication=HeadtOilOpList(GetOperator(_currn->_desc1->_ATKey, NULLtOilOpList));
/*SPC(488)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl9=_IL_incl9;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_8(_TPPrule_8 _currn)
#else
void _VS5rule_8(_currn )
_TPPrule_8 _currn;

#endif
{
tOilOp* _IL_incl9;

_VisitVarDecl()
_VisitEntry();
_IL_incl9=_IG_incl9;_IG_incl9= &(_currn->_ATindication);
_AVIndDef_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl9=_IL_incl9;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_9(_TPPrule_9 _currn)
#else
void _VS1rule_9(_currn )
_TPPrule_9 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_9(_TPPrule_9 _currn)
#else
void _VS2rule_9(_currn )
_TPPrule_9 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_9(_TPPrule_9 _currn)
#else
void _VS3rule_9(_currn )
_TPPrule_9 _currn;

#endif
{
int* _IL_incl17;
tOilArgSig* _IL_incl16;

_VisitVarDecl()
_VisitEntry();
_IL_incl17=_IG_incl17;_IG_incl17= &(_currn->_ATcost);
_IL_incl16=_IG_incl16;_IG_incl16= &(_currn->_ATsignature);
_AVG11SetNames_post=NULLDefTableKeyList;
/*SPC(406)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_AVCoerce_SetBinding=FirstSetBinding(_AVG11SetNames_post);

_CYCLE0SetBinding:;
;
/*SPC(411)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATcost=_AVCostSpecification_cost;
/*SPC(471)*/
_currn->_ATsignature=_AVSignature_signature;
/*SPC(470)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (!(EQ(_AVCoerce_SetBinding, NoSetBinding))) {
_AVCoerce_SetBinding=NextSetBinding(_AVCoerce_SetBinding);

goto _CYCLE0SetBinding;
}
;
/*SPC(413)*/
AddCoercions(_currn->_desc1->_ATKey);
/*SPC(473)*/
_IG_incl17=_IL_incl17;
_IG_incl16=_IL_incl16;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_9(_TPPrule_9 _currn)
#else
void _VS4rule_9(_currn )
_TPPrule_9 _currn;

#endif
{
int* _IL_incl17;
tOilArgSig* _IL_incl16;

_VisitVarDecl()
_VisitEntry();
_IL_incl17=_IG_incl17;_IG_incl17= &(_currn->_ATcost);
_IL_incl16=_IG_incl16;_IG_incl16= &(_currn->_ATsignature);
_AVOpDef_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl17=_IL_incl17;
_IG_incl16=_IL_incl16;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_10(_TPPrule_10 _currn)
#else
void _VS1rule_10(_currn )
_TPPrule_10 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_10(_TPPrule_10 _currn)
#else
void _VS2rule_10(_currn )
_TPPrule_10 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_10(_TPPrule_10 _currn)
#else
void _VS3rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int* _IL_incl17;
tOilArgSig* _IL_incl16;

_VisitVarDecl()
_VisitEntry();
_IL_incl17=_IG_incl17;_IG_incl17= &(_currn->_ATcost);
_IL_incl16=_IG_incl16;_IG_incl16= &(_currn->_ATsignature);
_AVG11SetNames_post=NULLDefTableKeyList;
/*SPC(406)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_AVOper_SetBinding=FirstSetBinding(_AVG11SetNames_post);

_CYCLE0SetBinding:;
;
/*SPC(411)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATcost=_AVCostSpecification_cost;
/*SPC(464)*/
_currn->_ATsignature=_AVSignature_signature;
/*SPC(463)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (!(EQ(_AVOper_SetBinding, NoSetBinding))) {
_AVOper_SetBinding=NextSetBinding(_AVOper_SetBinding);

goto _CYCLE0SetBinding;
}
;
/*SPC(413)*/
_IG_incl17=_IL_incl17;
_IG_incl16=_IL_incl16;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_10(_TPPrule_10 _currn)
#else
void _VS4rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int* _IL_incl17;
tOilArgSig* _IL_incl16;

_VisitVarDecl()
_VisitEntry();
_IL_incl17=_IG_incl17;_IG_incl17= &(_currn->_ATcost);
_IL_incl16=_IG_incl16;_IG_incl16= &(_currn->_ATsignature);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl17=_IL_incl17;
_IG_incl16=_IL_incl16;

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
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_11(_TPPrule_11 _currn)
#else
void _VS3rule_11(_currn )
_TPPrule_11 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_11(_TPPrule_11 _currn)
#else
void _VS4rule_11(_currn )
_TPPrule_11 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVG11SetNames_post=
((NE(GetTypeSet(_currn->_desc1->_ATKey, NULLDefTableKeyList), NULLDefTableKeyList)
) ? (AddToSetDefTableKeyList(_currn->_desc1->_ATKey, _AVG11SetNames_post, CmpKey)
) : (_AVG11SetNames_post))
;
/*SPC(422)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_11(_TPPrule_11 _currn,tOilType* _AS0type,DefTableKey* _AS0Key)
#else
void _VS5rule_11(_currn ,_AS0type,_AS0Key)
_TPPrule_11 _currn;
DefTableKey* _AS0Key;
tOilType* _AS0type;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0Key)=_currn->_desc1->_ATKey;
/*SPC(421)*/
(* _AS0type)=GetType(GetBoundType(_currn->_desc1->_ATKey, _currn->_desc1->_ATKey), OilErrorType());
/*SPC(432)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_11(_TPPrule_11 _currn,tOilType* _AS0type,DefTableKey* _AS0Key)
#else
void _VS6rule_11(_currn ,_AS0type,_AS0Key)
_TPPrule_11 _currn;
DefTableKey* _AS0Key;
tOilType* _AS0type;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVTypeIdentifier_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_12(_TPPrule_12 _currn)
#else
void _VS2rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_12(_TPPrule_12 _currn)
#else
void _VS3rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_12(_TPPrule_12 _currn)
#else
void _VS4rule_12(_currn )
_TPPrule_12 _currn;

#endif
{
DefTableKey _AS2Key;
tOilType _AS2type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2type)),(&( _AS2Key)));
_AVSignature_signature=OilAddArgSig(_AS2type, _AVSignature_signature);
/*SPC(396)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_12(_TPPrule_12 _currn)
#else
void _VS5rule_12(_currn )
_TPPrule_12 _currn;

#endif
{
DefTableKey _AS2Key;
tOilType _AS2type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2type)),(&( _AS2Key)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_13(_TPPrule_13 _currn)
#else
void _VS2rule_13(_currn )
_TPPrule_13 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_13(_TPPrule_13 _currn)
#else
void _VS3rule_13(_currn )
_TPPrule_13 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_13(_TPPrule_13 _currn)
#else
void _VS4rule_13(_currn )
_TPPrule_13 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVSignature_signature=OilAddArgSig(_AS1type, _AVSignature_signature);
/*SPC(390)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_13(_TPPrule_13 _currn)
#else
void _VS5rule_13(_currn )
_TPPrule_13 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_14(_TPPrule_14 _currn)
#else
void _VS4rule_14(_currn )
_TPPrule_14 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));
_AVSignature_signature=OilAddArgSig(_AS1type, OilNewArgSig());
/*SPC(385)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_14(_TPPrule_14 _currn)
#else
void _VS5rule_14(_currn )
_TPPrule_14 _currn;

#endif
{
DefTableKey _AS1Key;
tOilType _AS1type;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,tOilType*,DefTableKey*)) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1type)),(&( _AS1Key)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_15(_TPPrule_15 _currn)
#else
void _VS4rule_15(_currn )
_TPPrule_15 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVSignature_signature=OilNewArgSig();
/*SPC(380)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_16(_TPPrule_16 _currn)
#else
void _VS2rule_16(_currn )
_TPPrule_16 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVG12partialSet_post=AddToSetDefTableKeyList(_currn->_desc1->_ATKey, _AVG12partialSet_post, CmpKey);
/*SPC(368)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_16(_TPPrule_16 _currn)
#else
void _VS4rule_16(_currn )
_TPPrule_16 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVTypeIdentifier_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_17(_TPPrule_17 _currn)
#else
void _VS1rule_17(_currn )
_TPPrule_17 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_17(_TPPrule_17 _currn,DefTableKeyList* _AS0set)
#else
void _VS2rule_17(_currn ,_AS0set)
_TPPrule_17 _currn;
DefTableKeyList* _AS0set;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVG12partialSet_post=NULLDefTableKeyList;
/*SPC(362)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0set)=_AVG12partialSet_post;
/*SPC(363)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_17(_TPPrule_17 _currn,DefTableKeyList* _AS0set)
#else
void _VS3rule_17(_currn ,_AS0set)
_TPPrule_17 _currn;
DefTableKeyList* _AS0set;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_17(_TPPrule_17 _currn,DefTableKeyList* _AS0set)
#else
void _VS4rule_17(_currn ,_AS0set)
_TPPrule_17 _currn;
DefTableKeyList* _AS0set;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_18(_TPPrule_18 _currn)
#else
void _VS1rule_18(_currn )
_TPPrule_18 _currn;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_18(_TPPrule_18 _currn,DefTableKeyList* _AS0set)
#else
void _VS2rule_18(_currn ,_AS0set)
_TPPrule_18 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));
(* _AS0set)=Intersection(_AS1set, _AS2set);
/*SPC(354)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_18(_TPPrule_18 _currn,DefTableKeyList* _AS0set)
#else
void _VS3rule_18(_currn ,_AS0set)
_TPPrule_18 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_18(_TPPrule_18 _currn,DefTableKeyList* _AS0set)
#else
void _VS4rule_18(_currn ,_AS0set)
_TPPrule_18 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_19(_TPPrule_19 _currn)
#else
void _VS1rule_19(_currn )
_TPPrule_19 _currn;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_19(_TPPrule_19 _currn,DefTableKeyList* _AS0set)
#else
void _VS2rule_19(_currn ,_AS0set)
_TPPrule_19 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));
(* _AS0set)=Difference(_AS1set, _AS2set);
/*SPC(349)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_19(_TPPrule_19 _currn,DefTableKeyList* _AS0set)
#else
void _VS3rule_19(_currn ,_AS0set)
_TPPrule_19 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_19(_TPPrule_19 _currn,DefTableKeyList* _AS0set)
#else
void _VS4rule_19(_currn ,_AS0set)
_TPPrule_19 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_20(_TPPrule_20 _currn)
#else
void _VS1rule_20(_currn )
_TPPrule_20 _currn;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_20(_TPPrule_20 _currn,DefTableKeyList* _AS0set)
#else
void _VS2rule_20(_currn ,_AS0set)
_TPPrule_20 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));
(* _AS0set)=Union(_AS1set, _AS2set);
/*SPC(344)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_20(_TPPrule_20 _currn,DefTableKeyList* _AS0set)
#else
void _VS3rule_20(_currn ,_AS0set)
_TPPrule_20 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_20(_TPPrule_20 _currn,DefTableKeyList* _AS0set)
#else
void _VS4rule_20(_currn ,_AS0set)
_TPPrule_20 _currn;
DefTableKeyList* _AS0set;

#endif
{
DefTableKeyList _AS2set;
DefTableKeyList _AS1set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1set)));
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_21(_TPPrule_21 _currn)
#else
void _VS1rule_21(_currn )
_TPPrule_21 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_21(_TPPrule_21 _currn,DefTableKeyList* _AS0set)
#else
void _VS2rule_21(_currn ,_AS0set)
_TPPrule_21 _currn;
DefTableKeyList* _AS0set;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0set)=GetTypeSet(_AVSetIdUse_Key, NULLDefTableKeyList);
/*SPC(333)*/

if (EQ((* _AS0set), NULLDefTableKeyList)) {
message(ERROR, "Undefined set", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(336)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_21(_TPPrule_21 _currn,DefTableKeyList* _AS0set)
#else
void _VS3rule_21(_currn ,_AS0set)
_TPPrule_21 _currn;
DefTableKeyList* _AS0set;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_21(_TPPrule_21 _currn,DefTableKeyList* _AS0set)
#else
void _VS4rule_21(_currn ,_AS0set)
_TPPrule_21 _currn;
DefTableKeyList* _AS0set;

#endif
{

_VisitVarDecl()
_VisitEntry();

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_22(_TPPrule_22 _currn)
#else
void _VS2rule_22(_currn )
_TPPrule_22 _currn;

#endif
{
DefTableKeyList _AS2set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));
ResetTypeSet(_currn->_desc1->_ATKey, _AS2set);
/*SPC(326)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_22(_TPPrule_22 _currn)
#else
void _VS3rule_22(_currn )
_TPPrule_22 _currn;

#endif
{
DefTableKeyList _AS2set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_22(_TPPrule_22 _currn)
#else
void _VS4rule_22(_currn )
_TPPrule_22 _currn;

#endif
{
DefTableKeyList _AS2set;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,DefTableKeyList*)) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2set)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_23(_TPPrule_23 _currn)
#else
void _VS1rule_23(_currn )
_TPPrule_23 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVSetIdUse_Sym=_currn->_ATTERM_1;
/*SPC(216)*/
_AVSetIdUse_Key=KeyInEnv((* _IG_incl6), _AVSetIdUse_Sym);
/*SPC(241)*/

if (EQ(_AVSetIdUse_Key, NoKey)) {
message(ERROR, "Undefined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(220)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_24(_TPPrule_24 _currn)
#else
void _VS1rule_24(_currn )
_TPPrule_24 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_24(_TPPrule_24 _currn)
#else
void _VS2rule_24(_currn )
_TPPrule_24 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_24(_TPPrule_24 _currn)
#else
void _VS3rule_24(_currn )
_TPPrule_24 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVSetIdDef_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/

if (NOT(_AVSetIdDef_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(211)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_25(_TPPrule_25 _currn)
#else
void _VS1rule_25(_currn )
_TPPrule_25 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVOpRef_Sym=_currn->_ATTERM_1;
/*SPC(196)*/
_AVOpRef_Key=KeyInEnv((* _IG_incl6), _AVOpRef_Sym);
/*SPC(241)*/
AddIdentifications((* _IG_incl9), _AVOpRef_Key);
/*SPC(494)*/

if (EQ(_AVOpRef_Key, NoKey)) {
message(ERROR, "Undefined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(200)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_26(_TPPrule_26 _currn)
#else
void _VS1rule_26(_currn )
_TPPrule_26 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_26(_TPPrule_26 _currn)
#else
void _VS2rule_26(_currn )
_TPPrule_26 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(284)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_26(_TPPrule_26 _currn)
#else
void _VS3rule_26(_currn )
_TPPrule_26 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (EQ(GetOperator(_currn->_ATKey, NULLtOilOpList), NULLtOilOpList)) {
ResetOperator(_currn->_ATKey, ConstOilOpList(OilNewOp(_currn->_ATKey, OilNewArgSig(), 0), NULLtOilOpList));

} else {
}
;
/*SPC(505)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_26(_TPPrule_26 _currn)
#else
void _VS4rule_26(_currn )
_TPPrule_26 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVIndDef_IsOperFirstOcc=SetGetOperFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(119)*/
_AVIndDef_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/
_AVIdentificationOilExterns_post=
((AND(_AVIndDef_IsOperFirstOcc, OneOperator(_currn->_ATKey))
) ? (PTGSeq(_AVIdentificationOilExterns_post, PTGOperatorSymbol(PTGNumb(ID(Operator(_currn->_ATKey))), _AVIndDef_Ptg))
) : (_AVIdentificationOilExterns_post))
;
/*SPC(747)*/
_AVIdentificationKnownKeys_post=
((_AVIndDef_IsOperFirstOcc
) ? (PTGSeq(_AVIdentificationKnownKeys_post, 
((OneOperator(_currn->_ATKey)
) ? (PTGOperatorProperty(PTGNumb(ID(Operator(_currn->_ATKey))), _AVIndDef_Ptg)
) : (PTGMultOperator(_AVIndDef_Ptg)))
)
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(698)*/

if (_AVIndDef_IsFirstOcc) {
DumpOps(_currn->_ATKey);

} else {
}
;
/*SPC(666)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_27(_TPPrule_27 _currn)
#else
void _VS1rule_27(_currn )
_TPPrule_27 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl12), _currn->_ATSym);
/*SPC(251)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_27(_TPPrule_27 _currn)
#else
void _VS2rule_27(_currn )
_TPPrule_27 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
_AVClassParameterParameterIndex_post=
(ResetBindingStatus(_currn->_ATKey, eElementRef), ResetParameterIndex(_currn->_ATKey, _AVClassParameterParameterIndex_post), ADD(_AVClassParameterParameterIndex_post, 1))
;
/*SPC(558)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_27(_TPPrule_27 _currn)
#else
void _VS3rule_27(_currn )
_TPPrule_27 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassParameter_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/
_AVClassParameter_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/

if (NOT(_AVClassParameter_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(186)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_28(_TPPrule_28 _currn)
#else
void _VS1rule_28(_currn )
_TPPrule_28 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_28(_TPPrule_28 _currn)
#else
void _VS2rule_28(_currn )
_TPPrule_28 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
ResetBindingStatus(_currn->_ATKey, eClassRef);
/*SPC(540)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_28(_TPPrule_28 _currn)
#else
void _VS3rule_28(_currn )
_TPPrule_28 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(284)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/
_currn->_ATclass=OilNewClass(_currn->_ATKey, _AVClassName_argNum);
/*SPC(520)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_28(_TPPrule_28 _currn)
#else
void _VS4rule_28(_currn )
_TPPrule_28 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassName_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/

if (_AVClassName_IsFirstOcc) {
OilDumpClass(_currn->_ATclass);

} else {
}
;
/*SPC(672)*/
_AVClassName_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/
_AVIdentificationOilExterns_post=
((_AVClassName_IsFirstOcc
) ? (PTGSeq(_AVIdentificationOilExterns_post, PTGClassSymbol(PTGNumb(ID(_currn->_ATclass)), _AVClassName_Ptg))
) : (_AVIdentificationOilExterns_post))
;
/*SPC(757)*/
_AVIdentificationKnownKeys_post=
((_AVClassName_IsFirstOcc
) ? (PTGSeq(_AVIdentificationKnownKeys_post, PTGClassProperty(PTGNumb(ID(_currn->_ATclass)), _AVClassName_Ptg))
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(710)*/

if (NOT(_AVClassName_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(177)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_29(_TPPrule_29 _currn)
#else
void _VS1rule_29(_currn )
_TPPrule_29 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_29(_TPPrule_29 _currn)
#else
void _VS2rule_29(_currn )
_TPPrule_29 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_29(_TPPrule_29 _currn)
#else
void _VS3rule_29(_currn )
_TPPrule_29 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(276)*/
_currn->_ATIsTypeFirstOcc=SetGetTypeFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(95)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_29(_TPPrule_29 _currn)
#else
void _VS4rule_29(_currn )
_TPPrule_29 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATDoType=AND(_currn->_ATIsTypeFirstOcc, EQ(GetTypeSet(_currn->_ATKey, NULLDefTableKeyList), NULLDefTableKeyList));
/*SPC(277)*/
_currn->_ATtype=
(
((_currn->_ATDoType
) ? ((ResetType(_currn->_ATKey, OilNewType(_currn->_ATKey)), 0)
) : ((0)))
, GetType(_currn->_ATKey, OilErrorType()))
;
/*SPC(306)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_29(_TPPrule_29 _currn)
#else
void _VS5rule_29(_currn )
_TPPrule_29 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVIdentificationOilExterns_post=
((_currn->_ATDoType
) ? (PTGSeq(_AVIdentificationOilExterns_post, PTGTypeSymbol(PTGNumb(ID(_currn->_ATtype)), _AVTypeIdentifier_Ptg))
) : (_AVIdentificationOilExterns_post))
;
/*SPC(737)*/
_AVIdentificationKnownKeys_post=
((_currn->_ATDoType
) ? (PTGSeq(_AVIdentificationKnownKeys_post, PTGTypeProperty(PTGNumb(ID(_currn->_ATtype)), _AVTypeIdentifier_Ptg))
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(688)*/
_AVTypeIdentifier_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/

if (_currn->_ATDoType) {
OilDumpType(_currn->_ATtype);

} else {
}
;
/*SPC(660)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_30(_TPPrule_30 _currn)
#else
void _VS1rule_30(_currn )
_TPPrule_30 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_30(_TPPrule_30 _currn)
#else
void _VS2rule_30(_currn )
_TPPrule_30 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(284)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_30(_TPPrule_30 _currn)
#else
void _VS4rule_30(_currn )
_TPPrule_30 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
ResetClassOperator(_currn->_ATKey, ConstOilClassOpList(OilAddClassOp(_currn->_ATKey, (* _IG_incl13), (* _IG_incl14), (* _IG_incl15)), GetClassOperator(_currn->_ATKey, NULLtOilClassOpList)));
/*SPC(605)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_30(_TPPrule_30 _currn)
#else
void _VS5rule_30(_currn )
_TPPrule_30 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassOpDef_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/
_AVClassOpDef_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/
_AVIdentificationKnownKeys_post=
((_AVClassOpDef_IsFirstOcc
) ? (PTGSeq(_AVIdentificationKnownKeys_post, PTGMultOperator(_AVClassOpDef_Ptg))
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(720)*/

if (NOT(_AVClassOpDef_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(163)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_31(_TPPrule_31 _currn)
#else
void _VS1rule_31(_currn )
_TPPrule_31 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_31(_TPPrule_31 _currn)
#else
void _VS2rule_31(_currn )
_TPPrule_31 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(284)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_31(_TPPrule_31 _currn)
#else
void _VS4rule_31(_currn )
_TPPrule_31 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
ResetOperator(_currn->_ATKey, ConstOilOpList(OilNewOp(_currn->_ATKey, (* _IG_incl16), (* _IG_incl17)), GetOperator(_currn->_ATKey, NULLtOilOpList)));
/*SPC(444)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_31(_TPPrule_31 _currn)
#else
void _VS5rule_31(_currn )
_TPPrule_31 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVOpDef_IsOperFirstOcc=SetGetOperFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(119)*/
_AVOpDef_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/
_AVOpDef_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/
_AVIdentificationOilExterns_post=
((AND(_AVOpDef_IsOperFirstOcc, OneOperator(_currn->_ATKey))
) ? (PTGSeq(_AVIdentificationOilExterns_post, PTGOperatorSymbol(PTGNumb(ID(Operator(_currn->_ATKey))), _AVOpDef_Ptg))
) : (_AVIdentificationOilExterns_post))
;
/*SPC(747)*/
_AVIdentificationKnownKeys_post=
((_AVOpDef_IsOperFirstOcc
) ? (PTGSeq(_AVIdentificationKnownKeys_post, 
((OneOperator(_currn->_ATKey)
) ? (PTGOperatorProperty(PTGNumb(ID(Operator(_currn->_ATKey))), _AVOpDef_Ptg)
) : (PTGMultOperator(_AVOpDef_Ptg)))
)
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(698)*/

if (_AVOpDef_IsFirstOcc) {
DumpOps(_currn->_ATKey);

} else {
}
;
/*SPC(666)*/

if (NOT(_AVOpDef_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(154)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_32(_TPPrule_32 _currn)
#else
void _VS1rule_32(_currn )
_TPPrule_32 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATSym=GenerateName("_AnonOp");
/*SPC(145)*/
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_32(_TPPrule_32 _currn)
#else
void _VS2rule_32(_currn )
_TPPrule_32 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(284)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_32(_TPPrule_32 _currn)
#else
void _VS4rule_32(_currn )
_TPPrule_32 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
ResetClassOperator(_currn->_ATKey, ConstOilClassOpList(OilAddClassOp(_currn->_ATKey, (* _IG_incl13), (* _IG_incl14), (* _IG_incl15)), GetClassOperator(_currn->_ATKey, NULLtOilClassOpList)));
/*SPC(605)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_32(_TPPrule_32 _currn)
#else
void _VS5rule_32(_currn )
_TPPrule_32 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassOpDef_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/
_AVClassOpDef_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/
_AVIdentificationKnownKeys_post=
((_AVClassOpDef_IsFirstOcc
) ? (PTGSeq(_AVIdentificationKnownKeys_post, PTGMultOperator(_AVClassOpDef_Ptg))
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(720)*/

if (NOT(_AVClassOpDef_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(163)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_33(_TPPrule_33 _currn)
#else
void _VS1rule_33(_currn )
_TPPrule_33 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATSym=GenerateName("_AnonOp");
/*SPC(141)*/
DefineIdn((* _IG_incl8), _currn->_ATSym);
/*SPC(247)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_33(_TPPrule_33 _currn)
#else
void _VS2rule_33(_currn )
_TPPrule_33 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATKey=KeyInEnv((* _IG_incl6), _currn->_ATSym);
/*SPC(241)*/
ResetIndex(_currn->_ATKey, _currn->_ATSym);
/*SPC(284)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(20)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_33(_TPPrule_33 _currn)
#else
void _VS4rule_33(_currn )
_TPPrule_33 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
ResetOperator(_currn->_ATKey, ConstOilOpList(OilNewOp(_currn->_ATKey, (* _IG_incl16), (* _IG_incl17)), GetOperator(_currn->_ATKey, NULLtOilOpList)));
/*SPC(444)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_33(_TPPrule_33 _currn)
#else
void _VS5rule_33(_currn )
_TPPrule_33 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVOpDef_IsOperFirstOcc=SetGetOperFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(119)*/
_AVOpDef_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(71)*/
_AVOpDef_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(23)*/
_AVIdentificationOilExterns_post=
((AND(_AVOpDef_IsOperFirstOcc, OneOperator(_currn->_ATKey))
) ? (PTGSeq(_AVIdentificationOilExterns_post, PTGOperatorSymbol(PTGNumb(ID(Operator(_currn->_ATKey))), _AVOpDef_Ptg))
) : (_AVIdentificationOilExterns_post))
;
/*SPC(747)*/
_AVIdentificationKnownKeys_post=
((_AVOpDef_IsOperFirstOcc
) ? (PTGSeq(_AVIdentificationKnownKeys_post, 
((OneOperator(_currn->_ATKey)
) ? (PTGOperatorProperty(PTGNumb(ID(Operator(_currn->_ATKey))), _AVOpDef_Ptg)
) : (PTGMultOperator(_AVOpDef_Ptg)))
)
) : (_AVIdentificationKnownKeys_post))
;
/*SPC(698)*/

if (_AVOpDef_IsFirstOcc) {
DumpOps(_currn->_ATKey);

} else {
}
;
/*SPC(666)*/

if (NOT(_AVOpDef_Unique)) {
message(ERROR, "Multiply-defined identifier", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(154)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_34(_TPPrule_34 _currn)
#else
void _VS1rule_34(_currn )
_TPPrule_34 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVCostSpecification_cost=_currn->_ATTERM_1;
/*SPC(136)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_35(_TPPrule_35 _currn)
#else
void _VS1rule_35(_currn )
_TPPrule_35 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVCostSpecification_cost=1;
/*SPC(131)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_76(_TPPrule_76 _currn)
#else
void _VS3rule_76(_currn )
_TPPrule_76 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_74(_TPPrule_74 _currn)
#else
void _VS7rule_74(_currn )
_TPPrule_74 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_67(_TPPrule_67 _currn)
#else
void _VS1rule_67(_currn )
_TPPrule_67 _currn;

#endif
{
Environment* _IL_incl8;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
_currn->_ATEnv=NewEnv();
/*SPC(230)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVIdentificationOilExterns_post=PTGNULL;
/*SPC(731)*/
_AVIdentificationKnownKeys_post=PTGNULL;
/*SPC(682)*/
OilDumpInit("OilDecls.c");
/*SPC(655)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
PTGOutFile("OilDecls.h", PTGHeader(_AVIdentificationOilExterns_post));
/*SPC(732)*/
PTGOutFile("OilDecls.pdl", PTGPDL(_AVIdentificationKnownKeys_post));
/*SPC(683)*/
_IG_incl8=_IL_incl8;
_IG_incl6=_IL_incl6;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_65(_TPPrule_65 _currn)
#else
void _VS3rule_65(_currn )
_TPPrule_65 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_65(_TPPrule_65 _currn)
#else
void _VS4rule_65(_currn )
_TPPrule_65 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_63(_TPPrule_63 _currn)
#else
void _VS2rule_63(_currn )
_TPPrule_63 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVG8__const1=ADD(_AVG8__const1, ARGTOONE(_currn->_desc2->_ATKey));
/*SPC(874)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_62(_TPPrule_62 _currn)
#else
void _VS2rule_62(_currn )
_TPPrule_62 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVG8__const1=ARGTOONE(_currn->_desc1->_ATKey);
/*SPC(870)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_56(_TPPrule_56 _currn)
#else
void _VS5rule_56(_currn )
_TPPrule_56 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_55(_TPPrule_55 _currn)
#else
void _VS5rule_55(_currn )
_TPPrule_55 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVOpDef_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_54(_TPPrule_54 _currn)
#else
void _VS5rule_54(_currn )
_TPPrule_54 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVOpDef_Ptg=PTGId(_currn->_desc2->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_49(_TPPrule_49 _currn)
#else
void _VS6rule_49(_currn )
_TPPrule_49 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_49(_TPPrule_49 _currn)
#else
void _VS7rule_49(_currn )
_TPPrule_49 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_46(_TPPrule_46 _currn)
#else
void _VS5rule_46(_currn )
_TPPrule_46 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVClassOpDef_Ptg=PTGId(_currn->_desc2->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_45(_TPPrule_45 _currn)
#else
void _VS5rule_45(_currn )
_TPPrule_45 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassOpDef_Ptg=PTGId(_currn->_desc1->_ATSym);
/*SPC(34)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_41(_TPPrule_41 _currn)
#else
void _VS2rule_41(_currn )
_TPPrule_41 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVClassParameterParameterIndex_post=1;
/*SPC(553)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVClassParameters__const1=_AVG8__const1;
/*SPC(786)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_37(_TPPrule_37 _currn)
#else
void _VS1rule_37(_currn )
_TPPrule_37 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_37(_TPPrule_37 _currn)
#else
void _VS2rule_37(_currn )
_TPPrule_37 _currn;

#endif
{
Environment* _IL_incl12;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl12=_IG_incl12;_IG_incl12= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
_currn->_ATEnv=NewScope((* _IG_incl8));
/*SPC(236)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVClassBody__const1=_AVClassParameters__const1;
/*SPC(770)*/
_IG_incl12=_IL_incl12;
_IG_incl6=_IL_incl6;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_37(_TPPrule_37 _currn)
#else
void _VS3rule_37(_currn )
_TPPrule_37 _currn;

#endif
{
Environment* _IL_incl12;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl12=_IG_incl12;_IG_incl12= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl12=_IL_incl12;
_IG_incl6=_IL_incl6;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_37(_TPPrule_37 _currn)
#else
void _VS4rule_37(_currn )
_TPPrule_37 _currn;

#endif
{
Environment* _IL_incl12;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl12=_IG_incl12;_IG_incl12= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl12=_IL_incl12;
_IG_incl6=_IL_incl6;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_36(_TPPrule_36 _currn)
#else
void _VS1rule_36(_currn )
_TPPrule_36 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_36(_TPPrule_36 _currn)
#else
void _VS2rule_36(_currn )
_TPPrule_36 _currn;

#endif
{
Environment* _IL_incl12;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl12=_IG_incl12;_IG_incl12= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
_currn->_ATEnv=NewScope((* _IG_incl8));
/*SPC(236)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVClassBody__const1=ZERO();
/*SPC(766)*/
_IG_incl12=_IL_incl12;
_IG_incl6=_IL_incl6;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_36(_TPPrule_36 _currn)
#else
void _VS3rule_36(_currn )
_TPPrule_36 _currn;

#endif
{
Environment* _IL_incl12;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl12=_IG_incl12;_IG_incl12= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl12=_IL_incl12;
_IG_incl6=_IL_incl6;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_36(_TPPrule_36 _currn)
#else
void _VS4rule_36(_currn )
_TPPrule_36 _currn;

#endif
{
Environment* _IL_incl12;
Environment* _IL_incl6;

_VisitVarDecl()
_VisitEntry();
_IL_incl12=_IG_incl12;_IG_incl12= &(_currn->_ATEnv);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATEnv);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl12=_IL_incl12;
_IG_incl6=_IL_incl6;

_VisitExit();
}

