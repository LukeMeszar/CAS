
set n(tOilClassOpList,desc) "tOilClassOp List"

proc n_tOilClassOpList_open {text lst} {
    n_say "$text\n"
    if {$lst == 0} {
        n_say "  NULLtOilClassOpList\n"
    } else {
        set lst [n_hextodec $lst]
        set r [n_send get_tOilClassOpList_elems $lst]
        set c 0
        foreach i $r {
            n_say "  "
            n_say_val tOilClassOp $i
            n_say "\n"
            incr c
        }
        if {$c == 0} {
            n_say "  Empty\n"
        }
    }
}

proc n_tOilClassOpList_say {lst} {
    n_say "tOilClassOpList:0x[n_dectohex $lst]"
}
