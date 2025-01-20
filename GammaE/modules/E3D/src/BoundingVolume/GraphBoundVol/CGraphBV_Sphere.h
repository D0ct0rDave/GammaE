//	  %X% %Q% %Z% %W%



#ifndef CGraphBV_Sphere_h
#define CGraphBV_Sphere_h 1



// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingSphere
#include "BoundingVolume\CBoundingSphere.h"




class CGraphBV_Sphere : public CGraphBV  {
    
  public:
          CGraphBV_Sphere();

          ~CGraphBV_Sphere();


                virtual void Transform (CMatrix4x4& M);

            virtual void Compute (CVect3* VXs, int iNumVXs);

            virtual float GetRange (int iAxis);

            virtual CVect3 & GetCenter ();

            virtual int TestFrustum (CE3D_Frustum& _Frustum);

            virtual void Init (CVect3 Max, CVect3 Min);

            CBoundingSphere * pGetSphere ();

            virtual int TestInside (CVect3& _Pos);

            virtual void Copy (CGraphBV* Src);

    // Data Members for Associations

                        CBoundingSphere Vol;
      
    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  CVect3 oExtents;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CGraphBV_Sphere 



#endif
