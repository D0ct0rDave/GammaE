//## begin module%3CB5FD700193.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB5FD700193.cm

//## begin module%3CB5FD700193.cp preserve=no
//## end module%3CB5FD700193.cp

//## Module: eE3D_RenderBuffer_Type%3CB5FD700193; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\eE3D_RenderBuffer_Type.h

#ifndef eE3D_RenderBuffer_Type_h
#define eE3D_RenderBuffer_Type_h 1

//## begin module%3CB5FD700193.additionalIncludes preserve=no
//## end module%3CB5FD700193.additionalIncludes

//## begin module%3CB5FD700193.includes preserve=yes
//## end module%3CB5FD700193.includes

//## begin module%3CB5FD700193.additionalDeclarations preserve=yes
//## end module%3CB5FD700193.additionalDeclarations


//## begin eE3D_RenderBuffer_Type%3CB5FD700193.preface preserve=yes
//## end eE3D_RenderBuffer_Type%3CB5FD700193.preface

//## Class: eE3D_RenderBuffer_Type%3CB5FD700193
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eE3D_RB_None,    // 0
    eE3D_RB_Front,    // 1
    eE3D_RB_Back,    // 2
    eE3D_RB_Z,    // 3
    eE3D_RB_Stencil,    // 4
    eE3D_RB_NumTypes     // 5
} eE3D_RenderBuffer_Type;

//## begin eE3D_RenderBuffer_Type%3CB5FD700193.postscript preserve=yes
//## end eE3D_RenderBuffer_Type%3CB5FD700193.postscript

//## begin module%3CB5FD700193.epilog preserve=yes
//## end module%3CB5FD700193.epilog


#endif
