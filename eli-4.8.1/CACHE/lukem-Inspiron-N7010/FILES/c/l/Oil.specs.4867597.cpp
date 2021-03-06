# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/t/PtgCommon.ptg.3490471.ptg"


Id:             [PtgOutId $ int]
AsIs:           $ string
Numb:           $ int   
CString:        [CPtgOutstr $ string]
CChar:          [CPtgOutchar $ int]
PString:        [PPtgOutstr $ string]


Seq:            $ $
CommaSeq:       $ { ", " } $
Eol:            $ "\n"

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/b/y/Code.ptg.5054929.ptg"


PDL:
  "\"OilDecls.h\"\n"
  "IsType: int;\n"
  "OilType: tOilType;\n"
  "OilOp: tOilOp;\n"
  "OilClass: tOilClass;\n"
  $     


TypeProperty:
  $2 " -> IsType={1}, OilType={(tOilType)&Oil_t" $1 "};\n"


OperatorProperty:
  $2 " -> OilOp={(tOilOp)&Oil_o" $1 "};\n"

MultOperator:
  $ ";\n"


ClassProperty:
  $2 " -> OilClass={(tOilClass)&Oil_c" $1 "};\n"



Header:
  "#ifndef OILDECLS_H\n"
  "#define OILDECLS_H\n"
  "#include \"oiladt2.h\"\n"
  $     
  "#endif\n"


TypeSymbol:
  "extern struct Stype Oil_t" $1 ";\t/* " $2 " */\n"
  "#define OilType" $2 " (&Oil_t" $1 ")\n"


OperatorSymbol:
  "extern struct Sop Oil_o" $1 ";\t/* " $2 " */\n"
  "#define OilOp" $2 " (&Oil_o" $1 ")\n"


ClassSymbol:
  "extern struct Sclass Oil_c" $1 ";\t/* " $2 " */\n"
  "#define OilClass" $2 " (&Oil_c" $1 ")\n"

