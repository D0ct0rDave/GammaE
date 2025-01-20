// -----------------------------------------------------------------------------
#ifndef CE3D_ShIns_BlendOp_h
#define CE3D_ShIns_BlendOp_h 1
// -----------------------------------------------------------------------------
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
#include "E3D_Enums.h"
// -----------------------------------------------------------------------------
class CE3D_ShIns_BlendOp : public CE3D_ShaderInstruction
{
	public:

		CE3D_ShIns_BlendOp() : CE3D_ShaderInstruction(E3D_SHI_BlendOp), m_eBlendMode(E3D_BM_Copy) {};

		E3D_BlendMode eGetBlendMode()
		{
			return (m_eBlendMode);
		}
		
		void SetBlendMode(E3D_BlendMode value)
		{
			m_eBlendMode = value;
		};

	protected:

		E3D_BlendMode m_eBlendMode;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
