//	  %X% %Q% %Z% %W%



#ifndef CSLM_TexSect_h
#define CSLM_TexSect_h 1



// CSectorLoaderManager
#include "Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"




class CSLM_TexSect : public CSectorLoaderManager  {
    
  public:
          CSLM_TexSect();

          ~CSLM_TexSect();


                virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CSLM_TexSect 



#endif
