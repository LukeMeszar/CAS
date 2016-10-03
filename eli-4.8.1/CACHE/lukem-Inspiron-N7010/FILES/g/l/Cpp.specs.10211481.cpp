# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/i/AlgScope.lido.10435998.lidoEta"


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

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/i/FirstOcc.lido.10436702.lidoEta"

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
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/i/Analysis.lido.10437406.lidoEta"


RULE: xGrammar LISTOF xProduction END;

RULE: xProduction ::= 'RULE' xRule ':' xSymbol '::='    xRHS 'END' ';' END; 
RULE: xProduction ::= 'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';' END;

RULE: xRHS LISTOF Element END;
RULE: Syms LISTOF xSymbol END;

RULE: Element ::=     xSymbol END;
RULE: Element ::= '$' xSymbol END;
RULE: Element ::= xLiteral    END;

RULE: PatternSpec  ::=    PatternName ':' Items     END;
RULE: PatternName  ::=    xIdentifier               END;
RULE: Items        LISTOF Item                      END;
RULE: Item         ::=    CString                   END;
RULE: Item         ::=    '$'                       END;
RULE: Item         ::=    '$' Number                END;
RULE: Item         ::=    '$'        PtgType        END;
RULE: Item         ::=    '$' Number PtgType        END;
RULE: Item         ::=    '[' xIdentifier Items ']' END;
RULE: Item         ::=    '{' Items '}'             END;


SYMBOL xRoot:
  Prefix: CharPtr;      

SYMBOL xSymbol:
  IsTerminal: int,      
  Ptg: PTGNode,         
  AttrPtg: PTGNode;     

SYMBOL Element:
  Mark: PTGNode;        


SYMBOL xSymbol     INHERITS IdDefScope, LidoIdent   END;
SYMBOL xRule       INHERITS IdDefScope, LidoIdent   END;
SYMBOL PatternName INHERITS IdUseEnv,   PtgRuleName END;

SYMBOL LidoIdent   COMPUTE SYNT.Sym = TERM;             END;
SYMBOL PtgRuleName COMPUTE SYNT.Sym = MakePtgSym(TERM); END;


SYMBOL xRoot COMPUTE
  SYNT.GotProperties=
    CONSTITUENTS (xSymbol.GotProperties,PtgRuleName.GotProperties);
END;

SYMBOL xSymbol COMPUTE
  INH.GotProperties = 0;
END;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
COMPUTE
  xSymbol.GotProperties = ResetDefined(xSymbol.Key, 1);
END;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
COMPUTE
  xSymbol.GotProperties =
    ORDER(
      ResetDefined(xSymbol.Key, 1),
      ResetIsListofLhs(xSymbol.Key, 1));
END;

RULE: Element ::= '$' xSymbol
COMPUTE
  xSymbol.GotProperties = ResetComputedRoot(xSymbol.Key, 1);
END;


SYMBOL PtgRuleName COMPUTE
  SYNT.GotProperties = FixPtgGiven(TERM,THIS.Key);
END;


SYMBOL xRoot COMPUTE
  SYNT.Prefix=StringTable(GetClpValue(Prefix,NoStrIndex));
END;

SYMBOL xSymbol COMPUTE
  SYNT.IsTerminal=
    AND(NOT(GetDefined(THIS.Key,0)),NOT(GetComputedRoot(THIS.Key,0)))
    <- INCLUDING xRoot.GotProperties;
  SYNT.Ptg=PTGId(TERM);
  SYNT.AttrPtg=PTGAttr(THIS.Ptg,INCLUDING xRoot.Prefix);
END;

CHAIN NontermCnt, TermCnt: int; 

RULE: xProduction ::=  'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
COMPUTE
  CHAINSTART xRHS.NontermCnt = 1;
  CHAINSTART xRHS.TermCnt    = xRHS.NontermCnt;
END;

SYMBOL Element COMPUTE SYNT.Mark=PTGNULL; END;

RULE: Element ::= xSymbol
COMPUTE
  Element.Mark=
    IF(xSymbol.IsTerminal,
      PTGMarker(Element.TermCnt),
      PTGMarker(Element.NontermCnt));
  Element.NontermCnt=
    IF(xSymbol.IsTerminal,Element.NontermCnt,ADD(Element.NontermCnt,1));
  Element.TermCnt=
    IF(xSymbol.IsTerminal,ADD(Element.TermCnt,1),Element.TermCnt);
END;

RULE: Element ::= '$' xSymbol
COMPUTE
  Element.Mark=PTGMarker(Element.NontermCnt);
  Element.NontermCnt=ADD(Element.NontermCnt,1);
END;


CHAIN ClassComp: PTGNode;

SYMBOL xRoot COMPUTE
  CHAINSTART HEAD.ClassComp=PTGPlainRules(THIS.Prefix);
END;

RULE: xProduction ::= 'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
COMPUTE
  xProduction.ClassComp=
    PTGSeq(
      xProduction.ClassComp,
      PTGListofRule(
        INCLUDING xRoot.Prefix,
        PTGAsIs(StringTable(xRule.Sym)),
        xSymbol.Ptg,
        Syms CONSTITUENTS xSymbol.AttrPtg
          WITH(PTGNode, PTGCommaSeq, IDENTICAL, PTGNull),
        Syms CONSTITUENTS xSymbol.Ptg
          WITH(PTGNode, PTGCommaSeq, IDENTICAL, PTGNull)));
END;


CHAIN Inherit: PTGNode;

SYMBOL xRoot COMPUTE
  CHAINSTART HEAD.Inherit=PTGNULL <- THIS.GotProperties;
END;

SYMBOL xSymbol INHERITS FirstOcc COMPUTE
  THIS.Inherit =
    IF(THIS.IsFirstOcc,
      IF(GetIsListofLhs(THIS.Key,0),
        PTGSeq(THIS.Inherit,PTGListComp(THIS.Ptg,INCLUDING xRoot.Prefix)),
      IF(GetDefined(THIS.Key,0),
        PTGSeq(THIS.Inherit,PTGNontComp(THIS.Ptg,INCLUDING xRoot.Prefix)),
      IF(GetComputedRoot(THIS.Key,0),
        PTGSeq(THIS.Inherit,PTGNontNoComp(THIS.Ptg,INCLUDING xRoot.Prefix)),
        THIS.Inherit))),
      THIS.Inherit);
END;


CHAIN PtgTemplates: PTGNode;

SYMBOL xRoot COMPUTE
  CHAINSTART HEAD.PtgTemplates = PTGNULL;
END;


ATTR IdemPtg: PTGNode;

SYMBOL PatternName COMPUTE
  THIS.PtgTemplates =
    IF(NE(THIS.Key,NoKey),
      PTGSeq(THIS.PtgTemplates,INCLUDING PatternSpec.IdemPtg),
      THIS.PtgTemplates)
    <- INCLUDING xRoot.GotProperties;
END;

RULE: PatternSpec ::= PatternName ':' Items
COMPUTE
  PatternSpec.IdemPtg=PTGAxiom(PatternName.IdemPtg,Items.IdemPtg);
END;

RULE: PatternName ::= xIdentifier 
COMPUTE
  PatternName.IdemPtg=PTGId(xIdentifier);
END;

RULE: Item ::= CString
COMPUTE
  Item.IdemPtg=PTGId(FwOut(CString,Warn));
END;

RULE: Item ::= '$'
COMPUTE
  Item.IdemPtg=PTGAsIs("$");
END;

RULE: Item ::= '$' Number
COMPUTE
  Item.IdemPtg=PTGIndex(Number);
END;

RULE: Item ::= '$' PtgType
COMPUTE
  Item.IdemPtg=PTGCType(StringTable(PtgType));
END;

RULE: Item ::= '$' Number PtgType
COMPUTE
  Item.IdemPtg=PTGIndTyp(Number,StringTable(PtgType));
END;

RULE: Item ::= '[' xIdentifier Items ']'
COMPUTE
  Item.IdemPtg=PTGCall(StringTable(xIdentifier),Items.IdemPtg);
END;

RULE: Item ::= '{' Items '}'
COMPUTE
  Item.IdemPtg=PTGOption(Items.IdemPtg);
END;

RULE: Items LISTOF Item
COMPUTE
  Items.IdemPtg=
    CONSTITUENTS Item.IdemPtg SHIELD Item
      WITH (PTGNode, PTGSpSeq, IDENTICAL, PTGNull);
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/i/Idemcopy.lido.10438110.lidoEta"

ATTR TreeGram: PTGNode;

SYMBOL xRoot COMPUTE
  SYNT.TreeGram=
    CONSTITUENTS xProduction.TreeGram
      WITH (PTGNode, PTGSeq, IDENTICAL, PTGNull);
END;

RULE: xProduction ::= 'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
COMPUTE 
  xProduction.TreeGram=
    PTGPlain(
      StringTable(xRule.Sym),
      StringTable(xSymbol.Sym),
      CONSTITUENTS Element.TreeGram 
      WITH (PTGNode, PTGSpaceSeq, IDENTICAL, PTGNull));
END; 

RULE: xProduction ::= 'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
COMPUTE 
  xProduction.TreeGram=
    PTGListof(
      StringTable(xRule.Sym),
      StringTable(xSymbol.Sym),
      Syms CONSTITUENTS xSymbol.Ptg
        WITH (PTGNode, PTGAltSeq, IDENTICAL, PTGNull));
END;

RULE: Element ::= xSymbol
COMPUTE 
  Element.TreeGram=xSymbol.Ptg;
END;

RULE: Element ::= '$' xSymbol
COMPUTE 
  Element.TreeGram=PTGComputedRoot(StringTable(xSymbol.Sym));
END;

RULE: Element ::= xLiteral
COMPUTE 
  Element.TreeGram=PTGId(FwOut(xLiteral,Warn));
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/i/Cpp.lido.10438814.lidoEta"


SYMBOL xRoot COMPUTE
  PTGOutFile(
    "tree",
    PTGFrame(
      THIS.Prefix,
      THIS.TreeGram,
      TAIL.ClassComp,
      TAIL.Inherit,
      TAIL.PtgTemplates));
END;


SYMBOL xSymbol COMPUTE
  THIS.PtgTemplates =
    IF(AND(THIS.IsTerminal,AND(THIS.IsFirstOcc,GetNoPtgGiven(THIS.Key,1))),
      PTGSeq(THIS.PtgTemplates,PTGTerm(INCLUDING xRoot.Prefix,THIS.Ptg)),
      THIS.PtgTemplates)
    <- INCLUDING xRoot.GotProperties;
END;

ATTR Insert: PTGNode;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
COMPUTE
  xProduction.PtgTemplates=
    IF(GetNoPtgGiven(xRule.Key,1),
      PTGSeq(
        xRHS.PtgTemplates,
        PTGPlainProd(
          INCLUDING xRoot.Prefix,
          StringTable(xRule.Sym),
          xRHS CONSTITUENTS Element.Insert
            WITH (PTGNode, PTGSepSeq, IDENTICAL, PTGNull))),
      xRHS.PtgTemplates)
    <- INCLUDING xRoot.GotProperties;
END;

RULE: Element ::= xLiteral
COMPUTE
  Element.Insert = PTGNULL;
END;

RULE: Element ::= xSymbol
COMPUTE
  Element.Insert = Element.Mark;
END;

RULE: Element ::= '$' xSymbol
COMPUTE
  Element.Insert = Element.Mark;
END;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
COMPUTE
  xProduction.PtgTemplates=
    PTGSeq(
      Syms.PtgTemplates,
      PTGTriple(
        IF(GetNoPtgGiven(xRule.Key,1),
          PTGListProd(INCLUDING xRoot.Prefix,StringTable(xRule.Sym)),
          PTGNULL),
        IF(GetNoPtg2Given(xRule.Key,1),
          PTGListProd2(INCLUDING xRoot.Prefix,StringTable(xRule.Sym)),
          PTGNULL),
        IF(GetNoPtg1Given(xRule.Key,1),
          PTGListProd1(INCLUDING xRoot.Prefix,StringTable(xRule.Sym)),
          PTGNULL)))
    <- INCLUDING xRoot.GotProperties;
END;


ATTR Fwd, Visit, Class: PTGNode;

SYMBOL xRoot COMPUTE
  PTGOutFile(
    CatStrStr(THIS.ModuleBasename,".h"),
    PTGHeader(
      THIS.Prefix,
      CONSTITUENTS xRule.Fwd WITH(PTGNode,PTGSeq,IDENTICAL,PTGNull),
      CONSTITUENTS xRule.Visit WITH(PTGNode,PTGSeq,IDENTICAL,PTGNull),
      IF(THIS.HasListof,PTGDeclareCombine(THIS.Prefix),PTGNULL),
      CONSTITUENTS xSymbol.Class WITH(PTGNode,PTGSeq,IDENTICAL,PTGNull),
      CONSTITUENTS xProduction.Class WITH(PTGNode,PTGSeq,IDENTICAL,PTGNull)));
END;

SYMBOL xRule COMPUTE
  SYNT.Fwd=PTGForward(StringTable(THIS.Sym));
  SYNT.Visit=PTGVisit(StringTable(THIS.Sym));
END;


SYMBOL xRoot:
  HasListof:      int,          
  ModuleBasename: CharPtr;      

SYMBOL xRoot COMPUTE
  SYNT.HasListof=
    CONSTITUENTS xProduction.IsListof WITH (int, OR, IDENTICAL, ZERO);
  SYNT.ModuleBasename=CatStrStr("treeDef/", THIS.Prefix);
END;

SYMBOL xProduction:
  IsListof:       int;          

RULE: xProduction ::=  'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
COMPUTE
  xProduction.IsListof=0;
END;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
COMPUTE
  xProduction.IsListof=1;
END;


SYMBOL xSymbol COMPUTE
  SYNT.Class=
    IF(AND(THIS.IsFirstOcc,NOT(THIS.IsTerminal)),
      PTGSymbolClass(THIS.Ptg,INCLUDING xRoot.Prefix),
      PTGNULL);
END;


CHAIN cnt: int;
ATTR Argument, Assign, Access, Declare: PTGNode;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
COMPUTE
  .Declare=
    xRHS CONSTITUENTS Element.Declare
      WITH(PTGNode, PTGSeq, IDENTICAL, PTGNull);
  CHAINSTART xRHS.cnt=1;
  xProduction.Class=
    PTGProductionClass(
      StringTable(xRule.Sym),
      xSymbol.Ptg,
      xRHS CONSTITUENTS Element.Argument
        WITH(PTGNode, PTGCommaSeq, IDENTICAL, PTGNull),
      xRHS CONSTITUENTS Element.Assign
        WITH(PTGNode, PTGSeq, IDENTICAL, PTGNull),
      xRHS CONSTITUENTS Element.Access
        WITH(PTGNode, PTGSeq, IDENTICAL, PTGNull),
      IF(EQ(.Declare,PTGNULL),PTGNULL,PTGVars(.Declare)),
      INCLUDING xRoot.Prefix);
END;

SYMBOL Element COMPUTE
  THIS.cnt=ADD(THIS.cnt,1);
END;

RULE: Element ::= xLiteral
COMPUTE
  Element.Argument = PTGNULL;
  Element.Assign = PTGNULL;
  Element.Access = PTGNULL;
  Element.Declare = PTGNULL;
END;

SYMBOL xSymbol: Type: PTGNode;

SYMBOL xSymbol COMPUTE
  SYNT.Type=IF(THIS.IsTerminal,PTGAsIs("string"),PTGPointer(THIS.Ptg));
END;

RULE: Element ::= xSymbol
COMPUTE
  Element.Argument = PTGArgument(xSymbol.Type,Element.cnt);
  Element.Assign = PTGAssign(Element.cnt);
  Element.Access = PTGAccess(xSymbol.Type,Element.cnt);
  Element.Declare = PTGDeclare(xSymbol.Type,Element.cnt);
END;

RULE: Element ::= '$' xSymbol
COMPUTE
  Element.Argument = PTGNULL;
  Element.Assign = PTGComputed(xSymbol.Type,Element.cnt);
  Element.Access=
    PTGSeq(
      PTGSet(xSymbol.Type,Element.cnt),
      PTGAccess(xSymbol.Type,Element.cnt));
  Element.Declare = PTGDeclare(xSymbol.Type,Element.cnt);
END;

RULE: xProduction ::=  'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
COMPUTE
  xProduction.Class=
    PTGListofProdClass(
      StringTable(xRule.Sym),
      xSymbol.Ptg,
      INCLUDING xRoot.Prefix);
END;


ATTR Fwd, Visit, Class: PTGNode;

SYMBOL xRoot COMPUTE
  IF(THIS.HasListof,
    PTGOutFile(
      CatStrStr(THIS.ModuleBasename,".cc"),
      PTGCombine(THIS.Prefix)));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/l/abstree.lido.10545012.lidoEta"
RULE rule_19:
G2 ::= 
END;

RULE rule_20:
G2 ::= G2 PatternSpec
END;

RULE rule_21:
PTGSpec ::= G2
END;

RULE rule_22:
xRoot ::= xGrammar PTGSpec
END;

RULE rule_23:
xRule ::= PtgType
END;

RULE rule_24:
xRule ::= xIdentifier
END;

RULE rule_25:
xSymbol ::= PtgType
END;

RULE rule_26:
xSymbol ::= xIdentifier
END;

RULE rule_18:
xGrammar LISTOF xProduction
END;

RULE rule_17:
xProduction ::= 'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';'
END;

RULE rule_16:
xProduction ::= 'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';'
END;

RULE rule_15:
xRHS LISTOF Element
END;

RULE rule_14:
Syms LISTOF xSymbol
END;

RULE rule_13:
Element ::= xSymbol
END;

RULE rule_12:
Element ::= '$' xSymbol
END;

RULE rule_11:
Element ::= xLiteral
END;

RULE rule_10:
PatternSpec ::= PatternName ':' Items
END;

RULE rule_9:
PatternName ::= xIdentifier
END;

RULE rule_8:
Items LISTOF Item
END;

RULE rule_7:
Item ::= CString
END;

RULE rule_6:
Item ::= '$'
END;

RULE rule_5:
Item ::= '$' Number
END;

RULE rule_4:
Item ::= '$' PtgType
END;

RULE rule_3:
Item ::= '$' Number PtgType
END;

RULE rule_2:
Item ::= '[' xIdentifier Items ']'
END;

RULE rule_1:
Item ::= '{' Items '}'
END;

