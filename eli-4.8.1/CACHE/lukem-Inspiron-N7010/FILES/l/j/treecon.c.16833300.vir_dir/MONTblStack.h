
#ifndef MONTblSTACK_H
#define MONTblSTACK_H
#include "obstack.h"

extern Obstack MONTblStack;

#define MONTblStackEmpty \
  (obstack_next_free(&MONTblStack) == obstack_base(&MONTblStack))

#define MONTblStackSize \
  ((NODEPTR *)obstack_next_free(&MONTblStack)-(NODEPTR *)obstack_base(&MONTblStack))

#define MONTblStackTop \
  (((NODEPTR *)obstack_next_free(&MONTblStack))[-1])

#define MONTblStackPush(v) {\
  NODEPTR MONTblStackTemp; MONTblStackTemp = v; \
  obstack_grow(&MONTblStack, &MONTblStackTemp, sizeof(NODEPTR)); \
}

#define MONTblStackPop \
  (*((NODEPTR *)(obstack_next_free(&MONTblStack) -= sizeof(NODEPTR))))

#define ForEachMONTblStackElementUp(i) \
  for ((i) = (NODEPTR *)obstack_base(&MONTblStack); \
       (i) < (NODEPTR *)obstack_next_free(&MONTblStack); \
       (i)++)

#define ForEachMONTblStackElementDown(i) \
  for ((i) = ((NODEPTR *)obstack_next_free(&MONTblStack)) - 1; \
       (i) >= (NODEPTR *)obstack_base(&MONTblStack); \
       (i)--)

#define MONTblStackArray(i) \
  (((NODEPTR *)obstack_base(&MONTblStack))[i])

#define MONTblStackElement(i) \
  (((NODEPTR *)obstack_next_free(&MONTblStack))[-1-(i)])
#endif
