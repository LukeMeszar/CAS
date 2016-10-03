# $Id: Makefile.in,v 1.2 2002/05/08 15:00:49 waite Exp $
# 
# (C) Copyright 1997 University of Paderborn
# 
# /* This file is part of the Eli translator construction system.
# 
# Eli is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 2, or (at your option) any later
# version.
# 
# Eli is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
# 
# You should have received a copy of the GNU General Public License along
# with Eli; see the file COPYING.  If not, write to the Free Software
# Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
# 
# Makefile of Tool/cola/lalr/front/lalr

CC	=	gcc

DIR	=	pkg/cola/lalr/front/lalr
SRC	=
C_FILES = 	absparser.c parserlib.c ctx.c lr0.c lalr.c lalr1tst.c \
		mkiface.c printtbl.c purdom.c purdebug.c statistik.c \
		privatlib.c grammarcomp.c first1.c digraph.c \
		printst2ter.c
O_FILES = 	absparser.o parserlib.o ctx.o lr0.o lalr.o lalr1tst.o \
		mkiface.o printtbl.o purdom.o statistik.o \
		privatlib.o grammarcomp.o first1.o digraph.o \
		printst2ter.o
H_FILES = 	absparser.h parserlib.h ctx.h lr0.h lalr.h lalr1tst.h \
		mkiface.h printtbl.h lr0forpurdom.h purdom.h statistik.h \
		privatlib.h grammarcomp.h first1.h digraph.h \
		printst2ter.h
COP	=	$(C_FILES) $(H_FILES) Makefile.in
AUX	=	$(COP) Makefile
COM	=
CMD	=
RCS	=
EXE	=
GEN	=	lalr.a
GENINS	=	
SRCDIR	=
AUXDIR	=

IDL   = ../../../idl
LIB   = ../../../lib
FMT   = ../../../trafos/fmt

IHDRS = -I$(IDL) -I$(LIB) -I$(FMT)

# -DDEBUG_PRS, -DDEBUG_LR0, -DDEBUG_LALR,
# -DDEBUG_ABS, -DDEBUG_PUR: causes additional tests which can be helpful
#			    to search bugs
# -DDEBUG_FREEPOS: free positions are labeled with a connection
# -DSTATISTIK: to get more statistical informations
# ALLDEB =   -DDEBUG_PRS -DDEBUG_LR0 -DDEBUG_LALR -DDEBUG_ABS \
# 	     -DDEBUG_PUR -DDEBUG_FREEPOS -DSTATISTIK

CFLAGS  = $(ALLDEB) $(IHDRS)

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

lalr.a: $(O_FILES)
	rm -f $@
	ar rcu $@ $(O_FILES)
	ranlib $@

absparser.o:	$(IDL)/comar.h $(IDL)/name.h $(LIB)/cmrlib.h privatlib.h \
		grammarcomp.h absparser.h  \
		mkiface.h $(IDL)/prsiface.h lr0.h lalr.h lalr1tst.h printtbl.h


parserlib.o: 	privatlib.h $(LIB)/cmrlib.h $(LIB)/bitset.h \
		$(IDL)/comar.h \
	     	first1.h statistik.h parserlib.h


ctx.o:  privatlib.h $(LIB)/cmrlib.h $(LIB)/bitset.h \
	$(IDL)/comar.h statistik.h parserlib.h ctx.h


lr0.o:  $(IDL)/comar.h $(LIB)/cmrlib.h privatlib.h  \
	statistik.h parserlib.h lr0.h


lalr.o: $(IDL)/comar.h $(IDL)/prsiface.h \
	$(LIB)/cmrlib.h privatlib.h $(LIB)/bitset.h \
	absparser.h first1.h statistik.h parserlib.h ctx.h lalr.h


lalr1tst.o: $(IDL)/comar.h \
	    $(LIB)/cmrlib.h privatlib.h $(LIB)/bitset.h $(IDL)/name.h \
	    statistik.h parserlib.h lalr1tst.h


mkiface.o: $(IDL)/comar.h \
	   $(LIB)/cmrlib.h privatlib.h $(LIB)/bitset.h \
	   statistik.h parserlib.h $(IDL)/prsiface.h mkiface.h


printtbl.o:  $(IDL)/comar.h $(IDL)/name.h $(FMT)/format.h \
	     privatlib.h $(LIB)/cmrlib.h $(LIB)/bitset.h \
	     grammarcomp.h parserlib.h printtbl.h


purdom.o:  $(IDL)/comar.h $(IDL)/comar_func.h \
	   privatlib.h $(LIB)/cmrlib.h $(LIB)/bitset.h \
	   statistik.h parserlib.h ctx.h lr0forpurdom.h purdebug.c purdom.h


statistik.o:	$(IDL)/comar.h ctx.h parserlib.h statistik.h \
		privatlib.h $(LIB)/cmrlib.h

grammarcomp.o:	$(IDL)/comar.h $(IDL)/comar_func.h $(IDL)/name.h \
	$(LIB)/cmrlib.h $(FMT)/format.h privatlib.h first1.h grammarcomp.h

privatlib.o:  $(IDL)/comar.h $(LIB)/cmrlib.h privatlib.h

first1.o:	$(IDL)/comar.h $(IDL)/name.h \
		$(LIB)/cmrlib.h $(LIB)/cmrio.h $(LIB)/bitset.h \
		privatlib.h first1.h

digraph.o:	$(IDL)/global.h $(LIB)/bitset.h privatlib.h digraph.h

printst2ter.o:	printst2ter.h privatlib.h $(LIB)/cmrlib.h \
		$(IDL)/comar.h $(IDL)/comarMacros.h \
		$(IDL)/prsiface.h $(IDL)/prsifaceM.h

