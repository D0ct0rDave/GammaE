//## begin module%3AC0F80B0168.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC0F80B0168.cm

//## begin module%3AC0F80B0168.cp preserve=no
//## end module%3AC0F80B0168.cp

//## Module: CLoaderMD2%3AC0F80B0168; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\MD2Loader\CLoaderMD2.h

#ifndef CLoaderMD2_h
#define CLoaderMD2_h 1

//## begin module%3AC0F80B0168.additionalIncludes preserve=no
//## end module%3AC0F80B0168.additionalIncludes

//## begin module%3AC0F80B0168.includes preserve=yes
#include "MD2Types.h"
//## end module%3AC0F80B0168.includes

// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// C3DLoader
#include "Scene\3D_Loaders\C3DLoader.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_MeshCompacter
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h"
// SCNUt_AnimMesh_NormalComputer
#include "Scene\SceneUtils\ScnNormalGen\SCNUt_AnimMesh_NormalComputer.h"
// CObject3D_AnimCfgMgr
#include "Scene\Animation\CObject3D_AnimCfgMgr.h"
// CObject3D_AnimMesh
#include "Scene\Animation\CObject3D_AnimMesh.h"
// CObject3D_AnimCfg
#include "Scene\Animation\CObject3D_AnimCfg.h"
//## begin module%3AC0F80B0168.additionalDeclarations preserve=yes
//## end module%3AC0F80B0168.additionalDeclarations


//## begin CLoaderMD2%3AC0F80B0168.preface preserve=yes
//## end CLoaderMD2%3AC0F80B0168.preface

//## Class: CLoaderMD2%3AC0F80B0168
//## Category: Scene::3D_Loaders::MD2Loader%3AC0F7FE00AA
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AC0F84700DC;CObject3D { -> }
//## Uses: <unnamed>%3AC253F7038E;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3AC3B14200E6;SCNUt_MeshCompacter { -> }
//## Uses: <unnamed>%3AC0F8740064;CObject3D_Node { -> }
//## Uses: <unnamed>%3B9FF6890003;CObject3D_AnimCfg { -> }
//## Uses: <unnamed>%3B9FF68A0253;CObject3D_AnimMesh { -> }
//## Uses: <unnamed>%3BA51E5500A2;CObject3D_AnimCfgMgr { -> }
//## Uses: <unnamed>%3BA7B61000B3;SCNUt_AnimMesh_NormalComputer { -> }

class CLoaderMD2 : public C3DLoader  //## Inherits: <unnamed>%3AC0F8F000E6
{
  //## begin CLoaderMD2%3AC0F80B0168.initialDeclarations preserve=yes
  //## end CLoaderMD2%3AC0F80B0168.initialDeclarations

  public:
    //## Constructors (generated)
      CLoaderMD2();

    //## Destructor (generated)
      ~CLoaderMD2();


    //## Other Operations (specified)
      //## Operation: pLoad%985903378
      virtual CObject3D * pLoad (char* Filename);

      //## Operation: GetNumSkins%986042752
      int GetNumSkins ();

      //## Operation: GetSkin%986042753
      char * GetSkin (int iSkin);

      //## Operation: GetNumFrames%986051315
      int GetNumFrames ();

      //## Operation: pLoadQ2Player%1000676444
      CObject3D_AnimCfgGen * pLoadQ2Player (char* Filename);

    // Additional Public Declarations
      //## begin CLoaderMD2%3AC0F80B0168.public preserve=yes
      //## end CLoaderMD2%3AC0F80B0168.public

  protected:

    //## Other Operations (specified)
      //## Operation: ReadFile%986042756
      int ReadFile (char *Filename);

      //## Operation: SetupFrame%986042755
      void SetupFrame (int iFrame);

      //## Operation: ParseHeader%985725079
      void ParseHeader ();

      //## Operation: ParseChunks%985725080
      CObject3D * ParseChunks ();

      //## Operation: ParseModel%985903379
      SCNUt_TriScene * ParseModel ();

      //## Operation: ParseMaterial%985903848
      CE3D_Shader * ParseMaterial ();

      //## Operation: GetVertexConversionTable%985989940
      unsigned short * GetVertexConversionTable (CMesh &Mesh);

      //## Operation: ParseFrameSet%985989939
      void ParseFrameSet (CObject3D_AnimMesh &AnimMesh, CMesh &Mesh);

    // Additional Protected Declarations
      //## begin CLoaderMD2%3AC0F80B0168.protected preserve=yes
      //## end CLoaderMD2%3AC0F80B0168.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: Stream%3AC5D16301EA
      //## begin CLoaderMD2::Stream%3AC5D16301EA.attr preserve=no  private: char * {UA} NULL
      char *Stream;
      //## end CLoaderMD2::Stream%3AC5D16301EA.attr

      //## Attribute: StreamSize%3AC5D2AE008C
      //## begin CLoaderMD2::StreamSize%3AC5D2AE008C.attr preserve=no  private: int {UA} 0
      int StreamSize;
      //## end CLoaderMD2::StreamSize%3AC5D2AE008C.attr

      //## Attribute: MD2Header%3AC5D16E00C8
      //## begin CLoaderMD2::MD2Header%3AC5D16E00C8.attr preserve=no  private: model_t * {UA} NULL
      model_t *MD2Header;
      //## end CLoaderMD2::MD2Header%3AC5D16E00C8.attr

      //## Attribute: Frame%3AC5D2F7008C
      //## begin CLoaderMD2::Frame%3AC5D2F7008C.attr preserve=no  private: frame_t * {UA} NULL
      frame_t *Frame;
      //## end CLoaderMD2::Frame%3AC5D2F7008C.attr

      //## Attribute: Triangles%3AC5D32E0046
      //## begin CLoaderMD2::Triangles%3AC5D32E0046.attr preserve=no  private: triangle_t * {UA} NULL
      triangle_t *Triangles;
      //## end CLoaderMD2::Triangles%3AC5D32E0046.attr

      //## Attribute: Vertexs%3AC5D3040140
      //## begin CLoaderMD2::Vertexs%3AC5D3040140.attr preserve=no  private: triangleVertex_t * {UA} NULL
      triangleVertex_t *Vertexs;
      //## end CLoaderMD2::Vertexs%3AC5D3040140.attr

      //## Attribute: TexCoords%3AC5D3180096
      //## begin CLoaderMD2::TexCoords%3AC5D3180096.attr preserve=no  private: textureCoordinate_t * {UA} NULL
      textureCoordinate_t *TexCoords;
      //## end CLoaderMD2::TexCoords%3AC5D3180096.attr

    // Additional Private Declarations
      //## begin CLoaderMD2%3AC0F80B0168.private preserve=yes
      //## end CLoaderMD2%3AC0F80B0168.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLoaderMD2%3AC0F80B0168.implementation preserve=yes
      //## end CLoaderMD2%3AC0F80B0168.implementation

};

//## begin CLoaderMD2%3AC0F80B0168.postscript preserve=yes
//## end CLoaderMD2%3AC0F80B0168.postscript

// Class CLoaderMD2 

//## begin module%3AC0F80B0168.epilog preserve=yes
//## end module%3AC0F80B0168.epilog


#endif
