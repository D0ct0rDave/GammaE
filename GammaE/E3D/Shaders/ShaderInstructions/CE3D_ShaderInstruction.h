//## begin module%3C603A1B01E1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603A1B01E1.cm

//## begin module%3C603A1B01E1.cp preserve=no
//## end module%3C603A1B01E1.cp

//## Module: CE3D_ShaderInstruction%3C603A1B01E1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h

#ifndef CE3D_ShaderInstruction_h
#define CE3D_ShaderInstruction_h 1

//## begin module%3C603A1B01E1.additionalIncludes preserve=no
//## end module%3C603A1B01E1.additionalIncludes

//## begin module%3C603A1B01E1.includes preserve=yes
//## end module%3C603A1B01E1.includes

// eShaderInstruction_TypeID
#include "E3D\Shaders\ShaderInstructions\eShaderInstruction_TypeID.h"
//## begin module%3C603A1B01E1.additionalDeclarations preserve=yes
//## end module%3C603A1B01E1.additionalDeclarations


//## begin CE3D_ShaderInstruction%3C603A1B01E1.preface preserve=yes
//## end CE3D_ShaderInstruction%3C603A1B01E1.preface

//## Class: CE3D_ShaderInstruction%3C603A1B01E1
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShaderInstruction 
{
  //## begin CE3D_ShaderInstruction%3C603A1B01E1.initialDeclarations preserve=yes
  //## end CE3D_ShaderInstruction%3C603A1B01E1.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderInstruction();

    //## Destructor (generated)
      ~CE3D_ShaderInstruction();

    // Data Members for Associations

      //## Association: E3D::Materials::<unnamed>%3C603EFB00AF
      //## Role: CE3D_ShaderInstruction::eInsType%3C603EFC00B1
      //## begin CE3D_ShaderInstruction::eInsType%3C603EFC00B1.role preserve=no  public: eShaderInstruction_TypeID { -> VHAN}
      eShaderInstruction_TypeID eInsType;
      //## end CE3D_ShaderInstruction::eInsType%3C603EFC00B1.role

    // Additional Public Declarations
      //## begin CE3D_ShaderInstruction%3C603A1B01E1.public preserve=yes
      //## end CE3D_ShaderInstruction%3C603A1B01E1.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShaderInstruction%3C603A1B01E1.protected preserve=yes
      //## end CE3D_ShaderInstruction%3C603A1B01E1.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShaderInstruction%3C603A1B01E1.private preserve=yes
      //## end CE3D_ShaderInstruction%3C603A1B01E1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderInstruction%3C603A1B01E1.implementation preserve=yes
      //## end CE3D_ShaderInstruction%3C603A1B01E1.implementation

};

//## begin CE3D_ShaderInstruction%3C603A1B01E1.postscript preserve=yes
//## end CE3D_ShaderInstruction%3C603A1B01E1.postscript

// Class CE3D_ShaderInstruction 

//## begin module%3C603A1B01E1.epilog preserve=yes
//## end module%3C603A1B01E1.epilog


#endif
