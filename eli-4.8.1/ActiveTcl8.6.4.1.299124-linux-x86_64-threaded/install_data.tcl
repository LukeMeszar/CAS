# -*- tcl -*-
# Copyright (C) 2001-2008 ActiveState Software Inc. Jun 05, 2015
#
# Information for the installer which is dependent on the chosen
# distribution. Original source of the information is the script
# "build/setvars.sh".
#
# ActiveState ActiveTcl 8.6.4.1.299124 Linux/x86_64, Fri Jun 05 20:20:21 PDT 2015
#

global    AT
array set AT {
    build       {299124}
    NAME	{ActiveTcl}
    PGROUP	{ActiveTcl}
    dPGROUP	{ActiveTcl}
    VERSION	8.6.4.1
    MATURITY	final
    Company	ActiveState
    url,about	http://www.activestate.com/activetcl
    url,update	http://www.activestate.com/activetcl
    url,help	http://www.activestate.com
    MODE	normal
    DISTC	at
    HELP	{ActiveTclHelp.chm}
    BLD_PFXPATH  {/home/andreask/dbn/lba/GlobalBuildArena/builds/linux-x86_64/out}
    BLD_EPFXPATH {/home/andreask/dbn/lba/GlobalBuildArena/builds/linux-x86_64/out/linux-x86_64}
    DEBUG        0
    THREADED     1
    tcl_VERSION  8.6
    ARCH         linux-x86_64
    TDK_ATVERS   8.6.4.1
    true_MODE	 normal
}

if {[string equal $AT(MODE) normal]} {
    if {$AT(THREADED)} {set tSuffix "-thread" } else {set tSuffix ""}
    set AT(LOG) [file join \
	lib ppm log [string tolower $AT(PGROUP)]$AT(tcl_VERSION)$tSuffix install.log]
    unset tSuffix
} else {
    set AT(LOG) [file join \
	lib ppm log [string tolower $AT(PGROUP)] install.log]
}

# When this file is used by the uninstaller SCRIPT_DIR is not defined.

if {[info exists ::SCRIPT_DIR]} {
    set _welcome [file join $::SCRIPT_DIR install_welcome.txt]

    global WELCOME
    set    WELCOME [read [set fh [open $_welcome r]]][close $fh]
    unset _welcome
}

if {[string equal $::AT(MODE) direct]} {
    # For the purposes of the installation the 'direct' distribution
    # is the same as the 'normal' ActiveTcl one.
    set ::AT(MODE) normal
}

# ========================================

set ::AT(UNINSTALLER)  uninstall
set ::AT(LICENSE)      license-at8.6-thread.terms
set ::AT(README)       README-8.6-thread.txt
set ::AT(MANIFEST)     MANIFEST_at8.6.txt
set ::AT(tcl_revision) ef02e1dfd92a04054f9ae123fe7e498f793963ff
set ::AT(tk_revision)  9e919f756da587aae977c2edfcc5003004c90a78
