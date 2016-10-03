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
  case 1: _nst[_nsp]=Mkrule_27(&curpos, _nst[_nsp+0]); break;
  case 2: _nst[_nsp]=Mkrule_23(&curpos, _nst[_nsp+0]); break;
  case 3: _nsp -= 1;_nst[_nsp]=Mkrule_24(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 4: _nsp -= 1;_nst[_nsp]=Mkrule_7(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 5: _nsp -= 1;_nst[_nsp]=Mkrule_9(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 6: _nsp -= 1;_nst[_nsp]=Mkrule_8(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 7: _nsp -= 4;_nst[_nsp]=Mkrule_19(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2], _nst[_nsp+3], _nst[_nsp+4]); break;
  case 8: _incrnodestack();_nst[_nsp]=Mkrule_25(&curpos); break;
  case 9: _nst[_nsp]=Mkrule_21(&curpos, _nst[_nsp+0]); break;
  case 10: _incrnodestack();_nst[_nsp]=Mkrule_3(&curpos, Mkident(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 12: _incrnodestack();_nst[_nsp]=Mkrule_22(&curpos, Mklit(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 13: _incrnodestack();_nst[_nsp]=Mkrule_20(&curpos, Mklit(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 14: _incrnodestack();_nst[_nsp]=Mkrule_6(&curpos, Mklit(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 15: _nsp -= 1;_nst[_nsp]=Mkrule_26(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 16: _incrnodestack();_nst[_nsp]=Mkrule_4(&curpos); break;
  case 17: _incrnodestack();_nst[_nsp]=Mkrule_11(&curpos); break;
  case 18: _incrnodestack();_nst[_nsp]=Mkrule_10(&curpos); break;
  case 19: _incrnodestack();_nst[_nsp]=Mkrule_12(&curpos); break;
  case 20: _incrnodestack();_nst[_nsp]=Mkrule_1(&curpos, Mklit(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 21: _incrnodestack();_nst[_nsp]=Mkrule_2(&curpos); break;
  case 22: _incrnodestack();_nst[_nsp]=Mkrule_5(&curpos, Mklit(&(T_POS(TokenStack(3))), T_ATTR(TokenStack(3)))); break;
  case 23: _incrnodestack();_nst[_nsp]=Mkrule_18(&curpos); break;
  case 24: _incrnodestack();_nst[_nsp]=Mkrule_17(&curpos); break;
  case 25: _incrnodestack();_nst[_nsp]=Mkrule_16(&curpos); break;
  case 26: _incrnodestack();_nst[_nsp]=Mkrule_15(&curpos); break;
  case 27: _incrnodestack();_nst[_nsp]=Mkrule_14(&curpos); break;
  case 28: _incrnodestack();_nst[_nsp]=Mkrule_13(&curpos); break;
  } /* end switch */
}
