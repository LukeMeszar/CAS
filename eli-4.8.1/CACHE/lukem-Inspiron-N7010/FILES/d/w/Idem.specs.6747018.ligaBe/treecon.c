
/* implementation of tree construction functions */

#include "node.h"

#include "nodecode.h"

#include "attrpredef.h"

#include "visitmap.h"

#include "treeact.h"

#ifdef MONITOR
#include "attr_mon_dapto.h"
#include "MONTblStack.h"
#endif

#include <stdlib.h>

#define _USE_OBSTACK 1

/* use of obstack: */

#if _USE_OBSTACK

#include "obstack.h"
static struct obstack TreeSpace;
static void *_TreeBase;

#ifdef __cplusplus
void* NODEPTR_struct::operator new(size_t size)
{
	return obstack_alloc(&TreeSpace, size);
}
#else
#if defined(__STDC__) || defined(__cplusplus)
char* TreeNodeAlloc(int size)
#else
char* TreeNodeAlloc(size) int size;
#endif
{
	return (char *)(obstack_alloc(&TreeSpace, size));
}
#endif

void InitTree()
{
	obstack_init(&TreeSpace);
	_TreeBase=obstack_alloc(&TreeSpace,0);
}

void FreeTree()
{
	obstack_free(&TreeSpace, _TreeBase);
	_TreeBase=obstack_alloc(&TreeSpace,0);
}

#else

#include <stdio.h>

#ifdef __cplusplus
void* NODEPTR_struct::operator new(size_t size)
{
	void *retval = malloc(size);
	if (retval) return retval;
	fprintf(stderr, "*** DEADLY: No more memory.\n");
	exit(1);
}
#else
#if defined(__STDC__) || defined(__cplusplus)
char* TreeNodeAlloc(int size)
#else
char* TreeNodeAlloc(size) int size;
#endif
{
	char *retval = (char *) malloc(size);
	if (retval) return retval;
	fprintf(stderr, "*** DEADLY: No more memory.\n");
	exit(1);
}
#endif

void InitTree() { }

void FreeTree() { }

#endif

#ifdef MONITOR
#define _SETCOORD(node) \
        node->_coord = _coordref ? *_coordref : NoCoord;
#define _COPYCOORD(node) \
        node->_coord = _currn->_desc1->_coord;
#else
#define _SETCOORD(node)
#define _COPYCOORD(node)
#endif
#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkPTGSpec (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkPTGSpec (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBPTGSpec)) return (_currn);
if (IsSymb (_currn, SYMBG2)) return (Mkrule_21(_coordref, _currn));
return(NULLNODEPTR);
}/* MkPTGSpec */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG2 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG2 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG2)) return (_currn);
return(NULLNODEPTR);
}/* MkG2 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxRoot (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxRoot (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxRoot)) return (_currn);
return(NULLNODEPTR);
}/* MkxRoot */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkItem (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkItem (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBItem)) return (_currn);
return(NULLNODEPTR);
}/* MkItem */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkItems (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkItems (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBItems)) return (_currn);
return(NULLNODEPTR);
}/* MkItems */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkPatternName (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkPatternName (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBPatternName)) return (_currn);
return(NULLNODEPTR);
}/* MkPatternName */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkPatternSpec (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkPatternSpec (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBPatternSpec)) return (_currn);
return(NULLNODEPTR);
}/* MkPatternSpec */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkElement (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkElement (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBElement)) return (_currn);
if (IsSymb (_currn, SYMBxSymbol)) return (Mkrule_13(_coordref, _currn));
return(NULLNODEPTR);
}/* MkElement */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSyms (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSyms (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSyms)) return (_currn);
return(NULLNODEPTR);
}/* MkSyms */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxRHS (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxRHS (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxRHS)) return (_currn);
return(NULLNODEPTR);
}/* MkxRHS */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxSymbol (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxSymbol (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxSymbol)) return (_currn);
return(NULLNODEPTR);
}/* MkxSymbol */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxRule (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxRule (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxRule)) return (_currn);
return(NULLNODEPTR);
}/* MkxRule */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxProduction (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxProduction (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxProduction)) return (_currn);
return(NULLNODEPTR);
}/* MkxProduction */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxGrammar (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxGrammar (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxGrammar)) return (_currn);
return(NULLNODEPTR);
}/* MkxGrammar */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_1 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_1 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_1 _currn;
#ifdef __cplusplus
_currn = new _TPrule_1;
#else
_currn = (_TPPrule_1) TreeNodeAlloc (sizeof (struct _TPrule_1));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_1;
_currn->_desc1 = (_TSPItems) MkItems (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_1: root of subtree no. 1 can not be made a Items node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_1;
return ( (NODEPTR) _currn);
}/* Mkrule_1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_2 (POSITION *_coordref, int _TERM1, NODEPTR _desc1)
#else
NODEPTR Mkrule_2 (_coordref, _TERM1,_desc1)
	POSITION *_coordref;
	int _TERM1;
	NODEPTR _desc1;
#endif
{	_TPPrule_2 _currn;
#ifdef __cplusplus
_currn = new _TPrule_2;
#else
_currn = (_TPPrule_2) TreeNodeAlloc (sizeof (struct _TPrule_2));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_2;
_currn->_desc1 = (_TSPItems) MkItems (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_2: root of subtree no. 1 can not be made a Items node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_2;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "xIdentifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_2 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_3 (POSITION *_coordref, int _TERM1, int _TERM2)
#else
NODEPTR Mkrule_3 (_coordref, _TERM1, _TERM2)
	POSITION *_coordref;
	int _TERM1;
	int _TERM2;
#endif
{	_TPPrule_3 _currn;
#ifdef __cplusplus
_currn = new _TPrule_3;
#else
_currn = (_TPPrule_3) TreeNodeAlloc (sizeof (struct _TPrule_3));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_3;
_SETCOORD(_currn)
_TERMACT_rule_3;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Number", _TERM1);
#endif

#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "PtgType", _TERM2);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_3 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_4 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_4 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_4 _currn;
#ifdef __cplusplus
_currn = new _TPrule_4;
#else
_currn = (_TPPrule_4) TreeNodeAlloc (sizeof (struct _TPrule_4));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_4;
_SETCOORD(_currn)
_TERMACT_rule_4;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "PtgType", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_4 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_5 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_5 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_5 _currn;
#ifdef __cplusplus
_currn = new _TPrule_5;
#else
_currn = (_TPPrule_5) TreeNodeAlloc (sizeof (struct _TPrule_5));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_5;
_SETCOORD(_currn)
_TERMACT_rule_5;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Number", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_5 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_6 (POSITION *_coordref)
#else
NODEPTR Mkrule_6 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_6 _currn;
#ifdef __cplusplus
_currn = new _TPrule_6;
#else
_currn = (_TPPrule_6) TreeNodeAlloc (sizeof (struct _TPrule_6));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_6;
_SETCOORD(_currn)
_TERMACT_rule_6;
return ( (NODEPTR) _currn);
}/* Mkrule_6 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_7 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_7 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_7 _currn;
#ifdef __cplusplus
_currn = new _TPrule_7;
#else
_currn = (_TPPrule_7) TreeNodeAlloc (sizeof (struct _TPrule_7));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_7;
_SETCOORD(_currn)
_TERMACT_rule_7;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "CString", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_7 */

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkItemrule_8 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkItemrule_8 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_Itemrule_8 _new;
#ifdef __cplusplus
	_new = new _TPLST_Itemrule_8;
#else
	_new = (_TPPLST_Itemrule_8) TreeNodeAlloc (sizeof (struct _TPLST_Itemrule_8));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_Itemrule_8;
	_new->_desc1 = (_TSPItem)elem;
	_new->_desc2 = (_TSPLST_Items)_new;
	{_TPPLST_Itemrule_8 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_Itemrule_8;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _Elemrule_8 (POSITION *_coordref, NODEPTR t)
#else
static NODEPTR _Elemrule_8 (_coordref, t)
	POSITION *_coordref; NODEPTR t;
#endif
/* coerces t to a list element and returns a single circular list */
{	NODEPTR elem;
	/* check first without then with coercion: */
	if (IsSymb (t, SYMBItem)) 
		return _MkItemrule_8 (_coordref, MkItem (_coordref, t));
	message (DEADLY, "a rule_8 list element node can not be generated ",
		0, _coordref);
	return t; /* never reached */
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mk2rule_8 (POSITION *_coordref, NODEPTR l, NODEPTR r)
#else
NODEPTR Mk2rule_8 (_coordref, l, r) POSITION *_coordref; NODEPTR l, r;
#endif
/* make a list of l and r, which may be null, elements, or lists */
{	NODEPTR last;
if (l == NULLNODEPTR) return r;
if (r == NULLNODEPTR) return l;
/* ensure l and r to be lists: */
if (LHSMAP[l->_prod] != SYMBLST_Items)
	l =_Elemrule_8 (_coordref, l);
if (LHSMAP[r->_prod] != SYMBLST_Items)
	r = _Elemrule_8 (_coordref, r);
/* concatenate two lists: */
last = ((NODEPTR)((_TPPLST_0rule_8)r)->_desc2);
((_TPPLST_0rule_8)r)->_desc2 = ((_TPPLST_0rule_8)l)->_desc2;
((_TPPLST_0rule_8)l)->_desc2 = last;
return l;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_8 (POSITION *_coordref, NODEPTR t)
#else
NODEPTR Mkrule_8 (_coordref, t) POSITION *_coordref; NODEPTR t;
#endif
{	NODEPTR _currn; _TPPrule_8 root;
	_TPPLST_0rule_8 list, remain, p;
/* argument t may be empty, a list element, or a list: */
if (t == NULLNODEPTR)
	remain = (_TPPLST_0rule_8)NULLNODEPTR;
else {	if (LHSMAP[t->_prod] != SYMBLST_Items)
		t = _Elemrule_8 (_coordref, t);
	remain = (_TPPLST_0rule_8)(((_TPPLST_0rule_8) t)->_desc2);
	((_TPPLST_0rule_8) t)->_desc2 = NULLNODEPTR;
}
/* remain is a possibly empty list in reverse order */
/* finalize the list by an empty context: */
#ifdef __cplusplus
list = new _TPLST_0rule_8;
#else
list = (_TPPLST_0rule_8) TreeNodeAlloc (sizeof (struct _TPLST_0rule_8));
#endif
#ifdef MONITOR
list->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)list));
#endif
list->_prod = RULELST_0rule_8;
list->_desc1 = NULLNODEPTR;
list->_desc2 = NULLNODEPTR;
_SETCOORD(list)
_currn = (NODEPTR)list;
/* reverse the list and visit its nodes: */
while (remain) {
	p = (_TPPLST_0rule_8)(remain->_desc2);
	remain->_desc2 = (NODEPTR)list;
	list = remain;
	remain = p;
	_currn = (NODEPTR)list;
	/*if (_currn->_prod == RULELST_Itemrule_8)
	{_TPPLST_Itemrule_8 _currn = _currn;
	 _TERMACT_LST_Itemrule_8;
	} this code has been moved to _Elemrule_8*/
}
/* make root node and visit it: */
#ifdef __cplusplus
root = new _TPrule_8;
#else
root = (_TPPrule_8) TreeNodeAlloc (sizeof (struct _TPrule_8));
#endif
#ifdef MONITOR
root->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)root));
#endif
root->_prod = RULErule_8;
root->_desc1 = (_TSPLST_Items)list;
{ _TPPrule_8 _currn = root;
  _SETCOORD(_currn)
  _TERMACT_rule_8;
}
_currn = (NODEPTR)root;
return (NODEPTR)_currn;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_9 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_9 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_9 _currn;
#ifdef __cplusplus
_currn = new _TPrule_9;
#else
_currn = (_TPPrule_9) TreeNodeAlloc (sizeof (struct _TPrule_9));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_9;
_SETCOORD(_currn)
_TERMACT_rule_9;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "xIdentifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_9 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_10 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_10 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_10 _currn;
#ifdef __cplusplus
_currn = new _TPrule_10;
#else
_currn = (_TPPrule_10) TreeNodeAlloc (sizeof (struct _TPrule_10));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_10;
_currn->_desc1 = (_TSPPatternName) MkPatternName (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 1 can not be made a PatternName node ", 0, _coordref);
_currn->_desc2 = (_TSPItems) MkItems (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 2 can not be made a Items node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_10;
return ( (NODEPTR) _currn);
}/* Mkrule_10 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_11 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_11 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_11 _currn;
#ifdef __cplusplus
_currn = new _TPrule_11;
#else
_currn = (_TPPrule_11) TreeNodeAlloc (sizeof (struct _TPrule_11));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_11;
_SETCOORD(_currn)
_TERMACT_rule_11;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "xLiteral", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_11 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_12 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_12 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_12 _currn;
#ifdef __cplusplus
_currn = new _TPrule_12;
#else
_currn = (_TPPrule_12) TreeNodeAlloc (sizeof (struct _TPrule_12));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_12;
_currn->_desc1 = (_TSPxSymbol) MkxSymbol (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_12: root of subtree no. 1 can not be made a xSymbol node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_12;
return ( (NODEPTR) _currn);
}/* Mkrule_12 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_13 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_13 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_13 _currn;
#ifdef __cplusplus
_currn = new _TPrule_13;
#else
_currn = (_TPPrule_13) TreeNodeAlloc (sizeof (struct _TPrule_13));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_13;
_currn->_desc1 = (_TSPxSymbol) MkxSymbol (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 1 can not be made a xSymbol node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_13;
return ( (NODEPTR) _currn);
}/* Mkrule_13 */

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkxSymbolrule_14 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkxSymbolrule_14 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_xSymbolrule_14 _new;
#ifdef __cplusplus
	_new = new _TPLST_xSymbolrule_14;
#else
	_new = (_TPPLST_xSymbolrule_14) TreeNodeAlloc (sizeof (struct _TPLST_xSymbolrule_14));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_xSymbolrule_14;
	_new->_desc1 = (_TSPxSymbol)elem;
	_new->_desc2 = (_TSPLST_Syms)_new;
	{_TPPLST_xSymbolrule_14 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_xSymbolrule_14;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _Elemrule_14 (POSITION *_coordref, NODEPTR t)
#else
static NODEPTR _Elemrule_14 (_coordref, t)
	POSITION *_coordref; NODEPTR t;
#endif
/* coerces t to a list element and returns a single circular list */
{	NODEPTR elem;
	/* check first without then with coercion: */
	if (IsSymb (t, SYMBxSymbol)) 
		return _MkxSymbolrule_14 (_coordref, MkxSymbol (_coordref, t));
	message (DEADLY, "a rule_14 list element node can not be generated ",
		0, _coordref);
	return t; /* never reached */
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mk2rule_14 (POSITION *_coordref, NODEPTR l, NODEPTR r)
#else
NODEPTR Mk2rule_14 (_coordref, l, r) POSITION *_coordref; NODEPTR l, r;
#endif
/* make a list of l and r, which may be null, elements, or lists */
{	NODEPTR last;
if (l == NULLNODEPTR) return r;
if (r == NULLNODEPTR) return l;
/* ensure l and r to be lists: */
if (LHSMAP[l->_prod] != SYMBLST_Syms)
	l =_Elemrule_14 (_coordref, l);
if (LHSMAP[r->_prod] != SYMBLST_Syms)
	r = _Elemrule_14 (_coordref, r);
/* concatenate two lists: */
last = ((NODEPTR)((_TPPLST_0rule_14)r)->_desc2);
((_TPPLST_0rule_14)r)->_desc2 = ((_TPPLST_0rule_14)l)->_desc2;
((_TPPLST_0rule_14)l)->_desc2 = last;
return l;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_14 (POSITION *_coordref, NODEPTR t)
#else
NODEPTR Mkrule_14 (_coordref, t) POSITION *_coordref; NODEPTR t;
#endif
{	NODEPTR _currn; _TPPrule_14 root;
	_TPPLST_0rule_14 list, remain, p;
/* argument t may be empty, a list element, or a list: */
if (t == NULLNODEPTR)
	remain = (_TPPLST_0rule_14)NULLNODEPTR;
else {	if (LHSMAP[t->_prod] != SYMBLST_Syms)
		t = _Elemrule_14 (_coordref, t);
	remain = (_TPPLST_0rule_14)(((_TPPLST_0rule_14) t)->_desc2);
	((_TPPLST_0rule_14) t)->_desc2 = NULLNODEPTR;
}
/* remain is a possibly empty list in reverse order */
/* finalize the list by an empty context: */
#ifdef __cplusplus
list = new _TPLST_0rule_14;
#else
list = (_TPPLST_0rule_14) TreeNodeAlloc (sizeof (struct _TPLST_0rule_14));
#endif
#ifdef MONITOR
list->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)list));
#endif
list->_prod = RULELST_0rule_14;
list->_desc1 = NULLNODEPTR;
list->_desc2 = NULLNODEPTR;
_SETCOORD(list)
_currn = (NODEPTR)list;
/* reverse the list and visit its nodes: */
while (remain) {
	p = (_TPPLST_0rule_14)(remain->_desc2);
	remain->_desc2 = (NODEPTR)list;
	list = remain;
	remain = p;
	_currn = (NODEPTR)list;
	/*if (_currn->_prod == RULELST_xSymbolrule_14)
	{_TPPLST_xSymbolrule_14 _currn = _currn;
	 _TERMACT_LST_xSymbolrule_14;
	} this code has been moved to _Elemrule_14*/
}
/* make root node and visit it: */
#ifdef __cplusplus
root = new _TPrule_14;
#else
root = (_TPPrule_14) TreeNodeAlloc (sizeof (struct _TPrule_14));
#endif
#ifdef MONITOR
root->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)root));
#endif
root->_prod = RULErule_14;
root->_desc1 = (_TSPLST_Syms)list;
{ _TPPrule_14 _currn = root;
  _SETCOORD(_currn)
  _TERMACT_rule_14;
}
_currn = (NODEPTR)root;
return (NODEPTR)_currn;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkElementrule_15 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkElementrule_15 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_Elementrule_15 _new;
#ifdef __cplusplus
	_new = new _TPLST_Elementrule_15;
#else
	_new = (_TPPLST_Elementrule_15) TreeNodeAlloc (sizeof (struct _TPLST_Elementrule_15));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_Elementrule_15;
	_new->_desc1 = (_TSPElement)elem;
	_new->_desc2 = (_TSPLST_xRHS)_new;
	{_TPPLST_Elementrule_15 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_Elementrule_15;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _Elemrule_15 (POSITION *_coordref, NODEPTR t)
#else
static NODEPTR _Elemrule_15 (_coordref, t)
	POSITION *_coordref; NODEPTR t;
#endif
/* coerces t to a list element and returns a single circular list */
{	NODEPTR elem;
	/* check first without then with coercion: */
	if (IsSymb (t, SYMBxSymbol)) 
		return _MkElementrule_15 (_coordref, MkElement (_coordref, t));
	if (IsSymb (t, SYMBElement)) 
		return _MkElementrule_15 (_coordref, MkElement (_coordref, t));
	message (DEADLY, "a rule_15 list element node can not be generated ",
		0, _coordref);
	return t; /* never reached */
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mk2rule_15 (POSITION *_coordref, NODEPTR l, NODEPTR r)
#else
NODEPTR Mk2rule_15 (_coordref, l, r) POSITION *_coordref; NODEPTR l, r;
#endif
/* make a list of l and r, which may be null, elements, or lists */
{	NODEPTR last;
if (l == NULLNODEPTR) return r;
if (r == NULLNODEPTR) return l;
/* ensure l and r to be lists: */
if (LHSMAP[l->_prod] != SYMBLST_xRHS)
	l =_Elemrule_15 (_coordref, l);
if (LHSMAP[r->_prod] != SYMBLST_xRHS)
	r = _Elemrule_15 (_coordref, r);
/* concatenate two lists: */
last = ((NODEPTR)((_TPPLST_0rule_15)r)->_desc2);
((_TPPLST_0rule_15)r)->_desc2 = ((_TPPLST_0rule_15)l)->_desc2;
((_TPPLST_0rule_15)l)->_desc2 = last;
return l;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_15 (POSITION *_coordref, NODEPTR t)
#else
NODEPTR Mkrule_15 (_coordref, t) POSITION *_coordref; NODEPTR t;
#endif
{	NODEPTR _currn; _TPPrule_15 root;
	_TPPLST_0rule_15 list, remain, p;
/* argument t may be empty, a list element, or a list: */
if (t == NULLNODEPTR)
	remain = (_TPPLST_0rule_15)NULLNODEPTR;
else {	if (LHSMAP[t->_prod] != SYMBLST_xRHS)
		t = _Elemrule_15 (_coordref, t);
	remain = (_TPPLST_0rule_15)(((_TPPLST_0rule_15) t)->_desc2);
	((_TPPLST_0rule_15) t)->_desc2 = NULLNODEPTR;
}
/* remain is a possibly empty list in reverse order */
/* finalize the list by an empty context: */
#ifdef __cplusplus
list = new _TPLST_0rule_15;
#else
list = (_TPPLST_0rule_15) TreeNodeAlloc (sizeof (struct _TPLST_0rule_15));
#endif
#ifdef MONITOR
list->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)list));
#endif
list->_prod = RULELST_0rule_15;
list->_desc1 = NULLNODEPTR;
list->_desc2 = NULLNODEPTR;
_SETCOORD(list)
_currn = (NODEPTR)list;
/* reverse the list and visit its nodes: */
while (remain) {
	p = (_TPPLST_0rule_15)(remain->_desc2);
	remain->_desc2 = (NODEPTR)list;
	list = remain;
	remain = p;
	_currn = (NODEPTR)list;
	/*if (_currn->_prod == RULELST_Elementrule_15)
	{_TPPLST_Elementrule_15 _currn = _currn;
	 _TERMACT_LST_Elementrule_15;
	} this code has been moved to _Elemrule_15*/
}
/* make root node and visit it: */
#ifdef __cplusplus
root = new _TPrule_15;
#else
root = (_TPPrule_15) TreeNodeAlloc (sizeof (struct _TPrule_15));
#endif
#ifdef MONITOR
root->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)root));
#endif
root->_prod = RULErule_15;
root->_desc1 = (_TSPLST_xRHS)list;
{ _TPPrule_15 _currn = root;
  _SETCOORD(_currn)
  _TERMACT_rule_15;
}
_currn = (NODEPTR)root;
return (NODEPTR)_currn;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_16 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_16 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_16 _currn;
#ifdef __cplusplus
_currn = new _TPrule_16;
#else
_currn = (_TPPrule_16) TreeNodeAlloc (sizeof (struct _TPrule_16));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_16;
_currn->_desc1 = (_TSPxRule) MkxRule (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_16: root of subtree no. 1 can not be made a xRule node ", 0, _coordref);
_currn->_desc2 = (_TSPxSymbol) MkxSymbol (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_16: root of subtree no. 2 can not be made a xSymbol node ", 0, _coordref);
_currn->_desc3 = (_TSPSyms) MkSyms (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_16: root of subtree no. 3 can not be made a Syms node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_16;
return ( (NODEPTR) _currn);
}/* Mkrule_16 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_17 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_17 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPrule_17 _currn;
#ifdef __cplusplus
_currn = new _TPrule_17;
#else
_currn = (_TPPrule_17) TreeNodeAlloc (sizeof (struct _TPrule_17));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_17;
_currn->_desc1 = (_TSPxRule) MkxRule (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 1 can not be made a xRule node ", 0, _coordref);
_currn->_desc2 = (_TSPxSymbol) MkxSymbol (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 2 can not be made a xSymbol node ", 0, _coordref);
_currn->_desc3 = (_TSPxRHS) MkxRHS (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 3 can not be made a xRHS node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_17;
return ( (NODEPTR) _currn);
}/* Mkrule_17 */

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkxProductionrule_18 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkxProductionrule_18 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_xProductionrule_18 _new;
#ifdef __cplusplus
	_new = new _TPLST_xProductionrule_18;
#else
	_new = (_TPPLST_xProductionrule_18) TreeNodeAlloc (sizeof (struct _TPLST_xProductionrule_18));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_xProductionrule_18;
	_new->_desc1 = (_TSPxProduction)elem;
	_new->_desc2 = (_TSPLST_xGrammar)_new;
	{_TPPLST_xProductionrule_18 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_xProductionrule_18;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _Elemrule_18 (POSITION *_coordref, NODEPTR t)
#else
static NODEPTR _Elemrule_18 (_coordref, t)
	POSITION *_coordref; NODEPTR t;
#endif
/* coerces t to a list element and returns a single circular list */
{	NODEPTR elem;
	/* check first without then with coercion: */
	if (IsSymb (t, SYMBxProduction)) 
		return _MkxProductionrule_18 (_coordref, MkxProduction (_coordref, t));
	message (DEADLY, "a rule_18 list element node can not be generated ",
		0, _coordref);
	return t; /* never reached */
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mk2rule_18 (POSITION *_coordref, NODEPTR l, NODEPTR r)
#else
NODEPTR Mk2rule_18 (_coordref, l, r) POSITION *_coordref; NODEPTR l, r;
#endif
/* make a list of l and r, which may be null, elements, or lists */
{	NODEPTR last;
if (l == NULLNODEPTR) return r;
if (r == NULLNODEPTR) return l;
/* ensure l and r to be lists: */
if (LHSMAP[l->_prod] != SYMBLST_xGrammar)
	l =_Elemrule_18 (_coordref, l);
if (LHSMAP[r->_prod] != SYMBLST_xGrammar)
	r = _Elemrule_18 (_coordref, r);
/* concatenate two lists: */
last = ((NODEPTR)((_TPPLST_0rule_18)r)->_desc2);
((_TPPLST_0rule_18)r)->_desc2 = ((_TPPLST_0rule_18)l)->_desc2;
((_TPPLST_0rule_18)l)->_desc2 = last;
return l;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_18 (POSITION *_coordref, NODEPTR t)
#else
NODEPTR Mkrule_18 (_coordref, t) POSITION *_coordref; NODEPTR t;
#endif
{	NODEPTR _currn; _TPPrule_18 root;
	_TPPLST_0rule_18 list, remain, p;
/* argument t may be empty, a list element, or a list: */
if (t == NULLNODEPTR)
	remain = (_TPPLST_0rule_18)NULLNODEPTR;
else {	if (LHSMAP[t->_prod] != SYMBLST_xGrammar)
		t = _Elemrule_18 (_coordref, t);
	remain = (_TPPLST_0rule_18)(((_TPPLST_0rule_18) t)->_desc2);
	((_TPPLST_0rule_18) t)->_desc2 = NULLNODEPTR;
}
/* remain is a possibly empty list in reverse order */
/* finalize the list by an empty context: */
#ifdef __cplusplus
list = new _TPLST_0rule_18;
#else
list = (_TPPLST_0rule_18) TreeNodeAlloc (sizeof (struct _TPLST_0rule_18));
#endif
#ifdef MONITOR
list->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)list));
#endif
list->_prod = RULELST_0rule_18;
list->_desc1 = NULLNODEPTR;
list->_desc2 = NULLNODEPTR;
_SETCOORD(list)
_currn = (NODEPTR)list;
/* reverse the list and visit its nodes: */
while (remain) {
	p = (_TPPLST_0rule_18)(remain->_desc2);
	remain->_desc2 = (NODEPTR)list;
	list = remain;
	remain = p;
	_currn = (NODEPTR)list;
	/*if (_currn->_prod == RULELST_xProductionrule_18)
	{_TPPLST_xProductionrule_18 _currn = _currn;
	 _TERMACT_LST_xProductionrule_18;
	} this code has been moved to _Elemrule_18*/
}
/* make root node and visit it: */
#ifdef __cplusplus
root = new _TPrule_18;
#else
root = (_TPPrule_18) TreeNodeAlloc (sizeof (struct _TPrule_18));
#endif
#ifdef MONITOR
root->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)root));
#endif
root->_prod = RULErule_18;
root->_desc1 = (_TSPLST_xGrammar)list;
{ _TPPrule_18 _currn = root;
  _SETCOORD(_currn)
  _TERMACT_rule_18;
}
_currn = (NODEPTR)root;
return (NODEPTR)_currn;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_26 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_26 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_26 _currn;
#ifdef __cplusplus
_currn = new _TPrule_26;
#else
_currn = (_TPPrule_26) TreeNodeAlloc (sizeof (struct _TPrule_26));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_26;
_SETCOORD(_currn)
_TERMACT_rule_26;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "xIdentifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_26 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_25 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_25 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_25 _currn;
#ifdef __cplusplus
_currn = new _TPrule_25;
#else
_currn = (_TPPrule_25) TreeNodeAlloc (sizeof (struct _TPrule_25));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_25;
_SETCOORD(_currn)
_TERMACT_rule_25;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "PtgType", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_25 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_24 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_24 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_24 _currn;
#ifdef __cplusplus
_currn = new _TPrule_24;
#else
_currn = (_TPPrule_24) TreeNodeAlloc (sizeof (struct _TPrule_24));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_24;
_SETCOORD(_currn)
_TERMACT_rule_24;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "xIdentifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_24 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_23 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_23 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_23 _currn;
#ifdef __cplusplus
_currn = new _TPrule_23;
#else
_currn = (_TPPrule_23) TreeNodeAlloc (sizeof (struct _TPrule_23));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_23;
_SETCOORD(_currn)
_TERMACT_rule_23;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "PtgType", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_23 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_22 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_22 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_22 _currn;
#ifdef __cplusplus
_currn = new _TPrule_22;
#else
_currn = (_TPPrule_22) TreeNodeAlloc (sizeof (struct _TPrule_22));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_22;
_currn->_desc1 = (_TSPxGrammar) MkxGrammar (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_22: root of subtree no. 1 can not be made a xGrammar node ", 0, _coordref);
_currn->_desc2 = (_TSPPTGSpec) MkPTGSpec (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_22: root of subtree no. 2 can not be made a PTGSpec node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_22;
return ( (NODEPTR) _currn);
}/* Mkrule_22 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_21 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_21 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_21 _currn;
#ifdef __cplusplus
_currn = new _TPrule_21;
#else
_currn = (_TPPrule_21) TreeNodeAlloc (sizeof (struct _TPrule_21));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_21;
_currn->_desc1 = (_TSPG2) MkG2 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_21: root of subtree no. 1 can not be made a G2 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_21;
return ( (NODEPTR) _currn);
}/* Mkrule_21 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_20 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_20 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_20 _currn;
#ifdef __cplusplus
_currn = new _TPrule_20;
#else
_currn = (_TPPrule_20) TreeNodeAlloc (sizeof (struct _TPrule_20));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_20;
_currn->_desc1 = (_TSPG2) MkG2 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_20: root of subtree no. 1 can not be made a G2 node ", 0, _coordref);
_currn->_desc2 = (_TSPPatternSpec) MkPatternSpec (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_20: root of subtree no. 2 can not be made a PatternSpec node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_20;
return ( (NODEPTR) _currn);
}/* Mkrule_20 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_19 (POSITION *_coordref)
#else
NODEPTR Mkrule_19 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_19 _currn;
#ifdef __cplusplus
_currn = new _TPrule_19;
#else
_currn = (_TPPrule_19) TreeNodeAlloc (sizeof (struct _TPrule_19));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_19;
_SETCOORD(_currn)
_TERMACT_rule_19;
return ( (NODEPTR) _currn);
}/* Mkrule_19 */
