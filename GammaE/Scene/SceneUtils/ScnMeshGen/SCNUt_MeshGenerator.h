//## begin module%3BF19F09020E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BF19F09020E.cm

//## begin module%3BF19F09020E.cp preserve=no
//## end module%3BF19F09020E.cp

//## Module: SCNUt_MeshGenerator%3BF19F09020E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnMeshGen\SCNUt_MeshGenerator.h

#ifndef SCNUt_MeshGenerator_h
#define SCNUt_MeshGenerator_h 1

//## begin module%3BF19F09020E.additionalIncludes preserve=no
//## end module%3BF19F09020E.additionalIncludes

//## begin module%3BF19F09020E.includes preserve=yes
//## end module%3BF19F09020E.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h"
//## begin module%3BF19F09020E.additionalDeclarations preserve=yes
//## end module%3BF19F09020E.additionalDeclarations


//## begin SCNUt_MeshGenerator%3BF19F09020E.preface preserve=yes
//## end SCNUt_MeshGenerator%3BF19F09020E.preface

//## Class: SCNUt_MeshGenerator%3BF19F09020E
//## Category: Scene::SceneUtils::ScnMeshGen%3C76D598034A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BF19F3301FB;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C1BF4D8015C;GammaE_E3D { -> }
//## Uses: <unnamed>%3C76D8AE03A0;SCNUt_MaterialTable { -> }

class SCNUt_MeshGenerator 
{
  //## begin SCNUt_MeshGenerator%3BF19F09020E.initialDeclarations preserve=yes
  //## end SCNUt_MeshGenerator%3BF19F09020E.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_MeshGenerator();

    //## Destructor (generated)
      ~SCNUt_MeshGenerator();


    //## Other Operations (specified)
      //## Operation: GenerateMesh%1005690702
      CMesh * GenerateMesh (SCNUt_TriScene &Scene);

    // Additional Public Declarations
      //## begin SCNUt_MeshGenerator%3BF19F09020E.public preserve=yes
      //## end SCNUt_MeshGenerator%3BF19F09020E.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_MeshGenerator%3BF19F09020E.protected preserve=yes
      //## end SCNUt_MeshGenerator%3BF19F09020E.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_MeshGenerator%3BF19F09020E.private preserve=yes
      //## end SCNUt_MeshGenerator%3BF19F09020E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_MeshGenerator%3BF19F09020E.implementation preserve=yes
      //## end SCNUt_MeshGenerator%3BF19F09020E.implementation

};

//## begin SCNUt_MeshGenerator%3BF19F09020E.postscript preserve=yes
//## end SCNUt_MeshGenerator%3BF19F09020E.postscript

// Class SCNUt_MeshGenerator 

//## begin module%3BF19F09020E.epilog preserve=yes
//## end module%3BF19F09020E.epilog


#endif
