//## begin module%3C5850920196.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C5850920196.cm

//## begin module%3C5850920196.cp preserve=no
//## end module%3C5850920196.cp

//## Module: CLoaderBSP2%3C5850920196; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\BSP2Loader\CLoaderBSP2.h

#ifndef CLoaderBSP2_h
#define CLoaderBSP2_h 1

//## begin module%3C5850920196.additionalIncludes preserve=no
//## end module%3C5850920196.additionalIncludes

//## begin module%3C5850920196.includes preserve=yes
#include "BSP2types.h"
//## end module%3C5850920196.includes

// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_BSPNode
#include "Scene\CObject3D_BSPNode.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
// C3DLoader
#include "Scene\3D_Loaders\C3DLoader.h"
// SCNUt_TriSceneAccumulator
#include "Scene\SceneUtils\SCNUt_TriSceneAccumulator.h"
// SCNUt_TriUtils
#include "Scene\SceneUtils\ScnUtils\SCNUt_TriUtils.h"
// SCNUt_MeshGenerator
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshGenerator.h"
// SCNUt_TriSceneSeparator
#include "Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.h"
//## begin module%3C5850920196.additionalDeclarations preserve=yes

struct ext_texinfo
{
	int			iWidth;
	int			iHeight;
	bsp_texinfo *pBTI;
};

//## end module%3C5850920196.additionalDeclarations


//## begin CLoaderBSP2%3C5850920196.preface preserve=yes
//## end CLoaderBSP2%3C5850920196.preface

//## Class: CLoaderBSP2%3C5850920196
//## Category: Scene::3D_Loaders::BSP2Loader%3C58505402FF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C587A090008;SCNUt_TriSceneAccumulator { -> }
//## Uses: <unnamed>%3C587A40001B;SCNUt_TriSceneSeparator { -> }
//## Uses: <unnamed>%3C587A410294;SCNUt_MeshGenerator { -> }
//## Uses: <unnamed>%3C587EE80001;CObject3D { -> }
//## Uses: <unnamed>%3C587EEB0042;CObject3D_Node { -> }
//## Uses: <unnamed>%3C587EEC024C;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3C5AB39B0226;CObject3D_BSPNode { -> }
//## Uses: <unnamed>%3C76DB2400DF;SCNUt_TriUtils { -> }

class CLoaderBSP2 : public C3DLoader  //## Inherits: <unnamed>%3C5850B5016E
{
  //## begin CLoaderBSP2%3C5850920196.initialDeclarations preserve=yes
  //## end CLoaderBSP2%3C5850920196.initialDeclarations

  public:
    //## Constructors (generated)
      CLoaderBSP2();

    //## Destructor (generated)
      ~CLoaderBSP2();


    //## Other Operations (specified)
      //## Operation: pLoad%1012420867
      virtual CObject3D * pLoad (char* Filename);

      //## Operation: SetExtendedTexInfo%1012723808
      void SetExtendedTexInfo ();

      //## Operation: poProcessBSP%1012420868
      CObject3D * poProcessBSP ();

      //## Operation: poGenerateLeaf%1012428862
      CObject3D * poGenerateLeaf (bsp_leaf *_pLeaf);

      //## Operation: poGenerateNode%1012576246
      CObject3D * poGenerateNode (bsp_node* _pNode);

      //## Operation: poGenerateNodeMesh%1012576247
      CObject3D * poGenerateNodeMesh (bsp_node* _pNode);

      //## Operation: AddFace%1012428863
      void AddFace (bsp_face *pFace, SCNUt_TriSceneAccumulator *_pTScn);

      //## Operation: SetQ2BaseDir%1012510461
      void SetQ2BaseDir (char *_szDirectory);

    // Additional Public Declarations
      //## begin CLoaderBSP2%3C5850920196.public preserve=yes
      //## end CLoaderBSP2%3C5850920196.public

  protected:
    // Additional Protected Declarations
      //## begin CLoaderBSP2%3C5850920196.protected preserve=yes
      //## end CLoaderBSP2%3C5850920196.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: oBSPhdr%3C58515603C9
      //## begin CLoaderBSP2::oBSPhdr%3C58515603C9.attr preserve=no  private: bsp_header {UA} 
      bsp_header oBSPhdr;
      //## end CLoaderBSP2::oBSPhdr%3C58515603C9.attr

      //## Attribute: pVXs%3C585373031C
      //## begin CLoaderBSP2::pVXs%3C585373031C.attr preserve=no  private: bsp_point3f * {UA} NULL
      bsp_point3f *pVXs;
      //## end CLoaderBSP2::pVXs%3C585373031C.attr

      //## Attribute: iNumVXs%3C58538C00AB
      //## begin CLoaderBSP2::iNumVXs%3C58538C00AB.attr preserve=no  private: int {UA} 0
      int iNumVXs;
      //## end CLoaderBSP2::iNumVXs%3C58538C00AB.attr

      //## Attribute: pEdges%3C5853E202CC
      //## begin CLoaderBSP2::pEdges%3C5853E202CC.attr preserve=no  private: bsp_edge * {UA} NULL
      bsp_edge *pEdges;
      //## end CLoaderBSP2::pEdges%3C5853E202CC.attr

      //## Attribute: iNumEdges%3C5853E90037
      //## begin CLoaderBSP2::iNumEdges%3C5853E90037.attr preserve=no  private: int {UA} 0
      int iNumEdges;
      //## end CLoaderBSP2::iNumEdges%3C5853E90037.attr

      //## Attribute: pFaces%3C5854580376
      //## begin CLoaderBSP2::pFaces%3C5854580376.attr preserve=no  private: bsp_face * {UA} NULL
      bsp_face *pFaces;
      //## end CLoaderBSP2::pFaces%3C5854580376.attr

      //## Attribute: iNumFaces%3C58545E0342
      //## begin CLoaderBSP2::iNumFaces%3C58545E0342.attr preserve=no  private: int {UA} 0
      int iNumFaces;
      //## end CLoaderBSP2::iNumFaces%3C58545E0342.attr

      //## Attribute: pLFaces%3C5875AB005B
      //## begin CLoaderBSP2::pLFaces%3C5875AB005B.attr preserve=no  private: bsp_leaf_face * {UA} NULL
      bsp_leaf_face *pLFaces;
      //## end CLoaderBSP2::pLFaces%3C5875AB005B.attr

      //## Attribute: iNumLFaces%3C5875BD0075
      //## begin CLoaderBSP2::iNumLFaces%3C5875BD0075.attr preserve=no  private: int {UA} 0
      int iNumLFaces;
      //## end CLoaderBSP2::iNumLFaces%3C5875BD0075.attr

      //## Attribute: pFEdges%3C5854E403DB
      //## begin CLoaderBSP2::pFEdges%3C5854E403DB.attr preserve=no  private: bsp_face_edge * {UA} NULL
      bsp_face_edge *pFEdges;
      //## end CLoaderBSP2::pFEdges%3C5854E403DB.attr

      //## Attribute: iNumFEdges%3C5854EE0169
      //## begin CLoaderBSP2::iNumFEdges%3C5854EE0169.attr preserve=no  private: int {UA} 0
      int iNumFEdges;
      //## end CLoaderBSP2::iNumFEdges%3C5854EE0169.attr

      //## Attribute: pPlanes%3C5855540025
      //## begin CLoaderBSP2::pPlanes%3C5855540025.attr preserve=no  private: bsp_plane * {UA} NULL
      bsp_plane *pPlanes;
      //## end CLoaderBSP2::pPlanes%3C5855540025.attr

      //## Attribute: iNumPlanes%3C58555A024A
      //## begin CLoaderBSP2::iNumPlanes%3C58555A024A.attr preserve=no  private: int {UA} 0
      int iNumPlanes;
      //## end CLoaderBSP2::iNumPlanes%3C58555A024A.attr

      //## Attribute: pNodes%3C5855E8032B
      //## begin CLoaderBSP2::pNodes%3C5855E8032B.attr preserve=no  private: bsp_node * {UA} NULL
      bsp_node *pNodes;
      //## end CLoaderBSP2::pNodes%3C5855E8032B.attr

      //## Attribute: iNumNodes%3C5855F701D8
      //## begin CLoaderBSP2::iNumNodes%3C5855F701D8.attr preserve=no  private: int {UA} 0
      int iNumNodes;
      //## end CLoaderBSP2::iNumNodes%3C5855F701D8.attr

      //## Attribute: pLeaves%3C58572B03B2
      //## begin CLoaderBSP2::pLeaves%3C58572B03B2.attr preserve=no  private: bsp_leaf * {UA} NULL
      bsp_leaf *pLeaves;
      //## end CLoaderBSP2::pLeaves%3C58572B03B2.attr

      //## Attribute: iNumLeaves%3C5857390311
      //## begin CLoaderBSP2::iNumLeaves%3C5857390311.attr preserve=no  private: int {UA} 0
      int iNumLeaves;
      //## end CLoaderBSP2::iNumLeaves%3C5857390311.attr

      //## Attribute: pTexInfo%3C5858570395
      //## begin CLoaderBSP2::pTexInfo%3C5858570395.attr preserve=no  private: bsp_texinfo * {UA} NULL
      bsp_texinfo *pTexInfo;
      //## end CLoaderBSP2::pTexInfo%3C5858570395.attr

      //## Attribute: pExtTexInfo%3C5CF05300B9
      //## begin CLoaderBSP2::pExtTexInfo%3C5CF05300B9.attr preserve=no  private: ext_texinfo * {UA} NULL
      ext_texinfo *pExtTexInfo;
      //## end CLoaderBSP2::pExtTexInfo%3C5CF05300B9.attr

      //## Attribute: iNumTexs%3C5858640181
      //## begin CLoaderBSP2::iNumTexs%3C5858640181.attr preserve=no  private: int {UA} 0
      int iNumTexs;
      //## end CLoaderBSP2::iNumTexs%3C5858640181.attr

      //## Attribute: pVIS%3C5859490298
      //## begin CLoaderBSP2::pVIS%3C5859490298.attr preserve=no  private: bsp_vis_offset * {UA} NULL
      bsp_vis_offset *pVIS;
      //## end CLoaderBSP2::pVIS%3C5859490298.attr

      //## Attribute: iNumVis%3C5859590332
      //## begin CLoaderBSP2::iNumVis%3C5859590332.attr preserve=no  private: int {UA} 0
      int iNumVis;
      //## end CLoaderBSP2::iNumVis%3C5859590332.attr

      //## Attribute: poScnLeaves%3C587A8501B5
      //## begin CLoaderBSP2::poScnLeaves%3C587A8501B5.attr preserve=no  private: CObject3D* * {UA} NULL
      CObject3D* *poScnLeaves;
      //## end CLoaderBSP2::poScnLeaves%3C587A8501B5.attr

      //## Attribute: szQ2BaseDir%3C59C6ED0376
      //## begin CLoaderBSP2::szQ2BaseDir%3C59C6ED0376.attr preserve=no  private: char[256] {UA} 
      char szQ2BaseDir[256];
      //## end CLoaderBSP2::szQ2BaseDir%3C59C6ED0376.attr

    // Additional Private Declarations
      //## begin CLoaderBSP2%3C5850920196.private preserve=yes
      //## end CLoaderBSP2%3C5850920196.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLoaderBSP2%3C5850920196.implementation preserve=yes
      //## end CLoaderBSP2%3C5850920196.implementation

};

//## begin CLoaderBSP2%3C5850920196.postscript preserve=yes
//## end CLoaderBSP2%3C5850920196.postscript

// Class CLoaderBSP2 

//## begin module%3C5850920196.epilog preserve=yes
//## end module%3C5850920196.epilog


#endif
