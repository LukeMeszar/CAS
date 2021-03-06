#!/bin/sh
# $Id: mongdb.sh.in,v 1.2 2003/06/30 05:23:47 tony Exp $
# Copyright (c) 1991, The Regents of the University of Colorado
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

# EXEC (mongdb.sh) (.) (:allspecs +monitor :sources :dir_of :vir_dir)
#     (:allspecs +monitor :sources +incl=(:includes) :map=:incl.all :union :dir_of :vir_dir)
#     (:allspecs +monitor :exe) (:allspecs +monitor :monDb) 
#     (:all_tcl :cat) (+core) (+arg :ls) (+monitor)
#   NEEDS (:allspecs +monitor :sources) (:allspecs +monitor :sources +incl=(:includes) :map=:incl.all :union) (+arg)
#   => (:mongdb);
# 
# :mongdb 'Monitoring in conjunction with the GNU symbolic debugger'?
#   => :EXECUTABLE;

PKG=$1;shift; ODIN_sources=$1;shift; ODIN_includes=$1;shift; ODIN_exe=$1;shift
ODIN_monDb=$1;shift; ODIN_tcl=$1;shift; ODIN_core=$1;shift; ODIN_arg=$1; shift;
ODIN_monitor=$1;shift;

echo '#!/bin/sh' > mongdb
chmod +x mongdb

if false
then

if test -s "$ODIN_core"
then core=`cat "$ODIN_core"`
else core=''
fi

if test '' != "$ODIN_arg"
then
    arg=`echo \`cat "$ODIN_arg"\``
else
    arg=
fi

cat <<ENDMON >>mongdb
echo "set args $arg" >/tmp/ngdb$$
echo "set editing no" >>/tmp/ngdb$$
echo "handle SIGUSR1 pass noprint" >>/tmp/ngdb$$
echo "handle SIGHUP pass noprint" >>/tmp/ngdb$$
NOOSA_LIB=$PKG; export NOOSA_LIB
$PKG/noosa.exe $PKG/noosa.tcl -- "$ODIN_tcl" $ODIN_monDb \${ELI_DEBUGGER:-gdb} -directory $ODIN_sources -directory $ODIN_includes -tty=/dev/tty --command=/tmp/ngdb$$ $ODIN_exe $core
rm -f /tmp/ngdb$$
ENDMON

else
echo "echo Sorry, monitoring support is not configured into your Eli system." \
    >> mongdb
fi
