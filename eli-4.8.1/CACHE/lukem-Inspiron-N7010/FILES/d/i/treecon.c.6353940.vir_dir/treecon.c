
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
NODEPTR MkOperation (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOperation (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOperation)) return (_currn);
return(NULLNODEPTR);
}/* MkOperation */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIdentification (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkIdentification (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBIdentification)) return (_currn);
return(NULLNODEPTR);
}/* MkIdentification */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG6 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG6 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG6)) return (_currn);
if (IsSymb (_currn, SYMBOpRef)) return (Mkrule_59(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG6 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG5 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG5 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG5)) return (_currn);
if (IsSymb (_currn, SYMBIndication)) return (Mkrule_57(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG5 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG4 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG4 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG4)) return (_currn);
if (IsSymb (_currn, SYMBOpDef)) return (Mkrule_55(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG4 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG3 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG3 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG3)) return (_currn);
if (IsSymb (_currn, SYMBCoerce)) return (Mkrule_52(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG3 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG2 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG2 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG2)) return (_currn);
if (IsSymb (_currn, SYMBOper)) return (Mkrule_51(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG2 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSpecificationElement (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSpecificationElement (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSpecificationElement)) return (_currn);
if (IsSymb (_currn, SYMBClass)) return (Mkrule_72(_coordref, _currn));
if (IsSymb (_currn, SYMBEquivalenceClass)) return (Mkrule_73(_coordref, _currn));
if (IsSymb (_currn, SYMBIdentification)) return (Mkrule_74(_coordref, _currn));
if (IsSymb (_currn, SYMBOperation)) return (Mkrule_75(_coordref, _currn));
return(NULLNODEPTR);
}/* MkSpecificationElement */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG12 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG12 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG12)) return (_currn);
if (IsSymb (_currn, SYMBSingleton)) return (Mkrule_48(_coordref, _currn));
if (IsSymb (_currn, SYMBTypeIdentifier)) return (Mkrule_48(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG12 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG1 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG1 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG1)) return (_currn);
return(NULLNODEPTR);
}/* MkG1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG8 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG8 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG8)) return (_currn);
if (IsSymb (_currn, SYMBClassParameter)) return (Mkrule_62(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG8 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG9 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG9 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG9)) return (_currn);
if (IsSymb (_currn, SYMBClassOper)) return (Mkrule_64(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG9 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG10 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG10 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG10)) return (_currn);
if (IsSymb (_currn, SYMBClassCoerce)) return (Mkrule_43(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG10 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassOperation (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassOperation (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassOperation)) return (_currn);
return(NULLNODEPTR);
}/* MkClassOperation */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG11 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG11 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG11)) return (_currn);
if (IsSymb (_currn, SYMBClassOpDef)) return (Mkrule_45(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG11 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkG7 (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkG7 (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBG7)) return (_currn);
if (IsSymb (_currn, SYMBClassOperation)) return (Mkrule_60(_coordref, _currn));
return(NULLNODEPTR);
}/* MkG7 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassCoerce (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassCoerce (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassCoerce)) return (_currn);
return(NULLNODEPTR);
}/* MkClassCoerce */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassOpDefList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassOpDefList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassOpDefList)) return (_currn);
if (IsSymb (_currn, SYMBClassOpDef)) return (Mkrule_38(_coordref, _currn));
if (IsSymb (_currn, SYMBG11)) return (Mkrule_38(_coordref, _currn));
return(NULLNODEPTR);
}/* MkClassOpDefList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassOper (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassOper (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassOper)) return (_currn);
return(NULLNODEPTR);
}/* MkClassOper */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassSignature (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassSignature (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassSignature)) return (_currn);
if (IsSymb (_currn, SYMBTypeIdentifier)) return (Mkrule_5(_coordref, _currn));
if (IsSymb (_currn, SYMBSignatureElement)) return (Mkrule_5(_coordref, _currn));
return(NULLNODEPTR);
}/* MkClassSignature */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassParameters (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassParameters (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassParameters)) return (_currn);
if (IsSymb (_currn, SYMBClassParameter)) return (Mkrule_41(_coordref, _currn));
if (IsSymb (_currn, SYMBG8)) return (Mkrule_41(_coordref, _currn));
return(NULLNODEPTR);
}/* MkClassParameters */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClass (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClass (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClass)) return (_currn);
return(NULLNODEPTR);
}/* MkClass */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOpRefList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOpRefList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOpRefList)) return (_currn);
if (IsSymb (_currn, SYMBOpRef)) return (Mkrule_71(_coordref, _currn));
if (IsSymb (_currn, SYMBG6)) return (Mkrule_71(_coordref, _currn));
return(NULLNODEPTR);
}/* MkOpRefList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIndication (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkIndication (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBIndication)) return (_currn);
return(NULLNODEPTR);
}/* MkIndication */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkCoerce (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkCoerce (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBCoerce)) return (_currn);
return(NULLNODEPTR);
}/* MkCoerce */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOpDefList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOpDefList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOpDefList)) return (_currn);
if (IsSymb (_currn, SYMBOpDef)) return (Mkrule_68(_coordref, _currn));
if (IsSymb (_currn, SYMBG4)) return (Mkrule_68(_coordref, _currn));
return(NULLNODEPTR);
}/* MkOpDefList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOper (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOper (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOper)) return (_currn);
return(NULLNODEPTR);
}/* MkOper */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSignatureElement (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSignatureElement (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSignatureElement)) return (_currn);
if (IsSymb (_currn, SYMBTypeIdentifier)) return (Mkrule_11(_coordref, _currn));
return(NULLNODEPTR);
}/* MkSignatureElement */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSignature (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSignature (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSignature)) return (_currn);
if (IsSymb (_currn, SYMBTypeIdentifier)) return (Mkrule_14(_coordref, _currn));
if (IsSymb (_currn, SYMBSignatureElement)) return (Mkrule_14(_coordref, _currn));
return(NULLNODEPTR);
}/* MkSignature */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSingleton (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSingleton (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSingleton)) return (_currn);
if (IsSymb (_currn, SYMBTypeIdentifier)) return (Mkrule_16(_coordref, _currn));
return(NULLNODEPTR);
}/* MkSingleton */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxTypeList (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxTypeList (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxTypeList)) return (_currn);
if (IsSymb (_currn, SYMBG12)) return (Mkrule_76(_coordref, _currn));
if (IsSymb (_currn, SYMBSingleton)) return (Mkrule_76(_coordref, _currn));
if (IsSymb (_currn, SYMBTypeIdentifier)) return (Mkrule_76(_coordref, _currn));
return(NULLNODEPTR);
}/* MkxTypeList */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkxTypeExpr (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkxTypeExpr (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBxTypeExpr)) return (_currn);
if (IsSymb (_currn, SYMBSetIdUse)) return (Mkrule_21(_coordref, _currn));
return(NULLNODEPTR);
}/* MkxTypeExpr */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkEquivalenceClass (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkEquivalenceClass (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBEquivalenceClass)) return (_currn);
return(NULLNODEPTR);
}/* MkEquivalenceClass */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassBody (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassBody (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassBody)) return (_currn);
return(NULLNODEPTR);
}/* MkClassBody */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOIL (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOIL (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOIL)) return (_currn);
if (IsSymb (_currn, SYMBG1)) return (Mkrule_67(_coordref, _currn));
return(NULLNODEPTR);
}/* MkOIL */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSetIdUse (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSetIdUse (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSetIdUse)) return (_currn);
return(NULLNODEPTR);
}/* MkSetIdUse */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkSetIdDef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkSetIdDef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBSetIdDef)) return (_currn);
return(NULLNODEPTR);
}/* MkSetIdDef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOpRef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOpRef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOpRef)) return (_currn);
return(NULLNODEPTR);
}/* MkOpRef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkIndDef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkIndDef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBIndDef)) return (_currn);
return(NULLNODEPTR);
}/* MkIndDef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassParameter (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassParameter (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassParameter)) return (_currn);
return(NULLNODEPTR);
}/* MkClassParameter */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassName (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassName (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassName)) return (_currn);
return(NULLNODEPTR);
}/* MkClassName */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkTypeIdentifier (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkTypeIdentifier (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBTypeIdentifier)) return (_currn);
return(NULLNODEPTR);
}/* MkTypeIdentifier */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkClassOpDef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkClassOpDef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBClassOpDef)) return (_currn);
return(NULLNODEPTR);
}/* MkClassOpDef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkOpDef (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkOpDef (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBOpDef)) return (_currn);
return(NULLNODEPTR);
}/* MkOpDef */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR MkCostSpecification (POSITION *_coordref, NODEPTR _currn)
#else
NODEPTR MkCostSpecification (_coordref, _currn)
	POSITION *_coordref; NODEPTR _currn;
#endif
{
if (_currn == NULLNODEPTR) return NULLNODEPTR;
if (IsSymb (_currn, SYMBCostSpecification)) return (_currn);
return(NULLNODEPTR);
}/* MkCostSpecification */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_1 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_1 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
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
_currn->_desc1 = (_TSPClassOpDef) MkClassOpDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_1: root of subtree no. 1 can not be made a ClassOpDef node ", 0, _coordref);
_currn->_desc2 = (_TSPClassSignature) MkClassSignature (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_1: root of subtree no. 2 can not be made a ClassSignature node ", 0, _coordref);
_currn->_desc3 = (_TSPCostSpecification) MkCostSpecification (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_1: root of subtree no. 3 can not be made a CostSpecification node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_1;
return ( (NODEPTR) _currn);
}/* Mkrule_1 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_2 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_2 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
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
_currn->_desc1 = (_TSPClassOpDefList) MkClassOpDefList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_2: root of subtree no. 1 can not be made a ClassOpDefList node ", 0, _coordref);
_currn->_desc2 = (_TSPClassSignature) MkClassSignature (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_2: root of subtree no. 2 can not be made a ClassSignature node ", 0, _coordref);
_currn->_desc3 = (_TSPCostSpecification) MkCostSpecification (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_2: root of subtree no. 3 can not be made a CostSpecification node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_2;
return ( (NODEPTR) _currn);
}/* Mkrule_2 */

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
_currn->_desc1 = (_TSPClassSignature) MkClassSignature (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_3: root of subtree no. 1 can not be made a ClassSignature node ", 0, _coordref);
_currn->_desc2 = (_TSPSignatureElement) MkSignatureElement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_3: root of subtree no. 2 can not be made a SignatureElement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_3;
return ( (NODEPTR) _currn);
}/* Mkrule_3 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_4 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_4 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPSignatureElement) MkSignatureElement (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_4: root of subtree no. 1 can not be made a SignatureElement node ", 0, _coordref);
_currn->_desc2 = (_TSPClassSignature) MkClassSignature (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_4: root of subtree no. 2 can not be made a ClassSignature node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_4;
return ( (NODEPTR) _currn);
}/* Mkrule_4 */

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
_currn->_desc1 = (_TSPSignatureElement) MkSignatureElement (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_5: root of subtree no. 1 can not be made a SignatureElement node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_5;
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
NODEPTR Mkrule_7 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_7 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPClassName) MkClassName (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_7: root of subtree no. 1 can not be made a ClassName node ", 0, _coordref);
_currn->_desc2 = (_TSPClassBody) MkClassBody (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_7: root of subtree no. 2 can not be made a ClassBody node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_7;
return ( (NODEPTR) _currn);
}/* Mkrule_7 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_8 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_8 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPIndDef) MkIndDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_8: root of subtree no. 1 can not be made a IndDef node ", 0, _coordref);
_currn->_desc2 = (_TSPOpRefList) MkOpRefList (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_8: root of subtree no. 2 can not be made a OpRefList node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_8;
return ( (NODEPTR) _currn);
}/* Mkrule_8 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_9 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_9 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
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
_currn->_desc1 = (_TSPOpDef) MkOpDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_9: root of subtree no. 1 can not be made a OpDef node ", 0, _coordref);
_currn->_desc2 = (_TSPSignature) MkSignature (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_9: root of subtree no. 2 can not be made a Signature node ", 0, _coordref);
_currn->_desc3 = (_TSPCostSpecification) MkCostSpecification (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_9: root of subtree no. 3 can not be made a CostSpecification node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_9;
return ( (NODEPTR) _currn);
}/* Mkrule_9 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_10 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3)
#else
NODEPTR Mkrule_10 (_coordref,_desc1,_desc2,_desc3)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
	NODEPTR _desc3;
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
_currn->_desc1 = (_TSPOpDefList) MkOpDefList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 1 can not be made a OpDefList node ", 0, _coordref);
_currn->_desc2 = (_TSPSignature) MkSignature (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 2 can not be made a Signature node ", 0, _coordref);
_currn->_desc3 = (_TSPCostSpecification) MkCostSpecification (_coordref, _desc3);	
if (((NODEPTR)_currn->_desc3) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_10: root of subtree no. 3 can not be made a CostSpecification node ", 0, _coordref);
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
_currn->_desc1 = (_TSPTypeIdentifier) MkTypeIdentifier (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_11: root of subtree no. 1 can not be made a TypeIdentifier node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_11;
return ( (NODEPTR) _currn);
}/* Mkrule_11 */

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
_currn->_desc1 = (_TSPSignature) MkSignature (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_12: root of subtree no. 1 can not be made a Signature node ", 0, _coordref);
_currn->_desc2 = (_TSPSignatureElement) MkSignatureElement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_12: root of subtree no. 2 can not be made a SignatureElement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_12;
return ( (NODEPTR) _currn);
}/* Mkrule_12 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_13 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_13 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPSignatureElement) MkSignatureElement (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 1 can not be made a SignatureElement node ", 0, _coordref);
_currn->_desc2 = (_TSPSignature) MkSignature (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_13: root of subtree no. 2 can not be made a Signature node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_13;
return ( (NODEPTR) _currn);
}/* Mkrule_13 */

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
_currn->_desc1 = (_TSPSignatureElement) MkSignatureElement (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_14: root of subtree no. 1 can not be made a SignatureElement node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_14;
return ( (NODEPTR) _currn);
}/* Mkrule_14 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_15 (POSITION *_coordref)
#else
NODEPTR Mkrule_15 (_coordref)
	POSITION *_coordref;
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
_SETCOORD(_currn)
_TERMACT_rule_15;
return ( (NODEPTR) _currn);
}/* Mkrule_15 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_16 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_16 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPTypeIdentifier) MkTypeIdentifier (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_16: root of subtree no. 1 can not be made a TypeIdentifier node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_16;
return ( (NODEPTR) _currn);
}/* Mkrule_16 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_17 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_17 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
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
_currn->_desc1 = (_TSPxTypeList) MkxTypeList (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_17: root of subtree no. 1 can not be made a xTypeList node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_17;
return ( (NODEPTR) _currn);
}/* Mkrule_17 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_18 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_18 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_18: root of subtree no. 1 can not be made a xTypeExpr node ", 0, _coordref);
_currn->_desc2 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_18: root of subtree no. 2 can not be made a xTypeExpr node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_18;
return ( (NODEPTR) _currn);
}/* Mkrule_18 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_19 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_19 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
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
_currn->_desc1 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_19: root of subtree no. 1 can not be made a xTypeExpr node ", 0, _coordref);
_currn->_desc2 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_19: root of subtree no. 2 can not be made a xTypeExpr node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_19;
return ( (NODEPTR) _currn);
}/* Mkrule_19 */

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
_currn->_desc1 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_20: root of subtree no. 1 can not be made a xTypeExpr node ", 0, _coordref);
_currn->_desc2 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_20: root of subtree no. 2 can not be made a xTypeExpr node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_20;
return ( (NODEPTR) _currn);
}/* Mkrule_20 */

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
_currn->_desc1 = (_TSPSetIdUse) MkSetIdUse (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_21: root of subtree no. 1 can not be made a SetIdUse node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_21;
return ( (NODEPTR) _currn);
}/* Mkrule_21 */

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
_currn->_desc1 = (_TSPSetIdDef) MkSetIdDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_22: root of subtree no. 1 can not be made a SetIdDef node ", 0, _coordref);
_currn->_desc2 = (_TSPxTypeExpr) MkxTypeExpr (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_22: root of subtree no. 2 can not be made a xTypeExpr node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_22;
return ( (NODEPTR) _currn);
}/* Mkrule_22 */

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
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_23 */

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
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_24 */

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
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_25 */

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
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_26 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_27 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_27 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_27 _currn;
#ifdef __cplusplus
_currn = new _TPrule_27;
#else
_currn = (_TPPrule_27) TreeNodeAlloc (sizeof (struct _TPrule_27));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_27;
_SETCOORD(_currn)
_TERMACT_rule_27;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_27 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_28 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_28 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_28 _currn;
#ifdef __cplusplus
_currn = new _TPrule_28;
#else
_currn = (_TPPrule_28) TreeNodeAlloc (sizeof (struct _TPrule_28));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_28;
_SETCOORD(_currn)
_TERMACT_rule_28;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_28 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_29 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_29 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_29 _currn;
#ifdef __cplusplus
_currn = new _TPrule_29;
#else
_currn = (_TPPrule_29) TreeNodeAlloc (sizeof (struct _TPrule_29));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_29;
_SETCOORD(_currn)
_TERMACT_rule_29;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_29 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_30 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_30 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_30 _currn;
#ifdef __cplusplus
_currn = new _TPrule_30;
#else
_currn = (_TPPrule_30) TreeNodeAlloc (sizeof (struct _TPrule_30));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_30;
_SETCOORD(_currn)
_TERMACT_rule_30;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_30 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_31 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_31 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_31 _currn;
#ifdef __cplusplus
_currn = new _TPrule_31;
#else
_currn = (_TPPrule_31) TreeNodeAlloc (sizeof (struct _TPrule_31));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_31;
_SETCOORD(_currn)
_TERMACT_rule_31;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Identifier", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_31 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_32 (POSITION *_coordref)
#else
NODEPTR Mkrule_32 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_32 _currn;
#ifdef __cplusplus
_currn = new _TPrule_32;
#else
_currn = (_TPPrule_32) TreeNodeAlloc (sizeof (struct _TPrule_32));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_32;
_SETCOORD(_currn)
_TERMACT_rule_32;
return ( (NODEPTR) _currn);
}/* Mkrule_32 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_33 (POSITION *_coordref)
#else
NODEPTR Mkrule_33 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_33 _currn;
#ifdef __cplusplus
_currn = new _TPrule_33;
#else
_currn = (_TPPrule_33) TreeNodeAlloc (sizeof (struct _TPrule_33));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_33;
_SETCOORD(_currn)
_TERMACT_rule_33;
return ( (NODEPTR) _currn);
}/* Mkrule_33 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_34 (POSITION *_coordref, int _TERM1)
#else
NODEPTR Mkrule_34 (_coordref, _TERM1)
	POSITION *_coordref;
	int _TERM1;
#endif
{	_TPPrule_34 _currn;
#ifdef __cplusplus
_currn = new _TPrule_34;
#else
_currn = (_TPPrule_34) TreeNodeAlloc (sizeof (struct _TPrule_34));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_34;
_SETCOORD(_currn)
_TERMACT_rule_34;
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
_dapto_term_int((_currn)->_uid, "Integer", _TERM1);
#endif

return ( (NODEPTR) _currn);
}/* Mkrule_34 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_35 (POSITION *_coordref)
#else
NODEPTR Mkrule_35 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_35 _currn;
#ifdef __cplusplus
_currn = new _TPrule_35;
#else
_currn = (_TPPrule_35) TreeNodeAlloc (sizeof (struct _TPrule_35));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_35;
_SETCOORD(_currn)
_TERMACT_rule_35;
return ( (NODEPTR) _currn);
}/* Mkrule_35 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_76 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_76 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_76 _currn;
#ifdef __cplusplus
_currn = new _TPrule_76;
#else
_currn = (_TPPrule_76) TreeNodeAlloc (sizeof (struct _TPrule_76));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_76;
_currn->_desc1 = (_TSPG12) MkG12 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_76: root of subtree no. 1 can not be made a G12 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_76;
return ( (NODEPTR) _currn);
}/* Mkrule_76 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_75 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_75 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_75 _currn;
#ifdef __cplusplus
_currn = new _TPrule_75;
#else
_currn = (_TPPrule_75) TreeNodeAlloc (sizeof (struct _TPrule_75));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_75;
_currn->_desc1 = (_TSPOperation) MkOperation (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_75: root of subtree no. 1 can not be made a Operation node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_75;
return ( (NODEPTR) _currn);
}/* Mkrule_75 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_74 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_74 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_74 _currn;
#ifdef __cplusplus
_currn = new _TPrule_74;
#else
_currn = (_TPPrule_74) TreeNodeAlloc (sizeof (struct _TPrule_74));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_74;
_currn->_desc1 = (_TSPIdentification) MkIdentification (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_74: root of subtree no. 1 can not be made a Identification node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_74;
return ( (NODEPTR) _currn);
}/* Mkrule_74 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_73 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_73 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_73 _currn;
#ifdef __cplusplus
_currn = new _TPrule_73;
#else
_currn = (_TPPrule_73) TreeNodeAlloc (sizeof (struct _TPrule_73));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_73;
_currn->_desc1 = (_TSPEquivalenceClass) MkEquivalenceClass (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_73: root of subtree no. 1 can not be made a EquivalenceClass node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_73;
return ( (NODEPTR) _currn);
}/* Mkrule_73 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_72 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_72 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_72 _currn;
#ifdef __cplusplus
_currn = new _TPrule_72;
#else
_currn = (_TPPrule_72) TreeNodeAlloc (sizeof (struct _TPrule_72));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_72;
_currn->_desc1 = (_TSPClass) MkClass (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_72: root of subtree no. 1 can not be made a Class node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_72;
return ( (NODEPTR) _currn);
}/* Mkrule_72 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_71 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_71 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_71 _currn;
#ifdef __cplusplus
_currn = new _TPrule_71;
#else
_currn = (_TPPrule_71) TreeNodeAlloc (sizeof (struct _TPrule_71));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_71;
_currn->_desc1 = (_TSPG6) MkG6 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_71: root of subtree no. 1 can not be made a G6 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_71;
return ( (NODEPTR) _currn);
}/* Mkrule_71 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_70 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_70 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_70 _currn;
#ifdef __cplusplus
_currn = new _TPrule_70;
#else
_currn = (_TPPrule_70) TreeNodeAlloc (sizeof (struct _TPrule_70));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_70;
_currn->_desc1 = (_TSPG2) MkG2 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_70: root of subtree no. 1 can not be made a G2 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_70;
return ( (NODEPTR) _currn);
}/* Mkrule_70 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_69 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_69 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_69 _currn;
#ifdef __cplusplus
_currn = new _TPrule_69;
#else
_currn = (_TPPrule_69) TreeNodeAlloc (sizeof (struct _TPrule_69));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_69;
_currn->_desc1 = (_TSPG3) MkG3 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_69: root of subtree no. 1 can not be made a G3 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_69;
return ( (NODEPTR) _currn);
}/* Mkrule_69 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_68 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_68 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_68 _currn;
#ifdef __cplusplus
_currn = new _TPrule_68;
#else
_currn = (_TPPrule_68) TreeNodeAlloc (sizeof (struct _TPrule_68));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_68;
_currn->_desc1 = (_TSPG4) MkG4 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_68: root of subtree no. 1 can not be made a G4 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_68;
return ( (NODEPTR) _currn);
}/* Mkrule_68 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_67 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_67 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_67 _currn;
#ifdef __cplusplus
_currn = new _TPrule_67;
#else
_currn = (_TPPrule_67) TreeNodeAlloc (sizeof (struct _TPrule_67));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_67;
_currn->_desc1 = (_TSPG1) MkG1 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_67: root of subtree no. 1 can not be made a G1 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_67;
return ( (NODEPTR) _currn);
}/* Mkrule_67 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_66 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_66 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_66 _currn;
#ifdef __cplusplus
_currn = new _TPrule_66;
#else
_currn = (_TPPrule_66) TreeNodeAlloc (sizeof (struct _TPrule_66));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_66;
_currn->_desc1 = (_TSPG5) MkG5 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_66: root of subtree no. 1 can not be made a G5 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_66;
return ( (NODEPTR) _currn);
}/* Mkrule_66 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_65 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_65 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_65 _currn;
#ifdef __cplusplus
_currn = new _TPrule_65;
#else
_currn = (_TPPrule_65) TreeNodeAlloc (sizeof (struct _TPrule_65));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_65;
_currn->_desc1 = (_TSPG9) MkG9 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_65: root of subtree no. 1 can not be made a G9 node ", 0, _coordref);
_currn->_desc2 = (_TSPClassOper) MkClassOper (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_65: root of subtree no. 2 can not be made a ClassOper node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_65;
return ( (NODEPTR) _currn);
}/* Mkrule_65 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_64 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_64 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_64 _currn;
#ifdef __cplusplus
_currn = new _TPrule_64;
#else
_currn = (_TPPrule_64) TreeNodeAlloc (sizeof (struct _TPrule_64));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_64;
_currn->_desc1 = (_TSPClassOper) MkClassOper (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_64: root of subtree no. 1 can not be made a ClassOper node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_64;
return ( (NODEPTR) _currn);
}/* Mkrule_64 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_63 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_63 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_63 _currn;
#ifdef __cplusplus
_currn = new _TPrule_63;
#else
_currn = (_TPPrule_63) TreeNodeAlloc (sizeof (struct _TPrule_63));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_63;
_currn->_desc1 = (_TSPG8) MkG8 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_63: root of subtree no. 1 can not be made a G8 node ", 0, _coordref);
_currn->_desc2 = (_TSPClassParameter) MkClassParameter (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_63: root of subtree no. 2 can not be made a ClassParameter node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_63;
return ( (NODEPTR) _currn);
}/* Mkrule_63 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_62 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_62 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_62 _currn;
#ifdef __cplusplus
_currn = new _TPrule_62;
#else
_currn = (_TPPrule_62) TreeNodeAlloc (sizeof (struct _TPrule_62));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_62;
_currn->_desc1 = (_TSPClassParameter) MkClassParameter (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_62: root of subtree no. 1 can not be made a ClassParameter node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_62;
return ( (NODEPTR) _currn);
}/* Mkrule_62 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_61 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_61 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_61 _currn;
#ifdef __cplusplus
_currn = new _TPrule_61;
#else
_currn = (_TPPrule_61) TreeNodeAlloc (sizeof (struct _TPrule_61));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_61;
_currn->_desc1 = (_TSPG7) MkG7 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_61: root of subtree no. 1 can not be made a G7 node ", 0, _coordref);
_currn->_desc2 = (_TSPClassOperation) MkClassOperation (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_61: root of subtree no. 2 can not be made a ClassOperation node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_61;
return ( (NODEPTR) _currn);
}/* Mkrule_61 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_60 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_60 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_60 _currn;
#ifdef __cplusplus
_currn = new _TPrule_60;
#else
_currn = (_TPPrule_60) TreeNodeAlloc (sizeof (struct _TPrule_60));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_60;
_currn->_desc1 = (_TSPClassOperation) MkClassOperation (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_60: root of subtree no. 1 can not be made a ClassOperation node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_60;
return ( (NODEPTR) _currn);
}/* Mkrule_60 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_59 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_59 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_59 _currn;
#ifdef __cplusplus
_currn = new _TPrule_59;
#else
_currn = (_TPPrule_59) TreeNodeAlloc (sizeof (struct _TPrule_59));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_59;
_currn->_desc1 = (_TSPOpRef) MkOpRef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_59: root of subtree no. 1 can not be made a OpRef node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_59;
return ( (NODEPTR) _currn);
}/* Mkrule_59 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_58 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_58 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_58 _currn;
#ifdef __cplusplus
_currn = new _TPrule_58;
#else
_currn = (_TPPrule_58) TreeNodeAlloc (sizeof (struct _TPrule_58));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_58;
_currn->_desc1 = (_TSPG6) MkG6 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_58: root of subtree no. 1 can not be made a G6 node ", 0, _coordref);
_currn->_desc2 = (_TSPOpRef) MkOpRef (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_58: root of subtree no. 2 can not be made a OpRef node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_58;
return ( (NODEPTR) _currn);
}/* Mkrule_58 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_57 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_57 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_57 _currn;
#ifdef __cplusplus
_currn = new _TPrule_57;
#else
_currn = (_TPPrule_57) TreeNodeAlloc (sizeof (struct _TPrule_57));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_57;
_currn->_desc1 = (_TSPIndication) MkIndication (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_57: root of subtree no. 1 can not be made a Indication node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_57;
return ( (NODEPTR) _currn);
}/* Mkrule_57 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_56 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_56 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_56 _currn;
#ifdef __cplusplus
_currn = new _TPrule_56;
#else
_currn = (_TPPrule_56) TreeNodeAlloc (sizeof (struct _TPrule_56));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_56;
_currn->_desc1 = (_TSPG5) MkG5 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_56: root of subtree no. 1 can not be made a G5 node ", 0, _coordref);
_currn->_desc2 = (_TSPIndication) MkIndication (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_56: root of subtree no. 2 can not be made a Indication node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_56;
return ( (NODEPTR) _currn);
}/* Mkrule_56 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_55 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_55 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_55 _currn;
#ifdef __cplusplus
_currn = new _TPrule_55;
#else
_currn = (_TPPrule_55) TreeNodeAlloc (sizeof (struct _TPrule_55));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_55;
_currn->_desc1 = (_TSPOpDef) MkOpDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_55: root of subtree no. 1 can not be made a OpDef node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_55;
return ( (NODEPTR) _currn);
}/* Mkrule_55 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_54 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_54 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_54 _currn;
#ifdef __cplusplus
_currn = new _TPrule_54;
#else
_currn = (_TPPrule_54) TreeNodeAlloc (sizeof (struct _TPrule_54));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_54;
_currn->_desc1 = (_TSPG4) MkG4 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_54: root of subtree no. 1 can not be made a G4 node ", 0, _coordref);
_currn->_desc2 = (_TSPOpDef) MkOpDef (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_54: root of subtree no. 2 can not be made a OpDef node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_54;
return ( (NODEPTR) _currn);
}/* Mkrule_54 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_53 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_53 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_53 _currn;
#ifdef __cplusplus
_currn = new _TPrule_53;
#else
_currn = (_TPPrule_53) TreeNodeAlloc (sizeof (struct _TPrule_53));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_53;
_currn->_desc1 = (_TSPG3) MkG3 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_53: root of subtree no. 1 can not be made a G3 node ", 0, _coordref);
_currn->_desc2 = (_TSPCoerce) MkCoerce (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_53: root of subtree no. 2 can not be made a Coerce node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_53;
return ( (NODEPTR) _currn);
}/* Mkrule_53 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_52 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_52 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_52 _currn;
#ifdef __cplusplus
_currn = new _TPrule_52;
#else
_currn = (_TPPrule_52) TreeNodeAlloc (sizeof (struct _TPrule_52));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_52;
_currn->_desc1 = (_TSPCoerce) MkCoerce (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_52: root of subtree no. 1 can not be made a Coerce node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_52;
return ( (NODEPTR) _currn);
}/* Mkrule_52 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_51 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_51 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_51 _currn;
#ifdef __cplusplus
_currn = new _TPrule_51;
#else
_currn = (_TPPrule_51) TreeNodeAlloc (sizeof (struct _TPrule_51));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_51;
_currn->_desc1 = (_TSPOper) MkOper (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_51: root of subtree no. 1 can not be made a Oper node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_51;
return ( (NODEPTR) _currn);
}/* Mkrule_51 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_50 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_50 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_50 _currn;
#ifdef __cplusplus
_currn = new _TPrule_50;
#else
_currn = (_TPPrule_50) TreeNodeAlloc (sizeof (struct _TPrule_50));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_50;
_currn->_desc1 = (_TSPG2) MkG2 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_50: root of subtree no. 1 can not be made a G2 node ", 0, _coordref);
_currn->_desc2 = (_TSPOper) MkOper (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_50: root of subtree no. 2 can not be made a Oper node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_50;
return ( (NODEPTR) _currn);
}/* Mkrule_50 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_49 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_49 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_49 _currn;
#ifdef __cplusplus
_currn = new _TPrule_49;
#else
_currn = (_TPPrule_49) TreeNodeAlloc (sizeof (struct _TPrule_49));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_49;
_currn->_desc1 = (_TSPG1) MkG1 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_49: root of subtree no. 1 can not be made a G1 node ", 0, _coordref);
_currn->_desc2 = (_TSPSpecificationElement) MkSpecificationElement (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_49: root of subtree no. 2 can not be made a SpecificationElement node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_49;
return ( (NODEPTR) _currn);
}/* Mkrule_49 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_48 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_48 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_48 _currn;
#ifdef __cplusplus
_currn = new _TPrule_48;
#else
_currn = (_TPPrule_48) TreeNodeAlloc (sizeof (struct _TPrule_48));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_48;
_currn->_desc1 = (_TSPSingleton) MkSingleton (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_48: root of subtree no. 1 can not be made a Singleton node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_48;
return ( (NODEPTR) _currn);
}/* Mkrule_48 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_47 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_47 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_47 _currn;
#ifdef __cplusplus
_currn = new _TPrule_47;
#else
_currn = (_TPPrule_47) TreeNodeAlloc (sizeof (struct _TPrule_47));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_47;
_currn->_desc1 = (_TSPG12) MkG12 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_47: root of subtree no. 1 can not be made a G12 node ", 0, _coordref);
_currn->_desc2 = (_TSPSingleton) MkSingleton (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_47: root of subtree no. 2 can not be made a Singleton node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_47;
return ( (NODEPTR) _currn);
}/* Mkrule_47 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_46 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_46 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_46 _currn;
#ifdef __cplusplus
_currn = new _TPrule_46;
#else
_currn = (_TPPrule_46) TreeNodeAlloc (sizeof (struct _TPrule_46));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_46;
_currn->_desc1 = (_TSPG11) MkG11 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_46: root of subtree no. 1 can not be made a G11 node ", 0, _coordref);
_currn->_desc2 = (_TSPClassOpDef) MkClassOpDef (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_46: root of subtree no. 2 can not be made a ClassOpDef node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_46;
return ( (NODEPTR) _currn);
}/* Mkrule_46 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_45 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_45 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_45 _currn;
#ifdef __cplusplus
_currn = new _TPrule_45;
#else
_currn = (_TPPrule_45) TreeNodeAlloc (sizeof (struct _TPrule_45));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_45;
_currn->_desc1 = (_TSPClassOpDef) MkClassOpDef (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_45: root of subtree no. 1 can not be made a ClassOpDef node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_45;
return ( (NODEPTR) _currn);
}/* Mkrule_45 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_44 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_44 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_44 _currn;
#ifdef __cplusplus
_currn = new _TPrule_44;
#else
_currn = (_TPPrule_44) TreeNodeAlloc (sizeof (struct _TPrule_44));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_44;
_currn->_desc1 = (_TSPG10) MkG10 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_44: root of subtree no. 1 can not be made a G10 node ", 0, _coordref);
_currn->_desc2 = (_TSPClassCoerce) MkClassCoerce (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_44: root of subtree no. 2 can not be made a ClassCoerce node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_44;
return ( (NODEPTR) _currn);
}/* Mkrule_44 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_43 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_43 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_43 _currn;
#ifdef __cplusplus
_currn = new _TPrule_43;
#else
_currn = (_TPPrule_43) TreeNodeAlloc (sizeof (struct _TPrule_43));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_43;
_currn->_desc1 = (_TSPClassCoerce) MkClassCoerce (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_43: root of subtree no. 1 can not be made a ClassCoerce node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_43;
return ( (NODEPTR) _currn);
}/* Mkrule_43 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_42 (POSITION *_coordref)
#else
NODEPTR Mkrule_42 (_coordref)
	POSITION *_coordref;
#endif
{	_TPPrule_42 _currn;
#ifdef __cplusplus
_currn = new _TPrule_42;
#else
_currn = (_TPPrule_42) TreeNodeAlloc (sizeof (struct _TPrule_42));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_42;
_SETCOORD(_currn)
_TERMACT_rule_42;
return ( (NODEPTR) _currn);
}/* Mkrule_42 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_41 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_41 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_41 _currn;
#ifdef __cplusplus
_currn = new _TPrule_41;
#else
_currn = (_TPPrule_41) TreeNodeAlloc (sizeof (struct _TPrule_41));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_41;
_currn->_desc1 = (_TSPG8) MkG8 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_41: root of subtree no. 1 can not be made a G8 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_41;
return ( (NODEPTR) _currn);
}/* Mkrule_41 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_40 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_40 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_40 _currn;
#ifdef __cplusplus
_currn = new _TPrule_40;
#else
_currn = (_TPPrule_40) TreeNodeAlloc (sizeof (struct _TPrule_40));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_40;
_currn->_desc1 = (_TSPG9) MkG9 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_40: root of subtree no. 1 can not be made a G9 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_40;
return ( (NODEPTR) _currn);
}/* Mkrule_40 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_39 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_39 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_39 _currn;
#ifdef __cplusplus
_currn = new _TPrule_39;
#else
_currn = (_TPPrule_39) TreeNodeAlloc (sizeof (struct _TPrule_39));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_39;
_currn->_desc1 = (_TSPG10) MkG10 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_39: root of subtree no. 1 can not be made a G10 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_39;
return ( (NODEPTR) _currn);
}/* Mkrule_39 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_38 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_38 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_38 _currn;
#ifdef __cplusplus
_currn = new _TPrule_38;
#else
_currn = (_TPPrule_38) TreeNodeAlloc (sizeof (struct _TPrule_38));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_38;
_currn->_desc1 = (_TSPG11) MkG11 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_38: root of subtree no. 1 can not be made a G11 node ", 0, _coordref);
_COPYCOORD(_currn)
_TERMACT_rule_38;
return ( (NODEPTR) _currn);
}/* Mkrule_38 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_37 (POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2)
#else
NODEPTR Mkrule_37 (_coordref,_desc1,_desc2)
	POSITION *_coordref;
	NODEPTR _desc1;
	NODEPTR _desc2;
#endif
{	_TPPrule_37 _currn;
#ifdef __cplusplus
_currn = new _TPrule_37;
#else
_currn = (_TPPrule_37) TreeNodeAlloc (sizeof (struct _TPrule_37));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_37;
_currn->_desc1 = (_TSPClassParameters) MkClassParameters (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_37: root of subtree no. 1 can not be made a ClassParameters node ", 0, _coordref);
_currn->_desc2 = (_TSPG7) MkG7 (_coordref, _desc2);	
if (((NODEPTR)_currn->_desc2) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_37: root of subtree no. 2 can not be made a G7 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_37;
return ( (NODEPTR) _currn);
}/* Mkrule_37 */

#if defined(__STDC__) || defined(__cplusplus)
NODEPTR Mkrule_36 (POSITION *_coordref, NODEPTR _desc1)
#else
NODEPTR Mkrule_36 (_coordref,_desc1)
	POSITION *_coordref;
	NODEPTR _desc1;
#endif
{	_TPPrule_36 _currn;
#ifdef __cplusplus
_currn = new _TPrule_36;
#else
_currn = (_TPPrule_36) TreeNodeAlloc (sizeof (struct _TPrule_36));
#endif
#ifdef MONITOR
_currn->_uid=MONTblStackSize; MONTblStackPush(((NODEPTR)_currn));
#endif
_currn->_prod = RULErule_36;
_currn->_desc1 = (_TSPG7) MkG7 (_coordref, _desc1);	
if (((NODEPTR)_currn->_desc1) == NULLNODEPTR)	
	message (DEADLY, "RULE rule_36: root of subtree no. 1 can not be made a G7 node ", 0, _coordref);
_SETCOORD(_currn)
_TERMACT_rule_36;
return ( (NODEPTR) _currn);
}/* Mkrule_36 */
