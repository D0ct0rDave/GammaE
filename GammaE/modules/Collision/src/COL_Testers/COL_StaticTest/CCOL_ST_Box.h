//	  %X% %Q% %Z% %W%



#ifndef CCOL_ST_Box_h
#define CCOL_ST_Box_h 1



// GammaE_Math
#include "GammaE_Math.h"





class CCOL_ST_Box 
{
    
  public:
          CCOL_ST_Box();

          ~CCOL_ST_Box();


                static int iTestSphere (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDCenter, float _fDRadius);

            static int iTestBox (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDMaxs, CVect3& _oDMins);

            static int iTestPoint (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDPoint);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_ST_Box 



#endif
