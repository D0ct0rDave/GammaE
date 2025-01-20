//-----------------------------------------------------------------------------
#ifndef CPlane_h
#define CPlane_h 1
//-----------------------------------------------------------------------------
#include "..\MATH_Vector\CVect3.h"
//-----------------------------------------------------------------------------
#include "..\MATH_Other\MATH_Common.h"
//-----------------------------------------------------------------------------
#include "..\MATH_Matrix\CMatrix4x4.h"

class CPlane 
{

  public:
      
      void SetNormal (CVect3& _Normal);

      
      void SetD (float _D);

      
      void SetOrigin (CVect3& _Origin);

      
      void GenerateFromVectors (CVect3 VDir1, CVect3 VDir2, CVect3 VOrigin);

      
      void GenerateFromPoints (CVect3& a, CVect3& b, CVect3& c);

      
      void GeneratePlaneFromFields (CVect3& VOrigin, CVect3& VNormal);

      
      float GetDistanceToPoint (CVect3& Point);

      
      bool Coplanar (CPlane& Plane);

      
      CVect3 & Normal ();

      
      CVect3 & Origin ();

      
      float D ();

      
      void Transform (CMatrix4x4& _Transf);

      
      CVect3 ProjectPoint (CVect3& _Point);

      
      int iPlaneType ();

    //-----------------------------------------------------------------------------
      
      

  protected:
    //-----------------------------------------------------------------------------
      
      

  private:
    //-----------------------------------------------------------------------------

      
      
      float PlaneD;
      

      
      
      CVect3 PlaneOrigin;
      

      
      
      CVect3 PlaneNormal;
      

    //-----------------------------------------------------------------------------
      
      

  private: 
    //-----------------------------------------------------------------------------
      
      

};




//-----------------------------------------------------------------------------



inline void CPlane::SetNormal (CVect3& _Normal)
{
  
	PlaneNormal.Assign(_Normal);
  
}

inline void CPlane::SetD (float _D)
{
  
	PlaneD = _D;
  
}

inline void CPlane::SetOrigin (CVect3& _Origin)
{
  
	PlaneOrigin.Assign(_Origin);
  
}

inline CVect3 & CPlane::Normal ()
{
  
	return (PlaneNormal);
  
}

inline CVect3 & CPlane::Origin ()
{
  
	return (PlaneOrigin);
  
}

inline float CPlane::D ()
{
  
	return (PlaneD);
  
}
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
