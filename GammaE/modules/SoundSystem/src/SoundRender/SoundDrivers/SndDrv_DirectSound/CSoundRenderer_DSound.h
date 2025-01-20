//-----------------------------------------------------------------------------
#ifndef CSoundRenderer_DSound_h
#define CSoundRenderer_DSound_h 1


//-----------------------------------------------------------------------------
#include "SoundRender\CSoundRenderer.h"
//-----------------------------------------------------------------------------
#include "SoundRender\SoundMixer\CSoundMixer.h"
#include "SoundRender\SoundDrivers\SndDrv_DirectSound\CSoundEmiter_DSound.h"

class CSoundRenderer_DSound : public CSoundRenderer  
{
  public:
    
      CSoundRenderer_DSound();
      ~CSoundRenderer_DSound();

      virtual int Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters);

      void Finish ();

      int iLoadDirectSound ();

      int iUnloadDirectSound ();

      int iCreateBuffers ();

      virtual void Render (float _fDelta);

      void TransferData ();
      
      bool bComputeVolumeFactors (CSoundEmiter_DSound* _poEmiter);

      virtual CSoundEmiter* poGetFreeEmiter();

  protected:

      CGCircularArray <CSoundEmiter_DSound> oEmiters;

  private:

      int iNumChannels;
      
      int iSndRate;
      
      int iSndBits;
      
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
