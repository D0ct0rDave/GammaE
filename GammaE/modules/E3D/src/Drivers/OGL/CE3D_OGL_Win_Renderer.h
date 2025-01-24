//-----------------------------------------------------------------------------
#ifndef CE3D_OGL_Win_Renderer_h
#define CE3D_OGL_Win_Renderer_h 1
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Driver specific options
//-----------------------------------------------------------------------------
#define E3D_RENDERER_OP_GDI 	0x00000100

#ifdef _MBCS
	#include <windows.h>
	#include <wingdi.h>

	#define TPixelFormatDescriptor	PIXELFORMATDESCRIPTOR
	#define TLogPalette				LOGPALETTE
	#define TPaletteEntry			PALETTEENTRY
#else
	#ifdef __BORLANDC__


    #include <vcl.h>

    #include <windows.h>
	#define TPixelFormatDescriptor	PIXELFORMATDESCRIPTOR
	#define TLogPalette				LOGPALETTE
	#define TPaletteEntry			PALETTEENTRY
        
	#endif
#endif

// CE3D_OGL_Renderer
#include "Drivers\OGL\CE3D_OGL_Renderer.h"
// CE3D_ShIns_Color
#include "Shaders\ShaderInstructions\CE3D_ShIns_Color.h"

#include "GammaE_Misc.h"
//-----------------------------------------------------------------------------
class CE3D_OGL_Win_Renderer : public CE3D_OGL_Renderer  {
    
  public:
          CE3D_OGL_Win_Renderer();

          ~CE3D_OGL_Win_Renderer();


			virtual void UploadProgram(CGProgram* _poProgram);

			virtual void UpdateProgram(CGProgram* _poProgram);

			virtual void SetCurrentProgram(CGProgram* _poProgram);

			virtual void InvalidateProgram(CGProgram* _poProgram);

			virtual void SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void*_pValue);
			

            void RenderBBox (CGraphBV* BVol);

            void RenderNormals (CMesh* Mesh);

            virtual void BeginRender ();

            virtual void DisableBBoxRender ();

            virtual void DisableDefferredMode ();

            virtual void DisableFrustumCulling ();

            virtual void DisableNormalRender ();

            virtual void EnableBBoxRender ();

            virtual void EnableDefferredMode ();

            virtual void EnableFrustumCulling ();

            virtual void EnableNormalRender ();

            virtual void EndRender ();

            virtual void Finish ();

            virtual CE3D_Shader * poGetCurrentMaterial ();

            virtual int Init (handler _pHndDeviceContext, int _iOptions, int _iScrTX, int _iScrTY, int _iColorBits);

            virtual void RenderDefferredObjects ();

            virtual void RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader);

            virtual void RenderMesh (CMesh *_poMesh);

            virtual void RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader);

            virtual void RenderCompiledMesh (CCompiledMesh* _poCMesh);
			// ------------------------------------------------------
            void MultiplyMatrix (CMatrix4x4 *Matrix);

            void PreMultiplyMatrix (CMatrix4x4 *Matrix);
			// ------------------------------------------------------

            virtual void ClearCameraMatrix ();

            virtual void PushCameraMatrix();
            
            virtual void PopCameraMatrix ();

            virtual void SetCameraMatrix (CMatrix4x4 *M);

            virtual void GetCameraMatrix (CMatrix4x4 *M);



            virtual void ClearWorldMatrix();

            virtual void PushWorldMatrix();

            virtual void PopWorldMatrix();
            
            virtual void SetWorldMatrix (CMatrix4x4 *M);
            
            virtual void GetWorldMatrix (CMatrix4x4 *M);



            virtual void ClearProjectorMatrix ();

            virtual void PushProjectorMatrix ();           

            virtual void PopProjectorMatrix();
            
            virtual void SetProjectorMatrix (CMatrix4x4 *M);

            virtual void GetProjectorMatrix (CMatrix4x4 *M);
			
			// ------------------------------------------------------
			
            virtual void SetCurrentMaterial (CE3D_Shader *_poShader);

            virtual void SetCurrentTextureContext (CGTextureObj *TexObj);

            virtual void UpdateTexture (CGTextureObj *TexObj);

            virtual void UploadTexture (CGTextureObj *TexObj);

            virtual bool UsingBBoxRender ();

            virtual bool UsingDefferredMode ();

            virtual bool UsingFrustumCulling ();

            virtual bool UsingNormalRender ();

            virtual void UpdateViewing ();

            virtual void SetViewport (CE3D_Viewport *_Viewport);

            virtual CE3D_Viewport * GetViewport ();

            virtual void SetCamera (CE3D_Camera *_Camera);

            virtual CE3D_Camera * GetCamera ();

            virtual void SetProjector (CE3D_Projector *_Projector);

            virtual CE3D_Projector * GetProjector ();

            virtual void SetScreenSize (int _iScrTX, int _iScrTY);

            virtual CCompiledMesh * poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader);

            virtual void DestroyCompiledMesh (CCompiledMesh *_poCMesh);

            void SetupPalette (TPixelFormatDescriptor PFD);

            virtual void EnableFlatRendering ();

            virtual void DisableFlatRendering ();

            virtual bool UsingFlatRendering ();

            virtual void ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);

            virtual void WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);

            virtual void SetStencilParams (bool _bEnable, E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass);

            virtual void SetZPars (E3D_ZTestFunc _eZTest,E3D_ZWrite _eZWrite);

            virtual void MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA);

            virtual void SetFogPars (E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor);

            virtual void ClearBuffer (E3D_RenderBuffer_Type _eBuffer);

            virtual void SetupLight (int _iLightID, CE3D_Light& _oLight);

            virtual void SetLight (int _iLightID, bool _bEnable);

            virtual void InvalidateTexture (CGTextureObj *TexObj);

			virtual void SetConstantColor(const CGColor& _oColor);

    // Additional Public Declarations
            
  protected:

		void RenderMesh_Int(void *_poMesh, CE3D_Shader *_poShader,E3D_MeshType _eMeshType);
	
    // Additional Protected Declarations
   		HWND	WND;
		HDC		DC;
		HGLRC	GLRC;
		CGChrono m_oChrono;		
        private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
      	  void PrepareLights();
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
