# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/Eli/tests/scanner/c.gla"
{ $Id: c.gla,v 1.1 1990/06/28 11:39:25 tony Exp $ }
{ Lexical structure }

ICONST:		C_INTEGER
IDENTIFIER: 	C_IDENTIFIER			
TYPENAME:	C_IDENTIFIER		

SCONST:         C_STRING_LIT
CCONST:         C_CHAR_CONSTANT
RCONST:		C_FLOAT
		C_COMMENT
		{ ignore C preprocessor directives }
		$#\040[0-9]	(auxEOL)
                $#[\040]*[a-zA-Z]   (auxEOL)
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/gla/separator"
%EOFTOKEN 1
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/i/w/c.gla.13668247.dflt_codes"
ICONST		2
IDENTIFIER		3
TYPENAME		4
SCONST		5
CCONST		6
RCONST		7
