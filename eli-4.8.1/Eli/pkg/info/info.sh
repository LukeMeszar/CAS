#!/bin/sh
# $Id: info.sh.in,v 1.4 2002/06/07 19:36:37 waite Exp $
# Copyright 1995, The Regents of the University of Colorado

if test "$ODINCACHE" != '' -a -d $ODINCACHE/PKGS/info
then
  DATA=$ODINCACHE/PKGS/info
  SED=$ODINCACHE/PKGS/skeleton/sed.exe
else
  DATA=/home/user/Dropbox/CAS/eli-4.8.1/Eli/pkg/info
  SED=sed
fi

PROG=$DATA/texinfo

bg=1
dict="-d $DATA/manuals:$DATA"
libd="-l $DATA"

while test $# -gt 0 && test x`echo $1 | awk '{print substr($1,1,1)}'` = 'x-'
do
	case `echo $1 | awk '{print substr($1,1,2)}'`
	in
	-d)	shift; dict="-d $1";;
	-f)	bg=0;;
	-l)	shift; libd="-l $1";;
	-n)	shift; node="-n $1";;
	*)	break;;
	esac
	shift
done

if test "$DISPLAY" != ''
then
  if test -s $PROG/xinfotool.exe
  then
    XPROG="$PROG/xinfotool.exe $dict"
  elif test -s $PROG/tclinfo.exe
  then
    XPROG="$PROG/tclinfo.exe $PROG/info.tcl $dict"
  elif test '/usr/bin/xterm'
  then
    XPROG="xterm -e $PROG/infoReader.exe"
    # This is needed because the -d option doesn't get through xterm.
    INFO_DIRECTORY_PATHS=`echo $dict | $SED -e 's;^-d ;;'`
    export INFO_DIRECTORY_PATHS
  else
    DISPLAY=''
  fi
fi

if test "$DISPLAY" != ''
then
  if test $bg = 1
  then
    $XPROG $libd $node $* &
  else
    $XPROG $libd $node $*
  fi
elif test "$WINDOW_PARENT" != ''
then
  if test $bg = 1
  then
    $PROG/infotool.exe -Wp 474 58 -Wl "Eli System Documentation Browser" \
         $dict $libd $node $* &
  else
    $PROG/infotool.exe -Wp 474 58 -Wl "Eli System Documentation Browser" \
         $dict $libd $node $*
  fi
else  
    exec $PROG/infoReader.exe $dict $libd $node $*
fi
