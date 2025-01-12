//## begin module%3C603FF00328.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603FF00328.cm

//## begin module%3C603FF00328.cp preserve=no
//## end module%3C603FF00328.cp

//## Module: eShInsTexOp_TypeID%3C603FF00328; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\eShInsTexOp_TypeID.h

#ifndef eShInsTexOp_TypeID_h
#define eShInsTexOp_TypeID_h 1

//## begin module%3C603FF00328.additionalIncludes preserve=no
//## end module%3C603FF00328.additionalIncludes

//## begin module%3C603FF00328.includes preserve=yes
//## end module%3C603FF00328.includes

//## begin module%3C603FF00328.additionalDeclarations preserve=yes
//## end module%3C603FF00328.additionalDeclarations


//## begin eShInsTexOp_TypeID%3C603FF00328.preface preserve=yes
//## end eShInsTexOp_TypeID%3C603FF00328.preface

//## Class: eShInsTexOp_TypeID%3C603FF00328
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

typedef enum
{
    eSITexOp_NULL,    // 0
    eSITexOp_Rotate,    // 1
    eSITexOp_Scale,    // 2
    eSITexOp_ScaleU,    // 3
    eSITexOp_ScaleV,    // 4
    eSITexOp_TransU,    // 5
    eSITexOp_TransV,    // 6
    eSITexOp_ReflectMap,    // 7
    eSITexOp_EnvMap,    // 8
    eSITexOp_Matrix     // 9
} eShInsTexOp_TypeID;

//## begin eShInsTexOp_TypeID%3C603FF00328.postscript preserve=yes
//## end eShInsTexOp_TypeID%3C603FF00328.postscript

//## begin module%3C603FF00328.epilog preserve=yes
//## end module%3C603FF00328.epilog


#endif
