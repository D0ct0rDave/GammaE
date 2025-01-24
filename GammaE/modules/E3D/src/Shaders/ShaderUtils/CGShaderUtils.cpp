// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include "CGShaderUtils.h"
#include "Shaders/ShaderWarehouse/CGShaderWH.h"
#include "Shaders/ShaderInstructions/CGShInsTexture.h"
#include "Shaders/ShaderInstructions/CGShInsColor.h"
#include "Materials/CGTexObjWH.h"
#include "Materials/CGTexObj.h"
// ----------------------------------------------------------------------------
int CGShaderUtils::iUTFlag = 0;

int CGShaderUtils::iVTFlag = 0;

int CGShaderUtils::iMagFFlag = 0;

int CGShaderUtils::iMinFFlag = 0;
// ----------------------------------------------------------------------------
CGShaderUtils::CGShaderUtils()
{
}
// ----------------------------------------------------------------------------
CGShaderUtils::~CGShaderUtils()
{
}
// ----------------------------------------------------------------------------
CGShader* CGShaderUtils::poGenerateShaderFromMipMap (const CGMipMap* _poMip,const char* _szMatName)
{
    CGShader* poShader = CGShaderWH::I()->poFind(_szMatName);
    if ( poShader ) return(poShader);

    // --------------------
    // Setup texture object
    // --------------------
    CGTextureObj* poTexObj = mNew CGTextureObj;

    poTexObj->m_uiHandler = 0;          // Let the GE upload and fill this field
    poTexObj->m_uiUWrap = iUTFlag;
    poTexObj->m_uiVWrap = iVTFlag;

    poTexObj->m_uiMinFilter = iMinFFlag;
    poTexObj->m_uiMaxFilter = iMagFFlag;
    poTexObj->m_poMipMap = (CGMipMap*)_poMip;

    // --------------------
    // Setup shader
    // --------------------
    CGShInsTexture* poTI = mNew CGShInsTexture;
    poTI->m_poTex = poTexObj;

    CGShader* poSh = mNew CGShader;
    CGShaderWH::I()->uiAdd(poSh,_szMatName);

    poSh->AddInstruction(poTI);
    CGTexObjWH::I()->uiAdd(poTexObj,_szMatName);
    return(poSh);

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
    CGShInsTexture	*poTI = mNew CGShInsTexture;
    poTI->pTex = poTexObj;

    CGShader *poSh = mNew CGShader;
    CGShaderWH::I()->iAdd(poSh,_szMatName);

    poSh->AddInstruction(poTI);
    CGTexObjWH::I()->iAdd(poTexObj,_szMatName);
    return( poSh );
 */
}
// ----------------------------------------------------------------------------
CGShader* CGShaderUtils::poGenerateShaderFromColor (const CGColor& _oColor,const char* _szMatName)
{
    CGShader* poShader = CGShaderWH::I()->poFind(_szMatName);
    if ( poShader ) return(poShader);

    // --------------------
    // Setup shader
    // --------------------
    CGShader* poSh = mNew CGShader;
    CGShaderWH::I()->uiAdd(poSh,_szMatName);

    CGShInsColor* poCI = mNew CGShInsColor;
    poCI->SetColor(_oColor);
    poSh->AddInstruction(poCI);

    return(poSh);
}
// ----------------------------------------------------------------------------
void CGShaderUtils::SetupTilingFlags (int _iUTFlag, int _iVTFlag)
{
    iUTFlag = _iUTFlag;
    iVTFlag = _iVTFlag;
}
// ----------------------------------------------------------------------------
void CGShaderUtils::SetupFilterFlags (int _iMinFFlag, int _iMagFFlag)
{
    iMinFFlag = _iMinFFlag;
    iMagFFlag = _iMagFFlag;
}
// ----------------------------------------------------------------------------
