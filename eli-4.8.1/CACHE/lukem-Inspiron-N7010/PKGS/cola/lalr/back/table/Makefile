# $Id: Makefile.in,v 1.4 2010/04/26 10:44:14 pfahler Exp $
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
# Makefile of Tool/cola/lalr/back/table

CC	=	gcc

DIR	=	pkg/cola/lalr/back/table
SRC	=
C_FILES =	opt_tabs.c optfunc.c wrt_tabs.c wrtfunc.c BUILDPRS.c \
		optresfunc.c opthelpfunc.c wrthelpfunc.c build_copa.c \
		ptg_gen.c obstack.c
O_FILES =	opt_tabs.o optfunc.o wrt_tabs.o wrtfunc.o \
		optresfunc.o opthelpfunc.o wrthelpfunc.o ptg_gen.o \
		obstack.o
H_FILES =	build_tdcopa.h opthelpfunc.h tabsopttype.h wrthelpfunc.h \
		opt_tabs.h opthelptype.h wrt_tabs.h optfunc.h optresfunc.h \
	        wrtfunc.h build_copa.h ptg_gen.h obstack.h gettext.h config.h
COP	=	$(C_FILES) $(H_FILES) Makefile.in
AUX	=	$(COP) Makefile
COM	=
CMD	=
RCS	=	
EXE	=	../../../colaTbl.exe
GEN	=
GENINS	=
SRCDIR	=
AUXDIR	=

BOTH	=	../both
IDL	=	../../../idl

LIBS = $(BOTH)/both.a $(IDL)/IDL.a
CFLAGS	= -I$(BOTH) -I$(IDL)

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

$(EXE): table.a build_copa.o BUILDPRS.o  $(LIBS)
	$(CC) $(CFLAGS) BUILDPRS.o build_copa.o table.a $(LIBS) -o $(EXE)

IDLH	= $(IDL)/comar.h $(IDL)/prsiface.h

BUILDPRS.o: BUILDPRS.c $(IDLH) $(BOTH)/error.h build_copa.h
	$(CC) -DTABDRIV -DFILEOPT $(CFLAGS) -c BUILDPRS.c

table.a: $(O_FILES)
	rm -f $@
	ar rcu $@ $(O_FILES)
	ranlib $@

TABS	= wrt_tabs.h tabsopttype.h opt_tabs.h

build_copa.o: build_copa.c build_copa.h $(BOTH)/rd_absprs.h $(IDLH) $(TABS)
	$(CC) -c -DTABDRIV  $(CFLAGS) build_copa.c

opt_tabs.o: opt_tabs.c optfunc.h tabsopttype.h $(BOTH)/error.h

optfunc.o:   optfunc.c tabsopttype.h opthelptype.h opthelpfunc.h optresfunc.h

wrt_tabs.o:  wrt_tabs.c tabsopttype.h wrtfunc.h $(BOTH)/error.h

wrtfunc.o:   wrtfunc.c tabsopttype.h wrthelpfunc.h

optresfunc.o:   optresfunc.c  $(BOTH)/error.h tabsopttype.h opthelptype.h

opthelpfunc.o:   opthelpfunc.c  $(BOTH)/error.h tabsopttype.h opthelptype.h

wrthelpfunc.o:   wrthelpfunc.c  $(BOTH)/error.h tabsopttype.h

