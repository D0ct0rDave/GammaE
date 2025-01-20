//## begin module%3C7F8F990248.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7F8F990248.cm

//## begin module%3C7F8F990248.cp preserve=no
//## end module%3C7F8F990248.cp

//## Module: CSoundMixPars%3C7F8F990248; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\SoundMixer\CSoundMixPars.h

#ifndef CSoundMixPars_h
#define CSoundMixPars_h 1

//## begin module%3C7F8F990248.additionalIncludes preserve=no
//## end module%3C7F8F990248.additionalIncludes

//## begin module%3C7F8F990248.includes preserve=yes
//## end module%3C7F8F990248.includes

// CSound
#include "SoundSystem\Sound\CSound.h"
//## begin module%3C7F8F990248.additionalDeclarations preserve=yes
//## end module%3C7F8F990248.additionalDeclarations


//## Class: CSoundMixPars%3C7F8F990248
//## Category: SoundSystem::SoundRender::SoundMixer%3C7F7DE30126
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSoundMixPars 
{
  public:
    //## Constructors (generated)
      CSoundMixPars();

    //## Destructor (generated)
      ~CSoundMixPars();

    // Data Members for Class Attributes

      //## Attribute: fLVol%3C7F8FDC0154
      //## begin CSoundMixPars::fLVol%3C7F8FDC0154.attr preserve=no  public: float {UA} 1.0f
      float fLVol;
      //## end CSoundMixPars::fLVol%3C7F8FDC0154.attr

      //## Attribute: fRVol%3C7F8FE502C0
      //## begin CSoundMixPars::fRVol%3C7F8FE502C0.attr preserve=no  public: float {UA} 1.0f
      float fRVol;
      //## end CSoundMixPars::fRVol%3C7F8FE502C0.attr

      //## Attribute: iSPos%3C7F900B00A8
      //## begin CSoundMixPars::iSPos%3C7F900B00A8.attr preserve=no  public: int {UA} 0
      int iSPos;
      //## end CSoundMixPars::iSPos%3C7F900B00A8.attr

      //## Attribute: iCLayer%3C7F9012002F
      //## begin CSoundMixPars::iCLayer%3C7F9012002F.attr preserve=no  public: int {UA} 0
      int iCLayer;
      //## end CSoundMixPars::iCLayer%3C7F9012002F.attr

      //## Attribute: bLUnlock%3C7F91D402F4
      //## begin CSoundMixPars::bLUnlock%3C7F91D402F4.attr preserve=no  public: bool {UA} false
      bool bLUnlock;
      //## end CSoundMixPars::bLUnlock%3C7F91D402F4.attr

      //## Attribute: bEnd%3C7FA0E90350
      //## begin CSoundMixPars::bEnd%3C7FA0E90350.attr preserve=no  public: bool {UA} false
      bool bEnd;
      //## end CSoundMixPars::bEnd%3C7FA0E90350.attr

    // Data Members for Associations

      //## Association: SoundSystem::SoundRender::SoundMixer::<unnamed>%3C7F8FBF0379
      //## Role: CSoundMixPars::poSound%3C7F8FC00118
      //## begin CSoundMixPars::poSound%3C7F8FC00118.role preserve=no  public: CSound { -> RHAN}
      CSound *poSound;
      //## end CSoundMixPars::poSound%3C7F8FC00118.role

  protected:
  private:
  private: //## implementation
};

// Class CSoundMixPars 

//## begin module%3C7F8F990248.epilog preserve=yes
//## end module%3C7F8F990248.epilog


#endif
