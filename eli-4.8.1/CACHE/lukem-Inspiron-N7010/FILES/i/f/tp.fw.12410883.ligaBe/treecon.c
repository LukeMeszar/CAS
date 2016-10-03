
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
NODEPTR MkChildren (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkChildren (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBChildren)) return (_currn);
if (IsSymb (_currn, SYMBSymbolUse)) return (Mkrule_8(_coordref, _currn));
if (IsSymb (_currn, SYMBChild)) return (Mkrule_8(_coordref, _currn));
return(NULLNODEPTR);
}/* MkChildren */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkTerminal (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkTerminal (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBTerminal)) return (_currn);
return(NULLNODEPTR);
}/* MkTerminal */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkFunction (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkFunction (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBFunction)) return (_currn);
return(NULLNODEPTR);
}/* MkFunction */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkChild (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkChild (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBChild)) return (_currn);
if (IsSymb (_currn, SYMBSymbolUse)) return (Mkrule_12(_coordref, _currn));
return(NULLNODEPTR);
}/* MkChild */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSymbolUse (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSymbolUse (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSymbolUse)) return (_currn);
return(NULLNODEPTR);
}/* MkSymbolUse */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkCost (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkCost (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBCost)) return (_currn);
return(NULLNODEPTR);
}/* MkCost */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSignature (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSignature (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSignature)) return (_currn);
return(NULLNODEPTR);
}/* MkSignature */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSymbolDef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSymbolDef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSymbolDef)) return (_currn);
return(NULLNODEPTR);
}/* MkSymbolDef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkType (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkType (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBType)) return (_currn);
return(NULLNODEPTR);
}/* MkType */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkNonterms (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkNonterms (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBNonterms)) return (_currn);
return(NULLNODEPTR);
}/* MkNonterms */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkPattern (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkPattern (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBPattern)) return (_currn);
return(NULLNODEPTR);
}/* MkPattern */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkDeclaration (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkDeclaration (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBDeclaration)) return (_currn);
return(NULLNODEPTR);
}/* MkDeclaration */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkInclude (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkInclude (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBInclude)) return (_currn);
return(NULLNODEPTR);
}/* MkInclude */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSource (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSource (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSource)) return (_currn);
return(NULLNODEPTR);
}/* MkSource */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_1 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_1 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
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
_SETCOORD(_currn)
_TERMACT_rule_1;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_2 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_2 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
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
_SETCOORD(_currn)
_TERMACT_rule_2;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_2 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_3 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_3 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
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
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
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
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
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
_dapto_term_int((_currn)->_uid, "Integer", _TERM1);
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
NODEPTR Mkrule_7 (POSITION *_coordref)
#else
NODEPTR Mkrule_7 (_coordref)
	POSITION *_coordref;
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
return ( (NODEPTR) _currn);
}/* Mkrule_7 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_8 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_8 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_8 _currn;
#ifdef __cplusplus
_currn = new _TPrule_8;
#else
_currn = (_TPPrule_8) TreeNodeAlloc (sizeof (struct _TPrule_8));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_8;
_currn->_desc1 = (_TSPChild) MkChild (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_8: root of subtree no. 1 can not be made a Child node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_8;
return ( (NODEPTR) _currn);
}/* Mkrule_8 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_9 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_9 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPChildren) MkChildren (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_9: root of subtree no. 1 can not be made a Children node ", 0, _coordref);
_currn->_desc2 = (_TSPChild) MkChild (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_9: root of subtree no. 2 can not be made a Child node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_9;
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
_currn->_desc1 = (_TSPTerminal) MkTerminal (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 1 can not be made a Terminal node ", 0, _coordref);
_currn->_desc2 = (_TSPChildren) MkChildren (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 2 can not be made a Children node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_10;
return ( (NODEPTR) _currn);
}/* Mkrule_10 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_11 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_11 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPTerminal) MkTerminal (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_11: root of subtree no. 1 can not be made a Terminal node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_11;
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
_currn->_desc1 = (_TSPSymbolUse) MkSymbolUse (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_12: root of subtree no. 1 can not be made a SymbolUse node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_12;
return ( (NODEPTR) _currn);
}/* Mkrule_12 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_13 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_13 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
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
_currn->_desc1 = (_TSPSymbolUse) MkSymbolUse (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 1 can not be made a SymbolUse node ", 0, _coordref);
_currn->_desc2 = (_TSPChild) MkChild (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 2 can not be made a Child node ", 0, _coordref);
_currn->_desc3 = (_TSPFunction) MkFunction (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 3 can not be made a Function node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_13;
return ( (NODEPTR) _currn);
}/* Mkrule_13 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_14 (POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2)
#else
NODEPTR Mkrule_14 (_coordref,_desc1, _TERM1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	int _TERM1;
	NODEPTR _desc2;
#endif
{	_TPPrule_14 _currn;
#ifdef __cplusplus
_currn = new _TPrule_14;
#else
_currn = (_TPPrule_14) TreeNodeAlloc (sizeof (struct _TPrule_14));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_14;
_currn->_desc1 = (_TSPSignature) MkSignature (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_14: root of subtree no. 1 can not be made a Signature node ", 0, _coordref);
_currn->_desc2 = (_TSPCost) MkCost (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_14: root of subtree no. 2 can not be made a Cost node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_14;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_14 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_15 (POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2)
#else
NODEPTR Mkrule_15 (_coordref,_desc1, _TERM1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	int _TERM1;
	NODEPTR _desc2;
#endif
{	_TPPrule_15 _currn;
#ifdef __cplusplus
_currn = new _TPrule_15;
#else
_currn = (_TPPrule_15) TreeNodeAlloc (sizeof (struct _TPrule_15));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_15;
_currn->_desc1 = (_TSPSignature) MkSignature (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_15: root of subtree no. 1 can not be made a Signature node ", 0, _coordref);
_currn->_desc2 = (_TSPCost) MkCost (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_15: root of subtree no. 2 can not be made a Cost node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_15;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_15 */

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkSymbolDefrule_16 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkSymbolDefrule_16 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_SymbolDefrule_16 _new;
#ifdef __cplusplus
	_new = new _TPLST_SymbolDefrule_16;
#else
	_new = (_TPPLST_SymbolDefrule_16) TreeNodeAlloc (sizeof (struct _TPLST_SymbolDefrule_16));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_SymbolDefrule_16;
	_new->_desc1 = (_TSPSymbolDef)elem;
	_new->_desc2 = (_TSPLST_Nonterms)_new;
	{_TPPLST_SymbolDefrule_16 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_SymbolDefrule_16;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _Elemrule_16 (POSITION *_coordref, NODEPTR t)
#else
static NODEPTR _Elemrule_16 (_coordref, t)
	POSITION *_coordref; NODEPTR t;
#endif
/* coerces t to a list element and returns a single circular list */
{	NODEPTR elem;
	/* check first without then with coercion: */
	if (IsSymb (t, SYMBSymbolDef)) 
		return _MkSymbolDefrule_16 (_coordref, MkSymbolDef (_coordref, t));
	message (DEADLY, "a rule_16 list element node can not be generated ",
		0, _coordref);
	return t; /* never reached */
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mk2rule_16 (POSITION *_coordref, NODEPTR l, NODEPTR r)
#else
NODEPTR Mk2rule_16 (_coordref, l, r) POSITION *_coordref; NODEPTR l, r;
#endif
/* make a list of l and r, which may be null, elements, or lists */
{	NODEPTR last;
if (l == NULLNODEPTR) return r;
if (r == NULLNODEPTR) return l;
/* ensure l and r to be lists: */
if (LHSMAP[l->_prod] != SYMBLST_Nonterms)
	l =_Elemrule_16 (_coordref, l);
if (LHSMAP[r->_prod] != SYMBLST_Nonterms)
	r = _Elemrule_16 (_coordref, r);
/* concatenate two lists: */
last = ((NODEPTR)((_TPPLST_0rule_16)r)->_desc2);
((_TPPLST_0rule_16)r)->_desc2 = ((_TPPLST_0rule_16)l)->_desc2;
((_TPPLST_0rule_16)l)->_desc2 = last;
return l;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_16 (POSITION *_coordref, NODEPTR t)
#else
NODEPTR Mkrule_16 (_coordref, t) POSITION *_coordref; NODEPTR t;
#endif
{	NODEPTR _currn; _TPPrule_16 root;
	_TPPLST_0rule_16 list, remain, p;
/* argument t may be empty, a list element, or a list: */
if (t == NULLNODEPTR)
	remain = (_TPPLST_0rule_16)NULLNODEPTR;
else {	if (LHSMAP[t->_prod] != SYMBLST_Nonterms)
		t = _Elemrule_16 (_coordref, t);
	remain = (_TPPLST_0rule_16)(((_TPPLST_0rule_16) t)->_desc2);
	((_TPPLST_0rule_16) t)->_desc2 = NULLNODEPTR;
}
/* remain is a possibly empty list in reverse order */
/* finalize the list by an empty context: */
#ifdef __cplusplus
list = new _TPLST_0rule_16;
#else
list = (_TPPLST_0rule_16) TreeNodeAlloc (sizeof (struct _TPLST_0rule_16));
#endif
#ifdef MONITOR
list->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)list));
#endif
list->_prod = RULELST_0rule_16;
list->_desc1 = NULLNODEPTR;
list->_desc2 = NULLNODEPTR;
_SETCOORD(list)
_currn = (NODEPTR)list;
/* reverse the list and visit its nodes: */
while (remain) {
	p = (_TPPLST_0rule_16)(remain->_desc2);
	remain->_desc2 = (NODEPTR)list;
	list = remain;
	remain = p;
	_currn = (NODEPTR)list;
	/*if (_currn->_prod == RULELST_SymbolDefrule_16)
	{_TPPLST_SymbolDefrule_16 _currn = _currn;
	 _TERMACT_LST_SymbolDefrule_16;
	} this code has been moved to _Elemrule_16*/
}
/* make root node and visit it: */
#ifdef __cplusplus
root = new _TPrule_16;
#else
root = (_TPPrule_16) TreeNodeAlloc (sizeof (struct _TPrule_16));
#endif
#ifdef MONITOR
root->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)root));
#endif
root->_prod = RULErule_16;
root->_desc1 = (_TSPLST_Nonterms)list;
{ _TPPrule_16 _currn = root;
  _SETCOORD(_currn)
  _TERMACT_rule_16;
}
_currn = (NODEPTR)root;
return (NODEPTR)_currn;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_17 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_17 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPNonterms) MkNonterms (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 1 can not be made a Nonterms node ", 0, _coordref);
_currn->_desc2 = (_TSPType) MkType (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 2 can not be made a Type node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_17;
return ( (NODEPTR) _currn);
}/* Mkrule_17 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_18 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_18 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_18 _currn;
#ifdef __cplusplus
_currn = new _TPrule_18;
#else
_currn = (_TPPrule_18) TreeNodeAlloc (sizeof (struct _TPrule_18));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_18;
_SETCOORD(_currn)
_TERMACT_rule_18;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "String", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_18 */

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkIncluderule_19 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkIncluderule_19 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_Includerule_19 _new;
#ifdef __cplusplus
	_new = new _TPLST_Includerule_19;
#else
	_new = (_TPPLST_Includerule_19) TreeNodeAlloc (sizeof (struct _TPLST_Includerule_19));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_Includerule_19;
	_new->_desc1 = (_TSPInclude)elem;
	_new->_desc2 = (_TSPLST_Source)_new;
	{_TPPLST_Includerule_19 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_Includerule_19;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkDeclarationrule_19 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkDeclarationrule_19 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_Declarationrule_19 _new;
#ifdef __cplusplus
	_new = new _TPLST_Declarationrule_19;
#else
	_new = (_TPPLST_Declarationrule_19) TreeNodeAlloc (sizeof (struct _TPLST_Declarationrule_19));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_Declarationrule_19;
	_new->_desc1 = (_TSPDeclaration)elem;
	_new->_desc2 = (_TSPLST_Source)_new;
	{_TPPLST_Declarationrule_19 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_Declarationrule_19;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _MkPatternrule_19 (POSITION *_coordref, NODEPTR elem)
#else
static NODEPTR _MkPatternrule_19 (_coordref, elem)
	POSITION *_coordref; NODEPTR elem;
#endif
{
	_TPPLST_Patternrule_19 _new;
#ifdef __cplusplus
	_new = new _TPLST_Patternrule_19;
#else
	_new = (_TPPLST_Patternrule_19) TreeNodeAlloc (sizeof (struct _TPLST_Patternrule_19));
#endif
#ifdef MONITOR
_new->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_new));
#endif
	_new->_prod = RULELST_Patternrule_19;
	_new->_desc1 = (_TSPPattern)elem;
	_new->_desc2 = (_TSPLST_Source)_new;
	{_TPPLST_Patternrule_19 _currn = _new;
	 _SETCOORD(_currn)
	 _TERMACT_LST_Patternrule_19;
	}
	return (NODEPTR)_new;
}

#if defined(__STDC__) || defined(__cplusplus)
static NODEPTR _Elemrule_19 (POSITION *_coordref, NODEPTR t)
#else
static NODEPTR _Elemrule_19 (_coordref, t)
	POSITION *_coordref; NODEPTR t;
#endif
/* coerces t to a list element and returns a single circular list */
{	NODEPTR elem;
	/* check first without then with coercion: */
	if (IsSymb (t, SYMBInclude)) 
		return _MkIncluderule_19 (_coordref, MkInclude (_coordref, t));
	if (IsSymb (t, SYMBDeclaration)) 
		return _MkDeclarationrule_19 (_coordref, MkDeclaration (_coordref, t));
	if (IsSymb (t, SYMBPattern)) 
		return _MkPatternrule_19 (_coordref, MkPattern (_coordref, t));
	message (DEADLY, "a rule_19 list element node can not be generated ",
		0, _coordref);
	return t; /* never reached */
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mk2rule_19 (POSITION *_coordref, NODEPTR l, NODEPTR r)
#else
NODEPTR Mk2rule_19 (_coordref, l, r) POSITION *_coordref; NODEPTR l, r;
#endif
/* make a list of l and r, which may be null, elements, or lists */
{	NODEPTR last;
if (l == NULLNODEPTR) return r;
if (r == NULLNODEPTR) return l;
/* ensure l and r to be lists: */
if (LHSMAP[l->_prod] != SYMBLST_Source)
	l =_Elemrule_19 (_coordref, l);
if (LHSMAP[r->_prod] != SYMBLST_Source)
	r = _Elemrule_19 (_coordref, r);
/* concatenate two lists: */
last = ((NODEPTR)((_TPPLST_0rule_19)r)->_desc2);
((_TPPLST_0rule_19)r)->_desc2 = ((_TPPLST_0rule_19)l)->_desc2;
((_TPPLST_0rule_19)l)->_desc2 = last;
return l;
}

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_19 (POSITION *_coordref, NODEPTR t)
#else
NODEPTR Mkrule_19 (_coordref, t) POSITION *_coordref; NODEPTR t;
#endif
{	NODEPTR _currn; _TPPrule_19 root;
	_TPPLST_0rule_19 list, remain, p;
/* argument t may be empty, a list element, or a list: */
if (t == NULLNODEPTR)
	remain = (_TPPLST_0rule_19)NULLNODEPTR;
else {	if (LHSMAP[t->_prod] != SYMBLST_Source)
		t = _Elemrule_19 (_coordref, t);
	remain = (_TPPLST_0rule_19)(((_TPPLST_0rule_19) t)->_desc2);
	((_TPPLST_0rule_19) t)->_desc2 = NULLNODEPTR;
}
/* remain is a possibly empty list in reverse order */
/* finalize the list by an empty context: */
#ifdef __cplusplus
list = new _TPLST_0rule_19;
#else
list = (_TPPLST_0rule_19) TreeNodeAlloc (sizeof (struct _TPLST_0rule_19));
#endif
#ifdef MONITOR
list->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)list));
#endif
list->_prod = RULELST_0rule_19;
list->_desc1 = NULLNODEPTR;
list->_desc2 = NULLNODEPTR;
_SETCOORD(list)
_currn = (NODEPTR)list;
/* reverse the list and visit its nodes: */
while (remain) {
	p = (_TPPLST_0rule_19)(remain->_desc2);
	remain->_desc2 = (NODEPTR)list;
	list = remain;
	remain = p;
	_currn = (NODEPTR)list;
	/*if (_currn->_prod == RULELST_Includerule_19)
	{_TPPLST_Includerule_19 _currn = _currn;
	 _TERMACT_LST_Includerule_19;
	} this code has been moved to _Elemrule_19*/
	/*if (_currn->_prod == RULELST_Declarationrule_19)
	{_TPPLST_Declarationrule_19 _currn = _currn;
	 _TERMACT_LST_Declarationrule_19;
	} this code has been moved to _Elemrule_19*/
	/*if (_currn->_prod == RULELST_Patternrule_19)
	{_TPPLST_Patternrule_19 _currn = _currn;
	 _TERMACT_LST_Patternrule_19;
	} this code has been moved to _Elemrule_19*/
}
/* make root node and visit it: */
#ifdef __cplusplus
root = new _TPrule_19;
#else
root = (_TPPrule_19) TreeNodeAlloc (sizeof (struct _TPrule_19));
#endif
#ifdef MONITOR
root->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)root));
#endif
root->_prod = RULErule_19;
root->_desc1 = (_TSPLST_Source)list;
{ _TPPrule_19 _currn = root;
  _SETCOORD(_currn)
  _TERMACT_rule_19;
}
_currn = (NODEPTR)root;
return (NODEPTR)_currn;
}
