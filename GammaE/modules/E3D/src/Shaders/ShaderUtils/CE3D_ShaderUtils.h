//## begin module%3C6D9C350076.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C6D9C350076.cm

//## begin module%3C6D9C350076.cp preserve=no
//## end module%3C6D9C350076.cp

//## Module: CE3D_ShaderUtils%3C6D9C350076; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderUtils\CE3D_ShaderUtils.h

#ifndef CE3D_ShaderUtils_h
#define CE3D_ShaderUtils_h 1

//## begin module%3C6D9C350076.additionalIncludes preserve=no
//## end module%3C6D9C350076.additionalIncludes

//## begin module%3C6D9C350076.includes preserve=yes
// #include "Color.h"
//## end module%3C6D9C350076.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
//## begin module%3C6D9C350076.additionalDeclarations preserve=yes
struct Texture;
struct MipMap;
struct TFColor;
//## end module%3C6D9C350076.additionalDeclarations


//## begin CE3D_ShaderUtils%3C6D9C350076.preface preserve=yes
//## end CE3D_ShaderUtils%3C6D9C350076.preface

//## Class: CE3D_ShaderUtils%3C6D9C350076
//## Category: E3D::Shaders::ShaderUtils%3C6D9C1800B0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6D9FF600C6;GammaE_E3D { -> }

class CE3D_ShaderUtils 
{
  //## begin CE3D_ShaderUtils%3C6D9C350076.initialDeclarations preserve=yes
  //## end CE3D_ShaderUtils%3C6D9C350076.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderUtils();

    //## Destructor (generated)
      ~CE3D_ShaderUtils();


    //## Other Operations (specified)
      //## Operation: poGenerateShaderFromTexture%1013817337
      static CE3D_Shader* poGenerateShaderFromTexture (Texture* _poTex, char *_szMatName);

      //## Operation: poGenerateShaderFromMipMap%1013817338
      static CE3D_Shader* poGenerateShaderFromMipMap (MipMap* _poMip, char *_szMatName);

      //## Operation: poGenerateShaderFromColor%1013817339
      static CE3D_Shader* poGenerateShaderFromColor (TFColor& _oColor, char *_szMatName);

      //## Operation: SetupTilingFlags%1013817340
      static void SetupTilingFlags (int _iUTFlag, int _iVTFlag);

    // Additional Public Declarations
      //## begin CE3D_ShaderUtils%3C6D9C350076.public preserve=yes
      //## end CE3D_ShaderUtils%3C6D9C350076.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShaderUtils%3C6D9C350076.protected preserve=yes
      //## end CE3D_ShaderUtils%3C6D9C350076.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iUTFlag%3C6DA3560141
      //## begin CE3D_ShaderUtils::iUTFlag%3C6DA3560141.attr preserve=no  private: static int {UA} 0
      static int iUTFlag;
      //## end CE3D_ShaderUtils::iUTFlag%3C6DA3560141.attr

      //## Attribute: iVTFlag%3C6DA35E034B
      //## begin CE3D_ShaderUtils::iVTFlag%3C6DA35E034B.attr preserve=no  private: static int {UA} 0
      static int iVTFlag;
      //## end CE3D_ShaderUtils::iVTFlag%3C6DA35E034B.attr

    // Additional Private Declarations
      //## begin CE3D_ShaderUtils%3C6D9C350076.private preserve=yes
      //## end CE3D_ShaderUtils%3C6D9C350076.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderUtils%3C6D9C350076.implementation preserve=yes
      //## end CE3D_ShaderUtils%3C6D9C350076.implementation

};

//## begin CE3D_ShaderUtils%3C6D9C350076.postscript preserve=yes
//## end CE3D_ShaderUtils%3C6D9C350076.postscript

// Class CE3D_ShaderUtils 

//## begin module%3C6D9C350076.epilog preserve=yes
//## end module%3C6D9C350076.epilog


#endif
