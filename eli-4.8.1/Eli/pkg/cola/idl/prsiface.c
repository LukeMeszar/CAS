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
** $Id: prsiface.c,v 1.7 1997/08/29 08:38:08 mjung Exp $
*/
static char rcs_id[]= "$Id: prsiface.c,v 1.7 1997/08/29 08:38:08 mjung Exp $";

/* prsiface.c - IDL read/mark/write routines generated by idlc, version 3.2 
    on Tue Apr 18 18:13:15 1989
*/

# include <stdio.h>
# include "prsiface.h"

Entrytype IDLtempEntrytype;

# define DynMode 0
# define TwoPassMode 1
# define FlatMode 0
# define DynFormat 0
# include "writer.h"
void Maccept();
void Waccept();
void Mshiftred();
void Wshiftred();
void Mreduce();
void Wreduce();
void Mshift();
void Wshift();
void MEntrytype();
void WEntrytype();
void MARREntrytype();
void WSEQEntrytype();
void MRowtype();
void WRowtype();
void MARRRowtype();
void WSEQRowtype();
void Mabsparsertype();
void Wabsparsertype();
extern void Mu_short();
/*  extern void MBoolean();  */
# define PWriteAbsparser 2

void WSEQEntrytype(Atype)
SEQEntrytype Atype;
{	register int len;
	register Entrytype *A;
	A = Atype.array;
	IDLoutC(OpenAngle);
	for (len=0; len<Atype.length;++len,++A) {
		IDLoutC(ListLink);
		WEntrytype(*A);
	}
	IDLoutC(CloseAngle);
}
void MARREntrytype(Atype)
ARREntrytype Atype;
{
	register Entrytype *A;
	register int len;
	len = Atype.length;
	for (A=Atype.array; len; len--, ++A)
		{ MEntrytype(*A); }
}
void WEntrytype (C)
Entrytype C;
{
	switch(typeof(C)) {
		case Kshift: Wshift(C.Vshift); break;
		case Kreduce: Wreduce(C.Vreduce); break;
		case Kshiftred: Wshiftred(C.Vshiftred); break;
		case Kaccept: Waccept(C.Vaccept); break;
		default: WError(ErrBadClassType);
		         fprintf(stderr, "\tBad class is %lu\n",typeof(C));
	}
}
void MEntrytype (C)
Entrytype C;
{
	switch(typeof(C)) {
		case Kshift: Mshift(C.Vshift); break;
		case Kreduce: Mreduce(C.Vreduce); break;
		case Kshiftred: Mshiftred(C.Vshiftred); break;
		case Kaccept: Maccept(C.Vaccept); break;
		default: WError(ErrBadClassType);
		         fprintf(stderr, "\tBad class is %lu\n",typeof(C));
	}
}
void WSEQRowtype(Atype)
SEQRowtype Atype;
{	register int len;
	register Rowtype *A;
	A = Atype.array;
	IDLoutC(OpenAngle);
	for (len=0; len<Atype.length;++len,++A) {
		IDLoutC(ListLink);
		WRowtype(*A);
	}
	IDLoutC(CloseAngle);
}
void MARRRowtype(Atype)
ARRRowtype Atype;
{
	register Rowtype *A;
	register int len;
	len = Atype.length;
	for (A=Atype.array; len; len--, ++A)
		{ MRowtype(*A); }
}
void MRowtype(n)
register Rowtype n;
{
	if (n==NULL) return;
	if (NodeTouched(n)) {
		MarkShared(n); return; }
	else {
		MarkTouched(n);
		{MARREntrytype(n->Entries);}
		{Mu_short(n->Errsymb);}
	}
}
void WRowtype(zzn)
register Rowtype zzn;
{
	register String Sep;
	if (zzn==NULL) {WError(ErrNullNode); return; }
	if (!NodeTouched(zzn)) {IDLoutLabel(zzn); IDLoutC(UpArrow); return; }
	else if (NodeShared(zzn)) {
		IDLoutLabel(zzn); IDLoutC(Colon);
		UnmarkShared(zzn); UnmarkTouched(zzn);
	} else {UnmarkTouched(zzn); }
	IDLout("Rowtype"); Sep = "[";
	{IDLout(Sep); IDLout("Entries"); IDLoutC(AttrSep);
	WSEQEntrytype(zzn->Entries);
	Sep = ";\n";
	}
	{IDLout(Sep); IDLout("Errsymb"); IDLoutC(AttrSep);
	Wu_short(zzn->Errsymb);
	Sep = ";\n";
	}
	if (Sep[0] != OpenBracket) IDLout("]\n");
}
void Mabsparsertype(n)
register absparsertype n;
{
	if (n==NULL) return;
	if (NodeTouched(n)) {
		MarkShared(n); return; }
	else {
		MarkTouched(n);
		{MARRRowtype(n->ParsingTab);}
		{MBoolean(n->IsDeterm);}
	}
}
void Wabsparsertype(zzn)
register absparsertype zzn;
{
	register String Sep;
	if (zzn==NULL) {WError(ErrNullNode); return; }
	if (!NodeTouched(zzn)) {IDLoutLabel(zzn); IDLoutC(UpArrow); return; }
	else if (NodeShared(zzn)) {
		IDLoutLabel(zzn); IDLoutC(Colon);
		UnmarkShared(zzn); UnmarkTouched(zzn);
	} else {UnmarkTouched(zzn); }
	IDLout("absparsertype"); Sep = "[";
	{IDLout(Sep); IDLout("ParsingTab"); IDLoutC(AttrSep);
	WSEQRowtype(zzn->ParsingTab);
	Sep = ";\n";
	}
	{IDLout(Sep); IDLout("IsDeterm"); IDLoutC(AttrSep);
	WBoolean(zzn->IsDeterm);
	Sep = ";\n";
	}
	if (Sep[0] != OpenBracket) IDLout("]\n");
}
void Maccept(n)
register accept n;
{
	if (n==NULL) return;
	if (NodeTouched(n)) {
		MarkShared(n); return; }
	else {
		MarkTouched(n);
		{Mu_short(n->CMR_DT_index);}
	}
}
void Waccept(zzn)
register accept zzn;
{
	register String Sep;
	if (zzn==NULL) {WError(ErrNullNode); return; }
	if (!NodeTouched(zzn)) {IDLoutLabel(zzn); IDLoutC(UpArrow); return; }
	else if (NodeShared(zzn)) {
		IDLoutLabel(zzn); IDLoutC(Colon);
		UnmarkShared(zzn); UnmarkTouched(zzn);
	} else {UnmarkTouched(zzn); }
	IDLout("accept"); Sep = "[";
	{IDLout(Sep); IDLout("CMR_DT_index"); IDLoutC(AttrSep);
	Wu_short(zzn->CMR_DT_index);
	Sep = ";\n";
	}
	if (Sep[0] != OpenBracket) IDLout("]\n");
}
void Mreduce(n)
register reduce n;
{
	if (n==NULL) return;
	if (NodeTouched(n)) {
		MarkShared(n); return; }
	else {
		MarkTouched(n);
		{Mu_short(n->CMR_DT_index);}
		{Mu_short(n->Rule);}
	}
}
void Wreduce(zzn)
register reduce zzn;
{
	register String Sep;
	if (zzn==NULL) {WError(ErrNullNode); return; }
	if (!NodeTouched(zzn)) {IDLoutLabel(zzn); IDLoutC(UpArrow); return; }
	else if (NodeShared(zzn)) {
		IDLoutLabel(zzn); IDLoutC(Colon);
		UnmarkShared(zzn); UnmarkTouched(zzn);
	} else {UnmarkTouched(zzn); }
	IDLout("reduce"); Sep = "[";
	{IDLout(Sep); IDLout("CMR_DT_index"); IDLoutC(AttrSep);
	Wu_short(zzn->CMR_DT_index);
	Sep = ";\n";
	}
	{IDLout(Sep); IDLout("Rule"); IDLoutC(AttrSep);
	Wu_short(zzn->Rule);
	Sep = ";\n";
	}
	if (Sep[0] != OpenBracket) IDLout("]\n");
}
void Mshift(n)
register shift n;
{
	if (n==NULL) return;
	if (NodeTouched(n)) {
		MarkShared(n); return; }
	else {
		MarkTouched(n);
		{Mu_short(n->CMR_DT_index);}
		{Mu_short(n->NextState);}
	}
}
void Wshift(zzn)
register shift zzn;
{
	register String Sep;
	if (zzn==NULL) {WError(ErrNullNode); return; }
	if (!NodeTouched(zzn)) {IDLoutLabel(zzn); IDLoutC(UpArrow); return; }
	else if (NodeShared(zzn)) {
		IDLoutLabel(zzn); IDLoutC(Colon);
		UnmarkShared(zzn); UnmarkTouched(zzn);
	} else {UnmarkTouched(zzn); }
	IDLout("shift"); Sep = "[";
	{IDLout(Sep); IDLout("CMR_DT_index"); IDLoutC(AttrSep);
	Wu_short(zzn->CMR_DT_index);
	Sep = ";\n";
	}
	{IDLout(Sep); IDLout("NextState"); IDLoutC(AttrSep);
	Wu_short(zzn->NextState);
	Sep = ";\n";
	}
	if (Sep[0] != OpenBracket) IDLout("]\n");
}
void Mshiftred(n)
register shiftred n;
{
	if (n==NULL) return;
	if (NodeTouched(n)) {
		MarkShared(n); return; }
	else {
		MarkTouched(n);
		{Mu_short(n->CMR_DT_index);}
		{Mu_short(n->Rule);}
	}
}
void Wshiftred(zzn)
register shiftred zzn;
{
	register String Sep;
	if (zzn==NULL) {WError(ErrNullNode); return; }
	if (!NodeTouched(zzn)) {IDLoutLabel(zzn); IDLoutC(UpArrow); return; }
	else if (NodeShared(zzn)) {
		IDLoutLabel(zzn); IDLoutC(Colon);
		UnmarkShared(zzn); UnmarkTouched(zzn);
	} else {UnmarkTouched(zzn); }
	IDLout("shiftred"); Sep = "[";
	{IDLout(Sep); IDLout("CMR_DT_index"); IDLoutC(AttrSep);
	Wu_short(zzn->CMR_DT_index);
	Sep = ";\n";
	}
	{IDLout(Sep); IDLout("Rule"); IDLoutC(AttrSep);
	Wu_short(zzn->Rule);
	Sep = ";\n";
	}
	if (Sep[0] != OpenBracket) IDLout("]\n");
}
void WriteAbsparser (filePtr, zzN
# if DynMode
, mode
# endif
# if DynFormat
, format
# endif
)
FILE * filePtr;
absparsertype zzN;
# if DynMode
int mode;
# endif
# if DynFormat
int format;
# endif
{	IDLportState = PWriteAbsparser;
	IDLcurrentFile = filePtr;
# if DynMode
	switch (mode) {
	case FLAT:
# endif
# if (DynMode || FlatMode)
		O_Node((int)zzN);
		while (doList != NULL) {
		   register struct ncell *l;
		   l = doList; doList = l->next;
		   O_Node(l->value); FreeHeap(l);
		}
		while (doneList != NULL) {
		    register struct ncell *l;
		    l = doneList;
		    UnmarkTouched(l->value); 
		    UnmarkShared(l->value);
		    doneList = l->next;FreeHeap(l);
		}
# endif
# if DynMode
		break;
	case TWOPASS:
# endif
# if DynMode || TwoPassMode
		fprintf(IDLcurrentFile, "-- structure AbsParser\n");
		Mabsparsertype(zzN);
		Wabsparsertype(zzN);

# endif
# if DynMode
		break;
	default:
		WError(ErrPortMode);
	}
# endif
	fputs("#\n", IDLcurrentFile);
	return;
}
# include "reader.h"
extern ntype *IDLAllNodeTypes;
extern natype *IDLNodeAttributes;
extern int IDLnum_nodetypes;
static ntype AllNodeTypes[] = {
  { "Rowtype", KRowtype },
  { "absparsertype", Kabsparsertype },
  { "accept", Kaccept },
  { "reduce", Kreduce },
  { "shift", Kshift },
  { "shiftred", Kshiftred },
  { NULL, 0}
};
static natype NodeAttributes[] = {
  { "Entries", "Errsymb", NULL },
  { "ParsingTab", "IsDeterm", NULL },
  { "CMR_DT_index", NULL },
  { "CMR_DT_index", "Rule", NULL },
  { "CMR_DT_index", "NextState", NULL },
  { "CMR_DT_index", "Rule", NULL },
  { NULL }
};
static int num_nodetypes  = 6;
static int max_attributes  = 3;
# define Gaccept(R) ((accept)((R)->UnionField.NodeField))

# define Gshiftred(R) ((shiftred)((R)->UnionField.NodeField))

# define Greduce(R) ((reduce)((R)->UnionField.NodeField))

# define Gshift(R) ((shift)((R)->UnionField.NodeField))

Entrytype GEntrytype();
ARREntrytype GARREntrytype();
#define GSETEntrytype(R) GARREntrytype(R)
#define GSEQEntrytype(R) GARREntrytype(R)

# define GRowtype(R) ((Rowtype)((R)->UnionField.NodeField))
ARRRowtype GARRRowtype();
#define GSETRowtype(R) GARRRowtype(R)
#define GSEQRowtype(R) GARRRowtype(R)

# define Gabsparsertype(R) ((absparsertype)((R)->UnionField.NodeField))

absparsertype ReadAbsparser(zzF)
FILE *zzF;
{	absparsertype zzC;
	NodeType zzN;
	NodeType prsifaceNodeAlloc();
	void prsifaceAttrStore();
	extern PF_NodeType GenericNodeAlloc;
	extern PF_AttrStore GenericAttrStore;

	IDLAllNodeTypes = AllNodeTypes;
	IDLNodeAttributes = NodeAttributes;
	IDLnum_nodetypes = num_nodetypes;
	GenericNodeAlloc = prsifaceNodeAlloc;
	GenericAttrStore = prsifaceAttrStore;
	zzN = Reader(zzF);
	if (!OK) {
		zzC = NULL;
	}
	else if (TypeNode(zzN) == Kabsparsertype) {
		zzC = (absparsertype)AtNode(zzN);}
	else {
		Error(ErrBadRootType, Lex.Pos);
		OK = 0;
		zzC = NULL; }
	return(zzC);
}
NodeType prsifaceNodeAlloc(zzN)
register int zzN;
{	register NodeType zznt;
	switch(zzN) {
	    case KRowtype: SetNPtr(zznt, NRowtype); break;
	    case Kabsparsertype: SetNPtr(zznt, Nabsparsertype); break;
	    case Kaccept: SetNPtr(zznt, Naccept); break;
	    case Kreduce: SetNPtr(zznt, Nreduce); break;
	    case Kshift: SetNPtr(zznt, Nshift); break;
	    case Kshiftred: SetNPtr(zznt, Nshiftred); break;
	    default: Error(ErrBadNodeType, Lex.Pos);
	             OK = 0;
	             break;	}
	return(zznt);
}
ARREntrytype GARREntrytype(R)
RepType R;
{	ARREntrytype Atype;
	register SeqType S;
	register int size;
	register Entrytype *A;
	size = 0;
	S = R->UnionField.seqVal;
	while (S) {++size; S=S->next;}
	A = (Entrytype *)IDLNewArray(size);
	Atype.array = A;
	Atype.size = size;
	Atype.length = size;
	S = R->UnionField.seqVal;
	while (S) {
		*A = GEntrytype(S->value);
		S = S->next;
		A++;
	}
	return(Atype);
}
Entrytype GEntrytype (R)
register RepType R;
{
	Entrytype Ret;
	switch(R->UnionField.NodeField->IDLhidden.TypeID) {
		case Kshift: Ret.Vshift = Gshift(R); break;
		case Kreduce: Ret.Vreduce = Greduce(R); break;
		case Kshiftred: Ret.Vshiftred = Gshiftred(R); break;
		case Kaccept: Ret.Vaccept = Gaccept(R); break;
		default: Error(ErrBadClassNode, Lex.Pos);
	}
	return(Ret);
}
ARRRowtype GARRRowtype(R)
RepType R;
{	ARRRowtype Atype;
	register SeqType S;
	register int size;
	register Rowtype *A;
	size = 0;
	S = R->UnionField.seqVal;
	while (S) {++size; S=S->next;}
	A = (Rowtype *)IDLNewArray(size);
	Atype.array = A;
	Atype.size = size;
	Atype.length = size;
	S = R->UnionField.seqVal;
	while (S) {
		*A = GRowtype(S->value);
		S = S->next;
		A++;
	}
	return(Atype);
}

extern Boolean GBoolean();

void prsifaceAttrStore(N,A,R)
register NodeType N;
register AttrDesc A;
register RepType R;
{	switch(N->IDLhidden.TypeID) {
		case KRowtype: switch (A) {
			case 1: ((Rowtype)(N))->Entries = GSEQEntrytype(R); 
			         break;
			case 2: ((Rowtype)(N))->Errsymb = Gu_short(R); 
			         break;
			default: Error(ErrBadAttribute,Lex.Pos); 
		} break;
		case Kabsparsertype: switch (A) {
			case 1: ((absparsertype)(N))->ParsingTab = GSEQRowtype(R); 
			         break;
			case 2: ((absparsertype)(N))->IsDeterm = GBoolean(R); 
			         break;
			default: Error(ErrBadAttribute,Lex.Pos); 
		} break;
		case Kaccept: switch (A) {
			case 1: ((accept)(N))->CMR_DT_index = Gu_short(R); 
			         break;
			default: Error(ErrBadAttribute,Lex.Pos); 
		} break;
		case Kreduce: switch (A) {
			case 1: ((reduce)(N))->CMR_DT_index = Gu_short(R); 
			         break;
			case 2: ((reduce)(N))->Rule = Gu_short(R); 
			         break;
			default: Error(ErrBadAttribute,Lex.Pos); 
		} break;
		case Kshift: switch (A) {
			case 1: ((shift)(N))->CMR_DT_index = Gu_short(R); 
			         break;
			case 2: ((shift)(N))->NextState = Gu_short(R); 
			         break;
			default: Error(ErrBadAttribute,Lex.Pos); 
		} break;
		case Kshiftred: switch (A) {
			case 1: ((shiftred)(N))->CMR_DT_index = Gu_short(R); 
			         break;
			case 2: ((shiftred)(N))->Rule = Gu_short(R); 
			         break;
			default: Error(ErrBadAttribute,Lex.Pos); 
		} break;
		default: Error(ErrBadNodeType, Lex.Pos); break;
	}
	DelRep(R);
}