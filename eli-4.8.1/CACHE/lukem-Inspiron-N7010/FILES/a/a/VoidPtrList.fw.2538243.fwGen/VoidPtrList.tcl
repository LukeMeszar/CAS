
set n(VoidPtrList,desc) "VoidPtr List"

proc n_VoidPtrList_open {text lst} {
    n_say "$text\n"
    if {$lst == 0} {
        n_say "  NULLVoidPtrList\n"
    } else {
        set lst [n_hextodec $lst]
        set r [n_send get_VoidPtrList_elems $lst]
        set c 0
        foreach i $r {
            n_say "  "
            n_say_val VoidPtr $i
            n_say "\n"
            incr c
        }
        if {$c == 0} {
            n_say "  Empty\n"
        }
    }
}

proc n_VoidPtrList_say {lst} {
    n_say "VoidPtrList:0x[n_dectohex $lst]"
}
