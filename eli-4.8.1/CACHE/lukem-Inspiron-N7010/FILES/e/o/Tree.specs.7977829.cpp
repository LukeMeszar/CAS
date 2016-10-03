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
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/c/e/FirstOcc.pdl.5307723.pdl"

FirstOcc:       int [SetGet];
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/d/l/Analysis.pdl.6887688.pdl"


Defined:        int;    
IsListofLhs:    int;    
ComputedRoot:   int;    


NoPtgGiven:     int;    
NoPtg2Given:    int;    
NoPtg1Given:    int;    

