# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/k/c--lint.specs.15604001.mapBnf"
Addop: '-'.
Addop: '+'.
AmpAmp: '&&'.
Axiom: Program.
BarBar: '||'.
Comparison: Relation.
Comparison: Relation EquEqu Relation.
Compound: '{' StatementList '}'.
Compound: '{' VariableDeclList StatementList '}'.
Condition: Disjunction.
Condition: Disjunction '?' Expression ':' Condition.
Conjunction: Comparison.
Conjunction: Conjunction AmpAmp Comparison.
Disjunction: Conjunction.
Disjunction: Disjunction BarBar Conjunction.
EquEqu: '=='.
Expression: Condition.
Expression: IdUse '=' Expression.
Factor: Notop Factor.
Factor: Primary.
Factor: Unop Factor.
IdDef: Identifier.
IdUse: Identifier.
Mulop: '/'.
Mulop: '*'.
Mulop: '%'.
Notop: '!'.
OptInitialize: .
OptInitialize: '=' Expression.
ParameterDecl: 'float' IdDef.
ParameterDecl: 'int' IdDef.
ParameterList: ParameterDecl.
ParameterList: ParameterList ',' ParameterDecl.
Primary: '(' Expression ')'.
Primary: FloatDenotation.
Primary: IdUse.
Primary: IntDenotation.
Program: ResultType Identifier '(' ParameterList ')' Compound.
Relation: Sum.
Relation: Sum Relop Sum.
Relop: '<'.
Relop: '>'.
ResultType: 'float'.
ResultType: 'int'.
Statement: ';'.
Statement: 'break' ';'.
Statement: Compound.
Statement: 'continue' ';'.
Statement: Expression ';'.
Statement: 'if' '(' Expression ')' Statement $'else'.
Statement: 'if' '(' Expression ')' Statement 'else' Statement.
StatementList: Statement.
StatementList: StatementList Statement.
Statement: 'return' Expression ';'.
Statement: WhileStmt.
Sum: Sum Addop Term.
Sum: Term.
Term: Factor.
Term: Term Mulop Factor.
Unop: '-'.
VariableDecl: IdDef OptInitialize.
VariableDeclList: VariableDeclList VariableDeclSeg.
VariableDeclList: VariableDeclSeg.
VariableDeclSeg: 'float' VarIdList ';'.
VariableDeclSeg: 'int' VarIdList ';'.
VarIdList: VariableDecl.
VarIdList: VarIdList ',' VariableDecl.
WhileStmt: 'while' '(' Expression ')' Statement.
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/k/c--lint.specs.15605505.ligaProd"
RULE MonadicExp:	Expression ::= Unop Expression END;
RULE DyadicExp:	Expression ::= Expression Binop Expression END;
RULE IdnVal:	Expression ::= IdUse END;
RULE FloatVal:	Expression ::= FloatDenotation END;
RULE IntVal:	Expression ::= IntDenotation END;
RULE FloatParDecl:	ParameterDecl ::= 'float' IdDef END;
RULE IntParDecl:	ParameterDecl ::= 'int' IdDef END;
RULE Initialize:	OptInitialize ::= '=' Expression END;
RULE VarDecl:	VariableDecl ::= IdDef OptInitialize END;
RULE FloatVar:	VariableDeclSeg ::= 'float' VarIdList ';' END;
RULE IntVar:	VariableDeclSeg ::= 'int' VarIdList ';' END;
RULE UMinusOp:	Unop ::= '-' END;
RULE PercentOp:	Binop ::= '%' END;
RULE SlashOp:	Binop ::= '/' END;
RULE StarOp:	Binop ::= '*' END;
RULE MinusOp:	Binop ::= '-' END;
RULE PlusOp:	Binop ::= '+' END;
RULE GreaterOp:	Binop ::= '>' END;
RULE LessOp:	Binop ::= '<' END;
RULE EqualOp:	Binop ::= '==' END;
RULE ExclOp:	Notop ::= '!' END;
RULE NotExp:	Expression ::= Notop Expression END;
RULE AmpOp:	ShortCircuitOp ::= '&&' END;
RULE BarOp:	ShortCircuitOp ::= '||' END;
RULE ShortCircuitExp:	Expression ::= Expression ShortCircuitOp Expression END;
RULE CondExp:	Expression ::= Expression '?' Expression ':' Expression END;
RULE AssignExp:	Expression ::= IdUse '=' Expression END;
RULE ExprStmt:	Statement ::= Expression ';' END;
RULE FloatResult:	ResultType ::= 'float' END;
RULE IntResult:	ResultType ::= 'int' END;
RULE Source:	Program ::= ResultType Identifier '(' ParameterList ')' Compound END;
RULE ReturnStmt:	Statement ::= 'return' Expression ';' END;
RULE ContinueStmt:	Statement ::= 'continue' ';' END;
RULE BreakStmt:	Statement ::= 'break' ';' END;
RULE Loop:	WhileStmt ::= 'while' '(' Expression ')' Statement END;
RULE TwoSided:	Statement ::= 'if' '(' Expression ')' Statement 'else' Statement END;
RULE OneSided:	Statement ::= 'if' '(' Expression ')' Statement END;
RULE AppliedOccurrence:	IdUse ::= Identifier END;
RULE DefiningOccurrence:	IdDef ::= Identifier END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/k/c--lint.specs.15608065.SymToMap"
MAPSYM
# 0 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/h/cminus.sym.15868746.sym"



Expression ::=
  Condition Disjunction Conjunction Comparison Relation Sum
  Term Factor Primary .

ShortCircuitOp ::=
  BarBar AmpAmp .

Binop ::=
  EquEqu Relop Addop Mulop .

