//## begin module%3C6AE35502DD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C6AE35502DD.cm

//## begin module%3C6AE35502DD.cp preserve=no
//## end module%3C6AE35502DD.cp

//## Module: CE3D_ShaderDefWH%3C6AE35502DD; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderDefWarehouse\CE3D_ShaderDefWH.h

#ifndef CE3D_ShaderDefWH_h
#define CE3D_ShaderDefWH_h 1

//## begin module%3C6AE35502DD.additionalIncludes preserve=no
//## end module%3C6AE35502DD.additionalIncludes

//## begin module%3C6AE35502DD.includes preserve=yes
//## end module%3C6AE35502DD.includes

// CE3D_ShDefWH_Entry
#include "E3D\Shaders\ShaderDefWarehouse\CE3D_ShDefWH_Entry.h"
//## begin module%3C6AE35502DD.additionalDeclarations preserve=yes
//## end module%3C6AE35502DD.additionalDeclarations


//## begin CE3D_ShaderDefWH%3C6AE35502DD.preface preserve=yes
//## end CE3D_ShaderDefWH%3C6AE35502DD.preface

//## Class: CE3D_ShaderDefWH%3C6AE35502DD
//## Category: E3D::Shaders::ShaderDefWarehouse%3C6AE34802A2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CE3D_ShaderDefWH 
{
  //## begin CE3D_ShaderDefWH%3C6AE35502DD.initialDeclarations preserve=yes
  //## end CE3D_ShaderDefWH%3C6AE35502DD.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderDefWH();

    //## Destructor (generated)
      ~CE3D_ShaderDefWH();


    //## Other Operations (specified)
      //## Operation: Init%1013633086
      static void Init (int _iMaxShDefs);

      //## Operation: iAddShaderFile%1013633081
      static int iAddShaderFile (char* _szFilename);

      //## Operation: iAddShader%1013633082
      static int iAddShader (char* _szShaderString);

      //## Operation: Invalidate%1013633083
      static void Invalidate ();

      //## Operation: szGetShader%1013633084
      static char * szGetShader (char *_szShaderName);

      //## Operation: iFindShader%1013633085
      static int iFindShader (char *_szShaderName);

    // Data Members for Associations

      //## Association: E3D::Shaders::ShaderDefWarehouse::<unnamed>%3C6AE4060273
      //## Role: CE3D_ShaderDefWH::oShDefs%3C6AE406033C
      //## begin CE3D_ShaderDefWH::oShDefs%3C6AE406033C.role preserve=no  public: static CE3D_ShDefWH_Entry { -> RHAN}
      static CE3D_ShDefWH_Entry *oShDefs;
      //## end CE3D_ShaderDefWH::oShDefs%3C6AE406033C.role

    // Additional Public Declarations
      //## begin CE3D_ShaderDefWH%3C6AE35502DD.public preserve=yes
      //## end CE3D_ShaderDefWH%3C6AE35502DD.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShaderDefWH%3C6AE35502DD.protected preserve=yes
      //## end CE3D_ShaderDefWH%3C6AE35502DD.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iMaxShDefs%3C6AE417028B
      //## begin CE3D_ShaderDefWH::iMaxShDefs%3C6AE417028B.attr preserve=no  private: static int {UA} 0
      static int iMaxShDefs;
      //## end CE3D_ShaderDefWH::iMaxShDefs%3C6AE417028B.attr

      //## Attribute: iNumShDefs%3C6AE86C00A5
      //## begin CE3D_ShaderDefWH::iNumShDefs%3C6AE86C00A5.attr preserve=no  private: static int {UA} 0
      static int iNumShDefs;
      //## end CE3D_ShaderDefWH::iNumShDefs%3C6AE86C00A5.attr

    // Additional Private Declarations
      //## begin CE3D_ShaderDefWH%3C6AE35502DD.private preserve=yes
      //## end CE3D_ShaderDefWH%3C6AE35502DD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderDefWH%3C6AE35502DD.implementation preserve=yes
      //## end CE3D_ShaderDefWH%3C6AE35502DD.implementation

};

//## begin CE3D_ShaderDefWH%3C6AE35502DD.postscript preserve=yes
//## end CE3D_ShaderDefWH%3C6AE35502DD.postscript

// Class CE3D_ShaderDefWH 

//## begin module%3C6AE35502DD.epilog preserve=yes
//## end module%3C6AE35502DD.epilog


#endif
