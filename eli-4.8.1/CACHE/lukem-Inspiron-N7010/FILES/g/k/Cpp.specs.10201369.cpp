# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/j/Cpp.specs.10195865.mapBnf"
G1: G1 '|' xSymbol.
G1: xSymbol.
G2: .
G2: G2 PatternSpec.
G3: .
G3: G3 Item.
G4: G4 Item.
G4: Item.
Insert: G4.
Item: '$'.
Item: '{' Insert '}'.
Item: '$' Number.
Item: '$' Number PtgType.
Item: '$' PtgType.
Items: G3.
Item: '[' xIdentifier Items ']'.
PatternSpec: PatternName ':' Items.
PTGSpec: G2.
Syms: .
Syms: G1.
xRoot: xGrammar PTGSpec.
xRule: PtgType.
xRule: xIdentifier.
xSymbol: PtgType.
xSymbol: xIdentifier.
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/g/j/Cpp.specs.10197369.ligaProd"
RULE rule_18:	xGrammar LISTOF xProduction END;
RULE rule_17:	xProduction ::= 'RULE' xRule ':' xSymbol '::=' xRHS 'END' ';' END;
RULE rule_16:	xProduction ::= 'RULE' xRule ':' xSymbol 'LISTOF' Syms 'END' ';' END;
RULE rule_15:	xRHS LISTOF Element END;
RULE rule_14:	Syms LISTOF xSymbol END;
RULE rule_13:	Element ::= xSymbol END;
RULE rule_12:	Element ::= '$' xSymbol END;
RULE rule_11:	Element ::= xLiteral END;
RULE rule_10:	PatternSpec ::= PatternName ':' Items END;
RULE rule_9:	PatternName ::= xIdentifier END;
RULE rule_8:	Items LISTOF Item END;
RULE rule_7:	Item ::= CString END;
RULE rule_6:	Item ::= '$' END;
RULE rule_5:	Item ::= '$' Number END;
RULE rule_4:	Item ::= '$' PtgType END;
RULE rule_3:	Item ::= '$' Number PtgType END;
RULE rule_2:	Item ::= '[' xIdentifier Items ']' END;
RULE rule_1:	Item ::= '{' Items '}' END;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/d/l/Analysis.map.6886704.mapSrc"

MAPSYM
Items ::= Insert .
