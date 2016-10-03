
#include <string.h>
#include "obstack.h"
#include "csm.h"
#include "idn.h"
#include "clp.h"
#include "pdl_gen.h"
#include "termcode.h"
#include "Analysis.h"

int Warn = '@';        /* Standard FunnelWeb warning character */

int
#ifdef PROTO_OK
MakePtgSym(int sym)
#else
MakePtgSym(sym) int sym;
#endif

/* Obtain a possible LIDO rule name from a PTG template name
 *   On entry-
 *     sym=string table index of the template name
 *   If the template name format is appropriate then on exit-
 *     MakePtgSym=string table index of a possible LIDO rule name
 *   Else on exit-
 *     MakePtgSym=NoStrIndex
 ***/
{ char *str;
  CONST char *prefix = StringTable(GetClpValue(Prefix, NoStrIndex));
  int len = strlen(prefix);
  int t = xIdentifier, s;

  str = StringTable(sym);
  if (strncmp(str, prefix, len) == 0 && str[len] == '_') {
    str += len + 1;
    if (str[0] == '2' || str[0] == '1') str++;
    mkidn(str, strlen(str), &t, &s);
    return s;
  } else
    return NoStrIndex;
}


void
#ifdef PROTO_OK 
FixPtgGiven(int sym, DefTableKey key)
#else
FixPtgGiven(sym, key) int sym; DefTableKey key;
#endif

/* Check whether the template corresponds to a LIDO name
 *   On entry-
 *     sym is string table index of the PTG template name
 *     key is the key bound to the supposed LIDO name
 *   On exit-
 *     The appropriate property of the LIDO name has been set
 ***/
{ CONST char *str;
  CONST char *prefix = StringTable(GetClpValue(Prefix, NoStrIndex));
  int len = strlen(prefix);

  str = StringTable(sym);
  if (strncmp(str, prefix, len) == 0 && str[len] == '_') {
    switch (str[len + 1]) {
    case '1': ResetNoPtg1Given(key, 0); break;
    case '2': ResetNoPtg2Given(key, 0); break;
    default:  ResetNoPtgGiven(key, 0);
    }
  }
}


int
#ifdef PROTO_OK 
FwOut(int sym, int warn)
#else
FwOut(sym, warn) int sym, warn;
#endif

/* Protect the FunnelWeb warning character in a string
 *   On entry-
 *     sym indexes a string to be output
 *     warn is the warning character to be protected
 *   On exit-
 *     FwOut indexes an equivalent string with each FunnelWeb warning
 *       character protected
 ***/
{ CONST char *str = StringTable(sym);
  CONST char *first = strchr(str, warn);

  if (first) {
    int code = 0;

    do {
      while (str <= first) obstack_1grow(Csm_obstk, *str++);
      obstack_1grow(Csm_obstk, warn);
      first = strchr(first + 1, warn);
    } while (first);
    while (*str) obstack_1grow(Csm_obstk, *str++);
    obstack_1grow(Csm_obstk, '\0');
    CsmStrPtr = (char *)obstack_finish(Csm_obstk);
    mkidn(CsmStrPtr, strlen(CsmStrPtr), &code, &sym);
  }
  return sym;
}

