// ----------------------------------------------------------------------------
#ifndef CE3D_ShaderWH_h
#define CE3D_ShaderWH_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "Shaders/CE3D_Shader.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CE3D_ShaderWH,CGResourceWH,CE3D_Shader)
{
	public:
		CE3D_ShaderWH() {};

		virtual void Invalidate(int _iIdx = -1);
		void InvalidateElem(int _iIdx);
		CE3D_Shader* poCreateShader(const char* _szShaderName);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
