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
#include <string.h>
// -----------------------------------------------------------------------------
#include "CGRenderer.h"
#include "RenderVars/CGRenderVars.h"
// -----------------------------------------------------------------------------
#define _FRUST_STACK_SIZE_  20
// ----------------------------------------------------------------------------
CGE3DRenderer::CGE3DRenderer() : m_poCurrentShader(NULL), m_fAspectRatio(1.0f), m_uiScrTX(0), m_uiScrTY(0), m_eStencilFunc(E3D_SF_None), m_eStencilFuncLast(E3D_SF_None), m_eFogMode(E3D_FM_None), m_eFogModeLast(E3D_FM_None), m_eZWrite(E3D_ZW_Enable), m_eZWriteLast(E3D_ZW_Enable), m_eZTest(E3D_ZTF_LEqual), m_eZTestLast(E3D_ZTF_LEqual)
{
    // State variables
    m_oREState.m_bDefferredMode = false;
    m_oREState.m_bFrustumCulling = true;
    m_oREState.m_bBVRender = false;
    m_oREState.m_bNormalRender = false;
    m_oREState.m_bFlatRender = false;

    // Initialize defferred object Warehouse
    m_oDefObjWH.Init(256);
    CGRenderVars::I()->Init(10);

    m_poProjector = NULL;
    m_poCamera = NULL;
    m_poViewport = NULL;
}
// ----------------------------------------------------------------------------
bool CGE3DRenderer::bInit(handler _hDeviceContext, uint _uiOptions, uint _uiScrTX, uint _uiScrTY, uint _uiColorBits)
{
    return (0);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::Finish ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::UploadProgram(CGProgram* _poProgram)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::UpdateProgram(CGProgram* _poProgram)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetCurrentProgram(CGProgram* _poProgram)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::InvalidateProgram(CGProgram* _poProgram)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void* _pValue)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::UploadTexture (CGTextureObj* TexObj)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::UpdateTexture (CGTextureObj* TexObj)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::BeginRender ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::EndRender ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::RenderMesh (CGBaseMesh* _poMesh, CGShader* _poShader)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::RenderMesh (CGBaseMesh* _poMesh)
{
}
// ----------------------------------------------------------------------------
CGCompiledMesh* CGE3DRenderer::poCompileMesh (CGMesh* _poMesh, CGShader* _poShader)
{
    return (NULL);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::DestroyCompiledMesh (CGCompiledMesh* _poCGMesh)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::RenderDefferredObjects ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::EnableBVRender ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::DisableBVRender ()
{
}
// ----------------------------------------------------------------------------
bool CGE3DRenderer::bIsUsingBBRender ()
{
    return (false);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetCurrentTexture (CGTextureObj* TexObj)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::InvalidateTexture (CGTextureObj* TexObj)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::EnableDefferredMode ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::DisableDefferredMode ()
{
}
// ----------------------------------------------------------------------------
bool CGE3DRenderer::bIsUsingDefferredMode ()
{
    return (false);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::EnableFrustumCulling ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::DisableFrustumCulling ()
{
}
// ----------------------------------------------------------------------------
bool CGE3DRenderer::bIsUsingFrustumCulling ()
{
    return (false);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::EnableNormalRender ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::DisableNormalRender ()
{
}
// ----------------------------------------------------------------------------
bool CGE3DRenderer::bIsUsingNormalRender ()
{
    return (false);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::EnableFlatRendering ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::DisableFlatRendering ()
{
}
// ----------------------------------------------------------------------------
bool CGE3DRenderer::bIsUsingFlatRendering ()
{
    return(false);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PushWorldMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PopWorldMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::ClearWorldMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::MultiplyMatrix (const CGMatrix4x4& _oMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PreMultiplyMatrix (const CGMatrix4x4& _oMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::GetWorldMatrix (CGMatrix4x4* _poMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetWorldMatrix (const CGMatrix4x4& _oMatrix)
{
}
// ----------------------------------------------------------------------------
CGShader* CGE3DRenderer::poGetCurrentMaterial ()
{
    return (NULL);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PushCameraMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PopCameraMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::ClearCameraMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::GetCameraMatrix (CGMatrix4x4* _oMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetCameraMatrix (const CGMatrix4x4& _oMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PushProjectorMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::PopProjectorMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::ClearProjectorMatrix ()
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::GetProjectorMatrix (CGMatrix4x4* _poMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetProjectorMatrix (const CGMatrix4x4& _oMatrix)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetViewport (CGViewport* _Viewport)
{
}
// ----------------------------------------------------------------------------
CGViewport* CGE3DRenderer::poGetViewport ()
{
    return (NULL);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetCamera (CGCamera* _Camera)
{
}
// ----------------------------------------------------------------------------
CGCamera* CGE3DRenderer::poGetCamera ()
{
    return (NULL);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetProjector (CGProjector* _Projector)
{
}
// ----------------------------------------------------------------------------
CGProjector* CGE3DRenderer::poGetProjector ()
{
    return (NULL);
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::ReadBuffer (uint _uiX, uint _uiY, uint _uiTX, uint _uiTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::WriteBuffer (uint _uiX, uint _uiY, uint _uiTX, uint _uiTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetStencilPars (E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetFogPars (E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetZPars (E3D_ZTestFunc _eZTest, E3D_ZWrite _eZWrite)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::ClearBuffer (E3D_RenderBuffer_Type _eBuffer)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetupLight (int _iLightID, const CGLight& _oLight)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetLight (int _iLightID, bool _bEnable)
{
}
// ----------------------------------------------------------------------------
void CGE3DRenderer::SetConstantColor(const CGColor& _oColor)
{
    m_oColor = _oColor;
}
// ----------------------------------------------------------------------------
const CGColor& CGE3DRenderer::oGetConstantColor(const CGColor& _oColor)
{
    return(m_oColor);
}
// ----------------------------------------------------------------------------
