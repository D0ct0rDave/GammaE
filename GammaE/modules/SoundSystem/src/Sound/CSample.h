
//-----------------------------------------------------------------------------








#ifndef CSample_h
#define CSample_h 1








#include "GammaE_Misc.h"











class CSample : public CGResource
{
  
  

  public:
    
      CSample();

    
      ~CSample();


    
      
      
    //-----------------------------------------------------------------------------

      
      
      

      
      
      int iChannels;
      

      
      
      int iBits;
      

      
      
      int iSRate;
      

      
      
      int iSamples;
      

      
      
      int iHandle;
      

    //-----------------------------------------------------------------------------
      
      virtual int  iGetData(int _iOfs,void *_pBuffer,int _iSize);
      virtual void* pGetInternalData() { return(NULL); };
      

  protected:
    //-----------------------------------------------------------------------------
      
       virtual void Finish() {};
      

  private:
    //-----------------------------------------------------------------------------
      
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------





#endif
