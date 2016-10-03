# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/Adt/csm.dapto"




















aspect string;

<stdlib.h>
<string.h>
"csm.h"

event string_stored* "Storage of a new string in the string table"
    (int index "Index of new string", str string "New string");

operation get_string "Look up a string given its index"
    (int index "Index of the string to be looked up") : str
{ 
    if ((index < 0) || (index >= numstr)) {
	DAPTO_RESULT_STR ("*** Illegal string table index ***");
    } else {
	char *s = StringTable (index);
	if (s == (char *) 0) {
	    DAPTO_RESULT_STR ("*** No string at this index ***");
        } else {
	    DAPTO_RESULT_STR (s);
        }
    }
}

operation get_all_strings "Look up all of the index-string pairs"
    () : str
{
    int i;
    char *s;

    for (i = 0; i < numstr; i++) {
        s = StringTable (i);
        if (s == (char *) 0)
            continue;
	DAPTO_RESULT_INT (i);
	DAPTO_RESULT_STR (s);
    }
}

end;
