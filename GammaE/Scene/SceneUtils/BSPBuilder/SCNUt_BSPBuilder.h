//## begin module%3BE875B9026B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE875B9026B.cm

//## begin module%3BE875B9026B.cp preserve=no
//## end module%3BE875B9026B.cp

//## Module: SCNUt_BSPBuilder%3BE875B9026B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\BSPBuilder\SCNUt_BSPBuilder.h

#ifndef SCNUt_BSPBuilder_h
#define SCNUt_BSPBuilder_h 1

//## begin module%3BE875B9026B.additionalIncludes preserve=no
//## end module%3BE875B9026B.additionalIncludes

//## begin module%3BE875B9026B.includes preserve=yes
//## end module%3BE875B9026B.includes

// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_BSPNode
#include "Scene\CObject3D_BSPNode.h"
// CObject3D_Node
#include "Scene\CObject3D_Node.h"
// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h"
// SCNUt_MeshCompacter
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h"
// SCNUt_TriSceneClassifier
#include "Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneClassifier.h"
// SCNUt_TriSceneSplitter
#include "Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneSplitter.h"
// SCNUt_TriSceneSeparator
#include "Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.h"
//## begin module%3BE875B9026B.additionalDeclarations preserve=yes
//## end module%3BE875B9026B.additionalDeclarations


//## begin SCNUt_BSPBuilder%3BE875B9026B.preface preserve=yes
//## end SCNUt_BSPBuilder%3BE875B9026B.preface

//## Class: SCNUt_BSPBuilder%3BE875B9026B
//## Category: Scene::SceneUtils::BSPBuilder%3BFEE27701BF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BE876330299;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3BFED87E01C8;SCNUt_MeshCompacter { -> }
//## Uses: <unnamed>%3BFEDE1900C8;SCNUt_TriSceneSplitter { -> }
//## Uses: <unnamed>%3BFEDF2701A2;SCNUt_TriSceneSeparator { -> }
//## Uses: <unnamed>%3BFEE0B2011E;CObject3D_BSPNode { -> }
//## Uses: <unnamed>%3BFEE130018D;CObject3D { -> }
//## Uses: <unnamed>%3BFEE1E800D4;CObject3D_Node { -> }
//## Uses: <unnamed>%3BFEE24B00F4;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3BFEE7B1012D;SCNUt_MaterialTable { -> }
//## Uses: <unnamed>%3BFEEC9E02D5;SCNUt_TriSceneClassifier { -> }

class SCNUt_BSPBuilder 
{
  //## begin SCNUt_BSPBuilder%3BE875B9026B.initialDeclarations preserve=yes
  //## end SCNUt_BSPBuilder%3BE875B9026B.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_BSPBuilder();

    //## Destructor (generated)
      ~SCNUt_BSPBuilder();


    //## Other Operations (specified)
      //## Operation: poBuildBSP%1005085995
      CObject3D * poBuildBSP (SCNUt_TriScene& _roScene, SCNUt_MaterialTable& _roMatTable);

    // Data Members for Class Attributes

      //## Attribute: iMaxSubdivisions%3BFED5C20302
      //## begin SCNUt_BSPBuilder::iMaxSubdivisions%3BFED5C20302.attr preserve=no  public: int {UA} 0
      int iMaxSubdivisions;
      //## end SCNUt_BSPBuilder::iMaxSubdivisions%3BFED5C20302.attr

      //## Attribute: iMinTrisPerNode%3BFED5CD0358
      //## begin SCNUt_BSPBuilder::iMinTrisPerNode%3BFED5CD0358.attr preserve=no  public: int {UA} 0
      int iMinTrisPerNode;
      //## end SCNUt_BSPBuilder::iMinTrisPerNode%3BFED5CD0358.attr

    // Additional Public Declarations
      //## begin SCNUt_BSPBuilder%3BE875B9026B.public preserve=yes
      //## end SCNUt_BSPBuilder%3BE875B9026B.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetPartitionPlane%1006556678
      CPlane GetPartitionPlane (SCNUt_TriScene& _roScene);

      //## Operation: SelectPlaneCandidates%1006556679
      int SelectPlaneCandidates (SCNUt_TriScene& _roScene, int *_piTriIdxs, int _iNumTris);

      //## Operation: iGetNumSplits%1006556680
      int iGetNumSplits (SCNUt_TriScene& _roScene, CPlane& _roPlane, int &_iBackTris, int& _iFrontTris);

    // Additional Protected Declarations
      //## begin SCNUt_BSPBuilder%3BE875B9026B.protected preserve=yes
      //## end SCNUt_BSPBuilder%3BE875B9026B.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_BSPBuilder%3BE875B9026B.private preserve=yes
      //## end SCNUt_BSPBuilder%3BE875B9026B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_BSPBuilder%3BE875B9026B.implementation preserve=yes
      //## end SCNUt_BSPBuilder%3BE875B9026B.implementation

};

//## begin SCNUt_BSPBuilder%3BE875B9026B.postscript preserve=yes
//## end SCNUt_BSPBuilder%3BE875B9026B.postscript

// Class SCNUt_BSPBuilder 

//## begin module%3BE875B9026B.epilog preserve=yes
//## end module%3BE875B9026B.epilog


#endif
