
#ifndef _tOilOpLIST_H
#define _tOilOpLIST_H

/* include header file defining tOilOp if oiladt2 is set: */
#define EMPTYoiladt2HDR
#ifndef EMPTYHDR
#include "oiladt2.h"
#endif
#undef EMPTYoiladt2HDR

#include "VoidPtrList.h"

typedef VoidPtrList     tOilOpList;
typedef VoidPtrList    *tOilOpListPtr;
typedef VoidPtrCmpFctType     tOilOpCmpFctType;

#define NULLtOilOpList          ((tOilOpList)0)
#define NulltOilOpList()        ((tOilOpList)0)
#define SingletOilOpList(e)     (ConstOilOpList((e),NULLtOilOpList))

#define FinltOilOpList          FinlVoidPtrList

#define ConstOilOpList(e,l)     ConsVoidPtrList ((VoidPtr)(e),(l))

#define HeadtOilOpList(l)       ((tOilOp)(HeadVoidPtrList (l)))

#define TailtOilOpList(l)       TailVoidPtrList (l)

#define LengthtOilOpList(l)     LengthVoidPtrList (l)

#define IthElemtOilOpList(l,i)  ((tOilOp)(IthElemVoidPtrList (l, i)))

#define CopytOilOpList(l,cp)    CopyVoidPtrList (l, cp)

#define ApptOilOpList(l1,l2)    AppVoidPtrList (l1, l2)

#define AppEltOilOpList(l,e)    AppElVoidPtrList (l, (VoidPtr)e)

#define InsertAftertOilOpList(l,e) \
        InsertAfterVoidPtrList (l, (VoidPtr)e)

#define OrderedInserttOilOpList(l,e,fcmp) \
        OrderedInsertVoidPtrList (l, (VoidPtr)e, (VoidPtrCmpFctType)fcmp)

#define RefEndConstOilOpList(addr,e) \
        RefEndConsVoidPtrList (addr, (VoidPtr)e)

#define RefEndApptOilOpList(addr,l) \
        RefEndAppVoidPtrList (addr, l)

#define ElemIntOilOpList(e,l,cmpfct) \
        ElemInVoidPtrList ((VoidPtr)e, l, (VoidPtrCmpFctType)cmpfct)

#define AddToSettOilOpList(e,l,cmpfct) \
        AddToSetVoidPtrList ((VoidPtr)e, l, (VoidPtrCmpFctType)cmpfct)

#define AddToOrderedSettOilOpList(e,l,cmpfct) \
        AddToOrderedSetVoidPtrList ((VoidPtr)e, l, (VoidPtrCmpFctType)cmpfct)

#define MaptOilOpList(l,f) \
        MapVoidPtrList (l,(VoidPtrMapFct)f)

#define ComptOilOpList(l1,l2,f) \
        CompVoidPtrList (l1, l2, (VoidPtrCmpFctType)f)

#define SumtOilOpList(l,f,a) \
        SumVoidPtrList (l, (VoidPtrSumFct)f, (VoidPtr)a)

#ifdef MONITOR
#define DAPTO_RESULTtOilOpList(l) DAPTO_RESULT_PTR(l)
#define DAPTO_ARGtOilOpList(l)    DAPTO_ARG_PTR (l, tOilOpList)
#endif

#endif
