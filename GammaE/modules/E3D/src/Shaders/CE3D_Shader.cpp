// ----------------------------------------------------------------------------
#include <string.h>
#include "GammaE_Mem.h"
// ----------------------------------------------------------------------------
#include "Shaders\CE3D_Shader.h"
// ----------------------------------------------------------------------------
CE3D_Shader::CE3D_Shader() : poInsts(NULL), iNumInsts(0)
{
  	iShFlags = SHFLAG_UNDEFINEDFLAGS;
}
// ----------------------------------------------------------------------------
CE3D_Shader::~CE3D_Shader()
{
  	Invalidate();
}
// ----------------------------------------------------------------------------
void CE3D_Shader::AddInstruction(CE3D_ShaderInstruction *_poInst)
{
  	CE3D_ShaderInstruction* *poNewInsts;

	// Allocate space for old + new instructions
	poNewInsts = mNew CE3D_ShaderInstruction *[iNumInsts+1];

	// Copy old data
	if (poInsts) 
		memcpy(poNewInsts,poInsts,iNumInsts*sizeof(CE3D_ShaderInstruction *));

	// Add new instruction
	poNewInsts[iNumInsts] = _poInst;
	
	// delete old data
	if (poInsts) mDel []poInsts;

	// Update object
	poInsts = poNewInsts;

	iNumInsts++;
}
// ----------------------------------------------------------------------------
void CE3D_Shader::PushInstruction(CE3D_ShaderInstruction *_poInst)
{
  	CE3D_ShaderInstruction* *poNewInsts;

	// Allocate space for old + new instructions
	poNewInsts = mNew CE3D_ShaderInstruction *[iNumInsts+1];

	// Copy old data
	memcpy(poNewInsts + 1,poInsts,iNumInsts*sizeof(CE3D_ShaderInstruction *));

	// Add new instruction
	poNewInsts[0] = _poInst;
	
	// delete old data
	mDel []poInsts;

	// Update object		
	poInsts = poNewInsts;

	iNumInsts++;
}
// ----------------------------------------------------------------------------
void CE3D_Shader::SetupShaderFlags()
{
	iShFlags = 0;
	for (int iInst=0;iInst<iNumInsts;iInst++)
	{
		if (poInsts[iInst]->eGetInstructionType() == E3D_SHI_BlendOp)
		{
			iShFlags |= SHFLAG_TRANSPARENT;
			return;	// De momento solo necesitamos este flag
		}
	}
}
// ----------------------------------------------------------------------------
void CE3D_Shader::Invalidate()
{
	if (poInsts)
	{
		// Delete instructions
		for (int i=0;i<iNumInsts;i++)
		{
			mDel poInsts[i];
		}

		// Delete instruction array
		mDel []poInsts;
		poInsts = NULL;
	}

	CGResource::Invalidate();
}
// ----------------------------------------------------------------------------
void CE3D_Shader::RefCopy(CE3D_Shader* _poShader)
{
	poInsts   = _poShader->poInsts;
	iNumInsts = _poShader->iNumInsts;
	iShFlags  = _poShader->iShFlags;
}
// ----------------------------------------------------------------------------
