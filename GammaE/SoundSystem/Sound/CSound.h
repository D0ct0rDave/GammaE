//## begin module%3B76DF3D0334.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DF3D0334.cm

//## begin module%3B76DF3D0334.cp preserve=no
//## end module%3B76DF3D0334.cp

//## Module: CSound%3B76DF3D0334; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSound.h

#ifndef CSound_h
#define CSound_h 1

//## begin module%3B76DF3D0334.additionalIncludes preserve=no
//## end module%3B76DF3D0334.additionalIncludes

//## begin module%3B76DF3D0334.includes preserve=yes
//## end module%3B76DF3D0334.includes

// CSoundLayer
#include "SoundSystem\Sound\CSoundLayer.h"
//## begin module%3B76DF3D0334.additionalDeclarations preserve=yes
//## end module%3B76DF3D0334.additionalDeclarations


//## begin CSound%3B76DF3D0334.preface preserve=yes
//## end CSound%3B76DF3D0334.preface

//## Class: CSound%3B76DF3D0334
//## Category: SoundSystem::Sound%3B76DE2401DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSound 
{
  //## begin CSound%3B76DF3D0334.initialDeclarations preserve=yes
  //## end CSound%3B76DF3D0334.initialDeclarations

  public:
    //## Constructors (generated)
      CSound();

    //## Destructor (generated)
      ~CSound();


    //## Other Operations (specified)
      //## Operation: iAddLayer%1001802578
      int iAddLayer (CSoundLayer& _roSLayer);

      //## Operation: iAddLayer%1014992647
      int iAddLayer (bool _bLoop, CSample* _poSample);

    // Data Members for Class Attributes

      //## Attribute: iNumLayers%3BB6444503A8
      //## begin CSound::iNumLayers%3BB6444503A8.attr preserve=no  public: int {UA} 0
      int iNumLayers;
      //## end CSound::iNumLayers%3BB6444503A8.attr

    // Data Members for Associations

      //## Association: SoundSystem::Sound::<unnamed>%3C7F5D430202
      //## Role: CSound::poSLayer%3C7F5D4303E3
      //## begin CSound::poSLayer%3C7F5D4303E3.role preserve=no  public: CSoundLayer { -> RHAN}
      CSoundLayer *poSLayer;
      //## end CSound::poSLayer%3C7F5D4303E3.role

    // Additional Public Declarations
      //## begin CSound%3B76DF3D0334.public preserve=yes
      //## end CSound%3B76DF3D0334.public

  protected:
    // Additional Protected Declarations
      //## begin CSound%3B76DF3D0334.protected preserve=yes
      //## end CSound%3B76DF3D0334.protected

  private:
    // Additional Private Declarations
      //## begin CSound%3B76DF3D0334.private preserve=yes
      //## end CSound%3B76DF3D0334.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSound%3B76DF3D0334.implementation preserve=yes
      //## end CSound%3B76DF3D0334.implementation

};

//## begin CSound%3B76DF3D0334.postscript preserve=yes
//## end CSound%3B76DF3D0334.postscript

// Class CSound 

//## begin module%3B76DF3D0334.epilog preserve=yes
//## end module%3B76DF3D0334.epilog


#endif
