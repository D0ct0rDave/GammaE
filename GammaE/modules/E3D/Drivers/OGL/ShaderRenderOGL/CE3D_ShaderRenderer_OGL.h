//## begin module%3A9AB97B0096.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3A9AB97B0096.cm

//## begin module%3A9AB97B0096.cp preserve=no
//## end module%3A9AB97B0096.cp

//## Module: CE3D_ShaderRenderer_OGL%3A9AB97B0096; Pseudo Package specification
//## Source file: i:\Projects\GammaE\E3D\Drivers\OGL\ShaderRenderOGL\CE3D_ShaderRenderer_OGL.h

#ifndef CE3D_ShaderRenderer_OGL_h
#define CE3D_ShaderRenderer_OGL_h 1

//## begin module%3A9AB97B0096.additionalIncludes preserve=no
//## end module%3A9AB97B0096.additionalIncludes

//## begin module%3A9AB97B0096.includes preserve=yes
//## end module%3A9AB97B0096.includes

// CE3D_Renderer
#include "E3D\CE3D_Renderer.h"
// CMesh
#include "E3D\Mesh\CMesh.h"
// eE3D_MeshType
#include "E3D\MeshDB\eE3D_MeshType.h"
// CCompiledMesh
#include "E3D\CompiledMesh\CCompiledMesh.h"
// CE3D_Shader
#include "E3D\Shaders\CE3D_Shader.h"
// CE3D_ShaderInsts
#include "E3D\Shaders\ShaderInstructions\CE3D_ShaderInsts.h"
//## begin module%3A9AB97B0096.additionalDeclarations preserve=yes
//## end module%3A9AB97B0096.additionalDeclarations


//## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.preface preserve=yes
//## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.preface

//## Class: CE3D_ShaderRenderer_OGL%3A9AB97B0096
//## Category: E3D::Drivers::OGL::ShaderRenderOGL%3A9EC0130348
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C5089DC00BF;CCompiledMesh { -> }
//## Uses: <unnamed>%3A9EC383001E;CMesh { -> }
//## Uses: <unnamed>%3C699B7D021C;CE3D_Shader { -> }
//## Uses: <unnamed>%3C6E6A6203B0;CE3D_ShaderInsts { -> }
//## Uses: <unnamed>%3C6E6B10007B;CE3D_Renderer { -> }
//## Uses: <unnamed>%3C7037D20149;eE3D_MeshType { -> }

class CE3D_ShaderRenderer_OGL 
{
  //## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.initialDeclarations preserve=yes
  //## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.initialDeclarations

  public:
    //## Constructors (generated)
      CE3D_ShaderRenderer_OGL();

    //## Destructor (generated)
      ~CE3D_ShaderRenderer_OGL();


    //## Other Operations (specified)
      //## Operation: Init%1011714680
      virtual void Init ();

      //## Operation: Render_ShInsTexture%1013981858
      void Render_ShInsTexture (CE3D_ShIns_Texture* _poTI);

      //## Operation: Render_ShInsColor%1013981859
      void Render_ShInsColor (CE3D_ShIns_Color* _poTI);

      //## Operation: Render_ShInsWireframe%1013981860
      void Render_ShInsWireframe (CE3D_ShIns_Wireframe* _poTI);

      //## Operation: Render_ShInsExtension%1013981861
      void Render_ShInsExtension (CE3D_ShIns_Extension* _poTI);

      //## Operation: Render_ShInsGeoOp%1013981862
      void Render_ShInsGeoOp (CE3D_ShIns_GeoOp* _poTI);

      //## Operation: Render_ShInsTexOp%1013981863
      void Render_ShInsTexOp (CE3D_ShIns_TexOp* _poTI);

      //## Operation: Render_ShInsBlendOp%1013981864
      void Render_ShInsBlendOp (CE3D_ShIns_BlendOp* _poTI);

      //## Operation: Render_Geometry%1013981865
      void Render_Geometry ();

      //## Operation: InitTMU%1013981866
      void InitTMU (int _iTMU);

      //## Operation: Render%983551120
      virtual void Render (CMesh *_poMesh, CE3D_Shader *_poShader);

      //## Operation: Render%1011911191
      virtual void Render (CCompiledMesh *_poCMesh, CE3D_Shader *_poShader);

      //## Operation: RenderMesh%983551127
      virtual void RenderMesh (CMesh *_poMesh);

      //## Operation: RenderCompiledMesh%1011911190
      virtual void RenderCompiledMesh (CCompiledMesh *_poCMesh);

    // Additional Public Declarations
      //## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.public preserve=yes
      //## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.public

  protected:

    //## Other Operations (specified)
      //## Operation: BeginShaderRender%983551121
      virtual void BeginShaderRender ();

      //## Operation: EndShaderRender%983551122
      virtual void EndShaderRender ();

      //## Operation: RenderShader%983551123
      virtual void RenderShader (CE3D_Shader *_poShader);

    // Additional Protected Declarations
      //## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.protected preserve=yes
      //## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: bDepthEnabled%3A9ABC8602F8
      //## begin CE3D_ShaderRenderer_OGL::bDepthEnabled%3A9ABC8602F8.attr preserve=no  private: bool {UA} 
      bool bDepthEnabled;
      //## end CE3D_ShaderRenderer_OGL::bDepthEnabled%3A9ABC8602F8.attr

      //## Attribute: bUsingConstantColor%3BD3480701AE
      //## begin CE3D_ShaderRenderer_OGL::bUsingConstantColor%3BD3480701AE.attr preserve=no  private: bool {UA} 
      bool bUsingConstantColor;
      //## end CE3D_ShaderRenderer_OGL::bUsingConstantColor%3BD3480701AE.attr

      //## Attribute: poCurrentBV%3C508DA902EF
      //## begin CE3D_ShaderRenderer_OGL::poCurrentBV%3C508DA902EF.attr preserve=no  private: CGraphBV * {UA} NULL
      CGraphBV *poCurrentBV;
      //## end CE3D_ShaderRenderer_OGL::poCurrentBV%3C508DA902EF.attr

      //## Attribute: poCurrentCMesh%3C6AD1050097
      //## begin CE3D_ShaderRenderer_OGL::poCurrentCMesh%3C6AD1050097.attr preserve=no  private: CCompiledMesh * {UA} NULL
      CCompiledMesh *poCurrentCMesh;
      //## end CE3D_ShaderRenderer_OGL::poCurrentCMesh%3C6AD1050097.attr

      //## Attribute: poCurrentMesh%3C6AD10B019A
      //## begin CE3D_ShaderRenderer_OGL::poCurrentMesh%3C6AD10B019A.attr preserve=no  private: CMesh * {UA} NULL
      CMesh *poCurrentMesh;
      //## end CE3D_ShaderRenderer_OGL::poCurrentMesh%3C6AD10B019A.attr

      //## Attribute: bReactivateZTest%3C6AD1120013
      //## begin CE3D_ShaderRenderer_OGL::bReactivateZTest%3C6AD1120013.attr preserve=no  private: bool {UA} 
      bool bReactivateZTest;
      //## end CE3D_ShaderRenderer_OGL::bReactivateZTest%3C6AD1120013.attr

      //## Attribute: iMaxTMUs%3C7028C602B2
      //## begin CE3D_ShaderRenderer_OGL::iMaxTMUs%3C7028C602B2.attr preserve=no  private: int {UA} 1
      int iMaxTMUs;
      //## end CE3D_ShaderRenderer_OGL::iMaxTMUs%3C7028C602B2.attr

      //## Attribute: iCurrentTMU%3C7028CD037B
      //## begin CE3D_ShaderRenderer_OGL::iCurrentTMU%3C7028CD037B.attr preserve=no  private: int {UA} 0
      int iCurrentTMU;
      //## end CE3D_ShaderRenderer_OGL::iCurrentTMU%3C7028CD037B.attr

      //## Attribute: bFlushGeometry%3C7029680201
      //## begin CE3D_ShaderRenderer_OGL::bFlushGeometry%3C7029680201.attr preserve=no  private: bool {UA} false
      bool bFlushGeometry;
      //## end CE3D_ShaderRenderer_OGL::bFlushGeometry%3C7029680201.attr

      //## Attribute: bGeometryFlushed%3C714E5202BD
      //## begin CE3D_ShaderRenderer_OGL::bGeometryFlushed%3C714E5202BD.attr preserve=no  private: bool {UA} false
      bool bGeometryFlushed;
      //## end CE3D_ShaderRenderer_OGL::bGeometryFlushed%3C714E5202BD.attr

      //## Attribute: eMeshType%3C7037C7031A
      //## begin CE3D_ShaderRenderer_OGL::eMeshType%3C7037C7031A.attr preserve=no  private: eE3D_MeshType {UA} 
      eE3D_MeshType eMeshType;
      //## end CE3D_ShaderRenderer_OGL::eMeshType%3C7037C7031A.attr

      //## Attribute: bDisableAT%3C71911F026D
      //## begin CE3D_ShaderRenderer_OGL::bDisableAT%3C71911F026D.attr preserve=no  private: bool {UA} 
      bool bDisableAT;
      //## end CE3D_ShaderRenderer_OGL::bDisableAT%3C71911F026D.attr

      //## Attribute: bEnableCF%3C71912801BC
      //## begin CE3D_ShaderRenderer_OGL::bEnableCF%3C71912801BC.attr preserve=no  private: bool {UA} 
      bool bEnableCF;
      //## end CE3D_ShaderRenderer_OGL::bEnableCF%3C71912801BC.attr

    // Additional Private Declarations
      //## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.private preserve=yes
      //## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.implementation preserve=yes
      //## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.implementation

};

//## begin CE3D_ShaderRenderer_OGL%3A9AB97B0096.postscript preserve=yes
//## end CE3D_ShaderRenderer_OGL%3A9AB97B0096.postscript

// Class CE3D_ShaderRenderer_OGL 

//## begin module%3A9AB97B0096.epilog preserve=yes
//## end module%3A9AB97B0096.epilog


#endif
