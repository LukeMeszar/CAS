# $Id: Makefile.in,v 1.2 2001/11/23 23:30:36 waite Exp $
# Copyright 1993, The Regents of the University of Colorado

CC	= gcc
LIBS	= 
LDFLAGS	= 

DIR	= pkg/adtinit/src
SRC	=
AUX	= adtinit.c transl.c Makefile.in Makefile
CMD	=
GEN	=
EXE	= adtinit.exe transl.exe

# $Id: toolmk.h,v 1.27 2010/07/26 08:55:25 profw Exp $
# Skeleton for Tool Makefile

# The following make macros should be defined in order to use this skeleton:
#
# DIR=pathname of this directory relative to the Eli directory
# SRC=distributed files or directories needed during execution of Eli
# AUX=distributed files or directories not needed during execution of Eli
# CMD=command files needed during execution of Eli
# EXE=executable files needed during execution of Eli
# GEN=files or directories generated but not installed
# GENINS=files or directories generated and installed
# SRCDIR=subdirectories needed during execution of Eli
# AUXDIR=subdirectories not needed during execution of Eli
# PREDIR=subdirectories that need to do pre-distribution steps
#
# NOTE:  make is run on each SRCDIR, AUXDIR, and PREDIR subdirectory,
#        but not on any SRC, AUX or GEN directories

SHELL	= /bin/sh

ELILIB	= $(ELISYS)/pkg/eli

TIDY	= core a.out *.o *~ ERRS *.a $(GEN)
CLEAN	= $(EXE) $(GENINS)

all:	alldir $(SRC) $(CMD) $(EXE) $(GEN) $(GENINS)

install:
	@if test "$(DESTDIR)" = ''; \
	then \
		echo "A destination directory is required for install:"; \
		echo "   $(MAKE) install DESTDIR=destination directory"; \
		exit 1; \
	else :; fi
	@L='$(SRC) $(GENINS)'; \
        if test "$$L" != ' '; then for f in $$L; do \
		echo install -m 644 $$f $(DESTDIR); \
		if test -d $$f; then \
			for i in `find $$f -type d -print`; do \
				if test ! -d $(DESTDIR)/$$i; then \
					umask 002; mkdir $(DESTDIR)/$$i; \
				else :; \
				fi; \
			done; \
			for i in `find $$f -type f -print`; do \
			  cmp -s $$i $(DESTDIR)/$$i || cp $$i $(DESTDIR)/$$i; \
			done; \
		else \
			cmp -s $$f $(DESTDIR)/$$f || cp $$f $(DESTDIR)/$$f; \
		fi; \
		chmod -R u+rw,go-w,go+r $(DESTDIR)/$$f || true; \
		done; else :; fi
	@L='$(EXE) $(CMD)'; \
	if test "$$L" != ' '; then for f in $$L; do \
		echo install -m 755 $$f $(DESTDIR); \
		cmp -s $$f $(DESTDIR)/$$f || cp $$f $(DESTDIR)/$$f; \
		chmod 755 $(DESTDIR)/$$f || true; \
		done; else :; fi
	@L='$(SRCDIR)'; \
	if test "$$L" != ''; then for d in $$L; do \
		if test ! -d $(DESTDIR)/$$d; \
			then umask 002; mkdir $(DESTDIR)/$$d; \
			else :; \
			fi; \
		done; else :; fi
	@L='$(SRCDIR)'; \
	if test "$$L" != ''; then for d in $$L; do \
		if test -r $$d/Makefile; \
		then \
			echo; echo Installing $(DIR)/$$d; \
			DESTDIR="$(DESTDIR)/$$d" export DESTDIR; \
			(cd ./$$d; $(MAKE) DESTDIR=$$DESTDIR install); \
		else \
			echo; echo Copying $(DIR)/$$d; \
			for i in `find $$d -type d -print`; do \
				if test ! -d $(DESTDIR)/$$i; then \
					umask 002; mkdir $(DESTDIR)/$$i; \
				else :; \
				fi; \
			done; \
			for i in `find $$d -type f -print`; do \
			  cmp -s $$i $(DESTDIR)/$$i || cp $$i $(DESTDIR)/$$i; \
			done; \
		fi; done; \
	else :; fi

executable:
	@L='$(SRCDIR)'; \
	if test "$$L" != ''; then for d in $$L; do \
		if test -r $$d/Makefile; \
		then \
			echo " "; echo Making $(DIR)/$$d executable; \
			(cd ./$$d; $(MAKE) executable); \
		else :; fi; done; \
	else :; fi
	rm -rf $(TIDY) $(AUX) $(AUXDIR)

tidy:
	@L='$(SRCDIR) $(AUXDIR)'; \
	if test "$$L" != ' '; then for d in $$L; do \
		if test -r $$d/Makefile; \
		then \
			echo; echo Tidying $(DIR)/$$d; \
			(cd ./$$d; $(MAKE) tidy) || exit 1; \
		else :; fi; done; \
	else :; fi
	rm -rf $(TIDY)

clean:
	@L='$(SRCDIR) $(AUXDIR)'; \
	if test "$$L" != ' '; then for d in $$L; do \
		if test -r $$d/Makefile; \
		then \
			echo; echo Cleaning $(DIR)/$$d; \
			(cd ./$$d; $(MAKE) clean); \
		else :; fi; done; \
	else :; fi
	rm -rf $(TIDY) $(CLEAN)

alldir:
	@L='$(SRCDIR) $(AUXDIR)'; \
	if test "$$L" != ' '; then for d in $$L; do \
		if test -r $$d/Makefile; \
		then \
			echo; echo Making $(DIR)/$$d; \
			(cd ./$$d; \
			$(MAKE) DESTDIR=$(DESTDIR) ELISYS=$(ELISYS) \
				CC="$(CC)" ) || exit 1; \
		else :; fi; done; \
	else :; fi

predist:
	@L='$(PREDIR)'; \
	if test "$$L" != ' '; then for d in $$L; do \
		if test -r $$d/Makefile; \
		then \
			echo; echo Pre-disting $(DIR)/$$d; \
			(cd ./$$d; \
			$(MAKE) DESTDIR=$(DESTDIR) ELISYS=$(ELISYS) \
				ELIDOC="$(ELIDOC)" predist) || exit 1; \
		else :; fi; done; \
	else :; fi
# $Id: Adtmk.h,v 1.6 2001/05/09 20:43:04 waite Exp $
# Abstract data type library

ADTLIB	= $(ELISYS)/pkg/Adt
ADTINCL	= -I$(ADTLIB) -I$(ELILIB)

csm.o:	$(ADTLIB)/csm.c $(ADTLIB)/csm.h $(ELILIB)/eliproto.h
	$(CC) $(CFLAGS) $(ADTINCL) -c $(ADTLIB)/csm.c

obstack.o:	$(ADTLIB)/obstack.c $(ADTLIB)/obstack.h
	$(CC) $(CFLAGS) $(ADTINCL) -c $(ADTLIB)/obstack.c
# $Id: Inputmk.h,v 1.5 2008/04/26 14:21:19 profw Exp $
# Input library

INPLIB	= $(ELISYS)/pkg/Input
INPINCL	= -I$(INPLIB) -I$(ELILIB)

err.o:	$(INPLIB)/err.c $(INPLIB)/err.h $(INPLIB)/source.h $(ELILIB)/eliproto.h
	$(CC) $(CFLAGS) $(INPINCL) -c $(INPLIB)/err.c

source.o:	$(INPLIB)/source.c $(INPLIB)/source.h
	$(CC) $(CFLAGS) $(INPINCL) -c $(INPLIB)/source.c
# $Id: Scanmk.h,v 1.7 2008/04/26 14:21:19 profw Exp $
# Scanner library

SCNLIB	= $(ELISYS)/pkg/Scan
GLAPKG	= $(ELISYS)/pkg/gla

SCNINCL	= -I$(SCNLIB) -I$(GLAPKG) $(INPINCL) $(ADTINCL)

CchStr.o:	$(SCNLIB)/CchStr.c $(GLAPKG)/gla.h $(INPLIB)/source.h
CchStr.o:	$(INPLIB)/err.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/CchStr.c

Ccomment.o:	$(SCNLIB)/Ccomment.c $(GLAPKG)/gla.h $(INPLIB)/source.h
Ccomment.o:	$(INPLIB)/err.h $(GLAPKG)/tabsize.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/Ccomment.c

M2chStr.o:	$(SCNLIB)/M2chStr.c $(GLAPKG)/gla.h $(INPLIB)/source.h
M2chStr.o:	$(INPLIB)/err.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/M2chStr.c

M2int.o:	$(SCNLIB)/M2int.c
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/M2int.c

M3comment.o:	$(SCNLIB)/M3comment.c $(GLAPKG)/gla.h $(INPLIB)/source.h
M3comment.o:	$(INPLIB)/err.h $(GLAPKG)/tabsize.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/M3comment.c

auxEOF.o:	$(SCNLIB)/auxEOF.c
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/auxEOF.c

auxNUL.o:	$(SCNLIB)/auxNUL.c $(GLAPKG)/gla.h $(INPLIB)/source.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/auxNUL.c

auxNewLine.o:	$(SCNLIB)/auxNewLine.c $(GLAPKG)/gla.h $(INPLIB)/err.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/auxNewLine.c

auxScanEOL.o:	$(SCNLIB)/auxScanEOL.c $(GLAPKG)/gla.h $(INPLIB)/source.h
		$(INPLIB)/err.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/auxScanEOL.c

auxTab.o:	$(SCNLIB)/auxTab.c $(GLAPKG)/gla.h $(GLAPKG)/tabsize.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/auxTab.c

coordAdjust.o:	$(SCNLIB)/coordAdjust.c $(GLAPKG)/gla.h $(INPLIB)/err.h
coordAdjust.o:	$(GLAPKG)/tabsize.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/coordAdjust.c

dflteot.o:	$(SCNLIB)/dflteot.c
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/dflteot.c

dfltscan.o:	$(SCNLIB)/dfltscan.c
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/dfltscan.c

idn.o:	$(SCNLIB)/idn.c $(INPLIB)/err.h $(SCNLIB)/idn.h $(ADTLIB)/csm.h \
	$(ELILIB)/eliproto.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/idn.c

int.o:	$(SCNLIB)/int.c
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/int.c

pascalCom.o:	$(SCNLIB)/pascalCom.c $(GLAPKG)/gla.h $(INPLIB)/source.h
pascalCom.o:	$(INPLIB)/err.h $(GLAPKG)/tabsize.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/pascalCom.c

pascalStr.o:	$(SCNLIB)/pascalStr.c $(GLAPKG)/gla.h $(INPLIB)/err.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/pascalStr.c

str.o:	$(SCNLIB)/str.c $(ADTLIB)/csm.h
	$(CC) $(CFLAGS) $(SCNINCL) -c $(SCNLIB)/str.c

transl.exe:	transl.c
	$(CC) -o $@ $(CFLAGS) $? $(LDFLAGS) $(LIBS)

CFLAGS  = -DSAVE -DNORESTORE

OBJ	= adtinit.o csm.o idn.o err.o source.o obstack.o

adtinit.exe:	$(OBJ)
	$(CC) -o adtinit.exe $(CFLAGS) $(OBJ) $(LDFLAGS) $(LIBS)

adtinit.o:	adtinit.c $(ADTLIB)/csm.h $(ADTLIB)/obstack.h
adtinit.o:	$(INPLIB)/err.h $(INPLIB)/source.h $(SCNLIB)/idn.h
	$(CC) $(CFLAGS) $(ADTINCL) $(INPINCL) $(SCNINCL) -c adtinit.c

csm.o:	$(ADTLIB)/csmtbl.h
idn.o:	$(SCNLIB)/idntbl.h
