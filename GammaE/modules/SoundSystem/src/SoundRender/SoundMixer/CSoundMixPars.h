
//-----------------------------------------------------------------------------








#ifndef CSoundMixPars_h
#define CSoundMixPars_h 1







//-----------------------------------------------------------------------------
#include "Sound\CSound.h"









class CSoundMixPars 
{
  public:
    
      CSoundMixPars();

    
      ~CSoundMixPars();

    //-----------------------------------------------------------------------------

      
      
      float fLVol;
      

      
      
      float fRVol;
      

      
      
      int iSPos;
      

      
      
      int iCLayer;
      

      
      
      bool bLUnlock;
      

      
      
      bool bEnd;
      

    //-----------------------------------------------------------------------------

      
      
      
      CSound *poSound;
      

  protected:
  private:
  private: 
};

//-----------------------------------------------------------------------------





#endif
