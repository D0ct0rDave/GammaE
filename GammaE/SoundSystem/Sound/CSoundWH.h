//## begin module%3B76DEFB00B8.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B76DEFB00B8.cm

//## begin module%3B76DEFB00B8.cp preserve=no
//## end module%3B76DEFB00B8.cp

//## Module: CSoundWH%3B76DEFB00B8; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\Sound\CSoundWH.h

#ifndef CSoundWH_h
#define CSoundWH_h 1

//## begin module%3B76DEFB00B8.additionalIncludes preserve=no
//## end module%3B76DEFB00B8.additionalIncludes

//## begin module%3B76DEFB00B8.includes preserve=yes
//## end module%3B76DEFB00B8.includes

// CSampleWH
#include "SoundSystem\Sound\CSampleWH.h"
// CSoundWH_Elem
#include "SoundSystem\Sound\CSoundWH_Elem.h"
//## begin module%3B76DEFB00B8.additionalDeclarations preserve=yes
//## end module%3B76DEFB00B8.additionalDeclarations


//## begin CSoundWH%3B76DEFB00B8.preface preserve=yes
//## end CSoundWH%3B76DEFB00B8.preface

//## Class: CSoundWH%3B76DEFB00B8
//## Category: SoundSystem::Sound%3B76DE2401DB
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3BB64FD1034E;CSampleWH { -> }

class CSoundWH 
{
  //## begin CSoundWH%3B76DEFB00B8.initialDeclarations preserve=yes
  //## end CSoundWH%3B76DEFB00B8.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundWH();

    //## Destructor (generated)
      ~CSoundWH();


    //## Other Operations (specified)
      //## Operation: Init%1001802585
      static void Init (int _iMaxSounds);

      //## Operation: Invalidate%1001802586
      static void Invalidate ();

      //## Operation: iAddSound%1001802587
      static int iAddSound (CSound *_poSound, char *_szSndName);

      //## Operation: poGetSound%1001802588
      static CSound * poGetSound (char* _szName);

      //## Operation: poGetSound%1001802589
      static CSound * poGetSound (int _iIdx);

      //## Operation: iLoadSound%1001802596
      static int iLoadSound (char *_szFilename);

    //## Get and Set Operations for Associations (generated)

      //## Association: SoundSystem::Sound::<unnamed>%3BB646E10023
      //## Role: CSoundWH::poSndElem%3BB646E10145
      static CSoundWH_Elem * GetpoSndElem ();
      static void SetpoSndElem (CSoundWH_Elem * value);

    // Data Members for Associations

      //## Association: SoundSystem::Sound::<unnamed>%3BB646E10023
      //## begin CSoundWH::poSndElem%3BB646E10145.role preserve=no  public: static CSoundWH_Elem { -> RHAN}
      static CSoundWH_Elem *poSndElem;
      //## end CSoundWH::poSndElem%3BB646E10145.role

    // Additional Public Declarations
      //## begin CSoundWH%3B76DEFB00B8.public preserve=yes
      //## end CSoundWH%3B76DEFB00B8.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundWH%3B76DEFB00B8.protected preserve=yes
      //## end CSoundWH%3B76DEFB00B8.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iNumSounds%3BB645250115
      //## begin CSoundWH::iNumSounds%3BB645250115.attr preserve=no  private: static int {UA} 0
      static int iNumSounds;
      //## end CSoundWH::iNumSounds%3BB645250115.attr

      //## Attribute: iMaxSounds%3BB6452A0036
      //## begin CSoundWH::iMaxSounds%3BB6452A0036.attr preserve=no  private: static int {UA} 0
      static int iMaxSounds;
      //## end CSoundWH::iMaxSounds%3BB6452A0036.attr

    // Additional Private Declarations
      //## begin CSoundWH%3B76DEFB00B8.private preserve=yes
      //## end CSoundWH%3B76DEFB00B8.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundWH%3B76DEFB00B8.implementation preserve=yes
      //## end CSoundWH%3B76DEFB00B8.implementation

};

//## begin CSoundWH%3B76DEFB00B8.postscript preserve=yes
//## end CSoundWH%3B76DEFB00B8.postscript

// Class CSoundWH 

//## Get and Set Operations for Associations (inline)

inline CSoundWH_Elem * CSoundWH::GetpoSndElem ()
{
  //## begin CSoundWH::GetpoSndElem%3BB646E10145.get preserve=no
  return poSndElem;
  //## end CSoundWH::GetpoSndElem%3BB646E10145.get
}

inline void CSoundWH::SetpoSndElem (CSoundWH_Elem * value)
{
  //## begin CSoundWH::SetpoSndElem%3BB646E10145.set preserve=no
  poSndElem = value;
  //## end CSoundWH::SetpoSndElem%3BB646E10145.set
}

//## begin module%3B76DEFB00B8.epilog preserve=yes
//## end module%3B76DEFB00B8.epilog


#endif
