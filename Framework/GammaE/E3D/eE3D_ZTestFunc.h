//## begin module%3CB60B1B023E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB60B1B023E.cm

//## begin module%3CB60B1B023E.cp preserve=no
//## end module%3CB60B1B023E.cp

//## Module: eE3D_ZTestFunc%3CB60B1B023E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\eE3D_ZTestFunc.h

#ifndef eE3D_ZTestFunc_h
#define eE3D_ZTestFunc_h 1

//## begin module%3CB60B1B023E.additionalIncludes preserve=no
//## end module%3CB60B1B023E.additionalIncludes

//## begin module%3CB60B1B023E.includes preserve=yes
//## end module%3CB60B1B023E.includes

//## begin module%3CB60B1B023E.additionalDeclarations preserve=yes
//## end module%3CB60B1B023E.additionalDeclarations


//## begin eE3D_ZTestFunc%3CB60B1B023E.preface preserve=yes
//## end eE3D_ZTestFunc%3CB60B1B023E.preface

//## Class: eE3D_ZTestFunc%3CB60B1B023E
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eE3D_ZTF_None,    // 0
    eE3D_ZTF_Never,    // 1
    eE3D_ZTF_Less,    // 2
    eE3D_ZTF_LEqual,    // 3
    eE3D_ZTF_Greater,    // 4
    eE3D_ZTF_GEqual,    // 5
    eE3D_ZTF_Equal,    // 6
    eE3D_ZTF_NotEqual,    // 7
    eE3D_ZTF_Always,    // 8
    eE3D_ZTF_Current,    // 9
    eE3D_ZTF_Last,    // 10
    eE3D_ZTF_NumZTFs     // 11
} eE3D_ZTestFunc;

//## begin eE3D_ZTestFunc%3CB60B1B023E.postscript preserve=yes
//## end eE3D_ZTestFunc%3CB60B1B023E.postscript

//## begin module%3CB60B1B023E.epilog preserve=yes
//## end module%3CB60B1B023E.epilog


#endif
