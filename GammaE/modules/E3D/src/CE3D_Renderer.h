// -----------------------------------------------------------------------------
#ifndef CE3D_Renderer_h
#define CE3D_Renderer_h 1
// -----------------------------------------------------------------------------
#include "Light/CE3D_Light.h"
#include "E3D_Enums.h"
/*
#include "E3D_ZWrite.h"
#include "E3D_ZTestFunc.h"
#include "E3D_FogMode.h"
#include "E3D_StencilFunc.h"
#include "E3D_StencilAction.h"
#include "E3D_RenderBuffer_Type.h"
*/
#include "CE3D_RenderState.h"
#include "CE3D_RenderStats.h"
#include "Mesh\CMesh.h"
#include "Viewing\Frustum\CE3D_Frustum.h"
#include "Viewing\Camera\CE3D_Camera.h"
#include "Viewing\Viewport\CE3D_Viewport.h"
#include "CompiledMesh\CCompiledMesh.h"
#include "Viewing\Projector\CE3D_Projector.h"
#include "MeshDB\CDefferredMeshDB.h"
#include "Shaders\CE3D_Shader.h"
#include "Materials/CGTexObj.h"
#include "Materials/CGColor.h"
#include "Materials/CGProgram.h"

//-----------------------------------------------------------------------------
#define E3D_RENDERER_OP_DBUFFER 0x00000001
#define E3D_RENDERER_OP_STEREO  0x00000004
//-----------------------------------------------------------------------------

class CE3D_Renderer 
{
	public:

		CE3D_Renderer();


		virtual ~CE3D_Renderer();


		virtual int Init (handler HndDeviceContext, int Options, int ScrTX, int ScrTY, int ColorBits);


		virtual void Finish ();

		

		virtual void UploadProgram(CGProgram* _poProgram);

		virtual void UpdateProgram(CGProgram* _poProgram);

		virtual void SetCurrentProgram(CGProgram* _poProgram);

		virtual void InvalidateProgram(CGProgram* _poProgram);
		
		virtual void SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void*_pValue);
		
		
		virtual void UploadTexture (CGTextureObj *TexObj);

		virtual void UpdateTexture (CGTextureObj *TexObj);

		virtual void SetCurrentTextureContext (CGTextureObj *TexObj);

		virtual void InvalidateTexture (CGTextureObj *TexObj);



		virtual void BeginRender ();


		virtual void EndRender ();


		virtual void RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader);


		virtual void RenderMesh (CMesh *_poMesh);


		virtual void RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader* _poShader);


		virtual void RenderCompiledMesh (CCompiledMesh* _poCMesh);


		virtual CCompiledMesh * poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader);


		virtual void DestroyCompiledMesh (CCompiledMesh *_poCMesh);


		virtual void RenderDefferredObjects ();


		virtual void EnableBBoxRender ();


		virtual void DisableBBoxRender ();


		virtual bool UsingBBoxRender ();


		virtual void EnableDefferredMode ();


		virtual void DisableDefferredMode ();


		virtual bool UsingDefferredMode ();


		virtual void EnableFrustumCulling ();


		virtual void DisableFrustumCulling ();


		virtual bool UsingFrustumCulling ();


		virtual void EnableNormalRender ();


		virtual void DisableNormalRender ();


		virtual bool UsingNormalRender ();


		virtual void EnableFlatRendering ();


		virtual void DisableFlatRendering ();


		virtual bool UsingFlatRendering ();


		virtual void PushWorldMatrix ();


		virtual void PopWorldMatrix ();


		virtual void ClearWorldMatrix ();


		virtual void MultiplyMatrix (CMatrix4x4 *Matrix);


		virtual void PreMultiplyMatrix (CMatrix4x4 *Matrix);


		virtual void GetWorldMatrix (CMatrix4x4 *M);


		virtual void SetWorldMatrix (CMatrix4x4 *M);


		virtual void SetCurrentMaterial (CE3D_Shader *_poShader) = 0;


		virtual CE3D_Shader* poGetCurrentMaterial ();


		virtual void PushCameraMatrix ();


		virtual void PopCameraMatrix ();


		virtual void ClearCameraMatrix ();


		virtual void GetCameraMatrix (CMatrix4x4 *M);


		virtual void SetCameraMatrix (CMatrix4x4 *M);


		virtual void PushProjectorMatrix ();


		virtual void PopProjectorMatrix ();


		virtual void ClearProjectorMatrix ();


		virtual void GetProjectorMatrix (CMatrix4x4 *M);


		virtual void SetProjectorMatrix (CMatrix4x4 *M);


		virtual void UpdateViewing ();


		virtual void SetViewport (CE3D_Viewport *_Viewport);


		virtual CE3D_Viewport * GetViewport ();


		virtual void SetCamera (CE3D_Camera *_Camera);


		virtual CE3D_Camera * GetCamera ();


		virtual void SetProjector (CE3D_Projector *_Projector);


		virtual CE3D_Projector * GetProjector ();


		virtual float fGetAspectRatio ();


		virtual void SetScreenSize (int _iScrTX, int _iScrTY) = 0;


		int iGetScrTX ();


		int iGetScrTY ();


		void PushLocalFrustum ();


		void ComputeLocalFrustum ();


		void PopLocalFrustum ();


		CE3D_Frustum& GetLocalFrustum ();


		virtual void ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);


		virtual void WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);


		virtual void SetStencilPars (E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass);


		virtual void SetFogPars (E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor);


		virtual void SetZPars (E3D_ZTestFunc _eZTest, E3D_ZWrite _eZWrite);
		
		
		virtual void SetConstantColor(const CGColor& _oColor);

		
		virtual const CGColor& oGetConstantColor(const CGColor& _oColor);


		virtual void MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA);


		virtual void ClearBuffer (E3D_RenderBuffer_Type _eBuffer);


		virtual void SetupLight (int _iLightID, CE3D_Light& _oLight);


		virtual void SetLight (int _iLightID, bool _bEnable);


		CE3D_Frustum& GetFrustum ();


	public:


		//-----------------------------------------------------------------------------

		CE3D_RenderStats REStats;


		CE3D_RenderState REState;
	
	protected:
	
		CGColor		m_oColor;

		CE3D_Frustum Frustum;


		CE3D_Frustum *LocalFrustum;


		CDefferredMeshDB oDefObjWH;


		CE3D_Shader *poCurrentShader;


		CE3D_Shader E3D_NULL_SHADER;


		float fAspectRatio;


		int iScrTX;


		int iScrTY;


		int iLFrusts;


		E3D_StencilFunc eStencilFunc;


		E3D_StencilFunc eStencilFuncLast;


		E3D_FogMode eFogMode;


		E3D_FogMode eFogModeLast;


		E3D_ZWrite eZWrite;


		E3D_ZWrite eZWriteLast;


		E3D_ZTestFunc eZTest;


		E3D_ZTestFunc eZTestLast;


		CE3D_Projector *Projector;


		CE3D_Camera *Camera;


		CE3D_Viewport *Viewport;
};
//-----------------------------------------------------------------------------
inline float CE3D_Renderer::fGetAspectRatio ()
{ 
	return (fAspectRatio); 
}
//-----------------------------------------------------------------------------
inline int CE3D_Renderer::iGetScrTX ()
{
	return(iScrTX);
}
//-----------------------------------------------------------------------------
inline int CE3D_Renderer::iGetScrTY ()
{
	return(iScrTY); 
}
//-----------------------------------------------------------------------------
inline CE3D_Frustum& CE3D_Renderer::GetFrustum ()
{  
  return Frustum; 
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
