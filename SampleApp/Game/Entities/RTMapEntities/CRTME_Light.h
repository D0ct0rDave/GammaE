//## begin module%3CDED98200C6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3CDED98200C6.cm

//## begin module%3CDED98200C6.cp preserve=no
//## end module%3CDED98200C6.cp

//## Module: CRTME_Light%3CDED98200C6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Game\Entities\RTMapEntities\CRTME_Light.h

#ifndef CRTME_Light_h
#define CRTME_Light_h 1

//## begin module%3CDED98200C6.additionalIncludes preserve=no
//## end module%3CDED98200C6.additionalIncludes

//## begin module%3CDED98200C6.includes preserve=yes
//## end module%3CDED98200C6.includes

// CRTME_Target
#include "Game\Entities\RTMapEntities\CRTME_Target.h"
//## begin module%3CDED98200C6.additionalDeclarations preserve=yes
//## end module%3CDED98200C6.additionalDeclarations


//## begin CRTME_Light%3CDED98200C6.preface preserve=yes
//## end CRTME_Light%3CDED98200C6.preface

//## Class: CRTME_Light%3CDED98200C6
//## Category: Game::Entities::RTMapEntities%3CDE40EE01C2
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CRTME_Light : public CRTME_Target  //## Inherits: <unnamed>%3CDED9D0026C
{
  //## begin CRTME_Light%3CDED98200C6.initialDeclarations preserve=yes
  //## end CRTME_Light%3CDED98200C6.initialDeclarations

  public:
    //## Constructors (generated)
      CRTME_Light();

    //## Destructor (generated)
      ~CRTME_Light();


    //## Other Operations (specified)
      //## Operation: Think%1021237865
      virtual void Think (float _fDelta);

      //## Operation: Init%1021237872
      void Init (CMapEnt_Light* _poLInfo);

    // Data Members for Class Attributes

      //## Attribute: poSwitch%3CDED9E201C8
      //## begin CRTME_Light::poSwitch%3CDED9E201C8.attr preserve=no  public: CObject3D_Mux * {UA} NULL
      CObject3D_Mux *poSwitch;
      //## end CRTME_Light::poSwitch%3CDED9E201C8.attr

      //## Attribute: poLightInfo%3CDEF83101D9
      //## begin CRTME_Light::poLightInfo%3CDEF83101D9.attr preserve=no  public: CMapEnt_Light* {UA} NULL
      CMapEnt_Light* poLightInfo;
      //## end CRTME_Light::poLightInfo%3CDEF83101D9.attr

    // Additional Public Declarations
      //## begin CRTME_Light%3CDED98200C6.public preserve=yes
      //## end CRTME_Light%3CDED98200C6.public

  protected:
    // Additional Protected Declarations
      //## begin CRTME_Light%3CDED98200C6.protected preserve=yes
      //## end CRTME_Light%3CDED98200C6.protected

  private:
    // Additional Private Declarations
      //## begin CRTME_Light%3CDED98200C6.private preserve=yes
      //## end CRTME_Light%3CDED98200C6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CRTME_Light%3CDED98200C6.implementation preserve=yes
      //## end CRTME_Light%3CDED98200C6.implementation

};

//## begin CRTME_Light%3CDED98200C6.postscript preserve=yes
//## end CRTME_Light%3CDED98200C6.postscript

// Class CRTME_Light 

//## begin module%3CDED98200C6.epilog preserve=yes
//## end module%3CDED98200C6.epilog


#endif
