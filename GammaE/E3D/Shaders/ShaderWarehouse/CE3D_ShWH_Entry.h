//## begin module%3C6AD7DC02CF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C6AD7DC02CF.cm

//## begin module%3C6AD7DC02CF.cp preserve=no
//## end module%3C6AD7DC02CF.cp

//## Module: CE3D_ShWH_Entry%3C6AD7DC02CF; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderWarehouse\CE3D_ShWH_Entry.h

#ifndef CE3D_ShWH_Entry_h
#define CE3D_ShWH_Entry_h 1

//## begin module%3C6AD7DC02CF.additionalIncludes preserve=no
//## end module%3C6AD7DC02CF.additionalIncludes

//## begin module%3C6AD7DC02CF.includes preserve=yes
//## end module%3C6AD7DC02CF.includes

// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
//## begin module%3C6AD7DC02CF.additionalDeclarations preserve=yes
//## end module%3C6AD7DC02CF.additionalDeclarations


//## begin CE3D_ShWH_Entry%3C6AD7DC02CF.preface preserve=yes
//## end CE3D_ShWH_Entry%3C6AD7DC02CF.preface

//## Class: CE3D_ShWH_Entry%3C6AD7DC02CF
//## Category: E3D::Shaders::ShaderWarehouse%3C6AD68D020F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6ADB85015A;CE3D_Shader { -> }

class CE3D_ShWH_Entry 
{
  //## begin CE3D_ShWH_Entry%3C6AD7DC02CF.initialDeclarations preserve=yes
  //## end CE3D_ShWH_Entry%3C6AD7DC02CF.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShWH_Entry();

    //## Destructor (generated)
      ~CE3D_ShWH_Entry();

    // Data Members for Class Attributes

      //## Attribute: bValid%3C6AD7EE01D1
      //## begin CE3D_ShWH_Entry::bValid%3C6AD7EE01D1.attr preserve=no  public: bool {UA} false
      bool bValid;
      //## end CE3D_ShWH_Entry::bValid%3C6AD7EE01D1.attr

      //## Attribute: poShader%3C6AD7F700F7
      //## begin CE3D_ShWH_Entry::poShader%3C6AD7F700F7.attr preserve=no  public: CE3D_Shader * {UA} 
      CE3D_Shader *poShader;
      //## end CE3D_ShWH_Entry::poShader%3C6AD7F700F7.attr

      //## Attribute: szName%3C6AD80200D5
      //## begin CE3D_ShWH_Entry::szName%3C6AD80200D5.attr preserve=no  public: char[256] {UA} 
      char szName[256];
      //## end CE3D_ShWH_Entry::szName%3C6AD80200D5.attr

      //## Attribute: iId%3C89FE310201
      //## begin CE3D_ShWH_Entry::iId%3C89FE310201.attr preserve=no  public: int {UA} -1
      int iId;
      //## end CE3D_ShWH_Entry::iId%3C89FE310201.attr

    // Additional Public Declarations
      //## begin CE3D_ShWH_Entry%3C6AD7DC02CF.public preserve=yes
      //## end CE3D_ShWH_Entry%3C6AD7DC02CF.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_ShWH_Entry%3C6AD7DC02CF.protected preserve=yes
      //## end CE3D_ShWH_Entry%3C6AD7DC02CF.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_ShWH_Entry%3C6AD7DC02CF.private preserve=yes
      //## end CE3D_ShWH_Entry%3C6AD7DC02CF.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShWH_Entry%3C6AD7DC02CF.implementation preserve=yes
      //## end CE3D_ShWH_Entry%3C6AD7DC02CF.implementation

};

//## begin CE3D_ShWH_Entry%3C6AD7DC02CF.postscript preserve=yes
//## end CE3D_ShWH_Entry%3C6AD7DC02CF.postscript

// Class CE3D_ShWH_Entry 

//## begin module%3C6AD7DC02CF.epilog preserve=yes
//## end module%3C6AD7DC02CF.epilog


#endif
