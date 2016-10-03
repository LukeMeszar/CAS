
#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "eliproto.h"
#include "deftbl.h"

extern int  Warn;       /* Standard FunnelWeb warning character */

extern void p_mkstr     ELI_ARG((char *, int, int *, int *));
extern int  MakePtgSym  ELI_ARG((int));
extern void FixPtgGiven ELI_ARG((int, DefTableKey));
extern int  FwOut       ELI_ARG((int, int));

#endif
