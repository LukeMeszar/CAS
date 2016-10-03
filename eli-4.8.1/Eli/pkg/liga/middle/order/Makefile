# $Id: Makefile.in,v 1.1 2001/10/25 14:35:53 cogito Exp $
# Makefile for pkg/liga/order
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

DIR	=	pkg/liga/middle/order
SRC	=
C_FILES	= 	reftab.c initdp.c induce.c option.c part.c \
	  	visit.c ordout.c set.c \
		bottomup.c do_order.c depmod.c
H_FILES	= 	Types.h Gorto.h set.h bottomup.h reftab.h \
		initdp.h do_order.h depmod.h bool.h option.h \
		visit.h ordout.h part.h induce.h allocate.h
COP	=       Makefile.in $(C_FILES) $(H_FILES) bottomup.doc
AUX	=	$(COP) Makefile
COM	=
CMD	=	$(COM)
RCS	=	$(COP) $(COM) $(SRC)
EXE	=
GENINS	=
SRCDIR	=
AUXDIR	=

IDL	=	../../idl
GORTO	=	../../gorto
OPTION	= 	../../option
SCEL	=	../../ligascel
EXPAND	=	../expand
MIDDLE  =       ..
O_OB_DIR=	.

CFLAGS	= 	-I$(IDL) -I$(OPTION) -I$(SCEL) -I$(MIDDLE) -I$(EXPAND)
GFLAGS	=	-DGORTO 

OBJS	=	 $(O_OB_DIR)/do_order.o \
		 $(O_OB_DIR)/reftab.o $(O_OB_DIR)/initdp.o \
		 $(O_OB_DIR)/induce.o \
		 $(O_OB_DIR)/option.o $(O_OB_DIR)/part.o \
		 $(O_OB_DIR)/visit.o \
		 $(O_OB_DIR)/ordout.o \
		 $(O_OB_DIR)/set.o \
		 $(O_OB_DIR)/bottomup.o \
		 $(O_OB_DIR)/depmod.o

LIBS	= 	$(IDL)/IDL.a $(SCEL)/err.o $(SCEL)/source.o

# $Id: mknogortosym,v 1.1 2001/10/25 14:37:00 cogito Exp $

GEN	=	$(OBJS)

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


$(GORTOLIB):	$(G_OB_DIR) $(GORTOOBJ)
	rm -f $(GORTOLIB)
	ar ruc $(GORTOLIB) $(GORTOOBJ)
	ranlib $(GORTOLIB)

# Dependencies established by .h files:

TYPES_H=    Types.h $(IDL)/LIGA.h $(IDL)/LIGAMacros.h set.h bool.h
ALLOCATE_H= allocate.h $(MIDDLE)/middle_mem.h
OPTION_H=   option.h bool.h $(TYPES_H)
SET_H=      set.h bool.h
BOTTOMUP_H= bottomup.h bool.h
INITDP_H=   initdp.h $(TYPES_H)
DEPMOD_H=   depmod.h $(TYPES_H)
DO_ORDER_H= do_order.h $(TYPES_H)
VISIT_H=    visit.h $(TYPES_H)

# Dependencies established by .c files:

depmod.o:   $(DEPMOD_H) reftab.h

bottomup.o: $(BOTTOMUP_H) $(DEPMOD_H) ordout.h option.h reftab.h $(INITDP_H) $(DO_ORDER_H)
bottomup.o: $(IDL)/liga_func.h
bottomup.o: $(SCEL)/ligaconsts.h $(SCEL)/printerr.h $(SCEL)/err.h

do_order.o: $(DO_ORDER_H) reftab.h $(BOTTOMUP_H) $(ALLOCATE_H)
do_order.o: $(INITDP_H) $(VISIT_H) ordout.h part.h
do_order.o: $(SCEL)/err.h
do_order.o: $(OPTION)/option_types.h $(OPTION)/opt_input.h $(OPTION)/option_enums.h

induce.o: induce.h reftab.h $(ALLOCATE_H) $(DEPMOD_H)

initdp.o: $(INITDP_H) $(DEPMOD_H) $(DO_ORDER_H) reftab.h $(VISIT_H) $(BOTTOMUP_H)
initdp.o: $(SCEL)/ligaconsts.h $(SCEL)/printerr.h

option.o: option.h $(DO_ORDER_H) reftab.h $(DEPMOD_H) $(ALLOCATE_H)
option.o: $(OPTION)/option_enums.h $(OPTION)/option_types.h
option.o: $(OPTION)/opt_input.h $(SCEL)/printerr.h

ordout.o: ordout.h $(DO_ORDER_H) reftab.h option.h
ordout.o: $(SCEL)/ligaconsts.h $(SCEL)/printerr.h

part.o: part.h option.h $(DO_ORDER_H) reftab.h $(DEPMOD_H) $(ALLOCATE_H)
part.o: $(SCEL)/ligaconsts.h $(SCEL)/printerr.h

reftab.o: reftab.h $(ALLOCATE_H)
reftab.o: $(SCEL)/err.h

set.o: $(SET_H) $(ALLOCATE_H) reftab.h

visit.o: $(VISIT_H) $(INITDP_H) option.h reftab.h $(ALLOCATE_H) $(DO_ORDER_H)
visit.o: $(IDL)/liga_func.h
visit.o: $(SCEL)/printerr.h $(SCEL)/ligaconsts.h

