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


#define TYPE int
extern TYPE Getint ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void Setint ELI_ARG((int _Property, DefTableKey key, TYPE add, TYPE replace));
extern void Resetint ELI_ARG((int _Property, DefTableKey key, TYPE val));
#undef TYPE
#define TYPE DefTableKey
extern TYPE GetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE deflt));
extern void SetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE add, TYPE replace));
extern void ResetDefTableKey ELI_ARG((int _Property, DefTableKey key, TYPE val));
#undef TYPE

#define SetName(key, add, replace)   \
		Setint(1, (key), (add), (replace))
#define ResetName(key, val)   \
		Resetint(1, (key), (val))
#define GetName(key, deflt)   \
		Getint(1, (key), (deflt))
#define SetNodeName(key, add, replace)   \
		Setint(2, (key), (add), (replace))
#define ResetNodeName(key, val)   \
		Resetint(2, (key), (val))
#define GetNodeName(key, deflt)   \
		Getint(2, (key), (deflt))
#define SetNext(key, add, replace)   \
		SetDefTableKey(3, (key), (add), (replace))
#define ResetNext(key, val)   \
		ResetDefTableKey(3, (key), (val))
#define GetNext(key, deflt)   \
		GetDefTableKey(3, (key), (deflt))
#define SetPrev(key, add, replace)   \
		SetDefTableKey(4, (key), (add), (replace))
#define ResetPrev(key, val)   \
		ResetDefTableKey(4, (key), (val))
#define GetPrev(key, deflt)   \
		GetDefTableKey(4, (key), (deflt))
#define SetParent(key, add, replace)   \
		SetDefTableKey(5, (key), (add), (replace))
#define ResetParent(key, val)   \
		ResetDefTableKey(5, (key), (val))
#define GetParent(key, deflt)   \
		GetDefTableKey(5, (key), (deflt))
#define SetFirstChild(key, add, replace)   \
		SetDefTableKey(6, (key), (add), (replace))
#define ResetFirstChild(key, val)   \
		ResetDefTableKey(6, (key), (val))
#define GetFirstChild(key, deflt)   \
		GetDefTableKey(6, (key), (deflt))

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
