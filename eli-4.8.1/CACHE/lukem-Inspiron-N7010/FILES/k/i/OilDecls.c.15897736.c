#include "pdl_gen.h"
#include "oiladt2.h"


  extern struct Stype Oil_t3;

  extern struct Ssig Oil_s45;

  extern struct Ssig Oil_s5;
struct Ssig Oil_s42={ 42, 0, (tOilArgSig)&Oil_s5, (tOilType)&Oil_t3, (tOilArgSig)0 };
struct Sop Oil_o43={ 43, 0, IntToVoid, 1, (tOilArgSig)&Oil_s42, (tOilOp)0, (tOilOpIdentification)0 };
struct Sop Oil_o46={ 46, 0, FloatToVoid, 1, (tOilArgSig)&Oil_s45, (tOilOp)&Oil_o43, (tOilOpIdentification)0 };
struct ScoercionSeq Oil_cc47={ 47, 0, (tOilType)&Oil_t3, (tOilCoercionSeq)0, (tOilOp)&Oil_o46, (tOilCoercionSeq)0, 1 };

  extern struct Stype Oil_t2;

  extern struct Stype Oil_t1;

  extern struct Ssig Oil_s48;

  extern struct Ssig Oil_s9;
struct Ssig Oil_s13={ 13, 0, (tOilArgSig)&Oil_s9, (tOilType)&Oil_t2, (tOilArgSig)&Oil_s9 };

  extern struct Ssig Oil_s7;
struct Ssig Oil_s10={ 10, 0, (tOilArgSig)&Oil_s9, (tOilType)&Oil_t1, (tOilArgSig)&Oil_s7 };
struct Ssig Oil_s11={ 11, 0, (tOilArgSig)&Oil_s10, (tOilType)&Oil_t1, (tOilArgSig)&Oil_s10 };
struct Ssig Oil_s20={ 20, 0, (tOilArgSig)&Oil_s13, (tOilType)&Oil_t1, (tOilArgSig)&Oil_s11 };
struct Ssig Oil_s49={ 49, 0, (tOilArgSig)&Oil_s48, (tOilType)&Oil_t1, (tOilArgSig)&Oil_s20 };
struct Sop Oil_o50={ 50, 0, UnkI, 1, (tOilArgSig)&Oil_s49, (tOilOp)0, (tOilOpIdentification)0 };
struct ScoercionSeq Oil_cc51={ 51, 0, (tOilType)&Oil_t1, (tOilCoercionSeq)0, (tOilOp)&Oil_o50, (tOilCoercionSeq)0, 1 };

  extern struct ScoercionSeq Oil_cc44;
struct ScoercionSeq Oil_cc52={ 52, 0, (tOilType)&Oil_t3, (tOilCoercionSeq)&Oil_cc51, (tOilOp)&Oil_o50, (tOilCoercionSeq)&Oil_cc44, 2 };

  extern struct Ssig Oil_s54;
struct Ssig Oil_s14={ 14, 0, (tOilArgSig)&Oil_s13, (tOilType)&Oil_t2, (tOilArgSig)&Oil_s13 };
struct Ssig Oil_s39={ 39, 0, (tOilArgSig)&Oil_s5, (tOilType)&Oil_t2, (tOilArgSig)&Oil_s14 };
struct Sop Oil_o40={ 40, 0, IntToFloat, 1, (tOilArgSig)&Oil_s39, (tOilOp)0, (tOilOpIdentification)0 };
struct Sop Oil_o55={ 55, 0, UnkF, 1, (tOilArgSig)&Oil_s54, (tOilOp)&Oil_o40, (tOilOpIdentification)0 };
struct ScoercionSeq Oil_cc53={ 53, 0, (tOilType)&Oil_t2, (tOilCoercionSeq)&Oil_cc52, (tOilOp)&Oil_o55, (tOilCoercionSeq)0, 1 };
struct Stype Oil_t4={ 4, 0, unknown_t, (tOilCoercionSeq)&Oil_cc53, (tOilArgSig)&Oil_s48, (tOilTypeSet)0, (tOilOp)0 };
struct Ssig Oil_s48={ 48, 0, (tOilArgSig)0, (tOilType)&Oil_t4, (tOilArgSig)0 };
struct Ssig Oil_s54={ 54, 0, (tOilArgSig)&Oil_s48, (tOilType)&Oil_t2, (tOilArgSig)&Oil_s39 };
struct Stype Oil_t2={ 2, 0, float_t, (tOilCoercionSeq)&Oil_cc47, (tOilArgSig)&Oil_s54, (tOilTypeSet)0, (tOilOp)&Oil_o55 };
struct Ssig Oil_s9={ 9, 0, (tOilArgSig)0, (tOilType)&Oil_t2, (tOilArgSig)0 };
struct Ssig Oil_s45={ 45, 0, (tOilArgSig)&Oil_s9, (tOilType)&Oil_t3, (tOilArgSig)&Oil_s42 };
struct Stype Oil_t3={ 3, 0, void_t, (tOilCoercionSeq)0, (tOilArgSig)&Oil_s45, (tOilTypeSet)0, (tOilOp)&Oil_o46 };
struct ScoercionSeq Oil_cc41={ 41, 0, (tOilType)&Oil_t2, (tOilCoercionSeq)0, (tOilOp)&Oil_o40, (tOilCoercionSeq)0, 1 };
struct ScoercionSeq Oil_cc44={ 44, 0, (tOilType)&Oil_t3, (tOilCoercionSeq)&Oil_cc41, (tOilOp)&Oil_o43, (tOilCoercionSeq)0, 1 };
struct Stype Oil_t1={ 1, 0, int_t, (tOilCoercionSeq)&Oil_cc44, (tOilArgSig)&Oil_s49, (tOilTypeSet)0, (tOilOp)&Oil_o50 };
struct Ssig Oil_s5={ 5, 0, (tOilArgSig)0, (tOilType)&Oil_t1, (tOilArgSig)0 };
struct Ssig Oil_s6={ 6, 0, (tOilArgSig)&Oil_s5, (tOilType)&Oil_t1, (tOilArgSig)&Oil_s5 };
struct Ssig Oil_s7={ 7, 0, (tOilArgSig)&Oil_s6, (tOilType)&Oil_t1, (tOilArgSig)&Oil_s6 };
struct Sop Oil_o8={ 8, 0, IntegerAssignment, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid70={ 70, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o8 };
struct Sop Oil_o12={ 12, 0, TruncatingAssignment, 1, (tOilArgSig)&Oil_s11, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid71={ 71, 0, (tOilOpIdentification)&Oil_oid70, (tOilOp)&Oil_o12 };
struct Sop Oil_o15={ 15, 0, FloatingAssignment, 1, (tOilArgSig)&Oil_s14, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid72={ 72, 0, (tOilOpIdentification)&Oil_oid71, (tOilOp)&Oil_o15 };
struct Sop Oil_o56={ 56, 0, Equal, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid72 };
struct Sop Oil_o16={ 16, 0, Disjunction, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid73={ 73, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o16 };
struct Sop Oil_o57={ 57, 0, BarBar, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid73 };
struct Sop Oil_o17={ 17, 0, Conjunction, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid74={ 74, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o17 };
struct Sop Oil_o58={ 58, 0, AmpAmp, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid74 };
struct Sop Oil_o18={ 18, 0, Complement, 1, (tOilArgSig)&Oil_s6, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid75={ 75, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o18 };
struct Sop Oil_o59={ 59, 0, Exclam, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid75 };
struct Sop Oil_o19={ 19, 0, IntEqual, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid76={ 76, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o19 };
struct Sop Oil_o21={ 21, 0, FloatEqual, 1, (tOilArgSig)&Oil_s20, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid77={ 77, 0, (tOilOpIdentification)&Oil_oid76, (tOilOp)&Oil_o21 };
struct Sop Oil_o60={ 60, 0, EquEqu, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid77 };
struct Sop Oil_o22={ 22, 0, IntLess, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid78={ 78, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o22 };
struct Sop Oil_o23={ 23, 0, FloatLess, 1, (tOilArgSig)&Oil_s20, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid79={ 79, 0, (tOilOpIdentification)&Oil_oid78, (tOilOp)&Oil_o23 };
struct Sop Oil_o61={ 61, 0, Less, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid79 };
struct Sop Oil_o24={ 24, 0, IntGreater, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid80={ 80, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o24 };
struct Sop Oil_o25={ 25, 0, FloatGreater, 1, (tOilArgSig)&Oil_s20, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid81={ 81, 0, (tOilOpIdentification)&Oil_oid80, (tOilOp)&Oil_o25 };
struct Sop Oil_o62={ 62, 0, Greater, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid81 };
struct Sop Oil_o26={ 26, 0, IntegerAddition, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid82={ 82, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o26 };
struct Sop Oil_o27={ 27, 0, FloatingAddition, 1, (tOilArgSig)&Oil_s14, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid83={ 83, 0, (tOilOpIdentification)&Oil_oid82, (tOilOp)&Oil_o27 };
struct Sop Oil_o63={ 63, 0, Plus, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid83 };
struct Sop Oil_o28={ 28, 0, IntegerSubtraction, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid84={ 84, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o28 };
struct Sop Oil_o29={ 29, 0, FloatingSubtraction, 1, (tOilArgSig)&Oil_s14, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid85={ 85, 0, (tOilOpIdentification)&Oil_oid84, (tOilOp)&Oil_o29 };
struct Sop Oil_o64={ 64, 0, Minus, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid85 };
struct Sop Oil_o30={ 30, 0, IntegerMultiplication, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid86={ 86, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o30 };
struct Sop Oil_o31={ 31, 0, FloatingMultiplication, 1, (tOilArgSig)&Oil_s14, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid87={ 87, 0, (tOilOpIdentification)&Oil_oid86, (tOilOp)&Oil_o31 };
struct Sop Oil_o65={ 65, 0, Star, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid87 };
struct Sop Oil_o32={ 32, 0, IntegerDivision, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid88={ 88, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o32 };
struct Sop Oil_o33={ 33, 0, FloatingDivision, 1, (tOilArgSig)&Oil_s14, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid89={ 89, 0, (tOilOpIdentification)&Oil_oid88, (tOilOp)&Oil_o33 };
struct Sop Oil_o66={ 66, 0, Slash, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid89 };
struct Sop Oil_o34={ 34, 0, Remainder, 1, (tOilArgSig)&Oil_s7, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid90={ 90, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o34 };
struct Sop Oil_o67={ 67, 0, Percent, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid90 };
struct Sop Oil_o35={ 35, 0, IntegerNegation, 1, (tOilArgSig)&Oil_s6, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid91={ 91, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o35 };
struct Sop Oil_o36={ 36, 0, FloatingNegation, 1, (tOilArgSig)&Oil_s13, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid92={ 92, 0, (tOilOpIdentification)&Oil_oid91, (tOilOp)&Oil_o36 };
struct Sop Oil_o68={ 68, 0, UMinus, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid92 };
struct Sop Oil_o37={ 37, 0, IntOutput, 1, (tOilArgSig)&Oil_s6, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid93={ 93, 0, (tOilOpIdentification)0, (tOilOp)&Oil_o37 };
struct Sop Oil_o38={ 38, 0, FloatOutput, 1, (tOilArgSig)&Oil_s13, (tOilOp)0, (tOilOpIdentification)0 };
struct SopIdent Oil_oid94={ 94, 0, (tOilOpIdentification)&Oil_oid93, (tOilOp)&Oil_o38 };
struct Sop Oil_o69={ 69, 0, Return, 0, (tOilArgSig)0, (tOilOp)0, (tOilOpIdentification)&Oil_oid94 };
