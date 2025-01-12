//## begin module%3C603D5C0134.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603D5C0134.cm

//## begin module%3C603D5C0134.cp preserve=no
//## end module%3C603D5C0134.cp

//## Module: CE3D_ShIns_Wireframe%3C603D5C0134; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_Wireframe.h

#ifndef CE3D_ShIns_Wireframe_h
#define CE3D_ShIns_Wireframe_h 1

//## begin module%3C603D5C0134.additionalIncludes preserve=no
//## end module%3C603D5C0134.additionalIncludes

//## begin module%3C603D5C0134.includes preserve=yes
#include "E3D/Materials/ColorObj.h"
//## end module%3C603D5C0134.includes

// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//## begin module%3C603D5C0134.additionalDeclarations preserve=yes
//## end module%3C603D5C0134.additionalDeclarations


//## begin CE3D_ShIns_Wireframe%3C603D5C0134.preface preserve=yes
//## end CE3D_ShIns_Wireframe%3C603D5C0134.preface

//## Class: CE3D_ShIns_Wireframe%3C603D5C0134
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShIns_Wireframe : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C603DB002E4
{
  //## begin CE3D_ShIns_Wireframe%3C603D5C0134.initialDeclarations preserve=yes
  //## end CE3D_ShIns_Wireframe%3C603D5C0134.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_Wireframe();

    //## Destructor (generated)
      ~CE3D_ShIns_Wireframe();

    // Data Members for Class Attributes

      //## Attribute: oColor%3C603DAC00E9
      //## begin CE3D_ShIns_Wireframe::oColor%3C603DAC00E9.attr preserve=no  public: TColorObj {UA} 
      TColorObj oColor;
      //## end CE3D_ShIns_Wireframe::oColor%3C603DAC00E9.attr

    // Additional Public Declarations
      //## begin CE3D_ShIns_Wireframe%3C603D5C0134.public preserve=yes
      //## end CE3D_ShIns_Wireframe%3C603D5C0134.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_Wireframe%3C603D5C0134.protected preserve=yes
      //## end CE3D_ShIns_Wireframe%3C603D5C0134.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_Wireframe%3C603D5C0134.private preserve=yes
      //## end CE3D_ShIns_Wireframe%3C603D5C0134.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_Wireframe%3C603D5C0134.implementation preserve=yes
      //## end CE3D_ShIns_Wireframe%3C603D5C0134.implementation

};

//## begin CE3D_ShIns_Wireframe%3C603D5C0134.postscript preserve=yes
//## end CE3D_ShIns_Wireframe%3C603D5C0134.postscript

// Class CE3D_ShIns_Wireframe 

//## begin module%3C603D5C0134.epilog preserve=yes
//## end module%3C603D5C0134.epilog


#endif
