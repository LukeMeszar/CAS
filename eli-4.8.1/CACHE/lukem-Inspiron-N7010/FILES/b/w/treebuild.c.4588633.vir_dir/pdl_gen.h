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

#include "ptg_gen.h"
#include "Strings.h"
#include "ptg_gen.h"

#define TYPE int
extern TYPE Getint ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void Setint ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void Resetint ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE PTGNode
extern TYPE GetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE
#define TYPE CharPtr
extern TYPE GetCharPtr ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetCharPtr ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetCharPtr ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE

#define SetClpValue(key, _add, _replace)   \
		Setint(1, (key), (_add), (_replace))
#define ResetClpValue(key, _val)   \
		Resetint(1, (key), (_val))
#define GetClpValue(key, deflt)   \
		Getint(1, (key), (deflt))
#define SetExportUnique(key, _add, _replace)   \
		Setint(2, (key), (_add), (_replace))
#define ResetExportUnique(key, _val)   \
		Resetint(2, (key), (_val))
#define GetExportUnique(key, deflt)   \
		Getint(2, (key), (deflt))
#define SetTranslations(key, _add, _replace)   \
		SetPTGNode(3, (key), (_add), (_replace))
#define ResetTranslations(key, _val)   \
		ResetPTGNode(3, (key), (_val))
#define GetTranslations(key, deflt)   \
		GetPTGNode(3, (key), (deflt))
#define SetTranslationVars(key, _add, _replace)   \
		SetPTGNode(4, (key), (_add), (_replace))
#define ResetTranslationVars(key, _val)   \
		ResetPTGNode(4, (key), (_val))
#define GetTranslationVars(key, deflt)   \
		GetPTGNode(4, (key), (deflt))
#define Setamp(key, _add, _replace)   \
		SetCharPtr(5, (key), (_add), (_replace))
#define Resetamp(key, _val)   \
		ResetCharPtr(5, (key), (_val))
#define Getamp(key, deflt)   \
		GetCharPtr(5, (key), (deflt))
#define Setsend(key, _add, _replace)   \
		SetCharPtr(6, (key), (_add), (_replace))
#define Resetsend(key, _val)   \
		ResetCharPtr(6, (key), (_val))
#define Getsend(key, deflt)   \
		GetCharPtr(6, (key), (deflt))
#define Settype(key, _add, _replace)   \
		SetCharPtr(7, (key), (_add), (_replace))
#define Resettype(key, _val)   \
		ResetCharPtr(7, (key), (_val))
#define Gettype(key, deflt)   \
		GetCharPtr(7, (key), (deflt))
#define Setstandard(key, _add, _replace)   \
		Setint(8, (key), (_add), (_replace))
#define Resetstandard(key, _val)   \
		Resetint(8, (key), (_val))
#define Getstandard(key, deflt)   \
		Getint(8, (key), (deflt))
#define Setcast(key, _add, _replace)   \
		SetPTGNode(9, (key), (_add), (_replace))
#define Resetcast(key, _val)   \
		ResetPTGNode(9, (key), (_val))
#define Getcast(key, deflt)   \
		GetPTGNode(9, (key), (deflt))

extern struct PropList PDLk[];

#define intKey (&PDLk[0])
#define strKey (&PDLk[1])

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
