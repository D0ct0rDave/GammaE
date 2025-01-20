//	  %X% %Q% %Z% %W%



#ifndef CGraphBV_FileIO_h
#define CGraphBV_FileIO_h 1


#include <stdio.h>

// GammaE_FileSys
#include "GammaE_FileSys.h"
// CGraphBV_Sphere
#include "BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h"
// CGraphBV_Point
#include "BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
// CGraphBV_Cylinder
#include "BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
// CGraphBV_Box
#include "BoundingVolume\GraphBoundVol\CGraphBV_Box.h"





class CGraphBV_FileIO 
{
    
  public:
          CGraphBV_FileIO();

          ~CGraphBV_FileIO();


                static CGraphBV * pLoadGraphBV (CFile& _oFile);

            static int iSaveGraphBV (CFile& _oFile, CGraphBV *_pGBV);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CGraphBV_FileIO 



#endif
