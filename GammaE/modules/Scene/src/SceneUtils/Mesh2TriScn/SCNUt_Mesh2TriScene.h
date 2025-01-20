//## begin module%3C2BD25F0321.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BD25F0321.cm

//## begin module%3C2BD25F0321.cp preserve=no
//## end module%3C2BD25F0321.cp

//## Module: SCNUt_Mesh2TriScene%3C2BD25F0321; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\Mesh2TriScn\SCNUt_Mesh2TriScene.h

#ifndef SCNUt_Mesh2TriScene_h
#define SCNUt_Mesh2TriScene_h 1

//## begin module%3C2BD25F0321.additionalIncludes preserve=no
//## end module%3C2BD25F0321.additionalIncludes

//## begin module%3C2BD25F0321.includes preserve=yes
//## end module%3C2BD25F0321.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3C2BD25F0321.additionalDeclarations preserve=yes
//## end module%3C2BD25F0321.additionalDeclarations


//## begin SCNUt_Mesh2TriScene%3C2BD25F0321.preface preserve=yes
//## end SCNUt_Mesh2TriScene%3C2BD25F0321.preface

//## Class: SCNUt_Mesh2TriScene%3C2BD25F0321
//## Category: Scene::SceneUtils::Mesh2TriScn%3C2BD2E90026
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2BD34B014A;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C2BD3510207;GammaE_E3D { -> }

class SCNUt_Mesh2TriScene 
{
  //## begin SCNUt_Mesh2TriScene%3C2BD25F0321.initialDeclarations preserve=yes
  //## end SCNUt_Mesh2TriScene%3C2BD25F0321.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_Mesh2TriScene();

    //## Destructor (generated)
      ~SCNUt_Mesh2TriScene();


    //## Other Operations (specified)
      //## Operation: Generate%1009496924
      SCNUt_TriScene* Generate (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromIndexedTriFanMesh%1009552651
      SCNUt_TriScene* Generate_FromIndexedTriFanMesh (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromIndexedQuadStripMesh%1009552652
      SCNUt_TriScene* Generate_FromIndexedQuadStripMesh (CMesh& _roMesh, int _iMat);

    // Additional Public Declarations
      //## begin SCNUt_Mesh2TriScene%3C2BD25F0321.public preserve=yes
      //## end SCNUt_Mesh2TriScene%3C2BD25F0321.public

  protected:

    //## Other Operations (specified)
      //## Operation: Generate_FromIndexedTriMesh%1009552653
      SCNUt_TriScene* Generate_FromIndexedTriMesh (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromIndexedQuadMesh%1009552654
      SCNUt_TriScene* Generate_FromIndexedQuadMesh (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromIndexedTriStripMesh%1009552655
      SCNUt_TriScene* Generate_FromIndexedTriStripMesh (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromNonIndexedTriMesh%1009552656
      SCNUt_TriScene* Generate_FromNonIndexedTriMesh (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromNonIndexedQuadMesh%1009552657
      SCNUt_TriScene* Generate_FromNonIndexedQuadMesh (CMesh& _roMesh, int _iMat);

      //## Operation: Generate_FromNonIndexedTriStripMesh%1009552658
      SCNUt_TriScene* Generate_FromNonIndexedTriStripMesh (CMesh& _roMesh, int _iMat);

    // Additional Protected Declarations
      //## begin SCNUt_Mesh2TriScene%3C2BD25F0321.protected preserve=yes
      //## end SCNUt_Mesh2TriScene%3C2BD25F0321.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_Mesh2TriScene%3C2BD25F0321.private preserve=yes
      //## end SCNUt_Mesh2TriScene%3C2BD25F0321.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_Mesh2TriScene%3C2BD25F0321.implementation preserve=yes
      //## end SCNUt_Mesh2TriScene%3C2BD25F0321.implementation

};

//## begin SCNUt_Mesh2TriScene%3C2BD25F0321.postscript preserve=yes
//## end SCNUt_Mesh2TriScene%3C2BD25F0321.postscript

// Class SCNUt_Mesh2TriScene 

//## begin module%3C2BD25F0321.epilog preserve=yes
//## end module%3C2BD25F0321.epilog


#endif
