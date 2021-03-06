# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/n/attr_mon.dapto.16041592.dapto"
aspect attribution;


"node.h"
"nodecode.h"
"eliproto.h"
"MONTblStack.h"

operation get_symb_attrs
	"Return the attribute names and types for a particular node"
	(int root "Pointer to the relevant node") : str
{ switch (LHSMAP[(MONTblStackArray(root))->_prod]) {
	case SYMBVariableDeclList:
		break;
	case SYMBStatementList:
		break;
	case SYMBAxiom:
		break;
	case SYMBOptInitialize:
		break;
	case SYMBVarIdList:
		break;
	case SYMBVariableDeclSeg:
		DAPTO_RESULT_STR ("type tOilType");
		break;
	case SYMBParameterDecl:
		break;
	case SYMBVariableDecl:
		break;
	case SYMBUnop:
		DAPTO_RESULT_STR ("operator tOilOp");
		DAPTO_RESULT_STR ("indication tOilOp");
		break;
	case SYMBBinop:
		DAPTO_RESULT_STR ("operator tOilOp");
		DAPTO_RESULT_STR ("indication tOilOp");
		break;
	case SYMBNotop:
		DAPTO_RESULT_STR ("operator tOilOp");
		DAPTO_RESULT_STR ("indication tOilOp");
		break;
	case SYMBShortCircuitOp:
		DAPTO_RESULT_STR ("operator tOilOp");
		DAPTO_RESULT_STR ("indication tOilOp");
		break;
	case SYMBParameterList:
		break;
	case SYMBResultType:
		DAPTO_RESULT_STR ("type tOilType");
		break;
	case SYMBWhileStmt:
		DAPTO_RESULT_STR ("ContinueLbl DefTableKey");
		DAPTO_RESULT_STR ("BreakLbl DefTableKey");
		break;
	case SYMBExpression:
		DAPTO_RESULT_STR ("possible tOilTypeSet");
		DAPTO_RESULT_STR ("yields tOilType");
		break;
	case SYMBStatement:
		break;
	case SYMBCompound:
		DAPTO_RESULT_STR ("Env Environment");
		break;
	case SYMBProgram:
		DAPTO_RESULT_STR ("Env Environment");
		DAPTO_RESULT_STR ("type tOilType");
		DAPTO_RESULT_STR ("ContinueLbl DefTableKey");
		DAPTO_RESULT_STR ("BreakLbl DefTableKey");
		break;
	case SYMBIdUse:
		DAPTO_RESULT_STR ("Key DefTableKey");
		DAPTO_RESULT_STR ("Sym int");
		break;
	case SYMBIdDef:
		DAPTO_RESULT_STR ("Key DefTableKey");
		DAPTO_RESULT_STR ("Sym int");
		break;
	default: DAPTO_RESULT_STR ("unknown node type");
}}

operation get_rule_attrs
	"Return the attribute names and types for a particular node"
	(int root "Pointer to the relevant node") : str
{ switch ((MONTblStackArray(root))->_prod) {
	case RULErule_15:
		break;
	case RULErule_14:
		break;
	case RULErule_13:
		break;
	case RULErule_12:
		break;
	case RULErule_11:
		break;
	case RULErule_10:
		break;
	case RULErule_9:
		break;
	case RULErule_8:
		break;
	case RULErule_7:
		break;
	case RULErule_6:
		break;
	case RULErule_5:
		break;
	case RULErule_4:
		break;
	case RULErule_3:
		break;
	case RULErule_2:
		break;
	case RULErule_1:
		break;
	case RULEMonadicExp:
		break;
	case RULEDyadicExp:
		break;
	case RULEIdnVal:
		break;
	case RULEFloatVal:
		break;
	case RULEIntVal:
		break;
	case RULEFloatParDecl:
		break;
	case RULEIntParDecl:
		break;
	case RULEInitialize:
		break;
	case RULEVarDecl:
		break;
	case RULEFloatVar:
		break;
	case RULEIntVar:
		break;
	case RULEUMinusOp:
		break;
	case RULEPercentOp:
		break;
	case RULESlashOp:
		break;
	case RULEStarOp:
		break;
	case RULEMinusOp:
		break;
	case RULEPlusOp:
		break;
	case RULEGreaterOp:
		break;
	case RULELessOp:
		break;
	case RULEEqualOp:
		break;
	case RULEExclOp:
		break;
	case RULENotExp:
		break;
	case RULEAmpOp:
		break;
	case RULEBarOp:
		break;
	case RULEShortCircuitExp:
		break;
	case RULECondExp:
		break;
	case RULEAssignExp:
		DAPTO_RESULT_STR ("possible tOilTypeSet");
		DAPTO_RESULT_STR ("operator tOilOp");
		break;
	case RULEExprStmt:
		break;
	case RULEFloatResult:
		break;
	case RULEIntResult:
		break;
	case RULESource:
		break;
	case RULEReturnStmt:
		DAPTO_RESULT_STR ("operator tOilOp");
		break;
	case RULEContinueStmt:
		break;
	case RULEBreakStmt:
		break;
	case RULELoop:
		break;
	case RULETwoSided:
		break;
	case RULEOneSided:
		break;
	case RULEAppliedOccurrence:
		break;
	case RULEDefiningOccurrence:
		break;
	default: DAPTO_RESULT_STR ("unknown node type");
}}

operation get_rule_terms
	"Return terminal names and types for the rule applied at a node"
	(int root "Pointer to the relevant node") : str
{ switch ((MONTblStackArray(root))->_prod) {
	case RULEAssignExp:
		break;
	case RULECondExp:
		break;
	case RULEShortCircuitExp:
		break;
	case RULENotExp:
		break;
	case RULEIntVal:
		DAPTO_RESULT_STR ("IntDenotation int");
		break;
	case RULEFloatVal:
		DAPTO_RESULT_STR ("FloatDenotation int");
		break;
	case RULEIdnVal:
		break;
	case RULEDyadicExp:
		break;
	case RULEMonadicExp:
		break;
	case RULEDefiningOccurrence:
		DAPTO_RESULT_STR ("Identifier int");
		break;
	case RULEOneSided:
		break;
	case RULETwoSided:
		break;
	case RULELoop:
		break;
	case RULEBreakStmt:
		break;
	case RULEContinueStmt:
		break;
	case RULEReturnStmt:
		break;
	case RULESource:
		DAPTO_RESULT_STR ("Identifier int");
		break;
	case RULEExprStmt:
		break;
	case RULEBarOp:
		break;
	case RULEAmpOp:
		break;
	case RULEExclOp:
		break;
	case RULEEqualOp:
		break;
	case RULELessOp:
		break;
	case RULEGreaterOp:
		break;
	case RULEPlusOp:
		break;
	case RULEMinusOp:
		break;
	case RULEStarOp:
		break;
	case RULESlashOp:
		break;
	case RULEPercentOp:
		break;
	case RULEUMinusOp:
		break;
	case RULEIntVar:
		break;
	case RULEFloatVar:
		break;
	case RULEVarDecl:
		break;
	case RULEInitialize:
		break;
	case RULEIntParDecl:
		break;
	case RULEFloatParDecl:
		break;
	case RULErule_2:
		break;
	case RULErule_3:
		break;
	case RULErule_4:
		break;
	case RULErule_5:
		break;
	case RULErule_6:
		break;
	case RULErule_7:
		break;
	case RULErule_8:
		break;
	case RULErule_9:
		break;
	case RULErule_10:
		break;
	case RULErule_11:
		break;
	case RULErule_12:
		break;
	case RULErule_13:
		break;
	case RULErule_14:
		break;
	case RULErule_15:
		break;
	case RULEAppliedOccurrence:
		DAPTO_RESULT_STR ("Identifier int");
		break;
	case RULEIntResult:
		break;
	case RULEFloatResult:
		break;
	case RULErule_1:
		break;
	default: DAPTO_RESULT_STR ("unknown node type");
}}

event term_int
	"A terminal value of type int is available"
	(int root "Pointer to the left-hand side node of the rule where the terminal appears",
	 str name "Name of the terminal",
	 int value "Value of the terminal");

event attr_int
	"An attribute of type int has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 int value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_POSITION
	"An attribute of type POSITION has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 POSITION value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_NODEPTR
	"An attribute of type NODEPTR has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 NODEPTR value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_tOilOp
	"An attribute of type tOilOp has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 tOilOp value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_tOilTypeSet
	"An attribute of type tOilTypeSet has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 tOilTypeSet value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_tOilType
	"An attribute of type tOilType has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 tOilType value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_DefTableKey
	"An attribute of type DefTableKey has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 DefTableKey value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event attr_Environment
	"An attribute of type Environment has been evaluated"
	(int root "Pointer to the attribute's node",
	 int is_symb "Is a symbol attribute",
	 str name "Name of the attribute",
	 Environment value "Value of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event computation
	"A plain computation has been computed"
	(int root "Pointer to the node that is the computation's context",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");

event void_comp
	"A computation associated with a VOID attribute has been evaluated"
	(int root "Pointer to the attribute's node",
	 str name "Name of the attribute",
	 int line "The line number of the computation in the specification",
	 int col "The column of the computation in the specification");


end;
