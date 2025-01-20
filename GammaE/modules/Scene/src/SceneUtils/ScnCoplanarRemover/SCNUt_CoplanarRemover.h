//## begin module%3CD1BDE6026D.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CD1BDE6026D.cm

//## begin module%3CD1BDE6026D.cp preserve=no
//## end module%3CD1BDE6026D.cp

//## Module: SCNUt_CoplanarRemover%3CD1BDE6026D; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\SceneUtils\ScnCoplanarRemover\SCNUt_CoplanarRemover.h

#ifndef SCNUt_CoplanarRemover_h
#define SCNUt_CoplanarRemover_h 1

//## begin module%3CD1BDE6026D.additionalIncludes preserve=no
//## end module%3CD1BDE6026D.additionalIncludes

//## begin module%3CD1BDE6026D.includes preserve=yes
//## end module%3CD1BDE6026D.includes

// SCNUt_TriScene
#include "Scene\SceneUtils\SCNUt_TriScene.h"
//## begin module%3CD1BDE6026D.additionalDeclarations preserve=yes
//## end module%3CD1BDE6026D.additionalDeclarations


//## begin SCNUt_CoplanarRemover%3CD1BDE6026D.preface preserve=yes
//## end SCNUt_CoplanarRemover%3CD1BDE6026D.preface

//## Class: SCNUt_CoplanarRemover%3CD1BDE6026D
//## Category: Scene::SceneUtils::ScnCoplanarRemover%3CD1BDD5031C
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3CD30C2402C3;SCNUt_TriScene { -> }

class SCNUt_CoplanarRemover 
{
  //## begin SCNUt_CoplanarRemover%3CD1BDE6026D.initialDeclarations preserve=yes
  //## end SCNUt_CoplanarRemover%3CD1BDE6026D.initialDeclarations

  public:
    //## Constructors (generated)
      SCNUt_CoplanarRemover();

    //## Destructor (generated)
      ~SCNUt_CoplanarRemover();


    //## Other Operations (specified)
      //## Operation: RemoveCoplanars%1020464099
      SCNUt_TriScene * RemoveCoplanars (SCNUt_TriScene *_poScn);

    // Additional Public Declarations
      //## begin SCNUt_CoplanarRemover%3CD1BDE6026D.public preserve=yes
      //## end SCNUt_CoplanarRemover%3CD1BDE6026D.public

  protected:
    // Additional Protected Declarations
      //## begin SCNUt_CoplanarRemover%3CD1BDE6026D.protected preserve=yes
      //## end SCNUt_CoplanarRemover%3CD1BDE6026D.protected

  private:
    // Additional Private Declarations
      //## begin SCNUt_CoplanarRemover%3CD1BDE6026D.private preserve=yes
      //## end SCNUt_CoplanarRemover%3CD1BDE6026D.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin SCNUt_CoplanarRemover%3CD1BDE6026D.implementation preserve=yes
      //## end SCNUt_CoplanarRemover%3CD1BDE6026D.implementation

};

//## begin SCNUt_CoplanarRemover%3CD1BDE6026D.postscript preserve=yes
//## end SCNUt_CoplanarRemover%3CD1BDE6026D.postscript

// Class SCNUt_CoplanarRemover 

//## begin module%3CD1BDE6026D.epilog preserve=yes
//## end module%3CD1BDE6026D.epilog


#endif
