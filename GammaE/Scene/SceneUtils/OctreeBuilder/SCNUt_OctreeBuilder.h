//## begin module%3BE87546036A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE87546036A.cm

//## begin module%3BE87546036A.cp preserve=no
//## end module%3BE87546036A.cp

//## Module: SCNUt_OctreeBuilder%3BE87546036A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\OctreeBuilder\SCNUt_OctreeBuilder.h

#ifndef SCNUt_OctreeBuilder_h
#define SCNUt_OctreeBuilder_h 1

//## begin module%3BE87546036A.additionalIncludes preserve=no
//## end module%3BE87546036A.additionalIncludes

//## begin module%3BE87546036A.includes preserve=yes
//## end module%3BE87546036A.includes

// CObject3D
#include "Scene\CObject3D.h"
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
// SCNUt_TriSceneSplitter
#include "Scene\SceneUtils\SplitTriScene\SCNUt_TriSceneSplitter.h"
// SCNUt_TriSceneSeparator
#include "Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.h"
// SCNUt_ComputeBoundingBox
#include "Scene\SceneUtils\ScnBBoxGen\SCNUt_ComputeBoundingBox.h"
// SCNUt_SceneBuilder
#include "Scene\SceneUtils\SceneBuilder\SCNUt_SceneBuilder.h"
//## begin module%3BE87546036A.additionalDeclarations preserve=yes
//## end module%3BE87546036A.additionalDeclarations


//## begin SCNUt_OctreeBuilder%3BE87546036A.preface preserve=yes
//## end SCNUt_OctreeBuilder%3BE87546036A.preface

//## Class: SCNUt_OctreeBuilder%3BE87546036A
//## Category: Scene::SceneUtils::OctreeBuilder%3BFEE2F60262
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BE8761A0333;SCNUt_MeshCompacter { -> }
//## Uses: <unnamed>%3BE8761E00AE;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3BE876E50136;CObject3D_Node { -> }
//## Uses: <unnamed>%3BFEE12F00A5;CObject3D { -> }
//## Uses: <unnamed>%3BFEE23D01D0;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3BFEE3470345;SCNUt_TriSceneSeparator { -> }
//## Uses: <unnamed>%3BFEE36601CD;SCNUt_TriSceneSplitter { -> }
//## Uses: <unnamed>%3BFEE77E03DD;SCNUt_MaterialTable { -> }
//## Uses: <unnamed>%3C85183C001E;SCNUt_ComputeBoundingBox { -> }
//## Uses: <unnamed>%3C851F4802CB;SCNUt_SceneBuilder { -> }

class SCNUt_OctreeBuilder 
{
  //## begin SCNUt_OctreeBuilder%3BE87546036A.initialDeclarations preserve=yes
  //## end SCNUt_OctreeBuilder%3BE87546036A.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_OctreeBuilder();

    //## Destructor (generated)
      ~SCNUt_OctreeBuilder();


    //## Other Operations (specified)
      //## Operation: poBuildOctree%1005085994
      CObject3D * poBuildOctree (SCNUt_TriScene& _roScene, SCNUt_MaterialTable &_roMatTable);

      //## Operation: poBuildOctreeRec%1015354974
      CObject3D * poBuildOctreeRec (SCNUt_TriScene& _roScene, int _iCurrentSubs, SCNUt_MaterialTable &_roMatTable);

    // Data Members for Class Attributes

      //## Attribute: iMaxSubdivisions%3BE8755B01E4
      //## begin SCNUt_OctreeBuilder::iMaxSubdivisions%3BE8755B01E4.attr preserve=no  public: int {UA} 0
      int iMaxSubdivisions;
      //## end SCNUt_OctreeBuilder::iMaxSubdivisions%3BE8755B01E4.attr

      //## Attribute: iMinTrisPerNode%3BE8757100F5
      //## begin SCNUt_OctreeBuilder::iMinTrisPerNode%3BE8757100F5.attr preserve=no  public: int {UA} 0
      int iMinTrisPerNode;
      //## end SCNUt_OctreeBuilder::iMinTrisPerNode%3BE8757100F5.attr

    // Additional Public Declarations
      //## begin SCNUt_OctreeBuilder%3BE87546036A.public preserve=yes
      //## end SCNUt_OctreeBuilder%3BE87546036A.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_OctreeBuilder%3BE87546036A.protected preserve=yes
      //## end SCNUt_OctreeBuilder%3BE87546036A.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_OctreeBuilder%3BE87546036A.private preserve=yes
      //## end SCNUt_OctreeBuilder%3BE87546036A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_OctreeBuilder%3BE87546036A.implementation preserve=yes
      //## end SCNUt_OctreeBuilder%3BE87546036A.implementation

};

//## begin SCNUt_OctreeBuilder%3BE87546036A.postscript preserve=yes
//## end SCNUt_OctreeBuilder%3BE87546036A.postscript

// Class SCNUt_OctreeBuilder 

//## begin module%3BE87546036A.epilog preserve=yes
//## end module%3BE87546036A.epilog


#endif
