#!/bin/sh
# $Id: init.sh.in,v 1.3 2003/12/03 15:42:55 waite Exp $
# Copyright (c) 1993, The Regents of the University of Colorado
# Copyright 1994-1999 Anthony M. Sloane

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

# EXEC (init.sh) (:used_sources) (:used_sources :list :labels)
#     (+debug) (+prof) (+monitor)
#  NEEDS (:used_sources :list)
#  => (:init_sources) (:init_objects) (:libDb);
#
# :init_sources 'Source files for initialization' => :DERIVED-DIRECTORY;
# :init_objects 'Object files for initialization' => :DERIVED-DIRECTORY;
# :libDb 'Event database for library modules' => :FILE;

ODIN_RUNDIR=`pwd`;
ODIN_used_sources=$1;shift; ODIN_used_labels=$1;shift;
ODIN_debug=$1;shift; ODIN_prof=$1;shift; ODIN_monitor=$1;shift;

mkdir init_sources;

SED=$ODINCACHE/PKGS/skeleton/sed.exe

if false
then

if test '' = "$ODIN_monitor"
then
    cp /dev/null libDb
    exit 0
fi

c=init_sources/dapto_interface.c

echo "#ifdef MONITOR" > $c

$SED -n -e \
    's:\([^/]*\)_dapto.c:extern void _dap_\1_init ();:p' \
  "$ODIN_used_labels" >> $c

echo "void _dap_interface_init () {" >> $c

$SED -n -e \
    's:\([^/]*\)_dapto.c:_dap_\1_init ();:p' \
  "$ODIN_used_labels" >> $c
echo "}" >> $c
echo "#endif" >> $c

$SED -n -e 's:\(.*_dapto\).c:\1.db:p' \
    "$ODIN_used_sources" > libDb

else cp /dev/null libDb
fi
