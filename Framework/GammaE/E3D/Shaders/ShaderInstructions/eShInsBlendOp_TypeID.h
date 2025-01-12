//## begin module%3C6040CE0042.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C6040CE0042.cm

//## begin module%3C6040CE0042.cp preserve=no
//## end module%3C6040CE0042.cp

//## Module: eShInsBlendOp_TypeID%3C6040CE0042; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\eShInsBlendOp_TypeID.h

#ifndef eShInsBlendOp_TypeID_h
#define eShInsBlendOp_TypeID_h 1

//## begin module%3C6040CE0042.additionalIncludes preserve=no
//## end module%3C6040CE0042.additionalIncludes

//## begin module%3C6040CE0042.includes preserve=yes
//## end module%3C6040CE0042.includes

//## begin module%3C6040CE0042.additionalDeclarations preserve=yes
//## end module%3C6040CE0042.additionalDeclarations


//## begin eShInsBlendOp_TypeID%3C6040CE0042.preface preserve=yes
//## end eShInsBlendOp_TypeID%3C6040CE0042.preface

//## Class: eShInsBlendOp_TypeID%3C6040CE0042
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eSIBOp_NULL,    // 0
    eSIBOp_Copy,    // 1
    eSIBOp_Mult,    // 2
    eSIBOp_Mult2x,    // 3
    eSIBOp_Add,    // 4
    eSIBOp_AddAndMult,    // 5
    eSIBOp_MultAndAdd,    // 6
    eSIBOp_Alpha,    // 7
    eSIBOp_AlphaAdd,    // 8
    eSIBOp_AlphaInv,    // 9
    eSIBOp_AlphaThrough     // 10
} eShInsBlendOp_TypeID;

//## begin eShInsBlendOp_TypeID%3C6040CE0042.postscript preserve=yes
//## end eShInsBlendOp_TypeID%3C6040CE0042.postscript

//## begin module%3C6040CE0042.epilog preserve=yes
//## end module%3C6040CE0042.epilog


#endif
