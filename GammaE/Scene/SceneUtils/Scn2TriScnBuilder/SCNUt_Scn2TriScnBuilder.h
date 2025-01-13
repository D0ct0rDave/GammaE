//## begin module%3C2BCDC90337.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BCDC90337.cm

//## begin module%3C2BCDC90337.cp preserve=no
//## end module%3C2BCDC90337.cp

//## Module: SCNUt_Scn2TriScnBuilder%3C2BCDC90337; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\Scn2TriScnBuilder\SCNUt_Scn2TriScnBuilder.h

#ifndef SCNUt_Scn2TriScnBuilder_h
#define SCNUt_Scn2TriScnBuilder_h 1

//## begin module%3C2BCDC90337.additionalIncludes preserve=no
//## end module%3C2BCDC90337.additionalIncludes

//## begin module%3C2BCDC90337.includes preserve=yes
//## end module%3C2BCDC90337.includes

// CObject3D
#include "Scene\CObject3D.h"
// CObject3D_Transf
#include "Scene\CObject3D_Transf.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "Scene\SceneUtils\ScnMeshGen\SCNUt_MaterialTable.h"
//## begin module%3C2BCDC90337.additionalDeclarations preserve=yes
//## end module%3C2BCDC90337.additionalDeclarations


//## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.preface preserve=yes
//## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.preface

//## Class: SCNUt_Scn2TriScnBuilder%3C2BCDC90337
//## Category: Scene::SceneUtils::Scn2TriScnBuilder%3C2BCD9500F7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2BCE0A0196;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C2BCE190332;CObject3D { -> }
//## Uses: <unnamed>%3C2BD38A01FF;SCNUt_Mesh2TriScene { -> }
//## Uses: <unnamed>%3C2BD39B01BD;SCNUt_TransformTriScene { -> }
//## Uses: <unnamed>%3C2CA49902A6;SCNUt_MaterialTable { -> }
//## Uses: <unnamed>%3C2CA6D8013A;SCNUt_TriSceneAccumulator { -> }
//## Uses: <unnamed>%3C2CA768030E;CObject3D_Leaf { -> }
//## Uses: <unnamed>%3C2CA78400B6;CObject3D_Node { -> }
//## Uses: <unnamed>%3C2CAA8A0040;CObject3D_BSPNode { -> }
//## Uses: <unnamed>%3CC29206015B;CObject3D_Transf { -> }

class SCNUt_Scn2TriScnBuilder 
{
  //## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.initialDeclarations preserve=yes
  //## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_Scn2TriScnBuilder();

    //## Destructor (generated)
      ~SCNUt_Scn2TriScnBuilder();


    //## Other Operations (specified)
      //## Operation: poBuild%1009496920
      SCNUt_TriScene * poBuild (CObject3D* _poScene, SCNUt_MaterialTable& _roMTable);

      //## Operation: poBuildRec%1009496922
      SCNUt_TriScene* poBuildRec (CObject3D* _poScene, CMatrix4x4 *_poMStack, int _iMPos, SCNUt_MaterialTable& _poMTab);

      //## Operation: poBuildMesh%1009496923
      SCNUt_TriScene* poBuildMesh (CMesh& _roMesh, int _iMat, CMatrix4x4& _roMat);

    // Additional Public Declarations
      //## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.public preserve=yes
      //## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.protected preserve=yes
      //## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.private preserve=yes
      //## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.implementation preserve=yes
      //## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.implementation

};

//## begin SCNUt_Scn2TriScnBuilder%3C2BCDC90337.postscript preserve=yes
//## end SCNUt_Scn2TriScnBuilder%3C2BCDC90337.postscript

// Class SCNUt_Scn2TriScnBuilder 

//## begin module%3C2BCDC90337.epilog preserve=yes
//## end module%3C2BCDC90337.epilog


#endif
