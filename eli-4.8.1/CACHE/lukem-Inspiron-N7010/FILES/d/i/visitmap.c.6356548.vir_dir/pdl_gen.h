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
#include "CoordCmp.h"
#include "oiladt2.h"
#include "tOilOpList.h"
#include "tOilClassOpList.h"
#include "DefTableKeyList.h"

#define TYPE int
extern TYPE Getint ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void Setint ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void Resetint ELI_ARG((int _Property, DefTableKey key, TYPE _val));
extern TYPE SetGetint ELI_ARG((int _Property, DefTableKey key, TYPE init, TYPE reset));
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
#define TYPE tOilOpList
extern TYPE GettOilOpList ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SettOilOpList ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResettOilOpList ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE tOilClassOpList
extern TYPE GettOilClassOpList ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SettOilClassOpList ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResettOilClassOpList ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE DefTableKeyList
extern TYPE GetDefTableKeyList ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetDefTableKeyList ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetDefTableKeyList ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE DefTableKey
extern TYPE GetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE

#define SetClpValue(key, _add, _replace)   \
		Setint(1, (key), (_add), (_replace))
#define ResetClpValue(key, _val)   \
		Resetint(1, (key), (_val))
#define GetClpValue(key, deflt)   \
		Getint(1, (key), (deflt))
#define SetUnique(key, _add, _replace)   \
		Setint(2, (key), (_add), (_replace))
#define ResetUnique(key, _val)   \
		Resetint(2, (key), (_val))
#define GetUnique(key, deflt)   \
		Getint(2, (key), (deflt))
#define SetOilType(key, _add, _replace)   \
		SettOilType(3, (key), (_add), (_replace))
#define ResetOilType(key, _val)   \
		ResettOilType(3, (key), (_val))
#define GetOilType(key, deflt)   \
		GettOilType(3, (key), (deflt))
#define SetOilOp(key, _add, _replace)   \
		SettOilOp(4, (key), (_add), (_replace))
#define ResetOilOp(key, _val)   \
		ResettOilOp(4, (key), (_val))
#define GetOilOp(key, deflt)   \
		GettOilOp(4, (key), (deflt))
#define SetOilClass(key, _add, _replace)   \
		SettOilClass(5, (key), (_add), (_replace))
#define ResetOilClass(key, _val)   \
		ResettOilClass(5, (key), (_val))
#define GetOilClass(key, deflt)   \
		GettOilClass(5, (key), (deflt))
#define SetGetFirstOcc(key, init, reset)   \
		SetGetint(6, (key), (init), (reset))
#define SetFirstOcc(key, _add, _replace)   \
		Setint(6, (key), (_add), (_replace))
#define ResetFirstOcc(key, _val)   \
		Resetint(6, (key), (_val))
#define GetFirstOcc(key, deflt)   \
		Getint(6, (key), (deflt))
#define SetGetTypeFirstOcc(key, init, reset)   \
		SetGetint(7, (key), (init), (reset))
#define SetTypeFirstOcc(key, _add, _replace)   \
		Setint(7, (key), (_add), (_replace))
#define ResetTypeFirstOcc(key, _val)   \
		Resetint(7, (key), (_val))
#define GetTypeFirstOcc(key, deflt)   \
		Getint(7, (key), (deflt))
#define SetGetOperFirstOcc(key, init, reset)   \
		SetGetint(8, (key), (init), (reset))
#define SetOperFirstOcc(key, _add, _replace)   \
		Setint(8, (key), (_add), (_replace))
#define ResetOperFirstOcc(key, _val)   \
		Resetint(8, (key), (_val))
#define GetOperFirstOcc(key, deflt)   \
		Getint(8, (key), (deflt))
#define SetIndex(key, _add, _replace)   \
		Setint(9, (key), (_add), (_replace))
#define ResetIndex(key, _val)   \
		Resetint(9, (key), (_val))
#define GetIndex(key, deflt)   \
		Getint(9, (key), (deflt))
#define SetType(key, _add, _replace)   \
		SettOilType(10, (key), (_add), (_replace))
#define ResetType(key, _val)   \
		ResettOilType(10, (key), (_val))
#define GetType(key, deflt)   \
		GettOilType(10, (key), (deflt))
#define SetOperator(key, _add, _replace)   \
		SettOilOpList(11, (key), (_add), (_replace))
#define ResetOperator(key, _val)   \
		ResettOilOpList(11, (key), (_val))
#define GetOperator(key, deflt)   \
		GettOilOpList(11, (key), (deflt))
#define SetClassOperator(key, _add, _replace)   \
		SettOilClassOpList(12, (key), (_add), (_replace))
#define ResetClassOperator(key, _val)   \
		ResettOilClassOpList(12, (key), (_val))
#define GetClassOperator(key, deflt)   \
		GettOilClassOpList(12, (key), (deflt))
#define SetBindingStatus(key, _add, _replace)   \
		Setint(13, (key), (_add), (_replace))
#define ResetBindingStatus(key, _val)   \
		Resetint(13, (key), (_val))
#define GetBindingStatus(key, deflt)   \
		Getint(13, (key), (deflt))
#define SetParameterIndex(key, _add, _replace)   \
		Setint(14, (key), (_add), (_replace))
#define ResetParameterIndex(key, _val)   \
		Resetint(14, (key), (_val))
#define GetParameterIndex(key, deflt)   \
		Getint(14, (key), (deflt))
#define SetTypeSet(key, _add, _replace)   \
		SetDefTableKeyList(15, (key), (_add), (_replace))
#define ResetTypeSet(key, _val)   \
		ResetDefTableKeyList(15, (key), (_val))
#define GetTypeSet(key, deflt)   \
		GetDefTableKeyList(15, (key), (deflt))
#define SetBoundType(key, _add, _replace)   \
		SetDefTableKey(16, (key), (_add), (_replace))
#define ResetBoundType(key, _val)   \
		ResetDefTableKey(16, (key), (_val))
#define GetBoundType(key, deflt)   \
		GetDefTableKey(16, (key), (deflt))

extern struct PropList PDLk[];


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
