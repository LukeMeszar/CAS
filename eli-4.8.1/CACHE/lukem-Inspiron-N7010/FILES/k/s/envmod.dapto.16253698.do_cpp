# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/Name/envmod.dapto"



















 
aspect envmod;

"envmod.h"

event env_created* "An environment value has been created"
    (Environment env "The environment that was created",
     Environment parent "The parent environment (if any)");

event binding_made* "A binding has been made in an environment"
    (Environment env "The environment in which the binding was made",
     int idn "The identifier that was bound",
     DefTableKey key "The key to which the identifier was bound");

operation get_scope_info
    "Return the parent environment of an environment and its idn-key bindings"
    (Environment env "The environment to be searched") : str
{
    Scope s;

    DAPTO_RESULT_PTR (env->parent);
    DAPTO_RESULT_PTR (env->classdescr);
    for (s = env->relate; s != NoScope; s = s->nxt) {
	DAPTO_RESULT_INT (s->idn);
	DAPTO_RESULT_PTR (s->key);
    }   
}
 
operation get_binding_info
    "Return the components of a binding"
    (Binding bind "The binding of interest") : str
{
    DAPTO_RESULT_INT (bind->idn);
    DAPTO_RESULT_PTR (bind->key);
    DAPTO_RESULT_PTR (bind->env);
}
 
operation get_inheritance_info
    "Return the inheritance information of an environment"
    (_Class cl "The environment's classdescr") : str
{
    InheritPtr i;

    for (i = cl->inhlist; i != NoInherit; i = i->nxt) {
	DAPTO_RESULT_PTR (i->fromcl->env);
    }   
}

end;
