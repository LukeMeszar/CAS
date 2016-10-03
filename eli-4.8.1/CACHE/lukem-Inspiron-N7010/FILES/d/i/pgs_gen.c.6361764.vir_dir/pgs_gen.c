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
  case 1: _nst[_nsp]=Mkrule_72(&curpos, _nst[_nsp+0]); break;
  case 2: _nst[_nsp]=Mkrule_73(&curpos, _nst[_nsp+0]); break;
  case 3: _nsp -= 1;_nst[_nsp]=Mkrule_49(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 4: _nst[_nsp]=Mkrule_74(&curpos, _nst[_nsp+0]); break;
  case 5: _nst[_nsp]=Mkrule_75(&curpos, _nst[_nsp+0]); break;
  case 6: _nst[_nsp]=Mkrule_52(&curpos, _nst[_nsp+0]); break;
  case 7: _nst[_nsp]=Mkrule_55(&curpos, _nst[_nsp+0]); break;
  case 8: _nst[_nsp]=Mkrule_51(&curpos, _nst[_nsp+0]); break;
  case 9: _nst[_nsp]=Mkrule_57(&curpos, _nst[_nsp+0]); break;
  case 10: _nsp -= 1;_nst[_nsp]=Mkrule_7(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 11: _nsp -= 1;_nst[_nsp]=Mkrule_53(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 12: _nsp -= 1;_nst[_nsp]=Mkrule_50(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 13: _nsp -= 1;_nst[_nsp]=Mkrule_56(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 14: _nst[_nsp]=Mkrule_62(&curpos, _nst[_nsp+0]); break;
  case 15: _nst[_nsp]=Mkrule_14(&curpos, _nst[_nsp+0]); break;
  case 16: _nsp -= 1;_nst[_nsp]=Mkrule_54(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 17: _nst[_nsp]=Mkrule_21(&curpos, _nst[_nsp+0]); break;
  case 18: _nst[_nsp]=Mkrule_59(&curpos, _nst[_nsp+0]); break;
  case 19: _nst[_nsp]=Mkrule_16(&curpos, _nst[_nsp+0]); break;
  case 20: _nst[_nsp]=Mkrule_48(&curpos, _nst[_nsp+0]); break;
  case 21: _nsp -= 1;_nst[_nsp]=Mkrule_63(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 22: _nst[_nsp]=Mkrule_60(&curpos, _nst[_nsp+0]); break;
  case 23: _nsp -= 1;_nst[_nsp]=Mkrule_13(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 24: _nsp -= 1;_nst[_nsp]=Mkrule_18(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 25: _nsp -= 1;_nst[_nsp]=Mkrule_58(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 26: _nst[_nsp]=Mkrule_43(&curpos, _nst[_nsp+0]); break;
  case 27: _nst[_nsp]=Mkrule_45(&curpos, _nst[_nsp+0]); break;
  case 28: _nst[_nsp]=Mkrule_64(&curpos, _nst[_nsp+0]); break;
  case 29: _nsp -= 1;_nst[_nsp]=Mkrule_61(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 30: _nsp -= 1;_nst[_nsp]=Mkrule_12(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 31: _nsp -= 1;_nst[_nsp]=Mkrule_12(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 32: _nsp -= 1;_nst[_nsp]=Mkrule_47(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 33: _nsp -= 1;_nst[_nsp]=Mkrule_44(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 34: _nsp -= 1;_nst[_nsp]=Mkrule_65(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 35: _nst[_nsp]=Mkrule_5(&curpos, _nst[_nsp+0]); break;
  case 36: _nsp -= 1;_nst[_nsp]=Mkrule_46(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 37: _nsp -= 1;_nst[_nsp]=Mkrule_4(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 38: _nsp -= 1;_nst[_nsp]=Mkrule_3(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 39: _nsp -= 1;_nst[_nsp]=Mkrule_3(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 40: _incrnodestack();_nst[_nsp]=Mkrule_42(&curpos); break;
  case 41: _nst[_nsp]=Mkrule_67(&curpos, _nst[_nsp+0]); break;
  case 43: _incrnodestack();_nst[_nsp]=Mkrule_28(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 44: _incrnodestack();_nst[_nsp]=Mkrule_33(&curpos); break;
  case 45: _incrnodestack();_nst[_nsp]=Mkrule_31(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 46: _incrnodestack();_nst[_nsp]=Mkrule_24(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 47: _incrnodestack();_nst[_nsp]=Mkrule_26(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 48: _nst[_nsp]=Mkrule_69(&curpos, _nst[_nsp+0]); break;
  case 49: _nst[_nsp]=Mkrule_68(&curpos, _nst[_nsp+0]); break;
  case 50: _nst[_nsp]=Mkrule_70(&curpos, _nst[_nsp+0]); break;
  case 51: _nst[_nsp]=Mkrule_66(&curpos, _nst[_nsp+0]); break;
  case 52: _incrnodestack();_nst[_nsp]=Mkrule_27(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 53: _incrnodestack();_nst[_nsp]=Mkrule_29(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 54: _incrnodestack();_nst[_nsp]=Mkrule_35(&curpos); break;
  case 55: _incrnodestack();_nst[_nsp]=Mkrule_15(&curpos); break;
  case 56: _incrnodestack();_nst[_nsp]=Mkrule_23(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 57: _incrnodestack();_nst[_nsp]=Mkrule_25(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 58: _nst[_nsp]=Mkrule_41(&curpos, _nst[_nsp+0]); break;
  case 59: _incrnodestack();_nst[_nsp]=Mkrule_34(&curpos, MkInteger(&(T_POS(TokenStack(1))), T_ATTR(TokenStack(1)))); break;
  case 60: _nsp -= 2;_nst[_nsp]=Mkrule_9(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 61: _nst[_nsp]=Mkrule_14(&curpos, _nst[_nsp+0]); break;
  case 62: _nsp -= 2;_nst[_nsp]=Mkrule_10(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 63: _nsp -= 1;_nst[_nsp]=Mkrule_22(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 64: _nst[_nsp]=Mkrule_71(&curpos, _nst[_nsp+0]); break;
  case 65: _nsp -= 1;_nst[_nsp]=Mkrule_8(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 67: _nst[_nsp]=Mkrule_76(&curpos, _nst[_nsp+0]); break;
  case 68: _nst[_nsp]=Mkrule_17(&curpos, _nst[_nsp+0]); break;
  case 69: _incrnodestack();_nst[_nsp]=Mkrule_32(&curpos); break;
  case 70: _incrnodestack();_nst[_nsp]=Mkrule_30(&curpos, MkIdentifier(&(T_POS(TokenStack(0))), T_ATTR(TokenStack(0)))); break;
  case 71: _nsp -= 1;_nst[_nsp]=Mkrule_19(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 72: _nsp -= 1;_nst[_nsp]=Mkrule_20(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 73: _nst[_nsp]=Mkrule_39(&curpos, _nst[_nsp+0]); break;
  case 74: _nst[_nsp]=Mkrule_38(&curpos, _nst[_nsp+0]); break;
  case 75: _nst[_nsp]=Mkrule_40(&curpos, _nst[_nsp+0]); break;
  case 76: _nst[_nsp]=Mkrule_36(&curpos, _nst[_nsp+0]); break;
  case 77: _nsp -= 1;_nst[_nsp]=Mkrule_37(&curpos, _nst[_nsp+0], _nst[_nsp+1]); break;
  case 78: _incrnodestack();_nst[_nsp]=Mkrule_6(&curpos); break;
  case 79: _nsp -= 2;_nst[_nsp]=Mkrule_1(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  case 80: _nst[_nsp]=Mkrule_5(&curpos, _nst[_nsp+0]); break;
  case 81: _nsp -= 2;_nst[_nsp]=Mkrule_2(&curpos, _nst[_nsp+0], _nst[_nsp+1], _nst[_nsp+2]); break;
  } /* end switch */
}
