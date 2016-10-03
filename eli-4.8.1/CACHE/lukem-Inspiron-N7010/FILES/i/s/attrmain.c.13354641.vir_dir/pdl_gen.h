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

#include "CoordCmp.h"
#include "Strings.h"
#include "ptg_gen.h"

#define TYPE int
extern TYPE Getint ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void Setint ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void Resetint ELI_ARG((int _Property, DefTableKey key, TYPE _val));
extern int Obtainint ELI_ARG((int _Property, DefTableKey key, int sym));
extern TYPE Terminalint ELI_ARG((int _Property, DefTableKey key));
extern void Isint ELI_ARG((int _Property, DefTableKey key, TYPE _which, TYPE _error));
extern TYPE SetGetint ELI_ARG((int _Property, DefTableKey key, TYPE init, TYPE reset));
extern void SetDiffint ELI_ARG((int _Property, DefTableKey key, TYPE thistype, TYPE diff));
#undef TYPE
#define TYPE DefTableKey
extern TYPE GetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE PTGNode
extern TYPE GetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE _val));
extern void UpdatePTGNode ELI_ARG((int _Property, DefTableKey key, PTGNode add));
#undef TYPE

#define SetClpValue(key, _add, _replace)   \
		Setint(1, (key), (_add), (_replace))
#define ResetClpValue(key, _val)   \
		Resetint(1, (key), (_val))
#define GetClpValue(key, deflt)   \
		Getint(1, (key), (deflt))
#define SetDiffKind(key, thistype, diff)   \
		SetDiffint(2, (key), (thistype), (diff))
#define SetKind(key, _add, _replace)   \
		Setint(2, (key), (_add), (_replace))
#define ResetKind(key, _val)   \
		Resetint(2, (key), (_val))
#define GetKind(key, deflt)   \
		Getint(2, (key), (deflt))
#define SetUnique(key, _add, _replace)   \
		Setint(3, (key), (_add), (_replace))
#define ResetUnique(key, _val)   \
		Resetint(3, (key), (_val))
#define GetUnique(key, deflt)   \
		Getint(3, (key), (deflt))
#define SetGetFirstOcc(key, init, reset)   \
		SetGetint(4, (key), (init), (reset))
#define SetFirstOcc(key, _add, _replace)   \
		Setint(4, (key), (_add), (_replace))
#define ResetFirstOcc(key, _val)   \
		Resetint(4, (key), (_val))
#define GetFirstOcc(key, deflt)   \
		Getint(4, (key), (deflt))
#define IsArity(key, _which, _error)   \
		Isint(5, (key), (_which), (_error))
#define SetArity(key, _add, _replace)   \
		Setint(5, (key), (_add), (_replace))
#define ResetArity(key, _val)   \
		Resetint(5, (key), (_val))
#define GetArity(key, deflt)   \
		Getint(5, (key), (deflt))
#define TerminalIndex(key)   \
		Terminalint(6, (key))
#define SetIndex(key, _add, _replace)   \
		Setint(6, (key), (_add), (_replace))
#define ResetIndex(key, _val)   \
		Resetint(6, (key), (_val))
#define GetIndex(key, deflt)   \
		Getint(6, (key), (deflt))
#define SetType(key, _add, _replace)   \
		SetDefTableKey(7, (key), (_add), (_replace))
#define ResetType(key, _val)   \
		ResetDefTableKey(7, (key), (_val))
#define GetType(key, deflt)   \
		GetDefTableKey(7, (key), (deflt))
#define SetUsed(key, _add, _replace)   \
		Setint(8, (key), (_add), (_replace))
#define ResetUsed(key, _val)   \
		Resetint(8, (key), (_val))
#define GetUsed(key, deflt)   \
		Getint(8, (key), (deflt))
#define SetSym(key, _add, _replace)   \
		Setint(9, (key), (_add), (_replace))
#define ResetSym(key, _val)   \
		Resetint(9, (key), (_val))
#define GetSym(key, deflt)   \
		Getint(9, (key), (deflt))
#define ObtainSymbol(key, sym)   \
		Obtainint(10, (key), (sym))
#define SetSymbol(key, _add, _replace)   \
		Setint(10, (key), (_add), (_replace))
#define ResetSymbol(key, _val)   \
		Resetint(10, (key), (_val))
#define GetSymbol(key, deflt)   \
		Getint(10, (key), (deflt))
#define UpdateCases(key, add)   \
		UpdatePTGNode(11, (key), (add))
#define SetCases(key, _add, _replace)   \
		SetPTGNode(11, (key), (_add), (_replace))
#define ResetCases(key, _val)   \
		ResetPTGNode(11, (key), (_val))
#define GetCases(key, deflt)   \
		GetPTGNode(11, (key), (deflt))

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
