/* Date should go here */
#define    ZEMAXTERMINALCODE 17
#define    ZEMAXRSLAENGE     3
#define    ZEANZZST          13
#define    ZEMAXTEINTRAG     47
#define    ZEMAXNTEINTRAG    15
#define    ZEMAXTE1          13
#define    ZEMAXTE2          30
#define    ZEMAXNTE          13
#define    ZEANZNT           5
#define    ZEANZPROD         17
#define    ZEMAXTNEXT        35
#define    ZEMAXTCHECK       44
#define    ZEMAXNTNEXT       14
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,     0,     0,     8,    18,    27,    10,    20,     0,     0,
    0,     0,     0,    15 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,    46,    46,    46,    16,    17,    18,    19,    20,    21,
   22,    23,    24,    25,     2,    46,    47,    47,    47,    43,
    8,     9,     8,     9,    10,    11,    10,    11,    44,     0,
   47,     0,     0,     0,     0,    28 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,    12,    12,    12,    11,    11,    11,    11,    11,    11,
   11,    11,    11,    11,    11,    12,    13,    13,    13,     4,
    4,     4,     7,     7,     3,     3,     6,     6,     5,     0,
   13,     0,     0,     0,     0,     7,     0,     0,     0,     0,
    0,     0,     0,     0,     0 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,    11,    11,     4,     0,     0,     7,     0,    11,    11,
   11,     0,     6,     6 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     3,     0,     0,     0,     0,     0,     5,     7,
    8,     9,     0,     0 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     5,     4,     3,     3,     7,     6,     6,    12,
   12,    13,    13,    14,    15 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,     4,     4,     5,     5,     5,     5,     5,     5,     5,
    5,     5,     5,     2,     1,     5,     3,     3 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     3,     3,     1,     1,     1,     1,     1,     1,     1,
    1,     1,     1,     1,     1,     3,     3,     3 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,    13,    13,     1,     1,     1,    15,    15,    13,    13,
   13,    13,     1,     1 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,    13,    13,     1,     1,     1,    15,    15,    13,    13,
   13,    13,     1,     1 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2   ,  0X0    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0   ,  0X0    };

