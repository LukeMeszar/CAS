/* Date should go here */
#define    ZEMAXTERMINALCODE 2
#define    ZEMAXRSLAENGE     1
#define    ZEANZZST          2
#define    ZEMAXTEINTRAG     6
#define    ZEMAXNTEINTRAG    2
#define    ZEMAXTE1          2
#define    ZEMAXTE2          4
#define    ZEMAXNTE          2
#define    ZEANZNT           2
#define    ZEANZPROD         2
#define    ZEMAXTNEXT        2
#define    ZEMAXTCHECK       2
#define    ZEMAXNTNEXT       2
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,     0,     0 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,     6,     3 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,     2,     1 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,     0,     0 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     0 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     2 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,     2,     1 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     1,     1 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,     2,     1 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,     2,     1 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0    };

