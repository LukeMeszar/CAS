
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBtype 0
#define SYMBjoin 1
#define SYMBliterals 2
#define SYMBname 3
#define SYMBtparam 4
#define SYMBparam 5
#define SYMBdoc 6
#define SYMBliteral 7
#define SYMBparams 8
#define SYMBspec 9
#define RULErule_22 0
#define RULErule_23 1
#define RULErule_24 2
#define RULErule_25 3
#define RULErule_26 4
#define RULErule_27 5
#define RULErule_20 6
#define RULErule_19 7
#define RULErule_9 8
#define RULErule_8 9
#define RULErule_7 10
#define RULErule_6 11
#define RULErule_5 12
#define RULErule_4 13
#define RULErule_21 14
#define RULErule_18 15
#define RULErule_17 16
#define RULErule_16 17
#define RULErule_15 18
#define RULErule_14 19
#define RULErule_13 20
#define RULErule_12 21
#define RULErule_11 22
#define RULErule_10 23
#define RULErule_3 24
#define RULErule_2 25
#define RULErule_1 26
#endif
