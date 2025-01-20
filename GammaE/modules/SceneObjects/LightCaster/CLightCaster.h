//## begin module%3CB94617013A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CB94617013A.cm

//## begin module%3CB94617013A.cp preserve=no
//## end module%3CB94617013A.cp

//## Module: CLightCaster%3CB94617013A; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SceneObjects\LightCaster\CLightCaster.h

#ifndef CLightCaster_h
#define CLightCaster_h 1

//## begin module%3CB94617013A.additionalIncludes preserve=no
//## end module%3CB94617013A.additionalIncludes

//## begin module%3CB94617013A.includes preserve=yes
//## end module%3CB94617013A.includes

// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"
//## begin module%3CB94617013A.additionalDeclarations preserve=yes
//## end module%3CB94617013A.additionalDeclarations


//## begin CLightCaster%3CB94617013A.preface preserve=yes
//## end CLightCaster%3CB94617013A.preface

//## Class: CLightCaster%3CB94617013A
//## Category: SceneObjects::LightCaster%3CB945F403CF
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CLightCaster : public CObject3D_Leaf  //## Inherits: <unnamed>%3CB94726027B
{
  //## begin CLightCaster%3CB94617013A.initialDeclarations preserve=yes
  //## end CLightCaster%3CB94617013A.initialDeclarations

  public:
    //## Constructors (generated)
      CLightCaster();

    //## Destructor (generated)
      ~CLightCaster();


    //## Other Operations (specified)
      //## Operation: SetupLight%1018775600
      void SetupLight (CVect3& _roLightPos, CVect3 _roLightDir);

    // Additional Public Declarations
      //## begin CLightCaster%3CB94617013A.public preserve=yes
      //## end CLightCaster%3CB94617013A.public

  protected:
    // Additional Protected Declarations
      //## begin CLightCaster%3CB94617013A.protected preserve=yes
      //## end CLightCaster%3CB94617013A.protected

  private:
    // Additional Private Declarations
      //## begin CLightCaster%3CB94617013A.private preserve=yes
      //## end CLightCaster%3CB94617013A.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CLightCaster%3CB94617013A.implementation preserve=yes
      //## end CLightCaster%3CB94617013A.implementation

};

//## begin CLightCaster%3CB94617013A.postscript preserve=yes
//## end CLightCaster%3CB94617013A.postscript

// Class CLightCaster 

//## begin module%3CB94617013A.epilog preserve=yes
//## end module%3CB94617013A.epilog


#endif
