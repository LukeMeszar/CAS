# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/q/cola.dapto.16137975.dapto"






















aspect parser;

event production* "Recognition of a production during parsing"
	(int prod "Index of production",
	 int uses "Number of preceding recognitions subsumed",
	 int linebeg "Line number of beginning of extent",
	 int colbeg "Column number of beginning of extent",
	 int lineend "Line number of ending of extent",
	 int colend "Column number of ending of extent");

operation get_conc_prod "Look up the text of a production"
	(int index "Index of the production") : str
{
    extern char *conc_prods[];

    DAPTO_RESULT_STR (conc_prods[index]);
}

end;
