#include "pdl_gen.h"

#ifdef MONITOR
#include "pdl_dapto.h"
#endif

#define PRESENT find(key, _property, (Entry *)&_Item, 0)
#define VALUE (_Item->PropVal)

#define TYPE int

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct intElt))

typedef struct intElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *intProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
Getint (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
Getint (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  intProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
Setint (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
Setint (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  intProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
Resetint (int _property, DefTableKey key, TYPE _val)
#else
void
Resetint (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  intProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE tOilType

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct tOilTypeElt))

typedef struct tOilTypeElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *tOilTypeProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GettOilType (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GettOilType (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  tOilTypeProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SettOilType (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SettOilType (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  tOilTypeProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResettOilType (int _property, DefTableKey key, TYPE _val)
#else
void
ResettOilType (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  tOilTypeProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE tOilOp

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct tOilOpElt))

typedef struct tOilOpElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *tOilOpProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GettOilOp (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GettOilOp (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  tOilOpProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SettOilOp (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SettOilOp (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  tOilOpProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResettOilOp (int _property, DefTableKey key, TYPE _val)
#else
void
ResettOilOp (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  tOilOpProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE tOilClass

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct tOilClassElt))

typedef struct tOilClassElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *tOilClassProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GettOilClass (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GettOilClass (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  tOilClassProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SettOilClass (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SettOilClass (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  tOilClassProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResettOilClass (int _property, DefTableKey key, TYPE _val)
#else
void
ResettOilClass (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  tOilClassProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE

static struct PropElt PDLe0 = {(Entry)0, 0};
static struct tOilOpElt PDLe1 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o56};
static struct tOilOpElt PDLe2 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o8};
static struct tOilTypeElt PDLe4 = {(Entry)&PDLe0, 4, (tOilType)&Oil_t1};
static struct intElt PDLe3 = {(Entry)&PDLe4, 7, 1};
static struct tOilOpElt PDLe5 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o12};
static struct tOilTypeElt PDLe7 = {(Entry)&PDLe0, 4, (tOilType)&Oil_t2};
static struct intElt PDLe6 = {(Entry)&PDLe7, 7, 1};
static struct tOilOpElt PDLe8 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o15};
static struct tOilOpElt PDLe9 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o57};
static struct tOilOpElt PDLe10 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o16};
static struct tOilOpElt PDLe11 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o58};
static struct tOilOpElt PDLe12 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o17};
static struct tOilOpElt PDLe13 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o59};
static struct tOilOpElt PDLe14 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o18};
static struct tOilOpElt PDLe15 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o60};
static struct tOilOpElt PDLe16 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o19};
static struct tOilOpElt PDLe17 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o21};
static struct tOilOpElt PDLe18 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o61};
static struct tOilOpElt PDLe19 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o22};
static struct tOilOpElt PDLe20 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o23};
static struct tOilOpElt PDLe21 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o62};
static struct tOilOpElt PDLe22 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o24};
static struct tOilOpElt PDLe23 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o25};
static struct tOilOpElt PDLe24 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o63};
static struct tOilOpElt PDLe25 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o26};
static struct tOilOpElt PDLe26 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o27};
static struct tOilOpElt PDLe27 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o64};
static struct tOilOpElt PDLe28 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o28};
static struct tOilOpElt PDLe29 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o29};
static struct tOilOpElt PDLe30 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o65};
static struct tOilOpElt PDLe31 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o30};
static struct tOilOpElt PDLe32 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o31};
static struct tOilOpElt PDLe33 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o66};
static struct tOilOpElt PDLe34 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o32};
static struct tOilOpElt PDLe35 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o33};
static struct tOilOpElt PDLe36 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o67};
static struct tOilOpElt PDLe37 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o34};
static struct tOilOpElt PDLe38 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o68};
static struct tOilOpElt PDLe39 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o35};
static struct tOilOpElt PDLe40 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o36};
static struct tOilOpElt PDLe41 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o69};
static struct tOilOpElt PDLe42 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o37};
static struct tOilOpElt PDLe43 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o38};
static struct tOilOpElt PDLe44 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o40};
static struct tOilOpElt PDLe45 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o43};
static struct tOilTypeElt PDLe47 = {(Entry)&PDLe0, 4, (tOilType)&Oil_t3};
static struct intElt PDLe46 = {(Entry)&PDLe47, 7, 1};
static struct tOilOpElt PDLe48 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o46};
static struct tOilOpElt PDLe49 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o50};
static struct tOilTypeElt PDLe51 = {(Entry)&PDLe0, 4, (tOilType)&Oil_t4};
static struct intElt PDLe50 = {(Entry)&PDLe51, 7, 1};
static struct tOilOpElt PDLe52 = {(Entry)&PDLe0, 5, (tOilOp)&Oil_o55};

struct PropList PDLk[] = {
  {(Entry)&PDLe1},
  {(Entry)&PDLe2},
  {(Entry)&PDLe3},
  {(Entry)&PDLe5},
  {(Entry)&PDLe6},
  {(Entry)&PDLe8},
  {(Entry)&PDLe9},
  {(Entry)&PDLe10},
  {(Entry)&PDLe11},
  {(Entry)&PDLe12},
  {(Entry)&PDLe13},
  {(Entry)&PDLe14},
  {(Entry)&PDLe15},
  {(Entry)&PDLe16},
  {(Entry)&PDLe17},
  {(Entry)&PDLe18},
  {(Entry)&PDLe19},
  {(Entry)&PDLe20},
  {(Entry)&PDLe21},
  {(Entry)&PDLe22},
  {(Entry)&PDLe23},
  {(Entry)&PDLe24},
  {(Entry)&PDLe25},
  {(Entry)&PDLe26},
  {(Entry)&PDLe27},
  {(Entry)&PDLe28},
  {(Entry)&PDLe29},
  {(Entry)&PDLe30},
  {(Entry)&PDLe31},
  {(Entry)&PDLe32},
  {(Entry)&PDLe33},
  {(Entry)&PDLe34},
  {(Entry)&PDLe35},
  {(Entry)&PDLe36},
  {(Entry)&PDLe37},
  {(Entry)&PDLe38},
  {(Entry)&PDLe39},
  {(Entry)&PDLe40},
  {(Entry)&PDLe41},
  {(Entry)&PDLe42},
  {(Entry)&PDLe43},
  {(Entry)&PDLe44},
  {(Entry)&PDLe45},
  {(Entry)&PDLe46},
  {(Entry)&PDLe48},
  {(Entry)&PDLe49},
  {(Entry)&PDLe50},
  {(Entry)&PDLe52}};

DefTableKey
#if defined(__STDC__) || defined(__cplusplus)
CloneKey (DefTableKey key)
#else
CloneKey (key)
    DefTableKey key;
#endif
{
  DefTableKey k;
  Entry e;

  if (key == NoKey) return NoKey;
  k = NewKey ();
  for (e = key->List; (e != (Entry)0) && (e->selector != 0);
       e = e->next) {
    switch (e->selector) {
      case 1:
         ResetClpValue (k, ((intProperty)e)->PropVal);
         break;
      case 2:
         ResetDef (k, ((intProperty)e)->PropVal);
         break;
      case 3:
         ResetType (k, ((tOilTypeProperty)e)->PropVal);
         break;
      case 4:
         ResetOilType (k, ((tOilTypeProperty)e)->PropVal);
         break;
      case 5:
         ResetOilOp (k, ((tOilOpProperty)e)->PropVal);
         break;
      case 6:
         ResetOilClass (k, ((tOilClassProperty)e)->PropVal);
         break;
      case 7:
         ResetIsType (k, ((intProperty)e)->PropVal);
         break;
      }
  }
  return k;
}

#ifdef MONITOR
static CONST char *pdl_names[] = {
    (char *)0,
    "ClpValue",
    "Def",
    "Type",
    "OilType",
    "OilOp",
    "OilClass",
    "IsType",
};
static CONST char *pdl_types[] = {
    (char *)0,
    "int",
    "int",
    "tOilType",
    "tOilType",
    "tOilOp",
    "tOilClass",
    "int",
};

void
#if defined(__STDC__) || defined(__cplusplus)
pdl_mon_properties(DefTableKey k)
#else
pdl_mon_properties(k) DefTableKey k;
#endif
{
    Entry e;
    if (k == NoKey) return;
    for (e = k->List; (e != (Entry)0) && (e->selector != 0);
         e = e->next) {
        DAPTO_RESULT_STR (pdl_names[e->selector]);
        DAPTO_RESULT_STR (pdl_types[e->selector]);
        switch (e->selector) {
            case 1:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 2:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 3:
#ifdef DAPTO_RESULTtOilType
                DAPTO_RESULTtOilType (((tOilTypeProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilTypeProperty)e)->PropVal);
#endif
                break;
            case 4:
#ifdef DAPTO_RESULTtOilType
                DAPTO_RESULTtOilType (((tOilTypeProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilTypeProperty)e)->PropVal);
#endif
                break;
            case 5:
#ifdef DAPTO_RESULTtOilOp
                DAPTO_RESULTtOilOp (((tOilOpProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilOpProperty)e)->PropVal);
#endif
                break;
            case 6:
#ifdef DAPTO_RESULTtOilClass
                DAPTO_RESULTtOilClass (((tOilClassProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilClassProperty)e)->PropVal);
#endif
                break;
            case 7:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            default: DAPTO_RESULT_STR ("unknown property");
        }
    }
}
#endif
