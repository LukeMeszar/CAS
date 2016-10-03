
/* interface of tree construction functions */

#ifndef TREECON_H
#define TREECON_H
#include "eliproto.h"

#include "err.h"

#include "nodeptr.h"

#include "HEAD.h"


extern void InitTree ELI_ARG((void));

extern void FreeTree ELI_ARG((void));

extern NODEPTR MkOperation ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkIdentification ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG6 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG5 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG4 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG3 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG2 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSpecificationElement ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG12 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG1 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG8 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG9 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG10 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassOperation ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG11 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkG7 ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassCoerce ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassOpDefList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassOper ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassSignature ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassParameters ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClass ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOpRefList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkIndication ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkCoerce ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOpDefList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOper ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSignatureElement ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSignature ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSingleton ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxTypeList ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkxTypeExpr ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkEquivalenceClass ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassBody ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOIL ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSetIdUse ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkSetIdDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOpRef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkIndDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassParameter ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassName ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkTypeIdentifier ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkClassOpDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkOpDef ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR MkCostSpecification ELI_ARG((POSITION *_coordref, NODEPTR _currn));
extern NODEPTR Mkrule_1 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_2 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_3 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_4 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_5 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_6 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_7 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_8 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_9 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_10 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2, NODEPTR _desc3));
extern NODEPTR Mkrule_11 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_12 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_13 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_14 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_15 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_16 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_17 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_18 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_19 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_20 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_21 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_22 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_23 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_24 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_25 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_26 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_27 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_28 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_29 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_30 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_31 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_32 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_33 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_34 ELI_ARG((POSITION *_coordref, int _TERM1));
extern NODEPTR Mkrule_35 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_76 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_75 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_74 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_73 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_72 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_71 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_70 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_69 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_68 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_67 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_66 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_65 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_64 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_63 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_62 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_61 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_60 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_59 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_58 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_57 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_56 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_55 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_54 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_53 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_52 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_51 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_50 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_49 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_48 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_47 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_46 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_45 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_44 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_43 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_42 ELI_ARG((POSITION *_coordref));
extern NODEPTR Mkrule_41 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_40 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_39 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_38 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
extern NODEPTR Mkrule_37 ELI_ARG((POSITION *_coordref, NODEPTR _desc1, NODEPTR _desc2));
extern NODEPTR Mkrule_36 ELI_ARG((POSITION *_coordref, NODEPTR _desc1));
#define MkInteger(pos,val) (val)
#define MkIdentifier(pos,val) (val)
#endif
