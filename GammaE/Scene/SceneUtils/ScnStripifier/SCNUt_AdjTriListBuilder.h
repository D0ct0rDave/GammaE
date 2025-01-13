//## begin module%3C321D3802F1.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C321D3802F1.cm

//## begin module%3C321D3802F1.cp preserve=no
//## end module%3C321D3802F1.cp

//## Module: SCNUt_AdjTriListBuilder%3C321D3802F1; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriListBuilder.h

#ifndef SCNUt_AdjTriListBuilder_h
#define SCNUt_AdjTriListBuilder_h 1

//## begin module%3C321D3802F1.additionalIncludes preserve=no
//## end module%3C321D3802F1.additionalIncludes

//## begin module%3C321D3802F1.includes preserve=yes
//## end module%3C321D3802F1.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// SCNUt_Mesh2TriScene
#include "Scene\SceneUtils\Mesh2TriScn\SCNUt_Mesh2TriScene.h"
// SCNUt_AdjTriList
#include "Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriList.h"
// SCNUt_MeshCompacter
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h"
//## begin module%3C321D3802F1.additionalDeclarations preserve=yes
//## end module%3C321D3802F1.additionalDeclarations


//## begin SCNUt_AdjTriListBuilder%3C321D3802F1.preface preserve=yes
//## end SCNUt_AdjTriListBuilder%3C321D3802F1.preface

//## Class: SCNUt_AdjTriListBuilder%3C321D3802F1
//## Category: Scene::SceneUtils::ScnStripifier%3C308123036F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C321D6502B0;SCNUt_AdjTriList { -> }
//## Uses: <unnamed>%3C321E75035B;SCNUt_Mesh2TriScene { -> }
//## Uses: <unnamed>%3C321E7703C2;SCNUt_MeshCompacter { -> }
//## Uses: <unnamed>%3C321E990190;GammaE_E3D { -> }

class SCNUt_AdjTriListBuilder 
{
  //## begin SCNUt_AdjTriListBuilder%3C321D3802F1.initialDeclarations preserve=yes
  //## end SCNUt_AdjTriListBuilder%3C321D3802F1.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_AdjTriListBuilder();

    //## Destructor (generated)
      ~SCNUt_AdjTriListBuilder();


    //## Other Operations (specified)
      //## Operation: poBuild%1009917119
      SCNUt_AdjTriList* poBuild (CMesh* _poMesh, CMesh *&_rpoOutMesh);

    // Additional Public Declarations
      //## begin SCNUt_AdjTriListBuilder%3C321D3802F1.public preserve=yes
      //## end SCNUt_AdjTriListBuilder%3C321D3802F1.public

  protected:

    //## Other Operations (specified)
      //## Operation: poBuild_FromIndexedTriMesh%1009917121
      SCNUt_AdjTriList * poBuild_FromIndexedTriMesh (CMesh* _poMesh);

      //## Operation: AddEdgeNeighs%1009920806
      void AddEdgeNeighs (CMesh* _poMesh, SCNUt_AdjTriList *_poATL, int _iTri, int _iA, int _iB);

    // Additional Protected Declarations
      //## begin SCNUt_AdjTriListBuilder%3C321D3802F1.protected preserve=yes
      //## end SCNUt_AdjTriListBuilder%3C321D3802F1.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_AdjTriListBuilder%3C321D3802F1.private preserve=yes
      //## end SCNUt_AdjTriListBuilder%3C321D3802F1.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_AdjTriListBuilder%3C321D3802F1.implementation preserve=yes
      //## end SCNUt_AdjTriListBuilder%3C321D3802F1.implementation

};

//## begin SCNUt_AdjTriListBuilder%3C321D3802F1.postscript preserve=yes
//## end SCNUt_AdjTriListBuilder%3C321D3802F1.postscript

// Class SCNUt_AdjTriListBuilder 

//## begin module%3C321D3802F1.epilog preserve=yes
//## end module%3C321D3802F1.epilog


#endif
