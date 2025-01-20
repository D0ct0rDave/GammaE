//	  %X% %Q% %Z% %W%



#ifndef CLightCaster_h
#define CLightCaster_h 1



// CObject3D_Leaf
#include "Scene\CObject3D_Leaf.h"




class CLightCaster : public CObject3D_Leaf  {
    
  public:
          CLightCaster();

          ~CLightCaster();


                void SetupLight (CVect3& _oLightPos, CVect3 _oLightDir);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CLightCaster 



#endif
