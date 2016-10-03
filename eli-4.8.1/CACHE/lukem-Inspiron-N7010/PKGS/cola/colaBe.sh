#!/bin/sh
# $Id: colaBe.sh.in,v 1.2 2002/05/08 15:00:48 waite Exp $
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

PKG=$1;shift; ODIN_colaCmr=$1;shift; ODIN_colaAbs=$1;shift; ODIN_colaBackOpt=$1;shift; ODIN_colaErrOff=$1;shift; ODIN_colaErrTerms=$1;shift; ODIN_monitor=$1;shift; mkdir colaBe;

# EXEC (colaBe.sh) (.) (:colaCmr) (:colaAbs) (:colaBackOpt) (:colaErrOff) 
#                  (:colaErrTerms) (+monitor)
#  => (:colaBe);
#        :colaBe 'Generation of the concrete parser' => :DERIVED-DIRECTORY;

cp $ODIN_colaCmr cmr
$ODINCACHE/PKGS/cola/colaConn.exe cmr 1> ERRORS 2>&1

if test -s core
then
    echo '".", line 0:0 DEADLY: COLA Backend (colaConn) failed' >> ERRORS
fi

if test -s ERRORS
then 
    exit 0
fi

"$ODINCACHE/PKGS/cola/colaTbl.exe" \
		cmr.sem "$ODIN_colaAbs" "$ODIN_colaBackOpt" 1> ERRORS 2>&1
if test -s core
then
    echo '".", line 0:0 DEADLY: COLA Backend failed' >> ERRORS
fi

if test -s opt.out 
then 
    mv opt.out colaBe/colaBack.info
fi

if test -s ERRORS
then
   exit 0
fi

# Copying parser frame
cp "$ODINCACHE/PKGS/cola/Frames/parser.c" colaBe
if test -s "$ODIN_colaErrOff"
then
    cat "$ODIN_colaErrOff" "$ODINCACHE/PKGS/parser/parser.h" \
					> colaBe/parser.h
else
    cp "$ODINCACHE/PKGS/parser/parser.h" colaBe
fi

# Moving generated products
mv semprods.h colaBe/semprods.h
cat "$ODIN_colaErrTerms" >> ptabs.h
mv ptabs.h colaBe/ptabs.h

if false
then
  if test '' != "$ODIN_monitor"
  then
    cp "$ODINCACHE/PKGS/cola/Frames/cola.dapto" colaBe/cola.dapto
    echo "$ODINCACHE/PKGS/parser/mon_cprods.c" >> colaBe/cola.reqmod
    cp mon_cprods.h colaBe/mon_cprods.h
  fi
fi

exit 0
