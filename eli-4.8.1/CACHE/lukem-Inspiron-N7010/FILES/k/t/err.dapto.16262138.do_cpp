# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/Input/err.dapto"




aspect messages;

event message* "Generation of a program message"
	(str severity "Severity of this message",
	 str text "Message text",
	 int line "Line number",
	 int col "Column number");

end;

aspect coordinates;

"err.h"

operation get_coordinate_info
    "Return the coordinates"
    (CoordPtr coord "The coordinates of interest") : str
{
    DAPTO_RESULTPOSITION(*coord);
}

end;
