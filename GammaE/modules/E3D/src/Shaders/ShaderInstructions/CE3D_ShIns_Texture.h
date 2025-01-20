//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_Texture_h
#define CE3D_ShIns_Texture_h 1
//-----------------------------------------------------------------------------
#include "Materials/CGTexObj.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//-----------------------------------------------------------------------------
class CE3D_ShIns_Texture : public CE3D_ShaderInstruction
{
	public:
		CE3D_ShIns_Texture() : CE3D_ShaderInstruction(E3D_SHI_Texture), m_poTex(NULL) {};
		CGTextureObj* m_poTex;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
