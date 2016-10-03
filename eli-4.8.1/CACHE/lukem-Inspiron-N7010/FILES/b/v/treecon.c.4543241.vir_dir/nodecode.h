
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBparams 0
#define SYMBoptparams 1
#define SYMBoptattrs 2
#define SYMBattrs 3
#define SYMBtranslation_sig 4
#define SYMBiduse 5
#define SYMBsig 6
#define SYMBattr 7
#define SYMBevent_block 8
#define SYMBexport 9
#define SYMBevent_sig 10
#define SYMBsigs 11
#define SYMBaspect_stmt 12
#define SYMBaspects 13
#define SYMBspec 14
#define SYMBparam 15
#define SYMBtypeid 16
#define SYMBbody 17
#define SYMBoperation_block 18
#define SYMBiddef 19
#define SYMBoperation_sig 20
#define RULErule_12 0
#define RULErule_13 1
#define RULErule_26 2
#define RULErule_27 3
#define RULErule_28 4
#define RULErule_29 5
#define RULErule_30 6
#define RULErule_10 7
#define RULErule_5 8
#define RULErule_4 9
#define RULEoperation_sig1 10
#define RULEoperation_sig2 11
#define RULErule_14 12
#define RULErule_15 13
#define RULErule_17 14
#define RULErule_20 15
#define RULErule_21 16
#define RULErule_22 17
#define RULErule_23 18
#define RULErule_24 19
#define RULErule_25 20
#define RULErule_9 21
#define RULErule_6 22
#define RULErule_2 23
#define RULErule_1 24
#define RULErule_16 25
#define RULErule_18 26
#define RULErule_19 27
#define RULErule_31 28
#define RULErule_11 29
#define RULErule_8 30
#define RULErule_7 31
#define RULErule_3 32
#endif
