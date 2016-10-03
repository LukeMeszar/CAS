# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/q/Oil.specs.4883461.mapBnf"
ArgSig: .
ArgSig: TypeIdentifier.
ArgSig: TypeIdentifier ',' ArgSig.
ClassArgSig: .
ClassArgSig: TypeIdentifier.
ClassArgSig: TypeIdentifier ',' ClassArgSig.
ClassBody: '(' ')' 'BEGIN' G7 'END' ';'.
ClassBody: '(' ClassParameters ')' 'BEGIN' G7 'END' ';'.
Class: 'CLASS' ClassName ClassBody.
ClassCoerce: ClassOpDef ClassCoercionSig CostSpecification ';'.
ClassCoercionSig: '(' ClassOneArg ')' ':' TypeIdentifier.
ClassOneArg: TypeIdentifier.
ClassOpDefList: G11.
ClassOperation: 'COERCION' G10.
ClassOperation: 'OPER' G9.
ClassOperationSig: '(' ClassArgSig ')' ':' TypeIdentifier.
ClassOper: ClassOpDefList ClassOperationSig CostSpecification ';'.
ClassParameters: G8.
Coerce: OpDef CoercionSig CostSpecification ';'.
CoercionSig: '(' OneArg ')' ':' TypeIdentifier.
EquivalenceClass: 'SET' SetIdDef '=' xTypeExpr ';'.
G1: .
G10: ClassCoerce.
G10: G10 ClassCoerce.
G11: ClassOpDef.
G11: G11 ',' ClassOpDef.
G12: G12 ',' Singleton.
G12: Singleton.
G1: G1 SpecificationElement.
G2: G2 Oper.
G2: Oper.
G3: Coerce.
G3: G3 Coerce.
G4: G4 ',' OpDef.
G4: OpDef.
G5: G5 Indication.
G5: Indication.
G6: G6 ',' OpRef.
G6: OpRef.
G7: ClassOperation.
G7: G7 ClassOperation.
G8: ClassParameter.
G8: G8 ',' ClassParameter.
G9: ClassOper.
G9: G9 ClassOper.
Identification: 'INDICATION' G5.
Indication: IndDef ':' OpRefList ';'.
OIL: G1.
OneArg: TypeIdentifier.
OpDefList: G4.
Operation: 'COERCION' G3.
Operation: 'OPER' G2.
OperationSig: '(' ArgSig ')' ':' TypeIdentifier.
Oper: OpDefList OperationSig CostSpecification ';'.
OpRefList: G6.
SetIdDef: Identifier.
SetIdUse: Identifier.
Singleton: TypeIdentifier.
SpecificationElement: Class.
SpecificationElement: EquivalenceClass.
SpecificationElement: Identification.
SpecificationElement: Operation.
xTEprimary: SetIdUse.
xTEprimary: '(' xTypeExpr ')'.
xTEprimary: '[' xTypeList ']'.
xTEterm: xTEprimary.
xTEterm: xTEterm '*' xTEprimary.
xTypeExpr: xTEterm.
xTypeExpr: xTypeExpr '-' xTEterm.
xTypeExpr: xTypeExpr '+' xTEterm.
xTypeList: G12.
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/q/Oil.specs.4884965.ligaProd"
RULE rule_35:	CostSpecification ::=  END;
RULE rule_34:	CostSpecification ::= 'COST' Integer END;
RULE rule_33:	OpDef ::=  END;
RULE rule_32:	ClassOpDef ::=  END;
RULE rule_31:	OpDef ::= Identifier END;
RULE rule_30:	ClassOpDef ::= Identifier END;
RULE rule_29:	TypeIdentifier ::= Identifier END;
RULE rule_28:	ClassName ::= Identifier END;
RULE rule_27:	ClassParameter ::= Identifier END;
RULE rule_26:	IndDef ::= Identifier END;
RULE rule_25:	OpRef ::= Identifier END;
RULE rule_24:	SetIdDef ::= Identifier END;
RULE rule_23:	SetIdUse ::= Identifier END;
RULE rule_22:	EquivalenceClass ::= 'SET' SetIdDef '=' xTypeExpr ';' END;
RULE rule_21:	xTypeExpr ::= SetIdUse END;
RULE rule_20:	xTypeExpr ::= xTypeExpr '+' xTypeExpr END;
RULE rule_19:	xTypeExpr ::= xTypeExpr '-' xTypeExpr END;
RULE rule_18:	xTypeExpr ::= xTypeExpr '*' xTypeExpr END;
RULE rule_17:	xTypeExpr ::= '[' xTypeList ']' END;
RULE rule_16:	Singleton ::= TypeIdentifier END;
RULE rule_15:	Signature ::=  END;
RULE rule_14:	Signature ::= SignatureElement END;
RULE rule_13:	Signature ::= SignatureElement ',' Signature END;
RULE rule_12:	Signature ::= '(' Signature ')' ':' SignatureElement END;
RULE rule_11:	SignatureElement ::= TypeIdentifier END;
RULE rule_10:	Oper ::= OpDefList Signature CostSpecification ';' END;
RULE rule_9:	Coerce ::= OpDef Signature CostSpecification ';' END;
RULE rule_8:	Indication ::= IndDef ':' OpRefList ';' END;
RULE rule_7:	Class ::= 'CLASS' ClassName ClassBody END;
RULE rule_6:	ClassSignature ::=  END;
RULE rule_5:	ClassSignature ::= SignatureElement END;
RULE rule_4:	ClassSignature ::= SignatureElement ',' ClassSignature END;
RULE rule_3:	ClassSignature ::= '(' ClassSignature ')' ':' SignatureElement END;
RULE rule_2:	ClassOper ::= ClassOpDefList ClassSignature CostSpecification ';' END;
RULE rule_1:	ClassCoerce ::= ClassOpDef ClassSignature CostSpecification ';' END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/q/Oil.specs.4887525.SymToMap"
MAPSYM
# 0 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/y/language.sym.5051669.sym"



Signature ::= OperationSig CoercionSig ArgSig OneArg .


ClassSignature ::= ClassOperationSig ClassCoercionSig ClassArgSig ClassOneArg .


xTypeExpr ::= xTEterm xTEprimary .

