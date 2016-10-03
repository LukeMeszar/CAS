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
PTGNode PTGfile ELI_ARG((PTGNode p1, int p2, PTGNode p3, PTGNode p4, PTGNode p5, PTGNode p6, int p7, PTGNode p8));
PTGNode PTGkdecl ELI_ARG((int p1));
PTGNode PTGkkdecl ELI_ARG((int p1));
PTGNode PTGbdecl ELI_ARG((int p1));
PTGNode PTGidecl ELI_ARG((int p1));
PTGNode PTGtopt ELI_ARG((int p1));
PTGNode PTGlit ELI_ARG((int p1));
PTGNode PTGopt ELI_ARG((CONST char* p1, CONST char* p2, PTGNode p3, PTGNode p4, PTGNode p5));
PTGNode PTGcount ELI_ARG((int p1));
PTGNode PTGvar ELI_ARG((int p1));
PTGNode PTGnone ELI_ARG((void));
PTGNode PTGparam ELI_ARG((int p1));
PTGNode PTGmparam ELI_ARG((int p1));
PTGNode PTGinput ELI_ARG((int p1));
PTGNode PTGuse ELI_ARG((PTGNode p1, int p2));
PTGNode PTGuses ELI_ARG((PTGNode p1, int p2));
PTGNode PTGtuse ELI_ARG((PTGNode p1));
PTGNode PTGvuse ELI_ARG((int p1, CONST char* p2, CONST char* p3, int p4, PTGNode p5));
PTGNode PTGuuse ELI_ARG((PTGNode p1));
PTGNode PTGmsg ELI_ARG((int p1, CONST char* p2));
PTGNode PTGheader ELI_ARG((PTGNode p1));
PTGNode PTGkextern ELI_ARG((int p1));
PTGNode PTGkkextern ELI_ARG((int p1));
PTGNode PTGiextern ELI_ARG((int p1));
PTGNode PTGseq ELI_ARG((PTGNode p1, PTGNode p2));
PTGNode PTGseq3 ELI_ARG((PTGNode p1, PTGNode p2, PTGNode p3));
PTGNode PTGcstr ELI_ARG((CONST char* p1));
PTGNode PTGstr ELI_ARG((int p1));
PTGNode PTGpstr ELI_ARG((int p1, int p2));

/* prototypes for used function call insertions */

void OutStr ELI_ARG((PTG_OUTPUT_FILE, int));
void OutPSStr ELI_ARG((PTG_OUTPUT_FILE, int, CONST char*, CONST char*, int));
void OutPStr ELI_ARG((PTG_OUTPUT_FILE, int, int));
/* ============================ */

#ifdef MONITOR
/* Monitoring support for structured values */
#define DAPTO_RESULTPTGNode(n) DAPTO_RESULT_PTR(n)
#define DAPTO_ARGPTGNode(n) DAPTO_ARG_PTR(n, PTGNode)
#endif

#endif