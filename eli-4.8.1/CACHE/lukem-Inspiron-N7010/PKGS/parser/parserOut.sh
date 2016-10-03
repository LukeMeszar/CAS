#!/bin/sh
# $Id: parserOut.sh.in,v 1.5 2012/04/06 02:01:26 profw Exp $
# Copyright 1992-1998, The Regents of the University of Colorado

# EXEC (parserOut.sh) (:level_6_specs :extract=:mapPgram :names)
#                     (:level_6_specs :parserGen :names) (+parser) (+monitor)
#		      (parser.reqmod) (mon_cprods.c) (dfltparse.reqmod)
#   => (:parserOut);
# :parserOut 'Results of parser generation' => :FILE;

ODIN_e115=$1;shift;
ODIN_pgs=$1;shift; ODIN_parser=$1;shift; ODIN_mon=$1;shift;
ODIN_reqmod=$1;shift; ODIN_cprods=$1;shift; ODIN_default=$1;shift;

if test -s $ODIN_e115
then
  echo $ODIN_reqmod > parserOut

  if false
  then
    if test '' != "$ODIN_mon"
    then echo $ODIN_cprods >> parserOut
    fi
  fi

  if test 'none' = "$ODIN_parser"
  then cp /dev/null parserOut
  elif test -s $ODIN_pgs
  then cat $ODIN_pgs >> parserOut
  else echo "Invalid parser generator name: $ODIN_parser" > ERRORS
  fi
else
  if test 'none' = "$ODIN_parser"
  then touch parserOut
  else echo $ODIN_default > parserOut
  fi
fi
