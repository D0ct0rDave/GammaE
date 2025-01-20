//## begin module%3C6AD6B502E9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C6AD6B502E9.cm

//## begin module%3C6AD6B502E9.cp preserve=no
//## end module%3C6AD6B502E9.cp

//## Module: CE3D_ShaderWH%3C6AD6B502E9; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderWarehouse\CE3D_ShaderWH.h

#ifndef CE3D_ShaderWH_h
#define CE3D_ShaderWH_h 1

//## begin module%3C6AD6B502E9.additionalIncludes preserve=no
//## end module%3C6AD6B502E9.additionalIncludes

//## begin module%3C6AD6B502E9.includes preserve=yes
#include "E3D/Materials/MipmapWH.h"
#include "E3D/Materials/TexObjWH.h"
//## end module%3C6AD6B502E9.includes

// CE3D_ShaderParser
#include "E3D\Shaders\ShaderParser\CE3D_ShaderParser.h"
// CE3D_ShWH_Entry
#include "E3D\Shaders\ShaderWarehouse\CE3D_ShWH_Entry.h"
// CE3D_ShaderDefWH
#include "E3D\Shaders\ShaderDefWarehouse\CE3D_ShaderDefWH.h"
//## begin module%3C6AD6B502E9.additionalDeclarations preserve=yes
//## end module%3C6AD6B502E9.additionalDeclarations


//## begin CE3D_ShaderWH%3C6AD6B502E9.preface preserve=yes
//## end CE3D_ShaderWH%3C6AD6B502E9.preface

//## Class: CE3D_ShaderWH%3C6AD6B502E9
//## Category: E3D::Shaders::ShaderWarehouse%3C6AD68D020F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6AEA7100BD;CE3D_ShaderDefWH { -> }
//## Uses: <unnamed>%3C6AEFD602D5;CE3D_ShaderParser { -> }

class CE3D_ShaderWH 
{
  //## begin CE3D_ShaderWH%3C6AD6B502E9.initialDeclarations preserve=yes
  //## end CE3D_ShaderWH%3C6AD6B502E9.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderWH();

    //## Destructor (generated)
      ~CE3D_ShaderWH();


    //## Other Operations (specified)
      //## Operation: Init%1013633078
      static void Init (int _iMaxShaderEntries);

      //## Operation: Invalidate%1013633069
      static void Invalidate ();

      //## Operation: FreeShader%1013633070
      static void FreeShader (CE3D_Shader &_roShader);

      //## Operation: bShaderExists%1013633071
      static bool bShaderExists (char *_szShaderName);

      //## Operation: poFindShader%1013633075
      static CE3D_ShWH_Entry * poFindShader (CE3D_Shader& _roShader);

      //## Operation: poFindShader%1013633076
      static CE3D_ShWH_Entry * poFindShader (char *_szShaderName);

      //## Operation: poFindShader%1015675966
      static CE3D_ShWH_Entry * poFindShader (int _iShaderIdx);

      //## Operation: poFindFreeShaderEntry%1013633077
      static CE3D_ShWH_Entry * poFindFreeShaderEntry ();

      //## Operation: iAddShader%1013633087
      static int iAddShader (char *_szShaderName, CE3D_Shader *_poShader);

      //## Operation: iAllocShader%1013633073
      static int iAllocShader (char* _szShaderName);

      //## Operation: iCreateShader%1013633072
      static int iCreateShader (char* _szShaderName);

      //## Operation: poCreateShader%1015675968
      static CE3D_Shader* poCreateShader (char* _szShaderName);

      //## Operation: poGetShader%1015675967
      static CE3D_Shader* poGetShader (int _iShaderId);

      //## Operation: szGetShaderName%1013633074
      static char * szGetShaderName (CE3D_Shader& _roShader);

    // Data Members for Associations

      //## Association: E3D::Shaders::ShaderWarehouse::<unnamed>%3C6AD82D00D7
      //## Role: CE3D_ShaderWH::oShaders%3C6AD82D0363
      //## begin CE3D_ShaderWH::oShaders%3C6AD82D0363.role preserve=no  public: static CE3D_ShWH_Entry { -> RHAN}
      static CE3D_ShWH_Entry *oShaders;
      //## end CE3D_ShaderWH::oShaders%3C6AD82D0363.role

    // Additional Public Declarations
      //## begin CE3D_ShaderWH%3C6AD6B502E9.public preserve=yes
      //## end CE3D_ShaderWH%3C6AD6B502E9.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShaderWH%3C6AD6B502E9.protected preserve=yes
      //## end CE3D_ShaderWH%3C6AD6B502E9.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iMaxShaders%3C6AD9220224
      //## begin CE3D_ShaderWH::iMaxShaders%3C6AD9220224.attr preserve=no  private: static int {UA} 0
      static int iMaxShaders;
      //## end CE3D_ShaderWH::iMaxShaders%3C6AD9220224.attr

    // Additional Private Declarations
      //## begin CE3D_ShaderWH%3C6AD6B502E9.private preserve=yes
      //## end CE3D_ShaderWH%3C6AD6B502E9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderWH%3C6AD6B502E9.implementation preserve=yes
      //## end CE3D_ShaderWH%3C6AD6B502E9.implementation

};

//## begin CE3D_ShaderWH%3C6AD6B502E9.postscript preserve=yes
//## end CE3D_ShaderWH%3C6AD6B502E9.postscript

// Class CE3D_ShaderWH 

//## begin module%3C6AD6B502E9.epilog preserve=yes
//## end module%3C6AD6B502E9.epilog


#endif
