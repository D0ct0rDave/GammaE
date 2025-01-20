
//-----------------------------------------------------------------------------








#ifndef CSoundMixer_h
#define CSoundMixer_h 1







//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
#include "SoundRender\SoundMixer\CSoundMixPars.h"














class CSoundMixer 
{
  
  

  public:
    
      CSoundMixer();

    
      ~CSoundMixer();


    
      
      static void Clear ();

      
      static void SetupBuffer (unsigned int _uiSamples, unsigned int _iSRate, int _iBits);

      
      static void Mix (CSoundMixPars& _oSMP, unsigned int _uiSamples, unsigned int _uiCurDSmpPos = 0);

      
      static int iMix16M(CSoundMixPars& _oSMP, CSample* _poSample,unsigned int _uiSamples, unsigned int _uiCurDSmpPos);

      
      static int iMix16S(CSoundMixPars& _oSMP, CSample* _poSample,unsigned int _uiSamples, unsigned int _uiCurDSmpPos);

      
      static int iMix8M (CSoundMixPars& _oSMP, CSample* _poSample,unsigned int _uiSamples, unsigned int _uiCurDSmpPos);

      
      static int iMix8S (CSoundMixPars& _oSMP, CSample* _poSample,unsigned int _uiSamples, unsigned int _uiCurDSmpPos);

      
      static void* pGetBuffer ();

      
      static unsigned int uiGetBufferSize ();

      
      static void Finish ();

    //-----------------------------------------------------------------------------

      
      
      
      

    //-----------------------------------------------------------------------------
      
      static void PostProcess();
      

  protected:
    //-----------------------------------------------------------------------------
      
      

  private:
    //-----------------------------------------------------------------------------

      
      
      static void *pBuffer;
      

      
      
      static int *pi32bBuffer;
      

      
      
      static unsigned int uiBuffSize;
      

      
      
      static unsigned int uiBuffSamples;
      

      
      
      static int iSRate;
      

      
      
      static int iBits;
      

      
      
      

    //-----------------------------------------------------------------------------
      
      static void* pSampleBuffer;
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------





#endif
