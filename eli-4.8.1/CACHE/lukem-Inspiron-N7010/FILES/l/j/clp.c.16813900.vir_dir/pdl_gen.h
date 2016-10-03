#ifndef PDL_GEN_H
#define PDL_GEN_H

#include "deftbl.h"

#ifdef ELI_ARG
#undef ELI_ARG
#endif

#if defined(__STDC__) || defined(__cplusplus)
#define ELI_ARG(proto)    proto
#else
#define ELI_ARG(proto)    ()
#endif

#include "oiladt2.h"
#include "oiladt2.h"
#include "OilDecls.h"

#define TYPE int
extern TYPE Getint ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void Setint ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void Resetint ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE tOilType
extern TYPE GettOilType ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SettOilType ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResettOilType ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE tOilOp
extern TYPE GettOilOp ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SettOilOp ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResettOilOp ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE tOilClass
extern TYPE GettOilClass ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SettOilClass ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResettOilClass ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE

#define SetClpValue(key, _add, _replace)   \
		Setint(1, (key), (_add), (_replace))
#define ResetClpValue(key, _val)   \
		Resetint(1, (key), (_val))
#define GetClpValue(key, deflt)   \
		Getint(1, (key), (deflt))
#define SetDef(key, _add, _replace)   \
		Setint(2, (key), (_add), (_replace))
#define ResetDef(key, _val)   \
		Resetint(2, (key), (_val))
#define GetDef(key, deflt)   \
		Getint(2, (key), (deflt))
#define SetType(key, _add, _replace)   \
		SettOilType(3, (key), (_add), (_replace))
#define ResetType(key, _val)   \
		ResettOilType(3, (key), (_val))
#define GetType(key, deflt)   \
		GettOilType(3, (key), (deflt))
#define SetOilType(key, _add, _replace)   \
		SettOilType(4, (key), (_add), (_replace))
#define ResetOilType(key, _val)   \
		ResettOilType(4, (key), (_val))
#define GetOilType(key, deflt)   \
		GettOilType(4, (key), (deflt))
#define SetOilOp(key, _add, _replace)   \
		SettOilOp(5, (key), (_add), (_replace))
#define ResetOilOp(key, _val)   \
		ResettOilOp(5, (key), (_val))
#define GetOilOp(key, deflt)   \
		GettOilOp(5, (key), (deflt))
#define SetOilClass(key, _add, _replace)   \
		SettOilClass(6, (key), (_add), (_replace))
#define ResetOilClass(key, _val)   \
		ResettOilClass(6, (key), (_val))
#define GetOilClass(key, deflt)   \
		GettOilClass(6, (key), (deflt))
#define SetIsType(key, _add, _replace)   \
		Setint(7, (key), (_add), (_replace))
#define ResetIsType(key, _val)   \
		Resetint(7, (key), (_val))
#define GetIsType(key, deflt)   \
		Getint(7, (key), (deflt))

extern struct PropList PDLk[];

#define Equal (&PDLk[0])
#define IntegerAssignment (&PDLk[1])
#define int_t (&PDLk[2])
#define TruncatingAssignment (&PDLk[3])
#define float_t (&PDLk[4])
#define FloatingAssignment (&PDLk[5])
#define BarBar (&PDLk[6])
#define Disjunction (&PDLk[7])
#define AmpAmp (&PDLk[8])
#define Conjunction (&PDLk[9])
#define Exclam (&PDLk[10])
#define Complement (&PDLk[11])
#define EquEqu (&PDLk[12])
#define IntEqual (&PDLk[13])
#define FloatEqual (&PDLk[14])
#define Less (&PDLk[15])
#define IntLess (&PDLk[16])
#define FloatLess (&PDLk[17])
#define Greater (&PDLk[18])
#define IntGreater (&PDLk[19])
#define FloatGreater (&PDLk[20])
#define Plus (&PDLk[21])
#define IntegerAddition (&PDLk[22])
#define FloatingAddition (&PDLk[23])
#define Minus (&PDLk[24])
#define IntegerSubtraction (&PDLk[25])
#define FloatingSubtraction (&PDLk[26])
#define Star (&PDLk[27])
#define IntegerMultiplication (&PDLk[28])
#define FloatingMultiplication (&PDLk[29])
#define Slash (&PDLk[30])
#define IntegerDivision (&PDLk[31])
#define FloatingDivision (&PDLk[32])
#define Percent (&PDLk[33])
#define Remainder (&PDLk[34])
#define UMinus (&PDLk[35])
#define IntegerNegation (&PDLk[36])
#define FloatingNegation (&PDLk[37])
#define Return (&PDLk[38])
#define IntOutput (&PDLk[39])
#define FloatOutput (&PDLk[40])
#define IntToFloat (&PDLk[41])
#define IntToVoid (&PDLk[42])
#define void_t (&PDLk[43])
#define FloatToVoid (&PDLk[44])
#define UnkI (&PDLk[45])
#define unknown_t (&PDLk[46])
#define UnkF (&PDLk[47])

extern DefTableKey CloneKey ELI_ARG((DefTableKey key));
/* Clone a definition
 *    On entry-
 *       key=a valid definition
 *    On exit-
 *       CloneKey=Unique definition with the same properties
 *                and property values as key
 ***/

#ifdef MONITOR
extern void pdl_mon_properties ELI_ARG((DefTableKey));
#endif

#endif
