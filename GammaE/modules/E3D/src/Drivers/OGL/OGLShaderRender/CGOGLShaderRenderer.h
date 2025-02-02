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
#ifndef CGShaderRendererOGLH
#define CGShaderRendererOGLH
// ----------------------------------------------------------------------------
#include "CGRenderer.h"
#include "E3D_Enums.h"
#include "Mesh\CGMesh.h"
#include "Mesh\CGCompiledMesh.h"
#include "Shaders\CGShader.h"
#include "Shaders\ShaderInstructions\CGShaderInstructions.h"
// ----------------------------------------------------------------------------
class CGOGLShaderRenderer
{
    public:
        CGOGLShaderRenderer();

        ~CGOGLShaderRenderer();

        virtual void Init();

        void Render_ShInsProgram(CGShInsProgram* _poTI);

        void Render_ShInsTexture(CGShInsTexture* _poTI);

        void Render_ShInsColor(CGShInsColor* _poTI);

        void Render_ShInsWireframe(CGShInsWireframe* _poTI);

        void Render_ShInsExtension(CGShInsExtension* _poTI);

        void Render_ShInsGeoOp(CGShInsGeoOp* _poTI);

        void Render_ShInsTexOp(CGShInsTexOp* _poTI);

        void Render_ShInsBlendOp(CGShInsBlendOp* _poTI);

        void Render_ShInsZOp(CGShInsZOp* _poTI);

        void Render_Geometry();

        void InitTMU(uint _uiTMU);

        virtual void Render(CGMesh* _poMesh, CGShader* _poShader);

        virtual void Render(CGCompiledMesh* _poCGMesh, CGShader* _poShader);

        virtual void RenderMesh(CGMesh* _poMesh);

        virtual void RenderCompiledMesh(CGCompiledMesh* _poCGMesh);

    protected:

        virtual void BeginShaderRender();

        virtual void EndShaderRender();

        virtual void RenderShader(CGShader* _poShader);

    private:

        bool m_bDepthEnabled;

        CGGraphBV* m_poCurrentBV;

        CGCompiledMesh* m_poCurrentCGMesh;

        CGMesh* m_poCurrentMesh;

        bool m_bReactivateZTest;

        uint m_uiMaxTMUs;

        uint m_uiCurrentTMU;

        bool m_bFlushGeometry;

        bool m_bGeometryFlushed;

        E3D_MeshType m_eMeshType;

        bool m_bDisableAT;

        bool m_bEnableCF;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
