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
#include "ptg_gen.h"

#define TYPE int
extern TYPE Getint ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void Setint ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void Resetint ELI_ARG((int _Property, DefTableKey key, TYPE _val));
extern TYPE SetGetint ELI_ARG((int _Property, DefTableKey key, TYPE init, TYPE reset));
#undef TYPE
#define TYPE PTGNode
extern TYPE GetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE _add, TYPE _replace));
extern void ResetPTGNode ELI_ARG((int _Property, DefTableKey key, TYPE _val));
#undef TYPE

#define SetClpValue(key, _add, _replace)   \
		Setint(1, (key), (_add), (_replace))
#define ResetClpValue(key, _val)   \
		Resetint(1, (key), (_val))
#define GetClpValue(key, deflt)   \
		Getint(1, (key), (deflt))
#define SetGetFirstOcc(key, init, reset)   \
		SetGetint(2, (key), (init), (reset))
#define SetFirstOcc(key, _add, _replace)   \
		Setint(2, (key), (_add), (_replace))
#define ResetFirstOcc(key, _val)   \
		Resetint(2, (key), (_val))
#define GetFirstOcc(key, deflt)   \
		Getint(2, (key), (deflt))
#define SetDefined(key, _add, _replace)   \
		Setint(3, (key), (_add), (_replace))
#define ResetDefined(key, _val)   \
		Resetint(3, (key), (_val))
#define GetDefined(key, deflt)   \
		Getint(3, (key), (deflt))
#define SetIsListofLhs(key, _add, _replace)   \
		Setint(4, (key), (_add), (_replace))
#define ResetIsListofLhs(key, _val)   \
		Resetint(4, (key), (_val))
#define GetIsListofLhs(key, deflt)   \
		Getint(4, (key), (deflt))
#define SetComputedRoot(key, _add, _replace)   \
		Setint(5, (key), (_add), (_replace))
#define ResetComputedRoot(key, _val)   \
		Resetint(5, (key), (_val))
#define GetComputedRoot(key, deflt)   \
		Getint(5, (key), (deflt))
#define SetNoPtgGiven(key, _add, _replace)   \
		Setint(6, (key), (_add), (_replace))
#define ResetNoPtgGiven(key, _val)   \
		Resetint(6, (key), (_val))
#define GetNoPtgGiven(key, deflt)   \
		Getint(6, (key), (deflt))
#define SetNoPtg2Given(key, _add, _replace)   \
		Setint(7, (key), (_add), (_replace))
#define ResetNoPtg2Given(key, _val)   \
		Resetint(7, (key), (_val))
#define GetNoPtg2Given(key, deflt)   \
		Getint(7, (key), (deflt))
#define SetNoPtg1Given(key, _add, _replace)   \
		Setint(8, (key), (_add), (_replace))
#define ResetNoPtg1Given(key, _val)   \
		Resetint(8, (key), (_val))
#define GetNoPtg1Given(key, deflt)   \
		Getint(8, (key), (deflt))
#define SetEntity(key, _add, _replace)   \
		SetPTGNode(9, (key), (_add), (_replace))
#define ResetEntity(key, _val)   \
		ResetPTGNode(9, (key), (_val))
#define GetEntity(key, deflt)   \
		GetPTGNode(9, (key), (deflt))

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
