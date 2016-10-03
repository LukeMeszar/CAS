#!/bin/sh
# $Id: kwd.sh,v 2.6 2002/05/08 15:00:58 waite Exp $
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

#EXEC (kwd.sh) (kwfilter.exe) (:gla.cmpd :cpp) => (:kwd);

ODIN_filter=$1;shift; ODIN_gla=$1;shift;

$ODIN_filter $ODIN_gla 2> ERROR
mv filtered kwd

if test -s ERROR
then
	echo '(|'"$ODIN_gla"'|line_err|' >> ERRORS
	$ODINCACHE/PKGS/skeleton/sed.exe 's/^"\([^"]*\)", line \([0-9]*\):\([0-9]*\)/\1 \2 \3/' \
		ERROR >> ERRORS
	echo '|)' >> ERRORS
else :
fi
