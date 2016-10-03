# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/c/Kind.lido.12715122.lidoEta"

CLASS SYMBOL ROOTCLASS INHERITS RangeKind END;


CLASS SYMBOL RootKind INHERITS RangeKind END;

CLASS SYMBOL RangeKind:
                GotKind:        VOID    SYNT;

CLASS SYMBOL SetKind:
                Key:    DefTableKey,
                Kind:   int,
                GotKind:        VOID    SYNT;

CLASS SYMBOL GetKind:
                Key:    DefTableKey,
                HasKind:        int;

CLASS SYMBOL RangeKind COMPUTE
  SYNT.GotKind = CONSTITUENTS SetKind.GotKind
                        SHIELD RangeKind;
END;

CLASS SYMBOL SetKind COMPUTE
  SYNT.GotKind =
        SetDiffKind (THIS.Key, THIS.Kind, IntMultiple);
END;

CLASS SYMBOL GetKind COMPUTE
  SYNT.HasKind =
        GetKind (THIS.Key, IntNone)
        DEPENDS_ON INCLUDING RangeKind.GotKind;
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/c/Unique.lido.12715826.lidoEta"

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
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/c/FirstOcc.lido.12716530.lidoEta"

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
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/c/AlgScope.lido.12717234.lidoEta"


CLASS SYMBOL ROOTCLASS INHERITS RootScope END;

CLASS SYMBOL RootScope:
        Env:    Environment     SYNT,   
        GotLocKeys:     VOID    SYNT,   
        GotKeys:                VOID    SYNT;   

CLASS SYMBOL RootScope COMPUTE
  SYNT.Env = RootEnv;
  SYNT.GotLocKeys =
        CONSTITUENTS IdDefScope.Key 
        SHIELD (RangeScope, RootScope);
  SYNT.GotKeys = SYNT.GotLocKeys;
END;


CLASS SYMBOL RangeScope:
        Env:    Environment     INH,    
        GotLocKeys:     VOID    SYNT,   
        GotKeys:                VOID    INH;    

CLASS SYMBOL RangeScope COMPUTE
  INH.Env =
        NewScope (INCLUDING AnyScope.Env);
  SYNT.GotLocKeys =
        CONSTITUENTS IdDefScope.Key SHIELD AnyScope;
  INH.GotKeys =
        INCLUDING AnyScope.GotKeys
        <- SYNT.GotLocKeys;
END;


CLASS SYMBOL AnyScope END;
CLASS SYMBOL RootScope  INHERITS AnyScope END;
CLASS SYMBOL RangeScope INHERITS AnyScope END;


CLASS SYMBOL IdDefScope:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL IdDefScope COMPUTE
  SYNT.Bind =
        BindIdn (INCLUDING AnyScope.Env, THIS.Sym);
  SYNT.Key = KeyOf (SYNT.Bind);
END;


CLASS SYMBOL IdUseEnv:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL IdUseEnv INHERITS _InhPrecondDefault COMPUTE
  SYNT.Bind =
        BindingInEnv (INCLUDING AnyScope.Env, THIS.Sym)
        <- (INCLUDING AnyScope.GotKeys,
            SYNT._InhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
END;

CLASS SYMBOL _InhPrecondDefault:
        _InhPrecond:    VOID    SYNT;   
CLASS SYMBOL _InhPrecondDefault COMPUTE
  SYNT._InhPrecond = "yes";
END;


CLASS SYMBOL IdUseScope:
        Sym:            int,                    
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT;   

CLASS SYMBOL IdUseScope INHERITS _InhPrecondDefault COMPUTE
  SYNT.Bind =
        BindingInScope (INCLUDING AnyScope.Env, THIS.Sym)
        <- (INCLUDING AnyScope.GotLocKeys,
            SYNT._InhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
END;


CLASS SYMBOL ChkIdUse:
        Key:    DefTableKey     SYNT,   
        Sym:            int,                    
        SymErr:         int             SYNT,   
        SymMsg:         VOID            SYNT;   

CLASS SYMBOL ChkIdUse COMPUTE
  SYNT.SymErr = EQ (THIS.Key, NoKey);
  SYNT.SymMsg = IF (THIS.SymErr,
    message (ERROR, CatStrInd ("Identifier is not defined: ", THIS.Sym),
           0, COORDREF));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/c/tp.lido.12717938.lidoEta"


RULE: Source      LISTOF Include | Declaration | Pattern    END;
RULE: Include     ::=    String                             END; 
RULE: Declaration ::=    Nonterms ':' Type ';'              END;
RULE: Nonterms    LISTOF SymbolDef                          END;
RULE: Pattern     ::=    Signature ':'  Identifier Cost ';' END; 
RULE: Pattern     ::=    Signature '::' Identifier Cost ';' END; 
RULE: Signature   ::=    SymbolUse '::=' Child Function     END; 
RULE: Child       ::=    SymbolUse                          END;
RULE: Child       ::=    Terminal '(' ')'                   END; 
RULE: Child       ::=    Terminal '(' Children ')'          END; 
RULE: Children    ::=    Children ',' Child                 END; 
RULE: Children    ::=    Child                              END; 
RULE: Function    ::=                                       END; 
RULE: Cost        ::=                                       END; 
RULE: Cost        ::=    'COST' Integer                     END; 
RULE: Type        ::=    Identifier                         END; 
RULE: Terminal    ::=    Identifier                         END; 
RULE: SymbolDef   ::=    Identifier                         END; 
RULE: SymbolUse   ::=    Identifier                         END;


SYMBOL Terminal INHERITS SetKind COMPUTE
  SYNT.Kind=1;
  IF(EQ(GetArity(THIS.Key,100),100),
    message(ERROR,"Inconsistent arity",0,COORDREF))
    <- INCLUDING Source.GotAllArities;
END;

SYMBOL Source COMPUTE
  SYNT.GotAllArities=CONSTITUENTS Terminal.GotArity;
END;


ATTR type: DefTableKey;

SYMBOL Source COMPUTE
  SYNT.GotAllTypes=CONSTITUENTS SymbolDef.GotType <- THIS.GotAllSymbols;
  SYNT.GotAllUses=CONSTITUENTS Child.GotUse;
END;

RULE: Declaration ::= Nonterms ':' Type ';'
COMPUTE
  Declaration.type=Type.Key;
END;

SYMBOL SymbolDef INHERITS SetKind COMPUTE
  SYNT.Kind=2;
  SYNT.GotType=ResetType(THIS.Key,THIS.type);
  SYNT.type=INCLUDING Declaration.type;
END;

RULE: Child ::= SymbolUse
COMPUTE
  Child.GotUse=ResetUsed(SymbolUse.Key,1);
END;

SYMBOL Child COMPUTE
  SYNT.GotUse=1;
END;


SYMBOL Source COMPUTE
  SYNT.GotAllSymbols=CONSTITUENTS Type.GotSymbol;
END;

SYMBOL Type COMPUTE
  SYNT.GotSymbol=ResetSym(THIS.Key,THIS.Sym);
END;


CHAIN index: int;
ATTR value: int;

SYMBOL Source COMPUTE
  CHAINSTART HEAD.index=1;
END;

RULE: Pattern ::= Signature ':' Identifier Cost ';'
COMPUTE
  Pattern.index=ADD(Pattern.index,1);
END;

RULE: Pattern ::= Signature '::' Identifier Cost ';'
COMPUTE
  Pattern.index=ADD(Pattern.index,2);
END;

RULE: Cost ::=
COMPUTE
  Cost.value=1;
END;

RULE: Cost ::= 'COST' Integer
COMPUTE
  Cost.value=Integer;
END;


CHAIN sigs, comsigs, funs: VOID;
ATTR Kind, IsNt, ntcount, struct: int;


SYMBOL Source COMPUTE
  CHAINSTART HEAD.sigs=CONSTITUENTS Child.IsNt;
  CHAINSTART HEAD.comsigs = TAIL.sigs;
  CHAINSTART HEAD.funs=TAIL.comsigs;
END;

SYMBOL Child COMPUTE
  SYNT.ntcount=
    CONSTITUENTS Child.IsNt WITH(int, ADD, IDENTICAL, ZERO);
END;

SYMBOL SymbolUse INHERITS GetKind END;

ATTR ComSym: int;
SYMBOL Signature COMPUTE
  SYNT.ComSym = 0;
END;

RULE: Signature ::= SymbolUse '::=' Child Function
COMPUTE
  Signature.type=
    GetType(SymbolUse.Key,NoKey) <- INCLUDING Source.GotAllTypes;
  IF(EQ(Signature.type,NoKey),
    message(ERROR,CatStrInd("No type declared for ",SymbolUse.Sym),0,COORDREF));

  Signature.Sym=
    ORDER(obstack_1grow(SigObstk,'\0'),MakeName(obstack_finish(SigObstk)))
    <- Child.sigs;
  Signature.ComSym=IF(INCLUDING Pattern.IsCommutative,
    ORDER(obstack_1grow(SigObstk,'\0'),MakeName(obstack_finish(SigObstk))),
    0)
    <- Child.comsigs;
  
  Signature.struct=Function.Sym;
  Signature.sigs=Signature.Sym;
  Signature.funs=Function.Sym;
  Child.sigs=
    ORDER(
      obstack_grow(
        SigObstk,
        StringTable(SymbolUse.Sym),
        strlen(StringTable(SymbolUse.Sym))),
      obstack_1grow(SigObstk,':'))
    <- Signature.sigs;

  Signature.comsigs=Signature.ComSym;
  Child.comsigs=IF(INCLUDING Pattern.IsCommutative,
    ORDER(
      obstack_grow(
        SigObstk,
        StringTable(SymbolUse.Sym),
        strlen(StringTable(SymbolUse.Sym))),
      obstack_1grow(SigObstk,':')))
    <- Signature.comsigs;
    
  Child.funs=
      IF(EQ(Child.ntcount,0),obstack_grow(SigObstk,"TP_0", 4),
      IF(EQ(Child.ntcount,1),obstack_grow(SigObstk,"TP_1", 4),
      IF(EQ(Child.ntcount,2),obstack_grow(SigObstk,"TP_2", 4))))
    <- Signature.funs;
  Function.Sym=
    ORDER(obstack_1grow(SigObstk,'\0'),MakeName(obstack_finish(SigObstk)))
    <- Child.funs;
  Function.ntcount=Child.ntcount;
END;

RULE: Function ::=
COMPUTE
  Function.Key=DefineIdn(INCLUDING Source.Env,Function.Sym);
END;

ATTR RightSym, LeftSym: int;
SYMBOL Children COMPUTE
  SYNT.LeftSym = 0;
  INH.RightSym = 0;
END;

SYMBOL Child COMPUTE
  SYNT.Sym = 0;
END;

RULE: Child ::= SymbolUse
COMPUTE
  Child.Sym = SymbolUse.Sym;
  Child.IsNt=EQ(SymbolUse.HasKind,2);
  Child.sigs=
    IF(Child.IsNt,
      obstack_grow(
        SigObstk,
        StringTable(SymbolUse.Sym),
        strlen(StringTable(SymbolUse.Sym))))
    <- Child.sigs;
  Child.funs=
    IF(NOT(Child.IsNt),
      ORDER(
        obstack_1grow(SigObstk,'_'),
        obstack_grow(
          SigObstk,
          StringTable(SymbolUse.Sym),
          strlen(StringTable(SymbolUse.Sym)))))
    <- Child.funs;
END;

ATTR HasNt: int;

RULE: Child ::= Terminal '(' ')'
COMPUTE
  Child.IsNt=1;
  Child.sigs=
    obstack_grow(
      SigObstk,
      StringTable(Terminal.Sym),
      strlen(StringTable(Terminal.Sym)))
    <- Child.sigs;
  Child.comsigs=
    IF(INCLUDING Pattern.IsCommutative,
      obstack_grow(
        SigObstk,
        StringTable(Terminal.Sym),
        strlen(StringTable(Terminal.Sym))))
      <- Child.comsigs;
  Terminal.GotArity=IsArity(Terminal.Key,0,100);
END;

RULE: Child ::= Terminal '(' Children ')'
COMPUTE
  .HasNt=
    CONSTITUENTS Child.IsNt WITH (int, OR, IDENTICAL, ZERO);
  Child.IsNt=1;
  Children.sigs=
    ORDER(
      obstack_grow(
        SigObstk,
        StringTable(Terminal.Sym),
        strlen(StringTable(Terminal.Sym))),
      IF(.HasNt,obstack_1grow(SigObstk,'(')))
    <- Child.sigs;
  Child.sigs=IF(.HasNt,obstack_1grow(SigObstk,')')) <- Children.sigs;
  Children.comsigs=IF(INCLUDING Pattern.IsCommutative,
      ORDER(
        obstack_grow(
          SigObstk,
          StringTable(Terminal.Sym),
          strlen(StringTable(Terminal.Sym))),
        IF(.HasNt,obstack_1grow(SigObstk,'('))))
    <- Child.comsigs;
  Child.comsigs=IF(INCLUDING Pattern.IsCommutative,
    IF(.HasNt,obstack_1grow(SigObstk,')')))
    <- Children.comsigs;
  Terminal.GotArity=IsArity(Terminal.Key,Child.ntcount,100);
END;

RULE: Children ::= Children ',' Child
COMPUTE
  Children[2].RightSym = Child.Sym;
  Child.sigs=IF(Child.IsNt,obstack_1grow(SigObstk,',')) <- Children[2].sigs;
  Children[1].comsigs=IF(INCLUDING Pattern.IsCommutative,
    IF(Child.IsNt,
      ORDER(
        obstack_1grow(SigObstk,','),
        IF(EQ(Children[2].ntindex,1),
          obstack_grow(
            SigObstk,
            StringTable(Children[2].LeftSym),
            strlen(StringTable(Children[2].LeftSym))),
          obstack_grow(
            SigObstk,
            StringTable(Child.Sym),
            strlen(StringTable(Child.Sym)))))))
    <- Child.comsigs;
END;

RULE: Children ::= Child 
COMPUTE
  Children.LeftSym = Child.Sym;
  Children.comsigs=
    IF(INCLUDING Pattern.IsCommutative,
      obstack_grow(
        SigObstk,
        StringTable(Children.RightSym),
        strlen(StringTable(Children.RightSym))))
    <- Children.comsigs;
END;


CHAIN ntindex, tindex: int;

RULE: Signature ::= SymbolUse '::=' Child Function
COMPUTE
  CHAINSTART Child.ntindex=0;
  CHAINSTART Child.tindex=0;
END;

RULE: Child ::= SymbolUse
COMPUTE
  Child.ntindex=ADD(Child.ntindex,Child.IsNt);
  Child.tindex=ADD(Child.tindex,NOT(Child.IsNt));
END;


ATTR Sym: int;
ATTR Bind: Binding;
ATTR Key: DefTableKey;

SYMBOL Source    INHERITS RootScope         END;
SYMBOL Include   INHERITS IdOcc, IdDefScope END;
SYMBOL Terminal  INHERITS IdOcc, IdDefScope END;
SYMBOL Type      INHERITS IdOcc, IdDefScope END;
SYMBOL SymbolDef INHERITS IdOcc, IdDefScope END;
SYMBOL SymbolUse INHERITS IdOcc, IdUseEnv   END;

SYMBOL IdOcc COMPUTE SYNT.Sym=TERM; END;

SYMBOL Signature INHERITS Unique COMPUTE
  SYNT.Bind=BindIdn(INCLUDING AnyScope.Env,THIS.Sym);
  SYNT.Key=KeyOf(SYNT.Bind);
  IF(NOT(THIS.Unique),
    message(ERROR,"Multiply-defined pattern",0,COORDREF));
END;


CHAIN Includes: PTGNode;
ATTR Ptg: PTGNode;

SYMBOL Source COMPUTE
  CHAINSTART HEAD.Includes=PTGNULL;
  CHAINSTART HEAD.Termcodes=PTGNULL;
  CHAINSTART HEAD.Builders=PTGNULL;
  CHAINSTART HEAD.Forwards=PTGNULL;
  CHAINSTART HEAD.Reducers=PTGNULL;
  CHAINSTART HEAD.Transforms=PTGNULL;
  CHAINSTART HEAD.Macros=PTGNULL;
  CHAINSTART HEAD.Externs=PTGNULL;
  PTGOutFile(
    "tp_gen.burg",
    PTGBurg(
      TAIL.Termcodes,
      CONSTITUENTS Pattern.Ptg WITH (PTGNode, PTGSeq, IDENTICAL, PTGNull),
      TAIL.Builders,
      TAIL.Forwards,
      TAIL.Reducers,
      TAIL.Transforms));
  PTGOutFile(
    "tp_gen.h",
    PTGHeader(
      TAIL.Includes,
      TAIL.Macros,
      TAIL.Externs));
END;

SYMBOL Include INHERITS FirstOcc COMPUTE
  THIS.Includes=
    IF(THIS.IsFirstOcc,
      PTGSeq(THIS.Includes,PTGInclude(PTGId(THIS.Sym))),
      THIS.Includes);
END;


CHAIN Termcodes: PTGNode;
CHAIN Macros: PTGNode;

SYMBOL Terminal INHERITS FirstOcc COMPUTE
  THIS.Termcodes=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.Termcodes,
        PTGTerm(PTGId(THIS.Sym),TerminalIndex(THIS.Key))),
      THIS.Termcodes);
  THIS.Macros=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.Macros,
        PTGMacro(PTGId(THIS.Sym),TerminalIndex(THIS.Key))),
      THIS.Macros);
END;


ATTR id: PTGNode;

ATTR IsCommutative: int;
SYMBOL Pattern COMPUTE
  SYNT.IsCommutative = 0;
END;

RULE: Pattern ::= Signature ':' Identifier Cost ';'
COMPUTE
  Pattern.IsCommutative = 0;
  .id=PTGId(Identifier);
  Pattern.Ptg=
    PTGPattern(PTGId(Signature.Sym),Pattern.index,Cost.value,.id);
END;

RULE: Pattern ::= Signature '::' Identifier Cost ';'
COMPUTE
  Pattern.IsCommutative = 1;
  .id=PTGId(Identifier);
  Pattern.Ptg=PTGSeq(
    PTGPattern(PTGId(Signature.Sym),Pattern.index,Cost.value,.id),
    PTGPattern(PTGId(Signature.ComSym),ADD(Pattern.index,1),Cost.value,.id));
END;

RULE: Child ::= SymbolUse
COMPUTE
  Child.Ptg=
    IF(EQ(SymbolUse.HasKind,NEG(1)),
      PTGId(SymbolUse.Sym),
      PTGNULL);
END;

SYMBOL Child COMPUTE
  SYNT.Ptg=PTGNULL;
END;


CHAIN Builders, FieldDecls, ArgDecls, ArgNames, FieldSets, Externs: PTGNode;
ATTR typeSym: PTGNode;

SYMBOL Signature COMPUTE
  CHAINSTART HEAD.FieldDecls=PTGNULL;
  CHAINSTART HEAD.ArgDecls=PTGNULL;
  CHAINSTART HEAD.ArgNames=PTGNULL;
  CHAINSTART HEAD.FieldSets=PTGNULL;
END;

SYMBOL Function INHERITS FirstOcc COMPUTE
  THIS.Builders=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.Builders,
        IF(EQ(THIS.ntcount,0),
          PTGBuild0(
            PTGId(THIS.Sym),
            THIS.FieldDecls,
            THIS.ArgDecls,
            THIS.ArgNames,
            THIS.FieldSets),
        IF(EQ(THIS.ntcount,1),
          PTGBuild1(
            PTGId(THIS.Sym),
            THIS.FieldDecls,
            THIS.ArgDecls,
            THIS.ArgNames,
            THIS.FieldSets),
        IF(EQ(THIS.ntcount,2),
          PTGBuild2(
            PTGId(THIS.Sym),
            THIS.FieldDecls,
            THIS.ArgDecls,
            THIS.ArgNames,
            THIS.FieldSets),
          PTGNULL)))),
      THIS.Builders);
  THIS.Externs=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.Externs,
        IF(EQ(THIS.ntcount,0),PTGExtern0(PTGId(THIS.Sym),THIS.ArgDecls),
        IF(EQ(THIS.ntcount,1),PTGExtern1(PTGId(THIS.Sym),THIS.ArgDecls),
        IF(EQ(THIS.ntcount,2),PTGExtern2(PTGId(THIS.Sym),THIS.ArgDecls),
        PTGNULL)))),
      THIS.Externs);
END;

SYMBOL SymbolUse COMPUTE
  SYNT.typeSym=PTGId(THIS.Sym);
END;

RULE: Child ::= SymbolUse
COMPUTE
  Child.FieldDecls=
    IF(NOT(Child.IsNt),
      PTGSeq(
        Child.FieldDecls,
        PTGFieldDecl(SymbolUse.typeSym,Child.tindex)),
      Child.FieldDecls);
  Child.ArgDecls=
    IF(NOT(Child.IsNt),
      PTGSeq(
        Child.ArgDecls,
        PTGArgDecl(SymbolUse.typeSym,Child.tindex)),
      Child.ArgDecls);
  Child.ArgNames=
    IF(NOT(Child.IsNt),
      PTGSeq(
        Child.ArgNames,
        PTGArgName(Child.tindex)),
      Child.ArgNames);
  Child.FieldSets=
    IF(NOT(Child.IsNt),
      PTGSeq(
        Child.FieldSets,
        PTGFieldSet(Child.tindex)),
      Child.FieldSets);
END;


CHAIN Forwards, Reducers, leaves, revers: PTGNode;

SYMBOL Source COMPUTE
  SYNT.GotAllCases=CONSTITUENTS Pattern.GotCase;
END;

SYMBOL Type INHERITS FirstOcc COMPUTE
  THIS.Forwards=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.Forwards,
        PTGForward(
          PTGId(THIS.Sym),
          PTGId(ObtainSymbol(THIS.Key,THIS.Sym)))),
      THIS.Forwards);
  THIS.Reducers=
    IF(THIS.IsFirstOcc,
      PTGSeq(
        THIS.Reducers,
        PTGReducer(
          PTGId(THIS.Sym),
          PTGId(ObtainSymbol(THIS.Key,THIS.Sym)),
          GetCases(THIS.Key,PTGNULL) <- INCLUDING Source.GotAllCases,
          THIS.Sym)),
      THIS.Reducers);
END;

RULE: Pattern ::= Signature ':' Identifier Cost ';'
COMPUTE
  CHAINSTART Signature.leaves=PTGNULL;
  CHAINSTART Signature.revers=PTGNULL;
  Pattern.GotCase=
    UpdateCases(Signature.type,PTGCase(Pattern.index,.id,Signature.leaves));
END;

RULE: Pattern ::= Signature '::' Identifier Cost ';'
COMPUTE
  CHAINSTART Signature.leaves=PTGNULL;
  CHAINSTART Signature.revers=PTGNULL;
  Pattern.GotCase=
    UpdateCases(
      Signature.type,
      PTGSeq(
        PTGCase(Pattern.index,.id,Signature.leaves),
        PTGCase(ADD(Pattern.index,1),.id,Signature.revers)));
END;

RULE: Child ::= SymbolUse
COMPUTE
  .type=GetType(SymbolUse.Key,NoKey) <- INCLUDING Source.GotAllTypes;
  Child.leaves=
    PTGCommaSeq(
      Child.leaves,
      IF(Child.IsNt,
        PTGReducerCall(
          PTGId(ObtainSymbol(.type,GetSym(.type,0))),
          Child.ntindex),
        PTGGetValue(
          PTGId(INCLUDING Signature.struct),
          Child.tindex)));
  Child.revers=
    PTGCommaSeq(
      Child.revers,
      IF(Child.IsNt,
        PTGReducerCall(
          PTGId(ObtainSymbol(.type,GetSym(.type,0))),
          IF(EQ(Child.ntindex,0),1,IF(EQ(Child.ntindex,1),0,Child.ntindex))),
        PTGGetValue(
          PTGId(INCLUDING Signature.struct),
          Child.tindex)));
END;


CHAIN Transforms: PTGNode;

SYMBOL SymbolDef COMPUTE
  THIS.Transforms=
    PTGSeq(
      THIS.Transforms,
      PTGTransform(
        PTGId(THIS.Sym),
        PTGId(GetSym(THIS.type,0) <- INCLUDING Source.GotAllTypes)));
  THIS.Externs=
    PTGSeq(
      THIS.Externs,
      PTGTransformDecl(
        PTGId(THIS.Sym),
        PTGId(GetSym(THIS.type,0) <- INCLUDING Source.GotAllTypes)));
END;

