//## begin module%3C603CA4039C.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603CA4039C.cm

//## begin module%3C603CA4039C.cp preserve=no
//## end module%3C603CA4039C.cp

//## Module: CE3D_ShIns_Color%3C603CA4039C; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_Color.h

#ifndef CE3D_ShIns_Color_h
#define CE3D_ShIns_Color_h 1

//## begin module%3C603CA4039C.additionalIncludes preserve=no
//## end module%3C603CA4039C.additionalIncludes

//## begin module%3C603CA4039C.includes preserve=yes
#include "E3D/Materials/ColorObj.h"
//## end module%3C603CA4039C.includes

// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//## begin module%3C603CA4039C.additionalDeclarations preserve=yes
//## end module%3C603CA4039C.additionalDeclarations


//## begin CE3D_ShIns_Color%3C603CA4039C.preface preserve=yes
//## end CE3D_ShIns_Color%3C603CA4039C.preface

//## Class: CE3D_ShIns_Color%3C603CA4039C
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShIns_Color : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C603D19020A
{
  //## begin CE3D_ShIns_Color%3C603CA4039C.initialDeclarations preserve=yes
  //## end CE3D_ShIns_Color%3C603CA4039C.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_Color();

    //## Destructor (generated)
      ~CE3D_ShIns_Color();

    // Data Members for Class Attributes

      //## Attribute: oColor%3C603CBC0301
      //## begin CE3D_ShIns_Color::oColor%3C603CBC0301.attr preserve=no  public: TColorObj {UA} 
      TColorObj oColor;
      //## end CE3D_ShIns_Color::oColor%3C603CBC0301.attr

    // Additional Public Declarations
      //## begin CE3D_ShIns_Color%3C603CA4039C.public preserve=yes
      //## end CE3D_ShIns_Color%3C603CA4039C.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_Color%3C603CA4039C.protected preserve=yes
      //## end CE3D_ShIns_Color%3C603CA4039C.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_Color%3C603CA4039C.private preserve=yes
      //## end CE3D_ShIns_Color%3C603CA4039C.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_Color%3C603CA4039C.implementation preserve=yes
      //## end CE3D_ShIns_Color%3C603CA4039C.implementation

};

//## begin CE3D_ShIns_Color%3C603CA4039C.postscript preserve=yes
//## end CE3D_ShIns_Color%3C603CA4039C.postscript

// Class CE3D_ShIns_Color 

//## begin module%3C603CA4039C.epilog preserve=yes
//## end module%3C603CA4039C.epilog


#endif
