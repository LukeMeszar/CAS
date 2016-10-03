
#ifndef BUILD_H
#define BUILD_H

#include "eliproto.h"
#include "deftbl.h"
#include "oiladt2.h"
#include "DefTableKeyList.h"
#include "tOilOpList.h"
#include "tOilClassOpList.h"


typedef struct {
  DefTableKey KeyForSet;
  DefTableKeyList ElementsRemaining;
} OneSetBinding, *SetBindingState;

#define NoSetBinding (SetBindingState)0



extern int CmpKey ELI_ARG((DefTableKey, DefTableKey));


extern DefTableKeyList Union ELI_ARG((DefTableKeyList, DefTableKeyList));
extern DefTableKeyList Difference ELI_ARG((DefTableKeyList, DefTableKeyList));
extern DefTableKeyList Intersection ELI_ARG((DefTableKeyList, DefTableKeyList));
extern SetBindingState FirstSetBinding ELI_ARG((DefTableKeyList));
extern SetBindingState NextSetBinding ELI_ARG((SetBindingState));
extern void AddCoercions ELI_ARG((DefTableKey));
extern void AddClassCoercions ELI_ARG((DefTableKey));
extern void AddIdentifications ELI_ARG((tOilOp, DefTableKey));

#endif
