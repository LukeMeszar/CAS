
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBVariableDeclList 0
#define SYMBStatementList 1
#define SYMBAxiom 2
#define SYMBOptInitialize 3
#define SYMBVarIdList 4
#define SYMBVariableDeclSeg 5
#define SYMBParameterDecl 6
#define SYMBVariableDecl 7
#define SYMBUnop 8
#define SYMBBinop 9
#define SYMBNotop 10
#define SYMBShortCircuitOp 11
#define SYMBParameterList 12
#define SYMBResultType 13
#define SYMBWhileStmt 14
#define SYMBExpression 15
#define SYMBStatement 16
#define SYMBCompound 17
#define SYMBProgram 18
#define SYMBIdUse 19
#define SYMBIdDef 20
#define RULEAssignExp 0
#define RULECondExp 1
#define RULEShortCircuitExp 2
#define RULENotExp 3
#define RULEIntVal 4
#define RULEFloatVal 5
#define RULEIdnVal 6
#define RULEDyadicExp 7
#define RULEMonadicExp 8
#define RULEDefiningOccurrence 9
#define RULEOneSided 10
#define RULETwoSided 11
#define RULELoop 12
#define RULEBreakStmt 13
#define RULEContinueStmt 14
#define RULEReturnStmt 15
#define RULESource 16
#define RULEExprStmt 17
#define RULEBarOp 18
#define RULEAmpOp 19
#define RULEExclOp 20
#define RULEEqualOp 21
#define RULELessOp 22
#define RULEGreaterOp 23
#define RULEPlusOp 24
#define RULEMinusOp 25
#define RULEStarOp 26
#define RULESlashOp 27
#define RULEPercentOp 28
#define RULEUMinusOp 29
#define RULEIntVar 30
#define RULEFloatVar 31
#define RULEVarDecl 32
#define RULEInitialize 33
#define RULEIntParDecl 34
#define RULEFloatParDecl 35
#define RULErule_2 36
#define RULErule_3 37
#define RULErule_4 38
#define RULErule_5 39
#define RULErule_6 40
#define RULErule_7 41
#define RULErule_8 42
#define RULErule_9 43
#define RULErule_10 44
#define RULErule_11 45
#define RULErule_12 46
#define RULErule_13 47
#define RULErule_14 48
#define RULErule_15 49
#define RULEAppliedOccurrence 50
#define RULEIntResult 51
#define RULEFloatResult 52
#define RULErule_1 53
#endif
