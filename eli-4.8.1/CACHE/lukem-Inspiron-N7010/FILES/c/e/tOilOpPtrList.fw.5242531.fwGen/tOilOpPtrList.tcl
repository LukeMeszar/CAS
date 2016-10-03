
set n(tOilOpList,desc) "tOilOp List"

proc n_tOilOpList_open {text lst} {
    n_say "$text\n"
    if {$lst == 0} {
        n_say "  NULLtOilOpList\n"
    } else {
        set lst [n_hextodec $lst]
        set r [n_send get_tOilOpList_elems $lst]
        set c 0
        foreach i $r {
            n_say "  "
            n_say_val tOilOp $i
            n_say "\n"
            incr c
        }
        if {$c == 0} {
            n_say "  Empty\n"
        }
    }
}

proc n_tOilOpList_say {lst} {
    n_say "tOilOpList:0x[n_dectohex $lst]"
}
