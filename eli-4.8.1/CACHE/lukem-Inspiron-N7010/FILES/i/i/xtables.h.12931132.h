#define NONLITCOUNT 5
#define LITCOUNT 8
#define NTOKENS 13
#define EOFTOKEN 1
#if defined(__cplusplus) || defined(__STDC__)
extern void mkidn(const char *, int, int *, int *),
 mkint(const char *, int, int *, int *),
 mkidn(const char *, int, int *, int *),
 dummy1(char *, int, int *, int *);
#else
extern void mkidn(),
 mkint(),
 mkidn(),
 dummy1();
#endif
#if defined(__cplusplus) || defined(__STDC__)
extern char *auxCComment(char *, int),
 *auxEOL(char *, int),
 *dummy2(char *, int);
#else
extern char *auxCComment(),
 *auxEOL(),
 *dummy2();
#endif
#ifdef MONITOR
int mon_nonlit_codes[] = {
 6,
 12,
 3,
 15001,
 15001,
 -1
};
CONST char *mon_token_names[] = {
 "Identifier",
 "Integer",
 "String",
 "",
 "",
 ""
};
#endif

static short CaseTbl[256] = {
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  2,  3,  0,  0,  4,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  1,  0, 11, 10,  0,  0,  0,  0, 
 12, 12,  0,  0, 12,  0,  0,  9, 
  6,  6,  6,  6,  6,  6,  6,  6, 
  6,  6,  8, 12,  0,  0,  0,  0, 
  0,  5,  5,  7,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  0,  0,  0,  0,  5, 
  0,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0};

static short ExtCodeTbl[256] = {
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  9, 10,  0,  0,  2,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  5,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0};

static unsigned char ScanTbl[] = {
0x00, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x42, 0x44, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x41, 0x40, 0x00, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF8, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xC8,
0xE8, 0xE8, 0xE8, 0x68,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0x40,
0x40, 0x40, 0x40, 0xE8,
0x40, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0xE8,
0xE8, 0xE8, 0xE8, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x40, 0x40, 0x40, 0x40,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x00, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x00,
0x00, 0x00, 0x00, 0x01,
0x00, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00 };
