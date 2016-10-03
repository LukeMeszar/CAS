# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/Unique.lido.5591302.lidoEta"

CLASS SYMBOL ROOTCLASS INHERITS RangeUnique END;

CLASS SYMBOL RangeUnique:
                _GotUnique:     VOID;

CLASS SYMBOL Unique:
                _GotUnique:     VOID,
                Key:            DefTableKey,
                Unique:         int     SYNT;

CLASS SYMBOL RangeUnique        COMPUTE
  SYNT._GotUnique =
        CONSTITUENTS Unique._GotUnique
                SHIELD RangeUnique;
END;

CLASS SYMBOL Unique     COMPUTE
  SYNT._GotUnique = 
        SetUnique (THIS.Key, 1, 0);

  SYNT.Unique =
        GetUnique (THIS.Key, 0)
        DEPENDS_ON INCLUDING RangeUnique._GotUnique;
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/LeafPtg.lido.5592006.lidoEta"

CLASS SYMBOL IdPtg, NumPtg, CStringPtg, PStringPtg:
        Sym: int,       
        Ptg: PTGNode;   

CLASS SYMBOL IdPtg COMPUTE
  INH.Ptg = PTGId (THIS.Sym);
END;

CLASS SYMBOL NumPtg COMPUTE
  INH.Ptg = PTGNumb (THIS.Sym);
END;

CLASS SYMBOL CStringPtg COMPUTE
  INH.Ptg = PTGCString (StringTable (THIS.Sym));
END;

CLASS SYMBOL CCharPtg COMPUTE
  INH.Ptg = PTGCChar (THIS.Sym);
END;

CLASS SYMBOL PStringPtg COMPUTE
  INH.Ptg = PTGPString (StringTable (THIS.Sym));
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/FirstOcc.lido.5592710.lidoEta"

CLASS SYMBOL ROOTCLASS INHERITS RangeFirstOcc END;

CLASS SYMBOL RangeFirstOcc:
                GotFirstOcc:    VOID;

CLASS SYMBOL FirstOcc:
                Key:                    DefTableKey,
                IsFirstOcc:     int;

CHAIN _FirstOcc:        VOID;

CLASS SYMBOL RangeFirstOcc COMPUTE
  CHAINSTART HEAD._FirstOcc = "yes";
  SYNT.GotFirstOcc = TAIL._FirstOcc;
END;

CLASS SYMBOL FirstOcc   COMPUTE
  SYNT.IsFirstOcc =
        SetGetFirstOcc (THIS.Key, 1, 0)
        DEPENDS_ON THIS._FirstOcc;
  THIS._FirstOcc = SYNT.IsFirstOcc;
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/TypeFirstOcc.lido.5593414.lidoEta"

CLASS SYMBOL ROOTCLASS INHERITS TypeRangeFirstOcc END;

CLASS SYMBOL TypeRangeFirstOcc:
                GotTypeFirstOcc:        VOID;

CLASS SYMBOL TypeFirstOcc:
                Key:                    DefTableKey,
                IsTypeFirstOcc: int;

CHAIN _TypeFirstOcc:    VOID;

CLASS SYMBOL TypeRangeFirstOcc COMPUTE
  CHAINSTART HEAD._TypeFirstOcc = "yes";
  SYNT.GotTypeFirstOcc = TAIL._TypeFirstOcc;
END;

CLASS SYMBOL TypeFirstOcc       COMPUTE
  SYNT.IsTypeFirstOcc =
        SetGetTypeFirstOcc (THIS.Key, 1, 0)
        DEPENDS_ON THIS._TypeFirstOcc;
  THIS._TypeFirstOcc = SYNT.IsTypeFirstOcc;
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/OperFirstOcc.lido.5594118.lidoEta"

CLASS SYMBOL ROOTCLASS INHERITS OperRangeFirstOcc END;

CLASS SYMBOL OperRangeFirstOcc:
                GotOperFirstOcc:        VOID;

CLASS SYMBOL OperFirstOcc:
                Key:                    DefTableKey,
                IsOperFirstOcc: int;

CHAIN _OperFirstOcc:    VOID;

CLASS SYMBOL OperRangeFirstOcc COMPUTE
  CHAINSTART HEAD._OperFirstOcc = "yes";
  SYNT.GotOperFirstOcc = TAIL._OperFirstOcc;
END;

CLASS SYMBOL OperFirstOcc       COMPUTE
  SYNT.IsOperFirstOcc =
        SetGetOperFirstOcc (THIS.Key, 1, 0)
        DEPENDS_ON THIS._OperFirstOcc;
  THIS._OperFirstOcc = SYNT.IsOperFirstOcc;
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/language.lido.5594822.lidoEta"


ATTR cost: int;

RULE: CostSpecification ::=
COMPUTE
  CostSpecification.cost=1;
END;

RULE: CostSpecification ::= 'COST' Integer
COMPUTE
  CostSpecification.cost=Integer;
END;


RULE: OpDef ::=
COMPUTE OpDef.Sym=GenerateName("_AnonOp");
END;

RULE: ClassOpDef ::=
COMPUTE ClassOpDef.Sym=GenerateName("_AnonOp");
END;



RULE: OpDef ::= Identifier COMPUTE OpDef.Sym=Identifier; END;

SYMBOL OpDef INHERITS Unique COMPUTE
  IF(NOT(THIS.Unique),
    message(ERROR,"Multiply-defined identifier",0,COORDREF));
END;



RULE: ClassOpDef ::= Identifier COMPUTE ClassOpDef.Sym=Identifier; END;

SYMBOL ClassOpDef INHERITS Unique COMPUTE
  IF(NOT(THIS.Unique),
    message(ERROR,"Multiply-defined identifier",0,COORDREF));
END;


RULE: TypeIdentifier ::= Identifier COMPUTE TypeIdentifier.Sym=Identifier; END;





RULE: ClassName ::= Identifier COMPUTE ClassName.Sym=Identifier; END;

SYMBOL ClassName INHERITS Unique COMPUTE
  IF(NOT(THIS.Unique),
    message(ERROR,"Multiply-defined identifier",0,COORDREF));
END;



RULE: ClassParameter ::= Identifier COMPUTE ClassParameter.Sym=Identifier; END;

SYMBOL ClassParameter INHERITS Unique COMPUTE
  IF(NOT(THIS.Unique),
    message(ERROR,"Multiply-defined identifier",0,COORDREF));
END;




RULE: IndDef ::= Identifier COMPUTE IndDef.Sym=Identifier; END;



RULE: OpRef ::= Identifier COMPUTE OpRef.Sym=Identifier; END;

SYMBOL OpRef COMPUTE
  IF(EQ(THIS.Key,NoKey),
    message(ERROR,"Undefined identifier",0,COORDREF));
END;





RULE: SetIdDef ::= Identifier COMPUTE SetIdDef.Sym=Identifier; END;

SYMBOL SetIdDef INHERITS Unique COMPUTE
  IF(NOT(THIS.Unique),
    message(ERROR,"Multiply-defined identifier",0,COORDREF));
END;



RULE: SetIdUse ::= Identifier COMPUTE SetIdUse.Sym=Identifier; END;

SYMBOL SetIdUse COMPUTE
  IF(EQ(THIS.Key,NoKey),
    message(ERROR,"Undefined identifier",0,COORDREF));
END;



ATTR Sym: int;
ATTR Env: Environment;
ATTR Key: DefTableKey;

SYMBOL OIL INHERITS RangeUnique COMPUTE
  SYNT.Env=NewEnv();
  SYNT.BoundInOuter=CONSTITUENTS DefinedId.bound;
  SYNT.GotAllDefs=CONSTITUENTS Unique.bound;
END;

SYMBOL ClassBody INHERITS RangeUnique COMPUTE
  SYNT.Env=NewScope(INCLUDING OIL.Env) DEPENDS_ON INCLUDING OIL.BoundInOuter;
  SYNT.BoundInInner=CONSTITUENTS ClassParameter.bound;
END;

SYMBOL AllIdentifiers COMPUTE
  SYNT.Key=
    KeyInEnv(INCLUDING (OIL.Env,ClassBody.Env), THIS.Sym)
      DEPENDS_ON INCLUDING (OIL.BoundInOuter,ClassBody.BoundInInner);
END;

SYMBOL DefinedId INHERITS AllIdentifiers COMPUTE
  SYNT.bound=DefineIdn(INCLUDING OIL.Env, THIS.Sym);
END;

SYMBOL ClassParameter INHERITS AllIdentifiers COMPUTE
  SYNT.bound=DefineIdn(INCLUDING ClassBody.Env, THIS.Sym);
END;

SYMBOL OpDef INHERITS DefinedId END;
SYMBOL ClassOpDef INHERITS DefinedId END;
SYMBOL TypeIdentifier INHERITS DefinedId END;
SYMBOL ClassName INHERITS DefinedId END;
SYMBOL IndDef INHERITS DefinedId END;
SYMBOL OpRef INHERITS AllIdentifiers END;
SYMBOL SetIdDef INHERITS DefinedId END;
SYMBOL SetIdUse INHERITS AllIdentifiers END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/Build.lido.5595526.lidoEta"


SYMBOL OIL COMPUTE
  SYNT.DataBaseBuilt=
    CONSTITUENTS OpRef.bind
      DEPENDS_ON (THIS.GotAllOperators, THIS.GotAllClasses);
END;


ATTR DoType: int;

SYMBOL TypeName INHERITS FirstOcc, TypeFirstOcc COMPUTE
  SYNT.GotIndex=ResetIndex(THIS.Key, THIS.Sym);
  SYNT.DoType=
    AND(
      THIS.IsTypeFirstOcc,
      EQ(GetTypeSet(THIS.Key,NULLDefTableKeyList),NULLDefTableKeyList));
END;

SYMBOL OperatorName INHERITS FirstOcc COMPUTE
  SYNT.GotIndex=ResetIndex(THIS.Key, THIS.Sym);
END;

SYMBOL OIL COMPUTE
  SYNT.GotAllNames=
    CONSTITUENTS (TypeName.GotIndex,OperatorName.GotIndex);
END;


SYMBOL ClassParameter INHERITS FirstOcc END;


CHAIN GotEarlierTypes: VOID;

SYMBOL OIL COMPUTE
  CHAINSTART HEAD.GotEarlierTypes="yes" DEPENDS_ON THIS.GotAllSets;
  SYNT.GotAllTypes=TAIL.GotEarlierTypes;
END;

ATTR type: tOilType;

SYMBOL TypeIdentifier INHERITS TypeName COMPUTE
  SYNT.type=
    ORDER(
      IF(THIS.DoType, ResetType(THIS.Key, OilNewType(THIS.Key))),
      GetType(THIS.Key,OilErrorType()))
    DEPENDS_ON THIS.GotEarlierTypes;
  THIS.GotEarlierTypes=SYNT.type;
END;


CHAIN GotEarlierSets: VOID;

SYMBOL OIL COMPUTE
  CHAINSTART HEAD.GotEarlierSets="yes";
  SYNT.GotAllSets=TAIL.GotEarlierSets;
END;

ATTR set: DefTableKeyList;

RULE: EquivalenceClass ::=  'SET' SetIdDef '=' xTypeExpr ';'
COMPUTE
  EquivalenceClass.GotEarlierSets=
    ResetTypeSet(SetIdDef.Key, xTypeExpr.set)
    DEPENDS_ON EquivalenceClass.GotEarlierSets;
END;

RULE: xTypeExpr ::=  SetIdUse
COMPUTE
  xTypeExpr.set=
    GetTypeSet(SetIdUse.Key, NULLDefTableKeyList)
    DEPENDS_ON xTypeExpr.GotEarlierSets;
  xTypeExpr.GotEarlierSets=
    IF(EQ(xTypeExpr.set, NULLDefTableKeyList),
      message(ERROR, "Undefined set", 0, COORDREF));
END;


RULE: xTypeExpr ::=  xTypeExpr '+' xTypeExpr
COMPUTE
  xTypeExpr[1].set=Union(xTypeExpr[2].set, xTypeExpr[3].set);
END;

RULE: xTypeExpr ::=  xTypeExpr '-' xTypeExpr
COMPUTE
  xTypeExpr[1].set=Difference(xTypeExpr[2].set, xTypeExpr[3].set);
END;

RULE: xTypeExpr ::=  xTypeExpr '*' xTypeExpr
COMPUTE
  xTypeExpr[1].set=Intersection(xTypeExpr[2].set, xTypeExpr[3].set);
END;


CHAIN partialSet: DefTableKeyList;

RULE: xTypeExpr ::= '[' xTypeList ']'
COMPUTE
  CHAINSTART xTypeList.partialSet=NULLDefTableKeyList;
  xTypeExpr.set=xTypeList.partialSet;
END;

RULE: Singleton ::= TypeIdentifier
COMPUTE
  Singleton.partialSet=
    AddToSetDefTableKeyList(
      TypeIdentifier.Key,
      Singleton.partialSet,
      CmpKey);
END;


ATTR signature: tOilArgSig;

RULE: Signature ::=
COMPUTE
  Signature.signature=OilNewArgSig();
END;

RULE: Signature ::=  SignatureElement
COMPUTE
  Signature.signature=OilAddArgSig(SignatureElement.type,OilNewArgSig());
END;

RULE: Signature ::=  SignatureElement ',' Signature
COMPUTE
  Signature[1].signature=
    OilAddArgSig(SignatureElement.type,Signature[2].signature);
END;

RULE: Signature ::=  '(' Signature ')' ':' SignatureElement
COMPUTE
  Signature[1].signature=
    OilAddArgSig(SignatureElement.type,Signature[2].signature);
END;


CHAIN SetNames: DefTableKeyList;

ATTR SetBinding: SetBindingState;

SYMBOL Binder COMPUTE
  CHAINSTART HEAD.SetNames=
    NULLDefTableKeyList DEPENDS_ON (
      INCLUDING OIL.GotAllDefs,
      INCLUDING OIL.GotAllTypes,
      INCLUDING OIL.GotAllNames);
  SYNT.SetBinding=
    FirstSetBinding(TAIL.SetNames) DEPENDS_ON INCLUDING RangeUnique._GotUnique;
  SYNT.Done=
    UNTIL EQ(SYNT.SetBinding,NoSetBinding)
    ITERATE SYNT.SetBinding=NextSetBinding(SYNT.SetBinding)
    DEPENDS_ON THIS.defined;
END;

RULE: SignatureElement ::= TypeIdentifier
COMPUTE
  SignatureElement.Key=TypeIdentifier.Key;
  SignatureElement.SetNames=
    IF(
      NE(
        GetTypeSet(TypeIdentifier.Key,NULLDefTableKeyList),
        NULLDefTableKeyList),
      AddToSetDefTableKeyList(
        TypeIdentifier.Key,
        SignatureElement.SetNames,
        CmpKey),
      SignatureElement.SetNames);
  SignatureElement.type=
    GetType(
      GetBoundType(TypeIdentifier.Key, TypeIdentifier.Key),
      OilErrorType())
    DEPENDS_ON INCLUDING Binder.SetBinding;
END;

SYMBOL Operator INHERITS Binder END;
SYMBOL ClassOperator INHERITS Binder END;


SYMBOL OpDef INHERITS OperatorName COMPUTE
  SYNT.OpList=
    ResetOperator(
      THIS.Key,
      ConstOilOpList(
        OilNewOp(
          THIS.Key,
          INCLUDING Operator.signature,
          INCLUDING Operator.cost),
        GetOperator(THIS.Key,NULLtOilOpList)));
END;


SYMBOL OIL COMPUTE
  SYNT.GotOperators=CONSTITUENTS Operator.Done;
END;


RULE: Oper ::= OpDefList Signature CostSpecification ';'
COMPUTE
  Oper.signature=Signature.signature;
  Oper.cost=CostSpecification.cost;
  Oper.defined=CONSTITUENTS OpDef.OpList;
END;

RULE: Coerce ::= OpDef Signature CostSpecification ';'
COMPUTE
  Coerce.signature=Signature.signature;
  Coerce.cost=CostSpecification.cost;
  Coerce.defined=OpDef.OpList;
  AddCoercions(OpDef.Key) DEPENDS_ON Coerce.Done;
END;

SYMBOL Oper INHERITS Operator END;
SYMBOL Coerce INHERITS Operator END;


SYMBOL OIL COMPUTE
  SYNT.GotAllOperators=THIS.GotOperators DEPENDS_ON THIS.GotClassOperators;
END;

ATTR indication: tOilOp;

RULE: Indication ::= IndDef ':' OpRefList ';'
COMPUTE
  Indication.indication=
    HeadtOilOpList(GetOperator(IndDef.Key, NULLtOilOpList))
    DEPENDS_ON INCLUDING OIL.GotAllIndications;
END;

SYMBOL OpRef COMPUTE
  SYNT.bind=
    AddIdentifications(INCLUDING Indication.indication, THIS.Key)
    DEPENDS_ON INCLUDING OIL.GotAllOperators;
END;


SYMBOL OIL COMPUTE
  SYNT.GotAllIndications=CONSTITUENTS IndDef.OpList;
END;

SYMBOL IndDef INHERITS OperatorName COMPUTE
  SYNT.OpList=
    IF(EQ(GetOperator(THIS.Key,NULLtOilOpList),NULLtOilOpList),
      ResetOperator(
        THIS.Key,
        ConstOilOpList(
          OilNewOp(THIS.Key, OilNewArgSig(), 0),
          NULLtOilOpList)))
    DEPENDS_ON INCLUDING OIL.GotAllOperators;
END;


ATTR class: tOilClass;
ATTR argNum: int;

SYMBOL ClassName INHERITS OperatorName COMPUTE
  SYNT.class=OilNewClass(THIS.Key, THIS.argNum);
END;

RULE: Class ::= 'CLASS' ClassName ClassBody
COMPUTE
  Class.class=ClassName.class;
  ClassName.argNum=
    CONSTITUENTS ClassParameter.Key WITH (int, ADD, ARGTOONE, ZERO);
END;


CHAIN GotEarlierBindings: VOID;

SYMBOL Class COMPUTE
  CHAINSTART HEAD.GotEarlierBindings=THIS.GotEarlierTypes;
  THIS.GotEarlierTypes=TAIL.GotEarlierBindings;
  SYNT.defined=TAIL.GotEarlierBindings;
END;

SYMBOL ClassName COMPUTE
  THIS.GotEarlierBindings=
    ResetBindingStatus(THIS.Key, eClassRef)
      DEPENDS_ON THIS.GotEarlierBindings;
END;

SYMBOL OIL COMPUTE
  SYNT.GotAllClasses=CONSTITUENTS Class.defined;
END;


CHAIN ParameterIndex: int;

SYMBOL ClassParameters COMPUTE
  CHAINSTART HEAD.ParameterIndex=1;
  THIS.GotEarlierBindings=TAIL.ParameterIndex;
END;

SYMBOL ClassParameter COMPUTE
  THIS.ParameterIndex=
    ORDER(
      ResetBindingStatus(THIS.Key, eElementRef),
      ResetParameterIndex(THIS.Key, THIS.ParameterIndex),
      ADD(THIS.ParameterIndex, 1));
END;


ATTR classSignature: tOilClassArgSig;

RULE: ClassSignature ::=
COMPUTE
  ClassSignature.classSignature=OilNewClassSigArg();
END;

RULE: ClassSignature ::= SignatureElement
COMPUTE
  ClassSignature.classSignature=
    OilAddClassSigArg(
      GetBindingStatus(SignatureElement.Key,eSpecTypeRef),
      SignatureElement.type,
      GetParameterIndex(SignatureElement.Key,0),
      OilNewClassSigArg());
END;

RULE: ClassSignature ::=  SignatureElement ',' ClassSignature
COMPUTE
  ClassSignature[1].classSignature=
    OilAddClassSigArg(
      GetBindingStatus(SignatureElement.Key,eSpecTypeRef),
      SignatureElement.type,
      GetParameterIndex(SignatureElement.Key,0),
      ClassSignature[2].classSignature);
END;

RULE: ClassSignature ::=  '(' ClassSignature ')' ':' SignatureElement
COMPUTE
  ClassSignature[1].classSignature=
    OilAddClassSigArg(
      GetBindingStatus(SignatureElement.Key,eSpecTypeRef),
      SignatureElement.type,
      GetParameterIndex(SignatureElement.Key,0),
      ClassSignature[2].classSignature);
END;


SYMBOL ClassOpDef INHERITS OperatorName COMPUTE
  SYNT.classOpList=
    ResetClassOperator(
      THIS.Key,
      ConstOilClassOpList(
        OilAddClassOp(
          THIS.Key,
          INCLUDING ClassOperator.classSignature,
          INCLUDING ClassOperator.cost,
          INCLUDING Class.class),
        GetClassOperator(THIS.Key,NULLtOilClassOpList)));
END;


SYMBOL OIL COMPUTE
  SYNT.GotClassOperators=CONSTITUENTS ClassOperator.Done;
END;


RULE: ClassOper ::= ClassOpDefList ClassSignature CostSpecification ';'
COMPUTE
  ClassOper.classSignature=ClassSignature.classSignature;
  ClassOper.cost=CostSpecification.cost;
  ClassOper.defined=CONSTITUENTS ClassOpDef.classOpList;
END;

RULE: ClassCoerce ::= ClassOpDef ClassSignature CostSpecification ';'
COMPUTE
  ClassCoerce.classSignature=ClassSignature.classSignature;
  ClassCoerce.cost=CostSpecification.cost;
  ClassCoerce.defined=
    AddClassCoercions(ClassOpDef.Key) DEPENDS_ON ClassOpDef.classOpList;
END;

SYMBOL ClassOper INHERITS ClassOperator END;
SYMBOL ClassCoerce INHERITS ClassOperator END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/o/Code.lido.5596230.lidoEta"


SYMBOL OperatorId INHERITS OperFirstOcc, IdPtg END;
SYMBOL OpDef INHERITS OperatorId END;
SYMBOL IndDef INHERITS OperatorId END;


SYMBOL TypeId INHERITS FirstOcc, IdPtg END;
SYMBOL TypeIdentifier INHERITS TypeId END;
SYMBOL ClassTypeIdentifier INHERITS TypeId END;


SYMBOL OIL COMPUTE
  SYNT.DumpInit=OilDumpInit("OilDecls.c") DEPENDS_ON THIS.DataBaseBuilt;
END;


SYMBOL TypeIdentifier COMPUTE
  SYNT.dumped=
    IF(THIS.DoType, OilDumpType(THIS.type)
    DEPENDS_ON INCLUDING OIL.DumpInit);
END;

SYMBOL OperatorId COMPUTE
  SYNT.dumped=
    IF(THIS.IsFirstOcc, DumpOps(THIS.Key)
    DEPENDS_ON INCLUDING OIL.DumpInit);
END;

SYMBOL ClassName COMPUTE
  SYNT.dumped=
    IF(THIS.IsFirstOcc, OilDumpClass(THIS.class)
    DEPENDS_ON INCLUDING OIL.DumpInit);
END;



CHAIN KnownKeys: PTGNode;

SYMBOL OIL COMPUTE
  CHAINSTART HEAD.KnownKeys=PTGNULL DEPENDS_ON THIS.DataBaseBuilt;
  PTGOutFile("OilDecls.pdl",PTGPDL(TAIL.KnownKeys));
END;


SYMBOL TypeId COMPUTE
  THIS.KnownKeys=
    IF(THIS.DoType,
      PTGSeq(
        THIS.KnownKeys,
        PTGTypeProperty(PTGNumb(ID(THIS.type)),THIS.Ptg)),
      THIS.KnownKeys);
END;


SYMBOL OperatorId COMPUTE
  THIS.KnownKeys=
    IF(THIS.IsOperFirstOcc,
      PTGSeq(
        THIS.KnownKeys,
        IF(OneOperator(THIS.Key),
          PTGOperatorProperty(PTGNumb(ID(Operator(THIS.Key))),THIS.Ptg),
          PTGMultOperator(THIS.Ptg))),
      THIS.KnownKeys);
END;


SYMBOL ClassName INHERITS IdPtg COMPUTE
  THIS.KnownKeys=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.KnownKeys,
        PTGClassProperty(PTGNumb(ID(THIS.class)),THIS.Ptg)),
      THIS.KnownKeys);
END;


SYMBOL ClassOpDef INHERITS IdPtg COMPUTE
  THIS.KnownKeys=
    IF(THIS.IsFirstOcc,
      PTGSeq(THIS.KnownKeys,PTGMultOperator(THIS.Ptg)),
      THIS.KnownKeys);
END;



CHAIN OilExterns: PTGNode;

SYMBOL OIL COMPUTE
  CHAINSTART HEAD.OilExterns=PTGNULL DEPENDS_ON THIS.DataBaseBuilt;
  PTGOutFile("OilDecls.h",PTGHeader(TAIL.OilExterns));
END;


SYMBOL TypeId COMPUTE
  THIS.OilExterns=
    IF(THIS.DoType,
      PTGSeq(
        THIS.OilExterns,
        PTGTypeSymbol(PTGNumb(ID(THIS.type)),THIS.Ptg)),
      THIS.OilExterns);
END;


SYMBOL OperatorId COMPUTE
  THIS.OilExterns=
    IF(AND(THIS.IsOperFirstOcc,OneOperator(THIS.Key)),
      PTGSeq(
        THIS.OilExterns,
        PTGOperatorSymbol(PTGNumb(ID(Operator(THIS.Key))),THIS.Ptg)),
      THIS.OilExterns);
END;


SYMBOL ClassName INHERITS IdPtg COMPUTE
  THIS.OilExterns=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.OilExterns,
        PTGClassSymbol(PTGNumb(ID(THIS.class)),THIS.Ptg)),
      THIS.OilExterns);
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/s/abstree.lido.5729356.lidoEta"
RULE rule_36:
ClassBody ::= '(' ')' 'BEGIN' G7 'END' ';'
END;

RULE rule_37:
ClassBody ::= '(' ClassParameters ')' 'BEGIN' G7 'END' ';'
END;

RULE rule_38:
ClassOpDefList ::= G11
END;

RULE rule_39:
ClassOperation ::= 'COERCION' G10
END;

RULE rule_40:
ClassOperation ::= 'OPER' G9
END;

RULE rule_41:
ClassParameters ::= G8
END;

RULE rule_42:
G1 ::= 
END;

RULE rule_43:
G10 ::= ClassCoerce
END;

RULE rule_44:
G10 ::= G10 ClassCoerce
END;

RULE rule_45:
G11 ::= ClassOpDef
END;

RULE rule_46:
G11 ::= G11 ',' ClassOpDef
END;

RULE rule_47:
G12 ::= G12 ',' Singleton
END;

RULE rule_48:
G12 ::= Singleton
END;

RULE rule_49:
G1 ::= G1 SpecificationElement
END;

RULE rule_50:
G2 ::= G2 Oper
END;

RULE rule_51:
G2 ::= Oper
END;

RULE rule_52:
G3 ::= Coerce
END;

RULE rule_53:
G3 ::= G3 Coerce
END;

RULE rule_54:
G4 ::= G4 ',' OpDef
END;

RULE rule_55:
G4 ::= OpDef
END;

RULE rule_56:
G5 ::= G5 Indication
END;

RULE rule_57:
G5 ::= Indication
END;

RULE rule_58:
G6 ::= G6 ',' OpRef
END;

RULE rule_59:
G6 ::= OpRef
END;

RULE rule_60:
G7 ::= ClassOperation
END;

RULE rule_61:
G7 ::= G7 ClassOperation
END;

RULE rule_62:
G8 ::= ClassParameter
END;

RULE rule_63:
G8 ::= G8 ',' ClassParameter
END;

RULE rule_64:
G9 ::= ClassOper
END;

RULE rule_65:
G9 ::= G9 ClassOper
END;

RULE rule_66:
Identification ::= 'INDICATION' G5
END;

RULE rule_67:
OIL ::= G1
END;

RULE rule_68:
OpDefList ::= G4
END;

RULE rule_69:
Operation ::= 'COERCION' G3
END;

RULE rule_70:
Operation ::= 'OPER' G2
END;

RULE rule_71:
OpRefList ::= G6
END;

RULE rule_72:
SpecificationElement ::= Class
END;

RULE rule_73:
SpecificationElement ::= EquivalenceClass
END;

RULE rule_74:
SpecificationElement ::= Identification
END;

RULE rule_75:
SpecificationElement ::= Operation
END;

RULE rule_76:
xTypeList ::= G12
END;

RULE rule_35:
CostSpecification ::= 
END;

RULE rule_34:
CostSpecification ::= 'COST' Integer
END;

RULE rule_33:
OpDef ::= 
END;

RULE rule_32:
ClassOpDef ::= 
END;

RULE rule_31:
OpDef ::= Identifier
END;

RULE rule_30:
ClassOpDef ::= Identifier
END;

RULE rule_29:
TypeIdentifier ::= Identifier
END;

RULE rule_28:
ClassName ::= Identifier
END;

RULE rule_27:
ClassParameter ::= Identifier
END;

RULE rule_26:
IndDef ::= Identifier
END;

RULE rule_25:
OpRef ::= Identifier
END;

RULE rule_24:
SetIdDef ::= Identifier
END;

RULE rule_23:
SetIdUse ::= Identifier
END;

RULE rule_22:
EquivalenceClass ::= 'SET' SetIdDef '=' xTypeExpr ';'
END;

RULE rule_21:
xTypeExpr ::= SetIdUse
END;

RULE rule_20:
xTypeExpr ::= xTypeExpr '+' xTypeExpr
END;

RULE rule_19:
xTypeExpr ::= xTypeExpr '-' xTypeExpr
END;

RULE rule_18:
xTypeExpr ::= xTypeExpr '*' xTypeExpr
END;

RULE rule_17:
xTypeExpr ::= '[' xTypeList ']'
END;

RULE rule_16:
Singleton ::= TypeIdentifier
END;

RULE rule_15:
Signature ::= 
END;

RULE rule_14:
Signature ::= SignatureElement
END;

RULE rule_13:
Signature ::= SignatureElement ',' Signature
END;

RULE rule_12:
Signature ::= '(' Signature ')' ':' SignatureElement
END;

RULE rule_11:
SignatureElement ::= TypeIdentifier
END;

RULE rule_10:
Oper ::= OpDefList Signature CostSpecification ';'
END;

RULE rule_9:
Coerce ::= OpDef Signature CostSpecification ';'
END;

RULE rule_8:
Indication ::= IndDef ':' OpRefList ';'
END;

RULE rule_7:
Class ::= 'CLASS' ClassName ClassBody
END;

RULE rule_6:
ClassSignature ::= 
END;

RULE rule_5:
ClassSignature ::= SignatureElement
END;

RULE rule_4:
ClassSignature ::= SignatureElement ',' ClassSignature
END;

RULE rule_3:
ClassSignature ::= '(' ClassSignature ')' ':' SignatureElement
END;

RULE rule_2:
ClassOper ::= ClassOpDefList ClassSignature CostSpecification ';'
END;

RULE rule_1:
ClassCoerce ::= ClassOpDef ClassSignature CostSpecification ';'
END;

