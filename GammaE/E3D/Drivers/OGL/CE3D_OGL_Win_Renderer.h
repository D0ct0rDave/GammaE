//## begin module%3A9AB8C503B6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AB8C503B6.cm

//## begin module%3A9AB8C503B6.cp preserve=no
//## end module%3A9AB8C503B6.cp

//## Module: CE3D_OGL_Win_Renderer%3A9AB8C503B6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Drivers\OGL\CE3D_OGL_Win_Renderer.h

#ifndef CE3D_OGL_Win_Renderer_h
#define CE3D_OGL_Win_Renderer_h 1

//## begin module%3A9AB8C503B6.additionalIncludes preserve=no
//## end module%3A9AB8C503B6.additionalIncludes

//## begin module%3A9AB8C503B6.includes preserve=yes
#ifdef _MBCS
	#include <windows.h>
	#include <wingdi.h>

	#define TPixelFormatDescriptor	PIXELFORMATDESCRIPTOR
	#define TLogPalette				LOGPALETTE
	#define TPaletteEntry			PALETTEENTRY
#else
	#ifdef __BORLANDC__
	#include <vcl.h>
	#endif
#endif
//## end module%3A9AB8C503B6.includes

// CE3D_OGL_Renderer
#include "E3D\Drivers\OGL\CE3D_OGL_Renderer.h"
// CE3D_ShIns_Color
#include "E3D\Shaders\ShaderInstructions\CE3D_ShIns_Color.h"
//## begin module%3A9AB8C503B6.additionalDeclarations preserve=yes
//## end module%3A9AB8C503B6.additionalDeclarations


//## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.preface preserve=yes
//## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.preface

//## Class: CE3D_OGL_Win_Renderer%3A9AB8C503B6
//## Category: E3D::Drivers::OGL%3A9EBF2A00BE
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C69A68A0120;CE3D_ShIns_Color { -> }

class CE3D_OGL_Win_Renderer : public CE3D_OGL_Renderer  //## Inherits: <unnamed>%3A9AB8FA01CC
{
  //## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.initialDeclarations preserve=yes
  //## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_OGL_Win_Renderer();

    //## Destructor (generated)
      ~CE3D_OGL_Win_Renderer();


    //## Other Operations (specified)
      //## Operation: RenderBBox%996790582
      void RenderBBox (CGraphBV* BVol);

      //## Operation: RenderNormals%1000845954
      void RenderNormals (CMesh* Mesh);

      //## Operation: BeginRender%1003953180
      virtual void BeginRender ();

      //## Operation: ClearCameraMatrix%1003953181
      virtual void ClearCameraMatrix ();

      //## Operation: ClearProjectorMatrix%1003953182
      virtual void ClearProjectorMatrix ();

      //## Operation: DisableBBoxRender%1003953183
      virtual void DisableBBoxRender ();

      //## Operation: DisableDefferredMode%1003953184
      virtual void DisableDefferredMode ();

      //## Operation: DisableFrustumCulling%1003953186
      virtual void DisableFrustumCulling ();

      //## Operation: DisableNormalRender%1003953188
      virtual void DisableNormalRender ();

      //## Operation: EnableBBoxRender%1003953190
      virtual void EnableBBoxRender ();

      //## Operation: EnableDefferredMode%1003953191
      virtual void EnableDefferredMode ();

      //## Operation: EnableFrustumCulling%1003953193
      virtual void EnableFrustumCulling ();

      //## Operation: EnableNormalRender%1003953195
      virtual void EnableNormalRender ();

      //## Operation: EndRender%1003953197
      virtual void EndRender ();

      //## Operation: Finish%1003953198
      virtual void Finish ();

      //## Operation: GetCameraMatrix%1003953200
      virtual void GetCameraMatrix (CMatrix4x4 *M);

      //## Operation: poGetCurrentMaterial%1003953201
      virtual CE3D_Shader * poGetCurrentMaterial ();

      //## Operation: GetCurrentMatrix%1003953202
      virtual void GetCurrentMatrix (CMatrix4x4 *M);

      //## Operation: GetProjectorMatrix%1003953204
      virtual void GetProjectorMatrix (CMatrix4x4 *M);

      //## Operation: Init%1003953206
      virtual int Init (void *_pHndDeviceContext, int _iOptions, int _iScrTX, int _iScrTY, int _iColorBits);

      //## Operation: LoadIdentity%1003953207
      virtual void LoadIdentity ();

      //## Operation: MultiplyMatrix%1003953208
      void MultiplyMatrix (CMatrix4x4 *Matrix);

      //## Operation: PopCameraMatrix%1003953209
      virtual void PopCameraMatrix ();

      //## Operation: PopMatrix%1003953210
      virtual void PopMatrix ();

      //## Operation: PopProjectorMatrix%1003953211
      virtual void PopProjectorMatrix ();

      //## Operation: PreMultiplyMatrix%1003953212
      void PreMultiplyMatrix (CMatrix4x4 *Matrix);

      //## Operation: PushCameraMatrix%1003953213
      virtual void PushCameraMatrix ();

      //## Operation: PushMatrix%1003953214
      virtual void PushMatrix ();

      //## Operation: PushProjectorMatrix%1003953215
      virtual void PushProjectorMatrix ();

      //## Operation: RenderDefferredObjects%1003953216
      virtual void RenderDefferredObjects ();

      //## Operation: RenderMesh%1003953217
      virtual void RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader);

      //## Operation: RenderMesh%1003953218
      virtual void RenderMesh (CMesh *_poMesh);

      //## Operation: RenderCompiledMesh%1011911187
      virtual void RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader);

      //## Operation: RenderCompiledMesh%1011911188
      virtual void RenderCompiledMesh (CCompiledMesh* _poCMesh);

      //## Operation: Rotate%1003953219
      virtual void Rotate (float Angle, float v0, float v1, float v2);

      //## Operation: RotateX%1003953220
      virtual void RotateX (float Angle);

      //## Operation: RotateY%1003953221
      virtual void RotateY (float Angle);

      //## Operation: RotateZ%1003953222
      virtual void RotateZ (float Angle);

      //## Operation: Scale%1003953223
      virtual void Scale (float x, float y, float z);

      //## Operation: ScaleX%1003953224
      virtual void ScaleX (float Value);

      //## Operation: ScaleY%1003953225
      virtual void ScaleY (float Value);

      //## Operation: ScaleZ%1003953226
      virtual void ScaleZ (float Value);

      //## Operation: SetCameraMatrix%1003953228
      virtual void SetCameraMatrix (CMatrix4x4 *M);

      //## Operation: SetCurrentMaterial%1003953229
      virtual void SetCurrentMaterial (CE3D_Shader *_poShader);

      //## Operation: SetCurrentMatrix%1003953230
      virtual void SetCurrentMatrix (CMatrix4x4 *M);

      //## Operation: SetCurrentTextureContext%1003953231
      virtual void SetCurrentTextureContext (TTextureObj *TexObj);

      //## Operation: SetProjectorMatrix%1003953234
      virtual void SetProjectorMatrix (CMatrix4x4 *M);

      //## Operation: Translate%1003953236
      virtual void Translate (float x, float y, float z);

      //## Operation: TranslateX%1003953237
      virtual void TranslateX (float Value);

      //## Operation: TranslateY%1003953238
      virtual void TranslateY (float Value);

      //## Operation: TranslateZ%1003953239
      virtual void TranslateZ (float Value);

      //## Operation: UpdateTexture%1003953240
      virtual void UpdateTexture (TTextureObj *TexObj);

      //## Operation: UploadTexture%1003953241
      virtual void UploadTexture (TTextureObj *TexObj);

      //## Operation: UsingBBoxRender%1003953242
      virtual bool UsingBBoxRender ();

      //## Operation: UsingDefferredMode%1003953243
      virtual bool UsingDefferredMode ();

      //## Operation: UsingFrustumCulling%1003953245
      virtual bool UsingFrustumCulling ();

      //## Operation: UsingNormalRender%1003953247
      virtual bool UsingNormalRender ();

      //## Operation: UpdateViewing%1003953258
      virtual void UpdateViewing ();

      //## Operation: SetViewport%1003953259
      virtual void SetViewport (CE3D_Viewport *_Viewport);

      //## Operation: GetViewport%1003953260
      virtual CE3D_Viewport * GetViewport ();

      //## Operation: SetCamera%1003953261
      virtual void SetCamera (CE3D_Camera *_Camera);

      //## Operation: GetCamera%1003953262
      virtual CE3D_Camera * GetCamera ();

      //## Operation: SetProjector%1003953263
      virtual void SetProjector (CE3D_Projector *_Projector);

      //## Operation: GetProjector%1003953264
      virtual CE3D_Projector * GetProjector ();

      //## Operation: SetScreenSize%1006393129
      virtual void SetScreenSize (int _iScrTX, int _iScrTY);

      //## Operation: poCompileMesh%1011911189
      virtual CCompiledMesh * poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader);

      //## Operation: DestroyCompiledMesh%1011911201
      virtual void DestroyCompiledMesh (CCompiledMesh *_poCMesh);

      //## Operation: SetupPalette%983399603
      void SetupPalette (TPixelFormatDescriptor PFD);

      //## Operation: EnableFlatRendering%1018547526
      virtual void EnableFlatRendering ();

      //## Operation: DisableFlatRendering%1018547527
      virtual void DisableFlatRendering ();

      //## Operation: UsingFlatRendering%1018547528
      virtual bool UsingFlatRendering ();

      //## Operation: ReadBuffer%1018547529
      virtual void ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData);

      //## Operation: WriteBuffer%1018547530
      virtual void WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData);

      //## Operation: SetStencilParams%1018547531
      virtual void SetStencilParams (bool _bEnable, eE3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, eE3D_StencilAction _eSFails, eE3D_StencilAction _eZFails, eE3D_StencilAction _eZPass);

      //## Operation: SetZPars%1018547536
      virtual void SetZPars (eE3D_ZTestFunc _eZTest, eE3D_ZWrite _eZWrite);

      //## Operation: MaskChannels%1018623772
      virtual void MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA);

      //## Operation: SetFogPars%1018623773
      virtual void SetFogPars (eE3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, TFColor* _poColor);

      //## Operation: ClearBuffer%1018623775
      virtual void ClearBuffer (eE3D_RenderBuffer_Type _eBuffer);

      //## Operation: SetupLight%1032001950
      virtual void SetupLight (int _iLightID, CE3D_Light& _roLight);

      //## Operation: SetLight%1032019131
      virtual void SetLight (int _iLightID, bool _bEnable);

    // Additional Public Declarations
      //## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.public preserve=yes
      //## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.public

  protected:
    // Additional Protected Declarations
      //## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.protected preserve=yes
		HWND	WND;
		HDC		DC;
		HGLRC	GLRC;
      //## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.protected
  private:
    // Additional Private Declarations
      //## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.private preserve=yes
      //## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.implementation preserve=yes
	  void PrepareLights();
      //## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.implementation
};

//## begin CE3D_OGL_Win_Renderer%3A9AB8C503B6.postscript preserve=yes
//## end CE3D_OGL_Win_Renderer%3A9AB8C503B6.postscript

// Class CE3D_OGL_Win_Renderer 

//## begin module%3A9AB8C503B6.epilog preserve=yes
//## end module%3A9AB8C503B6.epilog


#endif
