//## begin module%3C604EBE02A5.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C604EBE02A5.cm

//## begin module%3C604EBE02A5.cp preserve=no
//## end module%3C604EBE02A5.cp

//## Module: CE3D_ShaderParser%3C604EBE02A5; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderParser\CE3D_ShaderParser.h

#ifndef CE3D_ShaderParser_h
#define CE3D_ShaderParser_h 1

//## begin module%3C604EBE02A5.additionalIncludes preserve=no
//## end module%3C604EBE02A5.additionalIncludes

//## begin module%3C604EBE02A5.includes preserve=yes
#include "E3D/Materials/TexObj.h"
#include "E3D/Materials/MipmapWH.h"
#include "E3D/Materials/TexObjWH.h"
//## end module%3C604EBE02A5.includes

// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
// CE3D_ShaderExtDB
#include "E3D\Shaders\CE3D_ShaderExtDB.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
//## begin module%3C604EBE02A5.additionalDeclarations preserve=yes
//## end module%3C604EBE02A5.additionalDeclarations


//## begin CE3D_ShaderParser%3C604EBE02A5.preface preserve=yes
//## end CE3D_ShaderParser%3C604EBE02A5.preface

//## Class: CE3D_ShaderParser%3C604EBE02A5
//## Category: E3D::Shaders::ShaderParser%3C604EAE0068
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C60516F0350;CE3D_ShaderExtDB { -> }
//## Uses: <unnamed>%3C6053D3024C;CE3D_Shader { -> }
//## Uses: <unnamed>%3C6056A60101;CE3D_ShaderInsts { -> }
//## Uses: <unnamed>%3C6AF00500DE;GammaE_Math { -> }

class CE3D_ShaderParser 
{
  //## begin CE3D_ShaderParser%3C604EBE02A5.initialDeclarations preserve=yes
  //## end CE3D_ShaderParser%3C604EBE02A5.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderParser();

    //## Destructor (generated)
      ~CE3D_ShaderParser();


    //## Other Operations (specified)
      //## Operation: poCreateShaderFromTexture%1012941677
      static CE3D_Shader * poCreateShaderFromTexture (char *_szTexName);

      //## Operation: poParseShader%1012941678
      static CE3D_Shader * poParseShader (char *_szShaderDefinition, char* _szShaderName);

      //## Operation: Parse_Color_General%1013026081
      static void Parse_Color_General (char* _szDesc, float* _fR, float* _fG, float* _fB, float* _fA);

      //## Operation: poParseEvaluator%1013026082
      static CEvaluator * poParseEvaluator (char *_szDesc);

    // Additional Public Declarations
      //## begin CE3D_ShaderParser%3C604EBE02A5.public preserve=yes
      //## end CE3D_ShaderParser%3C604EBE02A5.public

  protected:

    //## Other Operations (specified)
      //## Operation: poParse_ShIns_Texture%1012941679
      static CE3D_ShaderInstruction * poParse_ShIns_Texture (char *&_szDesc);

      //## Operation: poParse_ShIns_Color%1012941680
      static CE3D_ShaderInstruction * poParse_ShIns_Color (char *&_szDesc);

      //## Operation: poParse_ShIns_Wireframe%1012941681
      static CE3D_ShaderInstruction * poParse_ShIns_Wireframe (char *&_szDesc);

      //## Operation: poParse_ShIns_Extension%1012941682
      static CE3D_ShaderInstruction * poParse_ShIns_Extension (char *&_szDesc);

      //## Operation: poParse_ShIns_BlendingOperation%1012941683
      static CE3D_ShaderInstruction * poParse_ShIns_BlendingOperation (char *&_szDesc);

      //## Operation: poParse_ShIns_TextureOperation%1012941684
      static CE3D_ShaderInstruction * poParse_ShIns_TextureOperation (char *&_szDesc);

      //## Operation: poParse_ShIns_GeometricOperation%1012941685
      static CE3D_ShaderInstruction * poParse_ShIns_GeometricOperation (char *&_szDesc);

      //## Operation: poParse_ShIns_SetTMU%1012941686
      static CE3D_ShaderInstruction * poParse_ShIns_SetTMU (char *&_szDesc);

    // Additional Protected Declarations
      //## begin CE3D_ShaderParser%3C604EBE02A5.protected preserve=yes
      //## end CE3D_ShaderParser%3C604EBE02A5.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShaderParser%3C604EBE02A5.private preserve=yes
      //## end CE3D_ShaderParser%3C604EBE02A5.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderParser%3C604EBE02A5.implementation preserve=yes
      //## end CE3D_ShaderParser%3C604EBE02A5.implementation

};

//## begin CE3D_ShaderParser%3C604EBE02A5.postscript preserve=yes
//## end CE3D_ShaderParser%3C604EBE02A5.postscript

// Class CE3D_ShaderParser 

//## begin module%3C604EBE02A5.epilog preserve=yes
//## end module%3C604EBE02A5.epilog


#endif
