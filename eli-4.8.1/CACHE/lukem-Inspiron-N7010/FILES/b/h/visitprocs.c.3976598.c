
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
Environment* _IG_incl2;
Environment* _IG_incl0;
PTGNode _AVoptparamsargs_post;
PTGNode _AVoptparamsargvars_post;
PTGNode _AVoptparamsnames_post;
int _AVoptparamsargcount_post;
PTGNode _AVoptattrssends_post;
PTGNode _AVoptattrsansitypes_post;
PTGNode _AVoptattrstypes_post;
PTGNode _AVoptattrsansiargs_post;
PTGNode _AVoptattrsattrdbs_post;
PTGNode _AVtranslation_sig_translations_RuleAttr_56;
PTGNode _AVtranslation_sig_translationvars_RuleAttr_56;
CharPtr _AViduse_idcode;
int _AViduse_Sym;
Binding _AViduse_Bind;
PTGNode _AVaspect_stmtreqsyms_post;
PTGNode _AVaspect_stmtsigs_post;
PTGNode _AVevent_sigfuncs_post;
PTGNode _AVaspect_stmtentries_post;
PTGNode _AVaspect_stmtincls_post;
PTGNode _AVaspect_stmteventdbs_post;
PTGNode _AVattrargs_pre;
PTGNode _AVattr_cast_RuleAttr_61;
PTGNode _AVattr_type_RuleAttr_61;
PTGNode _AVattr_arg_RuleAttr_61;
PTGNode _AVevent_sig_translations;
PTGNode _AVevent_sig_translationvars;
PTGNode _AVaspect_stmtaspectdbs_post;
Binding _AVtypeid_Bind;
CharPtr _AVtypeid_idcode;
int _AVtypeid_Sym;
DefTableKey _AVtypeid_Key;
int _AViddef_ExportUnique;
Binding _AViddef_Bind;

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

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
_AVtranslation_sig_translations_RuleAttr_56=PTGSeq(GetTranslations(_currn->_desc2->_ATKey, PTGNULL), PTGtranslation(_currn->_desc1->_ATidcode, _currn->_desc3->_ATline, filename, _currn->_desc3->_ATbodycode));
/*SPC(588)*/
_AVtranslation_sig_translationvars_RuleAttr_56=PTGSeq(GetTranslationVars(_currn->_desc2->_ATKey, PTGNULL), PTGtranslationvar(_currn->_desc1->_ATidcode));
/*SPC(593)*/
SetTranslations(_currn->_desc2->_ATKey, _AVtranslation_sig_translations_RuleAttr_56, _AVtranslation_sig_translations_RuleAttr_56);
SetTranslationVars(_currn->_desc2->_ATKey, _AVtranslation_sig_translationvars_RuleAttr_56, _AVtranslation_sig_translationvars_RuleAttr_56);
;
/*SPC(595)*/

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVoptparamsargs_post=PTGSeq(_AVoptparamsargs_post, PTGarg(Getsend(_AVtypeid_Key, StringTable(_AVtypeid_Sym)), _currn->_desc2->_ATidcode));
/*SPC(510)*/
_AVoptparamsargvars_post=PTGSSeq(_AVoptparamsargvars_post, PTGDecl(Gettype(_AVtypeid_Key, _AVtypeid_idcode), _currn->_desc2->_ATidcode));
/*SPC(514)*/
_AVoptparamsnames_post=PTGNSeq(_AVoptparamsnames_post, Getamp(_AVtypeid_Key, "&"), _currn->_desc2->_ATidcode);
/*SPC(508)*/
_AVoptparamsargcount_post=ADD(_AVoptparamsargcount_post, 1);
/*SPC(334)*/

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
_currn->_ATbodycode=PTGId(_currn->_ATTERM_1);
/*SPC(462)*/

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
_AVaspect_stmtincls_post=PTGSeq(_AVaspect_stmtincls_post, PTGincl(PTGId(_currn->_ATTERM_1)));
/*SPC(424)*/

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
void _VS3rule_5(_TPPrule_5 _currn)
#else
void _VS3rule_5(_currn )
_TPPrule_5 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVaspect_stmtincls_post=PTGSeq(_AVaspect_stmtincls_post, PTGincl(PTGId(_currn->_ATTERM_1)));
/*SPC(418)*/

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_6(_TPPrule_6 _currn)
#else
void _VS2rule_6(_currn )
_TPPrule_6 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVoptattrssends_post=PTGSeq(_AVoptattrssends_post, PTGsend(Getsend(_AVtypeid_Key, StringTable(_AVtypeid_Sym)), _currn->_desc2->_ATidcode));
/*SPC(560)*/
_AVoptparamsargs_post=
((EQ(_AVattrargs_pre, PTGNULL)
) ? (PTGAsIs(_currn->_desc2->_ATidcode)
) : (PTGCommaSeq(_AVattrargs_pre, PTGAsIs(_currn->_desc2->_ATidcode))))
;
/*SPC(550)*/
_AVoptattrsattrdbs_post=PTGSSeq3(_AVoptattrsattrdbs_post, _currn->_desc2->_ATidcode, PTGId(_currn->_ATTERM_1));
/*SPC(392)*/
_AVattr_cast_RuleAttr_61=Getcast(_AVtypeid_Key, PTGAsIs("(long)"));
/*SPC(549)*/
_AVattr_type_RuleAttr_61=PTGAsIs(Gettype(_AVtypeid_Key, _AVtypeid_idcode));
/*SPC(553)*/
_AVattr_arg_RuleAttr_61=PTGSSeq(_AVattr_type_RuleAttr_61, PTGAsIs(_currn->_desc2->_ATidcode));
/*SPC(554)*/
_AVoptattrsansitypes_post=
((EQ(_AVattrargs_pre, PTGNULL)
) ? (_AVattr_type_RuleAttr_61
) : (PTGCommaSeq(_AVoptattrsansitypes_post, _AVattr_type_RuleAttr_61)))
;
/*SPC(558)*/
_AVoptattrstypes_post=PTGDeclSeq(_AVoptattrstypes_post, _AVattr_arg_RuleAttr_61);
/*SPC(557)*/
_AVoptattrsansiargs_post=
((EQ(_AVattrargs_pre, PTGNULL)
) ? (_AVattr_arg_RuleAttr_61
) : (PTGCommaSeq(_AVoptattrsansiargs_post, _AVattr_arg_RuleAttr_61)))
;
/*SPC(555)*/

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
_currn->_ATexported=0;
/*SPC(384)*/

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
_currn->_ATexported=1;
/*SPC(378)*/

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
_AVoptattrssends_post=PTGNULL;
/*SPC(529)*/
_AVoptattrsansitypes_post=PTGNULL;
/*SPC(528)*/
_AVoptattrstypes_post=PTGNULL;
/*SPC(527)*/
_AVoptattrsansiargs_post=PTGNULL;
/*SPC(526)*/
_AVoptparamsargs_post=PTGNULL;
/*SPC(525)*/
_AVoptattrsattrdbs_post=PTGNULL;
/*SPC(364)*/
_currn->_desc3->_ATExportEnv=NewScope((* _IG_incl0));
/*SPC(168)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

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
_AVaspect_stmtsigs_post=PTGSeq(_AVaspect_stmtsigs_post, PTGsig(_currn->_desc1->_ATidcode, _currn->_desc3->_ATansitypes_post));
/*SPC(538)*/
_AVaspect_stmteventdbs_post=PTGSeq(_AVaspect_stmteventdbs_post, PTGeventdb(_currn->_desc1->_ATidcode, PTGId(_currn->_ATTERM_1), _currn->_desc3->_ATattrdbs_post, PTGNumb(_currn->_desc2->_ATexported)));
/*SPC(366)*/
_AVevent_sig_translations=GetTranslations(_currn->_desc1->_ATKey, PTGNULL);
/*SPC(579)*/
_AVevent_sig_translationvars=GetTranslationVars(_currn->_desc1->_ATKey, PTGNULL);
/*SPC(581)*/
_AVevent_sigfuncs_post=PTGSeq(_AVevent_sigfuncs_post, PTGefunc(_AVevent_sig_translationvars, _currn->_desc1->_ATidcode, _currn->_desc3->_ATansiargs_post, _currn->_desc3->_ATargs_post, _currn->_desc3->_ATtypes_post, _currn->_desc3->_ATsends_post));
/*SPC(531)*/

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

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVaspect_stmtaspectdbs_post=PTGSeq(_AVaspect_stmtaspectdbs_post, PTGaspectdb(_currn->_desc1->_ATidcode));
/*SPC(355)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_11(_TPPrule_11 _currn)
#else
void _VS1rule_11(_currn )
_TPPrule_11 _currn;

#endif
{
Environment* _IL_incl2;
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATTypeEnv);
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATExportEnv);
_currn->_ATExportEnv=ExportRootEnv;
/*SPC(157)*/
_currn->_ATTypeEnv=TypeRootEnv;
/*SPC(13)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVaspect_stmtreqsyms_post=PTGNULL;
/*SPC(631)*/
_AVaspect_stmtsigs_post=PTGNULL;
/*SPC(408)*/
_AVevent_sigfuncs_post=PTGNULL;
/*SPC(405)*/
_AVaspect_stmtentries_post=PTGNULL;
/*SPC(404)*/
_AVaspect_stmtincls_post=PTGNULL;
/*SPC(403)*/
_AVaspect_stmteventdbs_post=PTGNULL;
/*SPC(346)*/
_AVaspect_stmtaspectdbs_post=PTGNULL;
/*SPC(345)*/
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
PTGOutFile(dbfilename, PTGdb(_AVaspect_stmtaspectdbs_post, _AVaspect_stmteventdbs_post));
/*SPC(347)*/
PTGOutFile(cfilename, PTGcfile(PTGAsIs(basefilename), _AVevent_sigfuncs_post, _AVaspect_stmtentries_post));
/*SPC(407)*/
PTGOutFile(hfilename, PTGhfile(PTGAsIs(basefilename), _AVaspect_stmtsigs_post, _AVaspect_stmtincls_post));
/*SPC(410)*/
PTGOutFile(reqsymfilename, PTGreqsyms(_AVaspect_stmtreqsyms_post));
/*SPC(632)*/
_IG_incl2=_IL_incl2;
_IG_incl0=_IL_incl0;

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
_AVtypeid_Sym=_currn->_ATTERM_1;
/*SPC(605)*/
_AVtypeid_Bind=BindIdn((* _IG_incl2), _AVtypeid_Sym);
/*SPC(41)*/
_AVtypeid_idcode=StringTable(_AVtypeid_Sym);
/*SPC(433)*/
_AVtypeid_Key=KeyOf(_AVtypeid_Bind);
/*SPC(44)*/

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS3MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

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
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATExportEnv);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATargs_post=_AVoptparamsargs_post;
/*SPC(0)*/
_currn->_ATargvars_post=_AVoptparamsargvars_post;
/*SPC(0)*/
_currn->_ATargcount_post=_AVoptparamsargcount_post;
/*SPC(0)*/
_IG_incl0=_IL_incl0;

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
_AViduse_Sym=_currn->_ATTERM_1;
/*SPC(605)*/
_AViduse_Bind=BindingInEnv((* _IG_incl0), _AViduse_Sym);
/*SPC(199)*/
_currn->_ATKey=KeyOf(_AViduse_Bind);
/*SPC(202)*/
_AViduse_idcode=StringTable(_AViduse_Sym);
/*SPC(433)*/

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
_AViddef_Bind=BindIdn((* _IG_incl0), _currn->_ATSym);
/*SPC(185)*/
_currn->_ATKey=KeyOf(_AViddef_Bind);
/*SPC(188)*/
SetExportUnique(_currn->_ATKey, 1, 0);
/*SPC(308)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_17(_TPPrule_17 _currn)
#else
void _VS2rule_17(_currn )
_TPPrule_17 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AViddef_ExportUnique=GetExportUnique(_currn->_ATKey, 0);
/*SPC(311)*/
_currn->_ATidcode=StringTable(_currn->_ATSym);
/*SPC(433)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_16(_TPPrule_16 _currn)
#else
void _VS1rule_16(_currn )
_TPPrule_16 _currn;

#endif
{
Environment* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATExportEnv);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_currn->_ATsends_post=_AVoptattrssends_post;
/*SPC(0)*/
_currn->_ATansitypes_post=_AVoptattrsansitypes_post;
/*SPC(0)*/
_currn->_ATtypes_post=_AVoptattrstypes_post;
/*SPC(0)*/
_currn->_ATansiargs_post=_AVoptattrsansiargs_post;
/*SPC(0)*/
_currn->_ATargs_post=_AVoptparamsargs_post;
/*SPC(0)*/
_currn->_ATattrdbs_post=_AVoptattrsattrdbs_post;
/*SPC(0)*/
_IG_incl0=_IL_incl0;

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
_AVattrargs_pre=_AVoptparamsargs_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
_AVattrargs_pre=_AVoptparamsargs_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1operation_sig2(_TPPoperation_sig2 _currn)
#else
void _VS1operation_sig2(_currn )
_TPPoperation_sig2 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVoptparamsargs_post=PTGNULL;
/*SPC(488)*/
_AVoptparamsargvars_post=PTGNULL;
/*SPC(489)*/
_AVoptparamsnames_post=PTGNULL;
/*SPC(490)*/
_AVoptparamsargcount_post=0;
/*SPC(329)*/
_currn->_desc2->_ATExportEnv=NewScope((* _IG_incl0));
/*SPC(168)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

if (NE(_AVtypeid_Key, strKey)) {
message(FATAL, "Non-string return type", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(620)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2operation_sig2(_TPPoperation_sig2 _currn)
#else
void _VS2operation_sig2(_currn )
_TPPoperation_sig2 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVaspect_stmtreqsyms_post=PTGSeq(_AVaspect_stmtreqsyms_post, PTGreqsym(_currn->_desc1->_ATidcode));
/*SPC(645)*/
_AVevent_sigfuncs_post=PTGSeq(_AVevent_sigfuncs_post, PTGcmdfunc(_currn->_desc1->_ATidcode, _currn->_desc2->_ATargvars_post, 
((EQ(_currn->_desc2->_ATargcount_post, 0)
) ? (PTGNULL
) : (_currn->_desc2->_ATargs_post))
, _currn->_desc4->_ATbodycode, _currn->_desc4->_ATline, filename));
/*SPC(491)*/
_AVaspect_stmtentries_post=PTGSeq(_AVaspect_stmtentries_post, PTGentry(_currn->_desc1->_ATidcode));
/*SPC(450)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1operation_sig1(_TPPoperation_sig1 _currn)
#else
void _VS1operation_sig1(_currn )
_TPPoperation_sig1 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVoptparamsargs_post=PTGNULL;
/*SPC(469)*/
_AVoptparamsargvars_post=PTGNULL;
/*SPC(470)*/
_AVoptparamsnames_post=PTGNULL;
/*SPC(471)*/
_AVoptparamsargcount_post=0;
/*SPC(323)*/
_currn->_desc2->_ATExportEnv=NewScope((* _IG_incl0));
/*SPC(168)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2operation_sig1(_TPPoperation_sig1 _currn)
#else
void _VS2operation_sig1(_currn )
_TPPoperation_sig1 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVaspect_stmtreqsyms_post=PTGSeq(_AVaspect_stmtreqsyms_post, PTGreqsym(_currn->_desc1->_ATidcode));
/*SPC(638)*/
_AVevent_sigfuncs_post=PTGSeq(_AVevent_sigfuncs_post, PTGcmdfunc(_currn->_desc1->_ATidcode, _currn->_desc2->_ATargvars_post, 
((EQ(_currn->_desc2->_ATargcount_post, 0)
) ? (PTGNULL
) : (_currn->_desc2->_ATargs_post))
, _currn->_desc3->_ATbodycode, _currn->_desc3->_ATline, filename));
/*SPC(472)*/
_AVaspect_stmtentries_post=PTGSeq(_AVaspect_stmtentries_post, PTGentry(_currn->_desc1->_ATidcode));
/*SPC(443)*/

_VisitExit();
}

