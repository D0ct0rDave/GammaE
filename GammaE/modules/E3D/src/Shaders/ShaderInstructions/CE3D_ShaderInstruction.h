//-----------------------------------------------------------------------------
#ifndef CE3D_ShaderInstruction_h
#define CE3D_ShaderInstruction_h 1
//-----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\EE3D_ShaderInstructionType.h"
//-----------------------------------------------------------------------------
class CE3D_ShaderInstruction 
{
	public:

		CE3D_ShaderInstruction() : eInsType(E3D_SHI_NULL) {};
		CE3D_ShaderInstruction(E3D_ShaderInstructionType _eInsType) { eInsType = _eInsType; };

		E3D_ShaderInstructionType eGetInstructionType() { return(eInsType); };

	protected:
		E3D_ShaderInstructionType eInsType;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
