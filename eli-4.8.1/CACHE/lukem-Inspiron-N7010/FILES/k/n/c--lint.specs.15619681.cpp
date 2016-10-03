# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/k/cminus.lido.15935458.lidoEta"


RULE DefiningOccurrence: IdDef ::= Identifier
COMPUTE IdDef.Sym=Identifier;
END;

RULE AppliedOccurrence: IdUse ::= Identifier
COMPUTE IdUse.Sym=Identifier;
END;


SYMBOL Program INHERITS Root END;
SYMBOL Compound INHERITS Range END;

ATTR Env: Environment;
ATTR Sym: int;
ATTR Key: DefTableKey;

CHAIN AllEarlierRenamed: VOID;

SYMBOL Root INHERITS Range COMPUTE
  INH.Env = NewEnv();
  CHAINSTART HEAD.AllEarlierRenamed="yes";
END;

SYMBOL Range COMPUTE
  INH.Env = NewScope(INCLUDING Range.Env);
END;

SYMBOL IdDef COMPUTE
  SYNT.Key=
    DefineIdn(INCLUDING Range.Env, THIS.Sym) DEPENDS_ON THIS.AllEarlierRenamed;
  THIS.AllEarlierRenamed=THIS.AllEarlierRenamed DEPENDS_ON THIS.Key;
END;

SYMBOL IdUse COMPUTE
  SYNT.Key=
    KeyInEnv(INCLUDING Range.Env, THIS.Sym) DEPENDS_ON THIS.AllEarlierRenamed;
  THIS.AllEarlierRenamed=THIS.AllEarlierRenamed DEPENDS_ON THIS.Key;
END;


SYMBOL Root COMPUTE
  INH.GotAllDefs = CONSTITUENTS IdDef.Def;
END;

SYMBOL IdDef COMPUTE
  SYNT.Def = SetDef(THIS.Key, 1, 2);
  IF(EQ(GetDef(THIS.Key,0), 2),
    message(FATAL, "Multiply-defined identifier", 0, COORDREF))
    DEPENDS_ON INCLUDING Root.GotAllDefs;
END;


SYMBOL IdUse COMPUTE
  IF(EQ(THIS.Key, NoKey), message(FATAL, "Undefined identifier", 0, COORDREF));
END;



RULE OneSided: Statement ::= 'if' '(' Expression ')' Statement
COMPUTE Expression.yields=OilTypeint_t;
END;

RULE TwoSided: Statement ::= 'if' '(' Expression ')' Statement 'else' Statement
COMPUTE Expression.yields=OilTypeint_t;
END;

RULE Loop: WhileStmt ::= 'while' '(' Expression ')' Statement
COMPUTE Expression.yields=OilTypeint_t;
END;

ATTR BreakLbl: DefTableKey;

SYMBOL WhileStmt COMPUTE SYNT.BreakLbl=NewKey(); END;
SYMBOL Program COMPUTE SYNT.BreakLbl=NoKey; END;

RULE BreakStmt: Statement ::= 'break' ';'
COMPUTE
  IF(EQ(INCLUDING (WhileStmt.BreakLbl, Program.BreakLbl), NoKey),
    message(FATAL, "break must be inside an iteration", 0, COORDREF));
END;

ATTR ContinueLbl: DefTableKey;

SYMBOL WhileStmt COMPUTE SYNT.ContinueLbl=NewKey(); END;
SYMBOL Program COMPUTE SYNT.ContinueLbl=NoKey; END;

RULE ContinueStmt: Statement ::= 'continue' ';'
COMPUTE
  IF(EQ(INCLUDING (WhileStmt.ContinueLbl, Program.ContinueLbl), NoKey),
    message(FATAL, "continue must be inside an iteration", 0, COORDREF));
END;

RULE ReturnStmt: Statement ::= 'return' Expression ';'
COMPUTE
  .operator=
    OilIdOpTS1(INCLUDING Program.type, OilOpReturn, Expression.possible);
  IF(NOT(OilIsValidOp(.operator)),
    message(FATAL, "Returned value incompatible with program type",
            0, COORDREF));
  Expression.yields=OilGetArgType(.operator,1);
END;

RULE Source: Program ::= ResultType Identifier '(' ParameterList ')' Compound
COMPUTE Program.type=ResultType.type;
END;

RULE IntResult: ResultType ::= 'int'
COMPUTE ResultType.type=OilTypeint_t;
END;

RULE FloatResult: ResultType ::= 'float'
COMPUTE ResultType.type=OilTypefloat_t;
END;

RULE ExprStmt: Statement ::= Expression ';'
COMPUTE Expression.yields=OilTypevoid_t;
END;



RULE AssignExp: Expression ::= IdUse '=' Expression
COMPUTE
  .possible=
    OilTypeToSet(GetType(IdUse.Key, OilTypeunknown_t))
    DEPENDS_ON INCLUDING Program.GotAllTypes;
  .operator=
    OilIdOpTS2(
      Expression[1].yields,
      OilOpEqual,
      .possible,
      Expression[2].possible);
  Expression[1].possible=
    OilIdResultTS2(
      OilOpEqual,
      .possible,
      Expression[2].possible);
  Expression[2].yields=OilGetArgType(.operator,2);
END;


RULE CondExp: Expression ::= Expression '?' Expression ':' Expression
COMPUTE
  Expression[1].possible=
    OilTypeToSet(OilBalance(Expression[3].possible,Expression[4].possible));
  Expression[2].yields=OilTypeint_t;
  Expression[3].yields=Expression[1].yields;
  Expression[4].yields=Expression[1].yields;
END;


SYMBOL ShortCircuitOp INHERITS Operator END;

RULE ShortCircuitExp: Expression ::= Expression ShortCircuitOp Expression
COMPUTE 
          Expression[1].possible=
            OilIdResultTS2(
              ShortCircuitOp.indication,
              Expression[2].possible,
              Expression[3].possible);
          ShortCircuitOp.operator=
            OilIdOpTS2(
              Expression[1].yields,
              ShortCircuitOp.indication,
              Expression[2].possible,
              Expression[3].possible);
          Expression[2].yields=OilGetArgType(ShortCircuitOp.operator,1);
          Expression[3].yields=OilGetArgType(ShortCircuitOp.operator,2);
        
END;

RULE BarOp: ShortCircuitOp ::= '||'
COMPUTE ShortCircuitOp.indication=OilOpBarBar;
END;

RULE AmpOp: ShortCircuitOp ::= '&&'
COMPUTE ShortCircuitOp.indication=OilOpAmpAmp;
END;

SYMBOL Notop INHERITS Operator END;

RULE NotExp: Expression ::= Notop Expression
COMPUTE 
          Expression[1].possible=
            OilIdResultTS1(
              Notop.indication,
              Expression[2].possible);
          Notop.operator=
            OilIdOpTS1(
              Expression[1].yields,
              Notop.indication,
              Expression[2].possible);
          Expression[2].yields=OilGetArgType(Notop.operator,1);
        
END;

RULE ExclOp: Notop ::= '!'
COMPUTE Notop.indication=OilOpExclam;
END;


RULE EqualOp: Binop ::= '=='
COMPUTE Binop.indication=OilOpEquEqu;
END;

RULE LessOp: Binop ::= '<'
COMPUTE Binop.indication=OilOpLess;
END;

RULE GreaterOp: Binop ::= '>'
COMPUTE Binop.indication=OilOpGreater;
END;


RULE PlusOp: Binop ::= '+'
COMPUTE Binop.indication=OilOpPlus;
END;

RULE MinusOp: Binop ::= '-'
COMPUTE Binop.indication=OilOpMinus;
END;

RULE StarOp: Binop ::= '*'
COMPUTE Binop.indication=OilOpStar;
END;

RULE SlashOp: Binop ::= '/'
COMPUTE Binop.indication=OilOpSlash;
END;

RULE PercentOp: Binop ::= '%'
COMPUTE Binop.indication=OilOpPercent;
END;

RULE UMinusOp: Unop ::= '-'
COMPUTE Unop.indication=OilOpUMinus;
END;



SYMBOL Program COMPUTE
  SYNT.GotAllTypes=CONSTITUENTS (VariableDecl.GotType, ParameterDecl.GotType);
END;

ATTR type: tOilType;

RULE IntVar: VariableDeclSeg ::= 'int' VarIdList ';'
COMPUTE VariableDeclSeg.type=OilTypeint_t;
END;

RULE FloatVar: VariableDeclSeg ::= 'float' VarIdList ';'
COMPUTE VariableDeclSeg.type=OilTypefloat_t;
END;

RULE VarDecl: VariableDecl ::= IdDef OptInitialize
COMPUTE
  VariableDecl.GotType=
    SetType(IdDef.Key, INCLUDING VariableDeclSeg.type, 0);
END;

RULE Initialize: OptInitialize ::= '=' Expression
COMPUTE Expression.yields=INCLUDING VariableDeclSeg.type;
END;

RULE IntParDecl: ParameterDecl ::= 'int' IdDef
COMPUTE
  ParameterDecl.GotType=SetType(IdDef.Key, OilTypeint_t, 0);
END;

RULE FloatParDecl: ParameterDecl ::= 'float' IdDef
COMPUTE
  ParameterDecl.GotType=SetType(IdDef.Key, OilTypefloat_t, 0);
END;

ATTR possible: tOilTypeSet;
ATTR yields: tOilType;

RULE IntVal: Expression ::= IntDenotation
COMPUTE Expression.possible=OilTypeToSet(OilTypeint_t);
END;

RULE FloatVal: Expression ::= FloatDenotation
COMPUTE Expression.possible=OilTypeToSet(OilTypefloat_t);
END;

RULE IdnVal: Expression ::= IdUse
COMPUTE
  Expression.possible=
    OilTypeToSet(GetType(IdUse.Key, OilTypeunknown_t))
    DEPENDS_ON INCLUDING Program.GotAllTypes;
END;

ATTR indication, operator: tOilOp;

SYMBOL Binop INHERITS Operator END;

RULE DyadicExp: Expression ::= Expression Binop Expression
COMPUTE 
          Expression[1].possible=
            OilIdResultTS2(
              Binop.indication,
              Expression[2].possible,
              Expression[3].possible);
          Binop.operator=
            OilIdOpTS2(
              Expression[1].yields,
              Binop.indication,
              Expression[2].possible,
              Expression[3].possible);
          Expression[2].yields=OilGetArgType(Binop.operator,1);
          Expression[3].yields=OilGetArgType(Binop.operator,2);
        
END;

SYMBOL Unop INHERITS Operator END;

RULE MonadicExp: Expression ::= Unop Expression
COMPUTE 
          Expression[1].possible=
            OilIdResultTS1(
              Unop.indication,
              Expression[2].possible);
          Unop.operator=
            OilIdOpTS1(
              Expression[1].yields,
              Unop.indication,
              Expression[2].possible);
          Expression[2].yields=OilGetArgType(Unop.operator,1);
        
END;

SYMBOL Operator COMPUTE
  IF(NOT(OilIsValidOp(THIS.operator)),
    message(FATAL, "Invalid operator in this context", 0, COORDREF));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/m/abstree.lido.16028488.lidoEta"
RULE rule_1:
Axiom ::= Program
END;

RULE rule_2:
Compound ::= '{' StatementList '}'
END;

RULE rule_3:
Compound ::= '{' VariableDeclList StatementList '}'
END;

RULE rule_4:
OptInitialize ::= 
END;

RULE rule_5:
ParameterList ::= ParameterDecl
END;

RULE rule_6:
ParameterList ::= ParameterList ',' ParameterDecl
END;

RULE rule_7:
Statement ::= ';'
END;

RULE rule_8:
Statement ::= Compound
END;

RULE rule_9:
StatementList ::= Statement
END;

RULE rule_10:
StatementList ::= StatementList Statement
END;

RULE rule_11:
Statement ::= WhileStmt
END;

RULE rule_12:
VariableDeclList ::= VariableDeclList VariableDeclSeg
END;

RULE rule_13:
VariableDeclList ::= VariableDeclSeg
END;

RULE rule_14:
VarIdList ::= VariableDecl
END;

RULE rule_15:
VarIdList ::= VarIdList ',' VariableDecl
END;

RULE MonadicExp:
Expression ::= Unop Expression
END;

RULE DyadicExp:
Expression ::= Expression Binop Expression
END;

RULE IdnVal:
Expression ::= IdUse
END;

RULE FloatVal:
Expression ::= FloatDenotation
END;

RULE IntVal:
Expression ::= IntDenotation
END;

RULE FloatParDecl:
ParameterDecl ::= 'float' IdDef
END;

RULE IntParDecl:
ParameterDecl ::= 'int' IdDef
END;

RULE Initialize:
OptInitialize ::= '=' Expression
END;

RULE VarDecl:
VariableDecl ::= IdDef OptInitialize
END;

RULE FloatVar:
VariableDeclSeg ::= 'float' VarIdList ';'
END;

RULE IntVar:
VariableDeclSeg ::= 'int' VarIdList ';'
END;

RULE UMinusOp:
Unop ::= '-'
END;

RULE PercentOp:
Binop ::= '%'
END;

RULE SlashOp:
Binop ::= '/'
END;

RULE StarOp:
Binop ::= '*'
END;

RULE MinusOp:
Binop ::= '-'
END;

RULE PlusOp:
Binop ::= '+'
END;

RULE GreaterOp:
Binop ::= '>'
END;

RULE LessOp:
Binop ::= '<'
END;

RULE EqualOp:
Binop ::= '=='
END;

RULE ExclOp:
Notop ::= '!'
END;

RULE NotExp:
Expression ::= Notop Expression
END;

RULE AmpOp:
ShortCircuitOp ::= '&&'
END;

RULE BarOp:
ShortCircuitOp ::= '||'
END;

RULE ShortCircuitExp:
Expression ::= Expression ShortCircuitOp Expression
END;

RULE CondExp:
Expression ::= Expression '?' Expression ':' Expression
END;

RULE AssignExp:
Expression ::= IdUse '=' Expression
END;

RULE ExprStmt:
Statement ::= Expression ';'
END;

RULE FloatResult:
ResultType ::= 'float'
END;

RULE IntResult:
ResultType ::= 'int'
END;

RULE Source:
Program ::= ResultType Identifier '(' ParameterList ')' Compound
END;

RULE ReturnStmt:
Statement ::= 'return' Expression ';'
END;

RULE ContinueStmt:
Statement ::= 'continue' ';'
END;

RULE BreakStmt:
Statement ::= 'break' ';'
END;

RULE Loop:
WhileStmt ::= 'while' '(' Expression ')' Statement
END;

RULE TwoSided:
Statement ::= 'if' '(' Expression ')' Statement 'else' Statement
END;

RULE OneSided:
Statement ::= 'if' '(' Expression ')' Statement
END;

RULE AppliedOccurrence:
IdUse ::= Identifier
END;

RULE DefiningOccurrence:
IdDef ::= Identifier
END;

