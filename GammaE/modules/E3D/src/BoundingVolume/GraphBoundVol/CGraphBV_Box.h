//	  %X% %Q% %Z% %W%



#ifndef CGraphBV_Box_h
#define CGraphBV_Box_h 1



// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingBox
#include "BoundingVolume\CBoundingBox.h"




class CGraphBV_Box : public CGraphBV  {
    
  public:
          CGraphBV_Box();

          ~CGraphBV_Box();


                virtual void Transform (CMatrix4x4& M);

            virtual void Compute (CVect3* VXs, int iNumVXs);

            virtual float GetRange (int iAxis);

            virtual CVect3 & GetCenter ();

            virtual int TestFrustum (CE3D_Frustum& _Frustum);

            virtual void Init (CVect3 Max, CVect3 Min);

            CBoundingBox * pGetBox ();

            virtual int TestInside (CVect3& _Pos);

            virtual CVect3 & GetExtents ();

            CVect3 & GetAxis (int _iAxis);

            virtual CVect3 & oGetMax ();

            virtual CVect3 & oGetMin ();

    // Data Members for Associations

                        CBoundingBox Vol;
      
    // Additional Public Declarations
            
  protected:

                void ComputeAll ();

    // Data Members for Class Attributes

                  CVect3 oExtents;
      
                  CVect3 oCenter;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CGraphBV_Box 



#endif
