# $Id: Makefile.in,v 1.1 2001/10/25 14:35:14 cogito Exp $
# Makefile for pkg/liga/middle
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

DIR	=	pkg/liga/middle
SRC	=
COP	=       Makefile.in middle.c middle_mem.h middle_mem.c \
		obstack.h obstack.c gettext.h linemap.c linemap.h
AUX	=	$(COP) Makefile
COM	=
CMD	=	$(COM)
RCS	=
EXE	=	../ligaMe.exe
GEN	=
GENINS	=
SRCDIR	=
ORDER	= 	order
EXPAND	=	expand
OPTIM	=	optim
IDL	= 	../idl
OPTION	= 	../option
SCEL	= 	../ligascel

AUXDIR	=       $(EXPAND) $(OPTIM) $(ORDER) 


CFLAGS	=	-I$(IDL) -I$(OPTION) -I$(SCEL) -I$(ORDER) -I$(EXPAND) \
		-I$(OPTIM) -I.

EXPAND_OBJS	= $(EXPAND)/exp_io.o \
		  $(EXPAND)/expchain.o \
		  $(EXPAND)/expclass.o \
		  $(EXPAND)/expconstit.o \
		  $(EXPAND)/expidl.o \
		  $(EXPAND)/expincl.o \
		  $(EXPAND)/expref.o \
		  $(EXPAND)/exptransfer.o \
		  $(EXPAND)/exptrav.o \
		  $(EXPAND)/do_expand.o \
		  $(EXPAND)/exp_prot.o

ORDER_OBJS	= $(ORDER)/bottomup.o \
		  $(ORDER)/induce.o \
		  $(ORDER)/initdp.o \
		  $(ORDER)/option.o \
		  $(ORDER)/ordout.o \
		  $(ORDER)/do_order.o \
		  $(ORDER)/part.o \
		  $(ORDER)/reftab.o \
		  $(ORDER)/set.o \
		  $(ORDER)/visit.o \
		  $(ORDER)/depmod.o

OPTIM_OBJS	= $(OPTIM)/OPTIM.o \
		  $(OPTIM)/optbuildstr.o \
		  $(OPTIM)/do_optim.o \
		  $(OPTIM)/optfct.o \
		  $(OPTIM)/optgroup.o \
		  $(OPTIM)/optidl.o \
		  $(OPTIM)/optlifet.o \
		  $(OPTIM)/optout.o \
		  $(OPTIM)/optvar.o \
		  $(OPTIM)/chkbu.o \
		  $(OPTIM)/optcycle.o \
		  $(OPTIM)/termtrafo.o

LIBS		= $(OPTION)/opt_input.o \
		  $(IDL)/IDL.a \
		  $(SCEL)/err.o \
		  $(SCEL)/printerr.o \
		  $(SCEL)/source.o 

MYOBJS          = obstack.o middle_mem.o middle.o linemap.o
OBJS		= $(MYOBJS) \
		  $(EXPAND_OBJS) $(ORDER_OBJS) $(OPTIM_OBJS) $(LIBS)

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

alldir:		$(MYOBJS)    # make MYOBJS before you go to subdirs

$(EXE): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

middle.o: $(IDL)/LIGA.h $(IDL)/global.h
middle.o: $(SCEL)/err.h middle_mem.h $(EXPAND)/do_expand.h $(ORDER)/do_order.h
middle.o: $(OPTIM)/do_optim.h
middle_mem.o: obstack.h
middle_mem.o: middle_mem.h
obstack.o: obstack.h config.h
