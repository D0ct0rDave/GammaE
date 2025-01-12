//## begin module%3C603CC60016.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603CC60016.cm

//## begin module%3C603CC60016.cp preserve=no
//## end module%3C603CC60016.cp

//## Module: CE3D_ShIns_Extension%3C603CC60016; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_Extension.h

#ifndef CE3D_ShIns_Extension_h
#define CE3D_ShIns_Extension_h 1

//## begin module%3C603CC60016.additionalIncludes preserve=no
//## end module%3C603CC60016.additionalIncludes

//## begin module%3C603CC60016.includes preserve=yes
//## end module%3C603CC60016.includes

// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//## begin module%3C603CC60016.additionalDeclarations preserve=yes
typedef void (*TExtensionFunction)(void *p1);
//## end module%3C603CC60016.additionalDeclarations


//## begin CE3D_ShIns_Extension%3C603CC60016.preface preserve=yes
//## end CE3D_ShIns_Extension%3C603CC60016.preface

//## Class: CE3D_ShIns_Extension%3C603CC60016
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShIns_Extension : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C603D1B038A
{
  //## begin CE3D_ShIns_Extension%3C603CC60016.initialDeclarations preserve=yes
  //## end CE3D_ShIns_Extension%3C603CC60016.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_Extension();

    //## Destructor (generated)
      ~CE3D_ShIns_Extension();

    // Data Members for Class Attributes

      //## Attribute: pFunction%3C603D0A0082
      //## begin CE3D_ShIns_Extension::pFunction%3C603D0A0082.attr preserve=no  public: TExtensionFunction {UA} 
      TExtensionFunction pFunction;
      //## end CE3D_ShIns_Extension::pFunction%3C603D0A0082.attr

    // Additional Public Declarations
      //## begin CE3D_ShIns_Extension%3C603CC60016.public preserve=yes
      //## end CE3D_ShIns_Extension%3C603CC60016.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_Extension%3C603CC60016.protected preserve=yes
      //## end CE3D_ShIns_Extension%3C603CC60016.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_Extension%3C603CC60016.private preserve=yes
      //## end CE3D_ShIns_Extension%3C603CC60016.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_Extension%3C603CC60016.implementation preserve=yes
      //## end CE3D_ShIns_Extension%3C603CC60016.implementation

};

//## begin CE3D_ShIns_Extension%3C603CC60016.postscript preserve=yes
//## end CE3D_ShIns_Extension%3C603CC60016.postscript

// Class CE3D_ShIns_Extension 

//## begin module%3C603CC60016.epilog preserve=yes
//## end module%3C603CC60016.epilog


#endif
