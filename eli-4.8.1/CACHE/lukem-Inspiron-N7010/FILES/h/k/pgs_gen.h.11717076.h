/* Date should go here */
#define    ZEMAXTERMINALCODE 18
#define    ZEMAXRSLAENGE     8
#define    ZEANZZST          30
#define    ZEMAXTEINTRAG     104
#define    ZEMAXNTEINTRAG    40
#define    ZEMAXTE1          30
#define    ZEMAXTE2          67
#define    ZEMAXNTE          30
#define    ZEANZNT           21
#define    ZEANZPROD         37
#define    ZEMAXTNEXT        75
#define    ZEMAXTCHECK       83
#define    ZEMAXNTNEXT       35
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,    56,    57,    42,    10,    35,    61,     1,    16,     0,
   45,    43,    25,    22,    18,    20,    24,     0,    57,    23,
    0,    47,    59,    62,    37,    12,     0,    57,    43,    58,
   65 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,    93,    28,    93,    93,    93,    25,    57,    93,    93,
   93,    81,     9,   100,    97,   100,   100,   100,    93,    64,
  100,   100,   100,    17,    15,    91,    89,    10,    16,    91,
  100,    91,    92,    24,    89,    89,    91,    27,    53,    91,
   88,    88,    45,    80,    46,    88,    88,    88,    88,    88,
   49,    80,    50,    88,    88,    88,    13,    78,    79,    14,
   26,    29,    84,    88,    98,    78,    79,    62,    78,     5,
   48,    95,    65,    66,    59,    67 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,    17,    20,    17,    17,    17,    17,    17,    17,    17,
   17,     4,     7,    25,    20,    25,    25,    25,    17,    25,
   25,    25,    25,    15,    15,    13,    12,     8,    15,    13,
   25,    13,    14,    16,    12,    12,    13,    19,    15,    13,
   24,    24,     5,     3,     5,    24,    10,    24,    10,    10,
   28,     3,    28,    10,    10,    24,    11,     1,     2,    11,
   18,    21,     6,    10,    22,     1,     2,    23,     1,     2,
    6,    18,    27,    29,    18,    30,     0,     0,     0,     0,
    0,     0,     0,     0 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     0,     0,     0,     0,     0,    28,
    0,     0,    15,     0,    28,     0,     0,     0,    28,     0,
    0,     0,    15,     0,     0,     0,    28,     0,     0,     0,
    0 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     1,     0,     0,     7,     0,     0,     0,    20,
    0,     0,    17,     2,     0,     0,     0,     0,    14,     0,
    0,     0,    18,     0,     9,     0,    23,     0,    24,     0,
    0 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     4,    20,    20,     6,    33,    12,    22,    22,
   23,    34,     8,    32,    21,     3,    12,     2,    36,    31,
   30,    19,    18,     7,    11,    35,    38,    39,    40,     0,
    0,     0,     0,     0,     0,    37 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,    17,     2,     5,     6,     7,    21,    20,     9,    21,
    3,    17,    15,     5,     1,    16,    16,    13,    12,     4,
    4,     7,    11,     8,    20,    14,     8,     8,    19,    21,
   14,    10,     8,     8,     8,    18,    18,     8 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     2,     2,     2,     3,     2,     1,     2,     2,     2,
    3,     0,     1,     0,     1,     1,     1,     1,     1,     1,
    1,     0,     1,     1,     0,     0,     1,     2,     1,     1,
    1,     1,     3,     2,     3,     8,     8,     4 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,     1,     9,     1,    11,    11,     9,
    1,    16,     1,     3,    14,    18,     9,     1,    14,    14,
   14,    14,     5,     5,     3,     1,     9,    15,     9,    15,
   10 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,     1,     9,     1,    11,    11,     9,
    1,    16,     1,     3,    14,    18,     9,     1,    14,    14,
   14,    14,     5,     5,     3,     1,     9,    15,     9,    15,
   10 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2   ,  0X0    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0   ,  0X0    };

