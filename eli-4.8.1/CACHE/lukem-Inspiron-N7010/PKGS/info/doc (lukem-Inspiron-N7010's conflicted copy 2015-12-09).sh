#! /bin/sh
# $Id: doc.sh.in,v 2.1 2008/03/19 22:48:13 profw Exp $
# Copyright 2008, The Regents of the University of Colorado

if test "$ODINCACHE" != '' -a -d $ODINCACHE/PKGS/info
then
  DATA=$ODINCACHE/PKGS/info
else
  DATA=/home/lukem/Dropbox/CAS/eli-4.8.1/Eli/pkg/info
fi

# In some cases, we can reliably open the HTML version of
# the docs, if it exists.

DOCLOC=/home/lukem
if test ! -f $DOCLOC/doc/Eli/index.html
then
  DOCLOC=`dirname /home/lukem/Dropbox/CAS/eli-4.8.1/Eli`
  if test ! -f $DOCLOC/doc/Eli/index.html
  then
    DOCLOC=
  fi
fi

trytoopenwith () {
  opener=`which $1 2>/dev/null`
  if test "$opener" != ''
  then
    cd $DOCLOC/doc/Eli
    $opener index.html
    exit 0
  fi
}

if test "$DOCLOC" != ''
then
  trytoopenwith gnome-open  # Linux GNOME
  trytoopenwith see         # Some linuxes
  trytoopenwith open        # Mac OS X
  trytoopenwith cygstart    # Cygwin

  # On some systems we can use mailcap to work out what to do

  SEARCH=$DATA/search.exe
  DOCFILE=$DOCLOC/doc/Eli/index.html

  if test -x $SEARCH
  then
    cmd=`$SEARCH text/html $DOCFILE`
    if [ -n "$cmd" ]
    then
      eval $cmd &
      exit 0
    fi
  fi
fi

# Otherwise, fall back on the info version of the docs

$DATA/info.sh
