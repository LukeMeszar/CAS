
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBLST_xGrammar 0
#define SYMBLST_xRHS 1
#define SYMBLST_Syms 2
#define SYMBLST_Items 3
#define SYMBPTGSpec 4
#define SYMBG2 5
#define SYMBxRoot 6
#define SYMBItem 7
#define SYMBItems 8
#define SYMBPatternName 9
#define SYMBPatternSpec 10
#define SYMBElement 11
#define SYMBSyms 12
#define SYMBxRHS 13
#define SYMBxSymbol 14
#define SYMBxRule 15
#define SYMBxProduction 16
#define SYMBxGrammar 17
#define RULErule_25 0
#define RULErule_26 1
#define RULErule_15 2
#define RULErule_13 3
#define RULErule_12 4
#define RULErule_11 5
#define RULELST_0rule_15 6
#define RULELST_Elementrule_15 7
#define RULErule_19 8
#define RULErule_20 9
#define RULErule_21 10
#define RULErule_18 11
#define RULErule_17 12
#define RULErule_16 13
#define RULErule_14 14
#define RULErule_10 15
#define RULErule_9 16
#define RULELST_0rule_14 17
#define RULELST_xSymbolrule_14 18
#define RULELST_0rule_18 19
#define RULELST_xProductionrule_18 20
#define RULErule_22 21
#define RULErule_23 22
#define RULErule_24 23
#define RULErule_8 24
#define RULErule_7 25
#define RULErule_6 26
#define RULErule_5 27
#define RULErule_4 28
#define RULErule_3 29
#define RULErule_2 30
#define RULErule_1 31
#define RULELST_0rule_8 32
#define RULELST_Itemrule_8 33
#endif
