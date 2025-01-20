
//-----------------------------------------------------------------------------








#ifndef CPCMStreamSample_h
#define CPCMStreamSample_h 1








#include "Sound\CStreamSample.h"











class CPCMStreamSample : public CStreamSample
{
  
  

  public:
    
      CPCMStreamSample();

    
      ~CPCMStreamSample();


    
      
		virtual void Init(char *_szFilename);
		virtual void Finish();
      
    //-----------------------------------------------------------------------------

    //-----------------------------------------------------------------------------
      
      virtual int iGetData(int _iOfs,void *_pBuffer,int _iSize);
      

  protected:
    //-----------------------------------------------------------------------------
      
      

  private:
    //-----------------------------------------------------------------------------
      
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------





#endif
