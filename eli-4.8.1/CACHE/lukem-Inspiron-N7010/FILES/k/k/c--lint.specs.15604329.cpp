# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/h/cminus.con.15869399.con"

Axiom: Program .

Program: ResultType Identifier '(' ParameterList ')' Compound .
ResultType: 'int' / 'float' .
Compound:
  '{' VariableDeclList StatementList '}' /
  '{' StatementList '}' .


VariableDeclList: VariableDeclSeg / VariableDeclList VariableDeclSeg .
VariableDeclSeg: 'int' VarIdList ';' / 'float' VarIdList ';' .
VarIdList: VariableDecl / VarIdList ',' VariableDecl .
VariableDecl: IdDef OptInitialize .
OptInitialize: / '=' Expression .


ParameterList: ParameterDecl / ParameterList ',' ParameterDecl .
ParameterDecl: 'int' IdDef / 'float' IdDef .



StatementList: Statement / StatementList Statement .
Statement: Compound / ';' .

Statement:
  'if' '(' Expression ')' Statement $'else' /
  'if' '(' Expression ')' Statement 'else' Statement .


Statement: WhileStmt .
WhileStmt: 'while' '(' Expression ')' Statement .


Statement: 'break' ';' .


Statement: 'continue' ';' .


Statement: 'return' Expression ';' .


Statement: Expression ';' .




IdDef: Identifier .
IdUse: Identifier .


Expression: Condition / IdUse '=' Expression .
Condition: Disjunction / Disjunction '?' Expression ':' Condition .
Disjunction: Conjunction / Disjunction BarBar Conjunction .
BarBar: '||' .
Conjunction: Comparison / Conjunction AmpAmp Comparison .
AmpAmp: '&&' .
Comparison: Relation / Relation EquEqu Relation .
EquEqu: '==' .
Relation: Sum / Sum Relop Sum .
Relop: '<' / '>' .
Sum: Term / Sum Addop Term .
Addop: '+' / '-' .
Term: Factor / Term Mulop Factor .
Mulop: '*' / '/' / '%' .
Factor: Primary / Unop Factor / Notop Factor .
Unop: '-' .
Notop: '!' .
Primary: IntDenotation / FloatDenotation / IdUse / '(' Expression ')' .

