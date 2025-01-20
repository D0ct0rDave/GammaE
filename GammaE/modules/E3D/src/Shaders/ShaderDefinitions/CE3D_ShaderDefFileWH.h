// ----------------------------------------------------------------------------
#ifndef CE3D_ShaderDefFileWH_h
#define CE3D_ShaderDefFileWH_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
DECLARE_WAREHOUSE(CE3D_ShaderDefFileWH,CGDiskResourceWH,CGTextResource)
{
public:
	virtual CGTextResource* poLoadResource(const CGString& _sFilename);
	virtual void Reload();

private:
	void AddShader (char* _szShaderString);
	void ProcessShaderDefFile(const CGString& _sShaderDefs);
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------