//## begin module%3CB60AB600D1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB60AB600D1.cm

//## begin module%3CB60AB600D1.cp preserve=no
//## end module%3CB60AB600D1.cp

//## Module: eE3D_FogMode%3CB60AB600D1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\eE3D_FogMode.h

#ifndef eE3D_FogMode_h
#define eE3D_FogMode_h 1

//## begin module%3CB60AB600D1.additionalIncludes preserve=no
//## end module%3CB60AB600D1.additionalIncludes

//## begin module%3CB60AB600D1.includes preserve=yes
//## end module%3CB60AB600D1.includes

//## begin module%3CB60AB600D1.additionalDeclarations preserve=yes
//## end module%3CB60AB600D1.additionalDeclarations


//## begin eE3D_FogMode%3CB60AB600D1.preface preserve=yes
//## end eE3D_FogMode%3CB60AB600D1.preface

//## Class: eE3D_FogMode%3CB60AB600D1
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eE3D_FM_None,    // 0
    eE3D_FM_Linear,    // 1
    eE3D_FM_Exp,    // 2
    eE3D_FM_Exp2,    // 3
    eE3D_FM_Current,    // 4
    eE3D_FM_Last,    // 5
    eE3D_FM_NumFMs     // 6
} eE3D_FogMode;

//## begin eE3D_FogMode%3CB60AB600D1.postscript preserve=yes
//## end eE3D_FogMode%3CB60AB600D1.postscript

//## begin module%3CB60AB600D1.epilog preserve=yes
//## end module%3CB60AB600D1.epilog


#endif
