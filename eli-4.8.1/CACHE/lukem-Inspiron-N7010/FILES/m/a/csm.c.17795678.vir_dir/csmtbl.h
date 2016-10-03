	/* This is an initialized obstack */

static struct {char *l; void *p; char c[181];} csm_data = {
	&(csm_data.c[181]),
	0,
"\0\
OR\0\
BEGIN\0\
END\0\
CONST\0\
OF\0\
NIL\0\
ARRAY\0\
LABEL\0\
AND\0\
DIV\0\
MOD\0\
PROGRAM\0\
FUNCTION\0\
PROCEDURE\0\
VAR\0\
IN\0\
FILE\0\
RECORD\0\
SET\0\
PACKED\0\
TYPE\0\
CASE\0\
FOR\0\
DOWNTO\0\
DO\0\
TO\0\
GOTO\0\
IF\0\
THEN\0\
ELSE\0\
REPEAT\0\
UNTIL\0\
WHILE\0\
NOT\0\
WITH"};

struct obstack csm_obstack =
	obstack_known_chunk(&csm_data,
	&(csm_data.c[181]), &(csm_data.c[181]), &(csm_data.c[181]),
	4096, 1);

	/* This is an initialized obstack */

static struct {char **l; void *p; char *c[36];} csm_indx = {
	&(csm_indx.c[36]),
	0,{
	&(csm_data.c[0]),
	&(csm_data.c[1]),
	&(csm_data.c[4]),
	&(csm_data.c[10]),
	&(csm_data.c[14]),
	&(csm_data.c[20]),
	&(csm_data.c[23]),
	&(csm_data.c[27]),
	&(csm_data.c[33]),
	&(csm_data.c[39]),
	&(csm_data.c[43]),
	&(csm_data.c[47]),
	&(csm_data.c[51]),
	&(csm_data.c[59]),
	&(csm_data.c[68]),
	&(csm_data.c[78]),
	&(csm_data.c[82]),
	&(csm_data.c[85]),
	&(csm_data.c[90]),
	&(csm_data.c[97]),
	&(csm_data.c[101]),
	&(csm_data.c[108]),
	&(csm_data.c[113]),
	&(csm_data.c[118]),
	&(csm_data.c[122]),
	&(csm_data.c[129]),
	&(csm_data.c[132]),
	&(csm_data.c[135]),
	&(csm_data.c[140]),
	&(csm_data.c[143]),
	&(csm_data.c[148]),
	&(csm_data.c[153]),
	&(csm_data.c[160]),
	&(csm_data.c[166]),
	&(csm_data.c[172]),
	&(csm_data.c[176])}};

struct csmalign {char ___x; char *___d;};
static struct obstack csm_indx_obstk =
	obstack_known_chunk(&csm_indx, &(csm_indx.c[0]),
	&(csm_indx.c[36]), &(csm_indx.c[36]), 4096,
	((PTR_INT_TYPE) ((char *) &((struct csmalign *) 0)->___d - (char *) 0)));

char **strng = csm_indx.c;
int numstr = 36;

