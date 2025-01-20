//## begin module%3C3081310184.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C3081310184.cm

//## begin module%3C3081310184.cp preserve=no
//## end module%3C3081310184.cp

//## Module: SCNUt_Stripifier%3C3081310184; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnStripifier\SCNUt_Stripifier.h

#ifndef SCNUt_Stripifier_h
#define SCNUt_Stripifier_h 1

//## begin module%3C3081310184.additionalIncludes preserve=no
//## end module%3C3081310184.additionalIncludes

//## begin module%3C3081310184.includes preserve=yes
//## end module%3C3081310184.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_EdgeBuilder
#include "Scene\SceneUtils\ScnStripifier\SCNUt_EdgeBuilder.h"
// SCNUt_AdjTriListBuilder
#include "Scene\SceneUtils\ScnStripifier\SCNUt_AdjTriListBuilder.h"
// SCNUt_MeshGenerator
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MeshGenerator.h"
//## begin module%3C3081310184.additionalDeclarations preserve=yes
//## end module%3C3081310184.additionalDeclarations


//## begin SCNUt_Stripifier%3C3081310184.preface preserve=yes
//## end SCNUt_Stripifier%3C3081310184.preface

//## Class: SCNUt_Stripifier%3C3081310184
//## Category: Scene::SceneUtils::ScnStripifier%3C308123036F
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C30819D02C0;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C30819F02AF;SCNUt_MeshGenerator { -> }
//## Uses: <unnamed>%3C30829B02D9;SCNUt_EdgeBuilder { -> }
//## Uses: <unnamed>%3C3084DB0205;GammaE_E3D { -> }
//## Uses: <unnamed>%3C321DB600C2;SCNUt_AdjTriListBuilder { -> }

class SCNUt_Stripifier 
{
  //## begin SCNUt_Stripifier%3C3081310184.initialDeclarations preserve=yes
  //## end SCNUt_Stripifier%3C3081310184.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_Stripifier();

    //## Destructor (generated)
      ~SCNUt_Stripifier();


    //## Other Operations (specified)
      //## Operation: poStripifyMesh%1009811891
      CMesh * poStripifyMesh (CMesh *_poMesh);

      //## Operation: poStripifyTriScene%1009811892
      CMesh * poStripifyTriScene (SCNUt_TriScene *_poTS);

      //## Operation: iGetNonCommonVertex%1009920812
      int iGetNonCommonVertex (CMesh* _SrcMesh, int _iSrcTri, int _iDstTri);

    // Additional Public Declarations
      //## begin SCNUt_Stripifier%3C3081310184.public preserve=yes
      //## end SCNUt_Stripifier%3C3081310184.public

  protected:

    //## Other Operations (specified)
      //## Operation: poStripify%1009920807
      CMesh * poStripify (CMesh* _poMesh, SCNUt_AdjTriList* _poATL);

      //## Operation: iSelectStartingTri%1009920808
      int iSelectStartingTri (SCNUt_AdjTriList *_poATL);

      //## Operation: iSelectBestNeigh%1009920809
      int iSelectBestNeigh (SCNUt_AdjTriList *_poATL, int _iSrcTri);

    // Additional Protected Declarations
      //## begin SCNUt_Stripifier%3C3081310184.protected preserve=yes
      //## end SCNUt_Stripifier%3C3081310184.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_Stripifier%3C3081310184.private preserve=yes
      //## end SCNUt_Stripifier%3C3081310184.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_Stripifier%3C3081310184.implementation preserve=yes
      //## end SCNUt_Stripifier%3C3081310184.implementation

};

//## begin SCNUt_Stripifier%3C3081310184.postscript preserve=yes
//## end SCNUt_Stripifier%3C3081310184.postscript

// Class SCNUt_Stripifier 

//## begin module%3C3081310184.epilog preserve=yes
//## end module%3C3081310184.epilog


#endif
