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

/* Implementation of Pattern file */

typedef struct _SPTGfile{
	_PTGProc _print;
	PTGNode p1;
	int p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
	int p7;
	PTGNode p8;
} * _PPTGfile;

#ifdef PROTO_OK
static void _PrPTGfile(_PPTGfile n)
#else
static void _PrPTGfile(n)
	_PPTGfile n;
#endif
{
	PTG_OUTPUT_STRING(f, "#include <stdio.h>\n");
	PTG_OUTPUT_STRING(f, "#include <stdlib.h>\n");
	PTG_OUTPUT_STRING(f, "#include <string.h>\n");
	PTG_OUTPUT_STRING(f, "#include \"clp.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"clpintf.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"pdl_gen.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"csm.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"eliproto.h\"\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#define TYPE_MASK      0x001F\n");
	PTG_OUTPUT_STRING(f, "#define BOOL           0x0001\n");
	PTG_OUTPUT_STRING(f, "#define INTVAL         0x0002\n");
	PTG_OUTPUT_STRING(f, "#define STRVAL         0x0004\n");
	PTG_OUTPUT_STRING(f, "#define USAGE          0x0008\n");
	PTG_OUTPUT_STRING(f, "#define TERM           0x0010\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#define JOINED         0x0100\n");
	PTG_OUTPUT_STRING(f, "#define SPACED         0x0200\n");
	PTG_OUTPUT_STRING(f, "#define PLURAL         0x0400\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "typedef struct opt opt;\n");
	PTG_OUTPUT_STRING(f, "struct opt {\n");
	PTG_OUTPUT_STRING(f, "    CONST char *str;\n");
	PTG_OUTPUT_STRING(f, "    int flags;\n");
	PTG_OUTPUT_STRING(f, "    int *count;\n");
	PTG_OUTPUT_STRING(f, "    DefTableKey *key;\n");
	PTG_OUTPUT_STRING(f, "    DefTableKeyList *list;\n");
	PTG_OUTPUT_STRING(f, "};\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "DefTableKey CLP_InputFile = NoKey;\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "static int error_count = 0;\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#define NUMOPTS ");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "static opt opts[] = {\n");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "    { \"dummy\", 0, NULL, NULL, NULL }\n");
	PTG_OUTPUT_STRING(f, "};\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "static void\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "clp_error (const char *str, const char *msg)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "clp_error (str, msg)\n");
	PTG_OUTPUT_STRING(f, "char *str, *msg;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	PTG_OUTPUT_STRING(f, "  if (str == (char *) NULL)\n");
	PTG_OUTPUT_STRING(f, "    fprintf (stderr, \"%s\\n\", msg);\n");
	PTG_OUTPUT_STRING(f, "  else\n");
	PTG_OUTPUT_STRING(f, "    fprintf (stderr, \"%s %s\\n\", str, msg);\n");
	PTG_OUTPUT_STRING(f, "  error_count++;\n");
	PTG_OUTPUT_STRING(f, "}\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "static int\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "clp_atos (char *str)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "clp_atos (str)\n");
	PTG_OUTPUT_STRING(f, "char *str;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	PTG_OUTPUT_STRING(f, "  return stostr (str, strlen(str));\n");
	PTG_OUTPUT_STRING(f, "}\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "void\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "clp_usage (char *prog)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "clp_usage (prog)\n");
	PTG_OUTPUT_STRING(f, "  char *prog;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"Usage: %s [options] parameters\\n\", prog);\n");
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"  Items marked with * may be repeated.\\n\");\n");
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"  Options:\\n\");\n");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"  Parameters:\\n\");\n");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "    exit (1);\n");
	PTG_OUTPUT_STRING(f, "}\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "void\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "clp_init (int argc, char *argv[])\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "clp_init (argc, argv)\n");
	PTG_OUTPUT_STRING(f, "int argc;\n");
	PTG_OUTPUT_STRING(f, "char *argv[];\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	PTG_OUTPUT_STRING(f, "  int i, j, p, t;\n");
	PTG_OUTPUT_STRING(f, "  DefTableKey k;\n");
	PTG_OUTPUT_STRING(f, "  opt *o;\n");
	PTG_OUTPUT_STRING(f, "  char *s;\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "  SetFileErr (\"");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, "\", ");
	PTG_OUTPUT_INT(f, n->p7);
	PTG_OUTPUT_STRING(f, ");\n");
	PTG_OUTPUT_STRING(f, "  for (i = 1; i < argc; i++) {\n");
	PTG_OUTPUT_STRING(f, "    for (j = 0, o = opts; j < NUMOPTS; j++, o++)\n");
	PTG_OUTPUT_STRING(f, "      if (strncmp (o->str, argv[i], strlen (o->str)) == 0)\n");
	PTG_OUTPUT_STRING(f, "        break;\n");
	PTG_OUTPUT_STRING(f, "    if (j == NUMOPTS)\n");
	PTG_OUTPUT_STRING(f, "      break;\n");
	PTG_OUTPUT_STRING(f, "    s = argv[i] + strlen (o->str);\n");
	PTG_OUTPUT_STRING(f, "    if (o->flags & USAGE) {\n");
	PTG_OUTPUT_STRING(f, "      if (*s != '\\0')\n");
	PTG_OUTPUT_STRING(f, "        clp_error (o->str, \"must not have a value\");\n");
	PTG_OUTPUT_STRING(f, "      clp_usage (argv[0]);\n");
	PTG_OUTPUT_STRING(f, "    } else if (o->flags & TERM) {\n");
	PTG_OUTPUT_STRING(f, "      if (*s != '\\0')\n");
	PTG_OUTPUT_STRING(f, "        clp_error (o->str, \"must not have a value\");\n");
	PTG_OUTPUT_STRING(f, "      i++;\n");
	PTG_OUTPUT_STRING(f, "      break;\n");
	PTG_OUTPUT_STRING(f, "    } else {\n");
	PTG_OUTPUT_STRING(f, "      if (o->count != (int *) NULL)\n");
	PTG_OUTPUT_STRING(f, "        (*o->count)++;\n");
	PTG_OUTPUT_STRING(f, "      p = o->flags & PLURAL;\n");
	PTG_OUTPUT_STRING(f, "      if ((!p) && (*o->count > 1))\n");
	PTG_OUTPUT_STRING(f, "        clp_error (o->str, \"can only be given once\");\n");
	PTG_OUTPUT_STRING(f, "      t = o->flags & TYPE_MASK;\n");
	PTG_OUTPUT_STRING(f, "      switch (t) {\n");
	PTG_OUTPUT_STRING(f, "        case BOOL:\n");
	PTG_OUTPUT_STRING(f, "          if (*s != '\\0')\n");
	PTG_OUTPUT_STRING(f, "            clp_error (o->str, \"must not have a value\");\n");
	PTG_OUTPUT_STRING(f, "          break;\n");
	PTG_OUTPUT_STRING(f, "        case INTVAL:\n");
	PTG_OUTPUT_STRING(f, "        case STRVAL: {\n");
	PTG_OUTPUT_STRING(f, "          if (o->flags & JOINED) {\n");
	PTG_OUTPUT_STRING(f, "            if (*s == '\\0') {\n");
	PTG_OUTPUT_STRING(f, "              if (o->flags & SPACED) {\n");
	PTG_OUTPUT_STRING(f, "                if (i == argc - 1) {\n");
	PTG_OUTPUT_STRING(f, "                  clp_error (o->str, \"must have a value\");\n");
	PTG_OUTPUT_STRING(f, "                  continue;\n");
	PTG_OUTPUT_STRING(f, "                } else {\n");
	PTG_OUTPUT_STRING(f, "                  i++;\n");
	PTG_OUTPUT_STRING(f, "                  s = argv[i];\n");
	PTG_OUTPUT_STRING(f, "                }\n");
	PTG_OUTPUT_STRING(f, "              } else {\n");
	PTG_OUTPUT_STRING(f, "                clp_error (o->str, \"must have a joined value\");\n");
	PTG_OUTPUT_STRING(f, "                continue;\n");
	PTG_OUTPUT_STRING(f, "              }\n");
	PTG_OUTPUT_STRING(f, "            }\n");
	PTG_OUTPUT_STRING(f, "          } else if (o->flags & SPACED) {\n");
	PTG_OUTPUT_STRING(f, "            if (*s != '\\0') {\n");
	PTG_OUTPUT_STRING(f, "              clp_error (o->str, \"must not have a joined value\");\n");
	PTG_OUTPUT_STRING(f, "              continue;\n");
	PTG_OUTPUT_STRING(f, "            }\n");
	PTG_OUTPUT_STRING(f, "            if (i == argc - 1) {\n");
	PTG_OUTPUT_STRING(f, "              clp_error (o->str, \"must have a value\");\n");
	PTG_OUTPUT_STRING(f, "              continue;\n");
	PTG_OUTPUT_STRING(f, "            } else {\n");
	PTG_OUTPUT_STRING(f, "              i++;\n");
	PTG_OUTPUT_STRING(f, "              s = argv[i];\n");
	PTG_OUTPUT_STRING(f, "            }\n");
	PTG_OUTPUT_STRING(f, "          }\n");
	PTG_OUTPUT_STRING(f, "          if (p) {\n");
	PTG_OUTPUT_STRING(f, "            DefTableKey k = NewKey ();\n");
	PTG_OUTPUT_STRING(f, "            switch (t) {\n");
	PTG_OUTPUT_STRING(f, "              case INTVAL:\n");
	PTG_OUTPUT_STRING(f, "                SetClpValue (k, atoi (s), 0);\n");
	PTG_OUTPUT_STRING(f, "                break;\n");
	PTG_OUTPUT_STRING(f, "              case STRVAL:\n");
	PTG_OUTPUT_STRING(f, "                SetClpValue (k, clp_atos (s), 0);\n");
	PTG_OUTPUT_STRING(f, "                break;\n");
	PTG_OUTPUT_STRING(f, "            }\n");
	PTG_OUTPUT_STRING(f, "            *o->list = AppElDefTableKeyList (*o->list, k);\n");
	PTG_OUTPUT_STRING(f, "          } else {\n");
	PTG_OUTPUT_STRING(f, "            *o->key = NewKey ();\n");
	PTG_OUTPUT_STRING(f, "            switch (t) {\n");
	PTG_OUTPUT_STRING(f, "              case INTVAL:\n");
	PTG_OUTPUT_STRING(f, "                SetClpValue (*o->key, atoi (s), 0);\n");
	PTG_OUTPUT_STRING(f, "                break;\n");
	PTG_OUTPUT_STRING(f, "              case STRVAL:\n");
	PTG_OUTPUT_STRING(f, "                SetClpValue (*o->key, clp_atos (s), 0);\n");
	PTG_OUTPUT_STRING(f, "                break;\n");
	PTG_OUTPUT_STRING(f, "            }\n");
	PTG_OUTPUT_STRING(f, "          }\n");
	PTG_OUTPUT_STRING(f, "        }\n");
	PTG_OUTPUT_STRING(f, "      }\n");
	PTG_OUTPUT_STRING(f, "    }\n");
	PTG_OUTPUT_STRING(f, "  }\n");
	n->p8->_print(n->p8);
	PTG_OUTPUT_STRING(f, "  if ((i < argc) || (error_count > 0))\n");
	PTG_OUTPUT_STRING(f, "    clp_usage (argv[0]);\n");
	PTG_OUTPUT_STRING(f, "}\n");
}

#ifdef PROTO_OK
PTGNode PTGfile(PTGNode p1, int p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, int p7, PTGNode p8)
#else
PTGNode PTGfile(p1, p2, p3, p4, p5, p6, p7, p8)

PTGNode p1;
int p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
int p7;
PTGNode p8;
#endif
{
	_PPTGfile n;
	n = (_PPTGfile)MALLOC(sizeof(struct _SPTGfile));
	n->_print = (_PTGProc)_PrPTGfile;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	n->p7 = p7;
	n->p8 = p8;
	return (PTGNode)n;
}


/* Implementation of Pattern kdecl */

typedef struct _SPTGkdecl{
	_PTGProc _print;
	int p1;
} * _PPTGkdecl;

#ifdef PROTO_OK
static void _PrPTGkdecl(_PPTGkdecl n)
#else
static void _PrPTGkdecl(n)
	_PPTGkdecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "DefTableKey ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, " = NoKey;\n");
}

#ifdef PROTO_OK
PTGNode PTGkdecl(int p1)
#else
PTGNode PTGkdecl(p1)

int p1;
#endif
{
	_PPTGkdecl n;
	n = (_PPTGkdecl)MALLOC(sizeof(struct _SPTGkdecl));
	n->_print = (_PTGProc)_PrPTGkdecl;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern kkdecl */

typedef struct _SPTGkkdecl{
	_PTGProc _print;
	int p1;
} * _PPTGkkdecl;

#ifdef PROTO_OK
static void _PrPTGkkdecl(_PPTGkkdecl n)
#else
static void _PrPTGkkdecl(n)
	_PPTGkkdecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "DefTableKeyList ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, " = NULLDefTableKeyList;\n");
}

#ifdef PROTO_OK
PTGNode PTGkkdecl(int p1)
#else
PTGNode PTGkkdecl(p1)

int p1;
#endif
{
	_PPTGkkdecl n;
	n = (_PPTGkkdecl)MALLOC(sizeof(struct _SPTGkkdecl));
	n->_print = (_PTGProc)_PrPTGkkdecl;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern bdecl */

typedef struct _SPTGbdecl{
	_PTGProc _print;
	int p1;
} * _PPTGbdecl;

#ifdef PROTO_OK
static void _PrPTGbdecl(_PPTGbdecl n)
#else
static void _PrPTGbdecl(n)
	_PPTGbdecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "int ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, " = 0;\n");
}

#ifdef PROTO_OK
PTGNode PTGbdecl(int p1)
#else
PTGNode PTGbdecl(p1)

int p1;
#endif
{
	_PPTGbdecl n;
	n = (_PPTGbdecl)MALLOC(sizeof(struct _SPTGbdecl));
	n->_print = (_PTGProc)_PrPTGbdecl;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern idecl */

typedef struct _SPTGidecl{
	_PTGProc _print;
	int p1;
} * _PPTGidecl;

#ifdef PROTO_OK
static void _PrPTGidecl(_PPTGidecl n)
#else
static void _PrPTGidecl(n)
	_PPTGidecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "static int ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, "_count = 0;\n");
}

#ifdef PROTO_OK
PTGNode PTGidecl(int p1)
#else
PTGNode PTGidecl(p1)

int p1;
#endif
{
	_PPTGidecl n;
	n = (_PPTGidecl)MALLOC(sizeof(struct _SPTGidecl));
	n->_print = (_PTGProc)_PrPTGidecl;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern topt */

typedef struct _SPTGtopt{
	_PTGProc _print;
	int p1;
} * _PPTGtopt;

#ifdef PROTO_OK
static void _PrPTGtopt(_PPTGtopt n)
#else
static void _PrPTGtopt(n)
	_PPTGtopt n;
#endif
{
	PTG_OUTPUT_STRING(f, "    { \"");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, "\", TERM, NULL, NULL, NULL },\n");
}

#ifdef PROTO_OK
PTGNode PTGtopt(int p1)
#else
PTGNode PTGtopt(p1)

int p1;
#endif
{
	_PPTGtopt n;
	n = (_PPTGtopt)MALLOC(sizeof(struct _SPTGtopt));
	n->_print = (_PTGProc)_PrPTGtopt;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern lit */

typedef struct _SPTGlit{
	_PTGProc _print;
	int p1;
} * _PPTGlit;

#ifdef PROTO_OK
static void _PrPTGlit(_PPTGlit n)
#else
static void _PrPTGlit(n)
	_PPTGlit n;
#endif
{
	PTG_OUTPUT_STRING(f, "    { \"");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, "\", ");
}

#ifdef PROTO_OK
PTGNode PTGlit(int p1)
#else
PTGNode PTGlit(p1)

int p1;
#endif
{
	_PPTGlit n;
	n = (_PPTGlit)MALLOC(sizeof(struct _SPTGlit));
	n->_print = (_PTGProc)_PrPTGlit;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern opt */

typedef struct _SPTGopt{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGopt;

#ifdef PROTO_OK
static void _PrPTGopt(_PPTGopt n)
#else
static void _PrPTGopt(n)
	_PPTGopt n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ", ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ", ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ", ");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, " },\n");
}

#ifdef PROTO_OK
PTGNode PTGopt(CONST char* p1, CONST char* p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGopt(p1, p2, p3, p4, p5)

CONST char* p1;
CONST char* p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGopt n;
	n = (_PPTGopt)MALLOC(sizeof(struct _SPTGopt));
	n->_print = (_PTGProc)_PrPTGopt;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern count */

typedef struct _SPTGcount{
	_PTGProc _print;
	int p1;
} * _PPTGcount;

#ifdef PROTO_OK
static void _PrPTGcount(_PPTGcount n)
#else
static void _PrPTGcount(n)
	_PPTGcount n;
#endif
{
	PTG_OUTPUT_STRING(f, "&");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, "_count");
}

#ifdef PROTO_OK
PTGNode PTGcount(int p1)
#else
PTGNode PTGcount(p1)

int p1;
#endif
{
	_PPTGcount n;
	n = (_PPTGcount)MALLOC(sizeof(struct _SPTGcount));
	n->_print = (_PTGProc)_PrPTGcount;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern var */

typedef struct _SPTGvar{
	_PTGProc _print;
	int p1;
} * _PPTGvar;

#ifdef PROTO_OK
static void _PrPTGvar(_PPTGvar n)
#else
static void _PrPTGvar(n)
	_PPTGvar n;
#endif
{
	PTG_OUTPUT_STRING(f, "&");
	OutStr(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGvar(int p1)
#else
PTGNode PTGvar(p1)

int p1;
#endif
{
	_PPTGvar n;
	n = (_PPTGvar)MALLOC(sizeof(struct _SPTGvar));
	n->_print = (_PTGProc)_PrPTGvar;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern none */

typedef struct _SPTGnone{
	_PTGProc _print;
} * _PPTGnone;

#ifdef PROTO_OK
static void _PrPTGnone(_PPTGnone n)
#else
static void _PrPTGnone(n)
	_PPTGnone n;
#endif
{
	PTG_OUTPUT_STRING(f, "NULL");
}

static struct _SPTGnone _sptgnone = { (_PTGProc) _PrPTGnone };

#ifdef PROTO_OK
PTGNode PTGnone(void)
#else
PTGNode PTGnone()
#endif
{
	return (PTGNode)(&_sptgnone);
}


/* Implementation of Pattern param */

typedef struct _SPTGparam{
	_PTGProc _print;
	int p1;
} * _PPTGparam;

#ifdef PROTO_OK
static void _PrPTGparam(_PPTGparam n)
#else
static void _PrPTGparam(n)
	_PPTGparam n;
#endif
{
	PTG_OUTPUT_STRING(f, "  if (i < argc) {\n");
	PTG_OUTPUT_STRING(f, "    ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, " = NewKey ();\n");
	PTG_OUTPUT_STRING(f, "    SetClpValue (");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ", clp_string (argv[i++]), 0);\n");
	PTG_OUTPUT_STRING(f, "  }\n");
}

#ifdef PROTO_OK
PTGNode PTGparam(int p1)
#else
PTGNode PTGparam(p1)

int p1;
#endif
{
	_PPTGparam n;
	n = (_PPTGparam)MALLOC(sizeof(struct _SPTGparam));
	n->_print = (_PTGProc)_PrPTGparam;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern mparam */

typedef struct _SPTGmparam{
	_PTGProc _print;
	int p1;
} * _PPTGmparam;

#ifdef PROTO_OK
static void _PrPTGmparam(_PPTGmparam n)
#else
static void _PrPTGmparam(n)
	_PPTGmparam n;
#endif
{
	PTG_OUTPUT_STRING(f, "  for (; i < argc; i++) {\n");
	PTG_OUTPUT_STRING(f, "    k = NewKey ();\n");
	PTG_OUTPUT_STRING(f, "    SetClpValue (k, clp_string (argv[i]), 0);\n");
	PTG_OUTPUT_STRING(f, "    ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, " = AppElDefTableKeyList (");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ", k);\n");
	PTG_OUTPUT_STRING(f, "  }\n");
}

#ifdef PROTO_OK
PTGNode PTGmparam(int p1)
#else
PTGNode PTGmparam(p1)

int p1;
#endif
{
	_PPTGmparam n;
	n = (_PPTGmparam)MALLOC(sizeof(struct _SPTGmparam));
	n->_print = (_PTGProc)_PrPTGmparam;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern input */

typedef struct _SPTGinput{
	_PTGProc _print;
	int p1;
} * _PPTGinput;

#ifdef PROTO_OK
static void _PrPTGinput(_PPTGinput n)
#else
static void _PrPTGinput(n)
	_PPTGinput n;
#endif
{
	PTG_OUTPUT_STRING(f, "  if (i < argc) {\n");
	PTG_OUTPUT_STRING(f, "    ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, " = NewKey ();\n");
	PTG_OUTPUT_STRING(f, "    SetClpValue (");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ", clp_string (argv[i++]), 0);\n");
	PTG_OUTPUT_STRING(f, "    CLP_InputFile = ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ";\n");
	PTG_OUTPUT_STRING(f, "  }\n");
}

#ifdef PROTO_OK
PTGNode PTGinput(int p1)
#else
PTGNode PTGinput(p1)

int p1;
#endif
{
	_PPTGinput n;
	n = (_PPTGinput)MALLOC(sizeof(struct _SPTGinput));
	n->_print = (_PTGProc)_PrPTGinput;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern use */

typedef struct _SPTGuse{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGuse;

#ifdef PROTO_OK
static void _PrPTGuse(_PPTGuse n)
#else
static void _PrPTGuse(n)
	_PPTGuse n;
#endif
{
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"    ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	OutStr(f, n->p2);
	PTG_OUTPUT_STRING(f, "\\n\");\n");
}

#ifdef PROTO_OK
PTGNode PTGuse(PTGNode p1, int p2)
#else
PTGNode PTGuse(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGuse n;
	n = (_PPTGuse)MALLOC(sizeof(struct _SPTGuse));
	n->_print = (_PTGProc)_PrPTGuse;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern uses */

typedef struct _SPTGuses{
	_PTGProc _print;
	PTGNode p1;
	int p2;
} * _PPTGuses;

#ifdef PROTO_OK
static void _PrPTGuses(_PPTGuses n)
#else
static void _PrPTGuses(n)
	_PPTGuses n;
#endif
{
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"    ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	OutStr(f, n->p2);
	PTG_OUTPUT_STRING(f, "*\\n\");\n");
}

#ifdef PROTO_OK
PTGNode PTGuses(PTGNode p1, int p2)
#else
PTGNode PTGuses(p1, p2)

PTGNode p1;
int p2;
#endif
{
	_PPTGuses n;
	n = (_PPTGuses)MALLOC(sizeof(struct _SPTGuses));
	n->_print = (_PTGProc)_PrPTGuses;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern tuse */

typedef struct _SPTGtuse{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGtuse;

#ifdef PROTO_OK
static void _PrPTGtuse(_PPTGtuse n)
#else
static void _PrPTGtuse(n)
	_PPTGtuse n;
#endif
{
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"    ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " Terminate options\\n\");\n");
}

#ifdef PROTO_OK
PTGNode PTGtuse(PTGNode p1)
#else
PTGNode PTGtuse(p1)

PTGNode p1;
#endif
{
	_PPTGtuse n;
	n = (_PPTGtuse)MALLOC(sizeof(struct _SPTGtuse));
	n->_print = (_PTGProc)_PrPTGtuse;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern vuse */

typedef struct _SPTGvuse{
	_PTGProc _print;
	int p1;
	CONST char* p2;
	CONST char* p3;
	int p4;
	PTGNode p5;
} * _PPTGvuse;

#ifdef PROTO_OK
static void _PrPTGvuse(_PPTGvuse n)
#else
static void _PrPTGvuse(n)
	_PPTGvuse n;
#endif
{
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"    ");
	OutPSStr(f, n->p1, n->p2, n->p3, n->p4);
	PTG_OUTPUT_STRING(f, " ");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ");\n");
}

#ifdef PROTO_OK
PTGNode PTGvuse(int p1, CONST char* p2, CONST char* p3, int p4, PTGNode p5)
#else
PTGNode PTGvuse(p1, p2, p3, p4, p5)

int p1;
CONST char* p2;
CONST char* p3;
int p4;
PTGNode p5;
#endif
{
	_PPTGvuse n;
	n = (_PPTGvuse)MALLOC(sizeof(struct _SPTGvuse));
	n->_print = (_PTGProc)_PrPTGvuse;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern uuse */

typedef struct _SPTGuuse{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGuuse;

#ifdef PROTO_OK
static void _PrPTGuuse(_PPTGuuse n)
#else
static void _PrPTGuuse(n)
	_PPTGuuse n;
#endif
{
	PTG_OUTPUT_STRING(f, "  fprintf (stderr, \"    ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " Display this usage message\\n\");\n");
}

#ifdef PROTO_OK
PTGNode PTGuuse(PTGNode p1)
#else
PTGNode PTGuuse(p1)

PTGNode p1;
#endif
{
	_PPTGuuse n;
	n = (_PPTGuuse)MALLOC(sizeof(struct _SPTGuuse));
	n->_print = (_PTGProc)_PrPTGuuse;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern msg */

typedef struct _SPTGmsg{
	_PTGProc _print;
	int p1;
	CONST char* p2;
} * _PPTGmsg;

#ifdef PROTO_OK
static void _PrPTGmsg(_PPTGmsg n)
#else
static void _PrPTGmsg(n)
	_PPTGmsg n;
#endif
{
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "\\n\"");
}

#ifdef PROTO_OK
PTGNode PTGmsg(int p1, CONST char* p2)
#else
PTGNode PTGmsg(p1, p2)

int p1;
CONST char* p2;
#endif
{
	_PPTGmsg n;
	n = (_PPTGmsg)MALLOC(sizeof(struct _SPTGmsg));
	n->_print = (_PTGProc)_PrPTGmsg;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern header */

typedef struct _SPTGheader{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGheader;

#ifdef PROTO_OK
static void _PrPTGheader(_PPTGheader n)
#else
static void _PrPTGheader(n)
	_PPTGheader n;
#endif
{
	PTG_OUTPUT_STRING(f, "#ifndef CLP_H\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#define CLP_H\n");
	PTG_OUTPUT_STRING(f, "#include \"clplib.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"pdl_gen.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"DefTableKeyList.h\"\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "extern DefTableKey CLP_InputFile;\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "extern void clp_usage (char *);\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "extern void clp_usage ();\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGheader(PTGNode p1)
#else
PTGNode PTGheader(p1)

PTGNode p1;
#endif
{
	_PPTGheader n;
	n = (_PPTGheader)MALLOC(sizeof(struct _SPTGheader));
	n->_print = (_PTGProc)_PrPTGheader;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern kextern */

typedef struct _SPTGkextern{
	_PTGProc _print;
	int p1;
} * _PPTGkextern;

#ifdef PROTO_OK
static void _PrPTGkextern(_PPTGkextern n)
#else
static void _PrPTGkextern(n)
	_PPTGkextern n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern DefTableKey ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGkextern(int p1)
#else
PTGNode PTGkextern(p1)

int p1;
#endif
{
	_PPTGkextern n;
	n = (_PPTGkextern)MALLOC(sizeof(struct _SPTGkextern));
	n->_print = (_PTGProc)_PrPTGkextern;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern kkextern */

typedef struct _SPTGkkextern{
	_PTGProc _print;
	int p1;
} * _PPTGkkextern;

#ifdef PROTO_OK
static void _PrPTGkkextern(_PPTGkkextern n)
#else
static void _PrPTGkkextern(n)
	_PPTGkkextern n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern DefTableKeyList ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGkkextern(int p1)
#else
PTGNode PTGkkextern(p1)

int p1;
#endif
{
	_PPTGkkextern n;
	n = (_PPTGkkextern)MALLOC(sizeof(struct _SPTGkkextern));
	n->_print = (_PTGProc)_PrPTGkkextern;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern iextern */

typedef struct _SPTGiextern{
	_PTGProc _print;
	int p1;
} * _PPTGiextern;

#ifdef PROTO_OK
static void _PrPTGiextern(_PPTGiextern n)
#else
static void _PrPTGiextern(n)
	_PPTGiextern n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern int ");
	OutStr(f, n->p1);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGiextern(int p1)
#else
PTGNode PTGiextern(p1)

int p1;
#endif
{
	_PPTGiextern n;
	n = (_PPTGiextern)MALLOC(sizeof(struct _SPTGiextern));
	n->_print = (_PTGProc)_PrPTGiextern;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern seq */

typedef struct _SPTGseq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGseq;

#ifdef PROTO_OK
static void _PrPTGseq(_PPTGseq n)
#else
static void _PrPTGseq(n)
	_PPTGseq n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGseq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGseq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGseq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGseq)MALLOC(sizeof(struct _SPTGseq));
	n->_print = (_PTGProc)_PrPTGseq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern seq3 */

typedef struct _SPTGseq3{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGseq3;

#ifdef PROTO_OK
static void _PrPTGseq3(_PPTGseq3 n)
#else
static void _PrPTGseq3(n)
	_PPTGseq3 n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGseq3(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGseq3(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGseq3 n;
	if(p1 == PTGNULL && p2 == PTGNULL && p3 == PTGNULL)
		return PTGNULL;
	n = (_PPTGseq3)MALLOC(sizeof(struct _SPTGseq3));
	n->_print = (_PTGProc)_PrPTGseq3;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern cstr */

typedef struct _SPTGcstr{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGcstr;

#ifdef PROTO_OK
static void _PrPTGcstr(_PPTGcstr n)
#else
static void _PrPTGcstr(n)
	_PPTGcstr n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGcstr(CONST char* p1)
#else
PTGNode PTGcstr(p1)

CONST char* p1;
#endif
{
	_PPTGcstr n;
	n = (_PPTGcstr)MALLOC(sizeof(struct _SPTGcstr));
	n->_print = (_PTGProc)_PrPTGcstr;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern str */

typedef struct _SPTGstr{
	_PTGProc _print;
	int p1;
} * _PPTGstr;

#ifdef PROTO_OK
static void _PrPTGstr(_PPTGstr n)
#else
static void _PrPTGstr(n)
	_PPTGstr n;
#endif
{
	OutStr(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGstr(int p1)
#else
PTGNode PTGstr(p1)

int p1;
#endif
{
	_PPTGstr n;
	n = (_PPTGstr)MALLOC(sizeof(struct _SPTGstr));
	n->_print = (_PTGProc)_PrPTGstr;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern pstr */

typedef struct _SPTGpstr{
	_PTGProc _print;
	int p1;
	int p2;
} * _PPTGpstr;

#ifdef PROTO_OK
static void _PrPTGpstr(_PPTGpstr n)
#else
static void _PrPTGpstr(n)
	_PPTGpstr n;
#endif
{
	OutPStr(f, n->p1, n->p2);
}

#ifdef PROTO_OK
PTGNode PTGpstr(int p1, int p2)
#else
PTGNode PTGpstr(p1, p2)

int p1;
int p2;
#endif
{
	_PPTGpstr n;
	n = (_PPTGpstr)MALLOC(sizeof(struct _SPTGpstr));
	n->_print = (_PTGProc)_PrPTGpstr;
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

