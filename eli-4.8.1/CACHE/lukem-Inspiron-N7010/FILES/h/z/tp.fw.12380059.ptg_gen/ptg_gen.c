#include <stdio.h>
#include <stdlib.h>

#include "ptg_gen.h"
#include "obstack.h"

/* -------------------------------------------------------- */
/*                      Memory Management                   */
/* -------------------------------------------------------- */

static Obstack _PTGObstack;
static void *_PTGFirstObj = NULL;

static void _PTGInit()
{
       if (_PTGFirstObj)
               return;
       obstack_init(&_PTGObstack);
       _PTGFirstObj = obstack_alloc(&_PTGObstack, 0);
}

void PTGFree()
{
       obstack_free(&_PTGObstack, _PTGFirstObj);
       _PTGFirstObj = obstack_alloc(&_PTGObstack, 0);
}


#if defined(__STDC__) || defined(__cplusplus)
static void *MALLOC(int size)
#else
static void *MALLOC(size) int size;
#endif
{
       if (! _PTGFirstObj)
               _PTGInit();
       return (obstack_alloc(&_PTGObstack, size));
}

/* -------------------------------------------------------- */
/*                       Output-functions                   */
/* -------------------------------------------------------- */

static PTG_OUTPUT_FILE f;
static char buffer[40];

#if PTG_OUTPUT_DEFAULT
#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGOut (PTGNode r)
#else
PTGNode PTGOut (r)
       PTGNode r;
#endif
{
       f = stdout;
       if (r) {
               (* (r->_print)) (r);
       }
       return (r);
}

#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGOutFile (const char *fn, PTGNode r)
#else
PTGNode PTGOutFile (fn, r)
       char * fn; PTGNode r;
#endif
{
       if ((f = fopen(fn, "w"))  == (FILE *)NULL)
       {
               fprintf(stderr, "ERROR: PTGOutFile: output file '%s' can't be opened.\n",fn);
               exit(1);
       }
       if (r)
               (* (r->_print)) (r);
       fclose(f);
       return (r);
}

#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGOutFPtr(FILE *fptr, PTGNode r)
#else
PTGNode PTGOutFPtr(fptr, r)
       FILE *fptr; PTGNode r;
#endif
{
       if ((f = fptr) == (FILE *)NULL)
       {
               fprintf(stderr, "ERROR: PTGOutFPtr: output file not open.\n");
               exit(1);
       }
       if (r)
               (* (r->_print)) (r);
       return (r);
}

#endif

#if defined(__STDC__) || defined(__cplusplus)
PTGNode PTGProcess(PTG_OUTPUT_FILE file, PTGNode r)
#else
PTGNode PTGProcess(file, r)
       PTG_OUTPUT_FILE file; PTGNode r;
#endif
{
       f = file;
       if (r)
               (* (r->_print)) (r);
       return (r);
}
/* -------------------------------------------------------- */
/*                            PTGNULL                       */
/* -------------------------------------------------------- */

/* Define PTGNULL as a PTGNode that prints nothing. */

#if defined(__STDC__) || defined(__cplusplus)
static void _PrPTGNULL(_PPTG0 n)
#else
static void _PrPTGNULL(n)
_PPTG0 n;
#endif
{(void)n; /* function printing nothing */}

struct _SPTG0   _PTGNULL = { (_PTGProc) _PrPTGNULL };

/* -------------------------------------------------------- */
/*          Node-Construction and Print-functions           */
/* -------------------------------------------------------- */

/* ============================ */

/* Implementation of Pattern Id */

typedef struct _SPTGId{
	_PTGProc _print;
	int p1;
} * _PPTGId;

#ifdef PROTO_OK
static void _PrPTGId(_PPTGId n)
#else
static void _PrPTGId(n)
	_PPTGId n;
#endif
{
	PtgOutId(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGId(int p1)
#else
PTGNode PTGId(p1)

int p1;
#endif
{
	_PPTGId n;
	n = (_PPTGId)MALLOC(sizeof(struct _SPTGId));
	n->_print = (_PTGProc)_PrPTGId;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern AsIs */

typedef struct _SPTGAsIs{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGAsIs;

#ifdef PROTO_OK
static void _PrPTGAsIs(_PPTGAsIs n)
#else
static void _PrPTGAsIs(n)
	_PPTGAsIs n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGAsIs(CONST char* p1)
#else
PTGNode PTGAsIs(p1)

CONST char* p1;
#endif
{
	_PPTGAsIs n;
	n = (_PPTGAsIs)MALLOC(sizeof(struct _SPTGAsIs));
	n->_print = (_PTGProc)_PrPTGAsIs;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Numb */

typedef struct _SPTGNumb{
	_PTGProc _print;
	int p1;
} * _PPTGNumb;

#ifdef PROTO_OK
static void _PrPTGNumb(_PPTGNumb n)
#else
static void _PrPTGNumb(n)
	_PPTGNumb n;
#endif
{
	PTG_OUTPUT_INT(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGNumb(int p1)
#else
PTGNode PTGNumb(p1)

int p1;
#endif
{
	_PPTGNumb n;
	n = (_PPTGNumb)MALLOC(sizeof(struct _SPTGNumb));
	n->_print = (_PTGProc)_PrPTGNumb;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CString */

typedef struct _SPTGCString{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGCString;

#ifdef PROTO_OK
static void _PrPTGCString(_PPTGCString n)
#else
static void _PrPTGCString(n)
	_PPTGCString n;
#endif
{
	CPtgOutstr(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCString(CONST char* p1)
#else
PTGNode PTGCString(p1)

CONST char* p1;
#endif
{
	_PPTGCString n;
	n = (_PPTGCString)MALLOC(sizeof(struct _SPTGCString));
	n->_print = (_PTGProc)_PrPTGCString;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CChar */

typedef struct _SPTGCChar{
	_PTGProc _print;
	int p1;
} * _PPTGCChar;

#ifdef PROTO_OK
static void _PrPTGCChar(_PPTGCChar n)
#else
static void _PrPTGCChar(n)
	_PPTGCChar n;
#endif
{
	CPtgOutchar(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCChar(int p1)
#else
PTGNode PTGCChar(p1)

int p1;
#endif
{
	_PPTGCChar n;
	n = (_PPTGCChar)MALLOC(sizeof(struct _SPTGCChar));
	n->_print = (_PTGProc)_PrPTGCChar;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern PString */

typedef struct _SPTGPString{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGPString;

#ifdef PROTO_OK
static void _PrPTGPString(_PPTGPString n)
#else
static void _PrPTGPString(n)
	_PPTGPString n;
#endif
{
	PPtgOutstr(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGPString(CONST char* p1)
#else
PTGNode PTGPString(p1)

CONST char* p1;
#endif
{
	_PPTGPString n;
	n = (_PPTGPString)MALLOC(sizeof(struct _SPTGPString));
	n->_print = (_PTGProc)_PrPTGPString;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Seq */

typedef struct _SPTGSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSeq;

#ifdef PROTO_OK
static void _PrPTGSeq(_PPTGSeq n)
#else
static void _PrPTGSeq(n)
	_PPTGSeq n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGSeq)MALLOC(sizeof(struct _SPTGSeq));
	n->_print = (_PTGProc)_PrPTGSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern CommaSeq */

typedef struct _SPTGCommaSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGCommaSeq;

#ifdef PROTO_OK
static void _PrPTGCommaSeq(_PPTGCommaSeq n)
#else
static void _PrPTGCommaSeq(n)
	_PPTGCommaSeq n;
#endif
{
	n->p1->_print(n->p1);
	if (n->p1 != PTGNULL && n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, ", ");
	}
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGCommaSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGCommaSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGCommaSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGCommaSeq)MALLOC(sizeof(struct _SPTGCommaSeq));
	n->_print = (_PTGProc)_PrPTGCommaSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Eol */

typedef struct _SPTGEol{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGEol;

#ifdef PROTO_OK
static void _PrPTGEol(_PPTGEol n)
#else
static void _PrPTGEol(n)
	_PPTGEol n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGEol(PTGNode p1)
#else
PTGNode PTGEol(p1)

PTGNode p1;
#endif
{
	_PPTGEol n;
	n = (_PPTGEol)MALLOC(sizeof(struct _SPTGEol));
	n->_print = (_PTGProc)_PrPTGEol;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Burg */

typedef struct _SPTGBurg{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGBurg;

#ifdef PROTO_OK
static void _PrPTGBurg(_PPTGBurg n)
#else
static void _PrPTGBurg(n)
	_PPTGBurg n;
#endif
{
	PTG_OUTPUT_STRING(f, "%{\n");
	PTG_OUTPUT_STRING(f, "#include \"tp_gen.h\"\n");
	PTG_OUTPUT_STRING(f, "#define NODEPTR_TYPE TPNode\n");
	PTG_OUTPUT_STRING(f, "#define OP_LABEL(p) ((p)->op)\n");
	PTG_OUTPUT_STRING(f, "#define LEFT_CHILD(p) ((p)->left)\n");
	PTG_OUTPUT_STRING(f, "#define RIGHT_CHILD(p) ((p)->right)\n");
	PTG_OUTPUT_STRING(f, "#define STATE_LABEL(p) ((p)->state_label)\n");
	PTG_OUTPUT_STRING(f, "#define PANIC printf\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "#define COORD(p) ((p)->loc)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "#define COORD(p) NoPosition\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "%}\n\n");
	PTG_OUTPUT_STRING(f, "%term\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "%%\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "%%\n\n");
	PTG_OUTPUT_STRING(f, "#include \"csm.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"obstack.h\"\n\n");
	PTG_OUTPUT_STRING(f, "static Obstack obstk;\n");
	PTG_OUTPUT_STRING(f, "static ObstackP scaffold = (ObstackP)0;\n\n");
	PTG_OUTPUT_STRING(f, "static int HasError = 0;\n\n");
	PTG_OUTPUT_STRING(f, "void\n");
	PTG_OUTPUT_STRING(f, "TP_init()\n");
	PTG_OUTPUT_STRING(f, "{ scaffold = &obstk; obstack_init(scaffold); }\n\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "TPNode\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "TPCoord(TPNode node, CoordPtr coord)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "TPCoord(node, coord) TPNode node; CoordPtr coord;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	PTG_OUTPUT_STRING(f, "  node->loc = coord;\n");
	PTG_OUTPUT_STRING(f, "  return node; }\n");
	PTG_OUTPUT_STRING(f, "#endif\n\n");
	PTG_OUTPUT_STRING(f, "static void\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "BuildError(TPNode node)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "BuildError(node) TPNode node;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ char *msg;\n");
	PTG_OUTPUT_STRING(f, "  int badkids = 0;\n");
	PTG_OUTPUT_STRING(f, "  obstack_grow(Csm_obstk, \"No rule matches \\\"\", 18);\n");
	PTG_OUTPUT_STRING(f, "  obstack_grow(\n");
	PTG_OUTPUT_STRING(f, "    Csm_obstk,\n");
	PTG_OUTPUT_STRING(f, "    TP_opname[OP_LABEL(node)],\n");
	PTG_OUTPUT_STRING(f, "    strlen(TP_opname[OP_LABEL(node)]));\n");
	PTG_OUTPUT_STRING(f, "  obstack_1grow(Csm_obstk, '(');\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[OP_LABEL(node)] > 0) {\n");
	PTG_OUTPUT_STRING(f, "    if (!STATE_LABEL(LEFT_CHILD(node))) badkids++;\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(\n");
	PTG_OUTPUT_STRING(f, "      Csm_obstk,\n");
	PTG_OUTPUT_STRING(f, "      TP_opname[OP_LABEL(LEFT_CHILD(node))],\n");
	PTG_OUTPUT_STRING(f, "      strlen(TP_opname[OP_LABEL(LEFT_CHILD(node))]));\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[OP_LABEL(node)] > 1) {\n");
	PTG_OUTPUT_STRING(f, "    if (!STATE_LABEL(RIGHT_CHILD(node))) badkids++;\n");
	PTG_OUTPUT_STRING(f, "    obstack_1grow(Csm_obstk, ',');\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(\n");
	PTG_OUTPUT_STRING(f, "      Csm_obstk,\n");
	PTG_OUTPUT_STRING(f, "      TP_opname[OP_LABEL(RIGHT_CHILD(node))],\n");
	PTG_OUTPUT_STRING(f, "      strlen(TP_opname[OP_LABEL(RIGHT_CHILD(node))]));\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "  msg = (char *)obstack_copy0(Csm_obstk, \")\\\"\", 3);\n");
	PTG_OUTPUT_STRING(f, "  if (badkids) obstack_free(Csm_obstk, msg);\n");
	PTG_OUTPUT_STRING(f, "  else message(ERROR, msg, 0, COORD(node));\n");
	PTG_OUTPUT_STRING(f, "  HasError++;\n");
	PTG_OUTPUT_STRING(f, "}\n\n");
	PTG_OUTPUT_STRING(f, "static void\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "ReduceError(TPNode p, int goalnt)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "ReduceError(p, goalnt) TPNode p; int goalnt;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ if (HasError == 0 && !STATE_LABEL(p)) BuildError(p);\n");
	PTG_OUTPUT_STRING(f, "  if (HasError > 0)\n");
	PTG_OUTPUT_STRING(f, "    message(DEADLY,\"Can't parse a tree with errors\",0,COORD(p));\n");
	PTG_OUTPUT_STRING(f, "  obstack_grow(Csm_obstk, \"No \\\"\", 5);\n");
	PTG_OUTPUT_STRING(f, "  obstack_grow(Csm_obstk, TP_opname[p->op], strlen(TP_opname[p->op]));\n");
	PTG_OUTPUT_STRING(f, "  obstack_1grow(Csm_obstk, '(');\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[p->op] > 0)\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(\n");
	PTG_OUTPUT_STRING(f, "      Csm_obstk,\n");
	PTG_OUTPUT_STRING(f, "     TP_opname[p->left->op],\n");
	PTG_OUTPUT_STRING(f, "     strlen(TP_opname[p->left->op]));\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[p->op] > 1) {\n");
	PTG_OUTPUT_STRING(f, "    obstack_1grow(Csm_obstk, ',');\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(\n");
	PTG_OUTPUT_STRING(f, "      Csm_obstk,\n");
	PTG_OUTPUT_STRING(f, "      TP_opname[p->right->op],\n");
	PTG_OUTPUT_STRING(f, "      strlen(TP_opname[p->right->op]));\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "  obstack_grow(Csm_obstk, \")\\\" rule builds \", 16);\n");
	PTG_OUTPUT_STRING(f, "  message(DEADLY,\n");
	PTG_OUTPUT_STRING(f, "    (char *)obstack_copy0(\n");
	PTG_OUTPUT_STRING(f, "      Csm_obstk,\n");
	PTG_OUTPUT_STRING(f, "      TP_ntname[goalnt],\n");
	PTG_OUTPUT_STRING(f, "      strlen(TP_ntname[goalnt])),\n");
	PTG_OUTPUT_STRING(f, "    0,\n");
	PTG_OUTPUT_STRING(f, "    COORD(p));\n");
	PTG_OUTPUT_STRING(f, "}\n\n");
	n->p3->_print(n->p3);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "\n");
	n->p5->_print(n->p5);
	n->p6->_print(n->p6);
}

#ifdef PROTO_OK
PTGNode PTGBurg(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGBurg(p1, p2, p3, p4, p5, p6)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGBurg n;
	n = (_PPTGBurg)MALLOC(sizeof(struct _SPTGBurg));
	n->_print = (_PTGProc)_PrPTGBurg;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern Include */

typedef struct _SPTGInclude{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGInclude;

#ifdef PROTO_OK
static void _PrPTGInclude(_PPTGInclude n)
#else
static void _PrPTGInclude(n)
	_PPTGInclude n;
#endif
{
	PTG_OUTPUT_STRING(f, "#include ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGInclude(PTGNode p1)
#else
PTGNode PTGInclude(p1)

PTGNode p1;
#endif
{
	_PPTGInclude n;
	n = (_PPTGInclude)MALLOC(sizeof(struct _SPTGInclude));
	n->_print = (_PTGProc)_PrPTGInclude;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Header */

typedef struct _SPTGHeader{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGHeader;

#ifdef PROTO_OK
static void _PrPTGHeader(_PPTGHeader n)
#else
static void _PrPTGHeader(n)
	_PPTGHeader n;
#endif
{
	PTG_OUTPUT_STRING(f, "#ifndef TP_GEN_H\n");
	PTG_OUTPUT_STRING(f, "#define TP_GEN_H\n\n");
	PTG_OUTPUT_STRING(f, "#include \"eliproto.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"err.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"tpnode.h\"\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "extern const char *TP_opname[];\n");
	PTG_OUTPUT_STRING(f, "extern char  TP_arity[];\n");
	PTG_OUTPUT_STRING(f, "extern const char *TP_string[];\n");
	PTG_OUTPUT_STRING(f, "extern short TP_cost[][4];\n");
	PTG_OUTPUT_STRING(f, "extern const char *TP_ntname[];\n\n");
	PTG_OUTPUT_STRING(f, "extern void TP_init ELI_ARG((void));\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "extern TPNode TPCoord ELI_ARG((TPNode node, CoordPtr coord));\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "#define TPCoord(n,c) (n)\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "extern int TP_op_label ELI_ARG((TPNode));\n");
	PTG_OUTPUT_STRING(f, "extern int TP_state_label ELI_ARG((TPNode));\n");
	PTG_OUTPUT_STRING(f, "extern TPNode TP_child ELI_ARG((TPNode,int));\n");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "/* Monitoring support */\n\n");
	PTG_OUTPUT_STRING(f, "#define DAPTO_RESULTTPNode(e)\tDAPTO_RESULT_PTR (e)\n");
	PTG_OUTPUT_STRING(f, "#define DAPTO_ARGTPNode(e)\tDAPTO_ARG_PTR (e, TPNode)\n\n");
	PTG_OUTPUT_STRING(f, "#endif\n\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGHeader(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGHeader(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGHeader n;
	n = (_PPTGHeader)MALLOC(sizeof(struct _SPTGHeader));
	n->_print = (_PTGProc)_PrPTGHeader;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern Term */

typedef struct _SPTGTerm{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGTerm;

#ifdef PROTO_OK
static void _PrPTGTerm(_PPTGTerm n)
#else
static void _PrPTGTerm(n)
	_PPTGTerm n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "=");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGTerm(PTGNode p1, int p2)
#else
PTGNode PTGTerm(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGTerm n;
	n = (_PPTGTerm)MALLOC(sizeof(struct _SPTGTerm));
	n->_print = (_PTGProc)_PrPTGTerm;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Macro */

typedef struct _SPTGMacro{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGMacro;

#ifdef PROTO_OK
static void _PrPTGMacro(_PPTGMacro n)
#else
static void _PrPTGMacro(n)
	_PPTGMacro n;
#endif
{
	PTG_OUTPUT_STRING(f, "#define ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGMacro(PTGNode p1, int p2)
#else
PTGNode PTGMacro(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGMacro n;
	n = (_PPTGMacro)MALLOC(sizeof(struct _SPTGMacro));
	n->_print = (_PTGProc)_PrPTGMacro;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Pattern */

typedef struct _SPTGPattern{
	_PTGProc _print;
	PTGNode p1;
	int p2;
	int p3;
	PTGNode p4;
} * _PPTGPattern;

#ifdef PROTO_OK
static void _PrPTGPattern(_PPTGPattern n)
#else
static void _PrPTGPattern(n)
	_PPTGPattern n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " = ");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, " (");
	PTG_OUTPUT_INT(f, n->p3);
	PTG_OUTPUT_STRING(f, "); /* ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, " */\n");
}

#ifdef PROTO_OK
PTGNode PTGPattern(PTGNode p1, int p2, int p3, PTGNode p4)
#else
PTGNode PTGPattern(p1, p2, p3, p4)

PTGNode p1;
int p2;
int p3;
PTGNode p4;
#endif
{
	_PPTGPattern n;
	n = (_PPTGPattern)MALLOC(sizeof(struct _SPTGPattern));
	n->_print = (_PTGProc)_PrPTGPattern;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern Commute */

typedef struct _SPTGCommute{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGCommute;

#ifdef PROTO_OK
static void _PrPTGCommute(_PPTGCommute n)
#else
static void _PrPTGCommute(n)
	_PPTGCommute n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ": ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "(");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ",");
	n->p4->_print(n->p4);
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGCommute(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGCommute(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGCommute n;
	n = (_PPTGCommute)MALLOC(sizeof(struct _SPTGCommute));
	n->_print = (_PTGProc)_PrPTGCommute;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern Build0 */

typedef struct _SPTGBuild0{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGBuild0;

#ifdef PROTO_OK
static void _PrPTGBuild0(_PPTGBuild0 n)
#else
static void _PrPTGBuild0(n)
	_PPTGBuild0 n;
#endif
{
	PTG_OUTPUT_STRING(f, "struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " {\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "  CoordPtr loc;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "  int op, state_label; ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "};\n\n");
	PTG_OUTPUT_STRING(f, "TPNode\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(int op");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(op");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") int op; ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " temp;\n\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[op] != 0) {\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(Csm_obstk, TP_opname[op], strlen(TP_opname[op]));\n");
	PTG_OUTPUT_STRING(f, "    message(DEADLY,\n");
	PTG_OUTPUT_STRING(f, "      (char *)obstack_copy0(Csm_obstk, \" used with arity 0\", 18),\n");
	PTG_OUTPUT_STRING(f, "      0,\n");
	PTG_OUTPUT_STRING(f, "      NoPosition);\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "  temp.op = op;\n");
	PTG_OUTPUT_STRING(f, "  temp.state_label = TP_state(op, 0, 0);\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "  temp.loc = NoPosition;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "  return (TPNode)obstack_copy(scaffold, &temp, sizeof(temp));\n");
	PTG_OUTPUT_STRING(f, "}\n\n");
}

#ifdef PROTO_OK
PTGNode PTGBuild0(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGBuild0(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGBuild0 n;
	n = (_PPTGBuild0)MALLOC(sizeof(struct _SPTGBuild0));
	n->_print = (_PTGProc)_PrPTGBuild0;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern Build1 */

typedef struct _SPTGBuild1{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGBuild1;

#ifdef PROTO_OK
static void _PrPTGBuild1(_PPTGBuild1 n)
#else
static void _PrPTGBuild1(n)
	_PPTGBuild1 n;
#endif
{
	PTG_OUTPUT_STRING(f, "struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " {\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "  CoordPtr loc;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "  int op, state_label; TPNode left; ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "};\n\n");
	PTG_OUTPUT_STRING(f, "TPNode\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(int op, TPNode left");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(op, left");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") int op; TPNode left; ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " temp;\n\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[op] != 1) {\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(Csm_obstk, TP_opname[op], strlen(TP_opname[op]));\n");
	PTG_OUTPUT_STRING(f, "    message(DEADLY,\n");
	PTG_OUTPUT_STRING(f, "      (char *)obstack_copy0(Csm_obstk, \" used with arity 1\", 18),\n");
	PTG_OUTPUT_STRING(f, "      0,\n");
	PTG_OUTPUT_STRING(f, "      NoPosition);\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "  if (!STATE_LABEL(left)) BuildError(left);\n");
	PTG_OUTPUT_STRING(f, "  temp.op = op;\n");
	PTG_OUTPUT_STRING(f, "  temp.state_label = TP_state(op, STATE_LABEL(left), 0);\n");
	PTG_OUTPUT_STRING(f, "  temp.left = left;\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "  temp.loc = NoPosition;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "  return (TPNode)obstack_copy(scaffold, &temp, sizeof(temp));\n");
	PTG_OUTPUT_STRING(f, "}\n\n");
}

#ifdef PROTO_OK
PTGNode PTGBuild1(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGBuild1(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGBuild1 n;
	n = (_PPTGBuild1)MALLOC(sizeof(struct _SPTGBuild1));
	n->_print = (_PTGProc)_PrPTGBuild1;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern Build2 */

typedef struct _SPTGBuild2{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGBuild2;

#ifdef PROTO_OK
static void _PrPTGBuild2(_PPTGBuild2 n)
#else
static void _PrPTGBuild2(n)
	_PPTGBuild2 n;
#endif
{
	PTG_OUTPUT_STRING(f, "struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " {\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "  CoordPtr loc;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "  int op, state_label; TPNode left, right; ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "};\n\n");
	PTG_OUTPUT_STRING(f, "TPNode\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(int op, TPNode left, TPNode right");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(op, left, right");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ") int op; TPNode left, right; ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " temp;\n\n");
	PTG_OUTPUT_STRING(f, "  if (TP_arity[op] != 2) {\n");
	PTG_OUTPUT_STRING(f, "    obstack_grow(Csm_obstk, TP_opname[op], strlen(TP_opname[op]));\n");
	PTG_OUTPUT_STRING(f, "    message(DEADLY,\n");
	PTG_OUTPUT_STRING(f, "      (char *)obstack_copy0(Csm_obstk, \" used with arity 2\", 18),\n");
	PTG_OUTPUT_STRING(f, "      0,\n");
	PTG_OUTPUT_STRING(f, "      NoPosition);\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "  if (!STATE_LABEL(left)) BuildError(left);\n");
	PTG_OUTPUT_STRING(f, "  if (!STATE_LABEL(right)) BuildError(right);\n");
	PTG_OUTPUT_STRING(f, "  temp.op = op;\n");
	PTG_OUTPUT_STRING(f, "  temp.state_label = TP_state(op,STATE_LABEL(left),STATE_LABEL(right));\n");
	PTG_OUTPUT_STRING(f, "  temp.left = left;\n");
	PTG_OUTPUT_STRING(f, "  temp.right = right;\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "  temp.loc = NoPosition;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "  return (TPNode)obstack_copy(scaffold, &temp, sizeof(temp));\n");
	PTG_OUTPUT_STRING(f, "}\n\n");
}

#ifdef PROTO_OK
PTGNode PTGBuild2(PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGBuild2(p1, p2, p3, p4, p5)

PTGNode p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGBuild2 n;
	n = (_PPTGBuild2)MALLOC(sizeof(struct _SPTGBuild2));
	n->_print = (_PTGProc)_PrPTGBuild2;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern FieldDecl */

typedef struct _SPTGFieldDecl{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGFieldDecl;

#ifdef PROTO_OK
static void _PrPTGFieldDecl(_PPTGFieldDecl n)
#else
static void _PrPTGFieldDecl(n)
	_PPTGFieldDecl n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " f_");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, "; ");
}

#ifdef PROTO_OK
PTGNode PTGFieldDecl(PTGNode p1, int p2)
#else
PTGNode PTGFieldDecl(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGFieldDecl n;
	n = (_PPTGFieldDecl)MALLOC(sizeof(struct _SPTGFieldDecl));
	n->_print = (_PTGProc)_PrPTGFieldDecl;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ArgDecl */

typedef struct _SPTGArgDecl{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGArgDecl;

#ifdef PROTO_OK
static void _PrPTGArgDecl(_PPTGArgDecl n)
#else
static void _PrPTGArgDecl(n)
	_PPTGArgDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, ", ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " f_");
	PTG_OUTPUT_INT(f, n->p2);
}

#ifdef PROTO_OK
PTGNode PTGArgDecl(PTGNode p1, int p2)
#else
PTGNode PTGArgDecl(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGArgDecl n;
	n = (_PPTGArgDecl)MALLOC(sizeof(struct _SPTGArgDecl));
	n->_print = (_PTGProc)_PrPTGArgDecl;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ArgName */

typedef struct _SPTGArgName{
	_PTGProc _print;
	int p1;
} * _PPTGArgName;

#ifdef PROTO_OK
static void _PrPTGArgName(_PPTGArgName n)
#else
static void _PrPTGArgName(n)
	_PPTGArgName n;
#endif
{
	PTG_OUTPUT_STRING(f, ", f_");
	PTG_OUTPUT_INT(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGArgName(int p1)
#else
PTGNode PTGArgName(p1)

int p1;
#endif
{
	_PPTGArgName n;
	n = (_PPTGArgName)MALLOC(sizeof(struct _SPTGArgName));
	n->_print = (_PTGProc)_PrPTGArgName;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern FieldSet */

typedef struct _SPTGFieldSet{
	_PTGProc _print;
	int p1;
} * _PPTGFieldSet;

#ifdef PROTO_OK
static void _PrPTGFieldSet(_PPTGFieldSet n)
#else
static void _PrPTGFieldSet(n)
	_PPTGFieldSet n;
#endif
{
	PTG_OUTPUT_STRING(f, "  temp.f_");
	PTG_OUTPUT_INT(f, n->p1);
	PTG_OUTPUT_STRING(f, "=f_");
	PTG_OUTPUT_INT(f, n->p1);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGFieldSet(int p1)
#else
PTGNode PTGFieldSet(p1)

int p1;
#endif
{
	_PPTGFieldSet n;
	n = (_PPTGFieldSet)MALLOC(sizeof(struct _SPTGFieldSet));
	n->_print = (_PTGProc)_PrPTGFieldSet;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Extern0 */

typedef struct _SPTGExtern0{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGExtern0;

#ifdef PROTO_OK
static void _PrPTGExtern0(_PPTGExtern0 n)
#else
static void _PrPTGExtern0(n)
	_PPTGExtern0 n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern TPNode ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ELI_ARG((int op");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "));\n");
}

#ifdef PROTO_OK
PTGNode PTGExtern0(PTGNode p1, PTGNode p2)
#else
PTGNode PTGExtern0(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGExtern0 n;
	n = (_PPTGExtern0)MALLOC(sizeof(struct _SPTGExtern0));
	n->_print = (_PTGProc)_PrPTGExtern0;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Extern1 */

typedef struct _SPTGExtern1{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGExtern1;

#ifdef PROTO_OK
static void _PrPTGExtern1(_PPTGExtern1 n)
#else
static void _PrPTGExtern1(n)
	_PPTGExtern1 n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern TPNode ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ELI_ARG((int op, TPNode left");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "));\n");
}

#ifdef PROTO_OK
PTGNode PTGExtern1(PTGNode p1, PTGNode p2)
#else
PTGNode PTGExtern1(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGExtern1 n;
	n = (_PPTGExtern1)MALLOC(sizeof(struct _SPTGExtern1));
	n->_print = (_PTGProc)_PrPTGExtern1;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Extern2 */

typedef struct _SPTGExtern2{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGExtern2;

#ifdef PROTO_OK
static void _PrPTGExtern2(_PPTGExtern2 n)
#else
static void _PrPTGExtern2(n)
	_PPTGExtern2 n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern TPNode ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ELI_ARG((int op, TPNode left, TPNode right");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "));\n");
}

#ifdef PROTO_OK
PTGNode PTGExtern2(PTGNode p1, PTGNode p2)
#else
PTGNode PTGExtern2(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGExtern2 n;
	n = (_PPTGExtern2)MALLOC(sizeof(struct _SPTGExtern2));
	n->_print = (_PTGProc)_PrPTGExtern2;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Reducer */

typedef struct _SPTGReducer{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
	int p4;
} * _PPTGReducer;

#ifdef PROTO_OK
static void _PrPTGReducer(_PPTGReducer n)
#else
static void _PrPTGReducer(n)
	_PPTGReducer n;
#endif
{
	PTG_OUTPUT_STRING(f, "static ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "(TPNode p, int goalnt)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "(p, goalnt) TPNode p; int goalnt;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ int eruleno = TP_rule(STATE_LABEL(p), goalnt);\n");
	PTG_OUTPUT_STRING(f, "  short *nts = TP_nts[eruleno];\n");
	PTG_OUTPUT_STRING(f, "  TPNode kids[10];\n\n");
	PTG_OUTPUT_STRING(f, "  if (!eruleno) ReduceError(p, goalnt);\n");
	PTG_OUTPUT_STRING(f, "  TP_kids(p, eruleno, kids);\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "  switch (eruleno) {\n");
	PTG_OUTPUT_STRING(f, "  default: message(DEADLY,\"Invalid reduction\",");
	PTG_OUTPUT_INT(f, n->p4);
	PTG_OUTPUT_STRING(f, ",NoPosition);\n");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "  }\n");
	PTG_OUTPUT_STRING(f, "exit(1);\n");
	PTG_OUTPUT_STRING(f, "}\n\n");
}

#ifdef PROTO_OK
PTGNode PTGReducer(PTGNode p1, PTGNode p2, PTGNode p3, int p4)
#else
PTGNode PTGReducer(p1, p2, p3, p4)

PTGNode p1;
PTGNode p2;
PTGNode p3;
int p4;
#endif
{
	_PPTGReducer n;
	n = (_PPTGReducer)MALLOC(sizeof(struct _SPTGReducer));
	n->_print = (_PTGProc)_PrPTGReducer;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern Forward */

typedef struct _SPTGForward{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGForward;

#ifdef PROTO_OK
static void _PrPTGForward(_PPTGForward n)
#else
static void _PrPTGForward(n)
	_PPTGForward n;
#endif
{
	PTG_OUTPUT_STRING(f, "static ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " ELI_ARG((TPNode p, int goalnt));\n");
}

#ifdef PROTO_OK
PTGNode PTGForward(PTGNode p1, PTGNode p2)
#else
PTGNode PTGForward(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGForward n;
	n = (_PPTGForward)MALLOC(sizeof(struct _SPTGForward));
	n->_print = (_PTGProc)_PrPTGForward;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Case */

typedef struct _SPTGCase{
	_PTGProc _print;
	int p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGCase;

#ifdef PROTO_OK
static void _PrPTGCase(_PPTGCase n)
#else
static void _PrPTGCase(n)
	_PPTGCase n;
#endif
{
	PTG_OUTPUT_STRING(f, "  case ");
	PTG_OUTPUT_INT(f, n->p1);
	PTG_OUTPUT_STRING(f, ": return ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "(");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ");\n");
}

#ifdef PROTO_OK
PTGNode PTGCase(int p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGCase(p1, p2, p3)

int p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGCase n;
	n = (_PPTGCase)MALLOC(sizeof(struct _SPTGCase));
	n->_print = (_PTGProc)_PrPTGCase;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern ReducerCall */

typedef struct _SPTGReducerCall{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGReducerCall;

#ifdef PROTO_OK
static void _PrPTGReducerCall(_PPTGReducerCall n)
#else
static void _PrPTGReducerCall(n)
	_PPTGReducerCall n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(kids[");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, "],nts[");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, "])");
}

#ifdef PROTO_OK
PTGNode PTGReducerCall(PTGNode p1, int p2)
#else
PTGNode PTGReducerCall(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGReducerCall n;
	n = (_PPTGReducerCall)MALLOC(sizeof(struct _SPTGReducerCall));
	n->_print = (_PTGProc)_PrPTGReducerCall;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern GetValue */

typedef struct _SPTGGetValue{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGGetValue;

#ifdef PROTO_OK
static void _PrPTGGetValue(_PPTGGetValue n)
#else
static void _PrPTGGetValue(n)
	_PPTGGetValue n;
#endif
{
	PTG_OUTPUT_STRING(f, "((struct ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " *)p)->f_");
	PTG_OUTPUT_INT(f, n->p2);
}

#ifdef PROTO_OK
PTGNode PTGGetValue(PTGNode p1, int p2)
#else
PTGNode PTGGetValue(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGGetValue n;
	n = (_PPTGGetValue)MALLOC(sizeof(struct _SPTGGetValue));
	n->_print = (_PTGProc)_PrPTGGetValue;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Transform */

typedef struct _SPTGTransform{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGTransform;

#ifdef PROTO_OK
static void _PrPTGTransform(_PPTGTransform n)
#else
static void _PrPTGTransform(n)
	_PPTGTransform n;
#endif
{
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "TP_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(TPNode p)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "TP_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "(p) TPNode p;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{ return Reduce_");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "(p, TP_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_NT); }\n\n");
}

#ifdef PROTO_OK
PTGNode PTGTransform(PTGNode p1, PTGNode p2)
#else
PTGNode PTGTransform(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGTransform n;
	n = (_PPTGTransform)MALLOC(sizeof(struct _SPTGTransform));
	n->_print = (_PTGProc)_PrPTGTransform;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern TransformDecl */

typedef struct _SPTGTransformDecl{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGTransformDecl;

#ifdef PROTO_OK
static void _PrPTGTransformDecl(_PPTGTransformDecl n)
#else
static void _PrPTGTransformDecl(n)
	_PPTGTransformDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " TP_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ELI_ARG((TPNode));\n");
}

#ifdef PROTO_OK
PTGNode PTGTransformDecl(PTGNode p1, PTGNode p2)
#else
PTGNode PTGTransformDecl(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGTransformDecl n;
	n = (_PPTGTransformDecl)MALLOC(sizeof(struct _SPTGTransformDecl));
	n->_print = (_PTGProc)_PrPTGTransformDecl;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}

/* ============================ */

/* -------------------------------------------------------- */
/*                  Default Output Functions                */
/* -------------------------------------------------------- */


#ifdef PROTO_OK
void _PTGPrintInt(PTG_OUTPUT_FILE file, int param)
#else
void _PTGPrintInt(file, param)
       PTG_OUTPUT_FILE file; int param;
#endif
{    /* used for short and int */
       sprintf(buffer,"%d",param);
       PTG_OUTPUT_STRING(file,buffer);
}

#ifdef PROTO_OK
void _PTGPrintLong(PTG_OUTPUT_FILE file, long param)
#else
void _PTGPrintLong(file, param)
       PTG_OUTPUT_FILE file; long param;
#endif
{
       sprintf(buffer,"%ld",param);
       PTG_OUTPUT_STRING(file,buffer);
}

#ifdef PROTO_OK
void _PTGPrintDouble(PTG_OUTPUT_FILE file, double param)
#else
void _PTGPrintDouble(file, param)
       PTG_OUTPUT_FILE file; double param;
#endif
{    /* used for float and double */
       sprintf(buffer,"%g",param);
       PTG_OUTPUT_STRING(file,buffer);
}

#ifdef PROTO_OK
void _PTGPrintChar(PTG_OUTPUT_FILE file, char param)
#else
void _PTGPrintChar(file, param)
       PTG_OUTPUT_FILE file; char param;
#endif
{
       buffer[0] = param;
       buffer[1] = 0;
       PTG_OUTPUT_STRING(file,buffer);
}

