//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_Wireframe_h
#define CE3D_ShIns_Wireframe_h 1
//-----------------------------------------------------------------------------
#include "Materials/CGColor.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//-----------------------------------------------------------------------------
class CE3D_ShIns_Wireframe : public CE3D_ShaderInstruction
{   
	public:
		CE3D_ShIns_Wireframe() : CE3D_ShaderInstruction(E3D_SHI_Wireframe) {};

		void SetColor(const CGColor& _oColor) { m_oColor = _oColor; };
		const CGColor& oGetColor() { return(m_oColor); };

	protected:
		CGColor m_oColor;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
