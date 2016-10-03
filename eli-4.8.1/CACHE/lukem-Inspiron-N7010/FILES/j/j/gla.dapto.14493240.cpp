# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/gla/gla.dapto"




aspect lexical;

event token* "Token recognition"
	(str type "Token type",
	 int linebeg "Line number of beginning of extent",
	 int colbeg "Local Column number of beginning of extent",
	 int cumcolbeg "Cumulative Column number of beginning of extent",
	 int lineend "Line number of ending of extent",
	 int colend "Local Column number of ending of extent",
	 int cumcolend "Cumulative Column number of ending of extent",
	 str lexeme "Character string",
	 int len "Length",
	 int val "Value",
	 int code "Token code");

end;
