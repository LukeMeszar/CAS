# define CHAR 257
# define NUMBER 258
# define SECTEND 259
# define SCDECL 260
# define XSCDECL 261
# define WHITESPACE 262
# define NAME 263
# define PREVCCL 264

extern void synerr( char[] );
extern void yyerror( char[] );
extern int yyparse( void );
