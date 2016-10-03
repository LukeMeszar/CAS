/* Date should go here */
#define    ZEMAXTERMINALCODE 20
#define    ZEMAXRSLAENGE     5
#define    ZEANZZST          16
#define    ZEMAXTEINTRAG     72
#define    ZEMAXNTEINTRAG    23
#define    ZEMAXTE1          16
#define    ZEMAXTE2          44
#define    ZEMAXNTE          16
#define    ZEANZNT           11
#define    ZEANZPROD         28
#define    ZEMAXTNEXT        46
#define    ZEMAXTCHECK       53
#define    ZEMAXNTNEXT       15
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,     0,    29,     5,     0,    25,     5,     6,     0,    17,
    0,     0,     0,     0,     9,     6,    33 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,    52,    28,    33,    34,    52,    55,    29,    30,    52,
    9,    38,    52,    31,    52,    63,    63,    63,    63,    63,
   63,    39,    40,    41,    42,    43,    44,    28,    14,    32,
   53,    11,    12,    13,    26,    36,     0,     0,     4,     0,
    0,     7,     0,     6,     0,     0,    65 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,     1,    10,    10,    10,     1,     3,     6,     7,     1,
    4,    14,     1,     8,     1,    10,    10,    10,    10,    10,
   10,    15,    15,    15,    15,    15,    15,     5,     9,     9,
    2,     5,     5,     5,     2,    16,     0,     0,     2,     0,
    0,     2,     0,     2,     0,     0,    16,     0,     0,     0,
    0,     0,     0,     0 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,    16,    16,    16,     0,     0,     0 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
    0,     0,     3,    10,     0,     3,    12 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     3,    20,    15,    19,    21,     5,     8,     2,
   17,    18,    10,    22,    16,    23 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,     8,     6,     6,     8,     8,     8,    10,     9,     2,
    7,     1,     5,     8,     8,     9,     8,     4,     4,     4,
    3,     3,     8,    11,    11,    11,    11,    11,    11 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     1,     1,     2,     3,     3,     3,     5,     0,     1,
    1,     1,     1,     2,     2,     3,     3,     1,     1,     0,
    1,     0,     4,     1,     1,     1,     1,     1,     1 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,    10,     8,     2,     2,    13,    12,
   15,    13,    13,    13,     2,    20,    13 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,    10,     8,     2,     2,    13,    12,
   15,    13,    13,    13,     2,    20,    13 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2   ,  0X0    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0   ,  0X0    };

