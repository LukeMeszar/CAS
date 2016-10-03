#ifndef HEAD_H1
#define HEAD_H1
/*
 * $Id: clp.head,v 1.7 1997/09/08 04:56:26 kadhim Exp $
 * Header file for CLP
 */

#include "clp.h"
#endif

#ifndef HEAD_H2
#define HEAD_H2
/* $Id: envmod.head,v 3.3 1997/09/05 10:52:59 peter Exp $ */
/* Copyright, 1995, University of Colorado */
/* This file is part of the Eli Module Library.

The Eli Module Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The Eli Module Library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the Eli Module Library; see the file COPYING.LIB.
If not, write to the Free Software Foundation, Inc., 59 Temple Place -
Suite 330, Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Eli into the
   directory resulting from a :source derivation, you may use that
   created file as a part of that directory without restriction. */
#include "envmod.h"
#endif

#ifndef HEAD_H3
#define HEAD_H3
/* $Id: deftbl.head,v 1.1 1992/06/20 19:04:11 kadhim Exp $ */
/* Type definitions for the property list module */

#include "deftbl.h"

#endif

#ifndef HEAD_H4
#define HEAD_H4

#include "BitSet.h"
#endif

#ifndef HEAD_H5
#define HEAD_H5

#include "MakeName.h"
#endif

#ifndef HEAD_H6
#define HEAD_H6

#include "CoordCmp.h"
#endif

#ifndef HEAD_H7
#define HEAD_H7

#include "VoidPtrList.h"
#endif

#ifndef HEAD_H8
#define HEAD_H8

#include "DefTableKeyList.h"
#endif

#ifndef HEAD_H9
#define HEAD_H9

#include "tOilOpList.h"
#endif

#ifndef HEAD_H10
#define HEAD_H10

#include "tOilClassOpList.h"
#endif

#ifndef HEAD_H11
#define HEAD_H11


#include "envmod.h"

#endif

#ifndef HEAD_H12
#define HEAD_H12

#include "oiladt2.h"
#include "oiladt2b.h"
#include "csm.h"
#include "Build.h"

#include "ptg_gen.h"
extern PTGNode PTGElements();
#endif

#ifndef HEAD_H13
#define HEAD_H13

#include "Code.h"


#define ID(of) ((of)->sID)


#define Operator(k) \
  (HeadtOilOpList(GetOperator((k),NULLtOilOpList)))
#define OneOperator(k) \
  (TailtOilOpList( \
    GetOperator((k),NULLtOilOpList))==NULLtOilOpList)

#endif

#ifndef HEAD_H14
#define HEAD_H14
/* $Id: ptgadt.head,v 1.1 1991/09/19 11:31:10 mjung Exp $ */
/* Interface for the PTG-generated module */

#include "ptg_gen.h"
#endif

#ifndef HEAD_H15
#define HEAD_H15
#include "pdl_gen.h"
#endif

#ifndef HEAD_H16
#define HEAD_H16
/* $Id: liga.head,v 4.3 1997/09/15 14:46:48 cogito Exp $ */
/* (C) Copyright 1997 University of Paderborn */

/* This file is part of the Eli Module Library.

The Eli Module Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The Eli Module Library is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the Eli Module Library; see the file COPYING.LIB.
If not, write to the Free Software Foundation, Inc., 59 Temple Place -
Suite 330, Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Eli into the
   directory resulting from a :source derivation, you may use that
   created file as a part of that directory without restriction. */

#include "treecon.h"

#endif

#ifndef HEAD_H17
#define HEAD_H17

#include "tOilTypeSetList.h"
#endif

#ifndef HEAD_H18
#define HEAD_H18
#include "PtgCommon.h"
#endif

