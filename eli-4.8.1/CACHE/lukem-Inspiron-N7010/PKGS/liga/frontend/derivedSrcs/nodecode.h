
/* encoding of tree node types and symbols */

#ifndef NODECODE_H
#define NODECODE_H

extern int LHSMAP[];

#define IsSymb(_n,_c) (LHSMAP[(_n)->_prod] == (_c))

#define SYMBSpec 0
#define SYMBShieldSyms 1
#define SYMBRemoteAttrs 2
#define SYMBParams 3
#define SYMBInheritSyms 4
#define SYMBG1 5
#define SYMBDependence 6
#define SYMBDepAttrs 7
#define SYMBComputations 8
#define SYMBAttrDefs 9
#define SYMBSpecs 10
#define SYMBAsgnTok 11
#define SYMBParam 12
#define SYMBParamsOpt 13
#define SYMBRhsAttrs 14
#define SYMBDepAttr 15
#define SYMBDepClause 16
#define SYMBExpression 17
#define SYMBExpandOpt 18
#define SYMBSubtree 19
#define SYMBRemoteExpression 20
#define SYMBRemoteClause 21
#define SYMBShieldClause 22
#define SYMBShield 23
#define SYMBComputation 24
#define SYMBAttrComp 25
#define SYMBShieldSym 26
#define SYMBDefAttr 27
#define SYMBCompute 28
#define SYMBPlainComp 29
#define SYMBChainNames 30
#define SYMBChainSpec 31
#define SYMBAttrNames 32
#define SYMBAttrSpec 33
#define SYMBAttrName 34
#define SYMBAttrDefIds 35
#define SYMBClass 36
#define SYMBAttrDef 37
#define SYMBExpressionDep 38
#define SYMBLoop 39
#define SYMBAttrDefId 40
#define SYMBChainName 41
#define SYMBSymOcc 42
#define SYMBAttr 43
#define SYMBAttrUseId 44
#define SYMBRemoteAttr 45
#define SYMBAlt 46
#define SYMBInheritSym 47
#define SYMBAlts 48
#define SYMBSyntUnits 49
#define SYMBRuleSpecId 50
#define SYMBRuleSpec 51
#define SYMBSyntUnit 52
#define SYMBSyntLit 53
#define SYMBProduction 54
#define SYMBCompPart 55
#define SYMBInheritOpt 56
#define SYMBAttrDefsOpt 57
#define SYMBSymbolDefIds 58
#define SYMBSymClass 59
#define SYMBTermSpec 60
#define SYMBSymCompSpec 61
#define SYMBSymAttrSpec 62
#define SYMBIndex 63
#define SYMBSymbolRef 64
#define SYMBAG 65
#define SYMBRuleId 66
#define SYMBTypeId 67
#define SYMBSyntId 68
#define SYMBSymbolId 69
#define SYMBSymbolDefId 70
#define RULErule_68 0
#define RULErule_82 1
#define RULErule_83 2
#define RULErule_84 3
#define RULErule_85 4
#define RULErule_86 5
#define RULErule_109 6
#define RULErule_110 7
#define RULErule_111 8
#define RULErule_112 9
#define RULErule_119 10
#define RULErule_120 11
#define RULErule_121 12
#define RULErule_122 13
#define RULErule_123 14
#define RULErule_124 15
#define RULErule_125 16
#define RULErule_126 17
#define RULErule_128 18
#define RULErule_59 19
#define RULErule_55 20
#define RULErule_48 21
#define RULErule_31 22
#define RULErule_27 23
#define RULErule_26 24
#define RULErule_25 25
#define RULErule_24 26
#define RULErule_3 27
#define RULErule_87 28
#define RULErule_88 29
#define RULErule_89 30
#define RULErule_90 31
#define RULErule_91 32
#define RULErule_92 33
#define RULErule_93 34
#define RULErule_94 35
#define RULErule_95 36
#define RULErule_98 37
#define RULErule_99 38
#define RULErule_100 39
#define RULErule_101 40
#define RULErule_102 41
#define RULErule_103 42
#define RULErule_104 43
#define RULErule_105 44
#define RULErule_106 45
#define RULErule_107 46
#define RULErule_108 47
#define RULErule_132 48
#define RULErule_134 49
#define RULErule_135 50
#define RULErule_136 51
#define RULErule_137 52
#define RULErule_60 53
#define RULErule_56 54
#define RULErule_52 55
#define RULErule_51 56
#define RULErule_50 57
#define RULErule_47 58
#define RULErule_46 59
#define RULErule_44 60
#define RULErule_37 61
#define RULErule_36 62
#define RULErule_35 63
#define RULErule_34 64
#define RULErule_33 65
#define RULErule_21 66
#define RULErule_20 67
#define RULErule_19 68
#define RULErule_15 69
#define RULErule_14 70
#define RULErule_13 71
#define RULErule_12 72
#define RULErule_11 73
#define RULErule_10 74
#define RULErule_9 75
#define RULErule_8 76
#define RULErule_7 77
#define RULErule_6 78
#define RULErule_5 79
#define RULErule_65 80
#define RULErule_66 81
#define RULErule_67 82
#define RULErule_72 83
#define RULErule_73 84
#define RULErule_74 85
#define RULErule_75 86
#define RULErule_96 87
#define RULErule_97 88
#define RULErule_114 89
#define RULErule_115 90
#define RULErule_116 91
#define RULErule_117 92
#define RULErule_118 93
#define RULErule_127 94
#define RULErule_129 95
#define RULErule_130 96
#define RULErule_133 97
#define RULErule_63 98
#define RULErule_58 99
#define RULErule_49 100
#define RULErule_43 101
#define RULErule_39 102
#define RULErule_38 103
#define RULErule_32 104
#define RULErule_28 105
#define RULErule_23 106
#define RULErule_22 107
#define RULErule_18 108
#define RULErule_76 109
#define RULErule_77 110
#define RULErule_78 111
#define RULErule_79 112
#define RULErule_80 113
#define RULErule_81 114
#define RULErule_113 115
#define RULErule_138 116
#define RULErule_54 117
#define RULErule_53 118
#define RULErule_17 119
#define RULErule_16 120
#define RULErule_64 121
#define RULErule_69 122
#define RULErule_70 123
#define RULErule_71 124
#define RULErule_131 125
#define RULErule_62 126
#define RULErule_61 127
#define RULErule_57 128
#define RULErule_45 129
#define RULErule_42 130
#define RULErule_41 131
#define RULErule_40 132
#define RULErule_30 133
#define RULErule_29 134
#define RULErule_4 135
#define RULErule_2 136
#define RULErule_1 137
#endif
