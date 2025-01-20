//	  %X% %Q% %Z% %W%



#ifndef CSLM_LMapSect_h
#define CSLM_LMapSect_h 1



// CSectorLoaderManager
#include "Sector\SectorMatrix\CSectorLoaderManager\CSectorLoaderManager.h"
// CLMSector_Gray
#include "Sector\LightMap\CLMSector_Gray.h"
// CLMSector_Pal
#include "Sector\LightMap\CLMSector_Pal.h"
// CLMSector_RGB24
#include "Sector\LightMap\CLMSector_RGB24.h"





class CSLM_LMapSect : public CSectorLoaderManager  {
    
  public:
          CSLM_LMapSect();

          ~CSLM_LMapSect();


                virtual CSector * poCreateClass (FILE *_FD);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CSLM_LMapSect 



#endif
