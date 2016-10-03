%{
#include "inc/GMC.h"
extern int num_ParseErrors;
tp_Nod YY_Parse() {tp_Nod Nod;
num_ParseErrors = 0; Init_Lex(); Init_ConstructTree();
(void)yyparse(); Nod = End_ConstructTree();
return Nod;}
void yyerror(GMC_ARG(char*, s)) GMC_DCL(char*, s) 
{num_ParseErrors++; ParseError(s);}
int yylex() {return YY_Lex();}
%}

%token
TOK_BANNER 2
TOK_NEEDS 3
TOK_Word 4
TOK_Colon 5
TOK_Plus 6
TOK_Equals 7
TOK_LeftParen 8
TOK_RightParen 9
TOK_Percent 10
TOK_Slash 11
TOK_Semicolon 12
TOK_Question 13
TOK_LeftAngle 14
TOK_RightAngle 15
TOK_Ampersand 16
TOK_At 17
TOK_Asterisk 18
TOK_Dollar 19

%%
 xDerivationGraph :

    xDerivationGraph_1 {Action(1,1);} ;

 xDerivationGraph_1 :

    xDerivationGraph_1
    TOK_Semicolon
    xDGEntry {Action(0,2);} |
    
    xDGEntry;

 xDGEntry :
 {Action(0,0);} |

    TOK_BANNER
    TOK_Wordleaf {Action(2,1);} |

    xSourceType
    TOK_Equals
    TOK_RightAngle
    xObjectType {Action(3,2);} |

    xObjectType
    xDesc
    TOK_Equals
    TOK_RightAngle
    xDGEntry_1 {Action(5,3);} |

    xParameterType
    xDesc
    TOK_Equals
    TOK_RightAngle
    xObjectType {Action(4,3);} |

    TOK_Dollar
    TOK_Wordleaf
    xDesc
    TOK_Equals
    xParameterValue {Action(7,3);} |

    TOK_Wordleaf
    xArgs
    xNeeds
    TOK_Equals
    TOK_RightAngle
    xResults {Action(6,4);} ;

 xDGEntry_1 :

    xDGEntry_1
    xSuperType {Action(0,2);} |
    
    xSuperType;

 xSourceType :

    TOK_Wordleaf
    TOK_Asterisk {Action(8,1);} |

    TOK_Asterisk
    xSourceType_1 {Action(9,1);} ;

 xSourceType_1 :

    
    TOK_Wordleaf|

     {Action(0,0);} ;

 xParameterType :

    TOK_Plus
    TOK_Wordleaf;

 xObjectType :

    TOK_Colon
    TOK_Wordleaf;

 xForeignObjectType :

    TOK_Colon
    TOK_Wordleaf
    TOK_Asterisk
    TOK_Wordleaf {Action(0,2);} ;

 xDesc :

    TOK_Wordleaf
    TOK_Question|

    TOK_Wordleaf {Action(10,1);} ;

 xSuperType :

    TOK_LeftAngle
    xObjectType
    TOK_RightAngle {Action(11,1);} |

    xObjectType;

 xArgs :

    xArgs_1 {Action(12,1);} ;

 xArgs_1 :

    xArgs_1
    xArg {Action(0,2);} |
    
    xArg;

 xNeeds :

    TOK_NEEDS
    xNeeds_1 {Action(13,1);} |
 {Action(13,0);} ;

 xNeeds_1 :

    xNeeds_1
    xArg {Action(0,2);} |
    
    xArg;

 xResults :

    xResults_1 {Action(16,1);} |

    xForeignResult {Action(16,1);} ;

 xResults_1 :

    xResults_1
    xResult {Action(0,2);} |
    
    xResult;

 xResult :

    TOK_LeftParen
    xObjectType
    TOK_RightParen;

 xForeignResult :

    TOK_LeftParen
    xForeignObjectType
    TOK_RightParen {Action(17,1);} ;

 xArg :

    xVarWord|

    xFileArg|

    xFileArg
    TOK_At {Action(14,1);} |

    xFileArg
    TOK_Ampersand {Action(15,1);} ;

 xFileArg :

    TOK_LeftParen
    xOdinExpr1
    TOK_RightParen {Action(18,1);} ;

 xOdinExpr1 :

    xRoot|

    xOdinExpr1
    xOperation {Action(0,2);} |

    TOK_LeftParen
    xOdinExpr1
    TOK_RightParen;

 xRoot :

    TOK_LeftParen
    TOK_RightParen {Action(21,0);} |

    xVarWord|

    xObjectType {Action(19,1);} |

    xParameterType {Action(20,1);} |

    TOK_Slash {Action(22,0);} |

    TOK_Slash
    xVarWord {Action(23,1);} |

    TOK_Percent
    xVarWord {Action(30,1);} ;

 xOperation :

    xParameterType
    xOperation_1 {Action(24,2);} |

    xParameterType
    xFileArg {Action(25,2);} |

    xObjectType {Action(27,1);} |

    xObjectType
    TOK_Equals
    xObjectType {Action(28,2);} |

    TOK_Slash
    xVarWord {Action(31,1);} |

    TOK_Slash {Action(32,0);} |

    TOK_Percent
    xVarWord {Action(30,1);} ;

 xOperation_1 :

    
    xParameterValues|

     {Action(0,0);} ;

 xParameterValues :

    TOK_Equals
    xParameterValues_1 {Action(26,1);} ;

 xParameterValues_1 :

    xParameterValues_1
    xParameterValue {Action(0,2);} |
    
    xParameterValue;

 xParameterValue :

    xVarWord|

    xFileArg;

 xVarWord :

    TOK_Wordleaf|

    TOK_Dollar
    TOK_Wordleaf {Action(33,1);} ;

 TOK_Wordleaf : TOK_Word {Action(34,-1);} ;

%%
