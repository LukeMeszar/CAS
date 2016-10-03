# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/k/n/liga.dapto.16045844.dapto"





















aspect tree;

"eliproto.h"
"err.h"
"obstack.h"
"node.h"
"MONTblStack.h"

event tree* "Abstract tree has been constructed"
    (int root "Handle for root of tree",
     int parent "Handle for the parent of this root (if any)",
     int desc "Descendant number of root under parent (starting at 1)");

operation get_abs_prods "Return abstract productions: name lhs rhs"
    () : str
{
    char **s;
    extern char *abs_prods[];
    
    for (s = abs_prods; *s != (char *) 0; s++)
	DAPTO_RESULT_STR (*s);
}

operation get_all_nodes "Return all nodes and their children"
    (int root "Handle for the root node of the tree") : str
{
    Obstack obstk;
    NODEPTR *stack, n, c;
    int tos = 0, size = 0, num, i;
    extern int abs_nchild[];
    extern NODEPTR abs_child ELI_ARG((NODEPTR, int));












    obstack_init (&obstk);
    if (tos == size) { obstack_grow (&obstk, (void *) (&MONTblStackArray(root)), sizeof (NODEPTR)); stack = (NODEPTR *) obstack_base (&obstk); tos++; size++; } else stack[tos++] = (NODEPTR) (MONTblStackArray(root));
    while (tos != 0) {
	n = stack[--tos];
	if (n == NULLNODEPTR) {
	    DAPTO_RESULT_INTVAL (0);
	    DAPTO_RESULT_INTVAL (-1);
	    DAPTO_RESULT_INTVAL (0);
	} else {
            DAPTO_RESULT_INT (n->_uid);
            DAPTO_RESULT_INT (n->_prod);
            num = abs_nchild[n->_prod];
            DAPTO_RESULT_INT (num);
            for (i = 1; i <= num; i++) {
                c = abs_child (n, i);
                if (tos == size) { obstack_grow (&obstk, (void *) (&c), sizeof (NODEPTR)); stack = (NODEPTR *) obstack_base (&obstk); tos++; size++; } else stack[tos++] = (NODEPTR) (c);
            }
	}
    }
    stack = (NODEPTR *) obstack_finish (&obstk);
    obstack_free (&obstk, (void *) stack);
}

operation get_node "Return the production number and children of a node"
    (int node "Handle for the parent node") : str
{
    NODEPTR nodept;
    int i;
    extern int abs_nchild[];
    extern NODEPTR abs_child ELI_ARG((NODEPTR, int));

    nodept = MONTblStackArray(node);
    DAPTO_RESULT_INT (nodept->_prod);
    for (i = 1; i <= abs_nchild[nodept->_prod]; i++) {
         DAPTO_RESULT_INTVAL ((abs_child (nodept, i))->_uid);
    }
}

operation get_node_coords "Return the starting and ending coords of a node"
    (int node "Handle for the node") : str
{
    NODEPTR nodept;

    nodept = MONTblStackArray(node);
    DAPTO_RESULT_INT (LineOf (nodept->_coord));
    DAPTO_RESULT_INT (CumColOf (nodept->_coord));
    DAPTO_RESULT_INT (RLineOf (nodept->_coord));
    DAPTO_RESULT_INT (RCumColOf (nodept->_coord));
}

operation find_nodes "Return the nodes containing a coordinate"
    (int root "Handle for the root node of the tree",
     int line "Line number", int col "Column number") : str
{
    NODEPTR n, ch, save;
    int i, l1, c1, l2, c2;
    extern int abs_nchild[];
    extern NODEPTR abs_child ELI_ARG((NODEPTR, int));
	
    DAPTO_RESULT_INT (root);
    n = MONTblStackArray(root);
    do {
	save = n;
	for (i = 1; i <= abs_nchild[n->_prod]; i++) {
	    ch = abs_child (n, i);
	    if (ch == NULLNODEPTR)
		continue;
	    l1 = LineOf (ch->_coord);
   	    c1 = CumColOf (ch->_coord);
	    l2 = RLineOf (ch->_coord);
	    c2 = RCumColOf (ch->_coord);
	    if ((((line == l1) && (col >= c1)) || (line > l1)) &&
		(((line == l2) && (col <= c2)) || (line < l2))) {
	        DAPTO_RESULT_INT (ch->_uid);
	        n = ch;
		break;
	    }
	}
    } while (n != save);
}

end;
