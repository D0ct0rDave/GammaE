//## begin module%3A9AB88A01CC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AB88A01CC.cm

//## begin module%3A9AB88A01CC.cp preserve=no
//## end module%3A9AB88A01CC.cp

//## Module: CE3D_Renderer%3A9AB88A01CC; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\CE3D_Renderer.h

#ifndef CE3D_Renderer_h
#define CE3D_Renderer_h 1

//## begin module%3A9AB88A01CC.additionalIncludes preserve=no
//## end module%3A9AB88A01CC.additionalIncludes

//## begin module%3A9AB88A01CC.includes preserve=yes
#include "Light/CE3D_Light.h"
//## end module%3A9AB88A01CC.includes

// eE3D_FogMode
#include "E3D\eE3D_FogMode.h"
// eE3D_StencilFunc
#include "E3D\eE3D_StencilFunc.h"
// eE3D_StencilAction
#include "E3D\eE3D_StencilAction.h"
// eE3D_RenderBuffer_Type
#include "E3D\eE3D_RenderBuffer_Type.h"
// CE3D_RenderState
#include "E3D\CE3D_RenderState.h"
// CE3D_RenderStats
#include "E3D\CE3D_RenderStats.h"
// eE3D_ZWrite
#include "E3D\eE3D_ZWrite.h"
// eE3D_ZTestFunc
#include "E3D\eE3D_ZTestFunc.h"
// CMesh
#include "E3D\Mesh\CMesh.h"
// CE3D_Camera
#include "E3D\Viewing\Camera\CE3D_Camera.h"
// CE3D_Viewport
#include "E3D\Viewing\Viewport\CE3D_Viewport.h"
// CE3D_Projector
#include "E3D\Viewing\Projector\CE3D_Projector.h"
// CE3D_Frustum
#include "E3D\Viewing\Frustum\CE3D_Frustum.h"
// CDefferredMeshDB
#include "E3D\MeshDB\CDefferredMeshDB.h"
// CCompiledMesh
#include "E3D\CompiledMesh\CCompiledMesh.h"
// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
//## begin module%3A9AB88A01CC.additionalDeclarations preserve=yes

//---------------------------------------------------------------------------
#define E3D_RENDERER_OP_DBUFFER 0x00000001
#define E3D_RENDERER_OP_STEREO  0x00000004
//---------------------------------------------------------------------------


#include "E3D/Materials/TexObj.h"
#include "E3D/Materials/ColorObj.h"
//## end module%3A9AB88A01CC.additionalDeclarations


//## begin CE3D_Renderer%3A9AB88A01CC.preface preserve=yes
//## end CE3D_Renderer%3A9AB88A01CC.preface

//## Class: CE3D_Renderer%3A9AB88A01CC
//## Category: E3D%3A9AB83902D0
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3A9D866B03A2;TRenderingContext { -> }
//## Uses: <unnamed>%3C69995701CB;CE3D_Shader { -> }
//## Uses: <unnamed>%3C6AD50502F2;CMesh { -> }
//## Uses: <unnamed>%3C6AD5090276;CCompiledMesh { -> }
//## Uses: <unnamed>%3CB5FDBE034E;eE3D_RenderBuffer_Type { -> }
//## Uses: <unnamed>%3CB60095012C;eE3D_StencilAction { -> }
//## Uses: <unnamed>%3CB601CF01A6;eE3D_StencilFunc { -> }
//## Uses: <unnamed>%3CB60C810207;eE3D_ZWrite { -> }
//## Uses: <unnamed>%3CB60C8D02CD;eE3D_ZTestFunc { -> }
//## Uses: <unnamed>%3CB60C9203C4;eE3D_FogMode { -> }

class CE3D_Renderer 
{
  //## begin CE3D_Renderer%3A9AB88A01CC.initialDeclarations preserve=yes
  //## end CE3D_Renderer%3A9AB88A01CC.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_Renderer();

    //## Destructor (generated)
      virtual ~CE3D_Renderer();


    //## Other Operations (specified)
      //## Operation: Init%1003953158
      virtual int Init (void *HndDeviceContext, int Options, int ScrTX, int ScrTY, int ColorBits);

      //## Operation: Finish%983399604
      virtual void Finish ();

      //## Operation: UploadTexture%983314250
      virtual void UploadTexture (TTextureObj *TexObj);

      //## Operation: UpdateTexture%983314251
      virtual void UpdateTexture (TTextureObj *TexObj);

      //## Operation: BeginRender%983314252
      virtual void BeginRender ();

      //## Operation: EndRender%983314253
      virtual void EndRender ();

      //## Operation: RenderMesh%983314256
      virtual void RenderMesh (CMesh *_poMesh, CE3D_Shader *_poShader);

      //## Operation: RenderMesh%983314257
      virtual void RenderMesh (CMesh *_poMesh);

      //## Operation: RenderCompiledMesh%1011911184
      virtual void RenderCompiledMesh (CCompiledMesh *_poCMesh, CE3D_Shader* _poShader);

      //## Operation: RenderCompiledMesh%1011911185
      virtual void RenderCompiledMesh (CCompiledMesh* _poCMesh);

      //## Operation: poCompileMesh%1011911186
      virtual CCompiledMesh * poCompileMesh (CMesh *_poMesh, CE3D_Shader *_poShader);

      //## Operation: DestroyCompiledMesh%1011911200
      virtual void DestroyCompiledMesh (CCompiledMesh *_poCMesh);

      //## Operation: RenderDefferredObjects%983314258
      virtual void RenderDefferredObjects ();

      //## Operation: EnableBBoxRender%983314262
      virtual void EnableBBoxRender ();

      //## Operation: DisableBBoxRender%983314263
      virtual void DisableBBoxRender ();

      //## Operation: UsingBBoxRender%983314264
      virtual bool UsingBBoxRender ();

      //## Operation: SetCurrentTextureContext%983314265
      virtual void SetCurrentTextureContext (TTextureObj *TexObj);

      //## Operation: EnableDefferredMode%983314266
      virtual void EnableDefferredMode ();

      //## Operation: DisableDefferredMode%983314267
      virtual void DisableDefferredMode ();

      //## Operation: UsingDefferredMode%983314268
      virtual bool UsingDefferredMode ();

      //## Operation: EnableFrustumCulling%983314269
      virtual void EnableFrustumCulling ();

      //## Operation: DisableFrustumCulling%983314270
      virtual void DisableFrustumCulling ();

      //## Operation: UsingFrustumCulling%983314271
      virtual bool UsingFrustumCulling ();

      //## Operation: EnableNormalRender%1003953163
      virtual void EnableNormalRender ();

      //## Operation: DisableNormalRender%1003953164
      virtual void DisableNormalRender ();

      //## Operation: UsingNormalRender%1003953165
      virtual bool UsingNormalRender ();

      //## Operation: EnableFlatRendering%1018547523
      virtual void EnableFlatRendering ();

      //## Operation: DisableFlatRendering%1018547524
      virtual void DisableFlatRendering ();

      //## Operation: UsingFlatRendering%1018547525
      virtual bool UsingFlatRendering ();

      //## Operation: Translate%983314275
      virtual void Translate (float x, float y, float z);

      //## Operation: TranslateX%983314276
      virtual void TranslateX (float Value);

      //## Operation: TranslateY%983314277
      virtual void TranslateY (float Value);

      //## Operation: TranslateZ%983314278
      virtual void TranslateZ (float Value);

      //## Operation: Scale%983314279
      virtual void Scale (float x, float y, float z);

      //## Operation: ScaleX%983314280
      virtual void ScaleX (float Value);

      //## Operation: ScaleY%983314281
      virtual void ScaleY (float Value);

      //## Operation: ScaleZ%983314282
      virtual void ScaleZ (float Value);

      //## Operation: Rotate%983314283
      virtual void Rotate (float Angle, float v0, float v1, float v2);

      //## Operation: RotateX%983314284
      virtual void RotateX (float Angle);

      //## Operation: RotateY%983314285
      virtual void RotateY (float Angle);

      //## Operation: RotateZ%983314286
      virtual void RotateZ (float Angle);

      //## Operation: PushMatrix%983314287
      virtual void PushMatrix ();

      //## Operation: PopMatrix%983314288
      virtual void PopMatrix ();

      //## Operation: LoadIdentity%983314289
      virtual void LoadIdentity ();

      //## Operation: MultiplyMatrix%985636791
      virtual void MultiplyMatrix (CMatrix4x4 *Matrix);

      //## Operation: PreMultiplyMatrix%985636792
      virtual void PreMultiplyMatrix (CMatrix4x4 *Matrix);

      //## Operation: GetCurrentMatrix%983314290
      virtual void GetCurrentMatrix (CMatrix4x4 *M);

      //## Operation: SetCurrentMatrix%983314291
      virtual void SetCurrentMatrix (CMatrix4x4 *M);

      //## Operation: SetCurrentMaterial%985636793
      virtual void SetCurrentMaterial (CE3D_Shader *_poShader) = 0;

      //## Operation: poGetCurrentMaterial%985636794
      virtual CE3D_Shader* poGetCurrentMaterial ();

      //## Operation: PushCameraMatrix%1003953174
      virtual void PushCameraMatrix ();

      //## Operation: PopCameraMatrix%1003953175
      virtual void PopCameraMatrix ();

      //## Operation: ClearCameraMatrix%1003953176
      virtual void ClearCameraMatrix ();

      //## Operation: GetCameraMatrix%1003953166
      virtual void GetCameraMatrix (CMatrix4x4 *M);

      //## Operation: SetCameraMatrix%1003953167
      virtual void SetCameraMatrix (CMatrix4x4 *M);

      //## Operation: PushProjectorMatrix%1003953177
      virtual void PushProjectorMatrix ();

      //## Operation: PopProjectorMatrix%1003953178
      virtual void PopProjectorMatrix ();

      //## Operation: ClearProjectorMatrix%1003953179
      virtual void ClearProjectorMatrix ();

      //## Operation: GetProjectorMatrix%1003953168
      virtual void GetProjectorMatrix (CMatrix4x4 *M);

      //## Operation: SetProjectorMatrix%1003953169
      virtual void SetProjectorMatrix (CMatrix4x4 *M);

      //## Operation: UpdateViewing%1003953265
      virtual void UpdateViewing ();

      //## Operation: SetViewport%1003953267
      virtual void SetViewport (CE3D_Viewport *_Viewport);

      //## Operation: GetViewport%1003953268
      virtual CE3D_Viewport * GetViewport ();

      //## Operation: SetCamera%1003953269
      virtual void SetCamera (CE3D_Camera *_Camera);

      //## Operation: GetCamera%1003953270
      virtual CE3D_Camera * GetCamera ();

      //## Operation: SetProjector%1003953271
      virtual void SetProjector (CE3D_Projector *_Projector);

      //## Operation: GetProjector%1003953272
      virtual CE3D_Projector * GetProjector ();

      //## Operation: fGetAspectRatio%1004042076
      virtual float fGetAspectRatio ();

      //## Operation: SetScreenSize%1006393128
      virtual void SetScreenSize (int _iScrTX, int _iScrTY) = 0;

      //## Operation: iGetScrTX%1018910303
      int iGetScrTX ();

      //## Operation: iGetScrTY%1018910304
      int iGetScrTY ();

      //## Operation: PushLocalFrustum%1007327356
      void PushLocalFrustum ();

      //## Operation: ComputeLocalFrustum%1006995108
      void ComputeLocalFrustum ();

      //## Operation: PopLocalFrustum%1007327357
      void PopLocalFrustum ();

      //## Operation: GetLocalFrustum%1007327358
      CE3D_Frustum& GetLocalFrustum ();

      //## Operation: ReadBuffer%1018547532
      virtual void ReadBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData);

      //## Operation: WriteBuffer%1018547533
      virtual void WriteBuffer (int _iX, int _iY, int _iTX, int _iTY, eE3D_RenderBuffer_Type _eBufferType, void* _pData);

      //## Operation: SetStencilPars%1018547534
      virtual void SetStencilPars (eE3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, eE3D_StencilAction _eSFails, eE3D_StencilAction _eZFails, eE3D_StencilAction _eZPass);

      //## Operation: SetFogPars%1018547537
      virtual void SetFogPars (eE3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, TFColor* _poColor);

      //## Operation: SetZPars%1018547538
      virtual void SetZPars (eE3D_ZTestFunc _eZTest, eE3D_ZWrite _eZWrite);

      //## Operation: MaskChannels%1018623771
      virtual void MaskChannels (bool _bR, bool _bG, bool _bB, bool _bA);

      //## Operation: ClearBuffer%1018623774
      virtual void ClearBuffer (eE3D_RenderBuffer_Type _eBuffer);

      //## Operation: SetupLight%1032001949
      virtual void SetupLight (int _iLightID, CE3D_Light& _roLight);

      //## Operation: SetLight%1032019132
      virtual void SetLight (int _iLightID, bool _bEnable);

    //## Get and Set Operations for Associations (generated)

      //## Association: E3D::<unnamed>%3BD736E703CE
      //## Role: CE3D_Renderer::Frustum%3BD736E800A4
      CE3D_Frustum& GetFrustum ();

    // Data Members for Associations

      //## Association: E3D::<unnamed>%3BD71CBC035D
      //## Role: CE3D_Renderer::REStats%3BD71CBD0065
      //## begin CE3D_Renderer::REStats%3BD71CBD0065.role preserve=no  public: CE3D_RenderStats { -> VHAN}
      CE3D_RenderStats REStats;
      //## end CE3D_Renderer::REStats%3BD71CBD0065.role

      //## Association: E3D::<unnamed>%3BD71E290203
      //## Role: CE3D_Renderer::REState%3BD71E29033A
      //## begin CE3D_Renderer::REState%3BD71E29033A.role preserve=no  public: CE3D_RenderState { -> UHAN}
      CE3D_RenderState REState;
      //## end CE3D_Renderer::REState%3BD71E29033A.role

      //## Association: E3D::<unnamed>%3BD736E703CE
      //## begin CE3D_Renderer::Frustum%3BD736E800A4.role preserve=no  public: CE3D_Frustum { -> VHAN}
      CE3D_Frustum Frustum;
      //## end CE3D_Renderer::Frustum%3BD736E800A4.role

      //## Association: E3D::<unnamed>%3C058D2A0335
      //## Role: CE3D_Renderer::LocalFrustum%3C058D2C0017
      //## begin CE3D_Renderer::LocalFrustum%3C058D2C0017.role preserve=no  public: CE3D_Frustum { -> RHAN}
      CE3D_Frustum *LocalFrustum;
      //## end CE3D_Renderer::LocalFrustum%3C058D2C0017.role

      //## Association: E3D::<unnamed>%3C509E050229
      //## Role: CE3D_Renderer::oDefObjWH%3C509E0503A5
      //## begin CE3D_Renderer::oDefObjWH%3C509E0503A5.role preserve=no  public: CDefferredMeshDB { -> VHAN}
      CDefferredMeshDB oDefObjWH;
      //## end CE3D_Renderer::oDefObjWH%3C509E0503A5.role

    // Additional Public Declarations
      //## begin CE3D_Renderer%3A9AB88A01CC.public preserve=yes
      //## end CE3D_Renderer%3A9AB88A01CC.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: poCurrentShader%3BD71D06029B
      //## begin CE3D_Renderer::poCurrentShader%3BD71D06029B.attr preserve=no  protected: CE3D_Shader * {UA} NULL
      CE3D_Shader *poCurrentShader;
      //## end CE3D_Renderer::poCurrentShader%3BD71D06029B.attr

      //## Attribute: E3D_NULL_SHADER%3BD71D180369
      //## begin CE3D_Renderer::E3D_NULL_SHADER%3BD71D180369.attr preserve=no  protected: CE3D_Shader {UA} 
      CE3D_Shader E3D_NULL_SHADER;
      //## end CE3D_Renderer::E3D_NULL_SHADER%3BD71D180369.attr

      //## Attribute: fAspectRatio%3BD8777402A2
      //## begin CE3D_Renderer::fAspectRatio%3BD8777402A2.attr preserve=no  protected: float {UA} 1.0f
      float fAspectRatio;
      //## end CE3D_Renderer::fAspectRatio%3BD8777402A2.attr

      //## Attribute: iScrTX%3BD878AD0343
      //## begin CE3D_Renderer::iScrTX%3BD878AD0343.attr preserve=no  protected: int {UA} 0
      int iScrTX;
      //## end CE3D_Renderer::iScrTX%3BD878AD0343.attr

      //## Attribute: iScrTY%3BD878B102EE
      //## begin CE3D_Renderer::iScrTY%3BD878B102EE.attr preserve=no  protected: int {UA} 0
      int iScrTY;
      //## end CE3D_Renderer::iScrTY%3BD878B102EE.attr

      //## Attribute: iLFrusts%3C0AB88B03DC
      //## begin CE3D_Renderer::iLFrusts%3C0AB88B03DC.attr preserve=no  protected: int {UA} 1
      int iLFrusts;
      //## end CE3D_Renderer::iLFrusts%3C0AB88B03DC.attr

      //## Attribute: eStencilFunc%3CB606890322
      //## begin CE3D_Renderer::eStencilFunc%3CB606890322.attr preserve=no  protected: eE3D_StencilFunc {UA} eE3D_SF_None
      eE3D_StencilFunc eStencilFunc;
      //## end CE3D_Renderer::eStencilFunc%3CB606890322.attr

      //## Attribute: eStencilFuncLast%3CB6103E002D
      //## begin CE3D_Renderer::eStencilFuncLast%3CB6103E002D.attr preserve=no  protected: eE3D_StencilFunc {UA} eE3D_SF_None
      eE3D_StencilFunc eStencilFuncLast;
      //## end CE3D_Renderer::eStencilFuncLast%3CB6103E002D.attr

      //## Attribute: eFogMode%3CB60D2003DC
      //## begin CE3D_Renderer::eFogMode%3CB60D2003DC.attr preserve=no  protected: eE3D_FogMode {UA} eE3D_FM_None
      eE3D_FogMode eFogMode;
      //## end CE3D_Renderer::eFogMode%3CB60D2003DC.attr

      //## Attribute: eFogModeLast%3CB6101F033F
      //## begin CE3D_Renderer::eFogModeLast%3CB6101F033F.attr preserve=no  protected: eE3D_FogMode {UA} eE3D_FM_None
      eE3D_FogMode eFogModeLast;
      //## end CE3D_Renderer::eFogModeLast%3CB6101F033F.attr

      //## Attribute: eZWrite%3CB60D340024
      //## begin CE3D_Renderer::eZWrite%3CB60D340024.attr preserve=no  protected: eE3D_ZWrite {UA} eE3D_ZW_Enable
      eE3D_ZWrite eZWrite;
      //## end CE3D_Renderer::eZWrite%3CB60D340024.attr

      //## Attribute: eZWriteLast%3CB6102802A2
      //## begin CE3D_Renderer::eZWriteLast%3CB6102802A2.attr preserve=no  protected: eE3D_ZWrite {UA} eE3D_ZW_Enable
      eE3D_ZWrite eZWriteLast;
      //## end CE3D_Renderer::eZWriteLast%3CB6102802A2.attr

      //## Attribute: eZTest%3CB60D550085
      //## begin CE3D_Renderer::eZTest%3CB60D550085.attr preserve=no  protected: eE3D_ZTestFunc {UA} eE3D_ZTF_LEqual
      eE3D_ZTestFunc eZTest;
      //## end CE3D_Renderer::eZTest%3CB60D550085.attr

      //## Attribute: eZTestLast%3CB610330258
      //## begin CE3D_Renderer::eZTestLast%3CB610330258.attr preserve=no  protected: eE3D_ZTestFunc {UA} eE3D_ZTF_LEqual
      eE3D_ZTestFunc eZTestLast;
      //## end CE3D_Renderer::eZTestLast%3CB610330258.attr

    // Data Members for Associations

      //## Association: E3D::<unnamed>%3BD71F2A036C
      //## Role: CE3D_Renderer::Projector%3BD71F2B0024
      //## begin CE3D_Renderer::Projector%3BD71F2B0024.role preserve=no  protected: CE3D_Projector { -> RHAN}
      CE3D_Projector *Projector;
      //## end CE3D_Renderer::Projector%3BD71F2B0024.role

      //## Association: E3D::<unnamed>%3BD71F580123
      //## Role: CE3D_Renderer::Camera%3BD71F580227
      //## begin CE3D_Renderer::Camera%3BD71F580227.role preserve=no  protected: CE3D_Camera { -> RHAN}
      CE3D_Camera *Camera;
      //## end CE3D_Renderer::Camera%3BD71F580227.role

      //## Association: E3D::<unnamed>%3BD71FA90210
      //## Role: CE3D_Renderer::Viewport%3BD71FA90314
      //## begin CE3D_Renderer::Viewport%3BD71FA90314.role preserve=no  protected: CE3D_Viewport { -> RHAN}
      CE3D_Viewport *Viewport;
      //## end CE3D_Renderer::Viewport%3BD71FA90314.role

    // Additional Protected Declarations
      //## begin CE3D_Renderer%3A9AB88A01CC.protected preserve=yes
      //## end CE3D_Renderer%3A9AB88A01CC.protected

  private:
    // Additional Private Declarations
      //## begin CE3D_Renderer%3A9AB88A01CC.private preserve=yes
      //## end CE3D_Renderer%3A9AB88A01CC.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_Renderer%3A9AB88A01CC.implementation preserve=yes
      //## end CE3D_Renderer%3A9AB88A01CC.implementation

};

//## begin CE3D_Renderer%3A9AB88A01CC.postscript preserve=yes
//## end CE3D_Renderer%3A9AB88A01CC.postscript

// Class CE3D_Renderer 


//## Other Operations (inline)
inline float CE3D_Renderer::fGetAspectRatio ()
{
  //## begin CE3D_Renderer::fGetAspectRatio%1004042076.body preserve=yes
	return (fAspectRatio);
  //## end CE3D_Renderer::fGetAspectRatio%1004042076.body
}

inline int CE3D_Renderer::iGetScrTX ()
{
  //## begin CE3D_Renderer::iGetScrTX%1018910303.body preserve=yes
	return(iScrTX);
  //## end CE3D_Renderer::iGetScrTX%1018910303.body
}

inline int CE3D_Renderer::iGetScrTY ()
{
  //## begin CE3D_Renderer::iGetScrTY%1018910304.body preserve=yes
	return(iScrTY);
  //## end CE3D_Renderer::iGetScrTY%1018910304.body
}

//## Get and Set Operations for Associations (inline)

inline CE3D_Frustum& CE3D_Renderer::GetFrustum ()
{
  //## begin CE3D_Renderer::GetFrustum%3BD736E800A4.get preserve=no
  return Frustum;
  //## end CE3D_Renderer::GetFrustum%3BD736E800A4.get
}

//## begin module%3A9AB88A01CC.epilog preserve=yes
//## end module%3A9AB88A01CC.epilog


#endif
