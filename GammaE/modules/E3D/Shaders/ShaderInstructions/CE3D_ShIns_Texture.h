//## begin module%3C603C2100B9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603C2100B9.cm

//## begin module%3C603C2100B9.cp preserve=no
//## end module%3C603C2100B9.cp

//## Module: CE3D_ShIns_Texture%3C603C2100B9; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShIns_Texture.h

#ifndef CE3D_ShIns_Texture_h
#define CE3D_ShIns_Texture_h 1

//## begin module%3C603C2100B9.additionalIncludes preserve=no
//## end module%3C603C2100B9.additionalIncludes

//## begin module%3C603C2100B9.includes preserve=yes
#include "E3D/Materials/TexObj.h"
//## end module%3C603C2100B9.includes

// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//## begin module%3C603C2100B9.additionalDeclarations preserve=yes
//## end module%3C603C2100B9.additionalDeclarations


//## begin CE3D_ShIns_Texture%3C603C2100B9.preface preserve=yes
//## end CE3D_ShIns_Texture%3C603C2100B9.preface

//## Class: CE3D_ShIns_Texture%3C603C2100B9
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShIns_Texture : public CE3D_ShaderInstruction  //## Inherits: <unnamed>%3C603C7F0303
{
  //## begin CE3D_ShIns_Texture%3C603C2100B9.initialDeclarations preserve=yes
  //## end CE3D_ShIns_Texture%3C603C2100B9.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShIns_Texture();

    //## Destructor (generated)
      ~CE3D_ShIns_Texture();

    // Data Members for Class Attributes

      //## Attribute: pTex%3C603C9502B5
      //## begin CE3D_ShIns_Texture::pTex%3C603C9502B5.attr preserve=no  public: TTextureObj * {UA} 
      TTextureObj *pTex;
      //## end CE3D_ShIns_Texture::pTex%3C603C9502B5.attr

    // Additional Public Declarations
      //## begin CE3D_ShIns_Texture%3C603C2100B9.public preserve=yes
      //## end CE3D_ShIns_Texture%3C603C2100B9.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShIns_Texture%3C603C2100B9.protected preserve=yes
      //## end CE3D_ShIns_Texture%3C603C2100B9.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShIns_Texture%3C603C2100B9.private preserve=yes
      //## end CE3D_ShIns_Texture%3C603C2100B9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShIns_Texture%3C603C2100B9.implementation preserve=yes
      //## end CE3D_ShIns_Texture%3C603C2100B9.implementation

};

//## begin CE3D_ShIns_Texture%3C603C2100B9.postscript preserve=yes
//## end CE3D_ShIns_Texture%3C603C2100B9.postscript

// Class CE3D_ShIns_Texture 

//## begin module%3C603C2100B9.epilog preserve=yes
//## end module%3C603C2100B9.epilog


#endif
