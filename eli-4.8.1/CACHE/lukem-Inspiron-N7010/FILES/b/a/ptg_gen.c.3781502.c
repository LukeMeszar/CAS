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


/* Implementation of Pattern db */

typedef struct _SPTGdb{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGdb;

#ifdef PROTO_OK
static void _PrPTGdb(_PPTGdb n)
#else
static void _PrPTGdb(n)
	_PPTGdb n;
#endif
{
	PTG_OUTPUT_STRING(f, "# Automatically generated by dapto: DO NOT EDIT\n");
	PTG_OUTPUT_STRING(f, "\n");
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGdb(PTGNode p1, PTGNode p2)
#else
PTGNode PTGdb(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGdb n;
	n = (_PPTGdb)MALLOC(sizeof(struct _SPTGdb));
	n->_print = (_PTGProc)_PrPTGdb;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern aspectdb */

typedef struct _SPTGaspectdb{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGaspectdb;

#ifdef PROTO_OK
static void _PrPTGaspectdb(_PPTGaspectdb n)
#else
static void _PrPTGaspectdb(n)
	_PPTGaspectdb n;
#endif
{
	PTG_OUTPUT_STRING(f, "new_aspect ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGaspectdb(CONST char* p1)
#else
PTGNode PTGaspectdb(p1)

CONST char* p1;
#endif
{
	_PPTGaspectdb n;
	n = (_PPTGaspectdb)MALLOC(sizeof(struct _SPTGaspectdb));
	n->_print = (_PTGProc)_PrPTGaspectdb;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern eventdb */

typedef struct _SPTGeventdb{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
} * _PPTGeventdb;

#ifdef PROTO_OK
static void _PrPTGeventdb(_PPTGeventdb n)
#else
static void _PrPTGeventdb(n)
	_PPTGeventdb n;
#endif
{
	PTG_OUTPUT_STRING(f, "new_event [list ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " {");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "} ");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "]\n");
}

#ifdef PROTO_OK
PTGNode PTGeventdb(CONST char* p1, PTGNode p2, PTGNode p3, PTGNode p4)
#else
PTGNode PTGeventdb(p1, p2, p3, p4)

CONST char* p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
#endif
{
	_PPTGeventdb n;
	n = (_PPTGeventdb)MALLOC(sizeof(struct _SPTGeventdb));
	n->_print = (_PTGProc)_PrPTGeventdb;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern cfile */

typedef struct _SPTGcfile{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGcfile;

#ifdef PROTO_OK
static void _PrPTGcfile(_PPTGcfile n)
#else
static void _PrPTGcfile(n)
	_PPTGcfile n;
#endif
{
	PTG_OUTPUT_STRING(f, "/* Automatically generated by dapto: DO NOT EDIT */\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#ifdef MONITOR\n");
	PTG_OUTPUT_STRING(f, "#include <stdio.h>\n");
	PTG_OUTPUT_STRING(f, "#include <time.h>\n");
	PTG_OUTPUT_STRING(f, "#include <string.h>\n");
	PTG_OUTPUT_STRING(f, "#include \"");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_dapto.h\"\n");
	PTG_OUTPUT_STRING(f, "\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "void _dap_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_init ()\n");
	PTG_OUTPUT_STRING(f, "{\n");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "}\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "static int _dapto; /* To avoid messages about empty files. */\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGcfile(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGcfile(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGcfile n;
	n = (_PPTGcfile)MALLOC(sizeof(struct _SPTGcfile));
	n->_print = (_PTGProc)_PrPTGcfile;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern hfile */

typedef struct _SPTGhfile{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGhfile;

#ifdef PROTO_OK
static void _PrPTGhfile(_PPTGhfile n)
#else
static void _PrPTGhfile(n)
	_PPTGhfile n;
#endif
{
	PTG_OUTPUT_STRING(f, "/* Automatically generated by dapto: DO NOT EDIT */\n");
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#ifndef ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_DAPTO_H\n");
	PTG_OUTPUT_STRING(f, "#define ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_DAPTO_H\n");
	PTG_OUTPUT_STRING(f, "#include \"dapto.h\"\n");
	PTG_OUTPUT_STRING(f, "#include \"eliproto.h\"\n");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "extern void _dap_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "_init ();\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGhfile(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGhfile(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGhfile n;
	n = (_PPTGhfile)MALLOC(sizeof(struct _SPTGhfile));
	n->_print = (_PTGProc)_PrPTGhfile;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern incl */

typedef struct _SPTGincl{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGincl;

#ifdef PROTO_OK
static void _PrPTGincl(_PPTGincl n)
#else
static void _PrPTGincl(n)
	_PPTGincl n;
#endif
{
	PTG_OUTPUT_STRING(f, "#include ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGincl(PTGNode p1)
#else
PTGNode PTGincl(p1)

PTGNode p1;
#endif
{
	_PPTGincl n;
	n = (_PPTGincl)MALLOC(sizeof(struct _SPTGincl));
	n->_print = (_PTGProc)_PrPTGincl;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern entry */

typedef struct _SPTGentry{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGentry;

#ifdef PROTO_OK
static void _PrPTGentry(_PPTGentry n)
#else
static void _PrPTGentry(n)
	_PPTGentry n;
#endif
{
	PTG_OUTPUT_STRING(f, "    _dap_add_command (\"");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "\", ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Cmd );\n");
}

#ifdef PROTO_OK
PTGNode PTGentry(CONST char* p1)
#else
PTGNode PTGentry(p1)

CONST char* p1;
#endif
{
	_PPTGentry n;
	n = (_PPTGentry)MALLOC(sizeof(struct _SPTGentry));
	n->_print = (_PTGProc)_PrPTGentry;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern cmdfunc */

typedef struct _SPTGcmdfunc{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	int p5;
	CONST char* p6;
} * _PPTGcmdfunc;

#ifdef PROTO_OK
static void _PrPTGcmdfunc(_PPTGcmdfunc n)
#else
static void _PrPTGcmdfunc(n)
	_PPTGcmdfunc n;
#endif
{
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "void ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Cmd (char *args)\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "void ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Cmd (args)\n");
	PTG_OUTPUT_STRING(f, "    char *args;\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "    DAPTO_ARG_INIT_OP;\n");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, "    DAPTO_INIT_OP;\n");
	PTG_OUTPUT_STRING(f, "/* #line ");
	PTG_OUTPUT_INT(f, n->p5);
	PTG_OUTPUT_STRING(f, " \"");
	PTG_OUTPUT_STRING(f, n->p6);
	PTG_OUTPUT_STRING(f, "\" */\n");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "\n    DAPTO_RESULT_SEND (1);\n");
	PTG_OUTPUT_STRING(f, "}\n");
}

#ifdef PROTO_OK
PTGNode PTGcmdfunc(CONST char* p1, PTGNode p2, PTGNode p3, PTGNode p4, int p5, CONST char* p6)
#else
PTGNode PTGcmdfunc(p1, p2, p3, p4, p5, p6)

CONST char* p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
int p5;
CONST char* p6;
#endif
{
	_PPTGcmdfunc n;
	n = (_PPTGcmdfunc)MALLOC(sizeof(struct _SPTGcmdfunc));
	n->_print = (_PTGProc)_PrPTGcmdfunc;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern arg */

typedef struct _SPTGarg{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGarg;

#ifdef PROTO_OK
static void _PrPTGarg(_PPTGarg n)
#else
static void _PrPTGarg(n)
	_PPTGarg n;
#endif
{
	PTG_OUTPUT_STRING(f, "    DAPTO_ARG");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " (&");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ");\n");
}

#ifdef PROTO_OK
PTGNode PTGarg(CONST char* p1, CONST char* p2)
#else
PTGNode PTGarg(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGarg n;
	n = (_PPTGarg)MALLOC(sizeof(struct _SPTGarg));
	n->_print = (_PTGProc)_PrPTGarg;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern efunc */

typedef struct _SPTGefunc{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
	PTGNode p6;
} * _PPTGefunc;

#ifdef PROTO_OK
static void _PrPTGefunc(_PPTGefunc n)
#else
static void _PrPTGefunc(n)
	_PPTGefunc n;
#endif
{
	PTG_OUTPUT_STRING(f, "\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "void _dapto_");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, " (");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "void _dapto_");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, " (");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ")\n");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "#endif\n");
	PTG_OUTPUT_STRING(f, "{\n");
	PTG_OUTPUT_STRING(f, "    DAPTO_INIT_EV;\n");
	PTG_OUTPUT_STRING(f, "    DAPTO_RESULT_STR (\"");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "\");\n");
	PTG_OUTPUT_STRING(f, "    DAPTO_RESULT_LONGVAL (clock ());\n");
	n->p6->_print(n->p6);
	PTG_OUTPUT_STRING(f, "    DAPTO_RESULT_SEND (0);\n");
	PTG_OUTPUT_STRING(f, "}\n");
}

#ifdef PROTO_OK
PTGNode PTGefunc(PTGNode p1, CONST char* p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6)
#else
PTGNode PTGefunc(p1, p2, p3, p4, p5, p6)

PTGNode p1;
CONST char* p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
PTGNode p6;
#endif
{
	_PPTGefunc n;
	n = (_PPTGefunc)MALLOC(sizeof(struct _SPTGefunc));
	n->_print = (_PTGProc)_PrPTGefunc;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	n->p6 = p6;
	return (PTGNode)n;
}


/* Implementation of Pattern sig */

typedef struct _SPTGsig{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
} * _PPTGsig;

#ifdef PROTO_OK
static void _PrPTGsig(_PPTGsig n)
#else
static void _PrPTGsig(n)
	_PPTGsig n;
#endif
{
	PTG_OUTPUT_STRING(f, "#ifdef PROTO_OK\n");
	PTG_OUTPUT_STRING(f, "extern void _dapto_");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " (");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ");\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "extern void _dapto_");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " ();\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGsig(CONST char* p1, PTGNode p2)
#else
PTGNode PTGsig(p1, p2)

CONST char* p1;
PTGNode p2;
#endif
{
	_PPTGsig n;
	n = (_PPTGsig)MALLOC(sizeof(struct _SPTGsig));
	n->_print = (_PTGProc)_PrPTGsig;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern send */

typedef struct _SPTGsend{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGsend;

#ifdef PROTO_OK
static void _PrPTGsend(_PPTGsend n)
#else
static void _PrPTGsend(n)
	_PPTGsend n;
#endif
{
	PTG_OUTPUT_STRING(f, "#ifdef DAPTO_RESULT");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "\n");
	PTG_OUTPUT_STRING(f, "    DAPTO_RESULT");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " (");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ");\n");
	PTG_OUTPUT_STRING(f, "#else\n");
	PTG_OUTPUT_STRING(f, "    DAPTO_RESULT_OTHER (");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ");\n");
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGsend(CONST char* p1, CONST char* p2)
#else
PTGNode PTGsend(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGsend n;
	n = (_PPTGsend)MALLOC(sizeof(struct _SPTGsend));
	n->_print = (_PTGProc)_PrPTGsend;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern translation */

typedef struct _SPTGtranslation{
	_PTGProc _print;
	CONST char* p1;
	int p2;
	CONST char* p3;
	PTGNode p4;
} * _PPTGtranslation;

#ifdef PROTO_OK
static void _PrPTGtranslation(_PPTGtranslation n)
#else
static void _PrPTGtranslation(n)
	_PPTGtranslation n;
#endif
{
	PTG_OUTPUT_STRING(f, "     if (");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "#line ");
	PTG_OUTPUT_INT(f, n->p2);
	PTG_OUTPUT_STRING(f, " \"");
	PTG_OUTPUT_STRING(f, n->p3);
	PTG_OUTPUT_STRING(f, "\"\n");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGtranslation(CONST char* p1, int p2, CONST char* p3, PTGNode p4)
#else
PTGNode PTGtranslation(p1, p2, p3, p4)

CONST char* p1;
int p2;
CONST char* p3;
PTGNode p4;
#endif
{
	_PPTGtranslation n;
	n = (_PPTGtranslation)MALLOC(sizeof(struct _SPTGtranslation));
	n->_print = (_PTGProc)_PrPTGtranslation;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	return (PTGNode)n;
}


/* Implementation of Pattern translationvar */

typedef struct _SPTGtranslationvar{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGtranslationvar;

#ifdef PROTO_OK
static void _PrPTGtranslationvar(_PPTGtranslationvar n)
#else
static void _PrPTGtranslationvar(n)
	_PPTGtranslationvar n;
#endif
{
	PTG_OUTPUT_STRING(f, "int ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " = 1;\n");
}

#ifdef PROTO_OK
PTGNode PTGtranslationvar(CONST char* p1)
#else
PTGNode PTGtranslationvar(p1)

CONST char* p1;
#endif
{
	_PPTGtranslationvar n;
	n = (_PPTGtranslationvar)MALLOC(sizeof(struct _SPTGtranslationvar));
	n->_print = (_PTGProc)_PrPTGtranslationvar;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern SSeq */

typedef struct _SPTGSSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSSeq;

#ifdef PROTO_OK
static void _PrPTGSSeq(_PPTGSSeq n)
#else
static void _PrPTGSSeq(n)
	_PPTGSSeq n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSSeq n;
	n = (_PPTGSSeq)MALLOC(sizeof(struct _SPTGSSeq));
	n->_print = (_PTGProc)_PrPTGSSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern SSeq3 */

typedef struct _SPTGSSeq3{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
	PTGNode p3;
} * _PPTGSSeq3;

#ifdef PROTO_OK
static void _PrPTGSSeq3(_PPTGSSeq3 n)
#else
static void _PrPTGSSeq3(n)
	_PPTGSSeq3 n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, " ");
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGSSeq3(PTGNode p1, CONST char* p2, PTGNode p3)
#else
PTGNode PTGSSeq3(p1, p2, p3)

PTGNode p1;
CONST char* p2;
PTGNode p3;
#endif
{
	_PPTGSSeq3 n;
	n = (_PPTGSSeq3)MALLOC(sizeof(struct _SPTGSSeq3));
	n->_print = (_PTGProc)_PrPTGSSeq3;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern DeclSeq */

typedef struct _SPTGDeclSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGDeclSeq;

#ifdef PROTO_OK
static void _PrPTGDeclSeq(_PPTGDeclSeq n)
#else
static void _PrPTGDeclSeq(n)
	_PPTGDeclSeq n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "    ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGDeclSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGDeclSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGDeclSeq n;
	n = (_PPTGDeclSeq)MALLOC(sizeof(struct _SPTGDeclSeq));
	n->_print = (_PTGProc)_PrPTGDeclSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Protect */

typedef struct _SPTGProtect{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGProtect;

#ifdef PROTO_OK
static void _PrPTGProtect(_PPTGProtect n)
#else
static void _PrPTGProtect(n)
	_PPTGProtect n;
#endif
{
	PTG_OUTPUT_STRING(f, "_");
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGProtect(PTGNode p1)
#else
PTGNode PTGProtect(p1)

PTGNode p1;
#endif
{
	_PPTGProtect n;
	n = (_PPTGProtect)MALLOC(sizeof(struct _SPTGProtect));
	n->_print = (_PTGProc)_PrPTGProtect;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern NSeq */

typedef struct _SPTGNSeq{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
	CONST char* p3;
} * _PPTGNSeq;

#ifdef PROTO_OK
static void _PrPTGNSeq(_PPTGNSeq n)
#else
static void _PrPTGNSeq(n)
	_PPTGNSeq n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ", ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, n->p3);
}

#ifdef PROTO_OK
PTGNode PTGNSeq(PTGNode p1, CONST char* p2, CONST char* p3)
#else
PTGNode PTGNSeq(p1, p2, p3)

PTGNode p1;
CONST char* p2;
CONST char* p3;
#endif
{
	_PPTGNSeq n;
	n = (_PPTGNSeq)MALLOC(sizeof(struct _SPTGNSeq));
	n->_print = (_PTGProc)_PrPTGNSeq;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern Decl */

typedef struct _SPTGDecl{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGDecl;

#ifdef PROTO_OK
static void _PrPTGDecl(_PPTGDecl n)
#else
static void _PrPTGDecl(n)
	_PPTGDecl n;
#endif
{
	PTG_OUTPUT_STRING(f, "   ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGDecl(CONST char* p1, CONST char* p2)
#else
PTGNode PTGDecl(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGDecl n;
	n = (_PPTGDecl)MALLOC(sizeof(struct _SPTGDecl));
	n->_print = (_PTGProc)_PrPTGDecl;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern reqsyms */

typedef struct _SPTGreqsyms{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGreqsyms;

#ifdef PROTO_OK
static void _PrPTGreqsyms(_PPTGreqsyms n)
#else
static void _PrPTGreqsyms(n)
	_PPTGreqsyms n;
#endif
{
	PTG_OUTPUT_STRING(f, "/* Automatically generated by dapto: DO NOT EDIT */\n");
	PTG_OUTPUT_STRING(f, "\n");
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGreqsyms(PTGNode p1)
#else
PTGNode PTGreqsyms(p1)

PTGNode p1;
#endif
{
	_PPTGreqsyms n;
	n = (_PPTGreqsyms)MALLOC(sizeof(struct _SPTGreqsyms));
	n->_print = (_PTGProc)_PrPTGreqsyms;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern reqsym */

typedef struct _SPTGreqsym{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGreqsym;

#ifdef PROTO_OK
static void _PrPTGreqsym(_PPTGreqsym n)
#else
static void _PrPTGreqsym(n)
	_PPTGreqsym n;
#endif
{
	PTG_OUTPUT_STRING(f, "{ extern void ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Cmd (); ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Cmd (); }\n");
}

#ifdef PROTO_OK
PTGNode PTGreqsym(CONST char* p1)
#else
PTGNode PTGreqsym(p1)

CONST char* p1;
#endif
{
	_PPTGreqsym n;
	n = (_PPTGreqsym)MALLOC(sizeof(struct _SPTGreqsym));
	n->_print = (_PTGProc)_PrPTGreqsym;
	n->p1 = p1;
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

