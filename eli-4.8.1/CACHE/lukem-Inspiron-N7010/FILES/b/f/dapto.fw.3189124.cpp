# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/f/dapto.fw.3183620.mapBnf"
aspects: aspects aspect_stmt.
aspects: aspect_stmt.
aspect_stmt: 'aspect' iddef ';' sigs 'end' ';'.
attrs: attr.
attrs: attrs ',' attr.
attr: typeid iddef str.
event_block: '(' optattrs ')'.
event_sig: 'event' iddef export str event_block ';'.
export: .
export: '*'.
iddef: ident.
iduse: ident.
operation_block: '(' optparams ')'.
operation_sig: 'operation' iddef str operation_block text.
operation_sig: 'operation' iddef str operation_block ':' typeid text.
optattrs: .
optattrs: attrs.
optparams: .
optparams: params.
params: param.
params: params ',' param.
param: typeid iddef str.
sig: bstr.
sig: event_sig.
sig: operation_sig.
sigs: sig.
sigs: sigs sig.
sig: str.
sig: translation_sig.
spec: aspects.
translation_sig: 'translation' iddef iduse str text.
typeid: ident.
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/f/dapto.fw.3185124.ligaProd"
RULE rule_11:	spec ::= aspects END;
RULE rule_10:	aspect_stmt ::= 'aspect' iddef ';' sigs 'end' ';' END;
RULE rule_9:	event_sig ::= 'event' iddef export str event_block ';' END;
RULE rule_8:	export ::= '*' END;
RULE rule_7:	export ::=  END;
RULE rule_6:	attr ::= typeid iddef str END;
RULE rule_5:	sig ::= bstr END;
RULE rule_4:	sig ::= str END;
RULE rule_3:	body ::= text END;
RULE rule_2:	param ::= typeid iddef str END;
RULE rule_1:	translation_sig ::= 'translation' iddef iduse str body END;
RULE operation_sig2:	operation_sig ::= 'operation' iddef str operation_block ':' typeid body END;
RULE operation_sig1:	operation_sig ::= 'operation' iddef str operation_block body END;
