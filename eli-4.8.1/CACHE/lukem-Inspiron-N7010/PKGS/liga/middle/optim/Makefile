# $Id: Makefile.in,v 1.1 2001/10/25 14:35:43 cogito Exp $
# Makefile for pkg/liga/optim
# Copyright 1994, Universitaet Gesamthochschule Paderborn

# This file is part of the Eli translator construction system.
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

CC	=	gcc

DIR	=	pkg/liga/middle/optim
SRC	=
COP	=       Makefile.in OPTIM.c optbuildstr.c optfct.c optgroup.c \
		optidl.c optlifet.c optout.c optvar.c \
		chkbu.c optcycle.c do_optim.c OPTIM.h OPTIMMacros.h \
		optglobal.h optfct.h optidl.h optdid.h do_optim.h \
		chkbu.h optcycle.h termtrafo.c termtrafo.h \
                optlifet.h optgroup.h optvar.h optout.h optbuildstr.h 
AUX	=	$(COP) Makefile
COM	=
CMD	=	$(COM)
RCS	=	$(COP) $(COM) $(SRC)
EXE	=
OBJ	= 	OPTIM.o optbuildstr.o optidl.o \
		optfct.o optvar.o optgroup.o optout.o optlifet.o \
		chkbu.o optcycle.o do_optim.o termtrafo.o
GEN	=	$(OBJ)
GENINS	=
SRCDIR	=
AUXDIR	=

IDL	=	../../idl
OPTION	= 	../../option
SCEL	= 	../../ligascel
EXPAND	= 	../expand
MIDDLE  =       ..
IDLHDRS	=	$(IDL)/LIGA.h $(IDL)/LIGAMacros.h $(IDL)/lookup_idl.h

DEBUG	=
# DEBUG	=	-DDEBUG -DLIFETIME

CFLAGS	= 	-I$(IDL) -I$(OPTION) -I$(SCEL) -I$(MIDDLE) -I$(EXPAND) $(DEBUG)

LIBS	= 	$(SCEL)/err.o $(SCEL)/source.o $(OPTION)/opt_input.o \
		$(IDL)/IDL.a

HEADER = 	OPTIM.h OPTIMMacros.h optglobal.h optfct.h optidl.h optdid.h \
		$(SCEL)/printerr.h do_optim.h chkbu.h optcycle.h \
		$(SCEL)/ligaconsts.h $(SCEL)/eliproto.h\
                optlifet.h optgroup.h optvar.h optout.h optbuildstr.h

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

OPTIM.o:	$(HEADER) $(IDL)/writer.h $(IDL)/reader.h $(IDL)/global.h

optbuildstr.o:	$(HEADER) $(IDLLOOK) $(IDL)/global.h

optidl.o:	$(HEADER)

optfct.o:	$(HEADER)

optsivi.o:	$(HEADER)

optvar.o:	$(HEADER)

optgroup.o:	$(HEADER)

optout.o:	$(HEADER)

optlifet.o:	$(HEADER)

chkbu.o:	$(HEADER)

optcycle.o:	$(HEADER)

termtrafo.o: $(IDL)/LIGA.h $(IDL)/LIGAMacros.h $(IDL)/liga_func.h \
		$(IDL)/lookup_idl.h $(SCEL)/ligaconsts.h

do_optim.o:	$(HEADER) termtrafo.h
