//## begin module%3D11F886028B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3D11F886028B.cm

//## begin module%3D11F886028B.cp preserve=no
//## end module%3D11F886028B.cp

//## Module: SCNUt_PlanarMapper%3D11F886028B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnPlanarMapper\SCNUt_PlanarMapper.h

#ifndef SCNUt_PlanarMapper_h
#define SCNUt_PlanarMapper_h 1

//## begin module%3D11F886028B.additionalIncludes preserve=no
//## end module%3D11F886028B.additionalIncludes

//## begin module%3D11F886028B.includes preserve=yes
//## end module%3D11F886028B.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
// SCNUt_TransformTriScene
#include "Scene\SceneUtils\TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_ComputeBoundingBox
#include "Scene\SceneUtils\ScnBBoxGen\SCNUt_ComputeBoundingBox.h"
//## begin module%3D11F886028B.additionalDeclarations preserve=yes
//## end module%3D11F886028B.additionalDeclarations


//## begin SCNUt_PlanarMapper%3D11F886028B.preface preserve=yes
//## end SCNUt_PlanarMapper%3D11F886028B.preface

//## Class: SCNUt_PlanarMapper%3D11F886028B
//## Category: Scene::SceneUtils::ScnPlanarMapper%3D11F87B0253
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3D11F8CA0166;SCNUt_TransformTriScene { -> }
//## Uses: <unnamed>%3D11F8CD0192;SCNUt_ComputeBoundingBox { -> }
//## Uses: <unnamed>%3D11F8D702AF;SCNUt_TriScene { -> }

class SCNUt_PlanarMapper 
{
  //## begin SCNUt_PlanarMapper%3D11F886028B.initialDeclarations preserve=yes
  //## end SCNUt_PlanarMapper%3D11F886028B.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_PlanarMapper();

    //## Destructor (generated)
      ~SCNUt_PlanarMapper();


    //## Other Operations (specified)
      //## Operation: PlanarMap%1024588005
      void PlanarMap (SCNUt_TriScene& _roTriScn);

    // Additional Public Declarations
      //## begin SCNUt_PlanarMapper%3D11F886028B.public preserve=yes
      //## end SCNUt_PlanarMapper%3D11F886028B.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_PlanarMapper%3D11F886028B.protected preserve=yes
      //## end SCNUt_PlanarMapper%3D11F886028B.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_PlanarMapper%3D11F886028B.private preserve=yes
      //## end SCNUt_PlanarMapper%3D11F886028B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_PlanarMapper%3D11F886028B.implementation preserve=yes
      //## end SCNUt_PlanarMapper%3D11F886028B.implementation

};

//## begin SCNUt_PlanarMapper%3D11F886028B.postscript preserve=yes
//## end SCNUt_PlanarMapper%3D11F886028B.postscript

// Class SCNUt_PlanarMapper 

//## begin module%3D11F886028B.epilog preserve=yes
//## end module%3D11F886028B.epilog


#endif
