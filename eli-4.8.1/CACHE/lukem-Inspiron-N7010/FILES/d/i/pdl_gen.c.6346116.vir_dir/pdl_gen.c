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

#if defined(__STDC__) || defined(__cplusplus)
TYPE
SetGetint (int _property, DefTableKey key, TYPE init, TYPE reset)
#else
TYPE
SetGetint (_property, key, init, reset)
int _property;
DefTableKey key;
TYPE init;
TYPE reset;
#endif
{  intProperty _Item;
{ if (key == NoKey) return init;
  if (ACCESS)   {VALUE = reset; return reset;}
  else          {VALUE = init; return init;}
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
#define TYPE tOilOpList

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct tOilOpListElt))

typedef struct tOilOpListElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *tOilOpListProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GettOilOpList (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GettOilOpList (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  tOilOpListProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SettOilOpList (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SettOilOpList (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  tOilOpListProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResettOilOpList (int _property, DefTableKey key, TYPE _val)
#else
void
ResettOilOpList (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  tOilOpListProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE tOilClassOpList

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct tOilClassOpListElt))

typedef struct tOilClassOpListElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *tOilClassOpListProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GettOilClassOpList (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GettOilClassOpList (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  tOilClassOpListProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SettOilClassOpList (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SettOilClassOpList (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  tOilClassOpListProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResettOilClassOpList (int _property, DefTableKey key, TYPE _val)
#else
void
ResettOilClassOpList (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  tOilClassOpListProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE DefTableKeyList

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct DefTableKeyListElt))

typedef struct DefTableKeyListElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *DefTableKeyListProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetDefTableKeyList (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetDefTableKeyList (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  DefTableKeyListProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetDefTableKeyList (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetDefTableKeyList (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  DefTableKeyListProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetDefTableKeyList (int _property, DefTableKey key, TYPE _val)
#else
void
ResetDefTableKeyList (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  DefTableKeyListProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE
#define TYPE DefTableKey

#define ACCESS find(key, _property, (Entry *)&_Item, sizeof(struct DefTableKeyElt))

typedef struct DefTableKeyElt {
	Entry next;
	int selector;
	TYPE PropVal;
} *DefTableKeyProperty;

#if defined(__STDC__) || defined(__cplusplus)
TYPE
GetDefTableKey (int _property, DefTableKey key, TYPE deflt)
#else
TYPE
GetDefTableKey (_property, key, deflt)
int _property;
DefTableKey key;
TYPE deflt;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return deflt;
  if (PRESENT) return VALUE;
  else return deflt;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
SetDefTableKey (int _property, DefTableKey key, TYPE _add, TYPE _replace)
#else
void
SetDefTableKey (_property, key, _add, _replace)
int _property;
DefTableKey key;
TYPE _add;
TYPE _replace;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return;
  if (ACCESS) VALUE = _replace;
  else VALUE = _add;
}
}

#if defined(__STDC__) || defined(__cplusplus)
void
ResetDefTableKey (int _property, DefTableKey key, TYPE _val)
#else
void
ResetDefTableKey (_property, key, _val)
int _property;
DefTableKey key;
TYPE _val;
#endif
{  DefTableKeyProperty _Item;
{ if (key == NoKey) return;
  ACCESS; VALUE = _val;
}
}

#undef ACCESS
#undef TYPE

static struct PropElt PDLe0 = {(Entry)0, 0};

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
         ResetUnique (k, ((intProperty)e)->PropVal);
         break;
      case 3:
         ResetOilType (k, ((tOilTypeProperty)e)->PropVal);
         break;
      case 4:
         ResetOilOp (k, ((tOilOpProperty)e)->PropVal);
         break;
      case 5:
         ResetOilClass (k, ((tOilClassProperty)e)->PropVal);
         break;
      case 6:
         ResetFirstOcc (k, ((intProperty)e)->PropVal);
         break;
      case 7:
         ResetTypeFirstOcc (k, ((intProperty)e)->PropVal);
         break;
      case 8:
         ResetOperFirstOcc (k, ((intProperty)e)->PropVal);
         break;
      case 9:
         ResetIndex (k, ((intProperty)e)->PropVal);
         break;
      case 10:
         ResetType (k, ((tOilTypeProperty)e)->PropVal);
         break;
      case 11:
         ResetOperator (k, ((tOilOpListProperty)e)->PropVal);
         break;
      case 12:
         ResetClassOperator (k, ((tOilClassOpListProperty)e)->PropVal);
         break;
      case 13:
         ResetBindingStatus (k, ((intProperty)e)->PropVal);
         break;
      case 14:
         ResetParameterIndex (k, ((intProperty)e)->PropVal);
         break;
      case 15:
         ResetTypeSet (k, ((DefTableKeyListProperty)e)->PropVal);
         break;
      case 16:
         ResetBoundType (k, ((DefTableKeyProperty)e)->PropVal);
         break;
      }
  }
  return k;
}

#ifdef MONITOR
static CONST char *pdl_names[] = {
    (char *)0,
    "ClpValue",
    "Unique",
    "OilType",
    "OilOp",
    "OilClass",
    "FirstOcc",
    "TypeFirstOcc",
    "OperFirstOcc",
    "Index",
    "Type",
    "Operator",
    "ClassOperator",
    "BindingStatus",
    "ParameterIndex",
    "TypeSet",
    "BoundType",
};
static CONST char *pdl_types[] = {
    (char *)0,
    "int",
    "int",
    "tOilType",
    "tOilOp",
    "tOilClass",
    "int",
    "int",
    "int",
    "int",
    "tOilType",
    "tOilOpList",
    "tOilClassOpList",
    "int",
    "int",
    "DefTableKeyList",
    "DefTableKey",
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
#ifdef DAPTO_RESULTtOilOp
                DAPTO_RESULTtOilOp (((tOilOpProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilOpProperty)e)->PropVal);
#endif
                break;
            case 5:
#ifdef DAPTO_RESULTtOilClass
                DAPTO_RESULTtOilClass (((tOilClassProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilClassProperty)e)->PropVal);
#endif
                break;
            case 6:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 7:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 8:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 9:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 10:
#ifdef DAPTO_RESULTtOilType
                DAPTO_RESULTtOilType (((tOilTypeProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilTypeProperty)e)->PropVal);
#endif
                break;
            case 11:
#ifdef DAPTO_RESULTtOilOpList
                DAPTO_RESULTtOilOpList (((tOilOpListProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilOpListProperty)e)->PropVal);
#endif
                break;
            case 12:
#ifdef DAPTO_RESULTtOilClassOpList
                DAPTO_RESULTtOilClassOpList (((tOilClassOpListProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((tOilClassOpListProperty)e)->PropVal);
#endif
                break;
            case 13:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 14:
#ifdef DAPTO_RESULTint
                DAPTO_RESULTint (((intProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((intProperty)e)->PropVal);
#endif
                break;
            case 15:
#ifdef DAPTO_RESULTDefTableKeyList
                DAPTO_RESULTDefTableKeyList (((DefTableKeyListProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((DefTableKeyListProperty)e)->PropVal);
#endif
                break;
            case 16:
#ifdef DAPTO_RESULTDefTableKey
                DAPTO_RESULTDefTableKey (((DefTableKeyProperty)e)->PropVal);
#else
                DAPTO_RESULT_OTHER (((DefTableKeyProperty)e)->PropVal);
#endif
                break;
            default: DAPTO_RESULT_STR ("unknown property");
        }
    }
}
#endif
