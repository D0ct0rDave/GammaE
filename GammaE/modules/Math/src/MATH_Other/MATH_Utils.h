//	  %X% %Q% %Z% %W%



#ifndef MATH_Utils_h
#define MATH_Utils_h 1



// CRay
#include "..\MATH_Ray\CRay.h"
// CPlane
#include "..\MATH_Plane\CPlane.h"
// CVect3
#include "..\MATH_Vector\CVect3.h"
// CTriangle
#include "..\MATH_Triangle\CTriangle.h"
// CSegment
#include "..\MATH_Segment\CSegment.h"





class MATH_Utils 
{
    
  public:
          MATH_Utils();

          ~MATH_Utils();


            static void GetPNVertexs (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane, CVect3& P, CVect3& N);

            static int iTestBoxPlane (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane);

            static int iTestSpherePlane (CVect3& _Center, float _fRadius, CPlane& _Plane);

            static int iTestPointPlane (CVect3& _oPoint, CPlane& _oPlane);

            static float fTriPointDistance (CTriangle& _Tri, CVect3& _Point);

            static float fTriPointSqDistance (CTriangle& _Tri, CVect3& _Point);

            static CVect3 oNearestTriPoint (CVect3& _oPoint, CTriangle& _oTri);

            static void GetMaxMins (float a, float b, float c, float &Max, float& Min);

            static int iTestRayTriIntersection (CRay& _ay, CTriangle& _Tri);

            static int iTestRayTriIntersection (CRay& _ay, CTriangle& _Tri, CVect3& _Point);

            static int iTestSegTriIntersection (CRay& _ay, CTriangle& _Tri);

            static int iTestSegTriIntersection (CRay& _ay, CTriangle& _Tri, CVect3& _Point);

            static float fGetT ();

            static int iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point, CVect3& _PPoint);

            static int iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point);

            static int iTest3PlaneIntersection (CPlane& _oPlane0, CPlane& _oPlane1, CPlane& _oPlane2, CVect3& _oPoint);

            static int iTest2PlaneIntersection (CPlane& _oPlane0, CPlane& _oPlane1, CRay& _oRay);

            static int iTestRayAABBIntersection (CRay& _oRay, CVect3& _oMaxs, CVect3& _oMins);

    // Additional Public Declarations
            
  protected:
    // Additional Protected Declarations
            
  private:
    // Additional Private Declarations
            
  private:     // Additional Implementation Declarations
            
};


// Class MATH_Utils 


inline void MATH_Utils::GetMaxMins (float a, float b, float c, float &Max, float& Min)
{
      if (a>b)
	{
		if (b>c)
		{
			Max = a;
			Min = c;
		}
		else
		{
			if (a>c)
			{
				Max = a;
				Min = b;
			}
			else
			{
				Max = c;
				Min = b;
			}
		}
	}
	else
	{	
		//  b > a
		if (a>c)
		{
			Max = b;
			Min = c;
		}
		else
		{
			// a < c
			if (b>c)
			{
				Max = b;
				Min = a;				
			}
			else
			{
				Max = c;
				Min = a;				
			}
		}
	}
}



#endif
