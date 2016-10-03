# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/clp/lib/clplib.pdl"























ClpValue : int;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/h/CoordCmp.pdl.5393593.pdl"

"CoordCmp.h"
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/i/PropLib.pdl.5394901.pdl"

TYPE SetGet (DefTableKey key, TYPE init, TYPE reset)
{ if (key == NoKey) return init;
  if (ACCESS)   {VALUE = reset; return reset;}
  else          {VALUE = init; return init;}
}

TYPE SetOnce (DefTableKey key, TYPE val)
{ if (key == NoKey) return val;
  if (!ACCESS) VALUE = val;
  return VALUE;
}

DefTableKey KReset (DefTableKey key, TYPE val)
{ if (key == NoKey) return NoKey;
  ACCESS; VALUE = val; return key;
}

TYPE VReset (DefTableKey key, TYPE val)
{ if (key != NoKey) 
    { ACCESS; VALUE = val; }
  return val;
}

DefTableKey Trans (DefTableKey key)
{ if (key == NoKey) return NoKey;
  while (PRESENT) key = VALUE;
  return key;
}

void SetDiff (DefTableKey key, TYPE thistype, TYPE diff)
{ if (key == NoKey) return;
  if (!ACCESS)                  VALUE = thistype;
  else if (VALUE != thistype)   VALUE = diff;
}

TYPE Insert(DefTableKey key, int val)
{ if (key == NoKey) return NULLIS;
  if (val < 0 || val > 8*sizeof(TYPE))
     message(DEADLY,"Invalid set element",0,NoPosition);
  if (!ACCESS) VALUE = NULLIS;
  VALUE |= (1<<val);
  return VALUE;
}

TYPE Union(DefTableKey key, TYPE val)
{ if (key == NoKey) return NULLIS;
  if (!ACCESS) VALUE = val;
  else VALUE |= val;
  return VALUE;
}

TYPE Intersect(DefTableKey key, TYPE val)
{ if (key == NoKey) return NULLIS;
  if (!ACCESS) VALUE = val;
  else VALUE &= val;
  return VALUE;
}
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/h/x/Kind.pdl.12573583.pdl"

Kind:   int [SetDiff];
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/c/Unique.pdl.5206830.pdl"

Unique: int;
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/e/FirstOcc.pdl.5307723.pdl"

FirstOcc:       int [SetGet];
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/h/w/tp.pdl.12534960.pdl"


Arity: int [Is];
Index: int [Terminal];

TYPE Terminal(DefTableKey key)
{ static int index = 1;

  if (key == NoKey) return 0;
  if (!ACCESS) VALUE = index++;
  return VALUE;
}


Type: DefTableKey;
Used: int;


Sym: int;


Symbol: int [Obtain];

int Obtain(DefTableKey key, int sym)
{ if (key == NoKey) return 0;
  if (!ACCESS) VALUE = IndCatStrStr("Reduce_",StringTable(sym));
  return VALUE;
} "Strings.h"

Cases: PTGNode [Update];

void Update(DefTableKey key, PTGNode add)
{ if (key == NoKey) return;
  if (!ACCESS) VALUE = add;
  else VALUE = PTGSeq(VALUE, add);
} "ptg_gen.h"

