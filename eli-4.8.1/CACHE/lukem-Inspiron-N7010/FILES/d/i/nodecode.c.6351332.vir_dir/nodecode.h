
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBOperation 0
#define SYMBIdentification 1
#define SYMBG6 2
#define SYMBG5 3
#define SYMBG4 4
#define SYMBG3 5
#define SYMBG2 6
#define SYMBSpecificationElement 7
#define SYMBG12 8
#define SYMBG1 9
#define SYMBG8 10
#define SYMBG9 11
#define SYMBG10 12
#define SYMBClassOperation 13
#define SYMBG11 14
#define SYMBG7 15
#define SYMBClassCoerce 16
#define SYMBClassOpDefList 17
#define SYMBClassOper 18
#define SYMBClassSignature 19
#define SYMBClassParameters 20
#define SYMBClass 21
#define SYMBOpRefList 22
#define SYMBIndication 23
#define SYMBCoerce 24
#define SYMBOpDefList 25
#define SYMBOper 26
#define SYMBSignatureElement 27
#define SYMBSignature 28
#define SYMBSingleton 29
#define SYMBxTypeList 30
#define SYMBxTypeExpr 31
#define SYMBEquivalenceClass 32
#define SYMBClassBody 33
#define SYMBOIL 34
#define SYMBSetIdUse 35
#define SYMBSetIdDef 36
#define SYMBOpRef 37
#define SYMBIndDef 38
#define SYMBClassParameter 39
#define SYMBClassName 40
#define SYMBTypeIdentifier 41
#define SYMBClassOpDef 42
#define SYMBOpDef 43
#define SYMBCostSpecification 44
#define RULErule_42 0
#define RULErule_49 1
#define RULErule_72 2
#define RULErule_73 3
#define RULErule_74 4
#define RULErule_75 5
#define RULErule_11 6
#define RULErule_38 7
#define RULErule_45 8
#define RULErule_46 9
#define RULErule_54 10
#define RULErule_55 11
#define RULErule_56 12
#define RULErule_57 13
#define RULErule_66 14
#define RULErule_68 15
#define RULErule_33 16
#define RULErule_32 17
#define RULErule_31 18
#define RULErule_30 19
#define RULErule_29 20
#define RULErule_15 21
#define RULErule_14 22
#define RULErule_13 23
#define RULErule_12 24
#define RULErule_8 25
#define RULErule_6 26
#define RULErule_5 27
#define RULErule_4 28
#define RULErule_3 29
#define RULErule_36 30
#define RULErule_37 31
#define RULErule_39 32
#define RULErule_40 33
#define RULErule_43 34
#define RULErule_44 35
#define RULErule_47 36
#define RULErule_48 37
#define RULErule_50 38
#define RULErule_51 39
#define RULErule_52 40
#define RULErule_53 41
#define RULErule_60 42
#define RULErule_61 43
#define RULErule_64 44
#define RULErule_65 45
#define RULErule_69 46
#define RULErule_70 47
#define RULErule_76 48
#define RULErule_28 49
#define RULErule_26 50
#define RULErule_22 51
#define RULErule_21 52
#define RULErule_20 53
#define RULErule_19 54
#define RULErule_18 55
#define RULErule_17 56
#define RULErule_16 57
#define RULErule_10 58
#define RULErule_9 59
#define RULErule_7 60
#define RULErule_2 61
#define RULErule_1 62
#define RULErule_41 63
#define RULErule_62 64
#define RULErule_63 65
#define RULErule_27 66
#define RULErule_24 67
#define RULErule_58 68
#define RULErule_59 69
#define RULErule_67 70
#define RULErule_71 71
#define RULErule_35 72
#define RULErule_34 73
#define RULErule_25 74
#define RULErule_23 75
#endif
