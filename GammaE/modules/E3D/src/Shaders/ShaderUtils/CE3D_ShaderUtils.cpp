//## begin module%3C6D9C350076.cm preserve=no
//## end module%3C6D9C350076.cm

//## begin module%3C6D9C350076.cp preserve=no
//## end module%3C6D9C350076.cp

//## Module: CE3D_ShaderUtils%3C6D9C350076; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\Shaders\ShaderUtils\CE3D_ShaderUtils.cpp

//## begin module%3C6D9C350076.additionalIncludes preserve=no
//## end module%3C6D9C350076.additionalIncludes

//## begin module%3C6D9C350076.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include "tex.h"
#include "Color.h"
//## end module%3C6D9C350076.includes

// CE3D_ShaderUtils
#include "E3D\Shaders\ShaderUtils\CE3D_ShaderUtils.h"
//## begin module%3C6D9C350076.additionalDeclarations preserve=yes

//## end module%3C6D9C350076.additionalDeclarations


// Class CE3D_ShaderUtils 

//## begin CE3D_ShaderUtils::iUTFlag%3C6DA3560141.attr preserve=no  private: static int {UA} 0
int CE3D_ShaderUtils::iUTFlag = 0;
//## end CE3D_ShaderUtils::iUTFlag%3C6DA3560141.attr

//## begin CE3D_ShaderUtils::iVTFlag%3C6DA35E034B.attr preserve=no  private: static int {UA} 0
int CE3D_ShaderUtils::iVTFlag = 0;
//## end CE3D_ShaderUtils::iVTFlag%3C6DA35E034B.attr

CE3D_ShaderUtils::CE3D_ShaderUtils()
  //## begin CE3D_ShaderUtils::CE3D_ShaderUtils%.hasinit preserve=no
  //## end CE3D_ShaderUtils::CE3D_ShaderUtils%.hasinit
  //## begin CE3D_ShaderUtils::CE3D_ShaderUtils%.initialization preserve=yes
  //## end CE3D_ShaderUtils::CE3D_ShaderUtils%.initialization
{
  //## begin CE3D_ShaderUtils::CE3D_ShaderUtils%.body preserve=yes
  //## end CE3D_ShaderUtils::CE3D_ShaderUtils%.body
}


CE3D_ShaderUtils::~CE3D_ShaderUtils()
{
  //## begin CE3D_ShaderUtils::~CE3D_ShaderUtils%.body preserve=yes
  //## end CE3D_ShaderUtils::~CE3D_ShaderUtils%.body
}



//## Other Operations (implementation)
CE3D_Shader* CE3D_ShaderUtils::poGenerateShaderFromTexture (Texture* _poTex, char *_szMatName)
{
  //## begin CE3D_ShaderUtils::poGenerateShaderFromTexture%1013817337.body preserve=yes
	CE3D_Shader  *poSh;

	// Generate a mipmap from the given texture
	MipMap* mipMap = poCreateMipMapFromTexture(_poTex);
	
	// Call the mipmap material generator function
	poSh = poGenerateShaderFromMipMap(mipMap, _szMatName);

	DestroyMipMap(mipMap);

	return( poSh );
  //## end CE3D_ShaderUtils::poGenerateShaderFromTexture%1013817337.body
}

CE3D_Shader* CE3D_ShaderUtils::poGenerateShaderFromMipMap (MipMap* _poMip, char *_szMatName)
{
  //## begin CE3D_ShaderUtils::poGenerateShaderFromMipMap%1013817338.body preserve=yes

	// --------------------
	// Create mipmap object
	// --------------------
	TMipMapObj		* mipMapObj;
	mipMapObj = new TMipMapObj();

	// Copy the source mipmap into the texture object mipmap field	
	mipMapObj->mipMap = poCreateMipMapCopy(_poMip);
	mipMapObj->Handler	= 0;							// Let the GE upload and fill this field
	mipMapObj->Update	= true;

	// --------------------
	// Setup texture object
	// --------------------
	TTextureObj			*poTexObj = TTexObjWarehouse::AllocateTexObj();
	poTexObj->UWrap     = iUTFlag;
	poTexObj->VWrap     = iVTFlag;

	poTexObj->MinFilter = E3D_TEX_MIN_FILTER_NEAREST;
	poTexObj->MaxFilter = E3D_TEX_MIN_FILTER_LINEAR;
	poTexObj->MipMapObj = mipMapObj;
	
	// --------------------
	// Setup shader
	// --------------------
	CE3D_ShIns_Texture	*poTI = mNew CE3D_ShIns_Texture;
	poTI->pTex = poTexObj;

	int					iShId = CE3D_ShaderWH::iAllocShader(_szMatName);
	CE3D_Shader			*poSh = CE3D_ShaderWH::poGetShader (iShId);
	
	poSh->AddInstruction(poTI);
	return( poSh );
  //## end CE3D_ShaderUtils::poGenerateShaderFromMipMap%1013817338.body
}

CE3D_Shader* CE3D_ShaderUtils::poGenerateShaderFromColor (TFColor& _oColor, char *_szMatName)
{
  //## begin CE3D_ShaderUtils::poGenerateShaderFromColor%1013817339.body preserve=yes
	// --------------------
	// Setup shader
	// --------------------
	CE3D_ShIns_Color	*poCI = mNew CE3D_ShIns_Color;
	poCI->oColor.SetColor(_oColor.r,_oColor.g,_oColor.b,_oColor.a);

	int					iShId = CE3D_ShaderWH::iAllocShader(_szMatName);
	CE3D_Shader			*poSh = CE3D_ShaderWH::poGetShader (iShId);

	poSh->AddInstruction(poCI);

	return( poSh );
  //## end CE3D_ShaderUtils::poGenerateShaderFromColor%1013817339.body
}

void CE3D_ShaderUtils::SetupTilingFlags (int _iUTFlag, int _iVTFlag)
{
  //## begin CE3D_ShaderUtils::SetupTilingFlags%1013817340.body preserve=yes
	iUTFlag = _iUTFlag;
	iVTFlag = _iVTFlag;
  //## end CE3D_ShaderUtils::SetupTilingFlags%1013817340.body
}

// Additional Declarations
  //## begin CE3D_ShaderUtils%3C6D9C350076.declarations preserve=yes
  //## end CE3D_ShaderUtils%3C6D9C350076.declarations

//## begin module%3C6D9C350076.epilog preserve=yes
//## end module%3C6D9C350076.epilog
