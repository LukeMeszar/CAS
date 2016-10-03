
set n(tOilTypeSetList,desc) "tOilTypeSet List"

proc n_tOilTypeSetList_open {text lst} {
    n_say "$text\n"
    if {$lst == 0} {
        n_say "  NULLtOilTypeSetList\n"
    } else {
        set lst [n_hextodec $lst]
        set r [n_send get_tOilTypeSetList_elems $lst]
        set c 0
        foreach i $r {
            n_say "  "
            n_say_val tOilTypeSet $i
            n_say "\n"
            incr c
        }
        if {$c == 0} {
            n_say "  Empty\n"
        }
    }
}

proc n_tOilTypeSetList_say {lst} {
    n_say "tOilTypeSetList:0x[n_dectohex $lst]"
}
