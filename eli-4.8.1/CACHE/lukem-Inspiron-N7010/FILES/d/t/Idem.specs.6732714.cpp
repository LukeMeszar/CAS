# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/d/l/Analysis.con.6888342.con"

xRoot: xGrammar PTGSpec .


xRule:    xIdentifier / PtgType .
xSymbol:  xIdentifier / PtgType .

Syms:     [ xSymbol // '|' ] .


PTGSpec: PatternSpec* .
PatternSpec: PatternName ':' Items .
Items: Item* .
Item:
  '$' [ Number ] [ PtgType ] /
  '[' xIdentifier Items ']' /
  '{' Insert '}' .
Insert: Item+ .

