# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/d/tp.fw.12396251.mapBnf"
G1: G1 ',' SymbolDef.
G1: SymbolDef.
Nonterms: G1.
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/d/tp.fw.12397755.ligaProd"
RULE rule_19:	Source LISTOF Include | Declaration | Pattern END;
RULE rule_18:	Include ::= String END;
RULE rule_17:	Declaration ::= Nonterms ':' Type ';' END;
RULE rule_16:	Nonterms LISTOF SymbolDef END;
RULE rule_15:	Pattern ::= Signature ':' Identifier Cost ';' END;
RULE rule_14:	Pattern ::= Signature '::' Identifier Cost ';' END;
RULE rule_13:	Signature ::= SymbolUse '::=' Child Function END;
RULE rule_12:	Child ::= SymbolUse END;
RULE rule_11:	Child ::= Terminal '(' ')' END;
RULE rule_10:	Child ::= Terminal '(' Children ')' END;
RULE rule_9:	Children ::= Children ',' Child END;
RULE rule_8:	Children ::= Child END;
RULE rule_7:	Function ::=  END;
RULE rule_6:	Cost ::=  END;
RULE rule_5:	Cost ::= 'COST' Integer END;
RULE rule_4:	Type ::= Identifier END;
RULE rule_3:	Terminal ::= Identifier END;
RULE rule_2:	SymbolDef ::= Identifier END;
RULE rule_1:	SymbolUse ::= Identifier END;