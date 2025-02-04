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
#ifndef CGE3DRendererH
#define CGE3DRendererH
// ----------------------------------------------------------------------------
#include "E3D_Enums.h"

#include "CGRenderState.h"
#include "CGRenderStats.h"

// #include "Mesh/CGMesh.h"
// #include "CompiledMesh/CGCompiledMesh.h"

// #include "Viewing/Camera/CGCamera.h"
// #include "Viewing/goViewport/CGViewport.h"
// #include "Viewing/Projector/CGProjector.h"

#include "MeshDB\CGDefferredMeshDB.h"

// #include "Shaders/CGShader.h"
// #include "Materials/CGTexObj.h"
#include "Materials/CGColor.h"
// #include "Materials/CGProgram.h"
// #include "Light/CGLight.h"
#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
#define E3D_RENDERER_OP_DBUFFER 0x00000001
#define E3D_RENDERER_OP_STEREO  0x00000004

// ----------------------------------------------------------------------------

class CGShader;
class CGProjector;
class CGCamera;
class CGViewport;
class CGBaseMesh;
class CGMesh;
class CGCompiledMesh;
class CGProgram;
class CGTextureObj;
class CGLight;
class CGColor;

// ----------------------------------------------------------------------------
class CGE3DRenderer
{
    public:

        CGE3DRenderer();
        
        // / Initializes the 3D Rendering System
        virtual bool bInit(handler _hDeviceContext, uint _uiOptions, uint _uiScrTX, uint _uiScrTY, uint _uiColorBits);

        // / Finalizes the 3D Rendering System
        virtual void Finish();

        // / Uploads a vertex/pixel shader program
        virtual void UploadProgram(CGProgram* _poProgram);

        // / Updates a vertex/pixel shader program
        virtual void UpdateProgram(CGProgram* _poProgram);

        // / Sets a vertex/pixel shader program as current
        virtual void SetCurrentProgram(CGProgram* _poProgram);

        // / Invalidates a vertex/pixel shader program
        virtual void InvalidateProgram(CGProgram* _poProgram);

        // / Sets a parameter for a given vertex/pixel shader program
        virtual void SetProgramParam(CGProgram* _poProgram,const CGString& _sParam,void* _pValue);

        // / Uploads a texture
        virtual void UploadTexture(CGTextureObj* _poTexObj);

        // / Updates a texture
        virtual void UpdateTexture(CGTextureObj* TexObj);

        // / Sets a texture as current
        virtual void SetCurrentTexture(CGTextureObj* _poTexObj);

        // / Invalidates the contents of a texture
        virtual void InvalidateTexture(CGTextureObj* _poTexObj);

        // / Starts the rendering of the current frame
        virtual void BeginRender();

        // / Ends the rendering of the current frame
        virtual void EndRender();

        // / Renders a mesh
        virtual void RenderMesh(CGBaseMesh* _poMesh);

        // / Renders a mesh using a given shader material
        virtual void RenderMesh(CGBaseMesh* _poMesh, CGShader* _poShader);

        // / Compiles a not compiled mesh and returns a compiled mesh object
        virtual CGCompiledMesh* poCompileMesh(CGMesh* _poMesh, CGShader* _poShader);

        // / Destroys a compiled mesh
        virtual void DestroyCompiledMesh(CGCompiledMesh* _poCGMesh);

        // / Forces the rendering of current deferred objects
        virtual void RenderDefferredObjects();

        // / Enables the rendering of mesh bounding volumes
        virtual void EnableBVRender();

        // / Disables the rendering of mesh bounding volumes
        virtual void DisableBVRender();

        // / Returns whether the rendering of mesh bounding volumes is enabled or not
        virtual bool bIsUsingBBRender();

        // / Enables the rendering of mesh normals
        virtual void EnableNormalRender();

        // / Disables the rendering of mesh normals
        virtual void DisableNormalRender();

        // / Returns whether the rendering of mesh normals is being done or not
        virtual bool bIsUsingNormalRender();

        // / Enables the deferred rendering mode
        virtual void EnableDefferredMode();

        // / Disables the deferred rendering mode
        virtual void DisableDefferredMode();

        // / Returns whether deferred rendering mode is being used or not
        virtual bool bIsUsingDefferredMode();

        // / Enables the frustum culling test for mesh rendering
        virtual void EnableFrustumCulling();

        // / Disables the frustum culling test for mesh rendering
        virtual void DisableFrustumCulling();

        // / Returns whether frustum culling test is being applied or not
        virtual bool bIsUsingFrustumCulling();

        // / Enables flat rendering. Rendering without textures and/or lighting
        virtual void EnableFlatRendering();

        // / Disables flat rendering. Rendering without textures and/or lighting
        virtual void DisableFlatRendering();

        // / Returns whether flat rendering is being used or not
        virtual bool bIsUsingFlatRendering();

        // / Pushes the current world matrix into the world matrix stack
        virtual void PushWorldMatrix();

        // / Pops the top of the world matrix stack
        virtual void PopWorldMatrix();

        // / Loads the identity into the current world matrix
        virtual void ClearWorldMatrix();

        // / Retrieves the current world matrix
        virtual void GetWorldMatrix(CGMatrix4x4* _poMatrix);

        // / Sets the given matrix as the current world matrix
        virtual void SetWorldMatrix(const CGMatrix4x4& _oMatrix);

        // / Multiplies the world matrix by the given matrix
        virtual void MultiplyMatrix(const CGMatrix4x4& _oMatrixatrix);

        // / Multiplies the given matrix by the world matrix and sets the result as the world matrix
        virtual void PreMultiplyMatrix(const CGMatrix4x4& _oMatrixatrix);

        // / Sets the given shader as the current shader material.
        virtual void SetCurrentMaterial(CGShader* _poShader) = 0;

        // / Retrieves the current shader material
        virtual CGShader* poGetCurrentMaterial();

        // / Pushes the current camera matrix into camera matrix stack
        virtual void PushCameraMatrix();

        // / Pops the top of the camera matrix stack
        virtual void PopCameraMatrix();

        // / Loads the identity matrix as the current camera matrix
        virtual void ClearCameraMatrix();

        // / Retrieves the current camera matrix
        virtual void GetCameraMatrix(CGMatrix4x4* _oMatrix);

        // / Sets the current camera matrix
        virtual void SetCameraMatrix(const CGMatrix4x4& _oMatrix);

        // / Pushes the current projector matrix into projector matrix stack
        virtual void PushProjectorMatrix();

        // / Pops the top of the projector matrix stack
        virtual void PopProjectorMatrix();

        // / Loads the identity matrix as the current projector matrix
        virtual void ClearProjectorMatrix();

        // / Retrieves the current projector matrix
        virtual void GetProjectorMatrix(CGMatrix4x4* _poMatrix);

        // / Sets the current projector matrix
        virtual void SetProjectorMatrix(const CGMatrix4x4& _oMatrix);

        // / Sets the viewport
        virtual void SetViewport(CGViewport* _poViewport);

        // / Retrieves the current viewport
        virtual CGViewport* poGetViewport();

        // / Sets the camera
        virtual void SetCamera(CGCamera* _poCamera);

        // / Retrieves the current camera
        virtual CGCamera* poGetCamera();

        // / Sets the projector
        virtual void SetProjector(CGProjector* _poProjector);

        // / Retrieves the projector
        virtual CGProjector* poGetProjector();

        // / Retrieves the current viewport aspect ratio
        virtual float fGetAspectRatio();

        // / Sets up the window or screen size
        virtual void SetScreenSize(uint _uiScrTX, uint _uiScrTY) = 0;

        // / Retrieves the window or screen width
        uint uiGetScrTX();

        // / Retrieves the window or screen height
        uint uiGetScrTY();

        // / Reads the specified rendering buffer into the given data pointer
        virtual void ReadBuffer(uint _uiX, uint _uiY, uint _uiTX, uint _uiTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);

        // / Writes into the specified rendering buffer using the given data pointer
        virtual void WriteBuffer(uint _uiX, uint _uiY, uint _uiTX, uint _uiTY, E3D_RenderBuffer_Type _eBufferType, void* _pData);

        // / Sets up the stencil params
        virtual void SetStencilPars(E3D_StencilFunc _eStencilFunc, int _iRefValue, int _iMask, E3D_StencilAction _eSFails, E3D_StencilAction _eZFails, E3D_StencilAction _eZPass);

        // / Sets up the fog params
        virtual void SetFogPars(E3D_FogMode _eFogMode, float _fStart, float _fEnd, float _fDensity, CGColor* _poColor);

        // / Sets up the Z params
        virtual void SetZPars(E3D_ZTestFunc _eZTest, E3D_ZWrite _eZWrite);

        // / Sets up the rendering constant color
        virtual void SetConstantColor(const CGColor& _oColor);

        // / Retrieves the rendering constant color
        virtual const CGColor& oGetConstantColor(const CGColor& _oColor);

        // / Enables or disables the writting into the the given frame buffer channels
        virtual void MaskChannels(bool _bR, bool _bG, bool _bB, bool _bA);

        // / Clears the given rendering buffer
        virtual void ClearBuffer(E3D_RenderBuffer_Type _eBuffer);

        // / Sets up the specified light
        virtual void SetupLight(int _iLightID,const CGLight& _oLight);

        // / Enables or disables the specified light
        virtual void SetLight(int _iLightID, bool _bEnable);

        // / Retrieves the current frustum
        const CGBVFrustum& oGetFrustum();

        // / Retrieves the rendering stats structure
        CGRenderStats& oGetStats()
        {
            return(m_oREStats);
        }

        // / Retrieves the current rendering state structure
        const CGRenderState& oGetState()
        {
            return(m_oREState);
        }

    protected:

        CGRenderStats m_oREStats;

        CGRenderState m_oREState;

        CGColor m_oColor;

        CGBVFrustum m_oFrustum;

        CGDefferredMeshDB m_oDefObjWH;

        CGShader* m_poCurrentShader;

        float m_fAspectRatio;

        uint m_uiScrTX;

        uint m_uiScrTY;

        E3D_StencilFunc m_eStencilFunc;

        E3D_StencilFunc m_eStencilFuncLast;

        E3D_FogMode m_eFogMode;

        E3D_FogMode m_eFogModeLast;

        E3D_ZWrite m_eZWrite;

        E3D_ZWrite m_eZWriteLast;

        E3D_ZTestFunc m_eZTest;

        E3D_ZTestFunc m_eZTestLast;

        CGProjector* m_poProjector;

        CGCamera* m_poCamera;

        CGViewport* m_poViewport;
};
// ----------------------------------------------------------------------------
inline float CGE3DRenderer::fGetAspectRatio ()
{
    return (m_fAspectRatio);
}
// ----------------------------------------------------------------------------
inline uint CGE3DRenderer::uiGetScrTX ()
{
    return(m_uiScrTX);
}
// ----------------------------------------------------------------------------
inline uint CGE3DRenderer::uiGetScrTY ()
{
    return(m_uiScrTY);
}
// ----------------------------------------------------------------------------
inline const CGBVFrustum& CGE3DRenderer::oGetFrustum ()
{
    return(m_oFrustum);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
