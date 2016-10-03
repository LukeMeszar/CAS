# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/l/clp.con.1861678.con"

spec     : params.
params   :  / params param ';'.
param    : 'terminator' lit
         / tparam
         / name 'positional' doc
         / name 'positionals' doc
         / name 'input' doc
         / 'usage' lit
         / 'open' 'error' 'format' lit
         / 'open' 'error' 'usage'.
tparam   : name literals join type doc.
literals : literal / literals literal.
literal  : lit.
join     : 
         / 'joinedto'
         / 'with'.
type     : 'boolean'
         / 'booleans'
         / 'int'
         / 'ints'
         / 'string'
         / 'strings'.
name     : ident.
doc      : 
         / lit.
