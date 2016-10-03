#ifndef CLP_H

#define CLP_H
#include "clplib.h"
#include "pdl_gen.h"
#include "DefTableKeyList.h"

extern DefTableKey CLP_InputFile;
#ifdef PROTO_OK
extern void clp_usage (char *);
#else
extern void clp_usage ();
#endif

extern int CompileOnly;
extern DefTableKeyList MacroPackage;
extern DefTableKey OutputFile;
extern DefTableKey InputFile;
extern int GenAssembly;
extern DefTableKey TmpFile;
extern int WideListing;
extern int Extra;
extern DefTableKey NumCopies;
extern DefTableKey NumCols;
extern DefTableKeyList NumZaps;
extern DefTableKeyList NumLines;
extern DefTableKeyList Others;

#endif
