//	  %X% %Q% %Z% %W%



#ifndef CCOL_DT_Box_h
#define CCOL_DT_Box_h 1



// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_ST_Box
#include "COL_Testers\COL_StaticTest\CCOL_ST_Box.h"





class CCOL_DT_Box 
{
    
  public:
          CCOL_DT_Box();

          ~CCOL_DT_Box();


                static float fTestSphere (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDCenter, float _fDRadius);

            static float fTestBox (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDMaxs, CVect3& _oDMins);

            static float fTestPoint (CVect3& _oSMaxs, CVect3& _oSMins, CVect3& _oDPoint);

    // Additional Public Declarations
      	  static int CCOL_DT_Box::iGetCollisionAxis();
      
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
      		static int iColAxis;
      
};


// Class CCOL_DT_Box 

inline int CCOL_DT_Box::iGetCollisionAxis()
{
	return(iColAxis);
}


#endif
