# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/dapto.con.3323190.con"

spec: aspects.

aspects: aspect_stmt / aspects aspect_stmt.

aspect_stmt: 'aspect' iddef ';' sigs 'end' ';'.

sigs: sig / sigs sig.

sig: event_sig / operation_sig / str / bstr / translation_sig.

event_sig: 'event' iddef export str event_block ';'.
event_block: '(' optattrs ')'.

export: '*' / .

optattrs:  / attrs.
attrs: attr / attrs ',' attr.
attr: typeid iddef str.

operation_sig: 'operation' iddef str operation_block text /
               'operation' iddef str operation_block ':' typeid text.
operation_block: '(' optparams ')'.

optparams:  / params.
params: param / params ',' param.
param: typeid iddef str.

translation_sig: 'translation' iddef iduse str text.

iddef: ident.
iduse: ident.
typeid: ident.
