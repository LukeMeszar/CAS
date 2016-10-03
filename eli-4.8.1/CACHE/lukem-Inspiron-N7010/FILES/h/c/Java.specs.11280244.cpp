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
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/h/a/Cpp.ptg.11433890.ptg"



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
  $1 string "_2" $2 string ":\n  { \"" $1 string ".Comb" $1 string
    "(\" } $ { \",\" [BP_BreakLine] } $ { \")\" }\n" 

ListProd1:
  $1 string "_1" $2 string ":\n  \"" $1 string ".Single" $1 string
    "(\" [BP_BeginBlockI] [BP_BreakLine] "
    "$ [BP_BreakLine] [BP_EndBlockI] \")\"\n"

Triple: $ $ $


Header:
  "package " $1 string ";\n\n"
  "import java.util.LinkedList;\n\n"
  "abstract public class " $1 string " {\n"
  "  abstract public void accept(" $1 string "Visitor a);\n"
  $2    
  "}\n"

Forward:
  "class " $1 string ";\n"

DeclareCombine:
  "  public static LinkedList Single" $1 string "(" $1 string " a)\n"
  "    { LinkedList t = new LinkedList(); t.add(a); return t; }\n"
  "  public static LinkedList Comb" $1 string "(LinkedList a, LinkedList b)\n"
  "    { a.addAll(b); return a; }\n"

Visitor:
  "package " $1 string ";\n\n"
  "abstract public class " $1 string "Visitor {\n"
  $2    
  "}\n"

Visit:
  "    abstract public void Visit" $1 string "(" $1 string " a);\n"


SymbolClass:
  "package " $2 string ";\n\n"
  "public abstract class " $1 " extends " $2 string " { }\n"


ProductionClass:
  "package " $7 string ";\n\n"
  "public final class " $1 string " extends " $2 " {\n"
  "  public " $1 string "(" $3 ")\n"
  "    { " $4 "}\n"
  "  public void accept(" $7 string "Visitor v)"
         " { v.Visit" $1 string "(this); }\n"
  $5    
  $6    
  "}\n"

Argument:
  $1 " a" $2 int

Assign:
  "c" $1 int " = a" $1 int "; "

Computed:
  "c" $2 int " = (" $1 ")0; "

Access:
  "  public " $1 " getChild" $2 int "() { return c" $2 int "; }\n"

Set:
  "  public void setChild" $2 int "(" $1 " a) { c" $2 int " = a; }\n"

Declare:
  "  private " $1 " c" $2 int ";\n"

ListofProdClass:
  "package " $3 string ";\n\n"
  "import java.util.LinkedList;\n\n"
  "final public class " $1 string " extends " $2 " {\n"
  "  public " $1 string "(LinkedList a) { c = a; }\n"
  "  public void accept(" $3 string "Visitor v)"
         " { v.visit" $1 string "(this); }\n"
  "  public LinkedList getList() { return c; }\n"
  "  private LinkedList c;\n"
  "}\n"


Combine:
  "#include \"" $1 string ".h\"\n\n"
  "list<" $1 string " *> *\n"
  "Comb" $1 string "(list<" $1 string " *> *x, list<" $1 string " *> *y)\n"
  "{ x->splice(x->end(), *y, y->begin(), y->end()); y->~list(); return x; }\n"


AltSeq: $ { " | " } $
