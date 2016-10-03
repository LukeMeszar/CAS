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

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/h/w/tp.ptg.12535606.ptg"


Burg:
  "%{\n"
  "#include \"tp_gen.h\"\n"
  "#define NODEPTR_TYPE TPNode\n"
  "#define OP_LABEL(p) ((p)->op)\n"
  "#define LEFT_CHILD(p) ((p)->left)\n"
  "#define RIGHT_CHILD(p) ((p)->right)\n"
  "#define STATE_LABEL(p) ((p)->state_label)\n"
  "#define PANIC printf\n"
  "#ifdef MONITOR\n"
  "#define COORD(p) ((p)->loc)\n"
  "#else\n"
  "#define COORD(p) NoPosition\n"
  "#endif\n"
  "%}\n\n"
  "%term\n"
  $
  "%%\n"
  $
  "%%\n\n"
  "#include \"csm.h\"\n"
  "#include \"obstack.h\"\n\n"
  "static Obstack obstk;\n"
  "static ObstackP scaffold = (ObstackP)0;\n\n"
  "static int HasError = 0;\n\n"
  "void\n"
  "TP_init()\n"
  "{ scaffold = &obstk; obstack_init(scaffold); }\n\n"
  "#ifdef MONITOR\n"
  "TPNode\n"
  "#ifdef PROTO_OK\n"
  "TPCoord(TPNode node, CoordPtr coord)\n"
  "#else\n"
  "TPCoord(node, coord) TPNode node; CoordPtr coord;\n"
  "#endif\n"
  "{\n"
  "  node->loc = coord;\n"
  "  return node; }\n"
  "#endif\n\n"
  "static void\n"
  "#ifdef PROTO_OK\n"
  "BuildError(TPNode node)\n"
  "#else\n"
  "BuildError(node) TPNode node;\n"
  "#endif\n"
  "{ char *msg;\n"
  "  int badkids = 0;\n"
  "  obstack_grow(Csm_obstk, \"No rule matches \\\"\", 18);\n"
  "  obstack_grow(\n"
  "    Csm_obstk,\n"
  "    TP_opname[OP_LABEL(node)],\n"
  "    strlen(TP_opname[OP_LABEL(node)]));\n"
  "  obstack_1grow(Csm_obstk, '(');\n"
  "  if (TP_arity[OP_LABEL(node)] > 0) {\n"
  "    if (!STATE_LABEL(LEFT_CHILD(node))) badkids++;\n"
  "    obstack_grow(\n"
  "      Csm_obstk,\n"
  "      TP_opname[OP_LABEL(LEFT_CHILD(node))],\n"
  "      strlen(TP_opname[OP_LABEL(LEFT_CHILD(node))]));\n"
  "  }\n"
  "  if (TP_arity[OP_LABEL(node)] > 1) {\n"
  "    if (!STATE_LABEL(RIGHT_CHILD(node))) badkids++;\n"
  "    obstack_1grow(Csm_obstk, ',');\n"
  "    obstack_grow(\n"
  "      Csm_obstk,\n"
  "      TP_opname[OP_LABEL(RIGHT_CHILD(node))],\n"
  "      strlen(TP_opname[OP_LABEL(RIGHT_CHILD(node))]));\n"
  "  }\n"
  "  msg = (char *)obstack_copy0(Csm_obstk, \")\\\"\", 3);\n"
  "  if (badkids) obstack_free(Csm_obstk, msg);\n"
  "  else message(ERROR, msg, 0, COORD(node));\n"
  "  HasError++;\n"
  "}\n\n"
  "static void\n"
  "#ifdef PROTO_OK\n"
  "ReduceError(TPNode p, int goalnt)\n"
  "#else\n"
  "ReduceError(p, goalnt) TPNode p; int goalnt;\n"
  "#endif\n"
  "{ if (HasError == 0 && !STATE_LABEL(p)) BuildError(p);\n"
  "  if (HasError > 0)\n"
  "    message(DEADLY,\"Can't parse a tree with errors\",0,COORD(p));\n"
  "  obstack_grow(Csm_obstk, \"No \\\"\", 5);\n"
  "  obstack_grow(Csm_obstk, TP_opname[p->op], strlen(TP_opname[p->op]));\n"
  "  obstack_1grow(Csm_obstk, '(');\n"
  "  if (TP_arity[p->op] > 0)\n"
  "    obstack_grow(\n"
  "      Csm_obstk,\n"
  "     TP_opname[p->left->op],\n"
  "     strlen(TP_opname[p->left->op]));\n"
  "  if (TP_arity[p->op] > 1) {\n"
  "    obstack_1grow(Csm_obstk, ',');\n"
  "    obstack_grow(\n"
  "      Csm_obstk,\n"
  "      TP_opname[p->right->op],\n"
  "      strlen(TP_opname[p->right->op]));\n"
  "  }\n"
  "  obstack_grow(Csm_obstk, \")\\\" rule builds \", 16);\n"
  "  message(DEADLY,\n"
  "    (char *)obstack_copy0(\n"
  "      Csm_obstk,\n"
  "      TP_ntname[goalnt],\n"
  "      strlen(TP_ntname[goalnt])),\n"
  "    0,\n"
  "    COORD(p));\n"
  "}\n\n"
  $             
  $ "\n"        
  $             
  $             

Include:
  "#include " $ "\n"

Header:
  "#ifndef TP_GEN_H\n"
  "#define TP_GEN_H\n\n"
  "#include \"eliproto.h\"\n"
  "#include \"err.h\"\n"
  "#include \"tpnode.h\"\n"
  $ "\n"        
  $ "\n"        
  "extern const char *TP_opname[];\n"
  "extern char  TP_arity[];\n"
  "extern const char *TP_string[];\n"
  "extern short TP_cost[][4];\n"
  "extern const char *TP_ntname[];\n\n"
  "extern void TP_init ELI_ARG((void));\n"
  "#ifdef MONITOR\n"
  "extern TPNode TPCoord ELI_ARG((TPNode node, CoordPtr coord));\n"
  "#else\n"
  "#define TPCoord(n,c) (n)\n"
  "#endif\n"
  "extern int TP_op_label ELI_ARG((TPNode));\n"
  "extern int TP_state_label ELI_ARG((TPNode));\n"
  "extern TPNode TP_child ELI_ARG((TPNode,int));\n"
  $ "\n"        
  "#ifdef MONITOR\n"
  "/* Monitoring support */\n\n"
  "#define DAPTO_RESULTTPNode(e)\tDAPTO_RESULT_PTR (e)\n"
  "#define DAPTO_ARGTPNode(e)\tDAPTO_ARG_PTR (e, TPNode)\n\n"
  "#endif\n\n"
  "#endif\n"


Term:
  $ "=" $ int "\n"

Macro:
  "#define " $ " " $ int "\n"


Pattern:
  $ " = " $ int " (" $ int "); /* " $ " */\n"

Commute:
  $1 ": " $2 "(" $3 "," $4 $5 ")"


Build0:
  "struct " $1 " {\n"
  "#ifdef MONITOR\n"
  "  CoordPtr loc;\n"
  "#endif\n"
  "  int op, state_label; " $2 "\n"
  "};\n\n"
  "TPNode\n"
  "#ifdef PROTO_OK\n"
  $1 "(int op" $3 ")\n"
  "#else\n"
  $1 "(op" $4 ") int op; " $2 "\n"
  "#endif\n"
  "{ struct " $1 " temp;\n\n"
  "  if (TP_arity[op] != 0) {\n"
  "    obstack_grow(Csm_obstk, TP_opname[op], strlen(TP_opname[op]));\n"
  "    message(DEADLY,\n"
  "      (char *)obstack_copy0(Csm_obstk, \" used with arity 0\", 18),\n"
  "      0,\n"
  "      NoPosition);\n"
  "  }\n"
  "  temp.op = op;\n"
  "  temp.state_label = TP_state(op, 0, 0);\n"
  "#ifdef MONITOR\n"
  "  temp.loc = NoPosition;\n"
  "#endif\n"
  $5
  "  return (TPNode)obstack_copy(scaffold, &temp, sizeof(temp));\n"
  "}\n\n"

Build1:
  "struct " $1 " {\n"
  "#ifdef MONITOR\n"
  "  CoordPtr loc;\n"
  "#endif\n"
  "  int op, state_label; TPNode left; " $2 "\n"
  "};\n\n"
  "TPNode\n"
  "#ifdef PROTO_OK\n"
  $1 "(int op, TPNode left" $3 ")\n"
  "#else\n"
  $1 "(op, left" $4 ") int op; TPNode left; " $2 "\n"
  "#endif\n"
  "{ struct " $1 " temp;\n\n"
  "  if (TP_arity[op] != 1) {\n"
  "    obstack_grow(Csm_obstk, TP_opname[op], strlen(TP_opname[op]));\n"
  "    message(DEADLY,\n"
  "      (char *)obstack_copy0(Csm_obstk, \" used with arity 1\", 18),\n"
  "      0,\n"
  "      NoPosition);\n"
  "  }\n"
  "  if (!STATE_LABEL(left)) BuildError(left);\n"
  "  temp.op = op;\n"
  "  temp.state_label = TP_state(op, STATE_LABEL(left), 0);\n"
  "  temp.left = left;\n"
  "#ifdef MONITOR\n"
  "  temp.loc = NoPosition;\n"
  "#endif\n"
  $5
  "  return (TPNode)obstack_copy(scaffold, &temp, sizeof(temp));\n"
  "}\n\n"

Build2:
  "struct " $1 " {\n"
  "#ifdef MONITOR\n"
  "  CoordPtr loc;\n"
  "#endif\n"
  "  int op, state_label; TPNode left, right; " $2 "\n"
  "};\n\n"
  "TPNode\n"
  "#ifdef PROTO_OK\n"
  $1 "(int op, TPNode left, TPNode right" $3 ")\n"
  "#else\n"
  $1 "(op, left, right" $4 ") int op; TPNode left, right; " $2 "\n"
  "#endif\n"
  "{ struct " $1 " temp;\n\n"
  "  if (TP_arity[op] != 2) {\n"
  "    obstack_grow(Csm_obstk, TP_opname[op], strlen(TP_opname[op]));\n"
  "    message(DEADLY,\n"
  "      (char *)obstack_copy0(Csm_obstk, \" used with arity 2\", 18),\n"
  "      0,\n"
  "      NoPosition);\n"
  "  }\n"
  "  if (!STATE_LABEL(left)) BuildError(left);\n"
  "  if (!STATE_LABEL(right)) BuildError(right);\n"
  "  temp.op = op;\n"
  "  temp.state_label = TP_state(op,STATE_LABEL(left),STATE_LABEL(right));\n"
  "  temp.left = left;\n"
  "  temp.right = right;\n"
  "#ifdef MONITOR\n"
  "  temp.loc = NoPosition;\n"
  "#endif\n"
  $5
  "  return (TPNode)obstack_copy(scaffold, &temp, sizeof(temp));\n"
  "}\n\n"

FieldDecl:
  $ " f_" $ int "; "

ArgDecl:
  ", " $ " f_" $ int

ArgName:
  ", f_" $ int

FieldSet:
  "  temp.f_" $1 int "=f_" $1 int ";\n"

Extern0:
  "extern TPNode " $ " ELI_ARG((int op" $ "));\n"

Extern1:
  "extern TPNode " $ " ELI_ARG((int op, TPNode left" $ "));\n"

Extern2:
  "extern TPNode " $
    " ELI_ARG((int op, TPNode left, TPNode right" $ "));\n"


Reducer:
  "static " $1 "\n"
  "#ifdef PROTO_OK\n"
  $2 "(TPNode p, int goalnt)\n"
  "#else\n"
  $2 "(p, goalnt) TPNode p; int goalnt;\n"
  "#endif\n"
  "{ int eruleno = TP_rule(STATE_LABEL(p), goalnt);\n"
  "  short *nts = TP_nts[eruleno];\n"
  "  TPNode kids[10];\n\n"
  "  if (!eruleno) ReduceError(p, goalnt);\n"
  "  TP_kids(p, eruleno, kids);\n"
  "\n"
  "  switch (eruleno) {\n"
  "  default: message(DEADLY,\"Invalid reduction\"," $4 int ",NoPosition);\n"
  $3
  "  }\n"
  "exit(1);\n"
  "}\n\n"

Forward:
  "static " $1 " " $2 " ELI_ARG((TPNode p, int goalnt));\n"

Case:
  "  case " $ int ": return " $ "(" $ ");\n"

ReducerCall:
  $1 "(kids[" $2 int "],nts[" $2 int "])"

GetValue:
  "((struct " $1 " *)p)->f_" $2 int


Transform:
  $2 "\n"
  "#ifdef PROTO_OK\n"
  "TP_" $1 "(TPNode p)\n"
  "#else\n"
  "TP_" $1 "(p) TPNode p;\n"
  "#endif\n"
  "{ return Reduce_" $2 "(p, TP_" $1 "_NT); }\n\n"

TransformDecl:
  "extern " $2 " TP_" $1 " ELI_ARG((TPNode));\n"

