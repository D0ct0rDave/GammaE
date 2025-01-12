//## begin module%3C603A4C03CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603A4C03CC.cm

//## begin module%3C603A4C03CC.cp preserve=no
//## end module%3C603A4C03CC.cp

//## Module: eShaderInstruction_TypeID%3C603A4C03CC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\eShaderInstruction_TypeID.h

#ifndef eShaderInstruction_TypeID_h
#define eShaderInstruction_TypeID_h 1

//## begin module%3C603A4C03CC.additionalIncludes preserve=no
//## end module%3C603A4C03CC.additionalIncludes

//## begin module%3C603A4C03CC.includes preserve=yes
//## end module%3C603A4C03CC.includes

//## begin module%3C603A4C03CC.additionalDeclarations preserve=yes
//## end module%3C603A4C03CC.additionalDeclarations


//## begin eShaderInstruction_TypeID%3C603A4C03CC.preface preserve=yes
//## end eShaderInstruction_TypeID%3C603A4C03CC.preface

//## Class: eShaderInstruction_TypeID%3C603A4C03CC
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eShIns_NULL,    // 0
    eShIns_Texture,    // 1
    eShIns_Color,    // 2
    eShIns_Wireframe,    // 3
    eShIns_Extension,    // 4
    eShIns_GeoOp,    // 5
    eShIns_TexOp,    // 6
    eShIns_BlendOp,    // 7
    eShIns_SetTMU     // 8
} eShaderInstruction_TypeID;

//## begin eShaderInstruction_TypeID%3C603A4C03CC.postscript preserve=yes
//## end eShaderInstruction_TypeID%3C603A4C03CC.postscript

//## begin module%3C603A4C03CC.epilog preserve=yes
//## end module%3C603A4C03CC.epilog


#endif
