#!/bin/sh
# $Id: mon.sh.in,v 1.3 2013/08/31 01:43:41 profw Exp $
# Copyright (c) 1994-1999 Anthony M. Sloane

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

# EXEC (mon.sh) (.) (:allspecs +monitor :exe) (:allspecs +monitor :monDb)
#      (:all_tcl :cat) (+arg :ls) (+monitor)
#   NEEDS (+arg) (noosa.exe) (noosa.tcl)
#   => (:mon);
#
# :mon 'Domain-specific execution monitoring run'? => :EXECUTABLE;

PKG=$1;shift; ODIN_exe=$1;shift; ODIN_monDb=$1;shift; ODIN_tcl=$1;shift;
ODIN_arg=$1;shift; ODIN_monitor=$1;shift;

echo '#!/bin/sh' > mon
chmod +x mon

if false
then

if test '' != "$ODIN_arg"
then
    arg=`echo \`cat "$ODIN_arg"\``
else
    arg=
fi

cat <<ENDMON >>mon
NOOSA_LIB=$PKG; export NOOSA_LIB
$PKG/noosa.exe $PKG/noosa.tcl -- "$ODIN_tcl" $ODIN_monDb $ODIN_exe $arg
ENDMON

else
echo "echo Sorry, monitoring support is not configured into your Eli system." \
    >> mon
fi
