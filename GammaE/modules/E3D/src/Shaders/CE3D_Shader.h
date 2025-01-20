// ----------------------------------------------------------------------------
#ifndef CE3D_Shader_h
#define CE3D_Shader_h 1
// ----------------------------------------------------------------------------
#include <assert.h>

#include "GammaE_Misc.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
// ----------------------------------------------------------------------------
#define SHFLAG_UNDEFINEDFLAGS	0x80000000
#define SHFLAG_TRANSPARENT		0x00000001
// ----------------------------------------------------------------------------																	   
class CE3D_Shader : public CGResource
{
  public:
		CE3D_Shader();

		~CE3D_Shader();

		void AddInstruction (CE3D_ShaderInstruction *_poInst);

		void PushInstruction (CE3D_ShaderInstruction *_poInst);

		CE3D_ShaderInstruction * pGetInstruction(int _iInstIdx);

		int iGetNumInstructions ();

		virtual void Invalidate();

		void RefCopy(CE3D_Shader* _poShader);
		// Data Members for Class Attributes

		CE3D_ShaderInstruction* *poInsts;

		int iNumInsts;

		// Additional Public Declarations
		bool bIsTransparent();
		void SetupShaderFlags();

		int iShFlags;
		protected:
};
// ----------------------------------------------------------------------------
inline CE3D_ShaderInstruction * CE3D_Shader::pGetInstruction (int _iInstIdx)
{
  	assert((poInsts) && "NULL shader instruction array");
	assert((_iInstIdx < iNumInsts) && "Shader instruction out of bounds");
	
	return( poInsts[_iInstIdx] );
}
// ----------------------------------------------------------------------------
inline int CE3D_Shader::iGetNumInstructions ()
{
  	return(iNumInsts);
}
// ----------------------------------------------------------------------------
inline bool CE3D_Shader::bIsTransparent()
{
	if (iShFlags & SHFLAG_UNDEFINEDFLAGS)	
		SetupShaderFlags();
	
	return (iShFlags & SHFLAG_TRANSPARENT);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
