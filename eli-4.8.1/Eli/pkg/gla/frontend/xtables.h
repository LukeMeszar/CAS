#define NONLITCOUNT 4
#define LITCOUNT 12
#define NTOKENS 16
#define EOFTOKEN 1
#if defined(__cplusplus) || defined(__STDC__)
extern void mkidn(const char *, int, int *, int *),
 mkint(const char *, int, int *, int *),
 mkstr(const char *, int, int *, int *),
 dummy1(char *, int, int *, int *);
#else
extern void mkidn(),
 mkint(),
 mkstr(),
 dummy1();
#endif
#if defined(__cplusplus) || defined(__STDC__)
extern char *auxPascalComment(char *, int),
 *dummy2(char *, int);
#else
extern char *auxPascalComment(),
 *dummy2();
#endif
#ifdef MONITOR
int mon_nonlit_codes[] = {
 3,
 14,
 4,
 15001,
 -1
};
CONST char *mon_token_names[] = {
 "Identifier",
 "Integer",
 "RegularExpr",
 "",
 ""
};
#endif

static short CaseTbl[256] = {
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  2,  3,  0,  0,  4,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  1,  0,  0,  0, 10,  9,  0,  0, 
  8, 11,  0, 11,  0, 11,  0,  0, 
  6,  6,  6,  6,  6,  6,  6,  6, 
  6,  6, 11,  0,  0,  0,  0, 11, 
  0,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5, 11,  0, 11,  0,  5, 
  0,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  7,  0,  0,  0,  0, 
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
  0,  7,  0, 15,  0, 13,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  5,  0,  0,  0,  0, 16, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0, 11,  0, 12,  0,  0, 
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
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x02, 0x04, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x01, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x38, 0x38, 0x38, 0x38,
0x38, 0x38, 0x38, 0x38,
0x38, 0x38, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x20,
0x20, 0x20, 0x20, 0x28,
0x20, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x28,
0x28, 0x28, 0x28, 0x20,
0x20, 0x20, 0x20, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20 };