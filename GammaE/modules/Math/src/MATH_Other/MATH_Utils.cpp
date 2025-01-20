//## begin module%3C080D120063.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C080D120063.cm

//## begin module%3C080D120063.cp preserve=no
//## end module%3C080D120063.cp

//## Module: MATH_Utils%3C080D120063; Pseudo Package body
//## Source file: i:\Projects\GammaE\Math\MATH_Other\MATH_Utils.cpp

//## begin module%3C080D120063.additionalIncludes preserve=no
//## end module%3C080D120063.additionalIncludes

//## begin module%3C080D120063.includes preserve=yes
#include <math.h>

const float EPSILON			 = 1e-5f;
const float ONE_PLUS_EPSILON = 1.0f + EPSILON;
//## end module%3C080D120063.includes

// MATH_Utils
#include "Math\MATH_Other\MATH_Utils.h"
// MATH_Common
#include "Math\MATH_Other\MATH_Common.h"
//## begin module%3C080D120063.additionalDeclarations preserve=yes
static float	fU;
static float	fV;
static float	fT;
static float	fDet;
static float	fInvDet;
static CVect3	PVec,TVec,QVec;
//## end module%3C080D120063.additionalDeclarations


// Class MATH_Utils 

MATH_Utils::MATH_Utils()
  //## begin MATH_Utils::MATH_Utils%.hasinit preserve=no
  //## end MATH_Utils::MATH_Utils%.hasinit
  //## begin MATH_Utils::MATH_Utils%.initialization preserve=yes
  //## end MATH_Utils::MATH_Utils%.initialization
{
  //## begin MATH_Utils::MATH_Utils%.body preserve=yes
  //## end MATH_Utils::MATH_Utils%.body
}


MATH_Utils::~MATH_Utils()
{
  //## begin MATH_Utils::~MATH_Utils%.body preserve=yes
  //## end MATH_Utils::~MATH_Utils%.body
}



//## Other Operations (implementation)
void MATH_Utils::GetPNVertexs (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane, CVect3& P, CVect3& N)
{
  //## begin MATH_Utils::GetPNVertexs%1007160407.body preserve=yes
  	if (_Plane.Normal().v[2]>0)
    {
    	if (_Plane.Normal().v[1]>0)
        {
        	if (_Plane.Normal().v[0]>0)
            {
            	P = _Maxs;
                N = _Mins;
            }
        	else
            {
            	P.V3( _Mins.X(),_Maxs.Y(),_Maxs.Z() );
                N.V3( _Maxs.X(),_Mins.Y(),_Mins.Z() );
            }
        }
        else
        {
        	if (_Plane.Normal().v[0]>0)
            {
                P.V3(_Maxs.X(),_Mins.Y(),_Maxs.Z() );
                N.V3(_Mins.X(),_Maxs.Y(),_Mins.Z() );
            }
        	else
            {
            	P.V3(_Mins.X(),_Mins.Y(),_Maxs.Z() );
                N.V3(_Maxs.X(),_Maxs.Y(),_Mins.Z() );
            }
        }
    }
    else
    {
    	if (_Plane.Normal().v[1]>0)
        {
        	if (_Plane.Normal().v[0]>0)
            {
            	P.V3(_Maxs.X(),_Maxs.Y(),_Mins.Z());
                N.V3(_Mins.X(),_Mins.Y(),_Maxs.Z());
            }
        	else
            {
            	P.V3(_Mins.X(),_Maxs.Y(),_Mins.Z());
                N.V3(_Maxs.X(),_Mins.Y(),_Maxs.Z());
            }
        }
        else
        {
        	if (_Plane.Normal().v[0]>0)
            {
                P.V3(_Maxs.X(),_Mins.Y(),_Mins.Z());
                N.V3(_Mins.X(),_Maxs.Y(),_Maxs.Z());
            }
        	else
            {
            	P = _Mins;
                N = _Maxs;
            }
        }
    }
  //## end MATH_Utils::GetPNVertexs%1007160407.body
}

int MATH_Utils::iTestBoxPlane (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane)
{
  //## begin MATH_Utils::iTestBoxPlane%1007160406.body preserve=yes
  	CVect3 P,N;

    // Get PN vertices
	GetPNVertexs (_Maxs,_Mins,_Plane,P,N);

    // Compute plane distance to a point    
	if (_Plane.GetDistanceToPoint(N) > 0.0f) return( 1);		// front
    if (_Plane.GetDistanceToPoint(P) < 0.0f) return(-1);		// back
	return (0);													// Intersecting

  //## end MATH_Utils::iTestBoxPlane%1007160406.body
}

int MATH_Utils::iTestSpherePlane (CVect3& _Center, float _fRadius, CPlane& _Plane)
{
  //## begin MATH_Utils::iTestSpherePlane%1007160408.body preserve=yes
  	float fDist = _Plane.GetDistanceToPoint(_Center);

		 if (fDist >  _fRadius) return( 1);		// in front of plane
	else if (fDist < -_fRadius) return(-1);		// back of the plane
	return(0);									// intersecting
  //## end MATH_Utils::iTestSpherePlane%1007160408.body
}

int MATH_Utils::iTestPointPlane (CVect3& _roPoint, CPlane& _roPlane)
{
  //## begin MATH_Utils::iTestPointPlane%1011722643.body preserve=yes
	
	return ( (int)_roPlane.GetDistanceToPoint(_roPoint) );

  //## end MATH_Utils::iTestPointPlane%1011722643.body
}

float MATH_Utils::fTriPointDistance (CTriangle& _Tri, CVect3& _Point)
{
  //## begin MATH_Utils::fTriPointDistance%1007945050.body preserve=yes

	return ( MATH_Common::fSqrt(fTriPointSqDistance(_Tri,_Point)) );

  //## end MATH_Utils::fTriPointDistance%1007945050.body
}

float MATH_Utils::fTriPointSqDistance (CTriangle& _Tri, CVect3& _Point)
{
  //## begin MATH_Utils::fTriPointSqDistance%1007945052.body preserve=yes
	
	return ( _Point.SqDistance(oNearestTriPoint(_Point,_Tri)) );

  //## end MATH_Utils::fTriPointSqDistance%1007945052.body
}

CVect3 MATH_Utils::oNearestTriPoint (CVect3& _roPoint, CTriangle& _roTri)
{
  //## begin MATH_Utils::oNearestTriPoint%1019590874.body preserve=yes
	CPlane	oPlane;
	float	fMu,fLambda;
	CVect3	cp;
	CVect3	c;
	
	oPlane.GeneratePlaneFromFields(_roTri.VXs[0],_roTri.Normal);
	c = oPlane.ProjectPoint(_roPoint);
	
	// Get vector c - p
	cp.Assign(c);
	cp.Sub   (_roTri.VXs[0]);

    if (_roTri.e2.X() != 0.0f)
    {
        float fAux = _roTri.e2.Y() / _roTri.e2.X();
        fMu     = (cp.Y() - cp.X()*fAux   )/(_roTri.e1.Y() - _roTri.e1.X()*fAux);
        fLambda = (cp.X() - fMu*_roTri.e1.X())/_roTri.e2.X();
    }
    else
    {
        // float fAux = Tri.E2.v[0] / Tri.E2.v[1] = 0.0f / Tri.E2.v[1] = 0.0f;
        // fMu     = (cp.v[0] - cp.v[1]*fAux   )/(Tri.E1.v[0] - Tri.E1.v[1]*fAux);
        // fMu     = (cp.v[0] - cp.v[1]*0.0f   )/(Tri.E1.v[0] - Tri.E1.v[1]*0.0f);
        // fMu     = (cp.v[0]                  )/(Tri.E1.v[0]                   );
        fMu     = cp.X() / _roTri.e1.v[0];
        fLambda = (cp.Y() - fMu*_roTri.e1.Y())/_roTri.e2.Y();
    }

	// --------------
    // Select region:
    // --------------
	CSegment oSeg;	
    if (fMu<0.0f)
    {
		if (fLambda <= 0.0f)
		{
			// Region A
			return (_roTri.VXs[0]);
		}
		else
		{
			if (fLambda >= 1.0f)
				// Region E
				return (_roTri.VXs[2]);
			else
				// Region D
				c.Interpolate(_roTri.VXs[0],_roTri.VXs[2],fLambda);
				return(c);				
		}
    }
    else
    {
		if (fLambda < 0.0f)
		{
			if (fMu >1.0f)
			{
				// Region C
				return(_roTri.VXs[1]);
			}
			else
			{
				// Region B
				
				// fMu >0.0f,fMu <1.0f
				c.Interpolate(_roTri.VXs[0],_roTri.VXs[1],fMu);
				return( c );				
			}
		}
		else
		{
			// Region F
			if (fMu + fLambda > 1.0f)	
			{
				CSegment oSeg;
				oSeg.Init(_roTri.VXs[1],_roTri.VXs[2]);
				return ( oSeg.ProjectPoint(c) );				
			}
			else
			{
				// Region C
				return(c);
			}
		}
     }
  //## end MATH_Utils::oNearestTriPoint%1019590874.body
}

int MATH_Utils::iTestRayTriIntersection (CRay& _Ray, CTriangle& _Tri)
{
  //## begin MATH_Utils::iTestRayTriIntersection%1008626800.body preserve=yes
	// Mirar si el punto cae dentro del triangulo

	/* Ray-Triangle Intersection Test Routine           */
	/* Different optimizations of my and Ben Trumbore's */
	/* code from journals of graphics tools (JGT)       */
	/* http://www.acm.org/jgt/                          */
	/* by Tomas Möller, May 2000                        */

	/* code rewritten to do tests on the sign of the determinant */
	/* the division is before the test of the sign of the det    */

	/* find vectors for two edges sharing vert0 */
	
	/*
	_Tri.e0;
	_Tri.e1;
	*/
/*
	e1.Assign(_Tri.VXs[1]);	e1.Sub(_Tri.VXs[0]);
	e2.Assign(_Tri.VXs[2]);	e2.Sub(_Tri.VXs[0]);
*/
	/* begin calculating determinant - also used to calculate U parameter */
	PVec.CrossProd(_Ray.Dir,_Tri.e2);


	/* if determinant is near zero, ray lies in plane of triangle */
	// fDet = e1.DotProd(PVec);
	fDet = _Tri.e1.DotProd(PVec);

	// Avoid divide by 0
	if (fDet > -EPSILON && fDet < EPSILON) return 0;	

	// NOTE: The better approach of Tomar Möller in the intersection algorithm
	// uses a if statement wich implies conditional branching prediction misses
	// instead of this is preferable to perform the inverse multiplication of
	// fU and fV factors and compare against (0,1) range of values instead of
	// fU>0.0 and fu<fDet orfU<0.0 and fU >fDet when fDet is negative
	fInvDet = 1.0f / fDet;

	// calculate distance from vert0 to ray origin
	TVec.Assign(_Ray.Origin);	TVec.Sub(_Tri.VXs[0]);

	// calculate U parameter and test bounds
	fU = TVec.DotProd(PVec)*fInvDet;
	if (fU < -EPSILON || fU > ONE_PLUS_EPSILON) return 0;

	// prepare to test V parameter
	// QVec.CrossProd(TVec,e1);
	QVec.CrossProd(TVec,_Tri.e1);

	// calculate V parameter and test bounds
	fV = _Ray.Dir.DotProd(QVec)*fInvDet;
	if (fV < -EPSILON || fU + fV > ONE_PLUS_EPSILON) return 0;
	
	return(1);
  //## end MATH_Utils::iTestRayTriIntersection%1008626800.body
}

int MATH_Utils::iTestRayTriIntersection (CRay& _Ray, CTriangle& _Tri, CVect3& _Point)
{
  //## begin MATH_Utils::iTestRayTriIntersection%1008112115.body preserve=yes
	if (iTestRayTriIntersection(_Ray,_Tri))
	{
		// calculate t, ray intersects triangle
		fT = _Tri.e2.DotProd(QVec)*fInvDet;

		_Point.LineEq(_Ray.Origin,_Ray.Dir,fT);
	   return 1;
	}
	else
		return(0);
  //## end MATH_Utils::iTestRayTriIntersection%1008112115.body
}

int MATH_Utils::iTestSegTriIntersection (CRay& _Ray, CTriangle& _Tri)
{
  //## begin MATH_Utils::iTestSegTriIntersection%1008626805.body preserve=yes
	if (iTestRayTriIntersection (_Ray, _Tri))
	{
		// calculate t, ray intersects triangle
		fT = _Tri.e2.DotProd(QVec)*fInvDet;

		return(fT>=0.0f);				// above the point of origin
	}

	return(0);
  //## end MATH_Utils::iTestSegTriIntersection%1008626805.body
}

int MATH_Utils::iTestSegTriIntersection (CRay& _Ray, CTriangle& _Tri, CVect3& _Point)
{
  //## begin MATH_Utils::iTestSegTriIntersection%1008626806.body preserve=yes
	if (iTestSegTriIntersection(_Ray,_Tri))
	{
		_Point.LineEq(_Ray.Origin,_Ray.Dir,fT);
		return(1);
	}
	return(0);
  //## end MATH_Utils::iTestSegTriIntersection%1008626806.body
}

float MATH_Utils::fGetT ()
{
  //## begin MATH_Utils::fGetT%1011825874.body preserve=yes
	return(fT);
  //## end MATH_Utils::fGetT%1011825874.body
}

int MATH_Utils::iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point, CVect3& _PPoint)
{
  //## begin MATH_Utils::iPointInsideTriangle%1008626801.body preserve=yes
	CRay	Ray;

	Ray.Origin.Assign(_Point);
	Ray.Dir.Assign   (_Tri.Normal);

	return ( iTestRayTriIntersection (Ray, _Tri,_PPoint) );
  //## end MATH_Utils::iPointInsideTriangle%1008626801.body
}

int MATH_Utils::iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point)
{
  //## begin MATH_Utils::iPointInsideTriangle%1008626799.body preserve=yes
	CRay	Ray;

	Ray.Origin.Assign(_Point);
	Ray.Dir.Assign   (_Tri.Normal);
	
	return ( iTestRayTriIntersection (Ray,_Tri) );
  //## end MATH_Utils::iPointInsideTriangle%1008626799.body
}

int MATH_Utils::iTest3PlaneIntersection (CPlane& _roPlane0, CPlane& _roPlane1, CPlane& _roPlane2, CVect3& _roPoint)
{
  //## begin MATH_Utils::iTest3PlaneIntersection%1014585363.body preserve=yes
	float		fDet;
	CMatrix4x4	oMat;	
	CVect3		a,b,c,p;

	// Setup matrix
	oMat.SetRowVector(0,_roPlane0.Normal().X(),_roPlane0.Normal().Y(),_roPlane0.Normal().Z(),-1.0f*_roPlane0.D());
	oMat.SetRowVector(1,_roPlane1.Normal().X(),_roPlane1.Normal().Y(),_roPlane1.Normal().Z(),-1.0f*_roPlane1.D());
	oMat.SetRowVector(2,_roPlane2.Normal().X(),_roPlane2.Normal().Y(),_roPlane2.Normal().Z(),-1.0f*_roPlane2.D());
	oMat.SetRowVector(3,0.0f,0.0f,0.0f,1.0f);
	
	// Compute matrix determinant
	fDet = oMat.f3ColDeterminant(0,1,2);
	
	// Planes are linear dependent
	if (MATH_Common::fAbs(fDet) < _EPSILON_) return(0);


	a.CrossProd(_roPlane1.Normal(),_roPlane2.Normal());
	a.Scale(-1.0f*_roPlane0.D());
	
	b.CrossProd(_roPlane2.Normal(),_roPlane0.Normal());
	b.Scale(-1.0f*_roPlane1.D());

	c.CrossProd(_roPlane0.Normal(),_roPlane1.Normal());
	c.Scale(-1.0f*_roPlane2.D());

	// Setup intersection point
	_roPoint.Assign(a);
	_roPoint.Add   (b);
	_roPoint.Add   (c);
	_roPoint.Scale (1.0f / fDet);

	return(1);

  //## end MATH_Utils::iTest3PlaneIntersection%1014585363.body
}

int MATH_Utils::iTest2PlaneIntersection (CPlane& _roPlane0, CPlane& _roPlane1, CRay& _roRay)
{
  //## begin MATH_Utils::iTest2PlaneIntersection%1014585364.body preserve=yes
  /*
    Vector3d m, pt0;
  float demn;

  if ((plane2.GetNorm()).IsParallel(GetNorm()))
    return false;

  m.CrossVector(GetNorm(), plane2.GetNorm());
  // Sanity Check.
  ASSERT(m.GetMag() > 0.0f);

  float dx = ABS(m.GetX());
  float dy = ABS(m.GetY());
  float dz = ABS(m.GetZ());

  if (dx >= dy && dx >= dz) {
    ASSERT(!EQUAL4(m.GetX(), 0.0f));
    demn = n.GetY() * plane2.n.GetZ() - n.GetZ() * plane2.n.GetY();
    ASSERT(demn != 0.0f);  // Sanity Check.

    pt0.SetX(0.0f);
    pt0.SetY((d * plane2.n.GetZ() - n.GetZ() * plane2.d) / demn);
    pt0.SetZ((n.GetY() * plane2.d - plane2.n.GetY() * d) / demn);
  }
  else if (dy >= dx && dy >= dz) {
    ASSERT(!EQUAL4(m.GetY(), 0.0f));
    demn = n.GetZ() * plane2.n.GetX() - n.GetX() * plane2.n.GetZ();
    ASSERT(demn != 0.0f);

    pt0.SetX((n.GetZ() * plane2.d - plane2.n.GetZ() * d) / demn);
    pt0.SetY(0.0f);
    pt0.SetZ((plane2.n.GetX() * d - n.GetX() * plane2.d) / demn);
  }
  else { // m.GetZ() != 0.0f
    // Sanity.
    ASSERT(dz >= dx && dz >= dy);
    ASSERT(!EQUAL4(m.GetZ(), 0.0f));

    demn = n.GetY() * plane2.n.GetX() - n.GetX() * plane2.n.GetY();
    ASSERT(demn != 0.0f);  // Sanity Check.

    pt0.SetX((n.GetY() * plane2.d - plane2.n.GetY() * d) / demn);
    pt0.SetY((plane2.n.GetX() * d - n.GetX() * plane2.d) / demn);
    pt0.SetZ(0.0f);
  }

  l.NewLine(pt0, m);
  return true;
  */
	return(0);
  //## end MATH_Utils::iTest2PlaneIntersection%1014585364.body
}

int MATH_Utils::iTestRayAABBIntersection (CRay& _roRay, CVect3& _roMaxs, CVect3& _roMins)
{
  //## begin MATH_Utils::iTestRayAABBIntersection%1015279069.body preserve=yes
	
	/*
	Fast Rat-Box Intersection
	by Andrew Woo
	from "Graphics Gems", Academic Press,1990
	*/

	#define Q_RIGHT  0
	#define Q_LEFT   1
	#define Q_MIDDLE 2

	int		i;
	char	cQuadrant[3];
	CVect3  oCPlane;
	CVect3  oMaxT;
	bool	bInside = true;
	int		iWhichPlane;
	CVect3	oPoint;
	
	// Find candidate planes
	for (i=0;i<3;i++)
	{
		if (_roRay.Origin.v[i] < _roMins.v[i])
		{
			cQuadrant[i] = Q_LEFT;
			oCPlane.v[i] = _roMins.v[i];
			bInside		 = false;
		}
   else if (_roRay.Origin.v[i] > _roMaxs.v[i])
		{
			cQuadrant[i]  = Q_RIGHT;
			oCPlane.v[i]  = _roMaxs.v[i];
			bInside		  = false;
		}
	else{
			cQuadrant[i]  = Q_MIDDLE;			
		}
	}

	// Ray origin inside bounding box
	if (bInside)
	{
		// IntersectionPoint = _roRay.Origin;
		return(1);
	}
	
	// Compute T distances to candidate planes
	for (i=0;i<3;i++)
	{
		if ((cQuadrant[i] != Q_MIDDLE) && (_roRay.Dir.v[i] != 0.0f))
			oMaxT.v[i] = (oCPlane.v[i] - _roRay.Origin.v[i]) / _roRay.Dir.v[i];
		else
			oMaxT.v[i] = -1.0f;
	}

	// Get largest maxT for final choice of intersection	
	iWhichPlane = 0;
	for (i=1;i<3;i++)
		if (oMaxT.v[iWhichPlane]<oMaxT.v[iWhichPlane])
			iWhichPlane = i;
	
	// Check final candidate actually inside box
	if (oMaxT.v[iWhichPlane]<0.0f) return (0);
	
	CVect3 _roPoint;
	for (i=0;i<3;i++)
	{
		if (iWhichPlane != i)
		{			
			_roPoint.v[i] = _roRay.Origin.v[i] + oMaxT.v[iWhichPlane]*_roRay.Dir.v[i];

			if ((_roPoint.v[i] < _roMins.v[i]) || (_roPoint.v[i] > _roMaxs.v[i])) 
				return(0);
		}
		else
		{
			_roPoint.v[i] = oCPlane.v[i];	
		}
	}

	return(1);
	
	#undef Q_RIGHT
	#undef Q_LEFT
	#undef Q_MIDDLE
  //## end MATH_Utils::iTestRayAABBIntersection%1015279069.body
}

// Additional Declarations
  //## begin MATH_Utils%3C080D120063.declarations preserve=yes
  //## end MATH_Utils%3C080D120063.declarations

//## begin module%3C080D120063.epilog preserve=yes
//## end module%3C080D120063.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin MATH_Utils::iPointBelongsTriangle%1020464100.body preserve=no

	// Point belongs the triangle iff:
	//	Point is contained in the triangle
	//	Point/TrianglePlane distance = 0

	if (_Tri

//## end MATH_Utils::iPointBelongsTriangle%1020464100.body

#endif
