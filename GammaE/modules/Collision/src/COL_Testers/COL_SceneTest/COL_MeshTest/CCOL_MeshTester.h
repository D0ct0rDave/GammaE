//	  %X% %Q% %Z% %W%



#ifndef CCOL_MeshTester_h
#define CCOL_MeshTester_h 1



// GammaE_E3D
#include "GammaE_E3D.h"
// CCOL_TriList
#include "COL_TriList\CCOL_TriList.h"





class CCOL_MeshTester 
{
    
  public:
          CCOL_MeshTester();

          ~CCOL_MeshTester();


                virtual int iTestCollision (CMesh* _poMesh, int _iMat, CGraphBV* _poBVol, CCOL_TriList& _oTriList);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CCOL_MeshTester 



#endif
