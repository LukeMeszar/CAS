# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/clp/lib/clplib.pdl"























ClpValue : int;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/s/TypePreDefId.pdl.3487891.pdl"







# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/Predef.d.3327404.FILE" 1
 intKey;
 strKey;
# 8 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/s/TypePreDefId.pdl.3487891.pdl" 2







# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/t/ExportUnique.pdl.3491463.pdl"

ExportUnique:   int;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/gen.pdl.3323841.pdl"


"ptg_gen.h"

Translations, TranslationVars: PTGNode;

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/Type.pdl.3324164.pdl"
"Strings.h"
amp, send, type: CharPtr;

standard: int;

"ptg_gen.h"
cast: PTGNode;

intKey ->
  send = {"_INT"},
  standard = {1},
  cast = {PTGNULL},
  type = {"int"};

strKey -> 
  send = {"_STR"},
  standard = {1},
  cast = {PTGNULL},
  type = {"const char *"},
  amp = {""};

