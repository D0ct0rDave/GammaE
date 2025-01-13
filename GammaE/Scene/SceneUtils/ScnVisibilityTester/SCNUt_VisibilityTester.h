//## begin module%3CD50F090024.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD50F090024.cm

//## begin module%3CD50F090024.cp preserve=no
//## end module%3CD50F090024.cp

//## Module: SCNUt_VisibilityTester%3CD50F090024; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnVisibilityTester\SCNUt_VisibilityTester.h

#ifndef SCNUt_VisibilityTester_h
#define SCNUt_VisibilityTester_h 1

//## begin module%3CD50F090024.additionalIncludes preserve=no
//## end module%3CD50F090024.additionalIncludes

//## begin module%3CD50F090024.includes preserve=yes
//## end module%3CD50F090024.includes

// GammaE_Math
#include "Math\GammaE_Math.h"
// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3CD50F090024.additionalDeclarations preserve=yes
//## end module%3CD50F090024.additionalDeclarations


//## begin SCNUt_VisibilityTester%3CD50F090024.preface preserve=yes
//## end SCNUt_VisibilityTester%3CD50F090024.preface

//## Class: SCNUt_VisibilityTester%3CD50F090024
//## Category: Scene::SceneUtils::ScnVisibilityTester%3CD50EED0223
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CD50F48016F;SCNUt_TriScene { -> }
//## Uses: <unnamed>%3CD5101303AC;GammaE_Math { -> }
//## Uses: <unnamed>%3CD5116E0379;SCNUt_TransformTriScene { -> }

class SCNUt_VisibilityTester 
{
  //## begin SCNUt_VisibilityTester%3CD50F090024.initialDeclarations preserve=yes
  //## end SCNUt_VisibilityTester%3CD50F090024.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_VisibilityTester();

    //## Destructor (generated)
      ~SCNUt_VisibilityTester();


    //## Other Operations (specified)
      //## Operation: bIsVisible%1020591281
      bool bIsVisible (SCNUt_TriScene* _poTScn, CVect3& _roIni, CVect3& _roEnd);

    // Additional Public Declarations
      //## begin SCNUt_VisibilityTester%3CD50F090024.public preserve=yes
      //## end SCNUt_VisibilityTester%3CD50F090024.public

  protected:

    //## Other Operations (specified)
      //## Operation: bRayToPos%1020591284
      bool bRayToPos (CRay& _roRay, CVect3& _roPos, SCNUt_TriScene* _poTScn);

    // Additional Protected Declarations
      //## begin SCNUt_VisibilityTester%3CD50F090024.protected preserve=yes
      //## end SCNUt_VisibilityTester%3CD50F090024.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_VisibilityTester%3CD50F090024.private preserve=yes
      //## end SCNUt_VisibilityTester%3CD50F090024.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_VisibilityTester%3CD50F090024.implementation preserve=yes
      //## end SCNUt_VisibilityTester%3CD50F090024.implementation

};

//## begin SCNUt_VisibilityTester%3CD50F090024.postscript preserve=yes
//## end SCNUt_VisibilityTester%3CD50F090024.postscript

// Class SCNUt_VisibilityTester 

//## begin module%3CD50F090024.epilog preserve=yes
//## end module%3CD50F090024.epilog


#endif
