//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_SetTMU_h
#define CE3D_ShIns_SetTMU_h 1
//-----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
#include "GammaE_Misc.h"
//-----------------------------------------------------------------------------
class CE3D_ShIns_SetTMU : public CE3D_ShaderInstruction
{   
	public:
		CE3D_ShIns_SetTMU() : CE3D_ShaderInstruction(E3D_SHI_SetTMU) {};
		uint uiGetTMU() { return(m_uiTMU); };
		void SetTMU(uint _uiTMU) { m_uiTMU = _uiTMU; };

	protected:
		uint m_uiTMU;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------

