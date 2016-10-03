/* implementation of monitoring support for attribution */

#ifdef MONITOR

#include "node.h"
#include "treecon.h"
#include"nodecode.h"
#include"eliproto.h"

CONST char *abs_prods[] = {
  "{AssignExp} {Expression} { IdUse '=' Expression}",
  "{CondExp} {Expression} { Expression '?' Expression ':' Expression}",
  "{ShortCircuitExp} {Expression} { Expression ShortCircuitOp Expression}",
  "{NotExp} {Expression} { Notop Expression}",
  "{IntVal} {Expression} { IntDenotation}",
  "{FloatVal} {Expression} { FloatDenotation}",
  "{IdnVal} {Expression} { IdUse}",
  "{DyadicExp} {Expression} { Expression Binop Expression}",
  "{MonadicExp} {Expression} { Unop Expression}",
  "{DefiningOccurrence} {IdDef} { Identifier}",
  "{OneSided} {Statement} { 'if' '(' Expression ')' Statement}",
  "{TwoSided} {Statement} { 'if' '(' Expression ')' Statement 'else' Statement}",
  "{Loop} {WhileStmt} { 'while' '(' Expression ')' Statement}",
  "{BreakStmt} {Statement} { 'break' ';'}",
  "{ContinueStmt} {Statement} { 'continue' ';'}",
  "{ReturnStmt} {Statement} { 'return' Expression ';'}",
  "{Source} {Program} { ResultType Identifier '(' ParameterList ')' Compound}",
  "{ExprStmt} {Statement} { Expression ';'}",
  "{BarOp} {ShortCircuitOp} { '||'}",
  "{AmpOp} {ShortCircuitOp} { '&&'}",
  "{ExclOp} {Notop} { '!'}",
  "{EqualOp} {Binop} { '=='}",
  "{LessOp} {Binop} { '<'}",
  "{GreaterOp} {Binop} { '>'}",
  "{PlusOp} {Binop} { '+'}",
  "{MinusOp} {Binop} { '-'}",
  "{StarOp} {Binop} { '*'}",
  "{SlashOp} {Binop} { '/'}",
  "{PercentOp} {Binop} { '%'}",
  "{UMinusOp} {Unop} { '-'}",
  "{IntVar} {VariableDeclSeg} { 'int' VarIdList ';'}",
  "{FloatVar} {VariableDeclSeg} { 'float' VarIdList ';'}",
  "{VarDecl} {VariableDecl} { IdDef OptInitialize}",
  "{Initialize} {OptInitialize} { '=' Expression}",
  "{IntParDecl} {ParameterDecl} { 'int' IdDef}",
  "{FloatParDecl} {ParameterDecl} { 'float' IdDef}",
  "{rule_2} {Compound} { '{' StatementList '}'}",
  "{rule_3} {Compound} { '{' VariableDeclList StatementList '}'}",
  "{rule_4} {OptInitialize} {}",
  "{rule_5} {ParameterList} { ParameterDecl}",
  "{rule_6} {ParameterList} { ParameterList ',' ParameterDecl}",
  "{rule_7} {Statement} { ';'}",
  "{rule_8} {Statement} { Compound}",
  "{rule_9} {StatementList} { Statement}",
  "{rule_10} {StatementList} { StatementList Statement}",
  "{rule_11} {Statement} { WhileStmt}",
  "{rule_12} {VariableDeclList} { VariableDeclList VariableDeclSeg}",
  "{rule_13} {VariableDeclList} { VariableDeclSeg}",
  "{rule_14} {VarIdList} { VariableDecl}",
  "{rule_15} {VarIdList} { VarIdList ',' VariableDecl}",
  "{AppliedOccurrence} {IdUse} { Identifier}",
  "{IntResult} {ResultType} { 'int'}",
  "{FloatResult} {ResultType} { 'float'}",
  "{rule_1} {Axiom} { Program}",
  (char *) 0
};

int abs_nchild[] = {
  2,
  3,
  3,
  2,
  0,
  0,
  1,
  3,
  2,
  0,
  2,
  3,
  2,
  0,
  0,
  1,
  3,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  2,
  1,
  1,
  1,
  1,
  2,
  0,
  1,
  2,
  0,
  1,
  1,
  2,
  1,
  2,
  1,
  1,
  2,
  0,
  0,
  0,
  1,
};


#if defined(__STDC__) || defined(__cplusplus)
NODEPTR abs_child (NODEPTR n, int c)
#else
NODEPTR abs_child (n, c)
  NODEPTR n;
  int c;
#endif
{
  switch (n->_prod) {
    case RULEAssignExp: {
      _TPPAssignExp m = (_TPPAssignExp) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULECondExp: {
      _TPPCondExp m = (_TPPCondExp) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        case 3: return (NODEPTR) m->_desc3; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEShortCircuitExp: {
      _TPPShortCircuitExp m = (_TPPShortCircuitExp) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        case 3: return (NODEPTR) m->_desc3; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULENotExp: {
      _TPPNotExp m = (_TPPNotExp) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEIdnVal: {
      _TPPIdnVal m = (_TPPIdnVal) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEDyadicExp: {
      _TPPDyadicExp m = (_TPPDyadicExp) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        case 3: return (NODEPTR) m->_desc3; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEMonadicExp: {
      _TPPMonadicExp m = (_TPPMonadicExp) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEOneSided: {
      _TPPOneSided m = (_TPPOneSided) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULETwoSided: {
      _TPPTwoSided m = (_TPPTwoSided) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        case 3: return (NODEPTR) m->_desc3; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULELoop: {
      _TPPLoop m = (_TPPLoop) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEReturnStmt: {
      _TPPReturnStmt m = (_TPPReturnStmt) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULESource: {
      _TPPSource m = (_TPPSource) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        case 3: return (NODEPTR) m->_desc3; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEExprStmt: {
      _TPPExprStmt m = (_TPPExprStmt) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEIntVar: {
      _TPPIntVar m = (_TPPIntVar) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEFloatVar: {
      _TPPFloatVar m = (_TPPFloatVar) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEVarDecl: {
      _TPPVarDecl m = (_TPPVarDecl) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEInitialize: {
      _TPPInitialize m = (_TPPInitialize) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEIntParDecl: {
      _TPPIntParDecl m = (_TPPIntParDecl) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULEFloatParDecl: {
      _TPPFloatParDecl m = (_TPPFloatParDecl) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_2: {
      _TPPrule_2 m = (_TPPrule_2) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_3: {
      _TPPrule_3 m = (_TPPrule_3) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_5: {
      _TPPrule_5 m = (_TPPrule_5) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_6: {
      _TPPrule_6 m = (_TPPrule_6) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_8: {
      _TPPrule_8 m = (_TPPrule_8) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_9: {
      _TPPrule_9 m = (_TPPrule_9) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_10: {
      _TPPrule_10 m = (_TPPrule_10) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_11: {
      _TPPrule_11 m = (_TPPrule_11) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_12: {
      _TPPrule_12 m = (_TPPrule_12) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_13: {
      _TPPrule_13 m = (_TPPrule_13) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_14: {
      _TPPrule_14 m = (_TPPrule_14) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_15: {
      _TPPrule_15 m = (_TPPrule_15) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        case 2: return (NODEPTR) m->_desc2; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    case RULErule_1: {
      _TPPrule_1 m = (_TPPrule_1) n;
      switch (c) {
        case 1: return (NODEPTR) m->_desc1; break;
        default:
          return (NODEPTR) 0;
      }
      break;
    }
    default:
        return (NODEPTR) 0;
  }
}

#else
/* To avoid messages about empty files */
static int _dapto;
#endif
