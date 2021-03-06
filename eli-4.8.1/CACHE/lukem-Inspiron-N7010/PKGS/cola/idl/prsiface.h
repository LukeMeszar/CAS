/* (C) Copyright 1997 University of Paderborn */

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

/*
** $Id: prsiface.h,v 1.6 1997/08/29 08:38:08 mjung Exp $
*/

#ifndef PRSIFACE_H
#define PRSIFACE_H

/* prsiface.h - IDL declarations generated by idlc, version 3.2
 *  on Tue Apr 18 18:13:15 1989
 * Last Change: 18.04.89	From: Karl-Josef Prott
 *		14.02.90	From: Kalle
 *		30.01.91	From: Kalle
 */

/* Inserted by Kalle to correct a mistake of the idlc-translator */
#define	Gu_short(a)	Gushort(a)
#define	Wu_short(a)	Wushort(a)

#include "global.h"

/* Private Types */

/* Class Headers */
typedef struct CAEntrytype * CPEntrytype;

/* Nodes */
typedef struct RRowtype * Rowtype;
# define KRowtype 2
# define NRowtype (IRowtype((Rowtype)N_INIT( \
	GetNode(sizeof(struct RRowtype),KRowtype), \
	KRowtype,sizeof(struct RRowtype))))
# define DRowtype(n) {FRowtype(n); FreeNode(n, KRowtype);}
# define IRowtype(N) (N)
# define FRowtype(N)

typedef struct Rabsparsertype * absparsertype;
# define Kabsparsertype 4
# define Nabsparsertype (Iabsparsertype((absparsertype)N_INIT( \
	GetNode(sizeof(struct Rabsparsertype),Kabsparsertype), \
	Kabsparsertype,sizeof(struct Rabsparsertype))))
# define Dabsparsertype(n) {Fabsparsertype(n); FreeNode(n, Kabsparsertype);}
# define Iabsparsertype(N) (N)
# define Fabsparsertype(N)

typedef struct Raccept * accept;
# define Kaccept 6
# define Naccept (Iaccept((accept)N_INIT( \
	GetNode(sizeof(struct Raccept),Kaccept), \
	Kaccept,sizeof(struct Raccept))))
# define Daccept(n) {Faccept(n); FreeNode(n, Kaccept);}
# define Iaccept(N) (N)
# define Faccept(N)

typedef struct Rreduce * reduce;
# define Kreduce 8
# define Nreduce (Ireduce((reduce)N_INIT( \
	GetNode(sizeof(struct Rreduce),Kreduce), \
	Kreduce,sizeof(struct Rreduce))))
# define Dreduce(n) {Freduce(n); FreeNode(n, Kreduce);}
# define Ireduce(N) (N)
# define Freduce(N)

typedef struct Rshift * shift;
# define Kshift 10
# define Nshift (Ishift((shift)N_INIT( \
	GetNode(sizeof(struct Rshift),Kshift), \
	Kshift,sizeof(struct Rshift))))
# define Dshift(n) {Fshift(n); FreeNode(n, Kshift);}
# define Ishift(N) (N)
# define Fshift(N)

typedef struct Rshiftred * shiftred;
# define Kshiftred 12
# define Nshiftred (Ishiftred((shiftred)N_INIT( \
	GetNode(sizeof(struct Rshiftred),Kshiftred), \
	Kshiftred,sizeof(struct Rshiftred))))
# define Dshiftred(n) {Fshiftred(n); FreeNode(n, Kshiftred);}
# define Ishiftred(N) (N)
# define Fshiftred(N)


/* Classes */
typedef union {
    someptr IDLinternal;
    CPEntrytype IDLclassCommon;
    shift Vshift;
    reduce Vreduce;
    shiftred Vshiftred;
    accept Vaccept;
} Entrytype;


/* Sets and Sequences */
typedef struct {
	int size;
	int length;
	Entrytype *array;
} ARREntrytype;
# define SEQEntrytype ARREntrytype
# define inSEQEntrytype(Entrytypearray, aEntrytype) IDLInArray(Entrytypearray, aEntrytype.IDLinternal)
# define initializeSEQEntrytype(Entrytypearray) IDLInitializeArray(Entrytypearray,0)
# define appendfrontSEQEntrytype(Entrytypearray, aEntrytype) IDLArrayAddFront(&(Entrytypearray), aEntrytype.IDLinternal)
# define appendrearSEQEntrytype(Entrytypearray, aEntrytype) IDLArrayAddRear(&(Entrytypearray), aEntrytype.IDLinternal)
# define orderedinsertSEQEntrytype(Entrytypearray, aEntrytype, cmpfn) IDLArrayOrderedInsert(&(Entrytypearray), aEntrytype.IDLinternal,cmpfn)
# define retrievefirstSEQEntrytype(Entrytypearray, aEntrytype) 	aEntrytype = IDLArrayRetrieveFirst(Entrytypearray)
# define retrievelastSEQEntrytype(Entrytypearray, aEntrytype) 		aEntrytype = IDLArrayRetrieveLast(Entrytypearray)
# define ithinSEQEntrytype(Entrytypearray,index,aEntrytype) 	aEntrytype = IthInArray(Entrytypearray, index)
# define removefirstSEQEntrytype(Entrytypearray) IDLArrayRemoveFirstElem(&(Entrytypearray))
# define removeSEQEntrytype(Entrytypearray, aEntrytype) IDLArrayRemoveElem(&(Entrytypearray), aEntrytype.IDLinternal)
# define removelastSEQEntrytype(Entrytypearray) IDLArrayRemoveLast(Entrytypearray)
# define emptySEQEntrytype(Entrytypearray) IDLEmptyArray(Entrytypearray)
# define lengthSEQEntrytype(Entrytypearray) IDLLengthArray(Entrytypearray)
# define copySEQEntrytype(Entrytypearray) (SEQEntrytype)IDLArrayCopy(Entrytypearray)
# define tailSEQEntrytype(Entrytypearray) (SEQEntrytype)IDLArrayTail(Entrytypearray)
# define sortSEQEntrytype(Entrytypearray) Entrytypearray = (SEQEntrytype)IDLArraySort(Entrytypearray)
# define foreachinSEQEntrytype(Entrytypearray, SEntrytype, AEntrytype) foreachinArray(Entrytypearray, SEntrytype, AEntrytype)
typedef struct {
	int size;
	int length;
	Rowtype *array;
} ARRRowtype;
# define SEQRowtype ARRRowtype
# define inSEQRowtype(Rowtypearray, aRowtype) IDLInArray(Rowtypearray, aRowtype)
# define initializeSEQRowtype(Rowtypearray) IDLInitializeArray(Rowtypearray,0)
# define appendfrontSEQRowtype(Rowtypearray, aRowtype) IDLArrayAddFront(&(Rowtypearray), aRowtype)
# define appendrearSEQRowtype(Rowtypearray, aRowtype) IDLArrayAddRear(&(Rowtypearray), aRowtype)
# define orderedinsertSEQRowtype(Rowtypearray, aRowtype, cmpfn) IDLArrayOrderedInsert(&(Rowtypearray), aRowtype,cmpfn)
# define retrievefirstSEQRowtype(Rowtypearray, aRowtype) 	aRowtype = IDLArrayRetrieveFirst(Rowtypearray)
# define retrievelastSEQRowtype(Rowtypearray, aRowtype) 		aRowtype = IDLArrayRetrieveLast(Rowtypearray)
# define ithinSEQRowtype(Rowtypearray,index,aRowtype) 	aRowtype = IthInArray(Rowtypearray, index)
# define removefirstSEQRowtype(Rowtypearray) IDLArrayRemoveFirstElem(&(Rowtypearray))
# define removeSEQRowtype(Rowtypearray, aRowtype) IDLArrayRemoveElem(&(Rowtypearray), aRowtype)
# define removelastSEQRowtype(Rowtypearray) IDLArrayRemoveLast(Rowtypearray)
# define emptySEQRowtype(Rowtypearray) IDLEmptyArray(Rowtypearray)
# define lengthSEQRowtype(Rowtypearray) IDLLengthArray(Rowtypearray)
# define copySEQRowtype(Rowtypearray) (SEQRowtype)IDLArrayCopy(Rowtypearray)
# define tailSEQRowtype(Rowtypearray) (SEQRowtype)IDLArrayTail(Rowtypearray)
# define sortSEQRowtype(Rowtypearray) Rowtypearray = (SEQRowtype)IDLArraySort(Rowtypearray)
# define foreachinSEQRowtype(Rowtypearray, SRowtype, ARowtype) foreachinArray(Rowtypearray, SRowtype, ARowtype)

/* Class Attributes */
struct CAEntrytype {
    IDLnodeHeader IDLhidden;
    u_short CMR_DT_index;
};

/* Node Structures*/
struct RRowtype { IDLnodeHeader IDLhidden;
    SEQEntrytype Entries;
    u_short Errsymb;
};
struct Rabsparsertype { IDLnodeHeader IDLhidden;
    SEQRowtype ParsingTab;
    Boolean IsDeterm;
};
struct Raccept { IDLnodeHeader IDLhidden;
    u_short CMR_DT_index;
};
struct Rreduce { IDLnodeHeader IDLhidden;
    u_short CMR_DT_index;
    u_short Rule;
};
struct Rshift { IDLnodeHeader IDLhidden;
    u_short CMR_DT_index;
    u_short NextState;
};
struct Rshiftred { IDLnodeHeader IDLhidden;
    u_short CMR_DT_index;
    u_short Rule;
};

/* Port Declarations */
void WriteAbsparser();
absparsertype ReadAbsparser();

#endif
