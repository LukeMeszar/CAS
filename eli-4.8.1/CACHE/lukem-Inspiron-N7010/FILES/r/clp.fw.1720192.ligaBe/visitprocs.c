
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
int* _IG_incl7;
PTGNode* _IG_incl6;
int* _IG_incl4;
PTGNode* _IG_incl8;
cstr* _IG_incl5;
int* _IG_incl3;
int* _IG_incl2;
cstr* _IG_incl1;
int* _IG_incl0;
PTGNode _AVparamexterns_post;
PTGNode _AVparamdecls_post;
cstr _AVtype_joinedstr;
int _AVtype_docid;
int _AVtype_nameid;
cstr _AVtype_desc;
cstr _AVjoin_joinedstr;
int _AVliterals__const0;
int _AVparamnumopts_post;
PTGNode _AVparamousages_post;
PTGNode _AVparamopts_post;
int _AVtparam__const0;
int _AVparam__const0;
int _AVparaminputs_post;
int _AVparamusageerrmsg_post;
PTGNode _AVparamerrmsg_post;
PTGNode _AVparampusages_post;
PTGNode _AVparamparams_post;
int _AVparam_maxstrlen;
PTGNode _AVliteral_usage;
int _AVliteral_len;
int _AVparams__const0;

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
_currn->_ATid=NoStrIndex;
/*SPC(242)*/

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
_AVparam__const0=ZERO();
/*SPC(216)*/

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
_AVparamusageerrmsg_post=1;
/*SPC(219)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/

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
_AVparam__const0=ZERO();
/*SPC(210)*/

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
_AVparamerrmsg_post=PTGstr(_currn->_ATTERM_1);
/*SPC(213)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/

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
_AVparam__const0=ZERO();
/*SPC(198)*/

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
_AVparamnumopts_post=ADD(_AVparamnumopts_post, 1);
/*SPC(201)*/
_AVparamopts_post=PTGseq(_AVparamopts_post, PTGseq(PTGlit(_currn->_ATTERM_1), PTGopt("USAGE", "", PTGnone(), PTGnone(), PTGnone())));
/*SPC(202)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/
_AVparamousages_post=PTGseq(_AVparamousages_post, PTGuuse(PTGpstr(_currn->_ATTERM_1, _AVparam_maxstrlen)));
/*SPC(206)*/

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
_AVparam__const0=ZERO();
/*SPC(183)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkextern(_currn->_desc1->_ATid));
/*SPC(188)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGkdecl(_currn->_desc1->_ATid));
/*SPC(186)*/

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

if (NE(_AVparaminputs_post, 0)) {
message(ERROR, "can't have more than one input parameter", 0, (&( _currn->_AT_pos)));

} else {
}
;
/*SPC(195)*/
_AVparaminputs_post=ADD(_AVparaminputs_post, 1);
/*SPC(192)*/
_AVparamparams_post=PTGseq(_AVparamparams_post, PTGinput(_currn->_desc1->_ATid));
/*SPC(187)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/
_AVparampusages_post=PTGseq(_AVparampusages_post, PTGuse(PTGpstr(_currn->_desc1->_ATid, _AVparam_maxstrlen), _currn->_desc2->_ATid));
/*SPC(189)*/

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVparam__const0=ZERO();
/*SPC(172)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkkextern(_currn->_desc1->_ATid));
/*SPC(177)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGkkdecl(_currn->_desc1->_ATid));
/*SPC(175)*/

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
_AVparamparams_post=PTGseq(_AVparamparams_post, PTGmparam(_currn->_desc1->_ATid));
/*SPC(176)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/
_AVparampusages_post=PTGseq(_AVparampusages_post, PTGuses(PTGpstr(_currn->_desc1->_ATid, _AVparam_maxstrlen), _currn->_desc2->_ATid));
/*SPC(178)*/

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
_AVparam__const0=ZERO();
/*SPC(161)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkextern(_currn->_desc1->_ATid));
/*SPC(166)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGkdecl(_currn->_desc1->_ATid));
/*SPC(164)*/

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
_AVparamparams_post=PTGseq(_AVparamparams_post, PTGparam(_currn->_desc1->_ATid));
/*SPC(165)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/
_AVparampusages_post=PTGseq(_AVparampusages_post, PTGuse(PTGpstr(_currn->_desc1->_ATid, _AVparam_maxstrlen), _currn->_desc2->_ATid));
/*SPC(167)*/

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
_currn->_ATspaced=1;
/*SPC(157)*/
_AVjoin_joinedstr="| SPACED | JOINED";
/*SPC(158)*/
_currn->_ATjoined=1;
/*SPC(156)*/

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
_currn->_ATspaced=0;
/*SPC(149)*/
_AVjoin_joinedstr="| JOINED";
/*SPC(150)*/
_currn->_ATjoined=1;
/*SPC(148)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_12(_TPPrule_12 _currn)
#else
void _VS1rule_12(_currn )
_TPPrule_12 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_currn->_ATspaced=1;
/*SPC(141)*/
_AVjoin_joinedstr="| SPACED";
/*SPC(142)*/
_currn->_ATjoined=0;
/*SPC(140)*/

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
_AVtype_joinedstr=(* _IG_incl1);
/*SPC(68)*/
_AVtype_docid=(* _IG_incl2);
/*SPC(67)*/
_AVtype_nameid=(* _IG_incl3);
/*SPC(66)*/
_currn->_ATrep=1;
/*SPC(134)*/
_AVtype_desc="string";
/*SPC(129)*/
_currn->_ATopt=PTGopt("STRVAL | PLURAL", _AVtype_joinedstr, PTGnone(), PTGnone(), PTGvar(_AVtype_nameid));
/*SPC(132)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkkextern(_AVtype_nameid));
/*SPC(131)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGkkdecl(_AVtype_nameid));
/*SPC(130)*/

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
_AVtype_joinedstr=(* _IG_incl1);
/*SPC(68)*/
_AVtype_docid=(* _IG_incl2);
/*SPC(67)*/
_AVtype_nameid=(* _IG_incl3);
/*SPC(66)*/
_currn->_ATrep=0;
/*SPC(69)*/
_AVtype_desc="string";
/*SPC(118)*/
_currn->_ATopt=PTGopt("STRVAL", _AVtype_joinedstr, PTGcount(_AVtype_nameid), PTGvar(_AVtype_nameid), PTGnone());
/*SPC(122)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkextern(_AVtype_nameid));
/*SPC(121)*/
_AVparamdecls_post=PTGseq3(_AVparamdecls_post, PTGkdecl(_AVtype_nameid), PTGidecl(_AVtype_nameid));
/*SPC(119)*/

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
_AVtype_joinedstr=(* _IG_incl1);
/*SPC(68)*/
_AVtype_docid=(* _IG_incl2);
/*SPC(67)*/
_AVtype_nameid=(* _IG_incl3);
/*SPC(66)*/
_currn->_ATrep=1;
/*SPC(112)*/
_AVtype_desc="int";
/*SPC(107)*/
_currn->_ATopt=PTGopt("INTVAL | PLURAL", _AVtype_joinedstr, PTGnone(), PTGnone(), PTGvar(_AVtype_nameid));
/*SPC(110)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkkextern(_AVtype_nameid));
/*SPC(109)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGkkdecl(_AVtype_nameid));
/*SPC(108)*/

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
_AVtype_joinedstr=(* _IG_incl1);
/*SPC(68)*/
_AVtype_docid=(* _IG_incl2);
/*SPC(67)*/
_AVtype_nameid=(* _IG_incl3);
/*SPC(66)*/
_currn->_ATrep=0;
/*SPC(69)*/
_AVtype_desc="int";
/*SPC(96)*/
_currn->_ATopt=PTGopt("INTVAL", _AVtype_joinedstr, PTGcount(_AVtype_nameid), PTGvar(_AVtype_nameid), PTGnone());
/*SPC(100)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGkextern(_AVtype_nameid));
/*SPC(99)*/
_AVparamdecls_post=PTGseq3(_AVparamdecls_post, PTGkdecl(_AVtype_nameid), PTGidecl(_AVtype_nameid));
/*SPC(97)*/

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
_AVtype_joinedstr=(* _IG_incl1);
/*SPC(68)*/
_AVtype_docid=(* _IG_incl2);
/*SPC(67)*/
_AVtype_nameid=(* _IG_incl3);
/*SPC(66)*/
_currn->_ATrep=1;
/*SPC(90)*/
_AVtype_desc="";
/*SPC(85)*/
_currn->_ATopt=PTGopt("BOOL | PLURAL", "", PTGvar(_AVtype_nameid), PTGnone(), PTGnone());
/*SPC(88)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGiextern(_AVtype_nameid));
/*SPC(87)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGbdecl(_AVtype_nameid));
/*SPC(86)*/

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
_AVtype_joinedstr=(* _IG_incl1);
/*SPC(68)*/
_AVtype_docid=(* _IG_incl2);
/*SPC(67)*/
_AVtype_nameid=(* _IG_incl3);
/*SPC(66)*/
_currn->_ATrep=0;
/*SPC(69)*/
_AVtype_desc="";
/*SPC(75)*/
_currn->_ATopt=PTGopt("BOOL", "", PTGvar(_AVtype_nameid), PTGnone(), PTGnone());
/*SPC(78)*/
_AVparamexterns_post=PTGseq(_AVparamexterns_post, PTGiextern(_AVtype_nameid));
/*SPC(77)*/
_AVparamdecls_post=PTGseq(_AVparamdecls_post, PTGbdecl(_AVtype_nameid));
/*SPC(76)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_19(_TPPrule_19 _currn)
#else
void _VS1rule_19(_currn )
_TPPrule_19 _currn;

#endif
{
cstr* _IL_incl5;
int* _IL_incl3;
int* _IL_incl2;
cstr* _IL_incl1;

_VisitVarDecl()
_VisitEntry();
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATdesc);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATnameid);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATdocid);
_IL_incl1=_IG_incl1;_IG_incl1= &(_currn->_ATjoinedstr);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc3->_prod])))((NODEPTR) _currn->_desc3);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc5->_prod])))((NODEPTR) _currn->_desc5);
_currn->_ATjoinedstr=_AVjoin_joinedstr;
/*SPC(58)*/
_currn->_ATnameid=_currn->_desc1->_ATid;
/*SPC(55)*/
_currn->_ATdocid=_currn->_desc5->_ATid;
/*SPC(54)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc4->_prod])))((NODEPTR) _currn->_desc4);
_currn->_ATdesc=_AVtype_desc;
/*SPC(60)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVtparam__const0=_AVliterals__const0;
/*SPC(51)*/
_IG_incl5=_IL_incl5;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl1=_IL_incl1;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_19(_TPPrule_19 _currn)
#else
void _VS2rule_19(_currn )
_TPPrule_19 _currn;

#endif
{
int* _IL_incl7;
PTGNode* _IL_incl6;
int* _IL_incl4;
PTGNode* _IL_incl8;
cstr* _IL_incl5;
int* _IL_incl3;
int* _IL_incl2;
cstr* _IL_incl1;

_VisitVarDecl()
_VisitEntry();
_IL_incl7=_IG_incl7;_IG_incl7= &(_currn->_ATjoined);
_IL_incl6=_IG_incl6;_IG_incl6= &(_currn->_ATusage);
_IL_incl4=_IG_incl4;_IG_incl4= &(_currn->_ATspaced);
_IL_incl8=_IG_incl8;_IG_incl8= &(_currn->_ATopt);
_IL_incl5=_IG_incl5;_IG_incl5= &(_currn->_ATdesc);
_IL_incl3=_IG_incl3;_IG_incl3= &(_currn->_ATnameid);
_IL_incl2=_IG_incl2;_IG_incl2= &(_currn->_ATdocid);
_IL_incl1=_IG_incl1;_IG_incl1= &(_currn->_ATjoinedstr);
_currn->_ATusage=PTGmsg(_currn->_desc5->_ATid, 
((_currn->_desc4->_ATrep
) ? ("*"
) : (""))
);
/*SPC(61)*/
_currn->_ATspaced=_currn->_desc3->_ATspaced;
/*SPC(59)*/
_currn->_ATjoined=_currn->_desc3->_ATjoined;
/*SPC(57)*/
_currn->_ATopt=_currn->_desc4->_ATopt;
/*SPC(56)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_IG_incl7=_IL_incl7;
_IG_incl6=_IL_incl6;
_IG_incl4=_IL_incl4;
_IG_incl8=_IL_incl8;
_IG_incl5=_IL_incl5;
_IG_incl3=_IL_incl3;
_IG_incl2=_IL_incl2;
_IG_incl1=_IL_incl1;

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_20(_TPPrule_20 _currn)
#else
void _VS1rule_20(_currn )
_TPPrule_20 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVparam__const0=ZERO();
/*SPC(42)*/

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
_AVparamnumopts_post=ADD(_AVparamnumopts_post, 1);
/*SPC(45)*/
_AVparamopts_post=PTGseq(_AVparamopts_post, PTGtopt(_currn->_ATTERM_1));
/*SPC(46)*/
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/
_AVparamousages_post=PTGseq(_AVparamousages_post, PTGtuse(PTGpstr(_currn->_ATTERM_1, _AVparam_maxstrlen)));
/*SPC(47)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_21(_TPPrule_21 _currn)
#else
void _VS1rule_21(_currn )
_TPPrule_21 _currn;

#endif
{
int* _IL_incl0;

_VisitVarDecl()
_VisitEntry();
_IL_incl0=_IG_incl0;_IG_incl0= &(_currn->_ATmaxstrlen);
_AVparamexterns_post=PTGNULL;
/*SPC(28)*/
_AVparamdecls_post=PTGNULL;
/*SPC(21)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
PTGOutFile("clp.h", PTGheader(_AVparamexterns_post));
/*SPC(34)*/
_currn->_ATmaxstrlen=_AVparams__const0;
/*SPC(18)*/
_AVparaminputs_post=0;
/*SPC(16)*/
_AVparamusageerrmsg_post=0;
/*SPC(15)*/
_AVparamnumopts_post=0;
/*SPC(22)*/
_AVparamerrmsg_post=PTGcstr("%p cannot open %f: %t");
/*SPC(14)*/
_AVparampusages_post=PTGNULL;
/*SPC(27)*/
_AVparamousages_post=PTGNULL;
/*SPC(26)*/
_AVparamparams_post=PTGNULL;
/*SPC(25)*/
_AVparamopts_post=PTGNULL;
/*SPC(23)*/
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
PTGOutFile("clp.c", PTGfile(_currn->_desc1->_ATdecls_post, _AVparamnumopts_post, _AVparamopts_post, _AVparamousages_post, _AVparampusages_post, _AVparamerrmsg_post, _AVparamusageerrmsg_post, _AVparamparams_post));
/*SPC(33)*/
_IG_incl0=_IL_incl0;

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
_AVparam__const0=_AVtparam__const0;
/*SPC(265)*/

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVparam_maxstrlen=(* _IG_incl0);
/*SPC(39)*/

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
_AVparamdecls_post=_currn->_desc1->_ATdecls_post;
/*SPC(0)*/
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVparams__const0=MAX(_AVparams__const0, _AVparam__const0);
/*SPC(261)*/
_currn->_ATdecls_post=_AVparamdecls_post;
/*SPC(0)*/

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
_AVparams__const0=ZERO();
/*SPC(257)*/
_currn->_ATdecls_post=_AVparamdecls_post;
/*SPC(0)*/

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);
_AVliterals__const0=MAX(_AVliterals__const0, IDENTICAL(_AVliteral_len));
/*SPC(253)*/

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
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc2->_prod])))((NODEPTR) _currn->_desc2);

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
(*(_CALL_VS_((NODEPTR )) (VS1MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);
_AVliterals__const0=IDENTICAL(_AVliteral_len);
/*SPC(249)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_23(_TPPrule_23 _currn)
#else
void _VS2rule_23(_currn )
_TPPrule_23 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
(*(_CALL_VS_((NODEPTR )) (VS2MAP[_currn->_desc1->_prod])))((NODEPTR) _currn->_desc1);

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS1rule_22(_TPPrule_22 _currn)
#else
void _VS1rule_22(_currn )
_TPPrule_22 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVliteral_len=ADD(string_length(_currn->_ATTERM_1), strlen((* _IG_incl5)));
/*SPC(238)*/

_VisitExit();
}

#if defined(__STDC__) || defined(__cplusplus)
void _VS2rule_22(_TPPrule_22 _currn)
#else
void _VS2rule_22(_currn )
_TPPrule_22 _currn;

#endif
{

_VisitVarDecl()
_VisitEntry();
_AVparamnumopts_post=ADD(_AVparamnumopts_post, 1);
/*SPC(224)*/
_AVparamopts_post=PTGseq(_AVparamopts_post, PTGseq(PTGlit(_currn->_ATTERM_1), (* _IG_incl8)));
/*SPC(225)*/
_AVliteral_usage=PTGseq(
(((* _IG_incl4)
) ? (PTGvuse(_currn->_ATTERM_1, " ", (* _IG_incl5), (* _IG_incl0), (* _IG_incl6))
) : (PTGNULL))
, 
(((* _IG_incl7)
) ? (PTGvuse(_currn->_ATTERM_1, "", (* _IG_incl5), (* _IG_incl0), (* _IG_incl6))
) : (PTGNULL))
);
/*SPC(227)*/
_AVparamousages_post=PTGseq(_AVparamousages_post, _AVliteral_usage);
/*SPC(237)*/

_VisitExit();
}

