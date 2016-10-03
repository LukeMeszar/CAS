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
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/d/Cpp.ptg.10333645.ptg"



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



Term: $ string "_" $ ":\n \"\\\"\" [PtgOutId $ int] \"\\\"\"\n"


PlainProd:
  $1 string "_" $2 string ":\n"
  "  \"new " $2 string "(\" [BP_BeginBlockI] [BP_BreakLine] "
    $3 " [BP_BreakLine] [BP_EndBlockI] \")\"\n"

SepSeq:
  $ { " \",\" [BP_BreakLine] " } $

ListProd:
  $1 string "_"  $2 string ":\n  \"new " $2 string
    "(\" [BP_BeginBlockI] [BP_BreakLine] "
    "$ [BP_BreakLine] [BP_EndBlockI] \")\"\n"

ListProd2:
  $1 string "_2" $2 string ":\n  { \"Comb" $1 string
    "(\" } $ { \",\" [BP_BreakLine] } $ { \")\" }\n" 

ListProd1:
  $1 string "_1" $2 string ":\n  \"new list<" $1 string " *>"
    "(\" [BP_BeginBlockI] [BP_BreakLine] \"1,\" [BP_BreakLine] "
    "$ [BP_BreakLine] [BP_EndBlockI] \")\"\n"

Triple: $ $ $


Header:
  "#ifndef " $1 string "_H\n"
  "#define " $1 string "_H\n\n"
  "#include <string>\n"
  "#include <list>\n\n"
  $2    
  "\nclass " $1 string "Visitor {\n"
  "  public:\n"
  $3    
  "};\n\n"
  "class " $1 string " {\n"
  "  public:\n"
  "    " $1 string "() { }\n"
  "    virtual ~" $1 string "() { }\n"
  "    virtual void Accept(" $1 string "Visitor *) { }\n"
  "};\n\n"
  $4    
  $5    
  $6    
  "\n#endif\n"

Forward:
  "class " $1 string ";\n"

Visit:
  "    virtual void Visit" $1 string "(" $1 string "*) = 0;\n"

DeclareCombine:
  "list<" $1 string " *> *"
    "Comb" $1 string "(list<" $1 string " *>*, list<" $1 string " *>*);\n\n"


SymbolClass:
  "class " $1 ": public " $2 string " {\n"
  "  public:\n"
  "    " $1 "() { }\n"
  "    virtual ~" $1 "() { }\n"
  "};\n\n"


ProductionClass:
  "class " $1 string ": public " $2 " {\n"
  "  public:\n"
  "    " $1 string "(" $3 ")\n"
  "      { " $4 "}\n"
  "    virtual ~" $1 string "() { }\n"
  "    virtual void Accept(" $7 string "Visitor *v)"
         " { v->Visit" $1 string "(this); }\n"
  $5    
  $6    
  "};\n\n"

Pointer:
  $ "*"

Argument:
  $1 " a" $2 int

Assign:
  "c" $1 int " = a" $1 int "; "

Computed:
  "c" $2 int " = (" $1 ")0; "

Access:
  "    " $1 " GetChild" $2 int "() { return c" $2 int "; }\n"

Set:
  "    void SetChild" $2 int "(" $1 " a) { c" $2 int " = a; }\n"

Declare:
  "    " $1 " c" $2 int ";\n"

Vars:
  "  private:\n"
  $

ListofProdClass:
  "class " $1 string ": public " $2 " {\n"
  "  public:\n"
  "    " $1 string "(list<" $3 string " *> *a)\n"
  "      { c = a; }\n"
  "    virtual ~" $1 string "() { }\n"
  "    virtual void Accept(" $3 string "Visitor *v)"
         " { v->Visit" $1 string "(this); }\n"
  "    list<" $3 string " *> *GetList() { return c; }\n"
  "  private:\n"
  "    list<" $3 string " *> *c;\n"
  "};\n\n"


Combine:
  "#include \"" $1 string ".h\"\n\n"
  "list<" $1 string " *> *\n"
  "Comb" $1 string "(list<" $1 string " *> *x, list<" $1 string " *> *y)\n"
  "{ x->splice(x->end(), *y, y->begin(), y->end()); y->~list(); return x; }\n"


AltSeq: $ { " | " } $
