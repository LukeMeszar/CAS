# $Id: Makefile.in,v 1.3 2002/10/01 20:37:59 waite Exp $
# Copyright (c) 1991, The Regents of the University of Colorado

CC	= gcc
LIBS	= 
LDFLAGS	= 

DIR	= pkg/skeleton/src
SRC	=
AUX	= map_errors.c err_tab.c err_map.c mk_include.c get_incl.c \
	  type_sel.c cat-n.c fmt.c eliexpand.c paste.c vtd.c line_err.c \
	  Makefile Makefile.in
CMD	=
EXE	= map_errors.exe err_tab.exe err_map.exe mk_include.exe \
	  get_incl.exe type_sel.exe cat-n.exe fmt.exe eliexpand.exe \
	  paste.exe vtd.exe rel_err.exe line_err.exe
GEN	=
GENINS	=
SRCDIR	=
AUXDIR	=

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

CFLAGS	=

get_incl.o:	get_incl.c $(ADTLIB)/obstack.h $(INPLIB)/source.h
	$(CC) $(CFLAGS) $(ADTINCL) $(INPINCL) -c get_incl.c

get_incl.exe:	get_incl.o obstack.o source.o
	$(CC) $(CFLAGS) -o get_incl.exe get_incl.o obstack.o source.o

err_map.o:	err_map.c $(ADTLIB)/obstack.h
	$(CC) $(CFLAGS) $(ADTINCL) -c err_map.c

err_map.exe:	err_map.o obstack.o
	$(CC) $(CFLAGS) -o err_map.exe err_map.o obstack.o

.SUFFIXES:      .exe
.c.exe:
	$(CC) $(CFLAGS) -o $@ $*.c $(LDFLAGS) $(LIBS)
