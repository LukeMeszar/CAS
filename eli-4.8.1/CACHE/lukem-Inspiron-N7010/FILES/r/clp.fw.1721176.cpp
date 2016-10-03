# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/o/clp.lido.1996843.lidoEta"

ATTR len, maxstrlen, id, nameid, docid, joined, spaced, rep : int;
ATTR desc, joinedstr : cstr;
ATTR opt, usage : PTGNode;

CHAIN decls, opts, params, externs, ousages, pusages : PTGNode;
CHAIN errmsg : PTGNode;
CHAIN numopts, usageerrmsg, inputs : int;

RULE:
    spec ::= params
COMPUTE
    CHAINSTART params.errmsg = PTGcstr ("%p cannot open %f: %t");
    CHAINSTART params.usageerrmsg = 0;
    CHAINSTART params.inputs = 0;

    spec.maxstrlen = CONSTITUENTS literal.len
                     SHIELD (doc) WITH (int, MAX, IDENTICAL, ZERO);

    CHAINSTART params.decls = PTGNULL;
    CHAINSTART params.numopts = 0;
    CHAINSTART params.opts = PTGNULL;

    CHAINSTART params.params = PTGNULL;
    CHAINSTART params.ousages = PTGNULL;
    CHAINSTART params.pusages = PTGNULL;
    CHAINSTART params.externs = PTGNULL;

    PTGOutFile ("clp.c", PTGfile (params.decls, params.numopts, params.opts,
                                  params.ousages, params.pusages,
                                  params.errmsg, params.usageerrmsg,
                                  params.params));
    PTGOutFile ("clp.h", PTGheader (params.externs));
END;

SYMBOL param
COMPUTE
    SYNT.maxstrlen = INCLUDING spec.maxstrlen;
END;

RULE:
    param ::= 'terminator' lit
COMPUTE
    param.numopts = ADD (param.numopts, 1);
    param.opts = PTGseq (param.opts, PTGtopt (lit));
    param.ousages = PTGseq (param.ousages,
                            PTGtuse (PTGpstr (lit, param.maxstrlen)));
END;

RULE:
    tparam ::= name literals join type doc
COMPUTE
    tparam.docid = doc.id;
    tparam.nameid = name.id;
    tparam.opt = type.opt;
    tparam.joined = join.joined;
    tparam.joinedstr = join.joinedstr;
    tparam.spaced = join.spaced;
    tparam.desc = type.desc;
    tparam.usage = PTGmsg (doc.id, IF (type.rep, "*", ""));
END;

SYMBOL type
COMPUTE
    SYNT.nameid = INCLUDING tparam.nameid;
    SYNT.docid = INCLUDING tparam.docid;
    SYNT.joinedstr = INCLUDING tparam.joinedstr;
    SYNT.rep = 0;
END;

RULE:
    type ::= 'boolean'
COMPUTE 
    type.desc = "";
    type.decls = PTGseq (type.decls, PTGbdecl (type.nameid));
    type.externs = PTGseq (type.externs, PTGiextern (type.nameid));
    type.opt = PTGopt ("BOOL", "", PTGvar (type.nameid), PTGnone (),
                       PTGnone ());
END;

RULE:
    type ::= 'booleans'
COMPUTE
    type.desc = "";
    type.decls = PTGseq (type.decls, PTGbdecl (type.nameid));
    type.externs = PTGseq (type.externs, PTGiextern (type.nameid));
    type.opt = PTGopt ("BOOL | PLURAL", "", PTGvar (type.nameid), PTGnone (),
                        PTGnone ());
    type.rep = 1;
END;

RULE:
    type ::= 'int'
COMPUTE
    type.desc = "int";
    type.decls = PTGseq3 (type.decls, PTGkdecl (type.nameid),
                          PTGidecl (type.nameid));
    type.externs = PTGseq (type.externs, PTGkextern (type.nameid));
    type.opt = PTGopt ("INTVAL", type.joinedstr, PTGcount (type.nameid),
                        PTGvar (type.nameid), PTGnone ());
END;

RULE:
    type ::= 'ints'
COMPUTE
    type.desc = "int";
    type.decls = PTGseq (type.decls, PTGkkdecl (type.nameid));
    type.externs = PTGseq (type.externs, PTGkkextern (type.nameid));
    type.opt = PTGopt ("INTVAL | PLURAL", type.joinedstr, PTGnone (),
                        PTGnone (), PTGvar (type.nameid));
    type.rep = 1;
END;

RULE:
    type ::= 'string'
COMPUTE
    type.desc = "string";
    type.decls = PTGseq3 (type.decls, PTGkdecl (type.nameid),
                          PTGidecl (type.nameid));
    type.externs = PTGseq (type.externs, PTGkextern (type.nameid));
    type.opt = PTGopt ("STRVAL", type.joinedstr, PTGcount (type.nameid),
                       PTGvar (type.nameid), PTGnone ());
END;

RULE:
    type ::= 'strings'
COMPUTE
    type.desc = "string";
    type.decls = PTGseq (type.decls, PTGkkdecl (type.nameid));
    type.externs = PTGseq (type.externs, PTGkkextern (type.nameid));
    type.opt = PTGopt ("STRVAL | PLURAL", type.joinedstr, PTGnone (),
                       PTGnone (), PTGvar (type.nameid));
    type.rep = 1;
END;

RULE:
    join ::=           
COMPUTE
    join.joined = 0;
    join.spaced = 1;
    join.joinedstr = "| SPACED";
END;

RULE:
    join ::= 'joinedto'
COMPUTE
    join.joined = 1;
    join.spaced = 0;
    join.joinedstr = "| JOINED";
END;

RULE:
    join ::= 'with'
COMPUTE
    join.joined = 1;
    join.spaced = 1;
    join.joinedstr = "| SPACED | JOINED";
END;

RULE:
    param ::= name 'positional' doc
COMPUTE
    param.decls = PTGseq (param.decls, PTGkdecl (name.id));
    param.params = PTGseq (param.params, PTGparam (name.id));
    param.externs = PTGseq (param.externs, PTGkextern (name.id));
    param.pusages = PTGseq (param.pusages,
                            PTGuse (PTGpstr (name.id, param.maxstrlen),
                                    doc.id));
END;

RULE:
    param ::= name 'positionals' doc
COMPUTE
    param.decls = PTGseq (param.decls, PTGkkdecl (name.id));
    param.params = PTGseq (param.params, PTGmparam (name.id));
    param.externs = PTGseq (param.externs, PTGkkextern (name.id));
    param.pusages = PTGseq (param.pusages,
                            PTGuses (PTGpstr (name.id, param.maxstrlen),
                                     doc.id));
END;

RULE:
    param ::= name 'input' doc
COMPUTE
    param.decls = PTGseq (param.decls, PTGkdecl (name.id));
    param.params = PTGseq (param.params, PTGinput (name.id));
    param.externs = PTGseq (param.externs, PTGkextern (name.id));
    param.pusages = PTGseq (param.pusages,
                            PTGuse (PTGpstr (name.id, param.maxstrlen),
                                    doc.id));
    param.inputs = ADD (param.inputs, 1);
    IF (NE (param.inputs, 0),
        message (ERROR, "can't have more than one input parameter", 0,
                 COORDREF));
END;

RULE:
    param ::= 'usage' lit
COMPUTE
    param.numopts = ADD (param.numopts, 1);
    param.opts = PTGseq (param.opts,
                         PTGseq (PTGlit (lit),
                                 PTGopt ("USAGE", "", PTGnone (), PTGnone (),
                                         PTGnone ())));
    param.ousages = PTGseq (param.ousages,
                            PTGuuse (PTGpstr (lit, param.maxstrlen)));
END;

RULE:
    param ::= 'open' 'error' 'format' lit
COMPUTE
    param.errmsg = PTGstr (lit) <- param.errmsg;
END;

RULE:
    param ::= 'open' 'error' 'usage'
COMPUTE
    param.usageerrmsg = 1 <- param.usageerrmsg;
END;

SYMBOL literal
COMPUTE
    SYNT.numopts = ADD (THIS.numopts, 1);
    SYNT.opts = PTGseq (THIS.opts,
                        PTGseq (PTGlit (TERM), INCLUDING tparam.opt));
    SYNT.usage = PTGseq (IF (INCLUDING tparam.spaced,
                             PTGvuse (TERM, " ", INCLUDING tparam.desc,
                                      INCLUDING spec.maxstrlen,
                                      INCLUDING tparam.usage),
                             PTGNULL),
                         IF (INCLUDING tparam.joined,
                             PTGvuse (TERM, "", INCLUDING tparam.desc,
                                      INCLUDING spec.maxstrlen,
                                      INCLUDING tparam.usage),
                             PTGNULL));
    SYNT.ousages = PTGseq (THIS.ousages, THIS.usage);
    SYNT.len = ADD (string_length (TERM), strlen (INCLUDING tparam.desc));
END;

RULE: name ::= ident COMPUTE name.id = ident; END;
RULE: doc  ::=       COMPUTE doc.id = NoStrIndex; END;
RULE: doc  ::= lit   COMPUTE doc.id = lit; END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/r/abstree.lido.2084299.lidoEta"
RULE rule_22:
literal ::= lit
END;

RULE rule_23:
literals ::= literal
END;

RULE rule_24:
literals ::= literals literal
END;

RULE rule_25:
params ::= 
END;

RULE rule_26:
params ::= params param ';'
END;

RULE rule_27:
param ::= tparam
END;

RULE rule_21:
spec ::= params
END;

RULE rule_20:
param ::= 'terminator' lit
END;

RULE rule_19:
tparam ::= name literals join type doc
END;

RULE rule_18:
type ::= 'boolean'
END;

RULE rule_17:
type ::= 'booleans'
END;

RULE rule_16:
type ::= 'int'
END;

RULE rule_15:
type ::= 'ints'
END;

RULE rule_14:
type ::= 'string'
END;

RULE rule_13:
type ::= 'strings'
END;

RULE rule_12:
join ::= 
END;

RULE rule_11:
join ::= 'joinedto'
END;

RULE rule_10:
join ::= 'with'
END;

RULE rule_9:
param ::= name 'positional' doc
END;

RULE rule_8:
param ::= name 'positionals' doc
END;

RULE rule_7:
param ::= name 'input' doc
END;

RULE rule_6:
param ::= 'usage' lit
END;

RULE rule_5:
param ::= 'open' 'error' 'format' lit
END;

RULE rule_4:
param ::= 'open' 'error' 'usage'
END;

RULE rule_3:
name ::= ident
END;

RULE rule_2:
doc ::= 
END;

RULE rule_1:
doc ::= lit
END;

