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


/* Implementation of Pattern PDL */

typedef struct _SPTGPDL{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGPDL;

#ifdef PROTO_OK
static void _PrPTGPDL(_PPTGPDL n)
#else
static void _PrPTGPDL(n)
	_PPTGPDL n;
#endif
{
	PTG_OUTPUT_STRING(f, "\"OilDecls.h\"\n");
	PTG_OUTPUT_STRING(f, "IsType: int;\n");
	PTG_OUTPUT_STRING(f, "OilType: tOilType;\n");
	PTG_OUTPUT_STRING(f, "OilOp: tOilOp;\n");
	PTG_OUTPUT_STRING(f, "OilClass: tOilClass;\n");
	n->p1->_print(n->p1);
}

#ifdef PROTO_OK
PTGNode PTGPDL(PTGNode p1)
#else
PTGNode PTGPDL(p1)

PTGNode p1;
#endif
{
	_PPTGPDL n;
	n = (_PPTGPDL)MALLOC(sizeof(struct _SPTGPDL));
	n->_print = (_PTGProc)_PrPTGPDL;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern TypeProperty */

typedef struct _SPTGTypeProperty{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGTypeProperty;

#ifdef PROTO_OK
static void _PrPTGTypeProperty(_PPTGTypeProperty n)
#else
static void _PrPTGTypeProperty(n)
	_PPTGTypeProperty n;
#endif
{
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " -> IsType={1}, OilType={(tOilType)&Oil_t");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "};\n");
}

#ifdef PROTO_OK
PTGNode PTGTypeProperty(PTGNode p1, PTGNode p2)
#else
PTGNode PTGTypeProperty(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGTypeProperty n;
	n = (_PPTGTypeProperty)MALLOC(sizeof(struct _SPTGTypeProperty));
	n->_print = (_PTGProc)_PrPTGTypeProperty;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern OperatorProperty */

typedef struct _SPTGOperatorProperty{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGOperatorProperty;

#ifdef PROTO_OK
static void _PrPTGOperatorProperty(_PPTGOperatorProperty n)
#else
static void _PrPTGOperatorProperty(n)
	_PPTGOperatorProperty n;
#endif
{
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " -> OilOp={(tOilOp)&Oil_o");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "};\n");
}

#ifdef PROTO_OK
PTGNode PTGOperatorProperty(PTGNode p1, PTGNode p2)
#else
PTGNode PTGOperatorProperty(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGOperatorProperty n;
	n = (_PPTGOperatorProperty)MALLOC(sizeof(struct _SPTGOperatorProperty));
	n->_print = (_PTGProc)_PrPTGOperatorProperty;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern MultOperator */

typedef struct _SPTGMultOperator{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGMultOperator;

#ifdef PROTO_OK
static void _PrPTGMultOperator(_PPTGMultOperator n)
#else
static void _PrPTGMultOperator(n)
	_PPTGMultOperator n;
#endif
{
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ";\n");
}

#ifdef PROTO_OK
PTGNode PTGMultOperator(PTGNode p1)
#else
PTGNode PTGMultOperator(p1)

PTGNode p1;
#endif
{
	_PPTGMultOperator n;
	n = (_PPTGMultOperator)MALLOC(sizeof(struct _SPTGMultOperator));
	n->_print = (_PTGProc)_PrPTGMultOperator;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern ClassProperty */

typedef struct _SPTGClassProperty{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGClassProperty;

#ifdef PROTO_OK
static void _PrPTGClassProperty(_PPTGClassProperty n)
#else
static void _PrPTGClassProperty(n)
	_PPTGClassProperty n;
#endif
{
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " -> OilClass={(tOilClass)&Oil_c");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "};\n");
}

#ifdef PROTO_OK
PTGNode PTGClassProperty(PTGNode p1, PTGNode p2)
#else
PTGNode PTGClassProperty(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGClassProperty n;
	n = (_PPTGClassProperty)MALLOC(sizeof(struct _SPTGClassProperty));
	n->_print = (_PTGProc)_PrPTGClassProperty;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern Header */

typedef struct _SPTGHeader{
	_PTGProc _print;
	PTGNode p1;
} * _PPTGHeader;

#ifdef PROTO_OK
static void _PrPTGHeader(_PPTGHeader n)
#else
static void _PrPTGHeader(n)
	_PPTGHeader n;
#endif
{
	PTG_OUTPUT_STRING(f, "#ifndef OILDECLS_H\n");
	PTG_OUTPUT_STRING(f, "#define OILDECLS_H\n");
	PTG_OUTPUT_STRING(f, "#include \"oiladt2.h\"\n");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, "#endif\n");
}

#ifdef PROTO_OK
PTGNode PTGHeader(PTGNode p1)
#else
PTGNode PTGHeader(p1)

PTGNode p1;
#endif
{
	_PPTGHeader n;
	n = (_PPTGHeader)MALLOC(sizeof(struct _SPTGHeader));
	n->_print = (_PTGProc)_PrPTGHeader;
	n->p1 = p1;
	return (PTGNode)n;
}


/* Implementation of Pattern TypeSymbol */

typedef struct _SPTGTypeSymbol{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGTypeSymbol;

#ifdef PROTO_OK
static void _PrPTGTypeSymbol(_PPTGTypeSymbol n)
#else
static void _PrPTGTypeSymbol(n)
	_PPTGTypeSymbol n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern struct Stype Oil_t");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ";\t/* ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " */\n");
	PTG_OUTPUT_STRING(f, "#define OilType");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " (&Oil_t");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")\n");
}

#ifdef PROTO_OK
PTGNode PTGTypeSymbol(PTGNode p1, PTGNode p2)
#else
PTGNode PTGTypeSymbol(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGTypeSymbol n;
	n = (_PPTGTypeSymbol)MALLOC(sizeof(struct _SPTGTypeSymbol));
	n->_print = (_PTGProc)_PrPTGTypeSymbol;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern OperatorSymbol */

typedef struct _SPTGOperatorSymbol{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGOperatorSymbol;

#ifdef PROTO_OK
static void _PrPTGOperatorSymbol(_PPTGOperatorSymbol n)
#else
static void _PrPTGOperatorSymbol(n)
	_PPTGOperatorSymbol n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern struct Sop Oil_o");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ";\t/* ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " */\n");
	PTG_OUTPUT_STRING(f, "#define OilOp");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " (&Oil_o");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")\n");
}

#ifdef PROTO_OK
PTGNode PTGOperatorSymbol(PTGNode p1, PTGNode p2)
#else
PTGNode PTGOperatorSymbol(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGOperatorSymbol n;
	n = (_PPTGOperatorSymbol)MALLOC(sizeof(struct _SPTGOperatorSymbol));
	n->_print = (_PTGProc)_PrPTGOperatorSymbol;
	n->p1 = p1;
	n->p2 = p2;
	return (PTGNode)n;
}


/* Implementation of Pattern ClassSymbol */

typedef struct _SPTGClassSymbol{
	_PTGProc _print;
	PTGNode p1;
	PTGNode p2;
} * _PPTGClassSymbol;

#ifdef PROTO_OK
static void _PrPTGClassSymbol(_PPTGClassSymbol n)
#else
static void _PrPTGClassSymbol(n)
	_PPTGClassSymbol n;
#endif
{
	PTG_OUTPUT_STRING(f, "extern struct Sclass Oil_c");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ";\t/* ");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " */\n");
	PTG_OUTPUT_STRING(f, "#define OilClass");
	n->p2->_print(n->p2);
	PTG_OUTPUT_STRING(f, " (&Oil_c");
	n->p1->_print(n->p1);
	PTG_OUTPUT_STRING(f, ")\n");
}

#ifdef PROTO_OK
PTGNode PTGClassSymbol(PTGNode p1, PTGNode p2)
#else
PTGNode PTGClassSymbol(p1, p2)

PTGNode p1;
PTGNode p2;
#endif
{
	_PPTGClassSymbol n;
	n = (_PPTGClassSymbol)MALLOC(sizeof(struct _SPTGClassSymbol));
	n->_print = (_PTGProc)_PrPTGClassSymbol;
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

