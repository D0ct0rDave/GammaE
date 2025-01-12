//## begin module%3CB60136019C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB60136019C.cm

//## begin module%3CB60136019C.cp preserve=no
//## end module%3CB60136019C.cp

//## Module: eE3D_StencilFunc%3CB60136019C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\eE3D_StencilFunc.h

#ifndef eE3D_StencilFunc_h
#define eE3D_StencilFunc_h 1

//## begin module%3CB60136019C.additionalIncludes preserve=no
//## end module%3CB60136019C.additionalIncludes

//## begin module%3CB60136019C.includes preserve=yes
//## end module%3CB60136019C.includes

//## begin module%3CB60136019C.additionalDeclarations preserve=yes
//## end module%3CB60136019C.additionalDeclarations


//## begin eE3D_StencilFunc%3CB60136019C.preface preserve=yes
//## end eE3D_StencilFunc%3CB60136019C.preface

//## Class: eE3D_StencilFunc%3CB60136019C
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eE3D_SF_None,    // 0
    eE3D_SF_Never,    // 1
    eE3D_SF_Less,    // 2
    eE3D_SF_LEqual,    // 3
    eE3D_SF_Greater,    // 4
    eE3D_SF_GEqual,    // 5
    eE3D_SF_Equal,    // 6
    eE3D_SF_NotEqual,    // 7
    eE3D_SF_Always,    // 8
    eE3D_SF_Current,    // 9
    eE3D_SF_Last,    // 10
    eE3D_SF_NumSFs     // 11
} eE3D_StencilFunc;

//## begin eE3D_StencilFunc%3CB60136019C.postscript preserve=yes
//## end eE3D_StencilFunc%3CB60136019C.postscript

//## begin module%3CB60136019C.epilog preserve=yes
//## end module%3CB60136019C.epilog


#endif
