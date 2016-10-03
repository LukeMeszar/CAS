
#include <string.h>
#include "csm.h"
#include "pdl_gen.h"
#include "oiladt2b.h"
#include "eliproto.h"


void
#ifdef PROTO_OK
DumpOps(DefTableKey OpName)
#else
DumpOps(OpName) DefTableKey OpName;
#endif
{ tOilOpList ops;

  for (ops = GetOperator(OpName, NULLtOilOpList);
       ops != NULLtOilOpList;
       ops = TailtOilOpList(ops))
   OilDumpOp(HeadtOilOpList(ops));
}


char *
#ifdef PROTO_OK
RepName(char *buffer, DefTableKey name)
#else
RepName(buffer, name) char *buffer; DefTableKey name;
#endif
{ return strcpy(buffer, StringTable(GetIndex(name, 0))); }

