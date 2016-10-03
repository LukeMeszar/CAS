/* Date should go here */
#define    ZEMAXTERMINALCODE 12
#define    ZEMAXRSLAENGE     5
#define    ZEANZZST          25
#define    ZEMAXTEINTRAG     75
#define    ZEMAXNTEINTRAG    33
#define    ZEMAXTE1          25
#define    ZEMAXTE2          50
#define    ZEMAXNTE          25
#define    ZEANZNT           17
#define    ZEANZPROD         25
#define    ZEMAXTNEXT        38
#define    ZEMAXTCHECK       44
#define    ZEMAXNTNEXT       26
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,     0,    10,    22,    16,     1,    10,    13,    21,     0,
   21,    22,    24,    25,    23,     0,    15,     0,    15,    28,
   24,    23,    31,    32,    19,    32 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,    59,    64,    59,    64,    10,    59,    64,    11,    67,
   64,    60,    63,    36,    63,    12,     6,    65,    64,    68,
   69,    25,    68,    62,     9,    13,    21,    17,    18,    50,
   38,    41,    20,    45,    46,    47,    48,    49,    15 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,     1,    15,     1,    15,     5,     1,    15,     5,    15,
   15,     2,     6,     2,     6,     7,     2,     7,     6,    16,
   18,    24,    16,     3,     4,     8,    18,    10,    11,    24,
   12,    13,    14,    19,    20,    21,    22,    23,    25,     0,
    0,     0,     0,     0,     0 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
    0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
   25,     0,     0,     0,     0,     0 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
    0,     0,     6,     2,     0,     0,     1,     9,    13,     0,
    1,     0,     0,     0,     0,    10 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     3,     7,     7,     8,     2,    26,    27,    28,
   30,     5,    19,     4,    29,    32,    31,    14,    24,    29,
   16,    22,    14,    29,    33,    23,    14 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,     6,     6,     6,    14,     3,    11,    17,    17,     6,
    2,     7,     1,     4,    13,     5,    10,    16,    15,    12,
    8,    14,    12,     9,     9,    14 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     2,     2,     2,     1,     3,     4,     1,     3,     0,
    1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
    4,     3,     2,     5,     5,     4 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,     8,     7,     2,     4,     4,     6,
    6,     6,     6,     6,     9,     2,     4,     5,     5,     5,
   10,    12,     5,     5,    10,     6 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,     8,     7,     2,     4,     4,     6,
    6,     6,     6,     6,     9,     2,     4,     5,     5,     5,
   10,    12,     5,     5,    10,     6 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0    };

