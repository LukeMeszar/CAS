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
TOK_EOF_ 2
TOK_ERR_ 3
TOK_INCLUDE 4
TOK_SCANNER 5
TOK_NODES 6
TOK_RULES 7
TOK_Name 8
TOK_AString 9
TOK_QString 10
TOK_Equals 11
TOK_DoubleArrow 12
TOK_SingleArrow 13
TOK_Plus 14
TOK_Star 15
TOK_DoubleSlash 16
TOK_SemiColon 17
TOK_Question 18
TOK_LeftParen 19
TOK_RightParen 20

%%
 xTreeGrammar :

    xIncludes
    xScanner
    xNodes
    xRules {Action(1,4);} ;

 xIncludes :

    xIncludes_1 {Action(2,1);} ;

 xIncludes_1 :

    
    TOK_INCLUDE
    xIncludes_101|

     {Action(0,0);} ;

 xIncludes_101 :

    xIncludes_101
    xIncludeFile {Action(0,2);} |
    
    xIncludeFile;

 xIncludeFile :

    TOK_AStringleaf|

    TOK_QStringleaf;

 xScanner :

    xScanner_1 {Action(3,1);} ;

 xScanner_1 :

    
    TOK_SCANNER
    xScanner_101|

     {Action(0,0);} ;

 xScanner_101 :

    xScanner_101
    xLexicalDefinition {Action(0,2);} |
    
    xLexicalDefinition;

 xLexicalDefinition :

    TOK_EOF_
    TOK_Equals
    TOK_Nameleaf {Action(4,1);} |

    TOK_ERR_
    TOK_Equals
    TOK_Nameleaf {Action(5,1);} |

    TOK_AStringleaf
    TOK_Equals
    TOK_Nameleaf {Action(6,2);} |

    TOK_QStringleaf
    TOK_Equals
    TOK_Nameleaf
    TOK_DoubleArrow
    TOK_QStringleaf {Action(7,3);} ;

 xNodes :

    xNodes_1 {Action(8,1);} ;

 xNodes_1 :

    
    TOK_NODES
    xNodes_101|

     {Action(0,0);} ;

 xNodes_101 :

    xNodes_101
    TOK_QStringleaf {Action(0,2);} |
    
    TOK_QStringleaf;

 xRules :

    xRules_1 {Action(9,1);} ;

 xRules_1 :

    
    TOK_RULES
    xRules_101|

     {Action(0,0);} ;

 xRules_101 :

    xRules_101
    xRule {Action(0,2);} |
    
    xRule;

 xRule :

    TOK_Nameleaf
    xAlternateList
    TOK_SemiColon {Action(10,2);} ;

 xAlternateList :

    xAlternateList_1 {Action(11,1);} ;

 xAlternateList_1 :

    xAlternateList_1
    xAlternate {Action(0,2);} |
    
    xAlternate;

 xAlternate :

    TOK_SingleArrow
    xExpression
    xAlternate_1 {Action(12,2);} ;

 xAlternate_1 :

    
    xTreeSpec|

     {Action(0,0);} ;

 xExpression :

    xExpression_1 {Action(-13,1);} ;

 xExpression_1 :

    xExpression_1
    xTerm {Action(0,2);} |

     {Action(0,0);} ;

 xTerm :

    xElement
    TOK_DoubleSlash
    xElement {Action(14,2);} |

    xElement
    TOK_Plus {Action(15,1);} |

    xElement
    TOK_Star {Action(16,1);} |

    xElement
    TOK_Question {Action(17,1);} |

    xElement;

 xElement :

    TOK_LeftParen
    xExpression
    TOK_RightParen|

    TOK_Nameleaf|

    TOK_QStringleaf|

    TOK_AStringleaf;

 xTreeSpec :

    TOK_DoubleArrow
    xNodeName|

    TOK_DoubleArrow
    xNodeName
    TOK_Question {Action(18,1);} |

    TOK_DoubleArrow
    TOK_LeftParen
    xNodeName
    TOK_RightParen {Action(19,1);} ;

 xNodeName :

    TOK_QStringleaf;

 TOK_Nameleaf : TOK_Name {Action(20,-1);} ;

 TOK_AStringleaf : TOK_AString {Action(21,-1);} ;

 TOK_QStringleaf : TOK_QString {Action(22,-1);} ;

%%
