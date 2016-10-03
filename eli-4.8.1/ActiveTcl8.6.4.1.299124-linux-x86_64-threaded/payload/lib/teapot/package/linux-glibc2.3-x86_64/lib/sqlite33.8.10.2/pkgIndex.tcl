#
# Tcl package index file
#
# Note sqlite*3* init specifically
#
package ifneeded sqlite3 3.8.10.2 \
    [list load [file join $dir libsqlite3.8.10.2.so] Sqlite3]
