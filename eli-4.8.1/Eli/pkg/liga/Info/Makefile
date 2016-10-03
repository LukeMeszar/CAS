# $Id: Makefile.in,v 1.2 2008/03/25 12:28:28 peter Exp $
# Makefile for pkg/liga/Info
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

DIR	=	pkg/liga/Info
PS	=	struktur.eps verfolgung.eps hierarchy.eps rule.eps symbol.eps \
		symbol-rule.eps hide.eps visitseq.eps lidow.eps message.eps 	
SRC	=	middle.err ligaBe.err option.err ligaProd.err
COP	=       Makefile.in lcl.tnf lidoref.tnf gorto.tnf \
		show.tnf comptrees.tnf help.tnf frontfix.err frontgen.err
AUX	=	$(COP) Makefile psfig.tex $(PS)
COM	=
CMD	=	$(COM)
RCS	=
EXE	=
GEN	=	
GENINS	=	front.err
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

front.err:	frontfix.err frontgen.err
	cat frontgen.err frontfix.err > front.err
	
predist:        docs
        
docs:
	cp -f *.gif $(ELIDOC)/gifs
	chmod +w $(ELIDOC)/gifs/*.gif

