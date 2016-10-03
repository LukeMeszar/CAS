# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/j/w/expr.specs.15013061.mapBnf"
expression: expression '-' term &'ExprMinus();'.
expression: expression '+' term &'ExprPlus();'.
expression: term.
primary: '0' &'ExprInt(0);'.
primary: '1' &'ExprInt(1);'.
primary: '2' &'ExprInt(2);'.
primary: '3' &'ExprInt(3);'.
primary: '4' &'ExprInt(4);'.
primary: '5' &'ExprInt(5);'.
primary: '6' &'ExprInt(6);'.
primary: '7' &'ExprInt(7);'.
primary: '8' &'ExprInt(8);'.
primary: '9' &'ExprInt(9);'.
primary: '(' expression ')'.
program: expression &'ExprFinl();'.
term: primary.
term: term '/' primary &'ExprDiv();'.
term: term '*' primary &'ExprTimes();'.
