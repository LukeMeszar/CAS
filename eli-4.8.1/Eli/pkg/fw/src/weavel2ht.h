/* $Id: weavel2ht.h,v 2.2 1999/10/20 04:57:12 tony Exp $ */
/*##############################################################################

FUNNNELWEB COPYRIGHT
====================
FunnelWeb is a literate-programming macro preprocessor.

Copyright (C) 1992 Ross N. Williams.

   Ross N. Williams
   ross@spam.adelaide.edu.au
   16 Lerwick Avenue, Hazelwood Park 5066, Australia.

This program is free software; you can redistribute it and/or modify
it under the terms of Version 2 of the GNU General Public License as
published by the Free Software Foundation.

This program is distributed WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See Version 2 of the GNU General Public License for more details.

You should have received a copy of Version 2 of the GNU General Public
License along with this program. If not, you can FTP the license from
prep.ai.mit.edu/pub/gnu/COPYING-2 or write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

Section 2a of the license requires that all changes to this file be
recorded prominently in this file. Please record all changes here.

Programmers:
   RNW  Ross N. Williams  ross@spam.adelaide.edu.au
   AMS  Tony Sloane	  asloane@comp.mq.edu.au
   WMW	William M. Waite  William.Waite@Colorado.edu

Changes:
   07-May-1992  RNW  Program prepared for release under GNU GPL V2.
   26-Jul-1992  AMS  Added RCS id.
   25-Apr-1998	WMW  Changed to produce latex2html markup

##############################################################################*/


/******************************************************************************/
/*                                  WEAVEL2HT.H                               */
/******************************************************************************/
/*                                                                            */
/* This package exports a single function "weave" that generates the typeset  */
/* output file.                                                               */
/*                                                                            */
/******************************************************************************/

#include "style.h"

/******************************************************************************/

EXPORT void weavel2ht P_((void));

/******************************************************************************/
/*                              End of WEAVEL2HT.H                            */
/******************************************************************************/
