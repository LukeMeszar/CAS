#! /bin/sh
# $Id: pgsGen.sh.in,v 1.7 2006/11/29 22:25:02 profw Exp $
# Copyright (c) 1990, The Regents of the University of Colorado

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

# EXEC (pgsGen.sh) (:Pgram) (:BuPgram) (+monitor) (+pgsOpt)
#      (eingabe.exe) (analyse.exe) (pgs_optim.exe) (buildtab.exe)
#      (StructConn) (parser.c) (pgs.dapto)
#   => (:pgsGen);

ODIN_Pgram=$1;shift; ODIN_BuPgram=$1;shift; ODIN_monitor=$1;shift;
ODIN_pgsOpt=$1;shift;
ODIN_eingabe=$1;shift; ODIN_analyse=$1;shift; ODIN_pgs_optim=$1;shift;
ODIN_buildtab=$1;shift;
ODIN_StructConn=$1;shift; ODIN_parser=$1;shift; ODIN_dapto=$1;shift;
mkdir pgsGen;

SED=$ODINCACHE/PKGS/skeleton/sed.exe

if test -s "$ODIN_BuPgram"
then
  input=$ODIN_BuPgram
  cp $ODIN_BuPgram Eindat
else
  input=$ODIN_Pgram
  cp $ODIN_Pgram Eindat
fi

if $ODIN_eingabe
then :
else
  $SED -e '/^#$/d
    /\* Error/s;^ *\([0-9]*\).*\*;'"$input"' \1 0;' Fehlerda \
    > ERRORS
  exit 0
fi

mv Putout eingabe.out

if test '' != "$ODIN_pgsOpt"
then
  echo "$ODIN_pgsOpt" > Optionen
  if $ODIN_analyse
  then :
  else
    echo "$input 0 0 Grammar is not LALR(1)" >> ERRORS
    exit 0
  fi
elif test '' = "$ODIN_monitor" && echo 'SU' > Optionen && $ODIN_analyse
then :
elif echo 'SUC' > Optionen && $ODIN_analyse
then :
else
  mv Putout analyse.out

  if test -s "$ODIN_BuPgram"
  then
    # Check to see if the non-bottomup version is also not LALR(1)
    rm -f Eindat
    cp $ODIN_Pgram Eindat
    $ODIN_eingabe
    if $ODIN_analyse
    then
      echo ". 0 0 You have bottomup constraints in your attribute grammar that cause your concrete syntax to not be parsable." >> ERRORS
    else
      echo "$input 0 0 Grammar is not LALR(1)" >> ERRORS
    fi
  else
    echo "(|$input|pgsGenErr|error: The concrete syntax is not parsable|)" >> ERRORS
  fi
  exit 0
fi

mv Produdat Produein
mv Varanada Interdat

$ODIN_pgs_optim || echo 'Optimization failed' >> ERRORS
if test -s ERRORS
then
  if test -s Putout; then cat Putout >> ERRORS; fi
  exit 0
fi

$ODIN_buildtab Zerdat pgs.mak.table Zudat

cat Zudat pgs.mak.table | $SED -e '/&MACRO/d' > pgsGen/pgs_gen.h
cat $ODIN_StructConn Strukdat > pgsGen/pgs_gen.c
echo "}" >> pgsGen/pgs_gen.c
echo $ODIN_parser > pgsGen/pgs.reqmod

if false
then
  if test '' != "$ODIN_monitor"
  then
  cp $ODIN_dapto pgsGen/pgs.dapto
  echo $ODINCACHE/PKGS/parser/mon_cprods.c >> pgsGen/pgs.reqmod
  cp mon_cprods.h pgsGen/mon_cprods.h
  fi
fi
