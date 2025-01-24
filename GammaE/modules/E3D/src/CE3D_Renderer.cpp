// -----------------------------------------------------------------------------
#include "GammaE_Mem.h"
#include <string.h>

// CE3D_Renderer
#include "CE3D_Renderer.h"
// -----------------------------------------------------------------------------
#define	_FRUST_STACK_SIZE_	20
// -----------------------------------------------------------------------------
CE3D_Renderer::CE3D_Renderer() : poCurrentShader(NULL), fAspectRatio(1.0f), iScrTX(0), iScrTY(0), iLFrusts(1), eStencilFunc(E3D_SF_None), eStencilFuncLast(E3D_SF_None), eFogMode(E3D_FM_None), eFogModeLast(E3D_FM_None), eZWrite(E3D_ZW_Enable), eZWriteLast(E3D_ZW_Enable), eZTest(E3D_ZTF_LEqual), eZTestLast(E3D_ZTF_LEqual)
{  
    // State variables
    REState.DefferredMode  = false;
    REState.FrustumCulling = true;
    REState.BBoxRender	   = false;
	REState.NormalRender   = false;

	LocalFrustum = mNew CE3D_Frustum[_FRUST_STACK_SIZE_];
	iLFrusts	 = 1;
	
	// Initialize defferred object Warehouse
	oDefObjWH.Init(256);

	Projector	= NULL;
    Camera		= NULL;
	Viewport	= NULL;

}
// -----------------------------------------------------------------------------

CE3D_Renderer::~CE3D_Renderer()
{
  	mDel []LocalFrustum;
}
// -----------------------------------------------------------------------------
int CE3D_Renderer::Init (handler HndDeviceContext, int Options, int ScrTX, int ScrTY, int ColorBits)
{
  	return (0);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::Finish ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::UploadProgram(CGProgram* _poProgram)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::UpdateProgram(CGProgram* _poProgram)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetCurrentProgram(CGProgram* _poProgram)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::InvalidateProgram(CGProgram* _poProgram)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void*_pValue)
{

}
// -----------------------------------------------------------------------------
void CE3D_Renderer::UploadTexture (CGTextureObj *TexObj)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::UpdateTexture (CGTextureObj *TexObj)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::BeginRender ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::EndRender ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::RenderMesh (CMesh *_poMesh)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader* _poShader)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::RenderCompiledMesh (CCompiledMesh* _poCMesh)
{
}
// -----------------------------------------------------------------------------
CCompiledMesh * CE3D_Renderer::poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  	return (NULL);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::DestroyCompiledMesh (CCompiledMesh *_poCMesh)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::RenderDefferredObjects ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::EnableBBoxRender ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::DisableBBoxRender ()
{
}
// -----------------------------------------------------------------------------
bool CE3D_Renderer::UsingBBoxRender ()
{
  	return (false);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetCurrentTextureContext (CGTextureObj *TexObj)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::InvalidateTexture (CGTextureObj *TexObj)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::EnableDefferredMode ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::DisableDefferredMode ()
{
}
// -----------------------------------------------------------------------------
bool CE3D_Renderer::UsingDefferredMode ()
{
  	return (false);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::EnableFrustumCulling ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::DisableFrustumCulling ()
{
}
// -----------------------------------------------------------------------------
bool CE3D_Renderer::UsingFrustumCulling ()
{
  	return (false);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::EnableNormalRender ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::DisableNormalRender ()
{
}
// -----------------------------------------------------------------------------
bool CE3D_Renderer::UsingNormalRender ()
{
  	return (false);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::EnableFlatRendering ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::DisableFlatRendering ()
{
}
// -----------------------------------------------------------------------------
bool CE3D_Renderer::UsingFlatRendering ()
{
  	return(false);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PushWorldMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PopWorldMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::ClearWorldMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::MultiplyMatrix (CMatrix4x4 *Matrix)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PreMultiplyMatrix (CMatrix4x4 *Matrix)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::GetWorldMatrix (CMatrix4x4 *M)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetWorldMatrix (CMatrix4x4 *M)
{
}
// -----------------------------------------------------------------------------
CE3D_Shader* CE3D_Renderer::poGetCurrentMaterial ()
{
  	return (NULL);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PushCameraMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PopCameraMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::ClearCameraMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::GetCameraMatrix (CMatrix4x4 *M)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetCameraMatrix (CMatrix4x4 *M)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PushProjectorMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PopProjectorMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::ClearProjectorMatrix ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::GetProjectorMatrix (CMatrix4x4 *M)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetProjectorMatrix (CMatrix4x4 *M)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::UpdateViewing ()
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetViewport (CE3D_Viewport *_Viewport)
{
}
// -----------------------------------------------------------------------------
CE3D_Viewport * CE3D_Renderer::GetViewport ()
{
  	return (NULL);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetCamera (CE3D_Camera *_Camera)
{
}
// -----------------------------------------------------------------------------
CE3D_Camera * CE3D_Renderer::GetCamera ()
{
  	return (NULL);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetProjector (CE3D_Projector *_Projector)
{
}
// -----------------------------------------------------------------------------
CE3D_Projector * CE3D_Renderer::GetProjector ()
{
  	return (NULL);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PushLocalFrustum ()
{
  	if (iLFrusts == _FRUST_STACK_SIZE_) return;
	
	memcpy(&LocalFrustum[iLFrusts],&LocalFrustum[iLFrusts-1],sizeof(CE3D_Frustum));
	iLFrusts++;
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::ComputeLocalFrustum ()
{
  	// Compute camera to local coordinate system matrixz
	CMatrix4x4		  M;
	GetWorldMatrix(&M);
	M.RTInverse();

	// Compute the local frustum
	LocalFrustum[iLFrusts-1].Copy(Frustum);
	LocalFrustum[iLFrusts-1].Transform(M);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::PopLocalFrustum ()
{
    if (iLFrusts>1) iLFrusts--;
}
// -----------------------------------------------------------------------------
CE3D_Frustum& CE3D_Renderer::GetLocalFrustum ()
{
  	return (LocalFrustum[iLFrusts-1]);
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetStencilPars (E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetFogPars (E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetZPars (E3D_ZTestFunc _eZTest, E3D_ZWrite _eZWrite)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::ClearBuffer (E3D_RenderBuffer_Type _eBuffer)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetupLight (int _iLightID, CE3D_Light& _oLight)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetLight (int _iLightID, bool _bEnable)
{
}
// -----------------------------------------------------------------------------
void CE3D_Renderer::SetConstantColor(const CGColor& _oColor)
{
	m_oColor = _oColor;
}
// -----------------------------------------------------------------------------
const CGColor& CE3D_Renderer::oGetConstantColor(const CGColor& _oColor)
{
	return(m_oColor);
}
// -----------------------------------------------------------------------------
