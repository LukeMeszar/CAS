# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/p/clp.fw.1705560.mapBnf"
doc: .
doc: lit.
join: .
join: 'joinedto'.
join: 'with'.
literal: lit.
literals: literal.
literals: literals literal.
name: ident.
param: name 'input' doc.
param: name 'positional' doc.
param: name 'positionals' doc.
param: 'open' 'error' 'format' lit.
param: 'open' 'error' 'usage'.
params: .
params: params param ';'.
param: 'terminator' lit.
param: tparam.
param: 'usage' lit.
spec: params.
tparam: name literals join type doc.
type: 'boolean'.
type: 'booleans'.
type: 'int'.
type: 'ints'.
type: 'string'.
type: 'strings'.
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/p/clp.fw.1707064.ligaProd"
RULE rule_21:	spec ::= params END;
RULE rule_20:	param ::= 'terminator' lit END;
RULE rule_19:	tparam ::= name literals join type doc END;
RULE rule_18:	type ::= 'boolean' END;
RULE rule_17:	type ::= 'booleans' END;
RULE rule_16:	type ::= 'int' END;
RULE rule_15:	type ::= 'ints' END;
RULE rule_14:	type ::= 'string' END;
RULE rule_13:	type ::= 'strings' END;
RULE rule_12:	join ::=  END;
RULE rule_11:	join ::= 'joinedto' END;
RULE rule_10:	join ::= 'with' END;
RULE rule_9:	param ::= name 'positional' doc END;
RULE rule_8:	param ::= name 'positionals' doc END;
RULE rule_7:	param ::= name 'input' doc END;
RULE rule_6:	param ::= 'usage' lit END;
RULE rule_5:	param ::= 'open' 'error' 'format' lit END;
RULE rule_4:	param ::= 'open' 'error' 'usage' END;
RULE rule_3:	name ::= ident END;
RULE rule_2:	doc ::=  END;
RULE rule_1:	doc ::= lit END;
