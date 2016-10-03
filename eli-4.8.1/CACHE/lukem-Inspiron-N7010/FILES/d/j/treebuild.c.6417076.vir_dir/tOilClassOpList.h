
#ifndef _tOilClassOpLIST_H
#define _tOilClassOpLIST_H

/* include header file defining tOilClassOp if oiladt2 is set: */
#define EMPTYoiladt2HDR
#ifndef EMPTYHDR
#include "oiladt2.h"
#endif
#undef EMPTYoiladt2HDR

#include "VoidPtrList.h"

typedef VoidPtrList     tOilClassOpList;
typedef VoidPtrList    *tOilClassOpListPtr;
typedef VoidPtrCmpFctType     tOilClassOpCmpFctType;

#define NULLtOilClassOpList             ((tOilClassOpList)0)
#define NulltOilClassOpList()   ((tOilClassOpList)0)
#define SingletOilClassOpList(e)        (ConstOilClassOpList((e),NULLtOilClassOpList))

#define FinltOilClassOpList             FinlVoidPtrList

#define ConstOilClassOpList(e,l)        ConsVoidPtrList ((VoidPtr)(e),(l))

#define HeadtOilClassOpList(l)  ((tOilClassOp)(HeadVoidPtrList (l)))

#define TailtOilClassOpList(l)  TailVoidPtrList (l)

#define LengthtOilClassOpList(l)        LengthVoidPtrList (l)

#define IthElemtOilClassOpList(l,i)     ((tOilClassOp)(IthElemVoidPtrList (l, i)))

#define CopytOilClassOpList(l,cp)       CopyVoidPtrList (l, cp)

#define ApptOilClassOpList(l1,l2)       AppVoidPtrList (l1, l2)

#define AppEltOilClassOpList(l,e)       AppElVoidPtrList (l, (VoidPtr)e)

#define InsertAftertOilClassOpList(l,e) \
        InsertAfterVoidPtrList (l, (VoidPtr)e)

#define OrderedInserttOilClassOpList(l,e,fcmp) \
        OrderedInsertVoidPtrList (l, (VoidPtr)e, (VoidPtrCmpFctType)fcmp)

#define RefEndConstOilClassOpList(addr,e) \
        RefEndConsVoidPtrList (addr, (VoidPtr)e)

#define RefEndApptOilClassOpList(addr,l) \
        RefEndAppVoidPtrList (addr, l)

#define ElemIntOilClassOpList(e,l,cmpfct) \
        ElemInVoidPtrList ((VoidPtr)e, l, (VoidPtrCmpFctType)cmpfct)

#define AddToSettOilClassOpList(e,l,cmpfct) \
        AddToSetVoidPtrList ((VoidPtr)e, l, (VoidPtrCmpFctType)cmpfct)

#define AddToOrderedSettOilClassOpList(e,l,cmpfct) \
        AddToOrderedSetVoidPtrList ((VoidPtr)e, l, (VoidPtrCmpFctType)cmpfct)

#define MaptOilClassOpList(l,f) \
        MapVoidPtrList (l,(VoidPtrMapFct)f)

#define ComptOilClassOpList(l1,l2,f) \
        CompVoidPtrList (l1, l2, (VoidPtrCmpFctType)f)

#define SumtOilClassOpList(l,f,a) \
        SumVoidPtrList (l, (VoidPtrSumFct)f, (VoidPtr)a)

#ifdef MONITOR
#define DAPTO_RESULTtOilClassOpList(l) DAPTO_RESULT_PTR(l)
#define DAPTO_ARGtOilClassOpList(l)    DAPTO_ARG_PTR (l, tOilClassOpList)
#endif

#endif
