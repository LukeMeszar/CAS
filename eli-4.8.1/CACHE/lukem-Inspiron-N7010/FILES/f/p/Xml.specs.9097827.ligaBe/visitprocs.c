
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
CharPtr* _IG_incl4;
PTGNode* _IG_incl2;
Environment* _IG_incl0;
PTGNode _AVLST_xGrammar__const10;
PTGNode _AVLST_xGrammar__const11;
PTGNode _AVLST_xGrammar__const12;
PTGNode _AVG2PtgTemplates_post;
PTGNode _AVxRHSInherit_post;
PTGNode _AVLST_xGrammarClassComp_post;
PTGNode _AVLST_xRHS__const5;
PTGNode _AVLST_xRHS__const6;
PTGNode _AVLST_xRHS__const7;
PTGNode _AVLST_xRHS__const10;
int _AVLST_xRHSTermCnt_post;
int _AVLST_xRHSNontermCnt_post;
PTGNode _AVLST_Syms__const1;
PTGNode _AVLST_Syms__const2;
PTGNode _AVLST_Syms__const3;
PTGNode _AVLST_Syms__const4;
PTGNode _AVLST_Syms__const10;
PTGNode _AVLST_Items__const0;
PTGNode _AVxRoot_TreeGram;
int _AVPatternName_Sym;
Binding _AVPatternName_Bind;
int _AVElementTermCnt_pre;
PTGNode _AVElement_Mark;
PTGNode _AVSyms__const1;
PTGNode _AVSyms__const2;
PTGNode _AVSyms__const3;
PTGNode _AVSyms__const4;
PTGNode _AVSyms__const10;
PTGNode _AVxRHS__const5;
PTGNode _AVxRHS__const6;
PTGNode _AVxRHS__const7;
PTGNode _AVxRHS__const10;
Binding _AVxSymbol_Bind;
int _AVxSymbol_IsFirstOcc;
Binding _AVxRule_Bind;
PTGNode _AVxProduction_Body_RuleAttr_66;
PTGNode _AVxProduction_Content_RuleAttr_66;
PTGNode _AVxGrammar__const10;
PTGNode _AVxGrammar__const11;
PTGNode _AVxGrammar__const12;

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
void _VS1LST_xProductionrule_18(_TPPLST_xProductionrule_18 _currn)
#else
void _VS1LST_xProductionrule_18(_currn )
_TPPLST_xProductionrule_18 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_xProductionrule_18(_TPPLST_xProductionrule_18 _currn)
#else
void _VS2LST_xProductionrule_18(_currn )
_TPPLST_xProductionrule_18 _currn;

#endif
{
PTGNode _AS1_const10;
PTGNode _AS1Element;
PTGNode _AS1TreeGram;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*)) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1TreeGram)),(&( _AS1Element)),(&( _AS1_const10)));
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_xGrammar__const10=PTGSeq(_AS1_const10, _AVLST_xGrammar__const10);
/*SPC(127)*/
_AVLST_xGrammar__const11=PTGSeq(IDENTICAL(_AS1Element), _AVLST_xGrammar__const11);
/*SPC(127)*/
_AVLST_xGrammar__const12=PTGSeq(IDENTICAL(_AS1TreeGram), _AVLST_xGrammar__const12);
/*SPC(127)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_0rule_18(_TPPLST_0rule_18 _currn)
#else
void _VS2LST_0rule_18(_currn )
_TPPLST_0rule_18 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVLST_xGrammar__const10=PTGNull();
/*SPC(127)*/
_AVLST_xGrammar__const11=PTGNull();
/*SPC(127)*/
_AVLST_xGrammar__const12=PTGNull();
/*SPC(127)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_Elementrule_15(_TPPLST_Elementrule_15 _currn)
#else
void _VS2LST_Elementrule_15(_currn )
_TPPLST_Elementrule_15 _currn;

#endif
{
PTGNode _AS1_const7;
PTGNode _AS1_const10;
PTGNode _AS1Insert;
PTGNode _AS1TreeGram;

_VisitVarDecl()
_VisitEntry();
_currn->_desc1->_ATNontermCnt_pre=_AVLST_xRHSNontermCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3LST_Elementrule_15(_TPPLST_Elementrule_15 _currn)
#else
void _VS3LST_Elementrule_15(_currn )
_TPPLST_Elementrule_15 _currn;

#endif
{
PTGNode _AS1_const7;
PTGNode _AS1_const10;
PTGNode _AS1Insert;
PTGNode _AS1TreeGram;

_VisitVarDecl()
_VisitEntry();
_AVElementTermCnt_pre=_AVLST_xRHSTermCnt_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*,PTGNode*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1TreeGram)),(&( _AS1Insert)),(&( _AS1_const10)),(&( _AS1_const7)));
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_xRHS__const5=PTGSpaceSeq(IDENTICAL(_AS1TreeGram), _AVLST_xRHS__const5);
/*SPC(132)*/
_AVLST_xRHS__const6=PTGSepSeq(IDENTICAL(_AS1Insert), _AVLST_xRHS__const6);
/*SPC(132)*/
_AVLST_xRHS__const7=PTGCommaSeq(_AS1_const7, _AVLST_xRHS__const7);
/*SPC(132)*/
_AVLST_xRHS__const10=PTGSeq(_AS1_const10, _AVLST_xRHS__const10);
/*SPC(132)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3LST_0rule_15(_TPPLST_0rule_15 _currn)
#else
void _VS3LST_0rule_15(_currn )
_TPPLST_0rule_15 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVLST_xRHS__const5=PTGNull();
/*SPC(132)*/
_AVLST_xRHS__const6=PTGNull();
/*SPC(132)*/
_AVLST_xRHS__const7=PTGNull();
/*SPC(132)*/
_AVLST_xRHS__const10=PTGNull();
/*SPC(132)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_xSymbolrule_14(_TPPLST_xSymbolrule_14 _currn)
#else
void _VS2LST_xSymbolrule_14(_currn )
_TPPLST_xSymbolrule_14 _currn;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*,PTGNode*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1Ptg)),(&( _AS1AttrPtg)),(&( _AS1Entity)),(&( _AS1Content)));
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_Syms__const1=PTGCommaSeq(IDENTICAL(_AS1AttrPtg), _AVLST_Syms__const1);
/*SPC(133)*/
_AVLST_Syms__const2=PTGCommaSeq(IDENTICAL(_AS1Ptg), _AVLST_Syms__const2);
/*SPC(133)*/
_AVLST_Syms__const3=PTGAltSeq(IDENTICAL(_AS1Ptg), _AVLST_Syms__const3);
/*SPC(133)*/
_AVLST_Syms__const4=PTGAltSeq(IDENTICAL(_AS1Content), _AVLST_Syms__const4);
/*SPC(133)*/
_AVLST_Syms__const10=PTGSeq(IDENTICAL(_AS1Entity), _AVLST_Syms__const10);
/*SPC(133)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2LST_0rule_14(_TPPLST_0rule_14 _currn)
#else
void _VS2LST_0rule_14(_currn )
_TPPLST_0rule_14 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVLST_Syms__const1=PTGNull();
/*SPC(133)*/
_AVLST_Syms__const2=PTGNull();
/*SPC(133)*/
_AVLST_Syms__const3=PTGNull();
/*SPC(133)*/
_AVLST_Syms__const4=PTGNull();
/*SPC(133)*/
_AVLST_Syms__const10=PTGNull();
/*SPC(133)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1LST_Itemrule_8(_TPPLST_Itemrule_8 _currn)
#else
void _VS1LST_Itemrule_8(_currn )
_TPPLST_Itemrule_8 _currn;

#endif
{
PTGNode _AS1IdemPtg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,PTGNode*)) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1IdemPtg)));
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVLST_Items__const0=PTGSpSeq(IDENTICAL(_AS1IdemPtg), _AVLST_Items__const0);
/*SPC(141)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1LST_0rule_8(_TPPLST_0rule_8 _currn)
#else
void _VS1LST_0rule_8(_currn )
_TPPLST_0rule_8 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVLST_Items__const0=PTGNull();
/*SPC(141)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_1(_TPPrule_1 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_1(_currn ,_AS0IdemPtg)
_TPPrule_1 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0IdemPtg)=PTGOption(_currn->_desc1->_ATIdemPtg);
/*SPC(346)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_2(_TPPrule_2 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_2(_currn ,_AS0IdemPtg)
_TPPrule_2 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(* _AS0IdemPtg)=PTGCall(StringTable(_currn->_ATTERM_1), _currn->_desc1->_ATIdemPtg);
/*SPC(341)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_3(_TPPrule_3 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_3(_currn ,_AS0IdemPtg)
_TPPrule_3 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0IdemPtg)=PTGIndTyp(_currn->_ATTERM_1, StringTable(_currn->_ATTERM_2));
/*SPC(336)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_4(_TPPrule_4 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_4(_currn ,_AS0IdemPtg)
_TPPrule_4 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0IdemPtg)=PTGCType(StringTable(_currn->_ATTERM_1));
/*SPC(331)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_5(_TPPrule_5 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_5(_currn ,_AS0IdemPtg)
_TPPrule_5 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0IdemPtg)=PTGIndex(_currn->_ATTERM_1);
/*SPC(326)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_6(_TPPrule_6 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_6(_currn ,_AS0IdemPtg)
_TPPrule_6 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0IdemPtg)=PTGAsIs("$");
/*SPC(321)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_7(_TPPrule_7 _currn,PTGNode* _AS0IdemPtg)
#else
void _VS1rule_7(_currn ,_AS0IdemPtg)
_TPPrule_7 _currn;
PTGNode* _AS0IdemPtg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0IdemPtg)=PTGId(FwOut(_currn->_ATTERM_1, Warn));
/*SPC(316)*/

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
_currn->_ATIdemPtg=_AVLST_Items__const0;
/*SPC(351)*/

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
_AVPatternName_Sym=MakePtgSym(_currn->_ATTERM_1);
/*SPC(168)*/
_AVPatternName_Bind=BindingInEnv((* _IG_incl0), _AVPatternName_Sym);
/*SPC(59)*/
_currn->_ATIdemPtg=PTGId(_currn->_ATTERM_1);
/*SPC(311)*/
_currn->_ATKey=KeyOf(_AVPatternName_Bind);
/*SPC(63)*/
FixPtgGiven(_currn->_ATTERM_1, _currn->_ATKey);
/*SPC(200)*/

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
_AVG2PtgTemplates_post=
((NE(_currn->_ATKey, NoKey)
) ? (PTGSeq(_AVG2PtgTemplates_post, (* _IG_incl2))
) : (_AVG2PtgTemplates_post))
;
/*SPC(297)*/

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
PTGNode* _IL_incl2;

_VisitVarDecl()
_VisitEntry();
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATIdemPtg);
_currn->_ATIdemPtg=PTGAxiom(_currn->_desc1->_ATIdemPtg, _currn->_desc2->_ATIdemPtg);
/*SPC(306)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_IG_incl2=_IL_incl2;

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
_AVLST_xRHSNontermCnt_post=_currn->_ATNontermCnt_pre;
/*SPC(0)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_11(_TPPrule_11 _currn,PTGNode* _AS0TreeGram,PTGNode* _AS0Insert,PTGNode* _AS0_const10,PTGNode* _AS0_const7)
#else
void _VS3rule_11(_currn ,_AS0TreeGram,_AS0Insert,_AS0_const10,_AS0_const7)
_TPPrule_11 _currn;
PTGNode* _AS0_const7;
PTGNode* _AS0_const10;
PTGNode* _AS0Insert;
PTGNode* _AS0TreeGram;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0_const7)=PTGNull();
/*SPC(137)*/
(* _AS0_const10)=PTGNull();
/*SPC(137)*/
_AVLST_xRHSTermCnt_post=_AVElementTermCnt_pre;
/*SPC(0)*/
(* _AS0TreeGram)=PTGId(FwOut(_currn->_ATTERM_1, Warn));
/*SPC(398)*/
_AVElement_Mark=PTGNULL;
/*SPC(224)*/
(* _AS0Insert)=PTGNULL;
/*SPC(427)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_12(_TPPrule_12 _currn)
#else
void _VS1rule_12(_currn )
_TPPrule_12 _currn;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
ResetComputedRoot(_currn->_desc1->_ATKey, 1);
/*SPC(195)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_12(_TPPrule_12 _currn)
#else
void _VS2rule_12(_currn )
_TPPrule_12 _currn;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVLST_xRHSNontermCnt_post=ADD(_currn->_ATNontermCnt_pre, 1);
/*SPC(241)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_12(_TPPrule_12 _currn,PTGNode* _AS0TreeGram,PTGNode* _AS0Insert,PTGNode* _AS0_const10,PTGNode* _AS0_const7)
#else
void _VS3rule_12(_currn ,_AS0TreeGram,_AS0Insert,_AS0_const10,_AS0_const7)
_TPPrule_12 _currn;
PTGNode* _AS0_const7;
PTGNode* _AS0_const10;
PTGNode* _AS0Insert;
PTGNode* _AS0TreeGram;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*,PTGNode*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1Ptg)),(&( _AS1AttrPtg)),(&( _AS1Entity)),(&( _AS1Content)));
(* _AS0_const7)=IDENTICAL(_AS1Content);
/*SPC(136)*/
(* _AS0_const10)=IDENTICAL(_AS1Entity);
/*SPC(136)*/
_AVLST_xRHSTermCnt_post=_AVElementTermCnt_pre;
/*SPC(0)*/
(* _AS0TreeGram)=PTGComputedRoot(StringTable(_currn->_desc1->_ATSym));
/*SPC(393)*/
_AVElement_Mark=PTGMarker(_currn->_ATNontermCnt_pre);
/*SPC(240)*/
(* _AS0Insert)=_AVElement_Mark;
/*SPC(437)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_13(_TPPrule_13 _currn)
#else
void _VS1rule_13(_currn )
_TPPrule_13 _currn;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_13(_TPPrule_13 _currn)
#else
void _VS2rule_13(_currn )
_TPPrule_13 _currn;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVLST_xRHSNontermCnt_post=
((_currn->_desc1->_ATIsTerminal
) ? (_currn->_ATNontermCnt_pre
) : (ADD(_currn->_ATNontermCnt_pre, 1)))
;
/*SPC(232)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_13(_TPPrule_13 _currn,PTGNode* _AS0TreeGram,PTGNode* _AS0Insert,PTGNode* _AS0_const10,PTGNode* _AS0_const7)
#else
void _VS3rule_13(_currn ,_AS0TreeGram,_AS0Insert,_AS0_const10,_AS0_const7)
_TPPrule_13 _currn;
PTGNode* _AS0_const7;
PTGNode* _AS0_const10;
PTGNode* _AS0Insert;
PTGNode* _AS0TreeGram;

#endif
{
PTGNode _AS1Content;
PTGNode _AS1Entity;
PTGNode _AS1AttrPtg;
PTGNode _AS1Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*,PTGNode*)) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1,(&( _AS1Ptg)),(&( _AS1AttrPtg)),(&( _AS1Entity)),(&( _AS1Content)));
(* _AS0_const7)=IDENTICAL(_AS1Content);
/*SPC(135)*/
(* _AS0_const10)=IDENTICAL(_AS1Entity);
/*SPC(135)*/
_AVLST_xRHSTermCnt_post=
((_currn->_desc1->_ATIsTerminal
) ? (ADD(_AVElementTermCnt_pre, 1)
) : (_AVElementTermCnt_pre))
;
/*SPC(234)*/
(* _AS0TreeGram)=_AS1Ptg;
/*SPC(388)*/
_AVElement_Mark=
((_currn->_desc1->_ATIsTerminal
) ? (PTGMarker(_AVElementTermCnt_pre)
) : (PTGMarker(_currn->_ATNontermCnt_pre)))
;
/*SPC(228)*/
(* _AS0Insert)=_AVElement_Mark;
/*SPC(432)*/

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
_AVSyms__const1=_AVLST_Syms__const1;
/*SPC(133)*/
_AVSyms__const2=_AVLST_Syms__const2;
/*SPC(133)*/
_AVSyms__const3=_AVLST_Syms__const3;
/*SPC(133)*/
_AVSyms__const4=_AVLST_Syms__const4;
/*SPC(133)*/
_AVSyms__const10=_AVLST_Syms__const10;
/*SPC(133)*/

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
_AVxRHS__const5=_AVLST_xRHS__const5;
/*SPC(132)*/
_AVxRHS__const6=_AVLST_xRHS__const6;
/*SPC(132)*/
_AVxRHS__const7=_AVLST_xRHS__const7;
/*SPC(132)*/
_AVxRHS__const10=_AVLST_xRHS__const10;
/*SPC(132)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_16(_TPPrule_16 _currn)
#else
void _VS1rule_16(_currn )
_TPPrule_16 _currn;

#endif
{
PTGNode _AS2Content;
PTGNode _AS2Entity;
PTGNode _AS2AttrPtg;
PTGNode _AS2Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
ResetEntity(_currn->_desc2->_ATKey, PTGAltSeq(GetEntity(_currn->_desc2->_ATKey, PTGNULL), PTGAsIs(StringTable(_currn->_desc1->_ATSym))));
/*SPC(498)*/
ResetDefined(_currn->_desc2->_ATKey, 1);
ResetIsListofLhs(_currn->_desc2->_ATKey, 1);
;
/*SPC(187)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_16(_TPPrule_16 _currn,PTGNode* _AS0TreeGram,PTGNode* _AS0Element,PTGNode* _AS0_const10)
#else
void _VS2rule_16(_currn ,_AS0TreeGram,_AS0Element,_AS0_const10)
_TPPrule_16 _currn;
PTGNode* _AS0_const10;
PTGNode* _AS0Element;
PTGNode* _AS0TreeGram;

#endif
{
PTGNode _AS2Content;
PTGNode _AS2Entity;
PTGNode _AS2AttrPtg;
PTGNode _AS2Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*,PTGNode*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2Ptg)),(&( _AS2AttrPtg)),(&( _AS2Entity)),(&( _AS2Content)));
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
(* _AS0_const10)=PTGSeq(IDENTICAL(_AS2Entity), _AVSyms__const10);
/*SPC(130)*/
_AVLST_xGrammarClassComp_post=PTGSeq(_AVLST_xGrammarClassComp_post, PTGListofRule((* _IG_incl4), PTGAsIs(StringTable(_currn->_desc1->_ATSym)), _AS2Ptg, _AVSyms__const1, _AVSyms__const2));
/*SPC(253)*/
(* _AS0Element)=PTGElement(StringTable(_currn->_desc1->_ATSym), PTGListContent(_AVSyms__const4));
/*SPC(539)*/
(* _AS0TreeGram)=PTGListof(StringTable(_currn->_desc1->_ATSym), StringTable(_currn->_desc2->_ATSym), _AVSyms__const3);
/*SPC(378)*/
_AVG2PtgTemplates_post=PTGSeq(_AVG2PtgTemplates_post, PTGTriple(
((GetNoPtgGiven(_currn->_desc1->_ATKey, 1)
) ? (PTGListProd((* _IG_incl4), StringTable(_currn->_desc1->_ATSym))
) : (PTGNULL))
, 
((GetNoPtg2Given(_currn->_desc1->_ATKey, 1)
) ? (PTGListProd2((* _IG_incl4), StringTable(_currn->_desc1->_ATSym))
) : (PTGNULL))
, 
((GetNoPtg1Given(_currn->_desc1->_ATKey, 1)
) ? (PTGListProd1((* _IG_incl4), StringTable(_currn->_desc1->_ATSym))
) : (PTGNULL))
));
/*SPC(460)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_17(_TPPrule_17 _currn)
#else
void _VS1rule_17(_currn )
_TPPrule_17 _currn;

#endif
{
PTGNode _AS2Content;
PTGNode _AS2Entity;
PTGNode _AS2AttrPtg;
PTGNode _AS2Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
ResetEntity(_currn->_desc2->_ATKey, PTGAltSeq(GetEntity(_currn->_desc2->_ATKey, PTGNULL), PTGAsIs(StringTable(_currn->_desc1->_ATSym))));
/*SPC(488)*/
ResetDefined(_currn->_desc2->_ATKey, 1);
/*SPC(182)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_17(_TPPrule_17 _currn,PTGNode* _AS0TreeGram,PTGNode* _AS0Element,PTGNode* _AS0_const10)
#else
void _VS2rule_17(_currn ,_AS0TreeGram,_AS0Element,_AS0_const10)
_TPPrule_17 _currn;
PTGNode* _AS0_const10;
PTGNode* _AS0Element;
PTGNode* _AS0TreeGram;

#endif
{
PTGNode _AS2Content;
PTGNode _AS2Entity;
PTGNode _AS2AttrPtg;
PTGNode _AS2Ptg;

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR ,PTGNode*,PTGNode*,PTGNode*,PTGNode*)) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2,(&( _AS2Ptg)),(&( _AS2AttrPtg)),(&( _AS2Entity)),(&( _AS2Content)));
_AVLST_xRHSNontermCnt_post=1;
/*SPC(220)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
_AVLST_xRHSTermCnt_post=_AVLST_xRHSNontermCnt_post;
/*SPC(221)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
(* _AS0_const10)=PTGSeq(IDENTICAL(_AS2Entity), _AVxRHS__const10);
/*SPC(129)*/
_AVxProduction_Body_RuleAttr_66=_AVxRHS__const6;
/*SPC(444)*/
_AVxProduction_Content_RuleAttr_66=_AVxRHS__const7;
/*SPC(526)*/
(* _AS0Element)=PTGElement(StringTable(_currn->_desc1->_ATSym), 
((EQ(_AVxProduction_Content_RuleAttr_66, PTGNULL)
) ? (PTGAsIs("EMPTY")
) : (PTGContent(_AVxProduction_Content_RuleAttr_66)))
);
/*SPC(529)*/
(* _AS0TreeGram)=PTGPlain(StringTable(_currn->_desc1->_ATSym), StringTable(_currn->_desc2->_ATSym), _AVxRHS__const5);
/*SPC(368)*/
_AVG2PtgTemplates_post=
((GetNoPtgGiven(_currn->_desc1->_ATKey, 1)
) ? (PTGSeq(_AVG2PtgTemplates_post, 
((EQ(_AVxProduction_Body_RuleAttr_66, PTGNULL)
) ? (PTGEmpty((* _IG_incl4), StringTable(_currn->_desc1->_ATSym))
) : (PTGPlainProd((* _IG_incl4), StringTable(_currn->_desc1->_ATSym), _AVxProduction_Body_RuleAttr_66)))
)
) : (_AVG2PtgTemplates_post))
;
/*SPC(447)*/

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVxGrammar__const10=_AVLST_xGrammar__const10;
/*SPC(127)*/
_AVxGrammar__const11=_AVLST_xGrammar__const11;
/*SPC(127)*/
_AVxGrammar__const12=_AVLST_xGrammar__const12;
/*SPC(127)*/

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
_AVxSymbol_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(47)*/
_currn->_ATKey=KeyOf(_AVxSymbol_Bind);
/*SPC(49)*/

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
_currn->_ATIsTerminal=AND(NOT(GetDefined(_currn->_ATKey, 0)), NOT(GetComputedRoot(_currn->_ATKey, 0)));
/*SPC(209)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_26(_TPPrule_26 _currn,PTGNode* _AS0Ptg,PTGNode* _AS0AttrPtg,PTGNode* _AS0Entity,PTGNode* _AS0Content)
#else
void _VS3rule_26(_currn ,_AS0Ptg,_AS0AttrPtg,_AS0Entity,_AS0Content)
_TPPrule_26 _currn;
PTGNode* _AS0Content;
PTGNode* _AS0Entity;
PTGNode* _AS0AttrPtg;
PTGNode* _AS0Ptg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0Content)=
((_currn->_ATIsTerminal
) ? (PTGAsIs("#PCDATA")
) : (PTGEntityUse(StringTable(_currn->_ATTERM_1))))
;
/*SPC(548)*/
_AVxSymbol_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(119)*/
(* _AS0Ptg)=PTGId(_currn->_ATTERM_1);
/*SPC(212)*/
_AVG2PtgTemplates_post=
((AND(_currn->_ATIsTerminal, AND(_AVxSymbol_IsFirstOcc, GetNoPtgGiven(_currn->_ATKey, 1)))
) ? (PTGSeq(_AVG2PtgTemplates_post, PTGTerm((* _IG_incl4), (* _AS0Ptg)))
) : (_AVG2PtgTemplates_post))
;
/*SPC(416)*/
_AVxRHSInherit_post=
((_AVxSymbol_IsFirstOcc
) ? (
((GetIsListofLhs(_currn->_ATKey, 0)
) ? (PTGSeq(_AVxRHSInherit_post, PTGListComp((* _AS0Ptg), (* _IG_incl4)))
) : (
((GetDefined(_currn->_ATKey, 0)
) ? (PTGSeq(_AVxRHSInherit_post, PTGNontComp((* _AS0Ptg), (* _IG_incl4)))
) : (
((GetComputedRoot(_currn->_ATKey, 0)
) ? (PTGSeq(_AVxRHSInherit_post, PTGNontNoComp((* _AS0Ptg), (* _IG_incl4)))
) : (_AVxRHSInherit_post))
))
))

) : (_AVxRHSInherit_post))
;
/*SPC(274)*/
(* _AS0Entity)=
((AND(_AVxSymbol_IsFirstOcc, NOT(_currn->_ATIsTerminal))
) ? (PTGEntityDef(StringTable(_currn->_ATTERM_1), GetEntity(_currn->_ATKey, PTGNULL))
) : (PTGNULL))
;
/*SPC(514)*/
(* _AS0AttrPtg)=PTGAttr((* _AS0Ptg), (* _IG_incl4));
/*SPC(213)*/

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
_AVxSymbol_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(47)*/
_currn->_ATKey=KeyOf(_AVxSymbol_Bind);
/*SPC(49)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_25(_TPPrule_25 _currn)
#else
void _VS2rule_25(_currn )
_TPPrule_25 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATIsTerminal=AND(NOT(GetDefined(_currn->_ATKey, 0)), NOT(GetComputedRoot(_currn->_ATKey, 0)));
/*SPC(209)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS3rule_25(_TPPrule_25 _currn,PTGNode* _AS0Ptg,PTGNode* _AS0AttrPtg,PTGNode* _AS0Entity,PTGNode* _AS0Content)
#else
void _VS3rule_25(_currn ,_AS0Ptg,_AS0AttrPtg,_AS0Entity,_AS0Content)
_TPPrule_25 _currn;
PTGNode* _AS0Content;
PTGNode* _AS0Entity;
PTGNode* _AS0AttrPtg;
PTGNode* _AS0Ptg;

#endif
{

_VisitVarDecl()
_VisitEntry();
(* _AS0Content)=
((_currn->_ATIsTerminal
) ? (PTGAsIs("#PCDATA")
) : (PTGEntityUse(StringTable(_currn->_ATTERM_1))))
;
/*SPC(548)*/
_AVxSymbol_IsFirstOcc=SetGetFirstOcc(_currn->_ATKey, 1, 0);
/*SPC(119)*/
(* _AS0Ptg)=PTGId(_currn->_ATTERM_1);
/*SPC(212)*/
_AVG2PtgTemplates_post=
((AND(_currn->_ATIsTerminal, AND(_AVxSymbol_IsFirstOcc, GetNoPtgGiven(_currn->_ATKey, 1)))
) ? (PTGSeq(_AVG2PtgTemplates_post, PTGTerm((* _IG_incl4), (* _AS0Ptg)))
) : (_AVG2PtgTemplates_post))
;
/*SPC(416)*/
_AVxRHSInherit_post=
((_AVxSymbol_IsFirstOcc
) ? (
((GetIsListofLhs(_currn->_ATKey, 0)
) ? (PTGSeq(_AVxRHSInherit_post, PTGListComp((* _AS0Ptg), (* _IG_incl4)))
) : (
((GetDefined(_currn->_ATKey, 0)
) ? (PTGSeq(_AVxRHSInherit_post, PTGNontComp((* _AS0Ptg), (* _IG_incl4)))
) : (
((GetComputedRoot(_currn->_ATKey, 0)
) ? (PTGSeq(_AVxRHSInherit_post, PTGNontNoComp((* _AS0Ptg), (* _IG_incl4)))
) : (_AVxRHSInherit_post))
))
))

) : (_AVxRHSInherit_post))
;
/*SPC(274)*/
(* _AS0Entity)=
((AND(_AVxSymbol_IsFirstOcc, NOT(_currn->_ATIsTerminal))
) ? (PTGEntityDef(StringTable(_currn->_ATTERM_1), GetEntity(_currn->_ATKey, PTGNULL))
) : (PTGNULL))
;
/*SPC(514)*/
(* _AS0AttrPtg)=PTGAttr((* _AS0Ptg), (* _IG_incl4));
/*SPC(213)*/

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
_AVxRule_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(47)*/
_currn->_ATKey=KeyOf(_AVxRule_Bind);
/*SPC(49)*/

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
_AVxRule_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(47)*/
_currn->_ATKey=KeyOf(_AVxRule_Bind);
/*SPC(49)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_22(_TPPrule_22 _currn)
#else
void _VS1rule_22(_currn )
_TPPrule_22 _currn;

#endif
{
CharPtr* _IL_incl4;
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATPrefix);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATEnv);
_currn->_ATEnv=RootEnv;
/*SPC(12)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_currn->_ATPrefix=StringTable(GetClpValue(Prefix, NoStrIndex));
/*SPC(205)*/
_AVG2PtgTemplates_post=PTGNULL;
/*SPC(290)*/
_AVxRHSInherit_post=PTGNULL;
/*SPC(270)*/
_AVLST_xGrammarClassComp_post=PTGPlainRules(_currn->_ATPrefix);
/*SPC(248)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
PTGOutFile(CatStrStr("treeDef/", CatStrStr(_currn->_ATPrefix, ".dtd")), PTGdtd(_AVxGrammar__const10, _AVxGrammar__const11));
/*SPC(482)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVxRoot_TreeGram=_AVxGrammar__const12;
/*SPC(361)*/
PTGOutFile("tree", PTGFrame(_currn->_ATPrefix, _AVxRoot_TreeGram, _AVLST_xGrammarClassComp_post, _AVxRHSInherit_post, _AVG2PtgTemplates_post));
/*SPC(411)*/
_IG_incl4=_IL_incl4;
_IG_incl0=_IL_incl0;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_20(_TPPrule_20 _currn)
#else
void _VS2rule_20(_currn )
_TPPrule_20 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

