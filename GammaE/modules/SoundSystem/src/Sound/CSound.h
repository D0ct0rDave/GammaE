
//-----------------------------------------------------------------------------








#ifndef CSound_h
#define CSound_h 1







//-----------------------------------------------------------------------------
#include "Sound\CSoundLayer.h"












class CSound : public CGResource
{
  
  

  public:
    
      CSound();

    
      ~CSound();


    
      
      int iAddLayer (CSoundLayer& _oSLayer);

      
      int iAddLayer (bool _bLoop, CSample* _poSample);

    //-----------------------------------------------------------------------------

      
      
      int iNumLayers;
      

    //-----------------------------------------------------------------------------

      
      
      
      CSoundLayer *poSLayer;
      

    //-----------------------------------------------------------------------------
      
      

  protected:
    //-----------------------------------------------------------------------------
      
      

  private:
    //-----------------------------------------------------------------------------
      
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------





#endif
