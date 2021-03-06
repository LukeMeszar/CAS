# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/Eli/tests/ignorecase/pascal.con"



pascal: OuterRoutine .
OuterRoutine: OuterRange .
OuterRange: 'program' outer '.' .
outer: Identifier ProgramParameters ';' DeclPart Compound .
ProgramParameters: '(' PgmParList ')' / .
PgmParList: PgmParm / PgmParList ',' PgmParm .
PgmParm: Identifier .

DeclPart0: LabelPart ConstPart .
DeclPart1: DeclPart0 TypePart .
DeclPart2: DeclPart1 VarPart .
DeclPart: DeclPart2 RoutinePart .

LabelPart: 'label' LblDeclList ';' / .
LblDeclList: LblDecl / LblDeclList LblTail .
LblTail: ',' LblDecl .
LblDecl: Integer .

ConstPart: 'const' ConstDefList / .
ConstDefList: ConstantDefinition / ConstDefList ConstantDefinition .
ConstantDefinition: IdDef '=' Constant ';' .

TypePart: 'Type' TypeDefList / .
TypeDefList: TypeDefinition / TypeDefList TypeDefinition .
TypeDefinition: IdDef '=' Type ';' .

VarPart: 'var' VarDeclList / .
VarDeclList: VariableDeclaration / VarDeclList VariableDeclaration .
VariableDeclaration: VarDefList ':' Type ';' .
VarDefList: VarDef / VarDefList ',' VarDef .
VarDef: IdDef .

RoutinePart: RoutineList / .
RoutineList: RoutineDeclaration / RoutineList RoutineDeclaration .

Compound: 'begin' StmtSeq 'end' .
StmtSeq: Statement / StmtSeq ';' Statement .


RoutineDeclaration:
   'procedure' FwdProcData ';' /
   'procedure' ProcData ';' /
   'function' FwdFuncData ';' /
   'function' FuncData ';' .
FwdProcData:
   Identifier ProcSignature ';' Identifier .
ProcData:
   Identifier ProcBody .
FwdFuncData:
   Identifier FuncSignature ';' Identifier .
FuncData:
   Identifier ProcBody /
   Identifier FuncBody .
ProcBody:
   ProcSignature ';' Body .
FuncBody:
   FuncSignature ';' Body .
ProcSignature:
   '(' ParameterSectionSeq ')' / .
FuncSignature:
   '(' ParameterSectionSeq ')' ':' ParmTypeId / ':' ParmTypeId .
Body: InnerRange .
InnerRange: DeclPart Compound .

ParameterSectionSeq:
   ParameterSection / ParameterSectionSeq ';' ParameterSection .
ParameterSection:
   'procedure' ParmIdDef ProcTypeSig /
   'function' ParmIdDef FuncTypeSig /
   'var' ParmDefList ':' ParmTypeId /
   ParmDefList ':' ParmTypeId .
ParmDefList: ParmDef / ParmDefList ',' ParmDef .
ParmDef: ParmIdDef .
ParmIdDef: Identifier .
ParmTypeId: Identifier .

ProcTypeSig: '(' ptypesectionSeq ')' / .
FuncTypeSig: '(' ptypesectionSeq ')' ':' ParmTypeId / ':' ParmTypeId .
ptypesectionSeq: ptypesection / ptypesectionSeq ';' ptypesection .
ptypesection:
   'procedure' ParmIdDef ProcTypeSig /
   'function' ParmIdDef FuncTypeSig /
   'var' ParmDefList ':' ParmTypeId /
   ParmDefList ':' ParmTypeId .

Statement: LbDef ':' unlabelledstatement / unlabelledstatement .
unlabelledstatement:
      Variable ':=' Expression /
      Call /
      compoundstmt /
      'if' Expression 'then' LbRangeStmt $'else' /
      'if' Expression 'then' LbRangeStmt 'else' LbRangeStmt /
      'case' Expression 'of' alternatives 'end' /
      'while' Expression 'do' LbRangeStmt /
      'repeat' LbRangeStmtSeq 'until' Expression /
      'for' IdUse ':=' Expression 'to' Expression 'do' LbRangeStmt /
      'for' IdUse ':=' Expression 'downto' Expression 'do' LbRangeStmt /
      withexpr withbody /
      'goto' LbUse /
      .
LbRangeStmt: LbRange .
LbRangeStmtSeq: LbRangeSeq .
LbRange: Statement .
LbRangeSeq: StmtSeq .
compoundstmt: 'begin' LbRangeSeq 'end' .

Call: IdUse Arguments .
Arguments: '(' argumentlist ')' / .
argumentlist: argument / argumentlist ',' argument .
argument:
   Expression /
   Expression ':' Expression /
   Expression ':' Expression ':' Expression .

alternatives: alternative / alternatives ';' alternative .
alternative: caseselectors ':' LbRange / .
caseselectors: caseselector / caseselectors ',' caseselector .
caseselector: Constant .

withexpr: 'with' Variable .
withbody: withexpnest withbody / 'do' LbRangeStmt .
withexpnest: ',' Variable .

Expression:
   simpleexpression /
   simpleexpression relop simpleexpression .
relop: '=' / '<' / '>' / '<>' / '>=' / '<=' / 'in' .

simpleexpression: uplusminus simpleexpression / unsignedexpression .
uplusminus: '+' / '-' .

unsignedexpression: term / unsignedexpression addop term .
addop: '+' / '-' / 'or' .

term: factor / term mulop factor .
mulop: '*' / '/' / 'div' / 'mod' / 'and' .

factor:
   Integer / Real / 'nil' / String /
   Variable /
   fncall /
   '(' Expression ')' /
   unot factor /
   '[' SetElements ']' .
fncall: IdUse fnargs .
fnargs: '(' argumentlist ')' .
unot: 'not' .
SetElements: setexpressionList / .
setexpressionList: setexpression / setexpressionList ',' setexpression .
setexpression: Expression '..' Expression / Expression .

Variable:
   IdUse /
   arrayvariable subscript /
   Variable '.' Identifier /
   Variable '^' .
arrayvariable: Variable '[' / arrayvariable subscr1 .
subscr1: Expression ',' .
subscript: Expression ']' .

Type:
   simpletype /
   '^' TypeId /
   structuredtype /
   'packed' structuredtype .

TypeId: IdUse .

simpletype:
   IdUse /
   '(' EnumRange ')' /
   Constant '..' Constant .
EnumRange: Enumeration .
Enumeration: EnumConst / Enumeration ',' EnumConst .
EnumConst: IdDef .

structuredtype:
   indextype elementtype /
   'file' 'of' Type /
   'set' 'of' Type /
   'record' recordtype 'end' .
indextype: 'array' '[' simpletype .
elementtype: ']' 'of' Type / nextindextype elementtype .
nextindextype: ',' simpletype .
recordtype: FieldList .
FieldList:
   FixedPart /
   FixedPart ';' /
   FixedPart ';' VariantPart /
   VariantPart /
   .
FixedPart: recordsection / FixedPart ';' recordsection .
recordsection: FieldIdList ':' Type .
FieldIdList: FieldIdDef / FieldIdList ',' FieldIdDef .
VariantPart: 'case' Tag 'of' VariantTail .
Tag: FieldIdDef ':' TypeId / TypeId .
VariantTail: VariantList / VariantList ';' .
VariantList: Variant / VariantList ';' Variant .
Variant: VariantSelectorList ':' '(' FieldList ')' .
FieldIdDef: IdDef .
VariantSelectorList:
   VariantSelector / VariantSelectorList ',' VariantSelector .
VariantSelector: Constant .

Constant:
   '+' constantid /
   '-' constantid /
   '+' unsignednumber /
   '-' unsignednumber /
   IdUse /
   unsignednumber /
   String .
constantid: IdUse .

unsignednumber:
   Integer / Real .

IdDef: Identifier .
IdUse: Identifier .

LbDef: Integer .
LbUse: Integer .
