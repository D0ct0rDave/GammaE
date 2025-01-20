//## begin module%3C3082720118.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3082720118.cm

//## begin module%3C3082720118.cp preserve=no
//## end module%3C3082720118.cp

//## Module: SCNUt_EdgeBuilder%3C3082720118; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_EdgeBuilder.h

#ifndef SCNUt_EdgeBuilder_h
#define SCNUt_EdgeBuilder_h 1

//## begin module%3C3082720118.additionalIncludes preserve=no
//## end module%3C3082720118.additionalIncludes

//## begin module%3C3082720118.includes preserve=yes
//## end module%3C3082720118.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// SCNUt_Mesh2TriScene
#include "Scene\SceneUtils\Mesh2TriScn\SCNUt_Mesh2TriScene.h"
// SCNUt_EdgeList
#include "Scene\SceneUtils\ScnStripifier\SCNUt_EdgeList.h"
// SCNUt_MeshCompacter
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshCompacter.h"
//## begin module%3C3082720118.additionalDeclarations preserve=yes
//## end module%3C3082720118.additionalDeclarations


//## begin SCNUt_EdgeBuilder%3C3082720118.preface preserve=yes
//## end SCNUt_EdgeBuilder%3C3082720118.preface

//## Class: SCNUt_EdgeBuilder%3C3082720118
//## Category: Scene::SceneUtils::ScnStripifier%3C308123036F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C3082960033;SCNUt_EdgeList { -> }
//## Uses: <unnamed>%3C30851100C2;GammaE_E3D { -> }
//## Uses: <unnamed>%3C3087500282;SCNUt_MeshCompacter { -> }
//## Uses: <unnamed>%3C3087FE0340;SCNUt_Mesh2TriScene { -> }

class SCNUt_EdgeBuilder 
{
  //## begin SCNUt_EdgeBuilder%3C3082720118.initialDeclarations preserve=yes
  //## end SCNUt_EdgeBuilder%3C3082720118.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_EdgeBuilder();

    //## Destructor (generated)
      ~SCNUt_EdgeBuilder();


    //## Other Operations (specified)
      //## Operation: poBuild%1009811893
      SCNUt_EdgeList* poBuild (CMesh* _poMesh, CMesh *&_rpoOutMesh);

      //## Operation: poBuild_FromIndexedTriMesh%1009811896
      SCNUt_EdgeList* poBuild_FromIndexedTriMesh (CMesh* _poMesh);

    // Additional Public Declarations
      //## begin SCNUt_EdgeBuilder%3C3082720118.public preserve=yes
      //## end SCNUt_EdgeBuilder%3C3082720118.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_EdgeBuilder%3C3082720118.protected preserve=yes
      //## end SCNUt_EdgeBuilder%3C3082720118.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_EdgeBuilder%3C3082720118.private preserve=yes
      //## end SCNUt_EdgeBuilder%3C3082720118.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_EdgeBuilder%3C3082720118.implementation preserve=yes
      //## end SCNUt_EdgeBuilder%3C3082720118.implementation

};

//## begin SCNUt_EdgeBuilder%3C3082720118.postscript preserve=yes
//## end SCNUt_EdgeBuilder%3C3082720118.postscript

// Class SCNUt_EdgeBuilder 

//## begin module%3C3082720118.epilog preserve=yes
//## end module%3C3082720118.epilog


#endif
