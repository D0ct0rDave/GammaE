//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_Program_h
#define CE3D_ShIns_Program_h 1
//-----------------------------------------------------------------------------
#include "Materials/CGProgram.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//-----------------------------------------------------------------------------
class CE3D_ShIns_Program : public CE3D_ShaderInstruction
{   
	public:
		CE3D_ShIns_Program(): CE3D_ShaderInstruction(E3D_SHI_Program), m_poProgram(NULL){};

		void SetProgram(CGProgram* _poProgram) { m_poProgram = _poProgram; };
		CGProgram* poGetProgram() { return(m_poProgram); };

	protected:
		CGProgram* m_poProgram;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
