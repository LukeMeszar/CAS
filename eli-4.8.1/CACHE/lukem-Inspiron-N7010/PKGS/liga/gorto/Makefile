# $Id: Makefile.in,v 1.1 2001/10/25 14:31:37 cogito Exp $
# Makefile for pkg/liga/gorto
# Copyright 1994, Universitaet Gesamthochschule Paderborn

# Test if all Resources (X-Libraries, Mathlib, etc) are available.
# If Yes, enable Compilation of gorto. If not, produce ligaGorto of
# file nogorto.c

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

DIR	=	pkg/liga/gorto
SOURCES	= 	Actions.c Main.c  ProdDep.c SymbCreate.c VisitDraw.c \
		Arrange.c MainList.c ProdDraw.c SymbDep.c VisitLife.c \
		Bitmaps.c MainWindow.c ProdMenu.c SymbDraw.c VisitMenu.c \
		Debug.c  Message.c ProdSelect.c SymbMenu.c VisitSelect.c \
		DepLayout.c Order.c  ProdSymbol.c SymbProd.c VisitUtil.c \
		Drawing.c OrdStrategy.c ProdUtil.c SymbSelect.c \
		Graph.c  PathFind.c Reftab.c SymbUtil.c \
		Hide.c  PopupUtil.c Resources.c Util.c Compile.c \
		Lido.c  ProdCreate.c SymbAttrs.c VisitCreate.c
HEADER	= 	Create.h Main.h Popup.h Symb.h \
		Graph.h Misc.h Prod.h Visit.h \
		Compile.h regexp.h
CONF	= 	Basic Cascade.bm CheckMark.bm Colors Icon.bm \
		Sizes.default Sizes.large Sizes.small Strings.engl \
		Strings.german STRUCTURE Sizes.tiny
SRC	=
COP	=       Makefile.in $(SOURCES) $(HEADER) $(CONF) nogorto.c
AUX	=	$(COP) Makefile
COM	=
CMD	=	$(COM)
RCS	=	$(COP) $(COM) $(SRC)
EXE	=	../ligaGorto.exe
GEN	=	
GENINS	=
SRCDIR	=
AUXDIR	=

XLIBS	=  -lXaw -lXmu -lXt -lXext -lX11  -lSM -lICE 
X_CFLAGS= 


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

# $Id: mknogorto,v 1.1 2001/10/25 14:32:57 cogito Exp $

$(EXE):	nogorto.o
	$(CC) nogorto.o -o $(EXE)

MISC_H= Misc.h $(ORDER)/Gorto.h

Compile.o: Compile.c Compile.h

Actions.o: $(MISC_H) Prod.h Symb.h Visit.h Graph.h

Arrange.o: $(MISC_H) Main.h 

Bitmaps.o: $(MISC_H) Main.h CheckMark.bm Cascade.bm Icon.bm

Debug.o: $(MISC_H) Visit.h

DepLayout.o: $(MISC_H)

Drawing.o: $(MISC_H)

Graph.o: Graph.h

Hide.o: Hide.c $(MISC_H) Create.h Prod.h Main.h Popup.h Compile.h

Lido.o: $(MISC_H) Main.h Popup.h

Main.o: $(MISC_H) Main.h

MainList.o: $(MISC_H) Create.h Prod.h Symb.h Popup.h Main.h

MainWindow.o: $(MISC_H) Create.h Prod.h Symb.h Visit.h Popup.h Main.h 

Message.o: $(MISC_H) Create.h Main.h Popup.h

Order.o: $(MISC_H) Prod.h Symb.h Visit.h Main.h

OrdStrategy.o: $(MISC_H) Create.h Main.h 

PathFind.o: $(MISC_H) Prod.h Symb.h

PopupUtil.o: $(MISC_H) Main.h Popup.h

ProdCreate.o: $(MISC_H) Create.h Graph.h Main.h Prod.h

ProdDep.o: $(MISC_H) Symb.h Main.h Prod.h

ProdDraw.o: $(MISC_H) Prod.h

ProdMenu.o: $(MISC_H) Create.h Visit.h Graph.h Prod.h

ProdSelect.o: $(MISC_H) Symb.h Graph.h Main.h Popup.h Prod.h

ProdSymbol.o: $(MISC_H) Graph.h Symb.h Prod.h

ProdUtil.o: $(MISC_H) Prod.h

Reftab.o: $(MISC_H) Prod.h Symb.h Visit.h Main.h

Resources.o: $(MISC_H) Main.h

SymbAttrs.o: $(MISC_H) Prod.h Symb.h

SymbCreate.o: $(MISC_H) Create.h Main.h Graph.h Symb.h

SymbDep.o: $(MISC_H) Prod.h Symb.h

SymbDraw.o: $(MISC_H) Graph.h Symb.h

SymbMenu.o: $(MISC_H) Create.h Visit.h Graph.h Popup.h Symb.h

SymbProd.o: $(MISC_H) Create.h Prod.h Main.h Graph.h Popup.h Symb.h

SymbSelect.o: $(MISC_H) Prod.h Main.h Graph.h Popup.h Symb.h

SymbUtil.o: $(MISC_H) Symb.h

Util.o: $(MISC_H) Main.h

VisitCreate.o: $(MISC_H) Create.h Graph.h Main.h Visit.h

VisitDraw.o: $(MISC_H) Graph.h Visit.h

VisitLife.o: $(MISC_H) Visit.h

VisitMenu.o: $(MISC_H) Create.h Prod.h Main.h Graph.h Visit.h

VisitSelect.o: $(MISC_H) Graph.h Prod.h Main.h Popup.h Visit.h

VisitUtil.o: $(MISC_H) Prod.h Visit.h
