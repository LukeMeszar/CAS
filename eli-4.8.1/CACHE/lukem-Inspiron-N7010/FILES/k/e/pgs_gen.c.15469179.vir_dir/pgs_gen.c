/* $Id: StructConn,v 1.13 1998/10/12 06:09:57 tony Exp $ */
#include "gsdescr.h"
#include "treestack.h"
#include "HEAD.h"

#define TokenStack(i)	(ZAttributKeller[(i)])

#ifdef RIGHTCOORD
extern POSITION rightpos;
#endif

#if defined(__cplusplus) || defined(__STDC__) 
void
StrukturAnknuepfung(unsigned PR, GRUNDSYMBOLDESKRIPTOR *ZAttributKeller)
#else
void
StrukturAnknuepfung(PR, ZAttributKeller)
unsigned  PR;
register GRUNDSYMBOLDESKRIPTOR  *ZAttributKeller;
#endif
{
  curpos = ZAttributKeller->Pos;
#ifdef RIGHTCOORD
  RLineOf (curpos) = RLineOf (rightpos);
  RColOf (curpos) = RColOf (rightpos);
#ifdef MONITOR
  RCumColOf (curpos) = RCumColOf (rightpos);
#endif
#endif
  switch (PR) {
  case 1: ExprDiv(); break;
  case 2: ExprTimes(); break;
  case 3: ExprInt(0); break;
  case 4: ExprInt(1); break;
  case 5: ExprInt(2); break;
  case 6: ExprInt(3); break;
  case 7: ExprInt(4); break;
  case 8: ExprInt(5); break;
  case 9: ExprInt(6); break;
  case 10: ExprInt(7); break;
  case 11: ExprInt(8); break;
  case 12: ExprInt(9); break;
  case 13: ExprFinl(); break;
  case 16: ExprMinus(); break;
  case 17: ExprPlus(); break;
  } /* end switch */
}
