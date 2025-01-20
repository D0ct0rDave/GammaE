
//-----------------------------------------------------------------------------








#ifndef CSoundRenderer_SDL_h
#define CSoundRenderer_SDL_h 1







//-----------------------------------------------------------------------------
#include "SoundRender\CSoundRenderer.h"












class CSoundRenderer_SDL : public CSoundRenderer  
{
  
  

  public:
    
      CSoundRenderer_SDL();

    
      ~CSoundRenderer_SDL();


    
      
      virtual int Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters);

      
      virtual void Render (float _fDelta);

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
