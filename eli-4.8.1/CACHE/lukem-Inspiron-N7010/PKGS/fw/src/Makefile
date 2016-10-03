# $Id: Makefile.in,v 1.2 2002/05/08 15:00:54 waite Exp $
# Copyright 1992, The Regents of the University of Colorado

# This file is part of the Eli translator construction system.

# Eli is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 2, or (at your option) any later
# version.

# Eli is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.

# You should have received a copy of the GNU General Public License along
# with Eli; see the file COPYING.  If not, write to the Free Software
# Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.

CC	= gcc

# Relative pathname for the current directory
DIR	= pkg/fw/src

SRCS	= analyse.c as.c clock.c command.c data.c dump.c help.c help_gnu.c \
	list.c lister.c machin.c main.c mapper.c memory.c misc.c option.c \
        parser.c scanner.c section.c table.c tangle.c texhead.c weave.c \
        writfile.c analyse.h as.h clock.h command.h data.h dump.h environ.h \
	help.h help_gnu.h list.h lister.h machin.h mapper.h memory.h misc.h \
	option.h parser.h scanner.h section.h style.h table.h tangle.h \
	texhead.h weave.h writfile.h help_gnu.ctx texhead.ctx \
	fw_errors.c fw_incl.c envmod.c envmod.h fw_specs.c BitSet.c BitSet.h \
	weaveinfo.h weaveinfo.c weavehtml.h weavehtml.c weavel2ht.h weavel2ht.c
OBJ	= analyse.o as.o clock.o command.o data.o dump.o help.o help_gnu.o \
	list.o lister.o machin.o main.o mapper.o memory.o misc.o option.o \
        parser.o scanner.o section.o table.o tangle.o texhead.o weave.o \
        writfile.o BitSet.o pdl_gen.o csm.o err.o envmod.o obstack.o \
	source.o deftbl.o idn.o weaveinfo.o weavehtml.o weavel2ht.o
EXE	= fw.exe fw_errors.exe fw_incl.exe fw_specs.exe
CMD	=
AUX	= $(SRCS) fw.tnf weaveinfo.pdl Makefile Makefile.in
GEN	= pdl_gen.c pdl_gen.h
SRC	=
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
# $Id: pdlmk.h,v 1.4 2001/05/09 20:43:05 waite Exp $
# PDL definition table library

PDLLIB	= $(ELISYS)/pkg/pdl
PDLINCL	= -I$(PDLLIB)

DEFDEPS = $(PDLLIB)/deftbl.c $(PDLLIB)/deftbl.h $(INPLIB)/err.h \
	  $(ADTLIB)/obstack.h

deftbl.o:	$(DEFDEPS)
	$(CC) $(CFLAGS) $(PDLINCL) $(INPINCL) $(ADTINCL) -c \
		$(PDLLIB)/deftbl.c
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

PDL	= ../../pdl/pdl.exe

CFLAGS	= $(SCNINCL) $(ADTINCL) $(INPINCL) $(PDLINCL) -DNORESTORE

pdl_gen.c pdl_gen.h:	weaveinfo.pdl
	$(PDL) weaveinfo.pdl

fw.exe:	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)

fw_errors.exe: fw_errors.o
	$(CC) $(CFLAGS) -o $@ fw_errors.o

fw_incl.exe:	fw_incl.c
	$(CC) $(CFLAGS) -o $@ fw_incl.c

fw_specs.exe:	fw_specs.c
	$(CC) $(CFLAGS) -o $@ fw_specs.c

EMLIB	= $(ELISYS)/pkg/Name

BitSet.o: BitSet.c BitSet.h $(ADTLIB)/obstack.h $(INPLIB)/err.h
analyse.o : analyse.c style.h environ.h analyse.h as.h data.h clock.h list.h \
	table.h option.h machin.h help.h section.h writfile.h lister.h misc.h
as.o : as.c style.h environ.h as.h machin.h
clock.o : clock.c style.h environ.h as.h clock.h machin.h 
command.o : command.c style.h environ.h analyse.h as.h command.h machin.h \
	data.h clock.h list.h table.h option.h help.h section.h writfile.h \
	dump.h lister.h memory.h mapper.h misc.h parser.h scanner.h tangle.h \
	weave.h weaveinfo.h weavehtml.h weavel2ht.h
data.o : data.c data.h style.h environ.h clock.h list.h table.h option.h \
	machin.h help.h section.h writfile.h
dump.o : dump.c style.h environ.h as.h clock.h data.h list.h table.h \
	option.h machin.h help.h section.h writfile.h dump.h misc.h
envmod.o: envmod.c envmod.h BitSet.h $(INPLIB)/err.h $(PDLLIB)/deftbl.h \
          $(ADTLIB)/obstack.h
help.o : help.c style.h environ.h as.h help.h help_gnu.h misc.h data.h \
	clock.h list.h table.h option.h machin.h section.h writfile.h 
help_gnu.o : help_gnu.c style.h environ.h help_gnu.h help_gnu.ctx 
list.o : list.c style.h environ.h as.h machin.h memory.h list.h 
lister.o : lister.c style.h environ.h as.h data.h clock.h list.h table.h \
	option.h machin.h help.h section.h writfile.h lister.h misc.h 
machin.o : machin.c style.h environ.h as.h machin.h 
main.o : main.c style.h environ.h as.h command.h machin.h data.h clock.h \
	list.h table.h option.h help.h section.h writfile.h memory.h 
mapper.o : mapper.c style.h environ.h as.h machin.h mapper.h memory.h 
memory.o : memory.c style.h environ.h as.h machin.h memory.h 
misc.o : misc.c style.h environ.h as.h data.h clock.h list.h table.h \
	option.h machin.h help.h section.h writfile.h memory.h misc.h 
option.o : option.c style.h environ.h as.h data.h clock.h list.h table.h \
	option.h machin.h help.h section.h writfile.h misc.h 
parser.o : parser.c style.h environ.h as.h data.h clock.h list.h table.h \
	option.h machin.h help.h section.h writfile.h lister.h mapper.h \
	memory.h misc.h parser.h
scanner.o : scanner.c style.h environ.h as.h clock.h data.h list.h table.h \
	option.h machin.h help.h section.h writfile.h dump.h lister.h \
	mapper.h memory.h misc.h scanner.h 
section.o : section.c style.h environ.h as.h section.h 
table.o : table.c style.h environ.h as.h machin.h memory.h table.h 
tangle.o : tangle.c style.h environ.h as.h data.h clock.h list.h table.h \
	option.h machin.h help.h section.h writfile.h lister.h memory.h \
	misc.h tangle.h 
texhead.o : texhead.c style.h environ.h texhead.h writfile.h texhead.ctx 
weave.o : weave.c style.h environ.h as.h data.h clock.h list.h table.h \
	option.h machin.h help.h section.h writfile.h lister.h misc.h \
	texhead.h weave.h 
weaveinfo.o : weaveinfo.c style.h environ.h as.h data.h clock.h list.h \
	table.h option.h machin.h help.h section.h writfile.h lister.h misc.h \
	texhead.h weaveinfo.h $(EMLIB)/envmod.h $(ADTLIB)/csm.h \
	$(SCNLIB)/idn.h pdl_gen.h $(PDLLIB)/deftbl.h $(ADTLIB)/obstack.h
weavehtml.o : weavehtml.c style.h as.h data.h lister.h machin.h misc.h \
	table.h weavehtml.h $(EMLIB)/envmod.h $(ADTLIB)/csm.h \
	$(SCNLIB)/idn.h pdl_gen.h environ.h clock.h list.h option.h \
	section.h writfile.h $(PDLLIB)/deftbl.h $(ADTLIB)/obstack.h \
	BitSet.h $(ELILIB)/eliproto.h
weavel2ht.o : weavel2ht.c style.h as.h data.h lister.h machin.h misc.h \
	table.h weavel2ht.h environ.h clock.h list.h option.h section.h \
	writfile.h
writfile.o : writfile.c style.h environ.h as.h machin.h writfile.h

 
