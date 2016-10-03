# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/t/PtgCommon.ptg.3490471.ptg"


Id:             [PtgOutId $ int]
AsIs:           $ string
Numb:           $ int   
CString:        [CPtgOutstr $ string]
CChar:          [CPtgOutchar $ int]
PString:        [PPtgOutstr $ string]


Seq:            $ $
CommaSeq:       $ { ", " } $
Eol:            $ "\n"

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/dbgen.ptg.3326753.ptg"


db: "# Automatically generated by dapto: DO NOT EDIT\n"
    "\n"
    $ 
    $ 

aspectdb: "new_aspect " $ string "\n"

eventdb: "new_event [list " $ string " " $ " {" $ "} " $ "]\n"

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/o/gen.ptg.3322543.ptg"


cfile: "/* Automatically generated by dapto: DO NOT EDIT */\n"
       "\n"
       "#ifdef MONITOR\n"
       "#include <stdio.h>\n"
       "#include <time.h>\n"
       "#include <string.h>\n"
       "#include \"" $1  "_dapto.h\"\n"
       "\n"
       $2 
       "\n"
       "void _dap_" $1 "_init ()\n"
       "{\n"
       $3 
       "}\n"
       "#else\n"
       "static int _dapto; /* To avoid messages about empty files. */\n"
       "#endif\n"

hfile: "/* Automatically generated by dapto: DO NOT EDIT */\n"
       "\n"
       "#ifndef " $1 "_DAPTO_H\n"
       "#define " $1 "_DAPTO_H\n"
       "#include \"dapto.h\"\n"
       "#include \"eliproto.h\"\n"
       $3 
       "extern void _dap_" $1 "_init ();\n"
       $2 
       "#endif\n"

incl: "#include " $ "\n"

entry: "    _dap_add_command (\"" $1 string "\", " $1 string "Cmd );\n"

cmdfunc: "\n"
         "#ifdef PROTO_OK\n"
         "void " $1 string "Cmd (char *args)\n"
         "#else\n"
         "void " $1 string "Cmd (args)\n"
         "    char *args;\n"
         "#endif\n"
         "{\n"
         $2
         "    DAPTO_ARG_INIT_OP;\n"
         $3
         "    DAPTO_INIT_OP;\n"
         "/* #line " $5 int " \"" $6 string "\" */\n"
         $4
         "\n    DAPTO_RESULT_SEND (1);\n"
         "}\n"

arg:  "    DAPTO_ARG" $1 string " (&" $2 string ");\n"

efunc: "\n"
       $1
       "#ifdef PROTO_OK\n"
       "void _dapto_" $2 string " (" $3 ")\n"
       "#else\n"
       "void _dapto_" $2 string " (" $4 ")\n"
       $5
       "#endif\n"
       "{\n"
       "    DAPTO_INIT_EV;\n"
       "    DAPTO_RESULT_STR (\"" $2 string "\");\n"
       "    DAPTO_RESULT_LONGVAL (clock ());\n"
       $6
       "    DAPTO_RESULT_SEND (0);\n"
       "}\n"

sig:   "#ifdef PROTO_OK\n"
       "extern void _dapto_" $1 string " (" $2 ");\n"
       "#else\n"
       "extern void _dapto_" $1 string " ();\n"
       "#endif\n"

send:  "#ifdef DAPTO_RESULT" $1 string "\n"
       "    DAPTO_RESULT" $1 string " (" $2 string ");\n"
       "#else\n"
       "    DAPTO_RESULT_OTHER (" $2 string ");\n"
       "#endif\n"

translation:    "     if (" $ string ")\n"
                "#line " $ int " \"" $ string "\"\n"
                $ "\n"
translationvar: "int " $ string " = 1;\n"

# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/out.ptg.3325784.ptg"

SSeq:           $ " " $
SSeq3:          $ " " $ string " " $
DeclSeq:        $1 "    " $2 ";\n"   
Protect:        "_" $
NSeq:           $1 ", " $2 string $3 string
Decl:           "   " $1 string " " $2 string ";\n"
# 1 "/home/lukem/Dropbox/CAS/eli-4.8.1/CACHE/lukem-Inspiron-N7010/FILES/a/p/reqsym.ptg.3324488.ptg"


reqsyms: "/* Automatically generated by dapto: DO NOT EDIT */\n"
         "\n"
         $ 

reqsym: "{ extern void " $1 string "Cmd (); " $1 string "Cmd (); }\n"

