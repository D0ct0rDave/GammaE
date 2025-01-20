//## begin module%3AC0F8A201FE.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3AC0F8A201FE.cm

//## begin module%3AC0F8A201FE.cp preserve=no
//## end module%3AC0F8A201FE.cp

//## Module: C3DLoader%3AC0F8A201FE; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\3D_Loaders\C3DLoader.h

#ifndef C3DLoader_h
#define C3DLoader_h 1

//## begin module%3AC0F8A201FE.additionalIncludes preserve=no
//## end module%3AC0F8A201FE.additionalIncludes

//## begin module%3AC0F8A201FE.includes preserve=yes
//## end module%3AC0F8A201FE.includes

// GammaE_E3D
#include "E3D\GammaE_E3D.h"
// CObject3D
#include "Scene\CObject3D.h"
//## begin module%3AC0F8A201FE.additionalDeclarations preserve=yes
//## end module%3AC0F8A201FE.additionalDeclarations


//## begin C3DLoader%3AC0F8A201FE.preface preserve=yes
//## end C3DLoader%3AC0F8A201FE.preface

//## Class: C3DLoader%3AC0F8A201FE
//## Category: Scene::3D_Loaders%3AB9109B00E6
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1BF41802C9;GammaE_E3D { -> }
//## Uses: <unnamed>%3CB84F5602DD;CObject3D { -> }

class C3DLoader 
{
  //## begin C3DLoader%3AC0F8A201FE.initialDeclarations preserve=yes
  //## end C3DLoader%3AC0F8A201FE.initialDeclarations

  public:
    //## Constructors (generated)
      C3DLoader();

    //## Destructor (generated)
      ~C3DLoader();


    //## Other Operations (specified)
      //## Operation: pLoad%985725077
      virtual CObject3D * pLoad (char* Filename) = 0;

    // Additional Public Declarations
      //## begin C3DLoader%3AC0F8A201FE.public preserve=yes
      //## end C3DLoader%3AC0F8A201FE.public

  protected:
    // Additional Protected Declarations
      //## begin C3DLoader%3AC0F8A201FE.protected preserve=yes
      //## end C3DLoader%3AC0F8A201FE.protected

  private:
    // Additional Private Declarations
      //## begin C3DLoader%3AC0F8A201FE.private preserve=yes
      //## end C3DLoader%3AC0F8A201FE.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin C3DLoader%3AC0F8A201FE.implementation preserve=yes
      //## end C3DLoader%3AC0F8A201FE.implementation

};

//## begin C3DLoader%3AC0F8A201FE.postscript preserve=yes
//## end C3DLoader%3AC0F8A201FE.postscript

// Class C3DLoader 

//## begin module%3AC0F8A201FE.epilog preserve=yes
//## end module%3AC0F8A201FE.epilog


#endif
