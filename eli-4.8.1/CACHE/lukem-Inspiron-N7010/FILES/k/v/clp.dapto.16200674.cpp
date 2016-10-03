# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/PKGS/clp/clp.dapto"





















aspect source;

event source_changed* "Program input source changed"
   (str filename "File name",
    int init "1 if starting at the beginning; 0 if resuming in the middle",
    int curline "Cumulative line number",
    int curcol "Cumulative column number",
    int line "Line number of next line to be read from filename",
    int col "Column number of next column to be read from filename");

end;
