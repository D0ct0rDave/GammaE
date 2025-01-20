//## begin module%3C7F7DF20222.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C7F7DF20222.cm

//## begin module%3C7F7DF20222.cp preserve=no
//## end module%3C7F7DF20222.cp

//## Module: CSoundMixer%3C7F7DF20222; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\SoundMixer\CSoundMixer.h

#ifndef CSoundMixer_h
#define CSoundMixer_h 1

//## begin module%3C7F7DF20222.additionalIncludes preserve=no
//## end module%3C7F7DF20222.additionalIncludes

//## begin module%3C7F7DF20222.includes preserve=yes
//## end module%3C7F7DF20222.includes

// CSoundReceiver
#include "SoundSystem\SoundRender\CSoundReceiver.h"
// CSoundMixPars
#include "SoundSystem\SoundRender\SoundMixer\CSoundMixPars.h"
//## begin module%3C7F7DF20222.additionalDeclarations preserve=yes
//## end module%3C7F7DF20222.additionalDeclarations


//## begin CSoundMixer%3C7F7DF20222.preface preserve=yes
//## end CSoundMixer%3C7F7DF20222.preface

//## Class: CSoundMixer%3C7F7DF20222
//## Category: SoundSystem::SoundRender::SoundMixer%3C7F7DE30126
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7F901F031D;CSoundMixPars { -> }

class CSoundMixer 
{
  //## begin CSoundMixer%3C7F7DF20222.initialDeclarations preserve=yes
  //## end CSoundMixer%3C7F7DF20222.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundMixer();

    //## Destructor (generated)
      ~CSoundMixer();


    //## Other Operations (specified)
      //## Operation: Clear%1014979369
      static void Clear ();

      //## Operation: SetupBuffer%1014979371
      static void SetupBuffer (float _fSeconds, unsigned int _iSRate, int _iBits);

      //## Operation: Mix%1014979370
      static void Mix (CSoundMixPars& _roSMP, unsigned int _uiSamples);

      //## Operation: Mix16M%1014979372
      static void Mix16M (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos);

      //## Operation: Mix16S%1014979373
      static void Mix16S (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos);

      //## Operation: Mix8M%1014979374
      static void Mix8M (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos);

      //## Operation: Mix8S%1014979375
      static void Mix8S (CSoundMixPars& _roSMP, unsigned int uiSamples, unsigned int _uiCurDSmpPos);

      //## Operation: pGetBuffer%1015160464
      static void* pGetBuffer ();

      //## Operation: uiGetBufferSize%1015168104
      static unsigned int uiGetBufferSize ();

    // Data Members for Associations

      //## Association: SoundSystem::SoundRender::SoundMixer::<unnamed>%3C7F8E400102
      //## Role: CSoundMixer::poRec%3C7F8E4001FD
      //## begin CSoundMixer::poRec%3C7F8E4001FD.role preserve=no  public: static CSoundReceiver { -> RHAN}
      static CSoundReceiver *poRec;
      //## end CSoundMixer::poRec%3C7F8E4001FD.role

    // Additional Public Declarations
      //## begin CSoundMixer%3C7F7DF20222.public preserve=yes
      //## end CSoundMixer%3C7F7DF20222.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundMixer%3C7F7DF20222.protected preserve=yes
      //## end CSoundMixer%3C7F7DF20222.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: pBuffer%3C7F7E0B0047
      //## begin CSoundMixer::pBuffer%3C7F7E0B0047.attr preserve=no  private: static void * {UA} NULL
      static void *pBuffer;
      //## end CSoundMixer::pBuffer%3C7F7E0B0047.attr

      //## Attribute: pi32bBuffer%3D0CA81B005D
      //## begin CSoundMixer::pi32bBuffer%3D0CA81B005D.attr preserve=no  private: static int * {UA} NULL
      static int *pi32bBuffer;
      //## end CSoundMixer::pi32bBuffer%3D0CA81B005D.attr

      //## Attribute: uiBuffSize%3C7F7E1B0307
      //## begin CSoundMixer::uiBuffSize%3C7F7E1B0307.attr preserve=no  private: static unsigned int {UA} 0
      static unsigned int uiBuffSize;
      //## end CSoundMixer::uiBuffSize%3C7F7E1B0307.attr

      //## Attribute: uiBuffSamples%3C82223001C4
      //## begin CSoundMixer::uiBuffSamples%3C82223001C4.attr preserve=no  private: static unsigned int {UA} 0
      static unsigned int uiBuffSamples;
      //## end CSoundMixer::uiBuffSamples%3C82223001C4.attr

      //## Attribute: iSRate%3C7F99A10179
      //## begin CSoundMixer::iSRate%3C7F99A10179.attr preserve=no  private: static int {UA} 0
      static int iSRate;
      //## end CSoundMixer::iSRate%3C7F99A10179.attr

      //## Attribute: iBits%3C7F9A530160
      //## begin CSoundMixer::iBits%3C7F9A530160.attr preserve=no  private: static int {UA} 0
      static int iBits;
      //## end CSoundMixer::iBits%3C7F9A530160.attr

      //## Attribute: bPostProcess%3D0CA872027F
      //## begin CSoundMixer::bPostProcess%3D0CA872027F.attr preserve=no  private: static bool {UA} false
      static bool bPostProcess;
      //## end CSoundMixer::bPostProcess%3D0CA872027F.attr

    // Additional Private Declarations
      //## begin CSoundMixer%3C7F7DF20222.private preserve=yes
      //## end CSoundMixer%3C7F7DF20222.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundMixer%3C7F7DF20222.implementation preserve=yes
      //## end CSoundMixer%3C7F7DF20222.implementation

};

//## begin CSoundMixer%3C7F7DF20222.postscript preserve=yes
//## end CSoundMixer%3C7F7DF20222.postscript

// Class CSoundMixer 

//## begin module%3C7F7DF20222.epilog preserve=yes
//## end module%3C7F7DF20222.epilog


#endif
