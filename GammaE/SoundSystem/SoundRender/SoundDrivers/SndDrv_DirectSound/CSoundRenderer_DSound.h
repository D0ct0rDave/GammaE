//## begin module%3BB700C50336.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BB700C50336.cm

//## begin module%3BB700C50336.cp preserve=no
//## end module%3BB700C50336.cp

//## Module: CSoundRenderer_DSound%3BB700C50336; Pseudo Package specification
//## Source file: i:\Projects\GammaE\SoundSystem\SoundRender\SoundDrivers\SndDrv_DirectSound\CSoundRenderer_DSound.h

#ifndef CSoundRenderer_DSound_h
#define CSoundRenderer_DSound_h 1

//## begin module%3BB700C50336.additionalIncludes preserve=no
//## end module%3BB700C50336.additionalIncludes

//## begin module%3BB700C50336.includes preserve=yes
#include <DSound.h>
//## end module%3BB700C50336.includes

// CSoundRenderer
#include "SoundSystem\SoundRender\CSoundRenderer.h"
// CSoundMixer
#include "SoundSystem\SoundRender\SoundMixer\CSoundMixer.h"
//## begin module%3BB700C50336.additionalDeclarations preserve=yes
//## end module%3BB700C50336.additionalDeclarations


//## begin CSoundRenderer_DSound%3BB700C50336.preface preserve=yes
//## end CSoundRenderer_DSound%3BB700C50336.preface

//## Class: CSoundRenderer_DSound%3BB700C50336
//## Category: SoundSystem::SoundRender::SoundDrivers::SndDrv_DirectSound%3BB700BA01B4
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C7F910A01F9;CSoundMixer { -> }

class CSoundRenderer_DSound : public CSoundRenderer  //## Inherits: <unnamed>%3BB700D30188
{
  //## begin CSoundRenderer_DSound%3BB700C50336.initialDeclarations preserve=yes
  //## end CSoundRenderer_DSound%3BB700C50336.initialDeclarations

  public:
    //## Constructors (generated)
      CSoundRenderer_DSound();

    //## Destructor (generated)
      ~CSoundRenderer_DSound();


    //## Other Operations (specified)
      //## Operation: Init%1001849070
      virtual int Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters);

      //## Operation: Finish%1014979367
      void Finish ();

      //## Operation: iLoadDirectSound%1015076948
      int iLoadDirectSound ();

      //## Operation: iUnloadDirectSound%1015076949
      int iUnloadDirectSound ();

      //## Operation: iCreateBuffers%1015076950
      int iCreateBuffers ();

      //## Operation: Render%1001849071
      virtual void Render (float _fDelta);

      //## Operation: TransferData%1015160465
      void TransferData (unsigned int _uiSamples);

      //## Operation: bComputeVolumeFactors%1015188291
      bool bComputeVolumeFactors (CSoundEmiter* _poEmiter);

    // Additional Public Declarations
      //## begin CSoundRenderer_DSound%3BB700C50336.public preserve=yes
      //## end CSoundRenderer_DSound%3BB700C50336.public

  protected:
    // Additional Protected Declarations
      //## begin CSoundRenderer_DSound%3BB700C50336.protected preserve=yes
      //## end CSoundRenderer_DSound%3BB700C50336.protected

  private:
    // Data Members for Class Attributes

      //## Attribute: iNumChannels%3BB8E2CD013F
      //## begin CSoundRenderer_DSound::iNumChannels%3BB8E2CD013F.attr preserve=no  private: int {UA} 
      int iNumChannels;
      //## end CSoundRenderer_DSound::iNumChannels%3BB8E2CD013F.attr

      //## Attribute: iSndRate%3BB8E2DE0035
      //## begin CSoundRenderer_DSound::iSndRate%3BB8E2DE0035.attr preserve=no  private: int {UA} 
      int iSndRate;
      //## end CSoundRenderer_DSound::iSndRate%3BB8E2DE0035.attr

      //## Attribute: iSndBits%3BB8E2E20117
      //## begin CSoundRenderer_DSound::iSndBits%3BB8E2E20117.attr preserve=no  private: int {UA} 
      int iSndBits;
      //## end CSoundRenderer_DSound::iSndBits%3BB8E2E20117.attr

    // Additional Private Declarations
      //## begin CSoundRenderer_DSound%3BB700C50336.private preserve=yes
      //## end CSoundRenderer_DSound%3BB700C50336.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin CSoundRenderer_DSound%3BB700C50336.implementation preserve=yes
      //## end CSoundRenderer_DSound%3BB700C50336.implementation

};

//## begin CSoundRenderer_DSound%3BB700C50336.postscript preserve=yes
//## end CSoundRenderer_DSound%3BB700C50336.postscript

// Class CSoundRenderer_DSound 

//## begin module%3BB700C50336.epilog preserve=yes
//## end module%3BB700C50336.epilog


#endif
