#ifndef OILDECLS_H
#define OILDECLS_H
#include "oiladt2.h"
extern struct Sop Oil_o56;	/* Equal */
#define OilOpEqual (&Oil_o56)
extern struct Sop Oil_o8;	/* IntegerAssignment */
#define OilOpIntegerAssignment (&Oil_o8)
extern struct Stype Oil_t1;	/* int_t */
#define OilTypeint_t (&Oil_t1)
extern struct Sop Oil_o12;	/* TruncatingAssignment */
#define OilOpTruncatingAssignment (&Oil_o12)
extern struct Stype Oil_t2;	/* float_t */
#define OilTypefloat_t (&Oil_t2)
extern struct Sop Oil_o15;	/* FloatingAssignment */
#define OilOpFloatingAssignment (&Oil_o15)
extern struct Sop Oil_o57;	/* BarBar */
#define OilOpBarBar (&Oil_o57)
extern struct Sop Oil_o16;	/* Disjunction */
#define OilOpDisjunction (&Oil_o16)
extern struct Sop Oil_o58;	/* AmpAmp */
#define OilOpAmpAmp (&Oil_o58)
extern struct Sop Oil_o17;	/* Conjunction */
#define OilOpConjunction (&Oil_o17)
extern struct Sop Oil_o59;	/* Exclam */
#define OilOpExclam (&Oil_o59)
extern struct Sop Oil_o18;	/* Complement */
#define OilOpComplement (&Oil_o18)
extern struct Sop Oil_o60;	/* EquEqu */
#define OilOpEquEqu (&Oil_o60)
extern struct Sop Oil_o19;	/* IntEqual */
#define OilOpIntEqual (&Oil_o19)
extern struct Sop Oil_o21;	/* FloatEqual */
#define OilOpFloatEqual (&Oil_o21)
extern struct Sop Oil_o61;	/* Less */
#define OilOpLess (&Oil_o61)
extern struct Sop Oil_o22;	/* IntLess */
#define OilOpIntLess (&Oil_o22)
extern struct Sop Oil_o23;	/* FloatLess */
#define OilOpFloatLess (&Oil_o23)
extern struct Sop Oil_o62;	/* Greater */
#define OilOpGreater (&Oil_o62)
extern struct Sop Oil_o24;	/* IntGreater */
#define OilOpIntGreater (&Oil_o24)
extern struct Sop Oil_o25;	/* FloatGreater */
#define OilOpFloatGreater (&Oil_o25)
extern struct Sop Oil_o63;	/* Plus */
#define OilOpPlus (&Oil_o63)
extern struct Sop Oil_o26;	/* IntegerAddition */
#define OilOpIntegerAddition (&Oil_o26)
extern struct Sop Oil_o27;	/* FloatingAddition */
#define OilOpFloatingAddition (&Oil_o27)
extern struct Sop Oil_o64;	/* Minus */
#define OilOpMinus (&Oil_o64)
extern struct Sop Oil_o28;	/* IntegerSubtraction */
#define OilOpIntegerSubtraction (&Oil_o28)
extern struct Sop Oil_o29;	/* FloatingSubtraction */
#define OilOpFloatingSubtraction (&Oil_o29)
extern struct Sop Oil_o65;	/* Star */
#define OilOpStar (&Oil_o65)
extern struct Sop Oil_o30;	/* IntegerMultiplication */
#define OilOpIntegerMultiplication (&Oil_o30)
extern struct Sop Oil_o31;	/* FloatingMultiplication */
#define OilOpFloatingMultiplication (&Oil_o31)
extern struct Sop Oil_o66;	/* Slash */
#define OilOpSlash (&Oil_o66)
extern struct Sop Oil_o32;	/* IntegerDivision */
#define OilOpIntegerDivision (&Oil_o32)
extern struct Sop Oil_o33;	/* FloatingDivision */
#define OilOpFloatingDivision (&Oil_o33)
extern struct Sop Oil_o67;	/* Percent */
#define OilOpPercent (&Oil_o67)
extern struct Sop Oil_o34;	/* Remainder */
#define OilOpRemainder (&Oil_o34)
extern struct Sop Oil_o68;	/* UMinus */
#define OilOpUMinus (&Oil_o68)
extern struct Sop Oil_o35;	/* IntegerNegation */
#define OilOpIntegerNegation (&Oil_o35)
extern struct Sop Oil_o36;	/* FloatingNegation */
#define OilOpFloatingNegation (&Oil_o36)
extern struct Sop Oil_o69;	/* Return */
#define OilOpReturn (&Oil_o69)
extern struct Sop Oil_o37;	/* IntOutput */
#define OilOpIntOutput (&Oil_o37)
extern struct Sop Oil_o38;	/* FloatOutput */
#define OilOpFloatOutput (&Oil_o38)
extern struct Sop Oil_o40;	/* IntToFloat */
#define OilOpIntToFloat (&Oil_o40)
extern struct Sop Oil_o43;	/* IntToVoid */
#define OilOpIntToVoid (&Oil_o43)
extern struct Stype Oil_t3;	/* void_t */
#define OilTypevoid_t (&Oil_t3)
extern struct Sop Oil_o46;	/* FloatToVoid */
#define OilOpFloatToVoid (&Oil_o46)
extern struct Sop Oil_o50;	/* UnkI */
#define OilOpUnkI (&Oil_o50)
extern struct Stype Oil_t4;	/* unknown_t */
#define OilTypeunknown_t (&Oil_t4)
extern struct Sop Oil_o55;	/* UnkF */
#define OilOpUnkF (&Oil_o55)
#endif
