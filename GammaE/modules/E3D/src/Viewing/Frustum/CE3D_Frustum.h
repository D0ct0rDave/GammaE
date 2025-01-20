//	  %X% %Q% %Z% %W%



#ifndef CE3D_Frustum_h
#define CE3D_Frustum_h 1



// CE3D_Projector
#include "Viewing\Projector\CE3D_Projector.h"
// GammaE_Math
#include "GammaE_Math.h"





class CE3D_Frustum 
{
    
  public:

                void Compute (CE3D_Projector *_Projector, float _fRatio);

            CPlane & GetPlane (int iPlane);

            int TestBBox (CVect3& Maxs, CVect3 &Mins);

            int TestSphere (float Radius, CVect3 &Center);

            int TestPoint (CVect3& _oPoint);

            void Transform (CMatrix4x4 &_Transf);

            void Copy (CE3D_Frustum &_pFrust);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Data Members for Class Attributes

                  CPlane Plane[6];
      
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CE3D_Frustum 



#endif
