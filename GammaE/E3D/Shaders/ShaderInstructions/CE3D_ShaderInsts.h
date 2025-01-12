//## begin module%3C605585003D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C605585003D.cm

//## begin module%3C605585003D.cp preserve=no
//## end module%3C605585003D.cp

//## Module: CE3D_ShaderInsts%3C605585003D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderInstructions\CE3D_ShaderInsts.h

#ifndef CE3D_ShaderInsts_h
#define CE3D_ShaderInsts_h 1

//## begin module%3C605585003D.additionalIncludes preserve=no
//## end module%3C605585003D.additionalIncludes

//## begin module%3C605585003D.includes preserve=yes
//## end module%3C605585003D.includes

// CE3D_ShIns_TexOp
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_TexOp.h"
// CE3D_ShIns_GeoOp
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_GeoOp.h"
// CE3D_ShIns_Wireframe
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_Wireframe.h"
// CE3D_ShIns_Extension
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_Extension.h"
// CE3D_ShIns_Color
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_Color.h"
// CE3D_ShIns_Texture
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_Texture.h"
// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
// CE3D_ShIns_BlendOp
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_BlendOp.h"
// CE3D_ShIns_SetTMU
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_SetTMU.h"
//## begin module%3C605585003D.additionalDeclarations preserve=yes
//## end module%3C605585003D.additionalDeclarations


//## begin CE3D_ShaderInsts%3C605585003D.preface preserve=yes
//## end CE3D_ShaderInsts%3C605585003D.preface

//## Class: CE3D_ShaderInsts%3C605585003D
//## Category: E3D::Shaders::ShaderInstructions%3C6041DB0067
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6055A500DA;CE3D_ShaderInstruction { -> }
//## Uses: <unnamed>%3C6055A800AC;CE3D_ShIns_Texture { -> }
//## Uses: <unnamed>%3C6055AA0055;CE3D_ShIns_Color { -> }
//## Uses: <unnamed>%3C6055CB02B5;CE3D_ShIns_GeoOp { -> }
//## Uses: <unnamed>%3C6055CE01A1;CE3D_ShIns_TexOp { -> }
//## Uses: <unnamed>%3C6055D20070;CE3D_ShIns_BlendOp { -> }
//## Uses: <unnamed>%3C6055D601CA;CE3D_ShIns_Wireframe { -> }
//## Uses: <unnamed>%3C6055D8015F;CE3D_ShIns_Extension { -> }
//## Uses: <unnamed>%3C6055DA0180;CE3D_ShIns_SetTMU { -> }

class CE3D_ShaderInsts 
{
  //## begin CE3D_ShaderInsts%3C605585003D.initialDeclarations preserve=yes
  //## end CE3D_ShaderInsts%3C605585003D.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderInsts();

    //## Destructor (generated)
      ~CE3D_ShaderInsts();

    // Additional Public Declarations
      //## begin CE3D_ShaderInsts%3C605585003D.public preserve=yes
      //## end CE3D_ShaderInsts%3C605585003D.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShaderInsts%3C605585003D.protected preserve=yes
      //## end CE3D_ShaderInsts%3C605585003D.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShaderInsts%3C605585003D.private preserve=yes
      //## end CE3D_ShaderInsts%3C605585003D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderInsts%3C605585003D.implementation preserve=yes
      //## end CE3D_ShaderInsts%3C605585003D.implementation

};

//## begin CE3D_ShaderInsts%3C605585003D.postscript preserve=yes
//## end CE3D_ShaderInsts%3C605585003D.postscript

// Class CE3D_ShaderInsts 

//## begin module%3C605585003D.epilog preserve=yes
//## end module%3C605585003D.epilog


#endif
