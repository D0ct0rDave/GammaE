//## begin module%3AC229230384.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC229230384.cm

//## begin module%3AC229230384.cp preserve=no
//## end module%3AC229230384.cp

//## Module: SCNUt_MeshCompacter%3AC229230384; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h

#ifndef SCNUt_MeshCompacter_h
#define SCNUt_MeshCompacter_h 1

//## begin module%3AC229230384.additionalIncludes preserve=no
//## end module%3AC229230384.additionalIncludes

//## begin module%3AC229230384.includes preserve=yes
//## end module%3AC229230384.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h"
//## begin module%3AC229230384.additionalDeclarations preserve=yes
//## end module%3AC229230384.additionalDeclarations


//## begin SCNUt_MeshCompacter%3AC229230384.preface preserve=yes
//## end SCNUt_MeshCompacter%3AC229230384.preface

//## Class: SCNUt_MeshCompacter%3AC229230384
//	Toma una escena con n triángulos y 3*n vertices, y
//	genera una malla de m <=3*n vertices.
//## Category: Scene::SceneUtils::ScnMeshGen%3C76D598034A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3AC22B64023A;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C1BF40A016A;GammaE_E3D { -> }
//## Uses: <unnamed>%3C76D8B30163;SCNUt_MaterialTable { -> }

class SCNUt_MeshCompacter 
{
  //## begin SCNUt_MeshCompacter%3AC229230384.initialDeclarations preserve=yes
  //## end SCNUt_MeshCompacter%3AC229230384.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_MeshCompacter();

    //## Destructor (generated)
      ~SCNUt_MeshCompacter();


    //## Other Operations (specified)
      //## Operation: CompactMesh%985803488
      CMesh * CompactMesh (SCNUt_TriScene &Scene);

    // Additional Public Declarations
      //## begin SCNUt_MeshCompacter%3AC229230384.public preserve=yes
      //## end SCNUt_MeshCompacter%3AC229230384.public

  protected:

    //## Other Operations (specified)
      //## Operation: InsertVertex%985803490
      int InsertVertex (CMesh *Mesh, CVect3 &VX, CVect2& UV, CVect4 &VC, CVect3 &VN);

    // Additional Protected Declarations
      //## begin SCNUt_MeshCompacter%3AC229230384.protected preserve=yes
      //## end SCNUt_MeshCompacter%3AC229230384.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_MeshCompacter%3AC229230384.private preserve=yes
      //## end SCNUt_MeshCompacter%3AC229230384.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_MeshCompacter%3AC229230384.implementation preserve=yes
      //## end SCNUt_MeshCompacter%3AC229230384.implementation

};

//## begin SCNUt_MeshCompacter%3AC229230384.postscript preserve=yes
//## end SCNUt_MeshCompacter%3AC229230384.postscript

// Class SCNUt_MeshCompacter 

//## begin module%3AC229230384.epilog preserve=yes
//## end module%3AC229230384.epilog


#endif
