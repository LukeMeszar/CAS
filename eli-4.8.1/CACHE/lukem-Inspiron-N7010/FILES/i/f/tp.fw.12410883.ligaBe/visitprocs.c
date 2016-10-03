
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
int* _IG_incl8;
int* _IG_incl7;
DefTableKey* _IG_incl3;
Environment* _IG_incl0;
PTGNode _AVLST_Source__const6;
PTGNode _AVDeclarationTransforms_post;
PTGNode _AVDeclarationReducers_post;
PTGNode _AVDeclarationForwards_post;
PTGNode _AVDeclarationExterns_post;
PTGNode _AVPatternBuilders_post;
PTGNode _AVPatternMacros_post;
PTGNode _AVPatternTermcodes_post;
PTGNode _AVIncludeIncludes_post;
int _AVPatternindex_post;
PTGNode _AVChildrenrevers_post;
PTGNode _AVChildrenleaves_post;
PTGNode _AVFunctionFieldSets_post;
PTGNode _AVFunctionArgNames_post;
PTGNode _AVFunctionArgDecls_post;
PTGNode _AVFunctionFieldDecls_post;
int _AVChildrentindex_post;
int _AVChildrenntindex_pre;
Binding _AVTerminal_Bind;
int _AVTerminal_IsFirstOcc;
int _AVTerminal_Kind;
PTGNode _AVFunctionFieldSets_pre;
PTGNode _AVFunctionArgNames_pre;
PTGNode _AVFunctionArgDecls_pre;
PTGNode _AVFunctionFieldDecls_pre;
int _AVFunction_IsFirstOcc;
DefTableKey _AVFunction_Key;
int _AVFunction_ntcount;
DefTableKey _AVChild_type_RuleAttr_69;
PTGNode _AVChild_Ptg;
Binding _AVSymbolUse_Bind;
PTGNode _AVSymbolUse_typeSym;
int _AVSignature_Unique;
Binding _AVSignature_Bind;
DefTableKey _AVSignature_type;
Binding _AVSymbolDef_Bind;
DefTableKey _AVSymbolDef_Key;
int _AVSymbolDef_Kind;
Binding _AVType_Bind;
int _AVType_IsFirstOcc;
Binding _AVInclude_Bind;
int _AVInclude_IsFirstOcc;

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
void _VS1LST_Patternrule_19(_TPPLST_Patternrule_19 _currn)
#else
void _VS1LST_Patternrule_19(_currn )
_TPPLST_Patternrule_19 _currn;

#endif
{
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_Patternrule_19(_TPPLST_Patternrule_19 _currn)
#else
void _VS2LST_Patternrule_19(_currn )
_TPPLST_Patternrule_19 _currn;

#endif
{
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3LST_Patternrule_19(_TPPLST_Patternrule_19 _currn)
#else
void _VS3LST_Patternrule_19(_currn )
_TPPLST_Patternrule_19 _currn;

#endif
{
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4LST_Patternrule_19(_TPPLST_Patternrule_19 _currn)
#else
void _VS4LST_Patternrule_19(_currn )
_TPPLST_Patternrule_19 _currn;

#endif
{
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5LST_Patternrule_19(_TPPLST_Patternrule_19 _currn)
#else
void _VS5LST_Patternrule_19(_currn )
_TPPLST_Patternrule_19 _currn;

#endif
{
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATindex_pre=_currn->_ATindex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc2->_ATindex_pre=_AVPatternindex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6LST_Patternrule_19(_TPPLST_Patternrule_19 _currn)
#else
void _VS6LST_Patternrule_19(_currn )
_TPPLST_Patternrule_19 _currn;

#endif
{
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,PTGNode*)) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1Ptg)));
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_Source__const6=PTGSeq(IDENTICAL(_AS1Ptg), _AVLST_Source__const6);
/*SPC(187)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1LST_Declarationrule_19(_TPPLST_Declarationrule_19 _currn)
#else
void _VS1LST_Declarationrule_19(_currn )
_TPPLST_Declarationrule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_Declarationrule_19(_TPPLST_Declarationrule_19 _currn)
#else
void _VS2LST_Declarationrule_19(_currn )
_TPPLST_Declarationrule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3LST_Declarationrule_19(_TPPLST_Declarationrule_19 _currn)
#else
void _VS3LST_Declarationrule_19(_currn )
_TPPLST_Declarationrule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4LST_Declarationrule_19(_TPPLST_Declarationrule_19 _currn)
#else
void _VS4LST_Declarationrule_19(_currn )
_TPPLST_Declarationrule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5LST_Declarationrule_19(_TPPLST_Declarationrule_19 _currn)
#else
void _VS5LST_Declarationrule_19(_currn )
_TPPLST_Declarationrule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATindex_pre=_currn->_ATindex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6LST_Declarationrule_19(_TPPLST_Declarationrule_19 _currn)
#else
void _VS6LST_Declarationrule_19(_currn )
_TPPLST_Declarationrule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_Source__const6=_AVLST_Source__const6;
/*SPC(187)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1LST_Includerule_19(_TPPLST_Includerule_19 _currn)
#else
void _VS1LST_Includerule_19(_currn )
_TPPLST_Includerule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_Includerule_19(_TPPLST_Includerule_19 _currn)
#else
void _VS2LST_Includerule_19(_currn )
_TPPLST_Includerule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3LST_Includerule_19(_TPPLST_Includerule_19 _currn)
#else
void _VS3LST_Includerule_19(_currn )
_TPPLST_Includerule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4LST_Includerule_19(_TPPLST_Includerule_19 _currn)
#else
void _VS4LST_Includerule_19(_currn )
_TPPLST_Includerule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5LST_Includerule_19(_TPPLST_Includerule_19 _currn)
#else
void _VS5LST_Includerule_19(_currn )
_TPPLST_Includerule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATindex_pre=_currn->_ATindex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6LST_Includerule_19(_TPPLST_Includerule_19 _currn)
#else
void _VS6LST_Includerule_19(_currn )
_TPPLST_Includerule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_Source__const6=_AVLST_Source__const6;
/*SPC(187)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6LST_0rule_19(_TPPLST_0rule_19 _currn)
#else
void _VS6LST_0rule_19(_currn )
_TPPLST_0rule_19 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVLST_Source__const6=PTGNull();
/*SPC(187)*/
_AVPatternindex_post=_currn->_ATindex_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1LST_SymbolDefrule_16(_TPPLST_SymbolDefrule_16 _currn)
#else
void _VS1LST_SymbolDefrule_16(_currn )
_TPPLST_SymbolDefrule_16 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_SymbolDefrule_16(_TPPLST_SymbolDefrule_16 _currn)
#else
void _VS2LST_SymbolDefrule_16(_currn )
_TPPLST_SymbolDefrule_16 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
_AVSymbolUse_Bind=BindingInEnv((* _IG_incl0), _currn->_ATSym);
/*SPC(143)*/
_currn->_ATKey=KeyOf(_AVSymbolUse_Bind);
/*SPC(147)*/
_currn->_ATHasKind=GetKind(_currn->_ATKey, IntNone);
/*SPC(31)*/

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
_currn->_ATFieldSets_post=_AVFunctionFieldSets_pre;
/*SPC(0)*/
_currn->_ATArgNames_post=_AVFunctionArgNames_pre;
/*SPC(0)*/
_currn->_ATArgDecls_post=_AVFunctionArgDecls_pre;
/*SPC(0)*/
_currn->_ATFieldDecls_post=_AVFunctionFieldDecls_pre;
/*SPC(0)*/
_AVSymbolUse_typeSym=PTGId(_currn->_ATSym);
/*SPC(653)*/

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
_currn->_ATtype=(* _IG_incl3);
/*SPC(235)*/
_AVSymbolDef_Kind=2;
/*SPC(233)*/
_AVSymbolDef_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(131)*/
_AVSymbolDef_Key=KeyOf(_AVSymbolDef_Bind);
/*SPC(133)*/
ResetType(_AVSymbolDef_Key, _currn->_ATtype);
/*SPC(234)*/
SetDiffKind(_AVSymbolDef_Key, _AVSymbolDef_Kind, IntMultiple);
/*SPC(26)*/

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
_AVDeclarationTransforms_post=PTGSeq(_AVDeclarationTransforms_post, PTGTransform(PTGId(_currn->_ATSym), PTGId(GetSym(_currn->_ATtype, 0))));
/*SPC(761)*/
_AVDeclarationExterns_post=PTGSeq(_AVDeclarationExterns_post, PTGTransformDecl(PTGId(_currn->_ATSym), PTGId(GetSym(_currn->_ATtype, 0))));
/*SPC(767)*/

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
_AVTerminal_Kind=1;
/*SPC(209)*/
_AVTerminal_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(131)*/
_currn->_ATKey=KeyOf(_AVTerminal_Bind);
/*SPC(133)*/
SetDiffKind(_currn->_ATKey, _AVTerminal_Kind, IntMultiple);
/*SPC(26)*/

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

if (EQ(GetArity(_currn->_ATKey, 100), 100)) {
message(ERROR, "Inconsistent arity", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(212)*/
_AVTerminal_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(80)*/
_AVPatternMacros_post=
((_AVTerminal_IsFirstOcc
) ? (PTGSeq(_AVPatternMacros_post, PTGMacro(PTGId(_currn->_ATSym), TerminalIndex(_currn->_ATKey)))
) : (_AVPatternMacros_post))
;
/*SPC(557)*/
_AVPatternTermcodes_post=
((_AVTerminal_IsFirstOcc
) ? (PTGSeq(_AVPatternTermcodes_post, PTGTerm(PTGId(_currn->_ATSym), TerminalIndex(_currn->_ATKey)))
) : (_AVPatternTermcodes_post))
;
/*SPC(551)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_4(_TPPrule_4 _currn)
#else
void _VS1rule_4(_currn )
_TPPrule_4 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVType_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(131)*/
_currn->_ATKey=KeyOf(_AVType_Bind);
/*SPC(133)*/
ResetSym(_currn->_ATKey, _currn->_ATSym);
/*SPC(253)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_4(_TPPrule_4 _currn)
#else
void _VS2rule_4(_currn )
_TPPrule_4 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVType_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(80)*/
_AVDeclarationReducers_post=
((_AVType_IsFirstOcc
) ? (PTGSeq(_AVDeclarationReducers_post, PTGReducer(PTGId(_currn->_ATSym), PTGId(ObtainSymbol(_currn->_ATKey, _currn->_ATSym)), GetCases(_currn->_ATKey, PTGNULL), _currn->_ATSym))
) : (_AVDeclarationReducers_post))
;
/*SPC(700)*/
_AVDeclarationForwards_post=
((_AVType_IsFirstOcc
) ? (PTGSeq(_AVDeclarationForwards_post, PTGForward(PTGId(_currn->_ATSym), PTGId(ObtainSymbol(_currn->_ATKey, _currn->_ATSym))))
) : (_AVDeclarationForwards_post))
;
/*SPC(692)*/

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

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_6(_TPPrule_6 _currn)
#else
void _VS1rule_6(_currn )
_TPPrule_6 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATvalue=1;
/*SPC(276)*/

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
_AVFunctionFieldSets_post=_AVFunctionFieldSets_pre;
/*SPC(0)*/
_AVFunctionArgNames_post=_AVFunctionArgNames_pre;
/*SPC(0)*/
_AVFunctionArgDecls_post=_AVFunctionArgDecls_pre;
/*SPC(0)*/
_AVFunctionFieldDecls_post=_AVFunctionFieldDecls_pre;
/*SPC(0)*/
_AVFunction_Key=DefineIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(357)*/
_AVFunction_IsFirstOcc=SetGetFirstOcc(_AVFunction_Key, 1, 0);
/*SPC(80)*/
_AVDeclarationExterns_post=
((_AVFunction_IsFirstOcc
) ? (PTGSeq(_AVDeclarationExterns_post, 
((EQ(_AVFunction_ntcount, 0)
) ? (PTGExtern0(PTGId(_currn->_ATSym), _AVFunctionArgDecls_pre)
) : (
((EQ(_AVFunction_ntcount, 1)
) ? (PTGExtern1(PTGId(_currn->_ATSym), _AVFunctionArgDecls_pre)
) : (
((EQ(_AVFunction_ntcount, 2)
) ? (PTGExtern2(PTGId(_currn->_ATSym), _AVFunctionArgDecls_pre)
) : (PTGNULL))
))
))
)
) : (_AVDeclarationExterns_post))
;
/*SPC(641)*/
_AVPatternBuilders_post=
((_AVFunction_IsFirstOcc
) ? (PTGSeq(_AVPatternBuilders_post, 
((EQ(_AVFunction_ntcount, 0)
) ? (PTGBuild0(PTGId(_currn->_ATSym), _AVFunctionFieldDecls_pre, _AVFunctionArgDecls_pre, _AVFunctionArgNames_pre, _AVFunctionFieldSets_pre)
) : (
((EQ(_AVFunction_ntcount, 1)
) ? (PTGBuild1(PTGId(_currn->_ATSym), _AVFunctionFieldDecls_pre, _AVFunctionArgDecls_pre, _AVFunctionArgNames_pre, _AVFunctionFieldSets_pre)
) : (
((EQ(_AVFunction_ntcount, 2)
) ? (PTGBuild2(PTGId(_currn->_ATSym), _AVFunctionFieldDecls_pre, _AVFunctionArgDecls_pre, _AVFunctionArgNames_pre, _AVFunctionFieldSets_pre)
) : (PTGNULL))
))
))
)
) : (_AVPatternBuilders_post))
;
/*SPC(614)*/

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
_currn->_AT_const1=IDENTICAL(_currn->_desc1->_ATIsNt);
/*SPC(198)*/

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
void _VS4rule_8(_TPPrule_8 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS4rule_8(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_8 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATntindex_pre=_AVChildrenntindex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0_const0)=IDENTICAL(_currn->_desc1->_ATIsNt);
/*SPC(198)*/
(* _AS0ntindex_post)=_AVChildrenntindex_pre;
/*SPC(0)*/

if ((* _IG_incl7)) {
obstack_grow(SigObstk, StringTable((* _AS0RightSym)), strlen(StringTable((* _AS0RightSym))));

} else {
}
;
/*SPC(464)*/
(* _AS0LeftSym)=_currn->_desc1->_ATSym;
/*SPC(463)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_8(_TPPrule_8 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS5rule_8(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_8 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_8(_TPPrule_8 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS6rule_8(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_8 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATtindex_pre=_AVChildrentindex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_8(_TPPrule_8 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS7rule_8(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_8 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_9(_TPPrule_9 _currn)
#else
void _VS1rule_9(_currn )
_TPPrule_9 _currn;

#endif
{
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

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
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_AT_const1=OR(_currn->_desc1->_AT_const1, IDENTICAL(_currn->_desc2->_ATIsNt));
/*SPC(197)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_9(_TPPrule_9 _currn)
#else
void _VS3rule_9(_currn )
_TPPrule_9 _currn;

#endif
{
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

if (_currn->_desc2->_ATIsNt) {
obstack_1grow(SigObstk, ',');

} else {
}
;
/*SPC(444)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_9(_TPPrule_9 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS4rule_9(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_9 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

_VisitVarDecl()
_VisitEntry();
_AS1RightSym=_currn->_desc2->_ATSym;
/*SPC(443)*/
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1LeftSym)),(&( _AS1RightSym)),(&( _AS1ntindex_post)),(&( _AS1_const0)));
_currn->_desc2->_ATntindex_pre=_AS1ntindex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(* _AS0_const0)=ADD(_AS1_const0, IDENTICAL(_currn->_desc2->_ATIsNt));
/*SPC(197)*/
(* _AS0ntindex_post)=_AVChildrenntindex_pre;
/*SPC(0)*/

if ((* _IG_incl7)) {

if (_currn->_desc2->_ATIsNt) {
obstack_1grow(SigObstk, ',');

if (EQ(_AS1ntindex_post, 1)) {
obstack_grow(SigObstk, StringTable(_AS1LeftSym), strlen(StringTable(_AS1LeftSym)));

} else {
obstack_grow(SigObstk, StringTable(_currn->_desc2->_ATSym), strlen(StringTable(_currn->_desc2->_ATSym)));
}
;
;

} else {
}
;

} else {
}
;
/*SPC(445)*/
(* _AS0LeftSym)=0;
/*SPC(362)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_9(_TPPrule_9 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS5rule_9(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_9 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1LeftSym)),(&( _AS1RightSym)),(&( _AS1ntindex_post)),(&( _AS1_const0)));
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_9(_TPPrule_9 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS6rule_9(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_9 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1LeftSym)),(&( _AS1RightSym)),(&( _AS1ntindex_post)),(&( _AS1_const0)));
_currn->_desc2->_ATtindex_pre=_AVChildrentindex_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_9(_TPPrule_9 _currn,int* _AS0LeftSym,int* _AS0RightSym,int* _AS0ntindex_post,int* _AS0_const0)
#else
void _VS7rule_9(_currn ,_AS0LeftSym,_AS0RightSym,_AS0ntindex_post,_AS0_const0)
_TPPrule_9 _currn;
int* _AS0_const0;
int* _AS0ntindex_post;
int* _AS0RightSym;
int* _AS0LeftSym;

#endif
{
int _AS1_const0;
int _AS1ntindex_post;
int _AS1RightSym;
int _AS1LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS7MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1LeftSym)),(&( _AS1RightSym)),(&( _AS1ntindex_post)),(&( _AS1_const0)));
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_10(_TPPrule_10 _currn)
#else
void _VS1rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

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
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATIsNt=1;
/*SPC(417)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_10(_TPPrule_10 _currn)
#else
void _VS3rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

_VisitVarDecl()
_VisitEntry();
_currn->_ATHasNt_RuleAttr_67=_currn->_desc2->_AT_const1;
/*SPC(415)*/
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));

if (_currn->_ATHasNt_RuleAttr_67) {
obstack_1grow(SigObstk, '(');

} else {
}
;
;
/*SPC(418)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

if (_currn->_ATHasNt_RuleAttr_67) {
obstack_1grow(SigObstk, ')');

} else {
}
;
/*SPC(426)*/
_currn->_ATSym=0;
/*SPC(367)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_10(_TPPrule_10 _currn)
#else
void _VS4rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

_VisitVarDecl()
_VisitEntry();
_AVChildrenntindex_pre=_currn->_ATntindex_pre;
/*SPC(0)*/

if ((* _IG_incl7)) {
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));

if (_currn->_ATHasNt_RuleAttr_67) {
obstack_1grow(SigObstk, '(');

} else {
}
;
;

} else {
}
;
/*SPC(427)*/
_AS2RightSym=0;
/*SPC(363)*/
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2LeftSym)),(&( _AS2RightSym)),(&( _AS2ntindex_post)),(&( _AS2_const0)));
_AVChildrenntindex_pre=_AS2ntindex_post;
/*SPC(0)*/

if ((* _IG_incl7)) {

if (_currn->_ATHasNt_RuleAttr_67) {
obstack_1grow(SigObstk, ')');

} else {
}
;

} else {
}
;
/*SPC(435)*/
_currn->_ATntcount=_AS2_const0;
/*SPC(296)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_10(_TPPrule_10 _currn)
#else
void _VS5rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2LeftSym)),(&( _AS2RightSym)),(&( _AS2ntindex_post)),(&( _AS2_const0)));

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_10(_TPPrule_10 _currn)
#else
void _VS6rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

_VisitVarDecl()
_VisitEntry();
_AVChildrentindex_post=_currn->_ATtindex_pre;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2LeftSym)),(&( _AS2RightSym)),(&( _AS2ntindex_post)),(&( _AS2_const0)));
IsArity(_currn->_desc1->_ATKey, _currn->_ATntcount, 100);
/*SPC(438)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_10(_TPPrule_10 _currn)
#else
void _VS7rule_10(_currn )
_TPPrule_10 _currn;

#endif
{
int _AS2_const0;
int _AS2ntindex_post;
int _AS2RightSym;
int _AS2LeftSym;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,int*,int*,int*,int*)) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2LeftSym)),(&( _AS2RightSym)),(&( _AS2ntindex_post)),(&( _AS2_const0)));
_AVChild_Ptg=PTGNULL;
/*SPC(599)*/

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
_currn->_ATIsNt=1;
/*SPC(396)*/

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
_currn->_ATSym=0;
/*SPC(367)*/
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));
/*SPC(397)*/

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
_AVChildrenntindex_pre=_currn->_ATntindex_pre;
/*SPC(0)*/

if ((* _IG_incl7)) {
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));

} else {
}
;
/*SPC(403)*/
_currn->_ATntcount=ZERO();
/*SPC(296)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_11(_TPPrule_11 _currn)
#else
void _VS6rule_11(_currn )
_TPPrule_11 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVChildrentindex_post=_currn->_ATtindex_pre;
/*SPC(0)*/
IsArity(_currn->_desc1->_ATKey, 0, 100);
/*SPC(410)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_11(_TPPrule_11 _currn)
#else
void _VS7rule_11(_currn )
_TPPrule_11 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVChild_Ptg=PTGNULL;
/*SPC(599)*/

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATIsNt=EQ(_currn->_desc1->_ATHasKind, 2);
/*SPC(373)*/

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
_currn->_ATSym=_currn->_desc1->_ATSym;
/*SPC(372)*/

if (_currn->_ATIsNt) {
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));

} else {
}
;
/*SPC(374)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_12(_TPPrule_12 _currn)
#else
void _VS4rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVChildrenntindex_pre=ADD(_currn->_ATntindex_pre, _currn->_ATIsNt);
/*SPC(484)*/
_currn->_ATntcount=ZERO();
/*SPC(296)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_12(_TPPrule_12 _currn)
#else
void _VS5rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();

if (NOT(_currn->_ATIsNt)) {
obstack_1grow(SigObstk, '_');
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));
;

} else {
}
;
/*SPC(381)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_12(_TPPrule_12 _currn)
#else
void _VS6rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVChildrentindex_post=ADD(_currn->_ATtindex_pre, NOT(_currn->_ATIsNt));
/*SPC(485)*/
_AVChild_type_RuleAttr_69=GetType(_currn->_desc1->_ATKey, NoKey);
/*SPC(734)*/
_AVChildrenrevers_post=PTGCommaSeq(_AVChildrenrevers_post, 
((_currn->_ATIsNt
) ? (PTGReducerCall(PTGId(ObtainSymbol(_AVChild_type_RuleAttr_69, GetSym(_AVChild_type_RuleAttr_69, 0))), 
((EQ(_currn->_ATntindex_pre, 0)
) ? (1
) : (
((EQ(_currn->_ATntindex_pre, 1)
) ? (0
) : (_currn->_ATntindex_pre))
))
)
) : (PTGGetValue(PTGId((* _IG_incl8)), _currn->_ATtindex_pre)))
);
/*SPC(745)*/
_AVChildrenleaves_post=PTGCommaSeq(_AVChildrenleaves_post, 
((_currn->_ATIsNt
) ? (PTGReducerCall(PTGId(ObtainSymbol(_AVChild_type_RuleAttr_69, GetSym(_AVChild_type_RuleAttr_69, 0))), _currn->_ATntindex_pre)
) : (PTGGetValue(PTGId((* _IG_incl8)), _currn->_ATtindex_pre)))
);
/*SPC(735)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS7rule_12(_TPPrule_12 _currn)
#else
void _VS7rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVFunctionFieldSets_pre=_AVFunctionFieldSets_post;
/*SPC(0)*/
_AVFunctionArgNames_pre=_AVFunctionArgNames_post;
/*SPC(0)*/
_AVFunctionArgDecls_pre=_AVFunctionArgDecls_post;
/*SPC(0)*/
_AVFunctionFieldDecls_pre=_AVFunctionFieldDecls_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVFunctionFieldSets_post=
((NOT(_currn->_ATIsNt)
) ? (PTGSeq(_AVFunctionFieldSets_post, PTGFieldSet(_currn->_ATtindex_pre))
) : (_AVFunctionFieldSets_post))
;
/*SPC(676)*/
_AVFunctionArgNames_post=
((NOT(_currn->_ATIsNt)
) ? (PTGSeq(_AVFunctionArgNames_post, PTGArgName(_currn->_ATtindex_pre))
) : (_AVFunctionArgNames_post))
;
/*SPC(670)*/
_AVFunctionArgDecls_post=
((NOT(_currn->_ATIsNt)
) ? (PTGSeq(_AVFunctionArgDecls_post, PTGArgDecl(_AVSymbolUse_typeSym, _currn->_ATtindex_pre))
) : (_AVFunctionArgDecls_post))
;
/*SPC(664)*/
_AVFunctionFieldDecls_post=
((NOT(_currn->_ATIsNt)
) ? (PTGSeq(_AVFunctionFieldDecls_post, PTGFieldDecl(_AVSymbolUse_typeSym, _currn->_ATtindex_pre))
) : (_AVFunctionFieldDecls_post))
;
/*SPC(658)*/
_AVChild_Ptg=
((EQ(_currn->_desc1->_ATHasKind, NEG(1))
) ? (PTGId(_currn->_desc1->_ATSym)
) : (PTGNULL))
;
/*SPC(592)*/
ResetUsed(_currn->_desc1->_ATKey, 1);
/*SPC(240)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_13(_TPPrule_13 _currn)
#else
void _VS1rule_13(_currn )
_TPPrule_13 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVFunctionFieldSets_pre=PTGNULL;
/*SPC(610)*/
_AVFunctionArgNames_pre=PTGNULL;
/*SPC(609)*/
_AVFunctionArgDecls_pre=PTGNULL;
/*SPC(608)*/
_AVFunctionFieldDecls_pre=PTGNULL;
/*SPC(607)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
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
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));
obstack_1grow(SigObstk, ':');
;
/*SPC(325)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATSym=
(obstack_1grow(SigObstk, '\0'), MakeName(obstack_finish(SigObstk)))
;
/*SPC(314)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_13(_TPPrule_13 _currn)
#else
void _VS4rule_13(_currn )
_TPPrule_13 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_desc2->_ATntindex_pre=0;
/*SPC(478)*/

if ((* _IG_incl7)) {
obstack_grow(SigObstk, StringTable(_currn->_desc1->_ATSym), strlen(StringTable(_currn->_desc1->_ATSym)));
obstack_1grow(SigObstk, ':');
;

} else {
}
;
/*SPC(335)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATComSym=
(((* _IG_incl7)
) ? (
(obstack_1grow(SigObstk, '\0'), MakeName(obstack_finish(SigObstk)))

) : (0))
;
/*SPC(317)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_13(_TPPrule_13 _currn)
#else
void _VS5rule_13(_currn )
_TPPrule_13 _currn;

#endif
{
int* _IL_incl8;

_VisitVarDecl()
_VisitEntry();
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATstruct);

if (EQ(_currn->_desc2->_ATntcount, 0)) {
obstack_grow(SigObstk, "TP_0", 4);

} else {

if (EQ(_currn->_desc2->_ATntcount, 1)) {
obstack_grow(SigObstk, "TP_1", 4);

} else {

if (EQ(_currn->_desc2->_ATntcount, 2)) {
obstack_grow(SigObstk, "TP_2", 4);

} else {
}
;
}
;
}
;
/*SPC(344)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_desc2->_ATtindex_pre=0;
/*SPC(479)*/
_currn->_desc3->_ATSym=
(obstack_1grow(SigObstk, '\0'), MakeName(obstack_finish(SigObstk)))
;
/*SPC(349)*/
_currn->_ATstruct=_currn->_desc3->_ATSym;
/*SPC(322)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVSignature_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(503)*/
_AVSignature_type=GetType(_currn->_desc1->_ATKey, NoKey);
/*SPC(309)*/
_currn->_ATKey=KeyOf(_AVSignature_Bind);
/*SPC(504)*/
SetUnique(_currn->_ATKey, 1, 0);
/*SPC(54)*/

if (EQ(_AVSignature_type, NoKey)) {
message(ERROR, CatStrInd("No type declared for ", _currn->_desc1->_ATSym), 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(312)*/
_IG_incl8=_IL_incl8;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_13(_TPPrule_13 _currn)
#else
void _VS6rule_13(_currn )
_TPPrule_13 _currn;

#endif
{
int* _IL_incl8;

_VisitVarDecl()
_VisitEntry();
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATstruct);
_AVFunctionFieldSets_post=_currn->_desc1->_ATFieldSets_post;
/*SPC(0)*/
_AVFunctionArgNames_post=_currn->_desc1->_ATArgNames_post;
/*SPC(0)*/
_AVFunctionArgDecls_post=_currn->_desc1->_ATArgDecls_post;
/*SPC(0)*/
_AVFunctionFieldDecls_post=_currn->_desc1->_ATFieldDecls_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS7MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVFunctionFieldSets_pre=_AVFunctionFieldSets_post;
/*SPC(0)*/
_AVFunctionArgNames_pre=_AVFunctionArgNames_post;
/*SPC(0)*/
_AVFunctionArgDecls_pre=_AVFunctionArgDecls_post;
/*SPC(0)*/
_AVFunctionFieldDecls_pre=_AVFunctionFieldDecls_post;
/*SPC(0)*/
_AVFunction_ntcount=_currn->_desc2->_ATntcount;
/*SPC(352)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_AVSignature_Unique=GetUnique(_currn->_ATKey, 0);
/*SPC(57)*/

if (NOT(_AVSignature_Unique)) {
message(ERROR, "Multiply-defined pattern", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(506)*/
_IG_incl8=_IL_incl8;

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
void _VS3rule_14(_TPPrule_14 _currn)
#else
void _VS3rule_14(_currn )
_TPPrule_14 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_14(_TPPrule_14 _currn)
#else
void _VS4rule_14(_currn )
_TPPrule_14 _currn;

#endif
{
int* _IL_incl7;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATIsCommutative);
_currn->_ATIsCommutative=1;
/*SPC(583)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl7=_IL_incl7;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_14(_TPPrule_14 _currn)
#else
void _VS5rule_14(_currn )
_TPPrule_14 _currn;

#endif
{
int* _IL_incl7;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATIsCommutative);
_AVChildrenrevers_post=PTGNULL;
/*SPC(723)*/
_AVChildrenleaves_post=PTGNULL;
/*SPC(722)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVPatternindex_post=ADD(_currn->_ATindex_pre, 2);
/*SPC(271)*/
_currn->_ATid_RuleAttr_71=PTGId(_currn->_ATTERM_1);
/*SPC(584)*/
UpdateCases(_AVSignature_type, PTGSeq(PTGCase(_currn->_ATindex_pre, _currn->_ATid_RuleAttr_71, _AVChildrenleaves_post), PTGCase(ADD(_currn->_ATindex_pre, 1), _currn->_ATid_RuleAttr_71, _AVChildrenrevers_post)));
/*SPC(724)*/
_IG_incl7=_IL_incl7;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_14(_TPPrule_14 _currn,PTGNode* _AS0Ptg)
#else
void _VS6rule_14(_currn ,_AS0Ptg)
_TPPrule_14 _currn;
PTGNode* _AS0Ptg;

#endif
{
int* _IL_incl7;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATIsCommutative);
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0Ptg)=PTGSeq(PTGPattern(PTGId(_currn->_desc1->_ATSym), _currn->_ATindex_pre, _currn->_desc2->_ATvalue, _currn->_ATid_RuleAttr_71), PTGPattern(PTGId(_currn->_desc1->_ATComSym), ADD(_currn->_ATindex_pre, 1), _currn->_desc2->_ATvalue, _currn->_ATid_RuleAttr_71));
/*SPC(585)*/
_IG_incl7=_IL_incl7;

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

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_15(_TPPrule_15 _currn)
#else
void _VS3rule_15(_currn )
_TPPrule_15 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS4rule_15(_TPPrule_15 _currn)
#else
void _VS4rule_15(_currn )
_TPPrule_15 _currn;

#endif
{
int* _IL_incl7;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATIsCommutative);
_currn->_ATIsCommutative=0;
/*SPC(575)*/
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl7=_IL_incl7;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS5rule_15(_TPPrule_15 _currn)
#else
void _VS5rule_15(_currn )
_TPPrule_15 _currn;

#endif
{
int* _IL_incl7;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATIsCommutative);
_AVChildrenrevers_post=PTGNULL;
/*SPC(715)*/
_AVChildrenleaves_post=PTGNULL;
/*SPC(714)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVPatternindex_post=ADD(_currn->_ATindex_pre, 1);
/*SPC(266)*/
_currn->_ATid_RuleAttr_72=PTGId(_currn->_ATTERM_1);
/*SPC(576)*/
UpdateCases(_AVSignature_type, PTGCase(_currn->_ATindex_pre, _currn->_ATid_RuleAttr_72, _AVChildrenleaves_post));
/*SPC(716)*/
_IG_incl7=_IL_incl7;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS6rule_15(_TPPrule_15 _currn,PTGNode* _AS0Ptg)
#else
void _VS6rule_15(_currn ,_AS0Ptg)
_TPPrule_15 _currn;
PTGNode* _AS0Ptg;

#endif
{
int* _IL_incl7;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATIsCommutative);
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0Ptg)=PTGPattern(PTGId(_currn->_desc1->_ATSym), _currn->_ATindex_pre, _currn->_desc2->_ATvalue, _currn->_ATid_RuleAttr_72);
/*SPC(577)*/
_IG_incl7=_IL_incl7;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_16(_TPPrule_16 _currn)
#else
void _VS1rule_16(_currn )
_TPPrule_16 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_17(_TPPrule_17 _currn)
#else
void _VS1rule_17(_currn )
_TPPrule_17 _currn;

#endif
{
DefTableKey* _IL_incl3;

_VisitVarDecl()
_VisitEntry();
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATtype);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATtype=_currn->_desc2->_ATKey;
/*SPC(229)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl3=_IL_incl3;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_17(_TPPrule_17 _currn)
#else
void _VS2rule_17(_currn )
_TPPrule_17 _currn;

#endif
{
DefTableKey* _IL_incl3;

_VisitVarDecl()
_VisitEntry();
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATtype);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl3=_IL_incl3;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_18(_TPPrule_18 _currn)
#else
void _VS1rule_18(_currn )
_TPPrule_18 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVInclude_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(131)*/
_currn->_ATKey=KeyOf(_AVInclude_Bind);
/*SPC(133)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_18(_TPPrule_18 _currn)
#else
void _VS2rule_18(_currn )
_TPPrule_18 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVInclude_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(80)*/
_AVIncludeIncludes_post=
((_AVInclude_IsFirstOcc
) ? (PTGSeq(_AVIncludeIncludes_post, PTGInclude(PTGId(_currn->_ATSym)))
) : (_AVIncludeIncludes_post))
;
/*SPC(540)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_19(_TPPrule_19 _currn)
#else
void _VS1rule_19(_currn )
_TPPrule_19 _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
_currn->_ATEnv=RootEnv;
/*SPC(96)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS4MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_desc1->_ATindex_pre=1;
/*SPC(261)*/
(*(_CALL_VS_((NODEPTR )) (VS5MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVDeclarationTransforms_post=PTGNULL;
/*SPC(519)*/
_AVDeclarationReducers_post=PTGNULL;
/*SPC(518)*/
_AVDeclarationForwards_post=PTGNULL;
/*SPC(517)*/
_AVDeclarationExterns_post=PTGNULL;
/*SPC(521)*/
_AVPatternBuilders_post=PTGNULL;
/*SPC(516)*/
_AVPatternMacros_post=PTGNULL;
/*SPC(520)*/
_AVPatternTermcodes_post=PTGNULL;
/*SPC(515)*/
_AVIncludeIncludes_post=PTGNULL;
/*SPC(514)*/
(*(_CALL_VS_((NODEPTR )) (VS6MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
PTGOutFile("tp_gen.h", PTGHeader(_AVIncludeIncludes_post, _AVPatternMacros_post, _AVDeclarationExterns_post));
/*SPC(536)*/
PTGOutFile("tp_gen.burg", PTGBurg(_AVPatternTermcodes_post, _AVLST_Source__const6, _AVPatternBuilders_post, _AVDeclarationForwards_post, _AVDeclarationReducers_post, _AVDeclarationTransforms_post));
/*SPC(530)*/
_IG_incl0=_IL_incl0;

_VisitExit();
}

