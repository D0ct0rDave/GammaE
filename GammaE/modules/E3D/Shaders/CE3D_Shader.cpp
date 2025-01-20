//## begin module%3C603880018F.cm preserve=no
//## end module%3C603880018F.cm

//## begin module%3C603880018F.cp preserve=no
//## end module%3C603880018F.cp

//## Module: CE3D_Shader%3C603880018F; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\CE3D_Shader.cpp

//## begin module%3C603880018F.additionalIncludes preserve=no
//## end module%3C603880018F.additionalIncludes

//## begin module%3C603880018F.includes preserve=yes
#include <string.h>
#include "Memory/GammaE_Mem.h"

//## end module%3C603880018F.includes

// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
//## begin module%3C603880018F.additionalDeclarations preserve=yes
//## end module%3C603880018F.additionalDeclarations


// Class CE3D_Shader 




CE3D_Shader::CE3D_Shader()
  //## begin CE3D_Shader::CE3D_Shader%.hasinit preserve=no
      : poInsts(NULL), iNumInsts(0)
  //## end CE3D_Shader::CE3D_Shader%.hasinit
  //## begin CE3D_Shader::CE3D_Shader%.initialization preserve=yes
  //## end CE3D_Shader::CE3D_Shader%.initialization
{
  //## begin CE3D_Shader::CE3D_Shader%.body preserve=yes
	iShFlags = SHFLAG_UNDEFINEDFLAGS;
  //## end CE3D_Shader::CE3D_Shader%.body
}


CE3D_Shader::~CE3D_Shader()
{
  //## begin CE3D_Shader::~CE3D_Shader%.body preserve=yes
	if (poInsts)
	{
		// Delete instructions
		for (int i=0;i<iNumInsts;i++)
		{
			mDel poInsts[i];
		}

		// Delete instruction array
		mDel []poInsts;
	}
  //## end CE3D_Shader::~CE3D_Shader%.body
}



//## Other Operations (implementation)
void CE3D_Shader::AddInstruction (CE3D_ShaderInstruction *_poInst)
{
  //## begin CE3D_Shader::AddInstruction%1012941672.body preserve=yes
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
  //## end CE3D_Shader::AddInstruction%1012941672.body
}

void CE3D_Shader::PushInstruction (CE3D_ShaderInstruction *_poInst)
{
  //## begin CE3D_Shader::PushInstruction%1013981857.body preserve=yes
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
  //## end CE3D_Shader::PushInstruction%1013981857.body
}

// Additional Declarations
  //## begin CE3D_Shader%3C603880018F.declarations preserve=yes
void CE3D_Shader::SetupShaderFlags()
{
	iShFlags = 0;
	for (int iInst=0;iInst<iNumInsts;iInst++)
	{
		if (poInsts[iInst]->eInsType == eShIns_BlendOp)
		{
			iShFlags |= SHFLAG_TRANSPARENT;
			return;	// De momento solo necesitamos este flag
		}
	}
}
  //## end CE3D_Shader%3C603880018F.declarations
//## begin module%3C603880018F.epilog preserve=yes
//## end module%3C603880018F.epilog
