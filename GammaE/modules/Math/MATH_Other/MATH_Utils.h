//## begin module%3C080D120063.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C080D120063.cm

//## begin module%3C080D120063.cp preserve=no
//## end module%3C080D120063.cp

//## Module: MATH_Utils%3C080D120063; Pseudo Package specification
//## Source file: i:\Projects\GammaE\Math\MATH_Other\MATH_Utils.h

#ifndef MATH_Utils_h
#define MATH_Utils_h 1

//## begin module%3C080D120063.additionalIncludes preserve=no
//## end module%3C080D120063.additionalIncludes

//## begin module%3C080D120063.includes preserve=yes
//## end module%3C080D120063.includes

// CRay
#include "Math\MATH_Ray\CRay.h"
// CPlane
#include "Math\MATH_Plane\CPlane.h"
// CVect3
#include "Math\MATH_Vector\CVect3.h"
// CTriangle
#include "Math\MATH_Triangle\CTriangle.h"
// CSegment
#include "Math\MATH_Segment\CSegment.h"
//## begin module%3C080D120063.additionalDeclarations preserve=yes
//## end module%3C080D120063.additionalDeclarations


//## begin MATH_Utils%3C080D120063.preface preserve=yes
//## end MATH_Utils%3C080D120063.preface

//## Class: MATH_Utils%3C080D120063
//## Category: Math::MATH_Other%3C275D6F02F7
//## Persistence: Transient
//## Cardinality/Multiplicity: n

//## Uses: <unnamed>%3C1FE820027D;MATH_Common { -> }
//## Uses: <unnamed>%3C275FA000FF;CVect3 { -> }
//## Uses: <unnamed>%3C275FA1027D;CTriangle { -> }
//## Uses: <unnamed>%3C275FA30244;CPlane { -> }
//## Uses: <unnamed>%3C275FA50016;CRay { -> }
//## Uses: <unnamed>%3CC5D80401A9;CSegment { -> }

class MATH_Utils 
{
  //## begin MATH_Utils%3C080D120063.initialDeclarations preserve=yes
  //## end MATH_Utils%3C080D120063.initialDeclarations

  public:
    //## Constructors (generated)
      MATH_Utils();

    //## Destructor (generated)
      ~MATH_Utils();


    //## Other Operations (specified)
      //## Operation: GetPNVertexs%1007160407
      static void GetPNVertexs (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane, CVect3& P, CVect3& N);

      //## Operation: iTestBoxPlane%1007160406
      static int iTestBoxPlane (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane);

      //## Operation: iTestSpherePlane%1007160408
      static int iTestSpherePlane (CVect3& _Center, float _fRadius, CPlane& _Plane);

      //## Operation: iTestPointPlane%1011722643
      static int iTestPointPlane (CVect3& _roPoint, CPlane& _roPlane);

      //## Operation: fTriPointDistance%1007945050
      static float fTriPointDistance (CTriangle& _Tri, CVect3& _Point);

      //## Operation: fTriPointSqDistance%1007945052
      static float fTriPointSqDistance (CTriangle& _Tri, CVect3& _Point);

      //## Operation: oNearestTriPoint%1019590874
      static CVect3 oNearestTriPoint (CVect3& _roPoint, CTriangle& _roTri);

      //## Operation: GetMaxMins%1007945051
      static void GetMaxMins (float a, float b, float c, float &Max, float& Min);

      //## Operation: iTestRayTriIntersection%1008626800
      static int iTestRayTriIntersection (CRay& _Ray, CTriangle& _Tri);

      //## Operation: iTestRayTriIntersection%1008112115
      static int iTestRayTriIntersection (CRay& _Ray, CTriangle& _Tri, CVect3& _Point);

      //## Operation: iTestSegTriIntersection%1008626805
      static int iTestSegTriIntersection (CRay& _Ray, CTriangle& _Tri);

      //## Operation: iTestSegTriIntersection%1008626806
      static int iTestSegTriIntersection (CRay& _Ray, CTriangle& _Tri, CVect3& _Point);

      //## Operation: fGetT%1011825874
      static float fGetT ();

      //## Operation: iPointInsideTriangle%1008626801
      static int iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point, CVect3& _PPoint);

      //## Operation: iPointInsideTriangle%1008626799
      static int iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point);

      //## Operation: iTest3PlaneIntersection%1014585363
      static int iTest3PlaneIntersection (CPlane& _roPlane0, CPlane& _roPlane1, CPlane& _roPlane2, CVect3& _roPoint);

      //## Operation: iTest2PlaneIntersection%1014585364
      static int iTest2PlaneIntersection (CPlane& _roPlane0, CPlane& _roPlane1, CRay& _roRay);

      //## Operation: iTestRayAABBIntersection%1015279069
      static int iTestRayAABBIntersection (CRay& _roRay, CVect3& _roMaxs, CVect3& _roMins);

    // Additional Public Declarations
      //## begin MATH_Utils%3C080D120063.public preserve=yes
      //## end MATH_Utils%3C080D120063.public

  protected:
    // Additional Protected Declarations
      //## begin MATH_Utils%3C080D120063.protected preserve=yes
      //## end MATH_Utils%3C080D120063.protected

  private:
    // Additional Private Declarations
      //## begin MATH_Utils%3C080D120063.private preserve=yes
      //## end MATH_Utils%3C080D120063.private

  private: //## implementation
    // Additional Implementation Declarations
      //## begin MATH_Utils%3C080D120063.implementation preserve=yes
      //## end MATH_Utils%3C080D120063.implementation

};

//## begin MATH_Utils%3C080D120063.postscript preserve=yes
//## end MATH_Utils%3C080D120063.postscript

// Class MATH_Utils 


//## Other Operations (inline)
inline void MATH_Utils::GetMaxMins (float a, float b, float c, float &Max, float& Min)
{
  //## begin MATH_Utils::GetMaxMins%1007945051.body preserve=yes
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
  //## end MATH_Utils::GetMaxMins%1007945051.body
}

//## begin module%3C080D120063.epilog preserve=yes
//## end module%3C080D120063.epilog


#endif
