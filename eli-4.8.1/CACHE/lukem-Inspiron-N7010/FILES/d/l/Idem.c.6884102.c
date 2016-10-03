
static char RCSid[] = "$Id";

#include "obstack.h"
#include "csm.h"
#include "idn.h"

int
#ifdef PROTO_OK
FunnelWebEscape(int sym)
#else
FunnelWebEscape(sym) int sym;
#endif


/* Double each occurrence of the FunnelWeb escape charcter in a literal
 *   On entry-
 *     sym=string table index of the unmodified literal
 *   On exit-
 *     FunnelWebEscape=string table index of the modified string
 ***/
{ char ch;
  CONST char *str;
  int n, t, v = 0;

  str = StringTable(sym) + 1;
  n = 0;

  while (str[1]) {
    ch = *str++;
    obstack_1grow(Csm_obstk, ch); n++;
    if (ch == '\'') str++;      /* throw away the extra quote */
    else if (*str == '@') {
      obstack_1grow(Csm_obstk, '@');
      ++n;
    }
  }

  obstack_1grow(Csm_obstk, '\0');
  CsmStrPtr = (char *)obstack_finish(Csm_obstk);

  mkidn(CsmStrPtr, n, &t, &v);
  return v;
}


