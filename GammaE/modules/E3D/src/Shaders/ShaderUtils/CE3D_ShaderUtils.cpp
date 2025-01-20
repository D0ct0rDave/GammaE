



#include "GammaE_Mem.h"

// CE3D_ShaderUtils
#include "Shaders\ShaderUtils\CE3D_ShaderUtils.h"


// Class CE3D_ShaderUtils 

int CE3D_ShaderUtils::iUTFlag = 0;

int CE3D_ShaderUtils::iVTFlag = 0;

int CE3D_ShaderUtils::iMagFFlag = 0;

int CE3D_ShaderUtils::iMinFFlag = 0;

CE3D_ShaderUtils::CE3D_ShaderUtils()
        {
}


CE3D_ShaderUtils::~CE3D_ShaderUtils()
{
}



CE3D_Shader* CE3D_ShaderUtils::poGenerateShaderFromMipMap (const CGMipMap* _poMip,const char *_szMatName)
{
  	
	CE3D_Shader* poShader = CE3D_ShaderWH::I()->poFind(_szMatName);
	if (poShader) return(poShader);

	// --------------------
	// Setup texture object
	// --------------------
	CGTextureObj* poTexObj   = mNew CGTextureObj;

	poTexObj->m_uiHandler   = 0;		// Let the GE upload and fill this field
	poTexObj->m_uiUWrap     = iUTFlag;
	poTexObj->m_uiVWrap     = iVTFlag;

	poTexObj->m_uiMinFilter = iMinFFlag;
	poTexObj->m_uiMaxFilter = iMagFFlag;
	poTexObj->m_poMipMap    = (CGMipMap*)_poMip;
	

	// --------------------
	// Setup shader
	// --------------------
	CE3D_ShIns_Texture	*poTI = mNew CE3D_ShIns_Texture;
	poTI->m_poTex = poTexObj;

	CE3D_Shader *poSh = mNew CE3D_Shader;
	CE3D_ShaderWH::I()->uiAdd(poSh,_szMatName);

	poSh->AddInstruction(poTI);
	CTexObjWH::I()->uiAdd(poTexObj,_szMatName);
	return( poSh );

/*
	assert(0);
	return(NULL);

	// --------------------
	// Create mipmap object
	// --------------------
	CMipMapObj* poTex = mNew CMipMapObj;	
	MipMap_fn_iCopyMipMap(_poMip,poTex->m_poMipMap);
	
	// Copy the source mipmap into the texture object mipmap field	
	MipMap_fn_iCopyMipMap(_poMip,&poTex->m_oMipMap);    
	poTex->Invalidate();

	// --------------------
	// Setup texture object
	// --------------------
	CTextureObj* poTexObj   = mNew CTextureObj;

	poTexObj->m_uiHandler   = 0;		// Let the GE upload and fill this field
	poTexObj->m_uiUWrap     = iUTFlag;
	poTexObj->m_uiVWrap     = iVTFlag;

	poTexObj->m_uiMinFilter = iMinFFlag;
	poTexObj->m_uiMaxFilter = iMagFFlag;
	poTexObj->m_poTex       = poTex;

	// --------------------
	// Setup shader
	// --------------------
	CE3D_ShIns_Texture	*poTI = mNew CE3D_ShIns_Texture;
	poTI->pTex = poTexObj;

	CE3D_Shader *poSh = mNew CE3D_Shader;
	CE3D_ShaderWH::I()->iAdd(poSh,_szMatName);

	poSh->AddInstruction(poTI);
	CTexObjWH::I()->iAdd(poTexObj,_szMatName);
	return( poSh );
	*/
}

CE3D_Shader* CE3D_ShaderUtils::poGenerateShaderFromColor (const CGColor& _oColor,const char *_szMatName)
{
  	
	CE3D_Shader* poShader = CE3D_ShaderWH::I()->poFind(_szMatName);
	if (poShader) return(poShader);

	// --------------------
	// Setup shader
	// --------------------
	CE3D_Shader* poSh = mNew CE3D_Shader;
	CE3D_ShaderWH::I()->uiAdd(poSh,_szMatName);

	CE3D_ShIns_Color	*poCI = mNew CE3D_ShIns_Color;
	poCI->SetColor(_oColor);
	poSh->AddInstruction(poCI);

	return( poSh );
}

void CE3D_ShaderUtils::SetupTilingFlags (int _iUTFlag, int _iVTFlag)
{
  	iUTFlag = _iUTFlag;
	iVTFlag = _iVTFlag;
}

void CE3D_ShaderUtils::SetupFilterFlags (int _iMinFFlag, int _iMagFFlag)
{
  	iMinFFlag = _iMinFFlag;
	iMagFFlag = _iMagFFlag;
}

// Additional Declarations
    
