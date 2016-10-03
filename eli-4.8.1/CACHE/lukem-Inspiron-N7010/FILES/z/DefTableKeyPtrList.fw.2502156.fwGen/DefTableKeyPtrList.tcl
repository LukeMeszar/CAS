
set n(DefTableKeyList,desc) "DefTableKey List"

proc n_DefTableKeyList_open {text lst} {
    n_say "$text\n"
    if {$lst == 0} {
        n_say "  NULLDefTableKeyList\n"
    } else {
        set lst [n_hextodec $lst]
        set r [n_send get_DefTableKeyList_elems $lst]
        set c 0
        foreach i $r {
            n_say "  "
            n_say_val DefTableKey $i
            n_say "\n"
            incr c
        }
        if {$c == 0} {
            n_say "  Empty\n"
        }
    }
}

proc n_DefTableKeyList_say {lst} {
    n_say "DefTableKeyList:0x[n_dectohex $lst]"
}
