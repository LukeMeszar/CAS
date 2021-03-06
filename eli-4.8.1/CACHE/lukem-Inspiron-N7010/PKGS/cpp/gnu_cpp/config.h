/* config.h.  Generated from config.h.in by configure.  */
/* $Id: config.h.in,v 1.1.1.1 2001/04/26 20:01:49 waite Exp $ */

/* Do we have header files? */
#define STDC_HEADERS 1
#define HAVE_FCNTL_H 1
#define HAVE_MALLOC_H 1
#define HAVE_SYS_FILE_H 1
#define HAVE_SYS_TIME_H 1
#define HAVE_UNISTD_H 1

/* typedefs, structures, and compiler characteristics */
/* #undef const */
/* #undef size_t */
/* #undef TM_IN_SYS_TIME */

/* Library functions */
#define HAVE_MEMCPY 1
#define HAVE_STRCHR 1

/* Library function characteristics */
#define RETSIGTYPE void

#define GCC_INCLUDE_DIR 	"/usr/include"
#define GPLUSPLUS_INCLUDE_DIR 	"/usr/include"

/* Names to predefine in the preprocessor for this target machine.
 *   None are interesting for Eli specification languages
 */
#define CPP_PREDEFINES ""

/* number of bits in an addressible storage unit */
#define BITS_PER_UNIT 8

/* Defined if C++ comments are to be stripped
 *   // is a valid EBNF operator, so we don't want this for Eli
 */
/* #undef CPLUSPLUS */

/* Define results of standard character escape sequences.  */
#define TARGET_BELL 007
#define TARGET_BS 010
#define TARGET_TAB 011
#define TARGET_NEWLINE 012
#define TARGET_VT 013
#define TARGET_FF 014
#define TARGET_CR 015

/* Why not? */
#define DOLLARS_IN_IDENTIFIERS 1

/* Allow #sscs (but don't do anything). */
#define SCCS_DIRECTIVE

/* #defines that need visibility everywhere.  */
#define FALSE 0
#define TRUE 1

/* Arguments to use with `exit'.  */
#define SUCCESS_EXIT_CODE 0
#define FATAL_EXIT_CODE 33

/* If compiled with GNU C, use the built-in alloca */
#define HAVE_ALLOCA_H 0

/* Decide whether or not to use function prototypes */
#if defined(__cplusplus) || defined(__STDC__) || defined(__ANSI__) || \
    defined(__GNUC__) || defined(__STRICT_ANSI__)

#define PROTO_OK 1

#else
  
#ifdef PROTO_OK
/* #undef PROTO_OK */
#endif

#endif
