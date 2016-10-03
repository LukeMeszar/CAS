# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/c/TypeCScope.lido.3833606.lidoEta"


CLASS SYMBOL ROOTCLASS INHERITS TypeRootScope END;

CHAIN _C_TypeGotKeys: VOID;

CLASS SYMBOL TypeRootScope:
        TypeEnv:        Environment     SYNT,   
        TypeGotKeys:            VOID    SYNT;   

CLASS SYMBOL TypeRootScope COMPUTE
  SYNT.TypeEnv = TypeRootEnv;
  CHAINSTART HEAD._C_TypeGotKeys = SYNT.TypeEnv;
  SYNT.TypeGotKeys = TAIL._C_TypeGotKeys;
END;


CLASS SYMBOL TypeRangeScope:
        TypeEnv:        Environment     INH,    
        TypeGotKeys:            VOID    SYNT;   

CLASS SYMBOL TypeRangeScope COMPUTE
  INH.TypeEnv = 
        NewScope (INCLUDING TypeAnyScope.TypeEnv);
  SYNT.TypeGotKeys = TAIL._C_TypeGotKeys;
END;


CLASS SYMBOL TypeAnyScope END;
CLASS SYMBOL TypeRootScope      INHERITS TypeAnyScope END;
CLASS SYMBOL TypeRangeScope     INHERITS TypeAnyScope END;


CLASS SYMBOL TypeIdDefScope:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL TypeIdDefScope COMPUTE
  SYNT.Bind =
        BindIdn (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym)
        <- THIS._C_TypeGotKeys;
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_TypeGotKeys = SYNT.Key;
END;


CLASS SYMBOL TypeIdUseEnv:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL TypeIdUseEnv INHERITS _TypeInhPrecondDefault COMPUTE
  SYNT.Bind =
        BindingInEnv (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym)
        <- (THIS._C_TypeGotKeys, SYNT._TypeInhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_TypeGotKeys = SYNT.Key;
END;

CLASS SYMBOL _TypeInhPrecondDefault:
        _TypeInhPrecond:        VOID    SYNT;   
CLASS SYMBOL _TypeInhPrecondDefault COMPUTE
  SYNT._TypeInhPrecond = "yes";
END;


CLASS SYMBOL TypeIdUseScope:
        Sym:            int,                    
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT;   

CLASS SYMBOL TypeIdUseScope INHERITS _TypeInhPrecondDefault COMPUTE
  SYNT.Bind =
        BindingInScope (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym)
        <- (THIS._C_TypeGotKeys, SYNT._TypeInhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_TypeGotKeys = SYNT.Key;
END;


CLASS SYMBOL TypeIdDefUse:
        Sym:            int,                    
        TypeDefCond:    int             INH,    
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        _TypeauxGotKeys: VOID           SYNT;   

CLASS SYMBOL TypeIdDefUse INHERITS _TypeInhPrecondDefault COMPUTE
  SYNT._TypeauxGotKeys = THIS._C_TypeGotKeys;
  INH.TypeDefCond =
        EQ (NoBinding, 
            BindingInEnv (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym))
        <- (THIS._TypeauxGotKeys, SYNT._TypeInhPrecond);
  SYNT.Bind =
        IF (THIS.TypeDefCond,
        BindIdn (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym),
        BindingInEnv (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym))
        <- (THIS._C_TypeGotKeys, SYNT._TypeInhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_TypeGotKeys = SYNT.Key;
END;


CLASS SYMBOL TypeChkIdUse:
        Key:       DefTableKey     SYNT,   
        Sym:            int,                    
        SymErr:         int             SYNT,   
        SymMsg:         VOID            SYNT;   

CLASS SYMBOL TypeChkIdUse COMPUTE
  SYNT.SymErr = EQ (THIS.Key, NoKey);
  SYNT.SymMsg = IF (THIS.SymErr,
    message (ERROR, CatStrInd ("Identifier is not defined: ", THIS.Sym),
           0, COORDREF));
END;


CLASS SYMBOL TypeDeclaratorWithId:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int             SYNT;   

CLASS SYMBOL TypeDeclaratorWithId COMPUTE
  SYNT.Sym = CONSTITUENT TypeIdInDeclarator.Sym SHIELD TypeDeclaratorWithId;
  SYNT.Bind =
        BindIdn (INCLUDING TypeAnyScope.TypeEnv, THIS.Sym)
        <- TAIL._C_TypeGotKeys;
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_TypeGotKeys = SYNT.Key;
END;


CLASS SYMBOL TypeIdInDeclarator:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL TypeIdInDeclarator COMPUTE
  SYNT.Bind = INCLUDING TypeDeclaratorWithId.Bind;
  SYNT.Key = KeyOf (SYNT.Bind);
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/c/ExportCScope.lido.3834310.lidoEta"


CLASS SYMBOL ROOTCLASS INHERITS ExportRootScope END;

CHAIN _C_ExportGotKeys: VOID;

CLASS SYMBOL ExportRootScope:
        ExportEnv:      Environment     SYNT,   
        ExportGotKeys:          VOID    SYNT;   

CLASS SYMBOL ExportRootScope COMPUTE
  SYNT.ExportEnv = ExportRootEnv;
  CHAINSTART HEAD._C_ExportGotKeys = SYNT.ExportEnv;
  SYNT.ExportGotKeys = TAIL._C_ExportGotKeys;
END;


CLASS SYMBOL ExportRangeScope:
        ExportEnv:      Environment     INH,    
        ExportGotKeys:          VOID    SYNT;   

CLASS SYMBOL ExportRangeScope COMPUTE
  INH.ExportEnv = 
        NewScope (INCLUDING ExportAnyScope.ExportEnv);
  SYNT.ExportGotKeys = TAIL._C_ExportGotKeys;
END;


CLASS SYMBOL ExportAnyScope END;
CLASS SYMBOL ExportRootScope    INHERITS ExportAnyScope END;
CLASS SYMBOL ExportRangeScope   INHERITS ExportAnyScope END;


CLASS SYMBOL ExportIdDefScope:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL ExportIdDefScope COMPUTE
  SYNT.Bind =
        BindIdn (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym)
        <- THIS._C_ExportGotKeys;
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_ExportGotKeys = SYNT.Key;
END;


CLASS SYMBOL ExportIdUseEnv:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL ExportIdUseEnv INHERITS _ExportInhPrecondDefault COMPUTE
  SYNT.Bind =
        BindingInEnv (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym)
        <- (THIS._C_ExportGotKeys, SYNT._ExportInhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_ExportGotKeys = SYNT.Key;
END;

CLASS SYMBOL _ExportInhPrecondDefault:
        _ExportInhPrecond:      VOID    SYNT;   
CLASS SYMBOL _ExportInhPrecondDefault COMPUTE
  SYNT._ExportInhPrecond = "yes";
END;


CLASS SYMBOL ExportIdUseScope:
        Sym:            int,                    
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT;   

CLASS SYMBOL ExportIdUseScope INHERITS _ExportInhPrecondDefault COMPUTE
  SYNT.Bind =
        BindingInScope (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym)
        <- (THIS._C_ExportGotKeys, SYNT._ExportInhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_ExportGotKeys = SYNT.Key;
END;


CLASS SYMBOL ExportIdDefUse:
        Sym:            int,                    
        ExportDefCond:  int             INH,    
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        _ExportauxGotKeys: VOID         SYNT;   

CLASS SYMBOL ExportIdDefUse INHERITS _ExportInhPrecondDefault COMPUTE
  SYNT._ExportauxGotKeys = THIS._C_ExportGotKeys;
  INH.ExportDefCond =
        EQ (NoBinding, 
            BindingInEnv (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym))
        <- (THIS._ExportauxGotKeys, SYNT._ExportInhPrecond);
  SYNT.Bind =
        IF (THIS.ExportDefCond,
        BindIdn (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym),
        BindingInEnv (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym))
        <- (THIS._C_ExportGotKeys, SYNT._ExportInhPrecond);
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_ExportGotKeys = SYNT.Key;
END;


CLASS SYMBOL ExportChkIdUse:
        Key:       DefTableKey     SYNT,   
        Sym:            int,                    
        SymErr:         int             SYNT,   
        SymMsg:         VOID            SYNT;   

CLASS SYMBOL ExportChkIdUse COMPUTE
  SYNT.SymErr = EQ (THIS.Key, NoKey);
  SYNT.SymMsg = IF (THIS.SymErr,
    message (ERROR, CatStrInd ("Identifier is not defined: ", THIS.Sym),
           0, COORDREF));
END;


CLASS SYMBOL ExportDeclaratorWithId:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int             SYNT;   

CLASS SYMBOL ExportDeclaratorWithId COMPUTE
  SYNT.Sym = CONSTITUENT ExportIdInDeclarator.Sym SHIELD ExportDeclaratorWithId;
  SYNT.Bind =
        BindIdn (INCLUDING ExportAnyScope.ExportEnv, THIS.Sym)
        <- TAIL._C_ExportGotKeys;
  SYNT.Key = KeyOf (SYNT.Bind);
  THIS._C_ExportGotKeys = SYNT.Key;
END;


CLASS SYMBOL ExportIdInDeclarator:
        Bind:   Binding         SYNT,   
        Key:    DefTableKey     SYNT,   
        Sym:            int;                    

CLASS SYMBOL ExportIdInDeclarator COMPUTE
  SYNT.Bind = INCLUDING ExportDeclaratorWithId.Bind;
  SYNT.Key = KeyOf (SYNT.Bind);
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/c/ExportUnique.lido.3835014.lidoEta"

CLASS SYMBOL ROOTCLASS INHERITS ExportRangeUnique END;

CLASS SYMBOL ExportRangeUnique:
                _GotExportUnique:       VOID;

CLASS SYMBOL ExportUnique:
                _GotExportUnique:       VOID,
                Key:            DefTableKey,
                ExportUnique:           int     SYNT;

CLASS SYMBOL ExportRangeUnique  COMPUTE
  SYNT._GotExportUnique =
        CONSTITUENTS ExportUnique._GotExportUnique
                SHIELD ExportRangeUnique;
END;

CLASS SYMBOL ExportUnique       COMPUTE
  SYNT._GotExportUnique = 
        SetExportUnique (THIS.Key, 1, 0);

  SYNT.ExportUnique =
        GetExportUnique (THIS.Key, 0)
        DEPENDS_ON INCLUDING ExportRangeUnique._GotExportUnique;
END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/c/count.lido.3835718.lidoEta"


CHAIN argcount : int;

RULE operation_sig1:
        operation_sig ::= 'operation' iddef str operation_block body
COMPUTE
        CHAINSTART operation_block.argcount = 0;
END;

RULE operation_sig2:
        operation_sig ::= 'operation' iddef str operation_block ':' typeid body
COMPUTE
        CHAINSTART operation_block.argcount = 0;
END;

SYMBOL param
COMPUTE
    THIS.argcount = ADD (THIS.argcount, 1);
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/c/dbgen.lido.3836422.lidoEta"


CHAIN aspectdbs, eventdbs : PTGNode;

RULE:
    spec ::= aspects
COMPUTE
    CHAINSTART HEAD.aspectdbs = PTGNULL;
    CHAINSTART HEAD.eventdbs = PTGNULL;
    PTGOutFile (dbfilename, PTGdb (aspects.aspectdbs, aspects.eventdbs));
END;

CHAIN aspectdbs : PTGNode;

RULE:
    aspect_stmt ::= 'aspect' iddef ';' sigs 'end' ';'
COMPUTE
    aspect_stmt.aspectdbs = PTGSeq (aspect_stmt.aspectdbs,
                                    PTGaspectdb (iddef.idcode));
END;

CHAIN eventdbs, attrdbs : PTGNode;

RULE:
    event_sig ::= 'event' iddef export str event_block ';'
COMPUTE
    CHAINSTART event_block.attrdbs = PTGNULL;

    event_sig.eventdbs = PTGSeq (event_sig.eventdbs,
                                 PTGeventdb (iddef.idcode,
                                             PTGId (str),
                                             event_block.attrdbs,
                                             PTGNumb (export.exported)));
END;

ATTR exported : int;

RULE:
    export ::= '*'
COMPUTE
    export.exported = 1;
END;

RULE:
    export ::= 
COMPUTE
    export.exported = 0;
END;

CHAIN attrdbs : PTGNode;

RULE:
    attr ::= typeid iddef str
COMPUTE
    attr.attrdbs = PTGSSeq3 (attr.attrdbs, iddef.idcode, PTGId (str));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/d/gen.lido.3837126.lidoEta"


CHAIN incls, entries, funcs, sigs : PTGNode;

RULE:
    spec ::= aspects
COMPUTE
    CHAINSTART HEAD.incls = PTGNULL;
    CHAINSTART HEAD.entries = PTGNULL;
    CHAINSTART HEAD.funcs = PTGNULL;
    PTGOutFile (cfilename, PTGcfile (PTGAsIs (basefilename), TAIL.funcs,
                                     TAIL.entries));
    CHAINSTART HEAD.sigs = PTGNULL;
    PTGOutFile (hfilename, PTGhfile (PTGAsIs (basefilename), TAIL.sigs,
                                     TAIL.incls));
END;

CHAIN incls : PTGNode;

RULE:
    sig ::= bstr
COMPUTE
    sig.incls = PTGSeq (sig.incls, PTGincl (PTGId (bstr)));
END;

RULE:
    sig ::= str
COMPUTE
    sig.incls = PTGSeq (sig.incls, PTGincl (PTGId (str)));
END;

CHAIN entries : PTGNode;
ATTR Sym : int;
ATTR idcode : CharPtr;

SYMBOL ptg_ident
COMPUTE
    SYNT.idcode = StringTable (THIS.Sym);
END;

SYMBOL iddef INHERITS ptg_ident END;
SYMBOL iduse INHERITS ptg_ident END;
SYMBOL typeid INHERITS ptg_ident END;

RULE:
    operation_sig ::= 'operation' iddef str operation_block body
COMPUTE
    operation_sig.entries = PTGSeq (operation_sig.entries,
                                    PTGentry (iddef.idcode));
END;

RULE:
    operation_sig ::= 'operation' iddef str operation_block ':' typeid body
COMPUTE
    operation_sig.entries = PTGSeq (operation_sig.entries,
                                    PTGentry (iddef.idcode));
END;

CHAIN funcs, names, argvars, args : PTGNode;
CHAIN argcount : int;

ATTR line : int;
ATTR bodycode : PTGNode;

RULE: body ::= text COMPUTE
    body.line = LINE;
    body.bodycode = PTGId (text);
END;

RULE:
    operation_sig ::= 'operation' iddef str operation_block body
COMPUTE
    
    CHAINSTART operation_block.args = PTGNULL;
    CHAINSTART operation_block.argvars = PTGNULL;
    CHAINSTART operation_block.names = PTGNULL;
    operation_sig.funcs = PTGSeq (operation_sig.funcs,
                              PTGcmdfunc (iddef.idcode,
                                          operation_block.argvars,
                                          IF (EQ (operation_block.argcount, 0),
                                              PTGNULL,
                                              operation_block.args),
                                          body.bodycode,
                                          body.line,
                                          filename));
    
END;

RULE:
    operation_sig ::= 'operation' iddef str operation_block ':' typeid body
COMPUTE
    
    CHAINSTART operation_block.args = PTGNULL;
    CHAINSTART operation_block.argvars = PTGNULL;
    CHAINSTART operation_block.names = PTGNULL;
    operation_sig.funcs = PTGSeq (operation_sig.funcs,
                              PTGcmdfunc (iddef.idcode,
                                          operation_block.argvars,
                                          IF (EQ (operation_block.argcount, 0),
                                              PTGNULL,
                                              operation_block.args),
                                          body.bodycode,
                                          body.line,
                                          filename));
    
END;

CHAIN names, argvars, args : PTGNode;

RULE:
    param ::= typeid iddef str
COMPUTE
    param.names = PTGNSeq (param.names, Getamp (typeid.Key, "&"),
                           iddef.idcode);
    param.args = PTGSeq (param.args,
                         PTGarg (Getsend (typeid.Key,
                                          StringTable (typeid.Sym)),
                                 iddef.idcode));
    param.argvars = PTGSSeq (param.argvars,
                             PTGDecl (Gettype (typeid.Key, typeid.idcode),
                                      iddef.idcode));
END;

CHAIN funcs, sigs, args, ansiargs, types, ansitypes, sends : PTGNode;
ATTR translations, translationvars : PTGNode;

RULE:
    event_sig ::= 'event' iddef export str event_block ';'
COMPUTE
    CHAINSTART event_block.args = PTGNULL;
    CHAINSTART event_block.ansiargs = PTGNULL;
    CHAINSTART event_block.types = PTGNULL;
    CHAINSTART event_block.ansitypes = PTGNULL;
    CHAINSTART event_block.sends = PTGNULL;

    event_sig.funcs = PTGSeq (event_sig.funcs,
                              PTGefunc (event_sig.translationvars,
                                        iddef.idcode,
                                        event_block.ansiargs,
                                        event_block.args,
                                        event_block.types,
                                        event_block.sends));
    event_sig.sigs = PTGSeq (event_sig.sigs,
                             PTGsig (iddef.idcode, event_block.ansitypes));
END;


CHAIN args, types, ansitypes : PTGNode;
ATTR cast, type, arg : PTGNode;

RULE:
    attr ::= typeid iddef str
COMPUTE
    .cast = Getcast (typeid.Key, PTGAsIs ("(long)"));
    attr.args = IF (EQ (attr.args, PTGNULL),
                    PTGAsIs (iddef.idcode),
                    PTGCommaSeq (attr.args, PTGAsIs (iddef.idcode)));
    .type = PTGAsIs (Gettype (typeid.Key, typeid.idcode));
    .arg = PTGSSeq (.type, PTGAsIs (iddef.idcode));
    attr.ansiargs = IF (EQ (attr.args, PTGNULL), .arg,
                        PTGCommaSeq (attr.ansiargs, .arg));
    attr.types = PTGDeclSeq (attr.types, .arg);
    attr.ansitypes = IF (EQ (attr.args, PTGNULL), .type,
                         PTGCommaSeq (attr.ansitypes, .type));
    attr.sends = PTGSeq (attr.sends,
                         PTGsend (Getsend (typeid.Key, 
                                           StringTable (typeid.Sym)),
                                  iddef.idcode));
END;

ATTR translationsset : VOID;
ATTR translations, translationvars : PTGNode;
ATTR Key : DefTableKey;

RULE:
    spec ::= aspects
COMPUTE
    spec.translationsset = CONSTITUENTS translation_sig.translationsset;
END;

RULE:
    event_sig ::= 'event' iddef export str event_block ';'
COMPUTE
    event_sig.translations = GetTranslations (iddef.Key, PTGNULL)
                             DEPENDS_ON INCLUDING spec.translationsset;
    event_sig.translationvars = GetTranslationVars (iddef.Key, PTGNULL)
                                DEPENDS_ON INCLUDING spec.translationsset;
END;

RULE:
    translation_sig ::= 'translation' iddef iduse str body
COMPUTE
    .translations = PTGSeq (GetTranslations (iduse.Key, PTGNULL),
                            PTGtranslation (iddef.idcode,
                                            body.line,
                                            filename,
                                            body.bodycode));
    .translationvars = PTGSeq (GetTranslationVars (iduse.Key, PTGNULL),
                               PTGtranslationvar (iddef.idcode));
    translation_sig.translationsset =
        ORDER (SetTranslations (iduse.Key, .translations, .translations),
               SetTranslationVars (iduse.Key, .translationvars,
                                   .translationvars));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/d/name.lido.3837830.lidoEta"

ATTR Sym: int SYNT;

SYMBOL IdentOcc COMPUTE SYNT.Sym = TERM; END;

SYMBOL typeid INHERITS IdentOcc, TypeIdDefScope END;


SYMBOL event_block     INHERITS ExportRangeScope, ExportRangeUnique      END;
SYMBOL operation_block INHERITS ExportRangeScope, ExportRangeUnique      END;
SYMBOL iddef           INHERITS IdentOcc, ExportIdDefScope, ExportUnique END;
SYMBOL iduse           INHERITS IdentOcc, ExportIdUseEnv                 END;


RULE:
    operation_sig ::= 'operation' iddef str operation_block ':' typeid body
COMPUTE
    IF (NE (typeid.Key, strKey),
        message (FATAL, "Non-string return type", 0, COORDREF));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/d/reqsym.lido.3838534.lidoEta"


CHAIN reqsyms : PTGNode;

RULE:
    spec ::= aspects
COMPUTE
    CHAINSTART HEAD.reqsyms = PTGNULL;
    PTGOutFile (reqsymfilename, PTGreqsyms (aspects.reqsyms));
END;

RULE operation_sig1:
    operation_sig ::= 'operation' iddef str operation_block body
COMPUTE
    operation_sig.reqsyms = PTGSeq (operation_sig.reqsyms,
                                    PTGreqsym (iddef.idcode));
END;

RULE operation_sig2:
    operation_sig ::= 'operation' iddef str operation_block ':' typeid body
COMPUTE
    operation_sig.reqsyms = PTGSeq (operation_sig.reqsyms,
                                    PTGreqsym (iddef.idcode));
END;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/g/abstree.lido.3961924.lidoEta"
RULE rule_12:
aspects ::= aspects aspect_stmt
END;

RULE rule_13:
aspects ::= aspect_stmt
END;

RULE rule_14:
attrs ::= attr
END;

RULE rule_15:
attrs ::= attrs ',' attr
END;

RULE rule_16:
event_block ::= '(' optattrs ')'
END;

RULE rule_17:
iddef ::= ident
END;

RULE rule_18:
iduse ::= ident
END;

RULE rule_19:
operation_block ::= '(' optparams ')'
END;

RULE rule_20:
optattrs ::= 
END;

RULE rule_21:
optattrs ::= attrs
END;

RULE rule_22:
optparams ::= 
END;

RULE rule_23:
optparams ::= params
END;

RULE rule_24:
params ::= param
END;

RULE rule_25:
params ::= params ',' param
END;

RULE rule_26:
sig ::= event_sig
END;

RULE rule_27:
sig ::= operation_sig
END;

RULE rule_28:
sigs ::= sig
END;

RULE rule_29:
sigs ::= sigs sig
END;

RULE rule_30:
sig ::= translation_sig
END;

RULE rule_31:
typeid ::= ident
END;

RULE rule_11:
spec ::= aspects
END;

RULE rule_10:
aspect_stmt ::= 'aspect' iddef ';' sigs 'end' ';'
END;

RULE rule_9:
event_sig ::= 'event' iddef export str event_block ';'
END;

RULE rule_8:
export ::= '*'
END;

RULE rule_7:
export ::= 
END;

RULE rule_6:
attr ::= typeid iddef str
END;

RULE rule_5:
sig ::= bstr
END;

RULE rule_4:
sig ::= str
END;

RULE rule_3:
body ::= text
END;

RULE rule_2:
param ::= typeid iddef str
END;

RULE rule_1:
translation_sig ::= 'translation' iddef iduse str body
END;

RULE operation_sig2:
operation_sig ::= 'operation' iddef str operation_block ':' typeid body
END;

RULE operation_sig1:
operation_sig ::= 'operation' iddef str operation_block body
END;

