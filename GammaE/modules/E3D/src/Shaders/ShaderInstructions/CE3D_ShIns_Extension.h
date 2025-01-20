//-----------------------------------------------------------------------------
#ifndef CE3D_ShIns_Extension_h
#define CE3D_ShIns_Extension_h 1
//-----------------------------------------------------------------------------
// CE3D_ShaderInstruction
#include "Shaders\ShaderInstructions\CE3D_ShaderInstruction.h"
//-----------------------------------------------------------------------------
typedef void (*TExtensionFunction)(void *p1);
//-----------------------------------------------------------------------------
class CE3D_ShIns_Extension : public CE3D_ShaderInstruction
{   
	public:
			CE3D_ShIns_Extension() : CE3D_ShaderInstruction(E3D_SHI_Extension), m_pFunction(NULL) {};

			TExtensionFunction pFunction() { return(m_pFunction); };
			void SetFunction(TExtensionFunction _pFunction) { m_pFunction = _pFunction; };

	protected:
			TExtensionFunction m_pFunction;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
