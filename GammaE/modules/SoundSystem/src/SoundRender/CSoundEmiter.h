//## begin module%3C7F8CFC012E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7F8CFC012E.cm

//## begin module%3C7F8CFC012E.cp preserve=no
//## end module%3C7F8CFC012E.cp

//## Module: CSoundEmiter%3C7F8CFC012E; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\CSoundEmiter.h

#ifndef CSoundEmiter_h
#define CSoundEmiter_h 1

//## begin module%3C7F8CFC012E.additionalIncludes preserve=no
//## end module%3C7F8CFC012E.additionalIncludes

//## begin module%3C7F8CFC012E.includes preserve=yes
//## end module%3C7F8CFC012E.includes

// CSoundEntity
#include "SoundSystem\SoundRender\CSoundEntity.h"
// CSoundMixPars
#include "SoundSystem\SoundRender\SoundMixer\CSoundMixPars.h"
//## begin module%3C7F8CFC012E.additionalDeclarations preserve=yes
//## end module%3C7F8CFC012E.additionalDeclarations


//## begin CSoundEmiter%3C7F8CFC012E.preface preserve=yes
//## end CSoundEmiter%3C7F8CFC012E.preface

//## Class: CSoundEmiter%3C7F8CFC012E
//## Category: SoundSystem::SoundRender%3B76FFA20393
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSoundEmiter : public CSoundEntity  //## Inherits: <unnamed>%3C7F8EC60303
{
  //## begin CSoundEmiter%3C7F8CFC012E.initialDeclarations preserve=yes
  //## end CSoundEmiter%3C7F8CFC012E.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundEmiter();

    //## Destructor (generated)
      ~CSoundEmiter();


    //## Other Operations (specified)
      //## Operation: Unlock%1015169087
      void Unlock ();

    // Data Members for Class Attributes

      //## Attribute: fRadius%3C7F8CFC0130
      //## begin CSoundEmiter::fRadius%3C7F8CFC0130.attr preserve=no  public: float {UA} 
      float fRadius;
      //## end CSoundEmiter::fRadius%3C7F8CFC0130.attr

      //## Attribute: fVol%3C7F8CFC0132
      //## begin CSoundEmiter::fVol%3C7F8CFC0132.attr preserve=no  public: float {UA} 
      float fVol;
      //## end CSoundEmiter::fVol%3C7F8CFC0132.attr

      //## Attribute: iType%3C7F8E56026C
      //## begin CSoundEmiter::iType%3C7F8E56026C.attr preserve=no  public: int {UA} 
      int iType;
      //## end CSoundEmiter::iType%3C7F8E56026C.attr

      //## Attribute: Dir%3C828B350264
      //## begin CSoundEmiter::Dir%3C828B350264.attr preserve=no  public: CVect3 {UA} 
      CVect3 Dir;
      //## end CSoundEmiter::Dir%3C828B350264.attr

    // Data Members for Associations

      //## Association: SoundSystem::SoundRender::<unnamed>%3C7F90B90148
      //## Role: CSoundEmiter::oSMP%3C7F90B9026B
      //## begin CSoundEmiter::oSMP%3C7F90B9026B.role preserve=no  public: CSoundMixPars { -> VHAN}
      CSoundMixPars oSMP;
      //## end CSoundEmiter::oSMP%3C7F90B9026B.role

    // Additional Public Declarations
      //## begin CSoundEmiter%3C7F8CFC012E.public preserve=yes
      //## end CSoundEmiter%3C7F8CFC012E.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundEmiter%3C7F8CFC012E.protected preserve=yes
      //## end CSoundEmiter%3C7F8CFC012E.protected

  private:
    // Additional Private Declarations
      //## begin CSoundEmiter%3C7F8CFC012E.private preserve=yes
      //## end CSoundEmiter%3C7F8CFC012E.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundEmiter%3C7F8CFC012E.implementation preserve=yes
      //## end CSoundEmiter%3C7F8CFC012E.implementation

};

//## begin CSoundEmiter%3C7F8CFC012E.postscript preserve=yes
//## end CSoundEmiter%3C7F8CFC012E.postscript

// Class CSoundEmiter 

//## begin module%3C7F8CFC012E.epilog preserve=yes
//## end module%3C7F8CFC012E.epilog


#endif
