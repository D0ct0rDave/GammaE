//## begin module%3C2BD21F003A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C2BD21F003A.cm

//## begin module%3C2BD21F003A.cp preserve=no
//## end module%3C2BD21F003A.cp

//## Module: SCNUt_TransformTriScene%3C2BD21F003A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\TransfTriScn\SCNUt_TransformTriScene.h

#ifndef SCNUt_TransformTriScene_h
#define SCNUt_TransformTriScene_h 1

//## begin module%3C2BD21F003A.additionalIncludes preserve=no
//## end module%3C2BD21F003A.additionalIncludes

//## begin module%3C2BD21F003A.includes preserve=yes
//## end module%3C2BD21F003A.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// GammaE_Math
#include "Math\GammaE_Math.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3C2BD21F003A.additionalDeclarations preserve=yes
//## end module%3C2BD21F003A.additionalDeclarations


//## begin SCNUt_TransformTriScene%3C2BD21F003A.preface preserve=yes
//## end SCNUt_TransformTriScene%3C2BD21F003A.preface

//## Class: SCNUt_TransformTriScene%3C2BD21F003A
//## Category: Scene::SceneUtils::TransfTriScn%3C2BD2F50363
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C2BD316027A;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3C2BD31C00B6;GammaE_E3D { -> }
//## Uses: <unnamed>%3C2BD327008A;GammaE_Math { -> }

class SCNUt_TransformTriScene 
{
  //## begin SCNUt_TransformTriScene%3C2BD21F003A.initialDeclarations preserve=yes
  //## end SCNUt_TransformTriScene%3C2BD21F003A.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_TransformTriScene();

    //## Destructor (generated)
      ~SCNUt_TransformTriScene();


    //## Other Operations (specified)
      //## Operation: Transform%1009496921
      void Transform (SCNUt_TriScene& _roTriScn, CMatrix4x4& _roMatrix);

    // Additional Public Declarations
      //## begin SCNUt_TransformTriScene%3C2BD21F003A.public preserve=yes
      //## end SCNUt_TransformTriScene%3C2BD21F003A.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_TransformTriScene%3C2BD21F003A.protected preserve=yes
      //## end SCNUt_TransformTriScene%3C2BD21F003A.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_TransformTriScene%3C2BD21F003A.private preserve=yes
      //## end SCNUt_TransformTriScene%3C2BD21F003A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_TransformTriScene%3C2BD21F003A.implementation preserve=yes
      //## end SCNUt_TransformTriScene%3C2BD21F003A.implementation

};

//## begin SCNUt_TransformTriScene%3C2BD21F003A.postscript preserve=yes
//## end SCNUt_TransformTriScene%3C2BD21F003A.postscript

// Class SCNUt_TransformTriScene 

//## begin module%3C2BD21F003A.epilog preserve=yes
//## end module%3C2BD21F003A.epilog


#endif
