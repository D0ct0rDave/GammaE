//## begin module%3BB6466C0378.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB6466C0378.cm

//## begin module%3BB6466C0378.cp preserve=no
//## end module%3BB6466C0378.cp

//## Module: CSoundWH_Elem%3BB6466C0378; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSoundWH_Elem.h

#ifndef CSoundWH_Elem_h
#define CSoundWH_Elem_h 1

//## begin module%3BB6466C0378.additionalIncludes preserve=no
//## end module%3BB6466C0378.additionalIncludes

//## begin module%3BB6466C0378.includes preserve=yes
//## end module%3BB6466C0378.includes

// CSound
#include "SoundSystem\Sound\CSound.h"
//## begin module%3BB6466C0378.additionalDeclarations preserve=yes
//## end module%3BB6466C0378.additionalDeclarations


//## begin CSoundWH_Elem%3BB6466C0378.preface preserve=yes
//## end CSoundWH_Elem%3BB6466C0378.preface

//## Class: CSoundWH_Elem%3BB6466C0378
//## Category: SoundSystem::Sound%3B76DE2401DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSoundWH_Elem 
{
  //## begin CSoundWH_Elem%3BB6466C0378.initialDeclarations preserve=yes
  //## end CSoundWH_Elem%3BB6466C0378.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundWH_Elem();

    //## Destructor (generated)
      ~CSoundWH_Elem();

    // Data Members for Class Attributes

      //## Attribute: szSoundName%3BB6468101B5
      //## begin CSoundWH_Elem::szSoundName%3BB6468101B5.attr preserve=no  public: char[256] {UA} 
      char szSoundName[256];
      //## end CSoundWH_Elem::szSoundName%3BB6468101B5.attr

    // Data Members for Associations

      //## Association: SoundSystem::Sound::<unnamed>%3BB646F600FF
      //## Role: CSoundWH_Elem::poSound%3BB646F601D2
      //## begin CSoundWH_Elem::poSound%3BB646F601D2.role preserve=no  public: CSound { -> RHAN}
      CSound *poSound;
      //## end CSoundWH_Elem::poSound%3BB646F601D2.role

    // Additional Public Declarations
      //## begin CSoundWH_Elem%3BB6466C0378.public preserve=yes
      //## end CSoundWH_Elem%3BB6466C0378.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundWH_Elem%3BB6466C0378.protected preserve=yes
      //## end CSoundWH_Elem%3BB6466C0378.protected

  private:
    // Additional Private Declarations
      //## begin CSoundWH_Elem%3BB6466C0378.private preserve=yes
      //## end CSoundWH_Elem%3BB6466C0378.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundWH_Elem%3BB6466C0378.implementation preserve=yes
      //## end CSoundWH_Elem%3BB6466C0378.implementation

};

//## begin CSoundWH_Elem%3BB6466C0378.postscript preserve=yes
//## end CSoundWH_Elem%3BB6466C0378.postscript

// Class CSoundWH_Elem 

//## begin module%3BB6466C0378.epilog preserve=yes
//## end module%3BB6466C0378.epilog


#endif
