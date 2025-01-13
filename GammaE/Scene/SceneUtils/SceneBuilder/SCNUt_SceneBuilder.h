//## begin module%3C76E0B701A9.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C76E0B701A9.cm

//## begin module%3C76E0B701A9.cp preserve=no
//## end module%3C76E0B701A9.cp

//## Module: SCNUt_SceneBuilder%3C76E0B701A9; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\SceneBuilder\SCNUt_SceneBuilder.h

#ifndef SCNUt_SceneBuilder_h
#define SCNUt_SceneBuilder_h 1

//## begin module%3C76E0B701A9.additionalIncludes preserve=no
//## end module%3C76E0B701A9.additionalIncludes

//## begin module%3C76E0B701A9.includes preserve=yes
//## end module%3C76E0B701A9.includes

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
// SCNUt_TriSceneSeparator
#include "Scene\SceneUtils\SeparateTriScene\SCNUt_TriSceneSeparator.h"
//## begin module%3C76E0B701A9.additionalDeclarations preserve=yes
//## end module%3C76E0B701A9.additionalDeclarations


//## begin SCNUt_SceneBuilder%3C76E0B701A9.preface preserve=yes
//## end SCNUt_SceneBuilder%3C76E0B701A9.preface

//## Class: SCNUt_SceneBuilder%3C76E0B701A9
//## Category: Scene::SceneUtils::SceneBuilder%3C76E099039B
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C76E14001E3;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3C76E14103BB;CObject3D_Node { -> }
//## Uses: <unnamed>%3C76E1430165;SCNUt_MaterialTable { -> }
//## Uses: <unnamed>%3C76E14502BC;SCNUt_MeshCompacter { -> }
//## Uses: <unnamed>%3C76E15A0230;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C76E590038F;SCNUt_TriSceneSeparator { -> }

class SCNUt_SceneBuilder 
{
  //## begin SCNUt_SceneBuilder%3C76E0B701A9.initialDeclarations preserve=yes
  //## end SCNUt_SceneBuilder%3C76E0B701A9.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_SceneBuilder();

    //## Destructor (generated)
      ~SCNUt_SceneBuilder();


    //## Other Operations (specified)
      //## Operation: poBuildScene%1014423918
      CObject3D * poBuildScene (SCNUt_TriScene& _roScene, SCNUt_MaterialTable &_roMatTable);

    // Additional Public Declarations
      //## begin SCNUt_SceneBuilder%3C76E0B701A9.public preserve=yes
      //## end SCNUt_SceneBuilder%3C76E0B701A9.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_SceneBuilder%3C76E0B701A9.protected preserve=yes
      //## end SCNUt_SceneBuilder%3C76E0B701A9.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_SceneBuilder%3C76E0B701A9.private preserve=yes
      //## end SCNUt_SceneBuilder%3C76E0B701A9.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_SceneBuilder%3C76E0B701A9.implementation preserve=yes
      //## end SCNUt_SceneBuilder%3C76E0B701A9.implementation

};

//## begin SCNUt_SceneBuilder%3C76E0B701A9.postscript preserve=yes
//## end SCNUt_SceneBuilder%3C76E0B701A9.postscript

// Class SCNUt_SceneBuilder 

//## begin module%3C76E0B701A9.epilog preserve=yes
//## end module%3C76E0B701A9.epilog


#endif
