
#include "TypeIdentTerm.h"
#include "PreDefMod.h"
#include "TypePreDefId.h"
#include "pdl_gen.h"

extern Environment TypeRootEnv; /* provided by a scope module */

#define PreDefSym(_str,_sym) int _sym;
#define PreDefKey(_str,_key) 
#define PreDefSymKey(_str,_sym,_key) int _sym;
#define PreDefBind(_str,_bnd) Binding _bnd;
#define PreDefKeyBind(_str,_key,_bnd) Binding _bnd;
#define PreDefSymKeyBind(_str,_sym,_key,_bnd) int _sym; Binding _bnd;
#include "TypePreDefId.d.h"
#undef PreDefSym
#undef PreDefKey
#undef PreDefSymKey
#undef PreDefBind
#undef PreDefKeyBind
#undef PreDefSymKeyBind

void TypeInitPreDef ()
{ int _dummysym; Binding _dummybnd;
  if (TypeRootEnv == NoEnv) TypeRootEnv = NewEnv ();
#define PreDefSym(_str,_sym) \
        PreDefineSym (_str, _TypeIdentTerm, &_sym);
#define PreDefKey(_str,_key) \
        PreDefine(_str,_TypeIdentTerm,&_dummysym,TypeRootEnv,_key,&_dummybnd);
#define PreDefSymKey(_str,_sym,_key) \
        PreDefine(_str,_TypeIdentTerm,&_sym,TypeRootEnv,_key,&_dummybnd);
#define PreDefBind(_str,_bnd) \
        PreDefine (_str,_TypeIdentTerm,&_dummysym,TypeRootEnv,NewKey(),&_bnd);
#define PreDefKeyBind(_str,_key,_bnd) \
        PreDefine (_str,_TypeIdentTerm,&_dummysym,TypeRootEnv,_key,&_bnd);
#define PreDefSymKeyBind(_str,_sym,_key,_bnd) \
        PreDefine (_str,_TypeIdentTerm,TypeRootEnv,&_sym,_key,&_bnd);
#include "TypePreDefId.d.h"
#undef PreDefSym
#undef PreDefKey
#undef PreDefSymKey
#undef PreDefBind
#undef PreDefKeyBind
#undef PreDefSymKeyBind
}
