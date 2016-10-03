# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/Eli/tests/digitcalc/expr.con"



program: expression &'ExprFinl();' .

expression:
   term /
   expression '+' term &'ExprPlus();' /
   expression '-' term &'ExprMinus();' .

term:
   primary /
   term '*' primary &'ExprTimes();' /
   term '/' primary &'ExprDiv();' .

primary:
   '(' expression ')' .
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/Eli/tests/digitcalc/digit.con"



primary:
   '0' &'ExprInt(0);' /
   '1' &'ExprInt(1);' /
   '2' &'ExprInt(2);' /
   '3' &'ExprInt(3);' /
   '4' &'ExprInt(4);' /
   '5' &'ExprInt(5);' /
   '6' &'ExprInt(6);' /
   '7' &'ExprInt(7);' /
   '8' &'ExprInt(8);' /
   '9' &'ExprInt(9);' .
