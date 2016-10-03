/* Date should go here */
#define    ZEMAXTERMINALCODE 22
#define    ZEMAXRSLAENGE     7
#define    ZEANZZST          86
#define    ZEMAXTEINTRAG     248
#define    ZEMAXNTEINTRAG    125
#define    ZEMAXTE1          86
#define    ZEMAXTE2          167
#define    ZEMAXNTE          86
#define    ZEANZNT           53
#define    ZEANZPROD         81
#define    ZEMAXTNEXT        118
#define    ZEMAXTCHECK       134
#define    ZEMAXNTNEXT       110
#define    ZETINDEX          ZEMAXTERMINALCODE / M_BITS
#define    ZESTOPSYMBOL      1
static  K_TYP1    TBase[ ZEANZZST + 1]  =
{   0,     0,    15,    72,    59,    43,     0,    60,    61,    74,
   75,    23,     0,    76,    31,    67,    72,    39,    78,     0,
    0,    83,     0,     0,     0,     0,    11,    83,    83,    85,
   68,    84,    26,    88,    86,     0,     0,    76,    37,    65,
   88,    81,    92,     0,    89,    95,    91,    83,    64,    69,
   85,     0,     0,     2,    88,    44,    45,     0,    98,     0,
    0,     0,     0,     2,    99,   103,    53,    59,   104,    59,
  101,   102,     0,     0,   108,     0,    45,   107,   105,    34,
  109,   107,   106,   112,   108,     0,   103 };

static  K_TYP1    TNext[ ZEMAXTNEXT + 1]  =
{   0,   207,    21,   216,   238,    35,   239,   238,   207,   239,
  207,   207,   207,    41,   207,   225,   208,   142,    36,   238,
  238,   239,   239,     4,   215,     5,     6,     7,    45,     8,
  228,   215,   217,   215,   215,   215,    83,   215,   247,   217,
  218,   217,   217,   217,   149,   217,   211,   218,   236,   218,
  218,   218,   221,   218,    56,    57,    51,    52,   131,   240,
  156,    74,   241,   240,   240,   242,    30,    54,   152,   242,
  242,    61,   231,   209,   129,   132,   133,    18,    19,    22,
   24,    25,    28,    51,    52,   211,   234,    42,    43,    44,
  145,   146,    46,   148,    53,   151,   138,    55,    59,   222,
   60,    53,   154,   143,    70,    71,    72,    75,   162,   163,
  236,    82,   165,    84,   167,    85,   245,    86,   139 };

static  K_TYP1    TCheck[ ZEMAXTCHECK + 1]  =
{   0,     1,    12,    12,    62,    53,    63,    62,     1,    63,
    1,     1,     1,    26,     1,    26,     2,    53,    53,    62,
   62,    63,    63,     2,    11,     2,     2,     2,    32,     2,
   32,    11,    14,    11,    11,    11,    79,    11,    79,    14,
   17,    14,    14,    14,    38,    14,     5,    17,    56,    17,
   17,    17,    76,    17,    55,    55,    38,    38,     5,    66,
   56,    67,    67,    66,    66,    69,    76,    39,    48,    69,
   69,    49,    39,     3,     4,     7,     8,     9,    10,    13,
   15,    16,    18,    48,    48,    21,    49,    27,    28,    29,
   30,    31,    33,    34,    37,    40,    41,    42,    44,    45,
   46,    47,    50,    54,    58,    64,    65,    68,    70,    71,
   74,    77,    78,    80,    81,    82,    83,    84,    86,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0 };

static  K_TYP1    TZDefault[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
    0,     5,     0,     0,    21,     0,     0,     8,    41,    86,
   76,     5,    45,    76,    53,    54,     0,     0,     0,     0,
    0,     0,     0,     0,     0,    53,    86,    38,     0,     0,
    0,     0,     0,    55,     0,    86,     0,    48,     0,     0,
    0,    53,    53,     0,     0,     0,     0,    74,    55,    86,
   86,    86,    47,    47,    55,     0,    56,     0,     0,    74,
    0,     0,    86,    76,    56,    83,     0,     0,     0,     0,
    0,     0,     0,    86,     0,    86,     0 };



static  K_TYP1    NtBase[ ZEANZZST + 1]  =
{   0,     0,     0,     0,     5,    30,     2,    59,    31,    11,
   63,    48,     0,    42,    22,     0,     0,    35,     0,    83,
    8,    67,     2,    79,     6,     0,     0,     0,     0,     0,
    0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
    0,    51,     0,     0,     0,    10,     0,     0,     0,     0,
    0,     0,    11,    27,    53,    56,     0,     4,    78,    93,
   94,     6,     0,     0,    78,    86,    70,     0,    79,    13,
    0,     0,    75,    87,    90,    79,    89,     0,     0,     0,
    0,     0,     0,    81,     0,   100,   101 };

static  K_TYP1    NtNext[ ZEMAXNTNEXT + 1]  =
{   0,     1,     3,     0,   105,    33,    32,    58,    27,    87,
  105,   112,    65,   109,    32,     9,   113,    96,   108,    66,
   68,    67,    31,    26,    69,   113,   114,    93,    88,    68,
   67,     2,    49,   106,    89,   120,    38,    14,    94,   118,
   12,    39,   104,   100,    90,    48,    40,    93,    91,    13,
  103,    62,    50,    62,    92,    10,   103,    37,    98,    37,
   12,   103,    63,    64,    63,   103,    47,    11,    47,    13,
   17,    95,    97,    10,   108,    99,    16,   103,   110,   121,
   16,   119,    65,    79,    80,    79,   123,   101,    15,    20,
   77,    23,   102,    34,   107,   111,   115,   116,   117,    73,
   76,    78,   122,    81,   124,   125,     0,     0,     0,     0,
   29 };

static  K_TYP1    LS[ ZEANZPROD + 1 ]  =
{   0,    34,    34,    31,    34,    34,    37,    38,    35,    39,
    9,    37,    35,    39,    23,    27,    38,    51,    41,    33,
   32,    23,     7,     3,    53,    41,    19,    17,    20,     7,
   26,    49,    32,    19,    20,    15,    17,     5,    13,    21,
   31,     2,     1,    10,    25,    25,    29,    45,    48,    47,
   48,    44,    43,     4,    14,     3,    50,    42,     8,    14,
   24,     3,    36,    28,    46,    40,    51,    52,    51,    12,
   12,    30,    30,    18,    16,    18,     6,     6,     5,    11,
    5,    22 };

static  K_TYP1    LaengeRS[ ZEANZPROD + 1 ]  =
{   0,     1,     1,     2,     1,     1,     1,     1,     1,     1,
    3,     2,     2,     2,     1,     1,     3,     1,     1,     1,
    1,     3,     1,     3,     3,     3,     1,     1,     1,     2,
    5,     5,     3,     2,     2,     1,     3,     3,     5,     5,
    0,     1,     1,     1,     0,     1,     1,     1,     2,     1,
    2,     2,     1,     1,     0,     0,     1,     1,     1,     2,
    4,     1,     4,     5,     1,     4,     3,     1,     3,     0,
    1,     3,     3,     2,     1,     2,     6,     7,     0,     4,
    1,     4 };

static  K_TYP1    FSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,    15,     3,     2,    15,    15,     3,
    3,     1,     3,     3,     1,    13,     9,     1,     4,    15,
    7,     2,     4,     7,    15,    15,     4,     4,     5,     4,
   22,     7,     4,     4,     7,    15,    15,     7,     7,     7,
    7,    15,     5,    11,     9,     4,     9,     4,     4,    17,
   17,    15,    15,    15,    15,    11,     3,     2,     6,    15,
   15,    15,     4,     4,     6,     3,     6,     3,     3,     6,
    7,     7,    15,     7,     2,     4,     7,     4,     7,     4,
    4,     7,     9,     4,     9,    15,    15 };

static  K_TYP1    RSymbol[ ZEANZZST + 1 ]  =
{   0,     1,     1,     1,    15,     3,     2,    15,    15,     3,
    3,     1,     3,     3,     1,    13,     9,     1,     4,    15,
    7,     2,     4,     7,    15,    15,     4,     4,     5,     4,
   22,     7,     4,     4,     7,    15,    15,     7,     7,     7,
    7,    15,     5,    11,     9,     4,     9,     4,     4,    17,
   17,    15,    15,    15,    15,    11,     3,     2,     6,    15,
   15,    15,     4,     4,     6,     3,     6,     3,     3,     6,
    7,     7,    15,     7,     2,     4,     7,     4,     7,     4,
    4,     7,     9,     4,     9,    15,    15 };

static  M_TYP    SemKlammer[ ZETINDEX + 1 ]  =
{0X2   ,  0X0    };

static  M_TYP    Ueberlesen[ ZETINDEX + 1 ]  =
{0X0   ,  0X0    };

