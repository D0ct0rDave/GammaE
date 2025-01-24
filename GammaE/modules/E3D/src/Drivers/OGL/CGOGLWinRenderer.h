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
#ifndef CGOGLWinRendererH
#define CGOGLWinRendererH
// ----------------------------------------------------------------------------
// Driver specific options
// ----------------------------------------------------------------------------
#define E3D_RENDERER_OP_GDI     0x00000100

#ifdef _MBCS
    #include <windows.h>
    #include <wingdi.h>

    #define TPixelFormatDescriptor  PIXELFORMATDESCRIPTOR
    #define TLogPalette             LOGPALETTE
    #define TPaletteEntry           PALETTEENTRY
#else
    #ifdef __BORLANDC__

        #include <vcl.h>

        #include <windows.h>
        #define TPixelFormatDescriptor  PIXELFORMATDESCRIPTOR
        #define TLogPalette             LOGPALETTE
        #define TPaletteEntry           PALETTEENTRY

    #endif
#endif

// CGOGLRenderer
#include "Drivers\OGL\CGOGLRenderer.h"
// CGShInsColor
#include "Shaders\ShaderInstructions\CGShInsColor.h"

#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGOGLWinRenderer : public CGOGLRenderer
{
    public:
        friend class CGOGLShaderRenderer;

        CGOGLWinRenderer();

        ~CGOGLWinRenderer();

        virtual void UploadProgram(CGProgram* _poProgram);

        virtual void UpdateProgram(CGProgram* _poProgram);

        virtual void SetCurrentProgram(CGProgram* _poProgram);

        virtual void InvalidateProgram(CGProgram* _poProgram);

        virtual void SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void* _pValue);

        void RenderBV(CGBoundingVolume* _poBV);

        void RenderNormals(CGMesh* _poMesh);

        virtual void BeginRender();

        virtual void DisableBVRender();

        virtual void DisableDefferredMode();

        virtual void DisableFrustumCulling();

        virtual void DisableNormalRender();

        virtual void EnableBVRender();

        virtual void EnableDefferredMode();

        virtual void EnableFrustumCulling();

        virtual void EnableNormalRender();

        virtual void EndRender();

        virtual void Finish();

        virtual CGShader* poGetCurrentMaterial();

        virtual bool bInit(handler _hDeviceContext, uint _uiOptions, uint _uiScrTX, uint _uiScrTY, uint _uiColorBits);

        virtual void RenderDefferredObjects();

        virtual void RenderMesh(CGBaseMesh* _poMesh, CGShader* _poShader);

        virtual void RenderMesh(CGBaseMesh* _poMesh);

        // ------------------------------------------------------
        void MultiplyMatrix(CGMatrix4x4* Matrix);

        void PreMultiplyMatrix(CGMatrix4x4* Matrix);
        // ------------------------------------------------------

        virtual void ClearCameraMatrix();

        virtual void PushCameraMatrix();

        virtual void PopCameraMatrix();

        virtual void SetCameraMatrix(CGMatrix4x4* M);

        virtual void GetCameraMatrix(CGMatrix4x4* M);

        virtual void ClearWorldMatrix();

        virtual void PushWorldMatrix();

        virtual void PopWorldMatrix();

        virtual void SetWorldMatrix(CGMatrix4x4* M);

        virtual void GetWorldMatrix(CGMatrix4x4* M);

        virtual void ClearProjectorMatrix();

        virtual void PushProjectorMatrix();

        virtual void PopProjectorMatrix();

        virtual void SetProjectorMatrix(CGMatrix4x4* M);

        virtual void GetProjectorMatrix(CGMatrix4x4* M);

        // ------------------------------------------------------

        virtual void SetCurrentMaterial(CGShader* _poShader);

        virtual void SetCurrentTexture(CGTextureObj* TexObj);

        virtual void UpdateTexture(CGTextureObj* TexObj);

        virtual void UploadTexture(CGTextureObj* TexObj);

        virtual bool bUsingBBRender();

        virtual bool bUsingDefferredMode();

        virtual bool bUsingFrustumCulling();

        virtual bool bUsingNormalRender();

        virtual void SetViewport(CGViewport* _Viewport);

        virtual CGViewport* poGetViewport();

        virtual void SetCamera(CGCamera* _Camera);

        virtual CGCamera* poGetCamera();

        virtual void SetProjector(CGProjector* _Projector);

        virtual CGProjector* poGetProjector();

        virtual void SetScreenSize(uint _uiScrTX, uint _uiScrTY);

        virtual CGCompiledMesh* poCompileMesh(CGMesh* _poMesh, CGShader* _poShader);

        virtual void DestroyCompiledMesh(CGCompiledMesh* _poCGMesh);

        void SetupPalette(TPixelFormatDescriptor PFD);

        virtual void EnableFlatRendering();

        virtual void DisableFlatRendering();

        virtual bool bUsingFlatRendering();

        virtual void ReadBuffer(int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);

        virtual void WriteBuffer(int _iX, int _iY, int _iTX, int _iTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);

        virtual void SetStencilParams(bool _bEnable, E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass);

        virtual void SetZPars(E3D_ZTestFunc _eZTest,E3D_ZWrite _eZWrite);

        virtual void MaskChannels(bool _bR, bool _bG, bool _bB, bool _bA);

        virtual void SetFogPars(E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor);

        virtual void ClearBuffer(E3D_RenderBuffer_Type _eBuffer);

        virtual void SetupLight(int _iLightID, CGLight& _oLight);

        virtual void SetLight(int _iLightID, bool _bEnable);

        virtual void InvalidateTexture(CGTextureObj* TexObj);

        virtual void SetConstantColor(const CGColor& _oColor);

    protected:

        void RenderMesh_Int(CGBaseMesh* _poMesh, CGShader* _poShader,const CGMatrix4x4& _oMVTransf);

        HWND WND;
        HDC DC;
        HGLRC GLRC;
        CGChrono m_oChrono;

    private:

    private:
        void PrepareLights();
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
