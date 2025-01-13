//## begin module%3B754DC701DD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B754DC701DD.cm

//## begin module%3B754DC701DD.cp preserve=no
//## end module%3B754DC701DD.cp

//## Module: CParticleSystem_Generic%3B754DC701DD; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Scene\ParticleSystems\CParticleSystem_Generic.h

#ifndef CParticleSystem_Generic_h
#define CParticleSystem_Generic_h 1

//## begin module%3B754DC701DD.additionalIncludes preserve=no
//## end module%3B754DC701DD.additionalIncludes

//## begin module%3B754DC701DD.includes preserve=yes
//## end module%3B754DC701DD.includes

// CParticleSystem
#include "Scene\ParticleSystems\CParticleSystem.h"
//## begin module%3B754DC701DD.additionalDeclarations preserve=yes
//## end module%3B754DC701DD.additionalDeclarations


//## begin CParticleSystem_Generic%3B754DC701DD.preface preserve=yes
//## end CParticleSystem_Generic%3B754DC701DD.preface

//## Class: CParticleSystem_Generic%3B754DC701DD
//## Category: Scene::ParticleSystems%3AABF9E8005A
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CParticleSystem_Generic : public CParticleSystem  //## Inherits: <unnamed>%3B754E0A00B7
{
  //## begin CParticleSystem_Generic%3B754DC701DD.initialDeclarations preserve=yes
  //## end CParticleSystem_Generic%3B754DC701DD.initialDeclarations

  public:
    //## Constructors (generated)
      CParticleSystem_Generic();

    //## Destructor (generated)
      virtual ~CParticleSystem_Generic();


    //## Other Operations (specified)
      //## Operation: SetColorsFact%1020210460
      void SetColorsFact (TFColor _oInitialColor, TFColor _oFactColor);

      //## Operation: SetSizeFact%1020210461
      void SetSizeFact (float _fSizeFact);

      //## Operation: SetEnergyFact%1020210462
      void SetEnergyFact (float _fInitialEnergy, float _fEnergyFact);

      //## Operation: SetSpeedFact%1020210463
      void SetSpeedFact (float _fSpeedFact);

    // Additional Public Declarations
      //## begin CParticleSystem_Generic%3B754DC701DD.public preserve=yes
      //## end CParticleSystem_Generic%3B754DC701DD.public

  protected:
    // Data Members for Class Attributes

      //## Attribute: RGBAFact%3B754E4E0213
      //## begin CParticleSystem_Generic::RGBAFact%3B754E4E0213.attr preserve=no  protected: CVect4 {UA} 
      CVect4 RGBAFact;
      //## end CParticleSystem_Generic::RGBAFact%3B754E4E0213.attr

      //## Attribute: RGBAInitialValue%3B754E63026E
      //## begin CParticleSystem_Generic::RGBAInitialValue%3B754E63026E.attr preserve=no  protected: CVect4 {UA} 
      CVect4 RGBAInitialValue;
      //## end CParticleSystem_Generic::RGBAInitialValue%3B754E63026E.attr

      //## Attribute: InitialSpeedFact%3B754F240239
      //## begin CParticleSystem_Generic::InitialSpeedFact%3B754F240239.attr preserve=no  protected: CVect3 {UA} 
      CVect3 InitialSpeedFact;
      //## end CParticleSystem_Generic::InitialSpeedFact%3B754F240239.attr

      //## Attribute: fPEnergyFact%3B76D10A0201
      //## begin CParticleSystem_Generic::fPEnergyFact%3B76D10A0201.attr preserve=no  protected: float {UA} 0
      float fPEnergyFact;
      //## end CParticleSystem_Generic::fPEnergyFact%3B76D10A0201.attr

      //## Attribute: fPInitialEnergyFact%3B76D10A0215
      //## begin CParticleSystem_Generic::fPInitialEnergyFact%3B76D10A0215.attr preserve=no  protected: float {UA} 0
      float fPInitialEnergyFact;
      //## end CParticleSystem_Generic::fPInitialEnergyFact%3B76D10A0215.attr

      //## Attribute: fPInitialSpeedFact%3B76D10A0229
      //## begin CParticleSystem_Generic::fPInitialSpeedFact%3B76D10A0229.attr preserve=no  protected: float {UA} 0
      float fPInitialSpeedFact;
      //## end CParticleSystem_Generic::fPInitialSpeedFact%3B76D10A0229.attr

      //## Attribute: fPInitialSizeFact%3B76D10A023D
      //## begin CParticleSystem_Generic::fPInitialSizeFact%3B76D10A023D.attr preserve=no  protected: float {UA} 0
      float fPInitialSizeFact;
      //## end CParticleSystem_Generic::fPInitialSizeFact%3B76D10A023D.attr

    // Additional Protected Declarations
      //## begin CParticleSystem_Generic%3B754DC701DD.protected preserve=yes
      //## end CParticleSystem_Generic%3B754DC701DD.protected

  private:
    // Additional Private Declarations
      //## begin CParticleSystem_Generic%3B754DC701DD.private preserve=yes
      //## end CParticleSystem_Generic%3B754DC701DD.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CParticleSystem_Generic%3B754DC701DD.implementation preserve=yes
      //## end CParticleSystem_Generic%3B754DC701DD.implementation

};

//## begin CParticleSystem_Generic%3B754DC701DD.postscript preserve=yes
//## end CParticleSystem_Generic%3B754DC701DD.postscript

// Class CParticleSystem_Generic 

//## begin module%3B754DC701DD.epilog preserve=yes
//## end module%3B754DC701DD.epilog


#endif
