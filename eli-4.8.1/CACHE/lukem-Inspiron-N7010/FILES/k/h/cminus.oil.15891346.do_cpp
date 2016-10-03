# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/g/cminus.oil.15868420.oil"


INDICATION Equal:
  IntegerAssignment, TruncatingAssignment, FloatingAssignment;
OPER IntegerAssignment(int_t,int_t): int_t;
OPER TruncatingAssignment(int_t,float_t): int_t;
OPER FloatingAssignment(float_t,float_t): float_t;

INDICATION BarBar: Disjunction;
OPER Disjunction(int_t,int_t): int_t;

INDICATION AmpAmp: Conjunction;
OPER Conjunction(int_t,int_t): int_t;

INDICATION Exclam: Complement;
OPER Complement(int_t): int_t;

INDICATION EquEqu: IntEqual, FloatEqual;
OPER IntEqual(int_t,int_t): int_t;
OPER FloatEqual(float_t,float_t): int_t;

INDICATION Less: IntLess, FloatLess;
OPER IntLess(int_t,int_t): int_t;
OPER FloatLess(float_t,float_t): int_t;

INDICATION Greater: IntGreater, FloatGreater;
OPER IntGreater(int_t,int_t): int_t;
OPER FloatGreater(float_t,float_t): int_t;

INDICATION Plus: IntegerAddition, FloatingAddition;
OPER IntegerAddition(int_t,int_t): int_t;
OPER FloatingAddition(float_t,float_t): float_t;

INDICATION Minus: IntegerSubtraction, FloatingSubtraction;
OPER IntegerSubtraction(int_t,int_t): int_t;
OPER FloatingSubtraction(float_t,float_t): float_t;

INDICATION Star: IntegerMultiplication, FloatingMultiplication;
OPER IntegerMultiplication(int_t,int_t): int_t;
OPER FloatingMultiplication(float_t,float_t): float_t;

INDICATION Slash: IntegerDivision, FloatingDivision;
OPER IntegerDivision(int_t,int_t): int_t;
OPER FloatingDivision(float_t,float_t): float_t;

INDICATION Percent: Remainder;
OPER Remainder(int_t,int_t): int_t;

INDICATION UMinus: IntegerNegation, FloatingNegation;
OPER IntegerNegation(int_t): int_t;
OPER FloatingNegation(float_t): float_t;

INDICATION Return: IntOutput, FloatOutput;
OPER IntOutput(int_t): int_t;
OPER FloatOutput(float_t): float_t;


COERCION IntToFloat(int_t): float_t;
COERCION IntToVoid(int_t): void_t;
COERCION FloatToVoid(float_t): void_t;

COERCION UnkI(unknown_t):int_t;
COERCION UnkF(unknown_t):float_t;
