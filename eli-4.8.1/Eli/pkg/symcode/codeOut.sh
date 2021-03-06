#! /bin/sh
# $Id: codeOut.sh,v 2.3 2002/05/08 15:01:06 waite Exp $
# Copyright 1994, The Regents of the University of Colorado

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

# EXEC (codeOut.sh) (:symbols.cmpd :names) (:codeGen :name)
#   => (:codeOut);

ODIN_Present=$1;shift; ODIN_GenName=$1;shift;

if test -s $ODIN_Present
then cat $ODIN_GenName > codeOut
else cat /dev/null > codeOut
fi
