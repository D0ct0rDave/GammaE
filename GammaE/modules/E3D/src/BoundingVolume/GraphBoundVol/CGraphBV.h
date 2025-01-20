//	  %X% %Q% %Z% %W%



#ifndef CGraphBV_h
#define CGraphBV_h 1



// eGraphBV_TypeID
#include "BoundingVolume\GraphBoundVol\eGraphBV_TypeID.h"
// CE3D_Frustum
#include "Viewing\Frustum\CE3D_Frustum.h"





class CGraphBV 
{
    
  public:
          CGraphBV();

          ~CGraphBV();


                virtual void Transform (CMatrix4x4& M);

            virtual void Compute (CVect3* VXs, int iNumVXs);

            virtual float GetRange (int iAxis);

            virtual CVect3 & GetCenter ();

            virtual int TestFrustum (CE3D_Frustum& _Frustum);

            virtual void Init (CVect3 Max, CVect3 Min);

            virtual void Copy (CGraphBV* Src);

            eGraphBV_TypeID eGetTypeID ();

            virtual int TestInside (CVect3& _Pos);

            virtual CVect3 & GetExtents ();

            virtual CVect3 & oGetMax ();

            virtual CVect3 & oGetMin ();

    // Additional Public Declarations
            
  protected:
    // Data Members for Class Attributes

                  eGraphBV_TypeID eTypeID;
      
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class CGraphBV 


inline eGraphBV_TypeID CGraphBV::eGetTypeID ()
{
  	return (eTypeID);
}



#endif
