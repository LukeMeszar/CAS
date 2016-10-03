/* $Id: rdsymb.h,v 1.1 2002/04/25 17:17:16 waite Exp $ */
/* a.out module interface
   Copyright 1994, The Regents of the University of Colorado */

/* This file is part of the Eli translator construction system.

Eli is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

Eli is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License along
with Eli; see the file COPYING.  If not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#if defined(__cplusplus) || defined(__STDC__)
extern void read_symbols(char *file_name);
/* Obtain symbol information
 *    On entry-
 *       file_name=file from which to obtain the symbols
 *    On exit-
 *       SymbolInfo(symbol,external) has been invoked for each symbol
 ***/
#else
extern void read_symbols();
#endif
