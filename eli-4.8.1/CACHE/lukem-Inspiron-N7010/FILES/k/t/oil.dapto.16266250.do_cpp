# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/oil/oil.dapto"




















aspect oil;

"oiladt2.h"

operation get_oil_type
  "Return the description of an Oil type"
  (tOilType t "The relevant type") : str
{
  DAPTO_RESULTDefTableKey(t->sName);
  DAPTO_RESULTtOilCoercionSeq(t->sCoercionCosts);
}

operation get_oil_op
  "Return the description of an Oil operator"
  (tOilOp o "The relevant operator") : str
{ tOilArgSig s;
  DAPTO_RESULTDefTableKey(o->sName);
  DAPTO_RESULT_INT(o->sCost);
  for (s = o->sArgs; s != OilEmptyArgSig; s = s->sNext)
    DAPTO_RESULTtOilType(s->sArg);
}

operation get_identifications
  "Return the identifications of an Oil operator"
  (tOilOp o "The relevant operator") : str
{ tOilOpIdentification s;
  for (s = o->sIndOps; s; s = s->sNext)
    DAPTO_RESULTtOilType(s->sOp);
}

operation get_oil_type_set
  "Return the description of an Oil type set"
  (tOilTypeSet ts "The relevant type set") : str
{ 
  do {
    DAPTO_RESULTtOilType(ts->sBaseType);
    DAPTO_RESULT_INT(ts->sCost);
    ts = ts->sNext;
  } while (ts != OilEmptyTypeSet);
}

operation get_oil_set_sig
  "Return the description of an Oil set signature"
  (tOilSetSig ts "The relevant set signature") : str
{ 
  do {
    DAPTO_RESULTtOilTypeSet(ts->head);
    ts = ts->tail;
  } while (ts != OilEmptySetSig);
}

operation get_oil_arg_sig
  "Return the description of an Oil argument signature"
  (tOilArgSig ts "The relevant argument signature") : str
{ 
  do {
    DAPTO_RESULTtOilType(ts->sArg);
    ts = ts->sNext;
  } while (ts != OilEmptyArgSig);
}

operation get_oil_coercion_seq
  "Return an Oil coercion sequence"
  (tOilCoercionSeq cs "The relevant coercion sequence") : str
{ 
  do {
    DAPTO_RESULTtOilType(cs->sResultType);
    DAPTO_RESULTint(cs->sCost);
    cs = cs->sNextCost;
  } while (cs);
}

end;
