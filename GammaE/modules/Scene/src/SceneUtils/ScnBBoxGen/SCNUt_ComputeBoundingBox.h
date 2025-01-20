//## begin module%3BE874C8016B.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BE874C8016B.cm

//## begin module%3BE874C8016B.cp preserve=no
//## end module%3BE874C8016B.cp

//## Module: SCNUt_ComputeBoundingBox%3BE874C8016B; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnBBoxGen\SCNUt_ComputeBoundingBox.h

#ifndef SCNUt_ComputeBoundingBox_h
#define SCNUt_ComputeBoundingBox_h 1

//## begin module%3BE874C8016B.additionalIncludes preserve=no
//## end module%3BE874C8016B.additionalIncludes

//## begin module%3BE874C8016B.includes preserve=yes
//## end module%3BE874C8016B.includes

// CBoundingBox
#include "E3D\BoundingVolume\CBoundingBox.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3BE874C8016B.additionalDeclarations preserve=yes
//## end module%3BE874C8016B.additionalDeclarations


//## begin SCNUt_ComputeBoundingBox%3BE874C8016B.preface preserve=yes
//## end SCNUt_ComputeBoundingBox%3BE874C8016B.preface

//## Class: SCNUt_ComputeBoundingBox%3BE874C8016B
//## Category: Scene::SceneUtils::ScnBBoxGen%3C76D73401F8
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BE874F8021E;CBoundingBox { -> }
//## Uses: <unnamed>%3BE875E00023;SCNUt_TriScene { -> }

class SCNUt_ComputeBoundingBox 
{
  //## begin SCNUt_ComputeBoundingBox%3BE874C8016B.initialDeclarations preserve=yes
  //## end SCNUt_ComputeBoundingBox%3BE874C8016B.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_ComputeBoundingBox();

    //## Destructor (generated)
      ~SCNUt_ComputeBoundingBox();


    //## Other Operations (specified)
      //## Operation: poComputeBoundingBox%1005085993
      CBoundingBox * poComputeBoundingBox (SCNUt_TriScene* _poScene);

    // Additional Public Declarations
      //## begin SCNUt_ComputeBoundingBox%3BE874C8016B.public preserve=yes
      //## end SCNUt_ComputeBoundingBox%3BE874C8016B.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_ComputeBoundingBox%3BE874C8016B.protected preserve=yes
      //## end SCNUt_ComputeBoundingBox%3BE874C8016B.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_ComputeBoundingBox%3BE874C8016B.private preserve=yes
      //## end SCNUt_ComputeBoundingBox%3BE874C8016B.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_ComputeBoundingBox%3BE874C8016B.implementation preserve=yes
      //## end SCNUt_ComputeBoundingBox%3BE874C8016B.implementation

};

//## begin SCNUt_ComputeBoundingBox%3BE874C8016B.postscript preserve=yes
//## end SCNUt_ComputeBoundingBox%3BE874C8016B.postscript

// Class SCNUt_ComputeBoundingBox 

//## begin module%3BE874C8016B.epilog preserve=yes
//## end module%3BE874C8016B.epilog


#endif
