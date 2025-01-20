//	  %X% %Q% %Z% %W%



#ifndef CSoundRenderer_Bass_h
#define CSoundRenderer_Bass_h 1



// CSoundRenderer
#include "SoundRender\CSoundRenderer.h"
// CSR_Bass_Emiter
#include "SoundRender\SoundDrivers\SndDrv_BASS\CSR_Bass_Emiter.h"





class CSoundRenderer_Bass : public CSoundRenderer  {
    
  public:
          CSoundRenderer_Bass();

          ~CSoundRenderer_Bass();


                virtual int Init (void *_HndDeviceContext, int _iSndBits, int _iSndSRate, int _iMaxEmiters);

            virtual void Render (float _fDelta);

            void ProcessEmiters ();

            void UploadSample (CSample *_pSample);

            void UpdateBassEmiter_Layers (CSR_Bass_Emiter *_pBEmiter);

            void UpdateBassEmiter_3D (CSR_Bass_Emiter *_pBEmiter);

            virtual int iAddEmiter (CSoundEmiter *_pEmiter);

            virtual void RemoveEmiter (int _iIdx);

            virtual void UnlockEmiter (int _iIdx);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CSR_Bass_Emiter* pBassEmiter;
      
                  int iMaxChannels;
      
                  int iNumChannels;
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CSoundRenderer_Bass 



#endif
