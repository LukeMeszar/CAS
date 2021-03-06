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


/* Implementation of Pattern Attr */

typedef struct _SPTGAttr{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
} * _PPTGAttr;

#ifdef PROTO_OK
static void _PrPTGAttr(_PPTGAttr n)
#else
static void _PrPTGAttr(n)
	_PPTGAttr n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ".");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "Ptg");
}

#ifdef PROTO_OK
PTGNode PTGAttr(PTGNode p1, CONST char* p2)
#else
PTGNode PTGAttr(p1, p2)

PTGNode p1;
CONST char* p2;
#endif
{
	_PPTGAttr n;
	n = (_PPTGAttr)MALLOC(sizeof(struct _SPTGAttr));
	n->_print = (_PTGProc)_PrPTGAttr;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Marker */

typedef struct _SPTGMarker{
	_PTGProc _print;
	int p1;
} * _PPTGMarker;

#ifdef PROTO_OK
static void _PrPTGMarker(_PPTGMarker n)
#else
static void _PrPTGMarker(n)
	_PPTGMarker n;
#endif
{
	PTG_OUTPUT_STRING(f, "$");
	PTG_OUTPUT_INT(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGMarker(int p1)
#else
PTGNode PTGMarker(p1)

int p1;
#endif
{
	_PPTGMarker n;
	n = (_PPTGMarker)MALLOC(sizeof(struct _SPTGMarker));
	n->_print = (_PTGProc)_PrPTGMarker;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern PlainRules */

typedef struct _SPTGPlainRules{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGPlainRules;

#ifdef PROTO_OK
static void _PrPTGPlainRules(_PPTGPlainRules n)
#else
static void _PrPTGPlainRules(n)
	_PPTGPlainRules n;
#endif
{
	PTG_OUTPUT_STRING(f, "CLASS SYMBOL ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Reproduce COMPUTE\n");
	PTG_OUTPUT_STRING(f, "  SYNT.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "OrigPtg=\n");
	PTG_OUTPUT_STRING(f, "    RuleFct(\"PTG");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_\", RHS.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg, TermFct(\"PTG");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_\"));\n");
	PTG_OUTPUT_STRING(f, "  SYNT.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg=THIS.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "OrigPtg;\n");
	PTG_OUTPUT_STRING(f, "END;\n\n");
	PTG_OUTPUT_STRING(f, "CLASS SYMBOL ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "NoReproduce COMPUTE\n");
	PTG_OUTPUT_STRING(f, "  SYNT.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg = PTGNULL;\n");
	PTG_OUTPUT_STRING(f, "END;\n\n");
}

#ifdef PROTO_OK
PTGNode PTGPlainRules(CONST char* p1)
#else
PTGNode PTGPlainRules(p1)

CONST char* p1;
#endif
{
	_PPTGPlainRules n;
	n = (_PPTGPlainRules)MALLOC(sizeof(struct _SPTGPlainRules));
	n->_print = (_PTGProc)_PrPTGPlainRules;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ListofRule */

typedef struct _SPTGListofRule{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGListofRule;

#ifdef PROTO_OK
static void _PrPTGListofRule(_PPTGListofRule n)
#else
static void _PrPTGListofRule(n)
	_PPTGListofRule n;
#endif
{
	PTG_OUTPUT_STRING(f, "CLASS SYMBOL ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Reproduce_");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " COMPUTE\n");
	PTG_OUTPUT_STRING(f, "  SYNT.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "OrigPtg=\n");
	PTG_OUTPUT_STRING(f, "    PTG");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "(\n");
	PTG_OUTPUT_STRING(f, "      CONSTITUENTS (");
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "      SHIELD (");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, ")\n");
	PTG_OUTPUT_STRING(f, "      WITH (PTGNode, PTG");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_2");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ", PTG");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_1");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ", PTGNull));\n");
	PTG_OUTPUT_STRING(f, "  SYNT.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg=THIS.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "OrigPtg;\n");
	PTG_OUTPUT_STRING(f, "END;\n\n");
}

#ifdef PROTO_OK
PTGNode PTGListofRule(CONST char* p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGListofRule(p1, p2, p3, p4, p5)

CONST char* p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGListofRule n;
	n = (_PPTGListofRule)MALLOC(sizeof(struct _SPTGListofRule));
	n->_print = (_PTGProc)_PrPTGListofRule;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern NontComp */

typedef struct _SPTGNontComp{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
} * _PPTGNontComp;

#ifdef PROTO_OK
static void _PrPTGNontComp(_PPTGNontComp n)
#else
static void _PrPTGNontComp(n)
	_PPTGNontComp n;
#endif
{
	PTG_OUTPUT_STRING(f, "SYMBOL ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " INHERITS ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "Reproduce END;\n");
}

#ifdef PROTO_OK
PTGNode PTGNontComp(PTGNode p1, CONST char* p2)
#else
PTGNode PTGNontComp(p1, p2)

PTGNode p1;
CONST char* p2;
#endif
{
	_PPTGNontComp n;
	n = (_PPTGNontComp)MALLOC(sizeof(struct _SPTGNontComp));
	n->_print = (_PTGProc)_PrPTGNontComp;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ListComp */

typedef struct _SPTGListComp{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
} * _PPTGListComp;

#ifdef PROTO_OK
static void _PrPTGListComp(_PPTGListComp n)
#else
static void _PrPTGListComp(n)
	_PPTGListComp n;
#endif
{
	PTG_OUTPUT_STRING(f, "SYMBOL ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " INHERITS ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "Reproduce_");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " END;\n");
}

#ifdef PROTO_OK
PTGNode PTGListComp(PTGNode p1, CONST char* p2)
#else
PTGNode PTGListComp(p1, p2)

PTGNode p1;
CONST char* p2;
#endif
{
	_PPTGListComp n;
	n = (_PPTGListComp)MALLOC(sizeof(struct _SPTGListComp));
	n->_print = (_PTGProc)_PrPTGListComp;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern NontNoComp */

typedef struct _SPTGNontNoComp{
	_PTGProc _print;
	PTGNode p1;
	CONST char* p2;
} * _PPTGNontNoComp;

#ifdef PROTO_OK
static void _PrPTGNontNoComp(_PPTGNontNoComp n)
#else
static void _PrPTGNontNoComp(n)
	_PPTGNontNoComp n;
#endif
{
	PTG_OUTPUT_STRING(f, "SYMBOL ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " INHERITS ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "NoReproduce END;\n");
}

#ifdef PROTO_OK
PTGNode PTGNontNoComp(PTGNode p1, CONST char* p2)
#else
PTGNode PTGNontNoComp(p1, p2)

PTGNode p1;
CONST char* p2;
#endif
{
	_PPTGNontNoComp n;
	n = (_PPTGNontNoComp)MALLOC(sizeof(struct _SPTGNontNoComp));
	n->_print = (_PTGProc)_PrPTGNontNoComp;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Axiom */

typedef struct _SPTGAxiom{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGAxiom;

#ifdef PROTO_OK
static void _PrPTGAxiom(_PPTGAxiom n)
#else
static void _PrPTGAxiom(n)
	_PPTGAxiom n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ":\n  ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
}

#ifdef PROTO_OK
PTGNode PTGAxiom(PTGNode p1, PTGNode p2)
#else
PTGNode PTGAxiom(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGAxiom n;
	n = (_PPTGAxiom)MALLOC(sizeof(struct _SPTGAxiom));
	n->_print = (_PTGProc)_PrPTGAxiom;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Index */

typedef struct _SPTGIndex{
	_PTGProc _print;
	int p1;
} * _PPTGIndex;

#ifdef PROTO_OK
static void _PrPTGIndex(_PPTGIndex n)
#else
static void _PrPTGIndex(n)
	_PPTGIndex n;
#endif
{
	PTG_OUTPUT_STRING(f, "$");
	PTG_OUTPUT_INT(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGIndex(int p1)
#else
PTGNode PTGIndex(p1)

int p1;
#endif
{
	_PPTGIndex n;
	n = (_PPTGIndex)MALLOC(sizeof(struct _SPTGIndex));
	n->_print = (_PTGProc)_PrPTGIndex;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern CType */

typedef struct _SPTGCType{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGCType;

#ifdef PROTO_OK
static void _PrPTGCType(_PPTGCType n)
#else
static void _PrPTGCType(n)
	_PPTGCType n;
#endif
{
	PTG_OUTPUT_STRING(f, "$ ");
	PTG_OUTPUT_STRING(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGCType(CONST char* p1)
#else
PTGNode PTGCType(p1)

CONST char* p1;
#endif
{
	_PPTGCType n;
	n = (_PPTGCType)MALLOC(sizeof(struct _SPTGCType));
	n->_print = (_PTGProc)_PrPTGCType;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern IndTyp */

typedef struct _SPTGIndTyp{
	_PTGProc _print;
	int p1;
	CONST char* p2;
} * _PPTGIndTyp;

#ifdef PROTO_OK
static void _PrPTGIndTyp(_PPTGIndTyp n)
#else
static void _PrPTGIndTyp(n)
	_PPTGIndTyp n;
#endif
{
	PTG_OUTPUT_STRING(f, "$");
	PTG_OUTPUT_INT(f, n->p1);
	PTG_OUTPUT_STRING(f, " ");
	PTG_OUTPUT_STRING(f, n->p2);
}

#ifdef PROTO_OK
PTGNode PTGIndTyp(int p1, CONST char* p2)
#else
PTGNode PTGIndTyp(p1, p2)

int p1;
CONST char* p2;
#endif
{
	_PPTGIndTyp n;
	n = (_PPTGIndTyp)MALLOC(sizeof(struct _SPTGIndTyp));
	n->_print = (_PTGProc)_PrPTGIndTyp;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Call */

typedef struct _SPTGCall{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
} * _PPTGCall;

#ifdef PROTO_OK
static void _PrPTGCall(_PPTGCall n)
#else
static void _PrPTGCall(n)
	_PPTGCall n;
#endif
{
	PTG_OUTPUT_STRING(f, "[");
	PTG_OUTPUT_STRING(f, n->p1);
	if (n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, " ");
	}
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "]");
}

#ifdef PROTO_OK
PTGNode PTGCall(CONST char* p1, PTGNode p2)
#else
PTGNode PTGCall(p1, p2)

CONST char* p1;
PTGNode p2;
#endif
{
	_PPTGCall n;
	n = (_PPTGCall)MALLOC(sizeof(struct _SPTGCall));
	n->_print = (_PTGProc)_PrPTGCall;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Option */

typedef struct _SPTGOption{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGOption;

#ifdef PROTO_OK
static void _PrPTGOption(_PPTGOption n)
#else
static void _PrPTGOption(n)
	_PPTGOption n;
#endif
{
	PTG_OUTPUT_STRING(f, "{ ");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, " }");
}

#ifdef PROTO_OK
PTGNode PTGOption(PTGNode p1)
#else
PTGNode PTGOption(p1)

PTGNode p1;
#endif
{
	_PPTGOption n;
	n = (_PPTGOption)MALLOC(sizeof(struct _SPTGOption));
	n->_print = (_PTGProc)_PrPTGOption;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern SpSeq */

typedef struct _SPTGSpSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSpSeq;

#ifdef PROTO_OK
static void _PrPTGSpSeq(_PPTGSpSeq n)
#else
static void _PrPTGSpSeq(n)
	_PPTGSpSeq n;
#endif
{
	n->p1->_print(n->p1);
	if (n->p1 != PTGNULL && n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, " ");
	}
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSpSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSpSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSpSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGSpSeq)MALLOC(sizeof(struct _SPTGSpSeq));
	n->_print = (_PTGProc)_PrPTGSpSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Plain */

typedef struct _SPTGPlain{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
	PTGNode p3;
} * _PPTGPlain;

#ifdef PROTO_OK
static void _PrPTGPlain(_PPTGPlain n)
#else
static void _PrPTGPlain(n)
	_PPTGPlain n;
#endif
{
	PTG_OUTPUT_STRING(f, "RULE ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, ": ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, " ::= ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " END;\n");
}

#ifdef PROTO_OK
PTGNode PTGPlain(CONST char* p1, CONST char* p2, PTGNode p3)
#else
PTGNode PTGPlain(p1, p2, p3)

CONST char* p1;
CONST char* p2;
PTGNode p3;
#endif
{
	_PPTGPlain n;
	n = (_PPTGPlain)MALLOC(sizeof(struct _SPTGPlain));
	n->_print = (_PTGProc)_PrPTGPlain;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern SpaceSeq */

typedef struct _SPTGSpaceSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSpaceSeq;

#ifdef PROTO_OK
static void _PrPTGSpaceSeq(_PPTGSpaceSeq n)
#else
static void _PrPTGSpaceSeq(n)
	_PPTGSpaceSeq n;
#endif
{
	n->p1->_print(n->p1);
	if (n->p1 != PTGNULL && n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, " ");
	}
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSpaceSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSpaceSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSpaceSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGSpaceSeq)MALLOC(sizeof(struct _SPTGSpaceSeq));
	n->_print = (_PTGProc)_PrPTGSpaceSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Listof */

typedef struct _SPTGListof{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
	PTGNode p3;
} * _PPTGListof;

#ifdef PROTO_OK
static void _PrPTGListof(_PPTGListof n)
#else
static void _PrPTGListof(n)
	_PPTGListof n;
#endif
{
	PTG_OUTPUT_STRING(f, "RULE ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, ": ");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, " LISTOF ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " END;\n");
}

#ifdef PROTO_OK
PTGNode PTGListof(CONST char* p1, CONST char* p2, PTGNode p3)
#else
PTGNode PTGListof(p1, p2, p3)

CONST char* p1;
CONST char* p2;
PTGNode p3;
#endif
{
	_PPTGListof n;
	n = (_PPTGListof)MALLOC(sizeof(struct _SPTGListof));
	n->_print = (_PTGProc)_PrPTGListof;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern AltSeq */

typedef struct _SPTGAltSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGAltSeq;

#ifdef PROTO_OK
static void _PrPTGAltSeq(_PPTGAltSeq n)
#else
static void _PrPTGAltSeq(n)
	_PPTGAltSeq n;
#endif
{
	n->p1->_print(n->p1);
	if (n->p1 != PTGNULL && n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, " | ");
	}
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGAltSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGAltSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGAltSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGAltSeq)MALLOC(sizeof(struct _SPTGAltSeq));
	n->_print = (_PTGProc)_PrPTGAltSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ComputedRoot */

typedef struct _SPTGComputedRoot{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGComputedRoot;

#ifdef PROTO_OK
static void _PrPTGComputedRoot(_PPTGComputedRoot n)
#else
static void _PrPTGComputedRoot(n)
	_PPTGComputedRoot n;
#endif
{
	PTG_OUTPUT_STRING(f, "$ ");
	PTG_OUTPUT_STRING(f, n->p1);
}

#ifdef PROTO_OK
PTGNode PTGComputedRoot(CONST char* p1)
#else
PTGNode PTGComputedRoot(p1)

CONST char* p1;
#endif
{
	_PPTGComputedRoot n;
	n = (_PPTGComputedRoot)MALLOC(sizeof(struct _SPTGComputedRoot));
	n->_print = (_PTGProc)_PrPTGComputedRoot;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern Frame */

typedef struct _SPTGFrame{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
	PTGNode p3;
	PTGNode p4;
	PTGNode p5;
} * _PPTGFrame;

#ifdef PROTO_OK
static void _PrPTGFrame(_PPTGFrame n)
#else
static void _PrPTGFrame(n)
	_PPTGFrame n;
#endif
{
	PTG_OUTPUT_STRING(f, "@p maximum_input_line_length = infinity\n\n");
	PTG_OUTPUT_STRING(f, "The following symbol computation can be used to display the entire input:");
	PTG_OUTPUT_STRING(f, "\n\nSYMBOL ROOTCLASS COMPUTE\n");
	PTG_OUTPUT_STRING(f, "  BP_Out(THIS.");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg);\n");
	PTG_OUTPUT_STRING(f, "END;\n\n");
	PTG_OUTPUT_STRING(f, "Applying this output function to the ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg attribute of any nonterminal\n");
	PTG_OUTPUT_STRING(f, "symbol in the tree will cause the subtree rooted in that node to be");
	PTG_OUTPUT_STRING(f, " displayed.\n\n");
	PTG_OUTPUT_STRING(f, "@O@<");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "copy.lido@>@{\n");
	PTG_OUTPUT_STRING(f, "ATTR ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "Ptg, ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "OrigPtg: PTGNode;\n\n");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, "\n");
	n->p3->_print(n->p3);
	n->p4->_print(n->p4);
	PTG_OUTPUT_STRING(f, "@}\n\n");
	PTG_OUTPUT_STRING(f, "@O@<");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "copy.ptg@>@{\n");
	n->p5->_print(n->p5);
	PTG_OUTPUT_STRING(f, "@}\n\n");
	PTG_OUTPUT_STRING(f, "@O@<");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "copy.ptg.phi@>@{\n");
	PTG_OUTPUT_STRING(f, "#define IGNORE(f,n)\n");
	PTG_OUTPUT_STRING(f, "@}\n\n");
	PTG_OUTPUT_STRING(f, "@O@<");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "copy.specs@>@{\n");
	PTG_OUTPUT_STRING(f, "$/Output/PtgCommon.fw\n");
	PTG_OUTPUT_STRING(f, "$/Output/BlockPrint.fw\n");
	PTG_OUTPUT_STRING(f, "@}\n");
}

#ifdef PROTO_OK
PTGNode PTGFrame(CONST char* p1, PTGNode p2, PTGNode p3, PTGNode p4, PTGNode p5)
#else
PTGNode PTGFrame(p1, p2, p3, p4, p5)

CONST char* p1;
PTGNode p2;
PTGNode p3;
PTGNode p4;
PTGNode p5;
#endif
{
	_PPTGFrame n;
	n = (_PPTGFrame)MALLOC(sizeof(struct _SPTGFrame));
	n->_print = (_PTGProc)_PrPTGFrame;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	n->p4 = p4;
	n->p5 = p5;
	return (PTGNode)n;
}


/* Implementation of Pattern Term */

typedef struct _SPTGTerm{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
} * _PPTGTerm;

#ifdef PROTO_OK
static void _PrPTGTerm(_PPTGTerm n)
#else
static void _PrPTGTerm(n)
	_PPTGTerm n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ":\n  [PtgOutId $ int]\n");
}

#ifdef PROTO_OK
PTGNode PTGTerm(CONST char* p1, PTGNode p2)
#else
PTGNode PTGTerm(p1, p2)

CONST char* p1;
PTGNode p2;
#endif
{
	_PPTGTerm n;
	n = (_PPTGTerm)MALLOC(sizeof(struct _SPTGTerm));
	n->_print = (_PTGProc)_PrPTGTerm;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern PlainProd */

typedef struct _SPTGPlainProd{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
	PTGNode p3;
} * _PPTGPlainProd;

#ifdef PROTO_OK
static void _PrPTGPlainProd(_PPTGPlainProd n)
#else
static void _PrPTGPlainProd(n)
	_PPTGPlainProd n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ":\n");
	PTG_OUTPUT_STRING(f, "  \"<");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ">\" [BP_BeginBlockI] [BP_BreakLine] ");
	n->p3->_print(n->p3);
	PTG_OUTPUT_STRING(f, " [BP_BreakLine] [BP_EndBlockI] \"</");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ">\"\n");
}

#ifdef PROTO_OK
PTGNode PTGPlainProd(CONST char* p1, CONST char* p2, PTGNode p3)
#else
PTGNode PTGPlainProd(p1, p2, p3)

CONST char* p1;
CONST char* p2;
PTGNode p3;
#endif
{
	_PPTGPlainProd n;
	n = (_PPTGPlainProd)MALLOC(sizeof(struct _SPTGPlainProd));
	n->_print = (_PTGProc)_PrPTGPlainProd;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern SepSeq */

typedef struct _SPTGSepSeq{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGSepSeq;

#ifdef PROTO_OK
static void _PrPTGSepSeq(_PPTGSepSeq n)
#else
static void _PrPTGSepSeq(n)
	_PPTGSepSeq n;
#endif
{
	n->p1->_print(n->p1);
	if (n->p1 != PTGNULL && n->p2 != PTGNULL)
	{
		PTG_OUTPUT_STRING(f, " [BP_BreakLine] ");
	}
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGSepSeq(PTGNode p1, PTGNode p2)
#else
PTGNode PTGSepSeq(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGSepSeq n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGSepSeq)MALLOC(sizeof(struct _SPTGSepSeq));
	n->_print = (_PTGProc)_PrPTGSepSeq;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Empty */

typedef struct _SPTGEmpty{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGEmpty;

#ifdef PROTO_OK
static void _PrPTGEmpty(_PPTGEmpty n)
#else
static void _PrPTGEmpty(n)
	_PPTGEmpty n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ":\n \"<");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, "/>\"\n");
}

#ifdef PROTO_OK
PTGNode PTGEmpty(CONST char* p1, CONST char* p2)
#else
PTGNode PTGEmpty(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGEmpty n;
	n = (_PPTGEmpty)MALLOC(sizeof(struct _SPTGEmpty));
	n->_print = (_PTGProc)_PrPTGEmpty;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ListProd */

typedef struct _SPTGListProd{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGListProd;

#ifdef PROTO_OK
static void _PrPTGListProd(_PPTGListProd n)
#else
static void _PrPTGListProd(n)
	_PPTGListProd n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ":\n  \"<");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ">\" [BP_BeginBlockI] [BP_BreakLine] ");
	PTG_OUTPUT_STRING(f, "$ [BP_BreakLine] [BP_EndBlockI] \"</");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ">\"\n");
}

#ifdef PROTO_OK
PTGNode PTGListProd(CONST char* p1, CONST char* p2)
#else
PTGNode PTGListProd(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGListProd n;
	n = (_PPTGListProd)MALLOC(sizeof(struct _SPTGListProd));
	n->_print = (_PTGProc)_PrPTGListProd;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ListProd2 */

typedef struct _SPTGListProd2{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGListProd2;

#ifdef PROTO_OK
static void _PrPTGListProd2(_PPTGListProd2 n)
#else
static void _PrPTGListProd2(n)
	_PPTGListProd2 n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_2");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ":\n  $ { [BP_BreakLine] } $\n");
}

#ifdef PROTO_OK
PTGNode PTGListProd2(CONST char* p1, CONST char* p2)
#else
PTGNode PTGListProd2(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGListProd2 n;
	n = (_PPTGListProd2)MALLOC(sizeof(struct _SPTGListProd2));
	n->_print = (_PTGProc)_PrPTGListProd2;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ListProd1 */

typedef struct _SPTGListProd1{
	_PTGProc _print;
	CONST char* p1;
	CONST char* p2;
} * _PPTGListProd1;

#ifdef PROTO_OK
static void _PrPTGListProd1(_PPTGListProd1 n)
#else
static void _PrPTGListProd1(n)
	_PPTGListProd1 n;
#endif
{
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, "_1");
	PTG_OUTPUT_STRING(f, n->p2);
	PTG_OUTPUT_STRING(f, ":\n  $\n");
}

#ifdef PROTO_OK
PTGNode PTGListProd1(CONST char* p1, CONST char* p2)
#else
PTGNode PTGListProd1(p1, p2)

CONST char* p1;
CONST char* p2;
#endif
{
	_PPTGListProd1 n;
	n = (_PPTGListProd1)MALLOC(sizeof(struct _SPTGListProd1));
	n->_print = (_PTGProc)_PrPTGListProd1;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Triple */

typedef struct _SPTGTriple{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
	PTGNode p3;
} * _PPTGTriple;

#ifdef PROTO_OK
static void _PrPTGTriple(_PPTGTriple n)
#else
static void _PrPTGTriple(n)
	_PPTGTriple n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
	n->p3->_print(n->p3);
}

#ifdef PROTO_OK
PTGNode PTGTriple(PTGNode p1, PTGNode p2, PTGNode p3)
#else
PTGNode PTGTriple(p1, p2, p3)

PTGNode p1;
PTGNode p2;
PTGNode p3;
#endif
{
	_PPTGTriple n;
	if(p1 == PTGNULL && p2 == PTGNULL && p3 == PTGNULL)
		return PTGNULL;
	n = (_PPTGTriple)MALLOC(sizeof(struct _SPTGTriple));
	n->_print = (_PTGProc)_PrPTGTriple;
	n->p1 = p1;
	n->p2 = p2;
	n->p3 = p3;
	return (PTGNode)n;
}


/* Implementation of Pattern dtd */

typedef struct _SPTGdtd{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGdtd;

#ifdef PROTO_OK
static void _PrPTGdtd(_PPTGdtd n)
#else
static void _PrPTGdtd(n)
	_PPTGdtd n;
#endif
{
	n->p1->_print(n->p1);
	n->p2->_print(n->p2);
}

#ifdef PROTO_OK
PTGNode PTGdtd(PTGNode p1, PTGNode p2)
#else
PTGNode PTGdtd(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGdtd n;
	if(p1 == PTGNULL && p2 == PTGNULL)
		return PTGNULL;
	n = (_PPTGdtd)MALLOC(sizeof(struct _SPTGdtd));
	n->_print = (_PTGProc)_PrPTGdtd;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern EntityDef */

typedef struct _SPTGEntityDef{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
} * _PPTGEntityDef;

#ifdef PROTO_OK
static void _PrPTGEntityDef(_PPTGEntityDef n)
#else
static void _PrPTGEntityDef(n)
	_PPTGEntityDef n;
#endif
{
	PTG_OUTPUT_STRING(f, "<!ENTITY % ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " \"(");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ")\">\n");
}

#ifdef PROTO_OK
PTGNode PTGEntityDef(CONST char* p1, PTGNode p2)
#else
PTGNode PTGEntityDef(p1, p2)

CONST char* p1;
PTGNode p2;
#endif
{
	_PPTGEntityDef n;
	n = (_PPTGEntityDef)MALLOC(sizeof(struct _SPTGEntityDef));
	n->_print = (_PTGProc)_PrPTGEntityDef;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Element */

typedef struct _SPTGElement{
	_PTGProc _print;
	CONST char* p1;
	PTGNode p2;
} * _PPTGElement;

#ifdef PROTO_OK
static void _PrPTGElement(_PPTGElement n)
#else
static void _PrPTGElement(n)
	_PPTGElement n;
#endif
{
	PTG_OUTPUT_STRING(f, "<!ELEMENT ");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, " ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, ">\n");
}

#ifdef PROTO_OK
PTGNode PTGElement(CONST char* p1, PTGNode p2)
#else
PTGNode PTGElement(p1, p2)

CONST char* p1;
PTGNode p2;
#endif
{
	_PPTGElement n;
	n = (_PPTGElement)MALLOC(sizeof(struct _SPTGElement));
	n->_print = (_PTGProc)_PrPTGElement;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Content */

typedef struct _SPTGContent{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGContent;

#ifdef PROTO_OK
static void _PrPTGContent(_PPTGContent n)
#else
static void _PrPTGContent(n)
	_PPTGContent n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")");
}

#ifdef PROTO_OK
PTGNode PTGContent(PTGNode p1)
#else
PTGNode PTGContent(p1)

PTGNode p1;
#endif
{
	_PPTGContent n;
	n = (_PPTGContent)MALLOC(sizeof(struct _SPTGContent));
	n->_print = (_PTGProc)_PrPTGContent;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ListContent */

typedef struct _SPTGListContent{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGListContent;

#ifdef PROTO_OK
static void _PrPTGListContent(_PPTGListContent n)
#else
static void _PrPTGListContent(n)
	_PPTGListContent n;
#endif
{
	PTG_OUTPUT_STRING(f, "(");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")*");
}

#ifdef PROTO_OK
PTGNode PTGListContent(PTGNode p1)
#else
PTGNode PTGListContent(p1)

PTGNode p1;
#endif
{
	_PPTGListContent n;
	n = (_PPTGListContent)MALLOC(sizeof(struct _SPTGListContent));
	n->_print = (_PTGProc)_PrPTGListContent;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern EntityUse */

typedef struct _SPTGEntityUse{
	_PTGProc _print;
	CONST char* p1;
} * _PPTGEntityUse;

#ifdef PROTO_OK
static void _PrPTGEntityUse(_PPTGEntityUse n)
#else
static void _PrPTGEntityUse(n)
	_PPTGEntityUse n;
#endif
{
	PTG_OUTPUT_STRING(f, "%");
	PTG_OUTPUT_STRING(f, n->p1);
	PTG_OUTPUT_STRING(f, ";");
}

#ifdef PROTO_OK
PTGNode PTGEntityUse(CONST char* p1)
#else
PTGNode PTGEntityUse(p1)

CONST char* p1;
#endif
{
	_PPTGEntityUse n;
	n = (_PPTGEntityUse)MALLOC(sizeof(struct _SPTGEntityUse));
	n->_print = (_PTGProc)_PrPTGEntityUse;
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

