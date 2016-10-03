
#include <string.h>
#include "csm.h"
#include "err.h"
#include "deftbl.h"
#include "pdl_gen.h"

CONST char *filename, *basefilename, *cfilename, *hfilename, *dbfilename,
     *reqsymfilename;

void uiinit ()
{
    char *dot, save;
    int len;

    extern DefTableKey InputFileName;
    extern DefTableKey BaseFileName;

    /* Get the actual filename and base file name */
    filename = StringTable (GetClpValue (InputFileName, 0));
    if (BaseFileName == NoKey) {
       /* Default to first component of filename */
       dot = strchr (filename, '.');
       if (!dot) dot = strchr (filename, '\0');
       obstack_grow0(Csm_obstk, filename, dot - filename);
       basefilename = (const char *)obstack_finish(Csm_obstk);
    } else    
       basefilename = StringTable (GetClpValue (BaseFileName, 0));

    /* Make the output filenames */
    len = strlen (basefilename);

    obstack_grow(Csm_obstk, basefilename, len);
    obstack_grow0(Csm_obstk, "_dapto.c", 8);
    cfilename = (const char *)obstack_finish(Csm_obstk);

    obstack_grow(Csm_obstk, basefilename, len);
    obstack_grow0(Csm_obstk, "_dapto.h", 8);
    hfilename = (const char *)obstack_finish(Csm_obstk);

    obstack_grow(Csm_obstk, basefilename, len);
    obstack_grow0(Csm_obstk, "_dapto.db", 9);
    dbfilename = (const char *)obstack_finish(Csm_obstk);

    obstack_grow(Csm_obstk, basefilename, len);
    obstack_grow0(Csm_obstk, "_dapto.reqsym", 13);
    reqsymfilename = (const char *)obstack_finish(Csm_obstk);
}
