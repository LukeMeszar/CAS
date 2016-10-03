
#include "Build.h"
#include "obstack.h"
#include "pdl_gen.h"
#include "oiladt2.h"
#include "DefTableKeyList.h"
#include "tOilOpList.h"
#include "tOilClassOpList.h"


int
#ifdef PROTO_OK
CmpKey(DefTableKey left, DefTableKey right)
#else
CmpKey(left, right) DefTableKey left, right;
#endif
{ return left < right ? -1 : left == right ? 0 : 1; }



DefTableKeyList
#ifdef PROTO_OK
Union(DefTableKeyList left, DefTableKeyList right)
#else
Union(left, right) DefTableKeyList left, right;
#endif

{ while (left != NULLDefTableKeyList) {
    right = AddToSetDefTableKeyList(HeadDefTableKeyList(left), right, CmpKey);
    left = TailDefTableKeyList(left);
  }
  return right;
}


DefTableKeyList
#ifdef PROTO_OK
Difference(DefTableKeyList left, DefTableKeyList right)
#else
Difference(left, right) DefTableKeyList left, right;
#endif

{ DefTableKeyList temp = NULLDefTableKeyList;
  while (left != NULLDefTableKeyList) {
    if (!ElemInDefTableKeyList(HeadDefTableKeyList(left), right, CmpKey))
      temp = ConsDefTableKeyList(HeadDefTableKeyList(left), temp);
    left = TailDefTableKeyList(left);
  }
  return temp;
}


DefTableKeyList
#ifdef PROTO_OK
Intersection(DefTableKeyList left, DefTableKeyList right)
#else
Intersection(left, right) DefTableKeyList left, right;
#endif

{ DefTableKeyList temp = NULLDefTableKeyList;
  while (left != NULLDefTableKeyList) {
    if (ElemInDefTableKeyList(HeadDefTableKeyList(left), right, CmpKey))
      temp = ConsDefTableKeyList(HeadDefTableKeyList(left), temp);
    left = TailDefTableKeyList(left);
  }
  return temp;
}


static Obstack SetObstk;

SetBindingState
#ifdef PROTO_OK
FirstSetBinding(DefTableKeyList SetKeys)
#else
FirstSetBinding(SetKeys) DefTableKeyList SetKeys;
#endif
{ OneSetBinding temp;

  if (SetKeys == NULLDefTableKeyList) return NoSetBinding;

  do {
    temp.KeyForSet = HeadDefTableKeyList(SetKeys);
    temp.ElementsRemaining = GetTypeSet(temp.KeyForSet, NULLDefTableKeyList);
    ResetBoundType(
      temp.KeyForSet,
      HeadDefTableKeyList(temp.ElementsRemaining));
    obstack_grow(&SetObstk, &temp, sizeof(temp));
    SetKeys = TailDefTableKeyList(SetKeys);
  } while (SetKeys != NULLDefTableKeyList);

  temp.KeyForSet = NoKey; temp.ElementsRemaining = NULLDefTableKeyList;
  return NextSetBinding(
    (SetBindingState)obstack_copy(&SetObstk, &temp, sizeof(temp)));
}

SetBindingState
#ifdef PROTO_OK
NextSetBinding(SetBindingState last)
#else
NextSetBinding(last) SetBindingState last;
#endif
{ SetBindingState current;

  for (current = last; current->KeyForSet != NoKey; current++) {
    current->ElementsRemaining=TailDefTableKeyList(current->ElementsRemaining);
    if (current->ElementsRemaining != NULLDefTableKeyList) {
      ResetBoundType(
        current->KeyForSet,
        HeadDefTableKeyList(current->ElementsRemaining));
      return last;
    }
    current->ElementsRemaining=
      GetTypeSet(current->KeyForSet,NULLDefTableKeyList);
    ResetBoundType(
      current->KeyForSet,
      HeadDefTableKeyList(current->ElementsRemaining));
  }

  obstack_free(&SetObstk, last);
  return NoSetBinding;
}

void InitSetBinding() { obstack_init(&SetObstk); }


void
#ifdef PROTO_OK
AddCoercions(DefTableKey OpName)
#else
AddCoercions(OpName) DefTableKey OpName;
#endif
{ tOilOpList ops;

  for (ops = GetOperator(OpName, NULLtOilOpList);
       ops != NULLtOilOpList;
       ops = TailtOilOpList(ops))
    OilAddCoercion(HeadtOilOpList(ops));
}


void
#ifdef PROTO_OK
AddClassCoercions(DefTableKey OpName)
#else
AddClassCoercions(OpName) DefTableKey OpName;
#endif
{ tOilClassOpList ops;

  for (ops = GetClassOperator(OpName, NULLtOilClassOpList);
       ops != NULLtOilClassOpList;
       ops = TailtOilClassOpList(ops))
    OilAddClassCoercion(HeadtOilClassOpList(ops));
}


void
#ifdef PROTO_OK
AddIdentifications(tOilOp Indication, DefTableKey OpName)
#else
AddIdentifications(Indication, OpName) tOilOp Indication; DefTableKey OpName;
#endif
{ tOilOpList ops;
  tOilClassOpList cops;

  for (ops = GetOperator(OpName, NULLtOilOpList);
       ops != NULLtOilOpList;
       ops = TailtOilOpList(ops))
    OilAddIdentification(Indication, HeadtOilOpList(ops));

  for (cops = GetClassOperator(OpName, NULLtOilClassOpList);
       cops != NULLtOilClassOpList;
       cops = TailtOilClassOpList(cops))
    OilAddClassOpId(Indication, HeadtOilClassOpList(cops));
}

