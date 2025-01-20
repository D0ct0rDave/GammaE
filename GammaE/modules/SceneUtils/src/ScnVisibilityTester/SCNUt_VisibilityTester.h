//	  %X% %Q% %Z% %W%



#ifndef SCNUt_VisibilityTester_h
#define SCNUt_VisibilityTester_h 1



// GammaE_Math
#include "GammaE_Math.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"





class SCNUt_VisibilityTester 
{
    
  public:
          SCNUt_VisibilityTester();

          ~SCNUt_VisibilityTester();


                bool bIsVisible (SCNUt_TriScene* _poTScn, CVect3& _oIni, CVect3& _oEnd);

    // Additional Public Declarations
            
  protected:

                bool bRayToPos (CRay& _oRay, CVect3& _oPos, SCNUt_TriScene* _poTScn);

    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class SCNUt_VisibilityTester 



#endif
