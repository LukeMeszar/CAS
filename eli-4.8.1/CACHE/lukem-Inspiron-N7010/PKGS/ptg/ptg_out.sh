#!/bin/sh
# $Id: ptg_out.sh.in,v 1.2 2008/08/22 09:40:22 pfahler Exp $
# Copyright (C) 1997 University of Paderborn
# 
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

ODIN_RUNDIR=`pwd`;
PKG=$1;shift; ODIN_e40=$1;shift; ODIN_e41=$1;shift; ODIN_mon=$1;shift;

#ptg_out(.none) "Results of PTG processing"* :
#	USER
#		: (:ptg.cmpd :names) 
#		: (:ptg_gen :name)  

if test -s "$ODIN_e40"
then
	echo "$ODINCACHE/PKGS/ptg/ptgadt.ptg.phi" > ptg_out
	echo "$ODINCACHE/PKGS/ptg/ptgadt.head" >> ptg_out
	echo "$ODINCACHE/PKGS/ptg/ptgadt.reqmod" >> ptg_out
 	cat "$ODIN_e41" >> ptg_out
  if false
  then
	if test '' != "$ODIN_mon"
	then
        	echo "$ODINCACHE/PKGS/ptg/ptg.dapto" >> ptg_out
        	echo "$ODINCACHE/PKGS/ptg/ptg.tcl" >> ptg_out
	fi
  fi
else
	cp /dev/null ptg_out 
fi

exit 0
