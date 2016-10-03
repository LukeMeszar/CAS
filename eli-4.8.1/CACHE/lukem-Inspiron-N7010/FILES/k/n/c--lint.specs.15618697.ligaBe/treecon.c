
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
NODEPTR MkVariableDeclList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkVariableDeclList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBVariableDeclList)) return (_currn);
if (IsSymb (_currn, SYMBVariableDeclSeg)) return (Mkrule_13(_coordref, _currn));
return(NULLNODEPTR);
}/* MkVariableDeclList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkStatementList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkStatementList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBStatementList)) return (_currn);
if (IsSymb (_currn, SYMBCompound)) return (Mkrule_9(_coordref, _currn));
if (IsSymb (_currn, SYMBWhileStmt)) return (Mkrule_9(_coordref, _currn));
if (IsSymb (_currn, SYMBStatement)) return (Mkrule_9(_coordref, _currn));
return(NULLNODEPTR);
}/* MkStatementList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkAxiom (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkAxiom (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBAxiom)) return (_currn);
if (IsSymb (_currn, SYMBProgram)) return (Mkrule_1(_coordref, _currn));
return(NULLNODEPTR);
}/* MkAxiom */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOptInitialize (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOptInitialize (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOptInitialize)) return (_currn);
return(NULLNODEPTR);
}/* MkOptInitialize */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkVarIdList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkVarIdList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBVarIdList)) return (_currn);
if (IsSymb (_currn, SYMBVariableDecl)) return (Mkrule_14(_coordref, _currn));
return(NULLNODEPTR);
}/* MkVarIdList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkVariableDeclSeg (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkVariableDeclSeg (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBVariableDeclSeg)) return (_currn);
return(NULLNODEPTR);
}/* MkVariableDeclSeg */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkParameterDecl (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkParameterDecl (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBParameterDecl)) return (_currn);
return(NULLNODEPTR);
}/* MkParameterDecl */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkVariableDecl (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkVariableDecl (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBVariableDecl)) return (_currn);
return(NULLNODEPTR);
}/* MkVariableDecl */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkUnop (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkUnop (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBUnop)) return (_currn);
return(NULLNODEPTR);
}/* MkUnop */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkBinop (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkBinop (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBBinop)) return (_currn);
return(NULLNODEPTR);
}/* MkBinop */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkNotop (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkNotop (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBNotop)) return (_currn);
return(NULLNODEPTR);
}/* MkNotop */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkShortCircuitOp (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkShortCircuitOp (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBShortCircuitOp)) return (_currn);
return(NULLNODEPTR);
}/* MkShortCircuitOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkParameterList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkParameterList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBParameterList)) return (_currn);
if (IsSymb (_currn, SYMBParameterDecl)) return (Mkrule_5(_coordref, _currn));
return(NULLNODEPTR);
}/* MkParameterList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkResultType (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkResultType (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBResultType)) return (_currn);
return(NULLNODEPTR);
}/* MkResultType */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkWhileStmt (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkWhileStmt (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBWhileStmt)) return (_currn);
return(NULLNODEPTR);
}/* MkWhileStmt */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkExpression (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkExpression (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBExpression)) return (_currn);
if (IsSymb (_currn, SYMBIdUse)) return (MkIdnVal(_coordref, _currn));
return(NULLNODEPTR);
}/* MkExpression */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkStatement (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkStatement (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBStatement)) return (_currn);
if (IsSymb (_currn, SYMBCompound)) return (Mkrule_8(_coordref, _currn));
if (IsSymb (_currn, SYMBWhileStmt)) return (Mkrule_11(_coordref, _currn));
return(NULLNODEPTR);
}/* MkStatement */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkCompound (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkCompound (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBCompound)) return (_currn);
return(NULLNODEPTR);
}/* MkCompound */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkProgram (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkProgram (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBProgram)) return (_currn);
return(NULLNODEPTR);
}/* MkProgram */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIdUse (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkIdUse (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBIdUse)) return (_currn);
return(NULLNODEPTR);
}/* MkIdUse */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIdDef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkIdDef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBIdDef)) return (_currn);
return(NULLNODEPTR);
}/* MkIdDef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_15 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_15 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPVarIdList) MkVarIdList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_15: root of subtree no. 1 can not be made a VarIdList node ", 0, _coordref);
_currn->_desc2 = (_TSPVariableDecl) MkVariableDecl (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_15: root of subtree no. 2 can not be made a VariableDecl node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_15;
return ( (NODEPTR) _currn);
}/* Mkrule_15 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_14 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_14 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPVariableDecl) MkVariableDecl (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_14: root of subtree no. 1 can not be made a VariableDecl node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_14;
return ( (NODEPTR) _currn);
}/* Mkrule_14 */

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
_currn->_desc1 = (_TSPVariableDeclSeg) MkVariableDeclSeg (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 1 can not be made a VariableDeclSeg node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_13;
return ( (NODEPTR) _currn);
}/* Mkrule_13 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_12 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_12 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPVariableDeclList) MkVariableDeclList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_12: root of subtree no. 1 can not be made a VariableDeclList node ", 0, _coordref);
_currn->_desc2 = (_TSPVariableDeclSeg) MkVariableDeclSeg (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_12: root of subtree no. 2 can not be made a VariableDeclSeg node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_12;
return ( (NODEPTR) _currn);
}/* Mkrule_12 */

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
_currn->_desc1 = (_TSPWhileStmt) MkWhileStmt (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_11: root of subtree no. 1 can not be made a WhileStmt node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_11;
return ( (NODEPTR) _currn);
}/* Mkrule_11 */

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
_currn->_desc1 = (_TSPStatementList) MkStatementList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 1 can not be made a StatementList node ", 0, _coordref);
_currn->_desc2 = (_TSPStatement) MkStatement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 2 can not be made a Statement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_10;
return ( (NODEPTR) _currn);
}/* Mkrule_10 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_9 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_9 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPStatement) MkStatement (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_9: root of subtree no. 1 can not be made a Statement node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_9;
return ( (NODEPTR) _currn);
}/* Mkrule_9 */

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
_currn->_desc1 = (_TSPCompound) MkCompound (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_8: root of subtree no. 1 can not be made a Compound node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_8;
return ( (NODEPTR) _currn);
}/* Mkrule_8 */

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
NODEPTR Mkrule_6 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_6 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPParameterList) MkParameterList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_6: root of subtree no. 1 can not be made a ParameterList node ", 0, _coordref);
_currn->_desc2 = (_TSPParameterDecl) MkParameterDecl (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_6: root of subtree no. 2 can not be made a ParameterDecl node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_6;
return ( (NODEPTR) _currn);
}/* Mkrule_6 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_5 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_5 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPParameterDecl) MkParameterDecl (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_5: root of subtree no. 1 can not be made a ParameterDecl node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_5;
return ( (NODEPTR) _currn);
}/* Mkrule_5 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_4 (POSITION *_coordref)
#else
NODEPTR Mkrule_4 (_coordref)
	POSITION *_coordref;
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
return ( (NODEPTR) _currn);
}/* Mkrule_4 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_3 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_3 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPVariableDeclList) MkVariableDeclList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_3: root of subtree no. 1 can not be made a VariableDeclList node ", 0, _coordref);
_currn->_desc2 = (_TSPStatementList) MkStatementList (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_3: root of subtree no. 2 can not be made a StatementList node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_3;
return ( (NODEPTR) _currn);
}/* Mkrule_3 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_2 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_2 (_coordref,_desc1)
	POSITION *_coordref;
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
_currn->_desc1 = (_TSPStatementList) MkStatementList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_2: root of subtree no. 1 can not be made a StatementList node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_2;
return ( (NODEPTR) _currn);
}/* Mkrule_2 */

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
_currn->_desc1 = (_TSPProgram) MkProgram (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_1: root of subtree no. 1 can not be made a Program node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_1;
return ( (NODEPTR) _currn);
}/* Mkrule_1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkMonadicExp (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR MkMonadicExp (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPMonadicExp _currn;
#ifdef __cplusplus
_currn = new _TPMonadicExp;
#else
_currn = (_TPPMonadicExp) TreeNodeAlloc (sizeof (struct _TPMonadicExp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEMonadicExp;
_currn->_desc1 = (_TSPUnop) MkUnop (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE MonadicExp: root of subtree no. 1 can not be made a Unop node ", 0, _coordref);
_currn->_desc2 = (_TSPExpression) MkExpression (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE MonadicExp: root of subtree no. 2 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_MonadicExp;
return ( (NODEPTR) _currn);
}/* MkMonadicExp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkDyadicExp (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR MkDyadicExp (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPDyadicExp _currn;
#ifdef __cplusplus
_currn = new _TPDyadicExp;
#else
_currn = (_TPPDyadicExp) TreeNodeAlloc (sizeof (struct _TPDyadicExp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEDyadicExp;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE DyadicExp: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_currn->_desc2 = (_TSPBinop) MkBinop (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE DyadicExp: root of subtree no. 2 can not be made a Binop node ", 0, _coordref);
_currn->_desc3 = (_TSPExpression) MkExpression (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE DyadicExp: root of subtree no. 3 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_DyadicExp;
return ( (NODEPTR) _currn);
}/* MkDyadicExp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIdnVal (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkIdnVal (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPIdnVal _currn;
#ifdef __cplusplus
_currn = new _TPIdnVal;
#else
_currn = (_TPPIdnVal) TreeNodeAlloc (sizeof (struct _TPIdnVal));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEIdnVal;
_currn->_desc1 = (_TSPIdUse) MkIdUse (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE IdnVal: root of subtree no. 1 can not be made a IdUse node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_IdnVal;
return ( (NODEPTR) _currn);
}/* MkIdnVal */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkFloatVal (POSITION *_coordref, int _TERM1)
#else
NODEPTR MkFloatVal (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPFloatVal _currn;
#ifdef __cplusplus
_currn = new _TPFloatVal;
#else
_currn = (_TPPFloatVal) TreeNodeAlloc (sizeof (struct _TPFloatVal));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEFloatVal;
_SETCOORD(_currn)
_TERMACT_FloatVal;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "FloatDenotation", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* MkFloatVal */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIntVal (POSITION *_coordref, int _TERM1)
#else
NODEPTR MkIntVal (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPIntVal _currn;
#ifdef __cplusplus
_currn = new _TPIntVal;
#else
_currn = (_TPPIntVal) TreeNodeAlloc (sizeof (struct _TPIntVal));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEIntVal;
_SETCOORD(_currn)
_TERMACT_IntVal;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "IntDenotation", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* MkIntVal */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkFloatParDecl (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkFloatParDecl (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPFloatParDecl _currn;
#ifdef __cplusplus
_currn = new _TPFloatParDecl;
#else
_currn = (_TPPFloatParDecl) TreeNodeAlloc (sizeof (struct _TPFloatParDecl));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEFloatParDecl;
_currn->_desc1 = (_TSPIdDef) MkIdDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE FloatParDecl: root of subtree no. 1 can not be made a IdDef node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_FloatParDecl;
return ( (NODEPTR) _currn);
}/* MkFloatParDecl */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIntParDecl (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkIntParDecl (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPIntParDecl _currn;
#ifdef __cplusplus
_currn = new _TPIntParDecl;
#else
_currn = (_TPPIntParDecl) TreeNodeAlloc (sizeof (struct _TPIntParDecl));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEIntParDecl;
_currn->_desc1 = (_TSPIdDef) MkIdDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE IntParDecl: root of subtree no. 1 can not be made a IdDef node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_IntParDecl;
return ( (NODEPTR) _currn);
}/* MkIntParDecl */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkInitialize (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkInitialize (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPInitialize _currn;
#ifdef __cplusplus
_currn = new _TPInitialize;
#else
_currn = (_TPPInitialize) TreeNodeAlloc (sizeof (struct _TPInitialize));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEInitialize;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE Initialize: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_Initialize;
return ( (NODEPTR) _currn);
}/* MkInitialize */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkVarDecl (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR MkVarDecl (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPVarDecl _currn;
#ifdef __cplusplus
_currn = new _TPVarDecl;
#else
_currn = (_TPPVarDecl) TreeNodeAlloc (sizeof (struct _TPVarDecl));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEVarDecl;
_currn->_desc1 = (_TSPIdDef) MkIdDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE VarDecl: root of subtree no. 1 can not be made a IdDef node ", 0, _coordref);
_currn->_desc2 = (_TSPOptInitialize) MkOptInitialize (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE VarDecl: root of subtree no. 2 can not be made a OptInitialize node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_VarDecl;
return ( (NODEPTR) _currn);
}/* MkVarDecl */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkFloatVar (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkFloatVar (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPFloatVar _currn;
#ifdef __cplusplus
_currn = new _TPFloatVar;
#else
_currn = (_TPPFloatVar) TreeNodeAlloc (sizeof (struct _TPFloatVar));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEFloatVar;
_currn->_desc1 = (_TSPVarIdList) MkVarIdList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE FloatVar: root of subtree no. 1 can not be made a VarIdList node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_FloatVar;
return ( (NODEPTR) _currn);
}/* MkFloatVar */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIntVar (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkIntVar (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPIntVar _currn;
#ifdef __cplusplus
_currn = new _TPIntVar;
#else
_currn = (_TPPIntVar) TreeNodeAlloc (sizeof (struct _TPIntVar));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEIntVar;
_currn->_desc1 = (_TSPVarIdList) MkVarIdList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE IntVar: root of subtree no. 1 can not be made a VarIdList node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_IntVar;
return ( (NODEPTR) _currn);
}/* MkIntVar */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkUMinusOp (POSITION *_coordref)
#else
NODEPTR MkUMinusOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPUMinusOp _currn;
#ifdef __cplusplus
_currn = new _TPUMinusOp;
#else
_currn = (_TPPUMinusOp) TreeNodeAlloc (sizeof (struct _TPUMinusOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEUMinusOp;
_SETCOORD(_currn)
_TERMACT_UMinusOp;
return ( (NODEPTR) _currn);
}/* MkUMinusOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkPercentOp (POSITION *_coordref)
#else
NODEPTR MkPercentOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPPercentOp _currn;
#ifdef __cplusplus
_currn = new _TPPercentOp;
#else
_currn = (_TPPPercentOp) TreeNodeAlloc (sizeof (struct _TPPercentOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEPercentOp;
_SETCOORD(_currn)
_TERMACT_PercentOp;
return ( (NODEPTR) _currn);
}/* MkPercentOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSlashOp (POSITION *_coordref)
#else
NODEPTR MkSlashOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPSlashOp _currn;
#ifdef __cplusplus
_currn = new _TPSlashOp;
#else
_currn = (_TPPSlashOp) TreeNodeAlloc (sizeof (struct _TPSlashOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULESlashOp;
_SETCOORD(_currn)
_TERMACT_SlashOp;
return ( (NODEPTR) _currn);
}/* MkSlashOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkStarOp (POSITION *_coordref)
#else
NODEPTR MkStarOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPStarOp _currn;
#ifdef __cplusplus
_currn = new _TPStarOp;
#else
_currn = (_TPPStarOp) TreeNodeAlloc (sizeof (struct _TPStarOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEStarOp;
_SETCOORD(_currn)
_TERMACT_StarOp;
return ( (NODEPTR) _currn);
}/* MkStarOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkMinusOp (POSITION *_coordref)
#else
NODEPTR MkMinusOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPMinusOp _currn;
#ifdef __cplusplus
_currn = new _TPMinusOp;
#else
_currn = (_TPPMinusOp) TreeNodeAlloc (sizeof (struct _TPMinusOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEMinusOp;
_SETCOORD(_currn)
_TERMACT_MinusOp;
return ( (NODEPTR) _currn);
}/* MkMinusOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkPlusOp (POSITION *_coordref)
#else
NODEPTR MkPlusOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPPlusOp _currn;
#ifdef __cplusplus
_currn = new _TPPlusOp;
#else
_currn = (_TPPPlusOp) TreeNodeAlloc (sizeof (struct _TPPlusOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEPlusOp;
_SETCOORD(_currn)
_TERMACT_PlusOp;
return ( (NODEPTR) _currn);
}/* MkPlusOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkGreaterOp (POSITION *_coordref)
#else
NODEPTR MkGreaterOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPGreaterOp _currn;
#ifdef __cplusplus
_currn = new _TPGreaterOp;
#else
_currn = (_TPPGreaterOp) TreeNodeAlloc (sizeof (struct _TPGreaterOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEGreaterOp;
_SETCOORD(_currn)
_TERMACT_GreaterOp;
return ( (NODEPTR) _currn);
}/* MkGreaterOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkLessOp (POSITION *_coordref)
#else
NODEPTR MkLessOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPLessOp _currn;
#ifdef __cplusplus
_currn = new _TPLessOp;
#else
_currn = (_TPPLessOp) TreeNodeAlloc (sizeof (struct _TPLessOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULELessOp;
_SETCOORD(_currn)
_TERMACT_LessOp;
return ( (NODEPTR) _currn);
}/* MkLessOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkEqualOp (POSITION *_coordref)
#else
NODEPTR MkEqualOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPEqualOp _currn;
#ifdef __cplusplus
_currn = new _TPEqualOp;
#else
_currn = (_TPPEqualOp) TreeNodeAlloc (sizeof (struct _TPEqualOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEEqualOp;
_SETCOORD(_currn)
_TERMACT_EqualOp;
return ( (NODEPTR) _currn);
}/* MkEqualOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkExclOp (POSITION *_coordref)
#else
NODEPTR MkExclOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPExclOp _currn;
#ifdef __cplusplus
_currn = new _TPExclOp;
#else
_currn = (_TPPExclOp) TreeNodeAlloc (sizeof (struct _TPExclOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEExclOp;
_SETCOORD(_currn)
_TERMACT_ExclOp;
return ( (NODEPTR) _currn);
}/* MkExclOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkNotExp (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR MkNotExp (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPNotExp _currn;
#ifdef __cplusplus
_currn = new _TPNotExp;
#else
_currn = (_TPPNotExp) TreeNodeAlloc (sizeof (struct _TPNotExp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULENotExp;
_currn->_desc1 = (_TSPNotop) MkNotop (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE NotExp: root of subtree no. 1 can not be made a Notop node ", 0, _coordref);
_currn->_desc2 = (_TSPExpression) MkExpression (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE NotExp: root of subtree no. 2 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_NotExp;
return ( (NODEPTR) _currn);
}/* MkNotExp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkAmpOp (POSITION *_coordref)
#else
NODEPTR MkAmpOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPAmpOp _currn;
#ifdef __cplusplus
_currn = new _TPAmpOp;
#else
_currn = (_TPPAmpOp) TreeNodeAlloc (sizeof (struct _TPAmpOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEAmpOp;
_SETCOORD(_currn)
_TERMACT_AmpOp;
return ( (NODEPTR) _currn);
}/* MkAmpOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkBarOp (POSITION *_coordref)
#else
NODEPTR MkBarOp (_coordref)
	POSITION *_coordref;
#endif
{	_TPPBarOp _currn;
#ifdef __cplusplus
_currn = new _TPBarOp;
#else
_currn = (_TPPBarOp) TreeNodeAlloc (sizeof (struct _TPBarOp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEBarOp;
_SETCOORD(_currn)
_TERMACT_BarOp;
return ( (NODEPTR) _currn);
}/* MkBarOp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkShortCircuitExp (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR MkShortCircuitExp (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPShortCircuitExp _currn;
#ifdef __cplusplus
_currn = new _TPShortCircuitExp;
#else
_currn = (_TPPShortCircuitExp) TreeNodeAlloc (sizeof (struct _TPShortCircuitExp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEShortCircuitExp;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE ShortCircuitExp: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_currn->_desc2 = (_TSPShortCircuitOp) MkShortCircuitOp (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE ShortCircuitExp: root of subtree no. 2 can not be made a ShortCircuitOp node ", 0, _coordref);
_currn->_desc3 = (_TSPExpression) MkExpression (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE ShortCircuitExp: root of subtree no. 3 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_ShortCircuitExp;
return ( (NODEPTR) _currn);
}/* MkShortCircuitExp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkCondExp (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR MkCondExp (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPCondExp _currn;
#ifdef __cplusplus
_currn = new _TPCondExp;
#else
_currn = (_TPPCondExp) TreeNodeAlloc (sizeof (struct _TPCondExp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULECondExp;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE CondExp: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_currn->_desc2 = (_TSPExpression) MkExpression (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE CondExp: root of subtree no. 2 can not be made a Expression node ", 0, _coordref);
_currn->_desc3 = (_TSPExpression) MkExpression (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE CondExp: root of subtree no. 3 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_CondExp;
return ( (NODEPTR) _currn);
}/* MkCondExp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkAssignExp (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR MkAssignExp (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPAssignExp _currn;
#ifdef __cplusplus
_currn = new _TPAssignExp;
#else
_currn = (_TPPAssignExp) TreeNodeAlloc (sizeof (struct _TPAssignExp));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEAssignExp;
_currn->_desc1 = (_TSPIdUse) MkIdUse (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE AssignExp: root of subtree no. 1 can not be made a IdUse node ", 0, _coordref);
_currn->_desc2 = (_TSPExpression) MkExpression (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE AssignExp: root of subtree no. 2 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_AssignExp;
return ( (NODEPTR) _currn);
}/* MkAssignExp */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkExprStmt (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkExprStmt (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPExprStmt _currn;
#ifdef __cplusplus
_currn = new _TPExprStmt;
#else
_currn = (_TPPExprStmt) TreeNodeAlloc (sizeof (struct _TPExprStmt));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEExprStmt;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE ExprStmt: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_ExprStmt;
return ( (NODEPTR) _currn);
}/* MkExprStmt */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkFloatResult (POSITION *_coordref)
#else
NODEPTR MkFloatResult (_coordref)
	POSITION *_coordref;
#endif
{	_TPPFloatResult _currn;
#ifdef __cplusplus
_currn = new _TPFloatResult;
#else
_currn = (_TPPFloatResult) TreeNodeAlloc (sizeof (struct _TPFloatResult));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEFloatResult;
_SETCOORD(_currn)
_TERMACT_FloatResult;
return ( (NODEPTR) _currn);
}/* MkFloatResult */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIntResult (POSITION *_coordref)
#else
NODEPTR MkIntResult (_coordref)
	POSITION *_coordref;
#endif
{	_TPPIntResult _currn;
#ifdef __cplusplus
_currn = new _TPIntResult;
#else
_currn = (_TPPIntResult) TreeNodeAlloc (sizeof (struct _TPIntResult));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEIntResult;
_SETCOORD(_currn)
_TERMACT_IntResult;
return ( (NODEPTR) _currn);
}/* MkIntResult */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSource (POSITION *_coordref, NODEPTR _desc1, int _TERM1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR MkSource (_coordref,_desc1, _TERM1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	int _TERM1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPSource _currn;
#ifdef __cplusplus
_currn = new _TPSource;
#else
_currn = (_TPPSource) TreeNodeAlloc (sizeof (struct _TPSource));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULESource;
_currn->_desc1 = (_TSPResultType) MkResultType (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE Source: root of subtree no. 1 can not be made a ResultType node ", 0, _coordref);
_currn->_desc2 = (_TSPParameterList) MkParameterList (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE Source: root of subtree no. 2 can not be made a ParameterList node ", 0, _coordref);
_currn->_desc3 = (_TSPCompound) MkCompound (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE Source: root of subtree no. 3 can not be made a Compound node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_Source;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* MkSource */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkReturnStmt (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR MkReturnStmt (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPReturnStmt _currn;
#ifdef __cplusplus
_currn = new _TPReturnStmt;
#else
_currn = (_TPPReturnStmt) TreeNodeAlloc (sizeof (struct _TPReturnStmt));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEReturnStmt;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE ReturnStmt: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_ReturnStmt;
return ( (NODEPTR) _currn);
}/* MkReturnStmt */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkContinueStmt (POSITION *_coordref)
#else
NODEPTR MkContinueStmt (_coordref)
	POSITION *_coordref;
#endif
{	_TPPContinueStmt _currn;
#ifdef __cplusplus
_currn = new _TPContinueStmt;
#else
_currn = (_TPPContinueStmt) TreeNodeAlloc (sizeof (struct _TPContinueStmt));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEContinueStmt;
_SETCOORD(_currn)
_TERMACT_ContinueStmt;
return ( (NODEPTR) _currn);
}/* MkContinueStmt */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkBreakStmt (POSITION *_coordref)
#else
NODEPTR MkBreakStmt (_coordref)
	POSITION *_coordref;
#endif
{	_TPPBreakStmt _currn;
#ifdef __cplusplus
_currn = new _TPBreakStmt;
#else
_currn = (_TPPBreakStmt) TreeNodeAlloc (sizeof (struct _TPBreakStmt));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEBreakStmt;
_SETCOORD(_currn)
_TERMACT_BreakStmt;
return ( (NODEPTR) _currn);
}/* MkBreakStmt */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkLoop (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR MkLoop (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPLoop _currn;
#ifdef __cplusplus
_currn = new _TPLoop;
#else
_currn = (_TPPLoop) TreeNodeAlloc (sizeof (struct _TPLoop));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULELoop;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE Loop: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_currn->_desc2 = (_TSPStatement) MkStatement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE Loop: root of subtree no. 2 can not be made a Statement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_Loop;
return ( (NODEPTR) _currn);
}/* MkLoop */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkTwoSided (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR MkTwoSided (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
#endif
{	_TPPTwoSided _currn;
#ifdef __cplusplus
_currn = new _TPTwoSided;
#else
_currn = (_TPPTwoSided) TreeNodeAlloc (sizeof (struct _TPTwoSided));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULETwoSided;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE TwoSided: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_currn->_desc2 = (_TSPStatement) MkStatement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE TwoSided: root of subtree no. 2 can not be made a Statement node ", 0, _coordref);
_currn->_desc3 = (_TSPStatement) MkStatement (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE TwoSided: root of subtree no. 3 can not be made a Statement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_TwoSided;
return ( (NODEPTR) _currn);
}/* MkTwoSided */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOneSided (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR MkOneSided (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPOneSided _currn;
#ifdef __cplusplus
_currn = new _TPOneSided;
#else
_currn = (_TPPOneSided) TreeNodeAlloc (sizeof (struct _TPOneSided));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEOneSided;
_currn->_desc1 = (_TSPExpression) MkExpression (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE OneSided: root of subtree no. 1 can not be made a Expression node ", 0, _coordref);
_currn->_desc2 = (_TSPStatement) MkStatement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE OneSided: root of subtree no. 2 can not be made a Statement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_OneSided;
return ( (NODEPTR) _currn);
}/* MkOneSided */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkAppliedOccurrence (POSITION *_coordref, int _TERM1)
#else
NODEPTR MkAppliedOccurrence (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPAppliedOccurrence _currn;
#ifdef __cplusplus
_currn = new _TPAppliedOccurrence;
#else
_currn = (_TPPAppliedOccurrence) TreeNodeAlloc (sizeof (struct _TPAppliedOccurrence));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEAppliedOccurrence;
_SETCOORD(_currn)
_TERMACT_AppliedOccurrence;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* MkAppliedOccurrence */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkDefiningOccurrence (POSITION *_coordref, int _TERM1)
#else
NODEPTR MkDefiningOccurrence (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPDefiningOccurrence _currn;
#ifdef __cplusplus
_currn = new _TPDefiningOccurrence;
#else
_currn = (_TPPDefiningOccurrence) TreeNodeAlloc (sizeof (struct _TPDefiningOccurrence));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULEDefiningOccurrence;
_SETCOORD(_currn)
_TERMACT_DefiningOccurrence;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* MkDefiningOccurrence */
