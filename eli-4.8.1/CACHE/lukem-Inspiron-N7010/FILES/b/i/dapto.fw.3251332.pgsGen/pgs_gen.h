/* Date should go here */
#define    ZEMAXTERMINALCODE 16
#define    ZEMAXRSLAENGE     7
#define    ZEANZZST          35
#define    ZEMAXTEINTRAG     101
#define    ZEMAXNTEINTRAG    46
#define    ZEMAXTE1          35
#define    ZEMAXTE2          68
#define    ZEMAXNTE          35
#define    ZEANZNT           21
#define    ZEANZPROD         33
#define    ZEMAXTNEXT        36
#define    ZEMAXTCHECK       45
#define    ZEMAXNTNEXT       37
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     2,     1,     0,     0,     0,     0,
    7,    11,    12,     8,    17,    16,    16,    18,    18,    18,
    0,    14,    20,    26,     0,     0,    22,     0,    20,     2,
   24,    27,     0,    21,    29,    25 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,    81,     2,    82,     6,    32,    50,    35,    95,     7,
   97,    14,     8,    58,    27,    51,     9,    85,    16,    54,
   55,    53,    18,    19,    21,    22,    89,    59,    93,    61,
   63,    47,    65,    66,    67,    68,    57 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,     3,     1,     4,     5,    25,     6,    29,    25,     6,
   29,    10,     6,    20,    20,     6,     6,    11,    12,    13,
   14,    11,    15,    16,    17,    18,    19,    21,    22,    23,
   26,    28,    30,    31,    33,    34,    35,     0,     0,     0,
    0,     0,     0,     0,     0,     0 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,     0,    28,     1,     0,     0,     0,    28,    28,    28,
    6,     0,     0,     0,     0,     0,     0,     0,     0,    35,
    0,     0,    35,     0,    28,     0,     0,    35,     0,     0,
    0,     0,    35,     0,     0,     0 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     0,     6,     0,     0,     0,     8,    21,    24,
    2,    17,     0,    17,     0,     0,    17,     0,    23,     9,
    0,     0,     0,     0,    30,     0,     0,    27,    32,     0,
    0,     0,    15,     0,     0,     7 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     4,     3,    36,     5,    10,    29,    44,    28,
   37,    30,    38,    11,    38,    46,    28,    39,    24,    39,
   40,    41,    42,    41,    24,    26,    12,    25,    43,    13,
   15,    17,    20,    23,    45,    31,    33,    34 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,     3,     3,    20,    20,     6,    20,     6,    18,     7,
   18,     7,     5,     2,     1,    20,    20,    13,    13,    14,
    4,    16,     9,    17,    21,    11,    12,    16,    15,    11,
   10,    19,    17,     8 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     1,     2,     1,     1,     1,     1,     2,     1,     1,
    3,     3,     1,     1,     1,     1,     1,     0,     1,     1,
    6,     0,     1,     5,     5,     0,     6,     1,     3,     1,
    3,     3,     7,     3 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,     2,    11,     1,     1,     3,     6,    11,    11,    11,
    4,     6,     6,    11,     3,     6,     7,     6,     7,     8,
   13,    13,     8,     3,    11,     8,     8,    11,    11,     8,
    8,     6,    11,    13,     6,    11 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,     2,    11,     1,     1,     3,     6,    11,    11,    11,
    4,     6,     6,    11,     3,     6,     7,     6,     7,     8,
   13,    13,     8,     3,    11,     8,     8,    11,    11,     8,
    8,     6,    11,    13,     6,    11 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2   ,  0X0    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0   ,  0X0    };

