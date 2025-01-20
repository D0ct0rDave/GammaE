//-----------------------------------------------------------------------------
#ifndef CE3D_ShaderRenderer_OGL_h
#define CE3D_ShaderRenderer_OGL_h 1
//-----------------------------------------------------------------------------
#include "CE3D_Renderer.h"
#include "E3D_Enums.h"
#include "Mesh\CMesh.h"
#include "CompiledMesh\CCompiledMesh.h"
#include "Shaders\CE3D_Shader.h"
#include "Shaders\ShaderInstructions\CE3D_ShaderInsts.h"
//-----------------------------------------------------------------------------
class CE3D_ShaderRenderer_OGL 
{
  public:
          CE3D_ShaderRenderer_OGL();

          ~CE3D_ShaderRenderer_OGL();

            virtual void Init ();

			void Render_ShInsProgram(CE3D_ShIns_Program* _poTI);

            void Render_ShInsTexture (CE3D_ShIns_Texture* _poTI);

            void Render_ShInsColor (CE3D_ShIns_Color* _poTI);

            void Render_ShInsWireframe (CE3D_ShIns_Wireframe* _poTI);

            void Render_ShInsExtension (CE3D_ShIns_Extension* _poTI);

            void Render_ShInsGeoOp (CE3D_ShIns_GeoOp* _poTI);

            void Render_ShInsTexOp (CE3D_ShIns_TexOp* _poTI);

            void Render_ShInsBlendOp (CE3D_ShIns_BlendOp* _poTI);
            
            void Render_ShInsZOp (CE3D_ShIns_ZOp* _poTI);

            void Render_Geometry ();

            void InitTMU (int _iTMU);

            virtual void Render (CMesh *_poMesh, CE3D_Shader *_poShader);

            virtual void Render (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader);

            virtual void RenderMesh (CMesh *_poMesh);

            virtual void RenderCompiledMesh (CCompiledMesh *_poCMesh);

    // Additional Public Declarations
            
  protected:

                virtual void BeginShaderRender ();

            virtual void EndShaderRender ();

            virtual void RenderShader (CE3D_Shader *_poShader);

    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  bool bDepthEnabled;
          
                  CGraphBV *poCurrentBV;
      
                  CCompiledMesh *poCurrentCMesh;
      
                  CMesh *poCurrentMesh;
      
                  bool bReactivateZTest;
      
                  int iMaxTMUs;
      
                  int iCurrentTMU;
      
                  bool bFlushGeometry;
      
                  bool bGeometryFlushed;
      
                  E3D_MeshType eMeshType;
      
                  bool bDisableAT;
      
                  bool bEnableCF;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
