//	  %X% %Q% %Z% %W%



#ifndef CObject3D_Reflector_h
#define CObject3D_Reflector_h 1



// GammaE_Math
#include "GammaE_Math.h"
// CObject3D_Node
#include "GammaE_Scene.h"





class CObject3D_Reflector : public CObject3D_Node  {
    
  public:
          CObject3D_Reflector();

          virtual ~CObject3D_Reflector();


                virtual void Render ();

            void SetupReflectionMatrix (CMatrix4x4 &_oMat);

    // Data Members for Class Attributes

                  CMesh *Mirror;
      
    // Data Members for Associations

                        CPlane Plane;
      
    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CObject3D_Reflector 



#endif
