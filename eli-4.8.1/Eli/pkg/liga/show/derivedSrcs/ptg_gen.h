#ifndef _PTGGEN_H
#define _PTGGEN_H

#include <stdio.h>
#include "eliproto.h"

/* Include-files specified in .ptg.phi-files */

#include "ptg.h"
/* Definition of Output-Macros */

#if !defined(PTG_OUTPUT_FILE)
#    define PTG_OUTPUT_FILE FILE *
#    define PTG_OUTPUT_DEFAULT 1
#else
#    define PTG_OUTPUT_DEFAULT 0
#endif
#if !defined(PTG_OUTPUT_STRING)
#    define PTG_OUTPUT_STRING(file,param) fputs(param, file)
#    if !defined(PTG_OUTPUT_INT)
#            define PTG_OUTPUT_INT(file,param)    fprintf(file,"%d",param)
#    endif
#    if !defined(PTG_OUTPUT_LONG)
#            define PTG_OUTPUT_LONG(file,param)   fprintf(file,"%ld",param)
#    endif
#    if !defined(PTG_OUTPUT_SHORT)
#            define PTG_OUTPUT_SHORT(file,param)  fprintf(file,"%d",(int) param)
#    endif
#    if !defined(PTG_OUTPUT_CHAR)
#            define PTG_OUTPUT_CHAR(file,param)   fputc(param, file)
#    endif
#    if !defined(PTG_OUTPUT_FLOAT)
#            define PTG_OUTPUT_FLOAT(file,param)  fprintf(file,"%g",(double)param)
#    endif
#    if !defined(PTG_OUTPUT_DOUBLE)
#            define PTG_OUTPUT_DOUBLE(file,param) fprintf(file,"%g",param)
#    endif

#else
     /* PTG_OUTPUT_STRING defined */
     extern void _PTGPrintInt ELI_ARG((PTG_OUTPUT_FILE,int));
     extern void _PTGPrintLong ELI_ARG((PTG_OUTPUT_FILE,long));
     extern void _PTGPrintChar ELI_ARG((PTG_OUTPUT_FILE,char));
     extern void _PTGPrintDouble ELI_ARG((PTG_OUTPUT_FILE,double));
#    if !defined(PTG_OUTPUT_INT)
#            define PTG_OUTPUT_INT(file,param)    _PTGPrintInt(file,param)
#    endif
#    if !defined(PTG_OUTPUT_LONG)
#            define PTG_OUTPUT_LONG(file,param)   _PTGPrintLong(file,param)
#    endif
#    if !defined(PTG_OUTPUT_SHORT)
#            define PTG_OUTPUT_SHORT(file,param)  _PTGPrintInt(file,(int)param)
#    endif
#    if !defined(PTG_OUTPUT_CHAR)
#            define PTG_OUTPUT_CHAR(file,param)   _PTGPrintChar(file,param)
#    endif
#    if !defined(PTG_OUTPUT_FLOAT)
#            define PTG_OUTPUT_FLOAT(file,param)  _PTGPrintDouble(file,(double)param)
#    endif
#    if !defined(PTG_OUTPUT_DOUBLE)
#            define PTG_OUTPUT_DOUBLE(file,param) _PTGPrintDouble(file,param)
#    endif
#endif

/* Define PTGNode Type */
#if defined(__cplusplus)
struct _SPTG0;
typedef void (* _PTGProc)(struct _SPTG0 *);
#else
typedef void (* _PTGProc)();
#endif

typedef struct _SPTG0
{
  _PTGProc _print;
} * _PPTG0;
typedef _PPTG0 PTGNode;                      /* the only exported type */

/* predefined static PTGNULL-Node */

extern struct _SPTG0 _PTGNULL;
#define PTGNULL (& _PTGNULL)
#define PTGNull() (& _PTGNULL)

/* output functions */

#if PTG_OUTPUT_DEFAULT
extern PTGNode PTGOut ELI_ARG((PTGNode root));
extern PTGNode PTGOutFile ELI_ARG((const char *filename, PTGNode root));
extern PTGNode PTGOutFPtr ELI_ARG((FILE *output, PTGNode root));
#endif
extern PTGNode PTGProcess ELI_ARG((PTG_OUTPUT_FILE file, PTGNode root));

/* Memory Management functions. */

extern void PTGFree ELI_ARG((void));

/* ============================ */
/* functions for making PTG nodes */
PTGNode PTGAttrListHead ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGAttrDecl ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGAttrInfo ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3, PTGNode p4));
PTGNode PTGTreeStore ELI_ARG((void));
PTGNode PTGStackStore ELI_ARG((void));
PTGNode PTGVarStore ELI_ARG((PTGNode p1));
PTGNode PTGOrigChain ELI_ARG((void));
PTGNode PTGOrigRule ELI_ARG((PTGNode p1));
PTGNode PTGOrigConst ELI_ARG((void));
PTGNode PTGOrigIncl ELI_ARG((void));
PTGNode PTGUnknown ELI_ARG((void));
PTGNode PTGNONTERM ELI_ARG((void));
PTGNode PTGTerminalDef ELI_ARG((CONST char* p1, CONST char* p2));
PTGNode PTGINH ELI_ARG((void));
PTGNode PTGSYNT ELI_ARG((void));
PTGNode PTGLine ELI_ARG((void));
PTGNode PTGCol ELI_ARG((void));
PTGNode PTGAddr ELI_ARG((void));
PTGNode PTGOrder ELI_ARG((void));
PTGNode PTGPragma ELI_ARG((void));
PTGNode PTGIf ELI_ARG((void));
PTGNode PTGIterate ELI_ARG((PTGNode p1));
PTGNode PTGCall ELI_ARG((PTGNode p1));
PTGNode PTGAssign ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGNonLitTermAcc ELI_ARG((int p1));
PTGNode PTGConstituents ELI_ARG((void));
PTGNode PTGConstituent ELI_ARG((void));
PTGNode PTGConstituent_s ELI_ARG((void));
PTGNode PTGIncluding ELI_ARG((void));
PTGNode PTGVisitRule ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGSymbolIndex ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGSymbol ELI_ARG((PTGNode p1));
PTGNode PTGGenSymbol ELI_ARG((PTGNode p1));
PTGNode PTGLiteral ELI_ARG((PTGNode p1));
PTGNode PTGVisit ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGLeave ELI_ARG((PTGNode p1));
PTGNode PTGComputation ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGLabel ELI_ARG((void));
PTGNode PTGChainStart ELI_ARG((PTGNode p1));
PTGNode PTGAttrAcc ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGFileList ELI_ARG((PTGNode p1));
PTGNode PTGFileAssoc ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGCoord ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGFileRef ELI_ARG((PTGNode p1));
PTGNode PTGComma ELI_ARG((void));
PTGNode PTGSemicol ELI_ARG((void));
PTGNode PTGColSemi ELI_ARG((void));
PTGNode PTGNewLine ELI_ARG((void));
PTGNode PTGSpace2 ELI_ARG((void));
PTGNode PTGCChar ELI_ARG((CONST char* p1));
PTGNode PTGName ELI_ARG((CONST char* p1));
PTGNode PTGNumb ELI_ARG((int p1));
PTGNode PTGSeq ELI_ARG((PTGNode p1, PTGNode p2));

/* prototypes for used function call insertions */

/* ============================ */

#ifdef MONITOR
/* Monitoring support for structured values */
#define DAPTO_RESULTPTGNode(n) DAPTO_RESULT_PTR(n)
#define DAPTO_ARGPTGNode(n) DAPTO_ARG_PTR(n, PTGNode)
#endif

#endif
