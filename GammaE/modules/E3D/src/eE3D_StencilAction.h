//## begin module%3CB600310197.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB600310197.cm

//## begin module%3CB600310197.cp preserve=no
//## end module%3CB600310197.cp

//## Module: eE3D_StencilAction%3CB600310197; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\eE3D_StencilAction.h

#ifndef eE3D_StencilAction_h
#define eE3D_StencilAction_h 1

//## begin module%3CB600310197.additionalIncludes preserve=no
//## end module%3CB600310197.additionalIncludes

//## begin module%3CB600310197.includes preserve=yes
//## end module%3CB600310197.includes

//## begin module%3CB600310197.additionalDeclarations preserve=yes
//## end module%3CB600310197.additionalDeclarations


//## begin eE3D_StencilAction%3CB600310197.preface preserve=yes
//## end eE3D_StencilAction%3CB600310197.preface

//## Class: eE3D_StencilAction%3CB600310197
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eE3D_SA_None,    // 0
    eE3D_SA_Keep,    // 1
    eE3D_SA_Zero,    // 2
    eE3D_SA_Inc,    // 3
    eE3D_SA_Dec,    // 4
    eE3D_SA_Inv,    // 5
    eE3D_SA_Replace,    // 6
    eE3D_SA_NumSAs     // 7
} eE3D_StencilAction;

//## begin eE3D_StencilAction%3CB600310197.postscript preserve=yes
//## end eE3D_StencilAction%3CB600310197.postscript

//## begin module%3CB600310197.epilog preserve=yes
//## end module%3CB600310197.epilog


#endif
