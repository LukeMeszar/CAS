
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBLST_Source 0
#define SYMBLST_Nonterms 1
#define SYMBChildren 2
#define SYMBTerminal 3
#define SYMBFunction 4
#define SYMBChild 5
#define SYMBSymbolUse 6
#define SYMBCost 7
#define SYMBSignature 8
#define SYMBSymbolDef 9
#define SYMBType 10
#define SYMBNonterms 11
#define SYMBPattern 12
#define SYMBDeclaration 13
#define SYMBInclude 14
#define SYMBSource 15
#define RULErule_12 0
#define RULErule_11 1
#define RULErule_10 2
#define RULErule_9 3
#define RULErule_8 4
#define RULErule_15 5
#define RULErule_14 6
#define RULErule_13 7
#define RULELST_0rule_19 8
#define RULELST_Includerule_19 9
#define RULELST_Declarationrule_19 10
#define RULELST_Patternrule_19 11
#define RULErule_18 12
#define RULErule_17 13
#define RULErule_16 14
#define RULErule_4 15
#define RULErule_3 16
#define RULErule_2 17
#define RULErule_1 18
#define RULELST_0rule_16 19
#define RULELST_SymbolDefrule_16 20
#define RULErule_19 21
#define RULErule_7 22
#define RULErule_6 23
#define RULErule_5 24
#endif
