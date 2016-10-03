
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

typedef struct _TSparams* _TSPparams;
typedef struct _TSoptparams* _TSPoptparams;
typedef struct _TSoptattrs* _TSPoptattrs;
typedef struct _TSattrs* _TSPattrs;
typedef struct _TStranslation_sig* _TSPtranslation_sig;
typedef struct _TSiduse* _TSPiduse;
typedef struct _TSsig* _TSPsig;
typedef struct _TSattr* _TSPattr;
typedef struct _TSevent_block* _TSPevent_block;
typedef struct _TSexport* _TSPexport;
typedef struct _TSevent_sig* _TSPevent_sig;
typedef struct _TSsigs* _TSPsigs;
typedef struct _TSaspect_stmt* _TSPaspect_stmt;
typedef struct _TSaspects* _TSPaspects;
typedef struct _TSspec* _TSPspec;
typedef struct _TSparam* _TSPparam;
typedef struct _TStypeid* _TSPtypeid;
typedef struct _TSbody* _TSPbody;
typedef struct _TSoperation_block* _TSPoperation_block;
typedef struct _TSiddef* _TSPiddef;
typedef struct _TSoperation_sig* _TSPoperation_sig;
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
typedef struct _TPrule_31* _TPPrule_31;
typedef struct _TPrule_30* _TPPrule_30;
typedef struct _TPrule_29* _TPPrule_29;
typedef struct _TPrule_28* _TPPrule_28;
typedef struct _TPrule_27* _TPPrule_27;
typedef struct _TPrule_26* _TPPrule_26;
typedef struct _TPrule_25* _TPPrule_25;
typedef struct _TPrule_24* _TPPrule_24;
typedef struct _TPrule_23* _TPPrule_23;
typedef struct _TPrule_22* _TPPrule_22;
typedef struct _TPrule_21* _TPPrule_21;
typedef struct _TPrule_20* _TPPrule_20;
typedef struct _TPrule_19* _TPPrule_19;
typedef struct _TPrule_18* _TPPrule_18;
typedef struct _TPrule_17* _TPPrule_17;
typedef struct _TPrule_16* _TPPrule_16;
typedef struct _TPrule_15* _TPPrule_15;
typedef struct _TPrule_14* _TPPrule_14;
typedef struct _TPrule_13* _TPPrule_13;
typedef struct _TPrule_12* _TPPrule_12;
typedef struct _TPoperation_sig2* _TPPoperation_sig2;
typedef struct _TPoperation_sig1* _TPPoperation_sig1;

struct _TSparams
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSoptparams
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSoptattrs
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSattrs
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TStranslation_sig
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSiduse
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
};

struct _TSsig
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSattr
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSevent_block
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATsends_post;
PTGNode _ATansitypes_post;
PTGNode _ATtypes_post;
PTGNode _ATansiargs_post;
PTGNode _ATargs_post;
PTGNode _ATattrdbs_post;
Environment _ATExportEnv;
};

struct _TSexport
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATexported;
};

struct _TSevent_sig
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSsigs
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSaspect_stmt
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSaspects
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSspec
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATExportEnv;
Environment _ATTypeEnv;
};

struct _TSparam
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TStypeid
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TSbody
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATbodycode;
int _ATline;
};

struct _TSoperation_block
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATargs_post;
PTGNode _ATargvars_post;
int _ATargcount_post;
Environment _ATExportEnv;
};

struct _TSiddef
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
CharPtr _ATidcode;
};

struct _TSoperation_sig
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
_TSPiddef _desc1;
_TSPiduse _desc2;
_TSPbody _desc3;
};

struct _TPrule_2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtypeid _desc1;
_TSPiddef _desc2;
};

struct _TPrule_3
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATbodycode;
int _ATline;
int _ATTERM_1;
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
_TSPtypeid _desc1;
_TSPiddef _desc2;
int _ATTERM_1;
};

struct _TPrule_7
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATexported;
};

struct _TPrule_8
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATexported;
};

struct _TPrule_9
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPiddef _desc1;
_TSPexport _desc2;
_TSPevent_block _desc3;
int _ATTERM_1;
};

struct _TPrule_10
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPiddef _desc1;
_TSPsigs _desc2;
};

struct _TPrule_11
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
Environment _ATExportEnv;
Environment _ATTypeEnv;
_TSPaspects _desc1;
};

struct _TPrule_31
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATTERM_1;
};

struct _TPrule_30
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPtranslation_sig _desc1;
};

struct _TPrule_29
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPsigs _desc1;
_TSPsig _desc2;
};

struct _TPrule_28
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPsig _desc1;
};

struct _TPrule_27
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPoperation_sig _desc1;
};

struct _TPrule_26
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPevent_sig _desc1;
};

struct _TPrule_25
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPparams _desc1;
_TSPparam _desc2;
};

struct _TPrule_24
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPparam _desc1;
};

struct _TPrule_23
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPparams _desc1;
};

struct _TPrule_22
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_21
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattrs _desc1;
};

struct _TPrule_20
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
};

struct _TPrule_19
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATargs_post;
PTGNode _ATargvars_post;
int _ATargcount_post;
Environment _ATExportEnv;
_TSPoptparams _desc1;
};

struct _TPrule_18
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
DefTableKey _ATKey;
int _ATTERM_1;
};

struct _TPrule_17
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
int _ATSym;
DefTableKey _ATKey;
CharPtr _ATidcode;
};

struct _TPrule_16
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
PTGNode _ATsends_post;
PTGNode _ATansitypes_post;
PTGNode _ATtypes_post;
PTGNode _ATansiargs_post;
PTGNode _ATargs_post;
PTGNode _ATattrdbs_post;
Environment _ATExportEnv;
_TSPoptattrs _desc1;
};

struct _TPrule_15
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattrs _desc1;
_TSPattr _desc2;
};

struct _TPrule_14
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPattr _desc1;
};

struct _TPrule_13
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPaspect_stmt _desc1;
};

struct _TPrule_12
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPaspects _desc1;
_TSPaspect_stmt _desc2;
};

struct _TPoperation_sig2
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPiddef _desc1;
_TSPoperation_block _desc2;
_TSPtypeid _desc3;
_TSPbody _desc4;
POSITION _AT_pos;
};

struct _TPoperation_sig1
#ifdef __cplusplus
	: public NODEPTR_struct {
#else
{
_NODECOMMON
#endif
_TSPiddef _desc1;
_TSPoperation_block _desc2;
_TSPbody _desc3;
};

#undef _NODECOMMON
#endif
