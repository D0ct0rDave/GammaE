//## begin module%3BB6430003E6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB6430003E6.cm

//## begin module%3BB6430003E6.cp preserve=no
//## end module%3BB6430003E6.cp

//## Module: CSoundLayer%3BB6430003E6; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSoundLayer.h

#ifndef CSoundLayer_h
#define CSoundLayer_h 1

//## begin module%3BB6430003E6.additionalIncludes preserve=no
//## end module%3BB6430003E6.additionalIncludes

//## begin module%3BB6430003E6.includes preserve=yes
//## end module%3BB6430003E6.includes

// CSample
#include "SoundSystem\Sound\CSample.h"
//## begin module%3BB6430003E6.additionalDeclarations preserve=yes
//## end module%3BB6430003E6.additionalDeclarations


//## begin CSoundLayer%3BB6430003E6.preface preserve=yes
//## end CSoundLayer%3BB6430003E6.preface

//## Class: CSoundLayer%3BB6430003E6
//## Category: SoundSystem::Sound%3B76DE2401DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSoundLayer 
{
  //## begin CSoundLayer%3BB6430003E6.initialDeclarations preserve=yes
  //## end CSoundLayer%3BB6430003E6.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundLayer();

    //## Destructor (generated)
      ~CSoundLayer();

    // Data Members for Class Attributes

      //## Attribute: bLoop%3BB8E21400E9
      //## begin CSoundLayer::bLoop%3BB8E21400E9.attr preserve=no  public: bool {UA} 
      bool bLoop;
      //## end CSoundLayer::bLoop%3BB8E21400E9.attr

    // Data Members for Associations

      //## Association: SoundSystem::Sound::<unnamed>%3BB643DE0088
      //## Role: CSoundLayer::poSample%3BB643DE01AC
      //## begin CSoundLayer::poSample%3BB643DE01AC.role preserve=no  public: CSample { -> RHAN}
      CSample *poSample;
      //## end CSoundLayer::poSample%3BB643DE01AC.role

    // Additional Public Declarations
      //## begin CSoundLayer%3BB6430003E6.public preserve=yes
      //## end CSoundLayer%3BB6430003E6.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundLayer%3BB6430003E6.protected preserve=yes
      //## end CSoundLayer%3BB6430003E6.protected

  private:
    // Additional Private Declarations
      //## begin CSoundLayer%3BB6430003E6.private preserve=yes
      //## end CSoundLayer%3BB6430003E6.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundLayer%3BB6430003E6.implementation preserve=yes
      //## end CSoundLayer%3BB6430003E6.implementation

};

//## begin CSoundLayer%3BB6430003E6.postscript preserve=yes
//## end CSoundLayer%3BB6430003E6.postscript

// Class CSoundLayer 

//## begin module%3BB6430003E6.epilog preserve=yes
//## end module%3BB6430003E6.epilog


#endif
