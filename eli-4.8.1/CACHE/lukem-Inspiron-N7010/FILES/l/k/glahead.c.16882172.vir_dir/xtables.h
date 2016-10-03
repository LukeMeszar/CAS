#define NONLITCOUNT 4
#define LITCOUNT 28
#define NTOKENS 32
#define EOFTOKEN 1
#if defined(__cplusplus) || defined(__STDC__)
extern void mkidn(const char *, int, int *, int *),
 c_mkint(const char *, int, int *, int *),
 mkstr(const char *, int, int *, int *),
 dummy1(char *, int, int *, int *);
#else
extern void mkidn(),
 c_mkint(),
 mkstr(),
 dummy1();
#endif
#if defined(__cplusplus) || defined(__STDC__)
extern char *auxCComment(char *, int),
 *dummy2(char *, int);
#else
extern char *auxCComment(),
 *dummy2();
#endif
#ifdef MONITOR
int mon_nonlit_codes[] = {
 12,
 23,
 22,
 15001,
 -1
};
CONST char *mon_token_names[] = {
 "Identifier",
 "IntDenotation",
 "FloatDenotation",
 "",
 ""
};
#endif

static short CaseTbl[256] = {
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  2,  3,  0,  0,  4,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  1, 20,  0,  0,  0, 20, 19,  0, 
 20, 20, 20, 20, 20, 20, 18, 17, 
 16,  6,  6,  6,  6,  6,  6,  6, 
  6,  6, 20, 20, 20, 15, 20, 20, 
  0,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  5,  5,  5,  5,  5, 
  5,  5,  5,  0,  0,  0,  0,  5, 
  0,  5, 14, 13,  5, 12, 11,  5, 
  5, 10,  5,  5,  5,  5,  5,  5, 
  5,  5,  9,  5,  5,  5,  5,  8, 
  5,  5,  5, 20,  7, 20,  0,  0, 
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
  0, 16,  0,  0,  0, 15,  0,  0, 
 20, 21, 14,  3, 19,  2,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  9, 26, 24,  0, 25,  8, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  0,  0,  0,  0,  0, 
  0,  0,  0,  6,  0,  7,  0,  0, 
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
0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0xD8, 0xD8, 0xD8, 0xD8,
0xD8, 0xD8, 0xD8, 0xD8,
0xD8, 0xD8, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0xC8, 0xC8, 0xC8,
0xC8, 0xE8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0x00,
0x00, 0x00, 0x00, 0xC8,
0x00, 0xC8, 0xC8, 0xC8,
0xC8, 0x68, 0xC8, 0xC8,
0x88, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0xC8,
0xC8, 0xC8, 0xC8, 0x00,
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
0x00, 0x00, 0x00, 0x40,
0x00, 0x40, 0x00, 0x00,
0x8F, 0x8F, 0x8F, 0x8F,
0x8F, 0x8F, 0x8F, 0x8F,
0x8F, 0x8F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x8F, 0x8F, 0x8F,
0x8F, 0x8F, 0xAF, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F,
0x2F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F,
0x1F, 0x0F, 0x0F, 0x00,
0x00, 0x00, 0x00, 0x0F,
0x00, 0x8F, 0x8F, 0x8F,
0x8F, 0x8F, 0xAE, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F,
0x2D, 0x0F, 0x0E, 0x0B,
0x0F, 0x0F, 0x07, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F,
0x1F, 0x0F, 0x0F, 0x00,
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
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x00,
0x00, 0x00, 0x00, 0x7F,
0x00, 0x7E, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x6F, 0x7F, 0x7D,
0x7F, 0x7F, 0x7B, 0x7F,
0x7F, 0x7F, 0x7F, 0x3F,
0x77, 0x5F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x00,
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
