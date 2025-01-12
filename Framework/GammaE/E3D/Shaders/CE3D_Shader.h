//## begin module%3C603880018F.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C603880018F.cm

//## begin module%3C603880018F.cp preserve=no
//## end module%3C603880018F.cp

//## Module: CE3D_Shader%3C603880018F; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Shaders\CE3D_Shader.h

#ifndef CE3D_Shader_h
#define CE3D_Shader_h 1

//## begin module%3C603880018F.additionalIncludes preserve=no
//## end module%3C603880018F.additionalIncludes

//## begin module%3C603880018F.includes preserve=yes
#include <assert.h>
//## end module%3C603880018F.includes

// CE3D_ShaderInstruction
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//## begin module%3C603880018F.additionalDeclarations preserve=yes
#define SHFLAG_UNDEFINEDFLAGS	0x80000000
#define SHFLAG_TRANSPARENT		0x00000001
//## end module%3C603880018F.additionalDeclarations


//## begin CE3D_Shader%3C603880018F.preface preserve=yes
//## end CE3D_Shader%3C603880018F.preface

//## Class: CE3D_Shader%3C603880018F
//## Category: E3D::Shaders%3BD3587E014A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C6042EE024D;CE3D_ShaderInstruction { -> }

class CE3D_Shader 
{
  //## begin CE3D_Shader%3C603880018F.initialDeclarations preserve=yes
  //## end CE3D_Shader%3C603880018F.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_Shader();

    //## Destructor (generated)
      ~CE3D_Shader();


    //## Other Operations (specified)
      //## Operation: AddInstruction%1012941672
      void AddInstruction (CE3D_ShaderInstruction *_poInst);

      //## Operation: PushInstruction%1013981857
      void PushInstruction (CE3D_ShaderInstruction *_poInst);

      //## Operation: pGetInstruction%1012941673
      CE3D_ShaderInstruction * pGetInstruction (int _iInstIdx);

      //## Operation: iGetNumInstructions%1012941674
      int iGetNumInstructions ();

    // Data Members for Class Attributes

      //## Attribute: poInsts%3C6042510071
      //## begin CE3D_Shader::poInsts%3C6042510071.attr preserve=no  public: CE3D_ShaderInstruction* * {UA} NULL
      CE3D_ShaderInstruction* *poInsts;
      //## end CE3D_Shader::poInsts%3C6042510071.attr

      //## Attribute: iNumInsts%3C6042640281
      //## begin CE3D_Shader::iNumInsts%3C6042640281.attr preserve=no  public: int {UA} 0
      int iNumInsts;
      //## end CE3D_Shader::iNumInsts%3C6042640281.attr

    // Additional Public Declarations
      //## begin CE3D_Shader%3C603880018F.public preserve=yes
		bool bIsTransparent();
		void SetupShaderFlags();
		
		int iShFlags;
      //## end CE3D_Shader%3C603880018F.public
  protected:
    // Additional Protected Declarations
      //## begin CE3D_Shader%3C603880018F.protected preserve=yes
      //## end CE3D_Shader%3C603880018F.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_Shader%3C603880018F.private preserve=yes
      //## end CE3D_Shader%3C603880018F.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_Shader%3C603880018F.implementation preserve=yes
      //## end CE3D_Shader%3C603880018F.implementation

};

//## begin CE3D_Shader%3C603880018F.postscript preserve=yes
//## end CE3D_Shader%3C603880018F.postscript

// Class CE3D_Shader 


//## Other Operations (inline)
inline CE3D_ShaderInstruction * CE3D_Shader::pGetInstruction (int _iInstIdx)
{
  //## begin CE3D_Shader::pGetInstruction%1012941673.body preserve=yes
	assert((poInsts) && "NULL shader instruction array");
	assert((_iInstIdx < iNumInsts) && "Shader instruction out of bounds");
	

	return( poInsts[_iInstIdx] );
  //## end CE3D_Shader::pGetInstruction%1012941673.body
}

inline int CE3D_Shader::iGetNumInstructions ()
{
  //## begin CE3D_Shader::iGetNumInstructions%1012941674.body preserve=yes
	return(iNumInsts);
  //## end CE3D_Shader::iGetNumInstructions%1012941674.body
}

//## begin module%3C603880018F.epilog preserve=yes
inline bool CE3D_Shader::bIsTransparent()
{
	if (iShFlags & SHFLAG_UNDEFINEDFLAGS)	
		SetupShaderFlags();
	
	return (iShFlags & SHFLAG_TRANSPARENT);
}
//## end module%3C603880018F.epilog


#endif
