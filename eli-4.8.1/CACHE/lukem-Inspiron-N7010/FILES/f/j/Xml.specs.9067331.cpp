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

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/d/l/Analysis.ptg.6887360.ptg"


Attr: $ "." $ string "Ptg"


Marker: "$" $ int


PlainRules:
  "CLASS SYMBOL " $1 string "Reproduce COMPUTE\n"
  "  SYNT." $1 string "OrigPtg=\n"
  "    RuleFct(\"PTG" $1 string "_\", RHS." $1 string "Ptg, TermFct(\"PTG"
$1 string "_\"));\n"
  "  SYNT." $1 string "Ptg=THIS." $1 string "OrigPtg;\n"
  "END;\n\n"

  "CLASS SYMBOL " $1 string "NoReproduce COMPUTE\n"
  "  SYNT." $1 string "Ptg = PTGNULL;\n"
  "END;\n\n"

ListofRule: 
  "CLASS SYMBOL " $1 string "Reproduce_" $3 " COMPUTE\n"
  "  SYNT." $1 string "OrigPtg=\n"
  "    PTG" $1 string "_" $2 "(\n"
  "      CONSTITUENTS (" $4 ")\n"
  "      SHIELD (" $5 ")\n"
  "      WITH (PTGNode, PTG" $1 string "_2" $2
    ", PTG" $1 string "_1" $2
    ", PTGNull));\n"
  "  SYNT." $1 string "Ptg=THIS." $1 string "OrigPtg;\n"
  "END;\n\n"


NontComp:
  "SYMBOL " $1 " INHERITS " $2 string "Reproduce END;\n"

ListComp:
  "SYMBOL " $1 " INHERITS " $2 string "Reproduce_" $1 " END;\n"

NontNoComp:
  "SYMBOL " $1 " INHERITS " $2 string "NoReproduce END;\n"


Axiom:  $ ":\n  " $ "\n"
Index:  "$" $ int
CType:  "$ " $ string
IndTyp: "$" $ int " " $ string
Call:   "[" $ string { " " } $ "]"
Option: "{ " $ " }"
SpSeq:  $ { " " } $

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/d/l/Idemcopy.ptg.6887032.ptg"

Plain:
  "RULE " $1 string ": " $2 string " ::= "    $3 " END;\n"

SpaceSeq:
  $ { " " } $

Listof:
  "RULE " $1 string ": " $2 string " LISTOF " $3 " END;\n"

AltSeq:
  $ { " | " } $

ComputedRoot:
  "$ " $1 string
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/f/h/Xml.ptg.9221622.ptg"



Frame:
  "@p maximum_input_line_length = infinity\n\n"
  "The following symbol computation can be used to display the entire input:"
  "\n\nSYMBOL ROOTCLASS COMPUTE\n"
  "  BP_Out(THIS." $1 string "Ptg);\n"
  "END;\n\n"
  "Applying this output function to the " $1 string
    "Ptg attribute of any nonterminal\n"
  "symbol in the tree will cause the subtree rooted in that node to be"
    " displayed.\n\n"
  "@O@<" $1 string "copy.lido@>@{\n"
  "ATTR " $1 string "Ptg, " $1 string "OrigPtg: PTGNode;\n\n"
  $2 "\n"       
  $3            
  $4            
  "@}\n\n"
  "@O@<" $1 string "copy.ptg@>@{\n"
  $5            
  "@}\n\n"
  "@O@<" $1 string "copy.ptg.phi@>@{\n"
  "#define IGNORE(f,n)\n"
  "@}\n\n"
  "@O@<" $1 string "copy.specs@>@{\n"
  "$/Output/PtgCommon.fw\n"
  "$/Output/BlockPrint.fw\n"
  "@}\n"



Term: $ string "_" $ ":\n  [PtgOutId $ int]\n"


PlainProd:
  $1 string "_" $2 string ":\n"
  "  \"<" $2 string ">\" [BP_BeginBlockI] [BP_BreakLine] "
    $3 " [BP_BreakLine] [BP_EndBlockI] \"</" $2 string ">\"\n"

SepSeq:
  $ { " [BP_BreakLine] " } $

Empty:
  $1 string "_" $2 string ":\n \"<" $2 string "/>\"\n"

ListProd:
  $1 string "_"  $2 string ":\n  \"<" $2 string
    ">\" [BP_BeginBlockI] [BP_BreakLine] "
    "$ [BP_BreakLine] [BP_EndBlockI] \"</" $2 string ">\"\n"

ListProd2: $1 string "_2" $2 string ":\n  $ { [BP_BreakLine] } $\n" 
ListProd1: $1 string "_1" $2 string ":\n  $\n"

Triple: $ $ $


dtd:
  $     
  $     


EntityDef: "<!ENTITY % " $ string " \"(" $ ")\">\n"


Element: "<!ELEMENT " $ string " " $ ">\n"

Content:
"(" $ ")"

ListContent:
"(" $ ")*"

EntityUse:
  "%" $ string ";"


AltSeq: $ { " | " } $
