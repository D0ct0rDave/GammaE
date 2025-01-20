//## begin module%3A9AB88A01CC.cm preserve=no
//## end module%3A9AB88A01CC.cm

//## begin module%3A9AB88A01CC.cp preserve=no
//## end module%3A9AB88A01CC.cp

//## Module: CE3D_Renderer%3A9AB88A01CC; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\CE3D_Renderer.cpp

//## begin module%3A9AB88A01CC.additionalIncludes preserve=no
//## end module%3A9AB88A01CC.additionalIncludes

//## begin module%3A9AB88A01CC.includes preserve=yes
#include "Memory/GammaE_Mem.h"
#include <string.h>
//## end module%3A9AB88A01CC.includes

// CE3D_Renderer
#include "E3D\CE3D_Renderer.h"
//## begin module%3A9AB88A01CC.additionalDeclarations preserve=yes
#define	_FRUST_STACK_SIZE_	20
//## end module%3A9AB88A01CC.additionalDeclarations


// Class CE3D_Renderer 























CE3D_Renderer::CE3D_Renderer()
  //## begin CE3D_Renderer::CE3D_Renderer%.hasinit preserve=no
      : poCurrentShader(NULL), fAspectRatio(1.0f), iScrTX(0), iScrTY(0), iLFrusts(1), eStencilFunc(eE3D_SF_None), eStencilFuncLast(eE3D_SF_None), eFogMode(eE3D_FM_None), eFogModeLast(eE3D_FM_None), eZWrite(eE3D_ZW_Enable), eZWriteLast(eE3D_ZW_Enable), eZTest(eE3D_ZTF_LEqual), eZTestLast(eE3D_ZTF_LEqual)
  //## end CE3D_Renderer::CE3D_Renderer%.hasinit
  //## begin CE3D_Renderer::CE3D_Renderer%.initialization preserve=yes
  //## end CE3D_Renderer::CE3D_Renderer%.initialization
{
  //## begin CE3D_Renderer::CE3D_Renderer%.body preserve=yes

    // State variables
    REState.DefferredMode  = false;
    REState.FrustumCulling = true;
    REState.BBoxRender	   = false;
	REState.NormalRender   = false;

	LocalFrustum = mNew CE3D_Frustum[_FRUST_STACK_SIZE_];
	iLFrusts	 = 1;
	
	// Initialize defferred object Warehouse
	oDefObjWH.Init(256);

  //## end CE3D_Renderer::CE3D_Renderer%.body
}


CE3D_Renderer::~CE3D_Renderer()
{
  //## begin CE3D_Renderer::~CE3D_Renderer%.body preserve=yes
	mDel []LocalFrustum;
  //## end CE3D_Renderer::~CE3D_Renderer%.body
}



//## Other Operations (implementation)
int CE3D_Renderer::Init (void *HndDeviceContext, int Options, int ScrTX, int ScrTY, int ColorBits)
{
  //## begin CE3D_Renderer::Init%1003953158.body preserve=yes
	return (0);
  //## end CE3D_Renderer::Init%1003953158.body
}

void CE3D_Renderer::Finish ()
{
  //## begin CE3D_Renderer::Finish%983399604.body preserve=yes
  //## end CE3D_Renderer::Finish%983399604.body
}

void CE3D_Renderer::UploadTexture (TTextureObj *TexObj)
{
  //## begin CE3D_Renderer::UploadTexture%983314250.body preserve=yes
  //## end CE3D_Renderer::UploadTexture%983314250.body
}

void CE3D_Renderer::UpdateTexture (TTextureObj *TexObj)
{
  //## begin CE3D_Renderer::UpdateTexture%983314251.body preserve=yes
  //## end CE3D_Renderer::UpdateTexture%983314251.body
}

void CE3D_Renderer::BeginRender ()
{
  //## begin CE3D_Renderer::BeginRender%983314252.body preserve=yes
  //## end CE3D_Renderer::BeginRender%983314252.body
}

void CE3D_Renderer::EndRender ()
{
  //## begin CE3D_Renderer::EndRender%983314253.body preserve=yes
  //## end CE3D_Renderer::EndRender%983314253.body
}

void CE3D_Renderer::RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_Renderer::RenderMesh%983314256.body preserve=yes
  //## end CE3D_Renderer::RenderMesh%983314256.body
}

void CE3D_Renderer::RenderMesh (CMesh *_poMesh)
{
  //## begin CE3D_Renderer::RenderMesh%983314257.body preserve=yes
  //## end CE3D_Renderer::RenderMesh%983314257.body
}

void CE3D_Renderer::RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader* _poShader)
{
  //## begin CE3D_Renderer::RenderCompiledMesh%1011911184.body preserve=yes
  //## end CE3D_Renderer::RenderCompiledMesh%1011911184.body
}

void CE3D_Renderer::RenderCompiledMesh (CCompiledMesh* _poCMesh)
{
  //## begin CE3D_Renderer::RenderCompiledMesh%1011911185.body preserve=yes
  //## end CE3D_Renderer::RenderCompiledMesh%1011911185.body
}

CCompiledMesh * CE3D_Renderer::poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader)
{
  //## begin CE3D_Renderer::poCompileMesh%1011911186.body preserve=yes
	return (NULL);
  //## end CE3D_Renderer::poCompileMesh%1011911186.body
}

void CE3D_Renderer::DestroyCompiledMesh (CCompiledMesh *_poCMesh)
{
  //## begin CE3D_Renderer::DestroyCompiledMesh%1011911200.body preserve=yes
  //## end CE3D_Renderer::DestroyCompiledMesh%1011911200.body
}

void CE3D_Renderer::RenderDefferredObjects ()
{
  //## begin CE3D_Renderer::RenderDefferredObjects%983314258.body preserve=yes
  //## end CE3D_Renderer::RenderDefferredObjects%983314258.body
}

void CE3D_Renderer::EnableBBoxRender ()
{
  //## begin CE3D_Renderer::EnableBBoxRender%983314262.body preserve=yes
  //## end CE3D_Renderer::EnableBBoxRender%983314262.body
}

void CE3D_Renderer::DisableBBoxRender ()
{
  //## begin CE3D_Renderer::DisableBBoxRender%983314263.body preserve=yes
  //## end CE3D_Renderer::DisableBBoxRender%983314263.body
}

bool CE3D_Renderer::UsingBBoxRender ()
{
  //## begin CE3D_Renderer::UsingBBoxRender%983314264.body preserve=yes
	return (false);
  //## end CE3D_Renderer::UsingBBoxRender%983314264.body
}

void CE3D_Renderer::SetCurrentTextureContext (TTextureObj *TexObj)
{
  //## begin CE3D_Renderer::SetCurrentTextureContext%983314265.body preserve=yes
  //## end CE3D_Renderer::SetCurrentTextureContext%983314265.body
}

void CE3D_Renderer::EnableDefferredMode ()
{
  //## begin CE3D_Renderer::EnableDefferredMode%983314266.body preserve=yes
  //## end CE3D_Renderer::EnableDefferredMode%983314266.body
}

void CE3D_Renderer::DisableDefferredMode ()
{
  //## begin CE3D_Renderer::DisableDefferredMode%983314267.body preserve=yes
  //## end CE3D_Renderer::DisableDefferredMode%983314267.body
}

bool CE3D_Renderer::UsingDefferredMode ()
{
  //## begin CE3D_Renderer::UsingDefferredMode%983314268.body preserve=yes
	return (false);
  //## end CE3D_Renderer::UsingDefferredMode%983314268.body
}

void CE3D_Renderer::EnableFrustumCulling ()
{
  //## begin CE3D_Renderer::EnableFrustumCulling%983314269.body preserve=yes
  //## end CE3D_Renderer::EnableFrustumCulling%983314269.body
}

void CE3D_Renderer::DisableFrustumCulling ()
{
  //## begin CE3D_Renderer::DisableFrustumCulling%983314270.body preserve=yes
  //## end CE3D_Renderer::DisableFrustumCulling%983314270.body
}

bool CE3D_Renderer::UsingFrustumCulling ()
{
  //## begin CE3D_Renderer::UsingFrustumCulling%983314271.body preserve=yes
	return (false);
  //## end CE3D_Renderer::UsingFrustumCulling%983314271.body
}

void CE3D_Renderer::EnableNormalRender ()
{
  //## begin CE3D_Renderer::EnableNormalRender%1003953163.body preserve=yes
  //## end CE3D_Renderer::EnableNormalRender%1003953163.body
}

void CE3D_Renderer::DisableNormalRender ()
{
  //## begin CE3D_Renderer::DisableNormalRender%1003953164.body preserve=yes
  //## end CE3D_Renderer::DisableNormalRender%1003953164.body
}

bool CE3D_Renderer::UsingNormalRender ()
{
  //## begin CE3D_Renderer::UsingNormalRender%1003953165.body preserve=yes
	return (false);
  //## end CE3D_Renderer::UsingNormalRender%1003953165.body
}

void CE3D_Renderer::EnableFlatRendering ()
{
  //## begin CE3D_Renderer::EnableFlatRendering%1018547523.body preserve=yes
  //## end CE3D_Renderer::EnableFlatRendering%1018547523.body
}

void CE3D_Renderer::DisableFlatRendering ()
{
  //## begin CE3D_Renderer::DisableFlatRendering%1018547524.body preserve=yes
  //## end CE3D_Renderer::DisableFlatRendering%1018547524.body
}

bool CE3D_Renderer::UsingFlatRendering ()
{
  //## begin CE3D_Renderer::UsingFlatRendering%1018547525.body preserve=yes
	return(false);
  //## end CE3D_Renderer::UsingFlatRendering%1018547525.body
}

void CE3D_Renderer::Translate (float x, float y, float z)
{
  //## begin CE3D_Renderer::Translate%983314275.body preserve=yes
  //## end CE3D_Renderer::Translate%983314275.body
}

void CE3D_Renderer::TranslateX (float Value)
{
  //## begin CE3D_Renderer::TranslateX%983314276.body preserve=yes
  //## end CE3D_Renderer::TranslateX%983314276.body
}

void CE3D_Renderer::TranslateY (float Value)
{
  //## begin CE3D_Renderer::TranslateY%983314277.body preserve=yes
  //## end CE3D_Renderer::TranslateY%983314277.body
}

void CE3D_Renderer::TranslateZ (float Value)
{
  //## begin CE3D_Renderer::TranslateZ%983314278.body preserve=yes
  //## end CE3D_Renderer::TranslateZ%983314278.body
}

void CE3D_Renderer::Scale (float x, float y, float z)
{
  //## begin CE3D_Renderer::Scale%983314279.body preserve=yes
  //## end CE3D_Renderer::Scale%983314279.body
}

void CE3D_Renderer::ScaleX (float Value)
{
  //## begin CE3D_Renderer::ScaleX%983314280.body preserve=yes
  //## end CE3D_Renderer::ScaleX%983314280.body
}

void CE3D_Renderer::ScaleY (float Value)
{
  //## begin CE3D_Renderer::ScaleY%983314281.body preserve=yes
  //## end CE3D_Renderer::ScaleY%983314281.body
}

void CE3D_Renderer::ScaleZ (float Value)
{
  //## begin CE3D_Renderer::ScaleZ%983314282.body preserve=yes
  //## end CE3D_Renderer::ScaleZ%983314282.body
}

void CE3D_Renderer::Rotate (float Angle, float v0, float v1, float v2)
{
  //## begin CE3D_Renderer::Rotate%983314283.body preserve=yes
  //## end CE3D_Renderer::Rotate%983314283.body
}

void CE3D_Renderer::RotateX (float Angle)
{
  //## begin CE3D_Renderer::RotateX%983314284.body preserve=yes
  //## end CE3D_Renderer::RotateX%983314284.body
}

void CE3D_Renderer::RotateY (float Angle)
{
  //## begin CE3D_Renderer::RotateY%983314285.body preserve=yes
  //## end CE3D_Renderer::RotateY%983314285.body
}

void CE3D_Renderer::RotateZ (float Angle)
{
  //## begin CE3D_Renderer::RotateZ%983314286.body preserve=yes
  //## end CE3D_Renderer::RotateZ%983314286.body
}

void CE3D_Renderer::PushMatrix ()
{
  //## begin CE3D_Renderer::PushMatrix%983314287.body preserve=yes
  //## end CE3D_Renderer::PushMatrix%983314287.body
}

void CE3D_Renderer::PopMatrix ()
{
  //## begin CE3D_Renderer::PopMatrix%983314288.body preserve=yes
  //## end CE3D_Renderer::PopMatrix%983314288.body
}

void CE3D_Renderer::LoadIdentity ()
{
  //## begin CE3D_Renderer::LoadIdentity%983314289.body preserve=yes
  //## end CE3D_Renderer::LoadIdentity%983314289.body
}

void CE3D_Renderer::MultiplyMatrix (CMatrix4x4 *Matrix)
{
  //## begin CE3D_Renderer::MultiplyMatrix%985636791.body preserve=yes
  //## end CE3D_Renderer::MultiplyMatrix%985636791.body
}

void CE3D_Renderer::PreMultiplyMatrix (CMatrix4x4 *Matrix)
{
  //## begin CE3D_Renderer::PreMultiplyMatrix%985636792.body preserve=yes
  //## end CE3D_Renderer::PreMultiplyMatrix%985636792.body
}

void CE3D_Renderer::GetCurrentMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_Renderer::GetCurrentMatrix%983314290.body preserve=yes
  //## end CE3D_Renderer::GetCurrentMatrix%983314290.body
}

void CE3D_Renderer::SetCurrentMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_Renderer::SetCurrentMatrix%983314291.body preserve=yes
  //## end CE3D_Renderer::SetCurrentMatrix%983314291.body
}

CE3D_Shader* CE3D_Renderer::poGetCurrentMaterial ()
{
  //## begin CE3D_Renderer::poGetCurrentMaterial%985636794.body preserve=yes
	return (NULL);
  //## end CE3D_Renderer::poGetCurrentMaterial%985636794.body
}

void CE3D_Renderer::PushCameraMatrix ()
{
  //## begin CE3D_Renderer::PushCameraMatrix%1003953174.body preserve=yes
  //## end CE3D_Renderer::PushCameraMatrix%1003953174.body
}

void CE3D_Renderer::PopCameraMatrix ()
{
  //## begin CE3D_Renderer::PopCameraMatrix%1003953175.body preserve=yes
  //## end CE3D_Renderer::PopCameraMatrix%1003953175.body
}

void CE3D_Renderer::ClearCameraMatrix ()
{
  //## begin CE3D_Renderer::ClearCameraMatrix%1003953176.body preserve=yes
  //## end CE3D_Renderer::ClearCameraMatrix%1003953176.body
}

void CE3D_Renderer::GetCameraMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_Renderer::GetCameraMatrix%1003953166.body preserve=yes
  //## end CE3D_Renderer::GetCameraMatrix%1003953166.body
}

void CE3D_Renderer::SetCameraMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_Renderer::SetCameraMatrix%1003953167.body preserve=yes
  //## end CE3D_Renderer::SetCameraMatrix%1003953167.body
}

void CE3D_Renderer::PushProjectorMatrix ()
{
  //## begin CE3D_Renderer::PushProjectorMatrix%1003953177.body preserve=yes
  //## end CE3D_Renderer::PushProjectorMatrix%1003953177.body
}

void CE3D_Renderer::PopProjectorMatrix ()
{
  //## begin CE3D_Renderer::PopProjectorMatrix%1003953178.body preserve=yes
  //## end CE3D_Renderer::PopProjectorMatrix%1003953178.body
}

void CE3D_Renderer::ClearProjectorMatrix ()
{
  //## begin CE3D_Renderer::ClearProjectorMatrix%1003953179.body preserve=yes
  //## end CE3D_Renderer::ClearProjectorMatrix%1003953179.body
}

void CE3D_Renderer::GetProjectorMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_Renderer::GetProjectorMatrix%1003953168.body preserve=yes
  //## end CE3D_Renderer::GetProjectorMatrix%1003953168.body
}

void CE3D_Renderer::SetProjectorMatrix (CMatrix4x4 *M)
{
  //## begin CE3D_Renderer::SetProjectorMatrix%1003953169.body preserve=yes
  //## end CE3D_Renderer::SetProjectorMatrix%1003953169.body
}

void CE3D_Renderer::UpdateViewing ()
{
  //## begin CE3D_Renderer::UpdateViewing%1003953265.body preserve=yes
  //## end CE3D_Renderer::UpdateViewing%1003953265.body
}

void CE3D_Renderer::SetViewport (CE3D_Viewport *_Viewport)
{
  //## begin CE3D_Renderer::SetViewport%1003953267.body preserve=yes
  //## end CE3D_Renderer::SetViewport%1003953267.body
}

CE3D_Viewport * CE3D_Renderer::GetViewport ()
{
  //## begin CE3D_Renderer::GetViewport%1003953268.body preserve=yes
	return (NULL);
  //## end CE3D_Renderer::GetViewport%1003953268.body
}

void CE3D_Renderer::SetCamera (CE3D_Camera *_Camera)
{
  //## begin CE3D_Renderer::SetCamera%1003953269.body preserve=yes
  //## end CE3D_Renderer::SetCamera%1003953269.body
}

CE3D_Camera * CE3D_Renderer::GetCamera ()
{
  //## begin CE3D_Renderer::GetCamera%1003953270.body preserve=yes
	return (NULL);
  //## end CE3D_Renderer::GetCamera%1003953270.body
}

void CE3D_Renderer::SetProjector (CE3D_Projector *_Projector)
{
  //## begin CE3D_Renderer::SetProjector%1003953271.body preserve=yes
  //## end CE3D_Renderer::SetProjector%1003953271.body
}

CE3D_Projector * CE3D_Renderer::GetProjector ()
{
  //## begin CE3D_Renderer::GetProjector%1003953272.body preserve=yes
	return (NULL);
  //## end CE3D_Renderer::GetProjector%1003953272.body
}

void CE3D_Renderer::PushLocalFrustum ()
{
  //## begin CE3D_Renderer::PushLocalFrustum%1007327356.body preserve=yes
	if (iLFrusts == _FRUST_STACK_SIZE_) return;
	
	memcpy(&LocalFrustum[iLFrusts],&LocalFrustum[iLFrusts-1],sizeof(CE3D_Frustum));
	iLFrusts++;
  //## end CE3D_Renderer::PushLocalFrustum%1007327356.body
}

void CE3D_Renderer::ComputeLocalFrustum ()
{
  //## begin CE3D_Renderer::ComputeLocalFrustum%1006995108.body preserve=yes
	// Compute camera to local coordinate system matrixz
	CMatrix4x4		  M;
	GetCurrentMatrix(&M);
	M.RTInverse();

	// Compute the local frustum
	LocalFrustum[iLFrusts-1].Copy(Frustum);
	LocalFrustum[iLFrusts-1].Transform(M);
  //## end CE3D_Renderer::ComputeLocalFrustum%1006995108.body
}

void CE3D_Renderer::PopLocalFrustum ()
{
  //## begin CE3D_Renderer::PopLocalFrustum%1007327357.body preserve=yes
  if (iLFrusts>1) iLFrusts--;
  //## end CE3D_Renderer::PopLocalFrustum%1007327357.body
}

CE3D_Frustum& CE3D_Renderer::GetLocalFrustum ()
{
  //## begin CE3D_Renderer::GetLocalFrustum%1007327358.body preserve=yes
	return (LocalFrustum[iLFrusts-1]);
  //## end CE3D_Renderer::GetLocalFrustum%1007327358.body
}

void CE3D_Renderer::ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData)
{
  //## begin CE3D_Renderer::ReadBuffer%1018547532.body preserve=yes
  //## end CE3D_Renderer::ReadBuffer%1018547532.body
}

void CE3D_Renderer::WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData)
{
  //## begin CE3D_Renderer::WriteBuffer%1018547533.body preserve=yes
  //## end CE3D_Renderer::WriteBuffer%1018547533.body
}

void CE3D_Renderer::SetStencilPars (eE3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, eE3D_StencilAction _eSFails, eE3D_StencilAction _eZFails, eE3D_StencilAction _eZPass)
{
  //## begin CE3D_Renderer::SetStencilPars%1018547534.body preserve=yes
  //## end CE3D_Renderer::SetStencilPars%1018547534.body
}

void CE3D_Renderer::SetFogPars (eE3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, TFColor* _poColor)
{
  //## begin CE3D_Renderer::SetFogPars%1018547537.body preserve=yes
  //## end CE3D_Renderer::SetFogPars%1018547537.body
}

void CE3D_Renderer::SetZPars (eE3D_ZTestFunc _eZTest, eE3D_ZWrite _eZWrite)
{
  //## begin CE3D_Renderer::SetZPars%1018547538.body preserve=yes
  //## end CE3D_Renderer::SetZPars%1018547538.body
}

void CE3D_Renderer::MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA)
{
  //## begin CE3D_Renderer::MaskChannels%1018623771.body preserve=yes
  //## end CE3D_Renderer::MaskChannels%1018623771.body
}

void CE3D_Renderer::ClearBuffer (eE3D_RenderBuffer_Type _eBuffer)
{
  //## begin CE3D_Renderer::ClearBuffer%1018623774.body preserve=yes
  //## end CE3D_Renderer::ClearBuffer%1018623774.body
}

void CE3D_Renderer::SetupLight (int _iLightID, CE3D_Light& _roLight)
{
  //## begin CE3D_Renderer::SetupLight%1032001949.body preserve=yes
  //## end CE3D_Renderer::SetupLight%1032001949.body
}

void CE3D_Renderer::SetLight (int _iLightID, bool _bEnable)
{
  //## begin CE3D_Renderer::SetLight%1032019132.body preserve=yes
  //## end CE3D_Renderer::SetLight%1032019132.body
}

// Additional Declarations
  //## begin CE3D_Renderer%3A9AB88A01CC.declarations preserve=yes
  //## end CE3D_Renderer%3A9AB88A01CC.declarations

//## begin module%3A9AB88A01CC.epilog preserve=yes
//## end module%3A9AB88A01CC.epilog
