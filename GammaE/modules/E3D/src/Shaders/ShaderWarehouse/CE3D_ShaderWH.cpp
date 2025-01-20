// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include <string.h>
// ----------------------------------------------------------------------------
// CE3D_ShaderWH
#include "Shaders\ShaderWarehouse\CE3D_ShaderWH.h"
#include "Shaders\ShaderDefinitions\CE3D_ShaderDefWH.h"
#include "Shaders\ShaderParser\CE3D_ShaderParser.h"
// ----------------------------------------------------------------------------
CE3D_Shader* CE3D_ShaderWH::poCreateShader(const char* _szShaderName)
{
	// Look if the material already exists in the warehouse
    CE3D_Shader* poShader = poFind(_szShaderName);
    if (poShader) return(poShader);
	
    // If it doesn't exist in the shader warehouse,
    // look if it's in the shader definition warehouse
	CGTextResource* poSR = CE3D_ShaderDefWH::I()->poFind(_szShaderName);
    if (poSR)
    {
    	// Try loading shader from definition
	    const char* szShaderDef = poSR->sGetData().szString();
		poShader = CE3D_ShaderParser::poParseShader(szShaderDef,_szShaderName);
	}
	else
		// Try loading shader as a texture
		poShader = CE3D_ShaderParser::poCreateShaderFromTexture(_szShaderName);

	if (! poShader) return(NULL);

	// Add shader to warehouse
	uiAdd(poShader,_szShaderName);

	return (poShader);	
}
// ----------------------------------------------------------------------------
void CE3D_ShaderWH::Invalidate(int _iIdx)
{
	CGResourceWH<CE3D_Shader,CE3D_ShaderWH>::Invalidate(_iIdx);

	if (_iIdx == -1)
	{
		for (int i=0;i<m_oWH.uiNumElems();i++)
			InvalidateElem(i);					// Should derive from resource
	}
	else
	{
		InvalidateElem(_iIdx);					// Should derive from resource		
	}
}
// ----------------------------------------------------------------------------
void CE3D_ShaderWH::InvalidateElem(int _iIdx)
{
	const char* szShaderName = m_oWH.sGetElemName(_iIdx).szString();
	CE3D_Shader* poNewShader = NULL;
	
	// ------------------------
	// If it doesn't exist in the shader warehouse,
	// look if it's in the shader definition warehouse
	CGTextResource* poSR = CE3D_ShaderDefWH::I()->poFind( szShaderName );
	if (poSR)
	{
		// Try loading shader from definition
		const char* szShaderDef = poSR->sGetData().szString();
		poNewShader = CE3D_ShaderParser::poParseShader(szShaderDef,szShaderName);
	}
	else
		// Try loading shader as a texture
		poNewShader = CE3D_ShaderParser::poCreateShaderFromTexture(szShaderName);
	// ------------------------
	
	// Copy the contents
	if (poNewShader == NULL)
	{
		// This shader cannot be invalidated: Probably it was created by code
		return;
	}

	if (m_oWH.oGetElem(_iIdx) == NULL)
	{
		int a = 0;
	}
	m_oWH.oGetElem(_iIdx)->RefCopy(poNewShader);

	//
	memset(poNewShader,0,sizeof(CE3D_Shader));
	mDel poNewShader;
}
// ----------------------------------------------------------------------------
