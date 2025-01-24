//	  %X% %Q% %Z% %W%




#include <math.h>

const float EPSILON			 = 1e-5f;
const float ONE_PLUS_EPSILON = 1.0f + EPSILON;

// MATH_Utils
#include "MATH_Other\MATH_Utils.h"
// MATH_Common
#include "MATH_Other\MATH_Common.h"
static float	fU;
static float	fV;
static float	fT;
static float	fDet;
static float	fInvDet;
static CVect3	PVec,TVec,QVec;


// Class MATH_Utils 

MATH_Utils::MATH_Utils()
        {
}


MATH_Utils::~MATH_Utils()
{
}



void MATH_Utils::GetPNVertexs (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane, CVect3& P, CVect3& N)
{
    	if (_Plane.Normal().z>0)
    {
    	if (_Plane.Normal().y>0)
        {
        	if (_Plane.Normal().x>0)
            {
            	P = _Maxs;
                N = _Mins;
}
        	else
            {
            	P.V3( _Mins.x,_Maxs.y,_Maxs.z );
                N.V3( _Maxs.x,_Mins.y,_Mins.z );
}
}
        else
        {
        	if (_Plane.Normal().x>0)
            {
                P.V3(_Maxs.x,_Mins.y,_Maxs.z );
                N.V3(_Mins.x,_Maxs.y,_Mins.z );
}
        	else
            {
            	P.V3(_Mins.x,_Mins.y,_Maxs.z );
                N.V3(_Maxs.x,_Maxs.y,_Mins.z );
}
}
}
    else
    {
    	if (_Plane.Normal().y>0)
        {
        	if (_Plane.Normal().x>0)
            {
            	P.V3(_Maxs.x,_Maxs.y,_Mins.z);
                N.V3(_Mins.x,_Mins.y,_Maxs.z);
}
        	else
            {
            	P.V3(_Mins.x,_Maxs.y,_Mins.z);
                N.V3(_Maxs.x,_Mins.y,_Maxs.z);
}
}
        else
        {
        	if (_Plane.Normal().x>0)
            {
                P.V3(_Maxs.x,_Mins.y,_Mins.z);
                N.V3(_Mins.x,_Maxs.y,_Maxs.z);
}
        	else
            {
            	P = _Mins;
                N = _Maxs;
}
}
}
}

int MATH_Utils::iTestBoxPlane (CVect3& _Maxs, CVect3& _Mins, CPlane& _Plane)
{
    	CVect3 P,N;

    // Get PN vertices
	GetPNVertexs (_Maxs,_Mins,_Plane,P,N);

    // Compute plane distance to a point    
	if (_Plane.GetDistanceToPoint(N) > 0.0f) return( 1);		// front
    if (_Plane.GetDistanceToPoint(P) < 0.0f) return(-1);		// back
	return (0);													// Intersecting

}

int MATH_Utils::iTestSpherePlane (CVect3& _Center, float _fRadius, CPlane& _Plane)
{
    	float fDist = _Plane.GetDistanceToPoint(_Center);

		 if (fDist >  _fRadius) return( 1);		// in front of plane
	else if (fDist < -_fRadius) return(-1);		// back of the plane
	return(0);									// intersecting
}

int MATH_Utils::iTestPointPlane (CVect3& _oPoint, CPlane& _oPlane)
{
  	
	return ( (int)_oPlane.GetDistanceToPoint(_oPoint) );

}

float MATH_Utils::fTriPointDistance (CTriangle& _Tri, CVect3& _Point)
{
  
	return ( MATH_Common::fSqrt(fTriPointSqDistance(_Tri,_Point)) );

}

float MATH_Utils::fTriPointSqDistance (CTriangle& _Tri, CVect3& _Point)
{
  
	CVect3 oPnt = oNearestTriPoint(_Point,_Tri);
	return ( _Point.fSqDistance(oPnt) );

}

CVect3 MATH_Utils::oNearestTriPoint (CVect3& _oPoint, CTriangle& _oTri)
{
  	CPlane	oPlane;
	float	fMu,fLambda;
	CVect3	cp;
	CVect3	c;
	
	oPlane.GeneratePlaneFromFields(_oTri.VXs[0],_oTri.Normal);
	c = oPlane.ProjectPoint(_oPoint);
	
	// Get vector c - p
	cp.Assign(c);
	cp.Sub   (_oTri.VXs[0]);

    if (_oTri.e2.x != 0.0f)
    {
        float fAux = _oTri.e2.y / _oTri.e2.x;
        fMu     = (cp.y - cp.x*fAux   )/(_oTri.e1.y - _oTri.e1.x*fAux);
        fLambda = (cp.x - fMu*_oTri.e1.x)/_oTri.e2.x;
}
    else
    {
        // float fAux = Tri.E2[0] / Tri.E2[1] = 0.0f / Tri.E2[1] = 0.0f;
        // fMu     = (cp[0] - cp[1]*fAux   )/(Tri.E1[0] - Tri.E1[1]*fAux);
        // fMu     = (cp[0] - cp[1]*0.0f   )/(Tri.E1[0] - Tri.E1[1]*0.0f);
        // fMu     = (cp[0]                  )/(Tri.E1[0]                   );
        fMu     = cp.x / _oTri.e1.x;
        fLambda = (cp.y - fMu*_oTri.e1.y)/_oTri.e2.y;
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
			return (_oTri.VXs[0]);
		}
		else
		{
			if (fLambda >= 1.0f)
				// Region E
				return (_oTri.VXs[2]);
			else
				// Region D
				c.Interpolate(_oTri.VXs[0],_oTri.VXs[2],fLambda);
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
				return(_oTri.VXs[1]);
			}
			else
			{
				// Region B
				
				// fMu >0.0f,fMu <1.0f
				c.Interpolate(_oTri.VXs[0],_oTri.VXs[1],fMu);
				return( c );				
			}
		}
		else
		{
			// Region F
			if (fMu + fLambda > 1.0f)	
			{
				CSegment oSeg;
				oSeg.Init(_oTri.VXs[1],_oTri.VXs[2]);
				return ( oSeg.ProjectPoint(c) );				
			}
			else
			{
				// Region C
				return(c);
			}
		}
}
}

int MATH_Utils::iTestRayTriIntersection (CRay& _ay, CTriangle& _Tri)
{
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
	PVec.CrossProd(_ay.Dir,_Tri.e2);


	/* if determinant is near zero, ray lies in plane of triangle */
	// fDet = e1.DotProd(PVec);
	fDet = _Tri.e1.fDotProd(PVec);

	// Avoid divide by 0
	if (fDet > -EPSILON && fDet < EPSILON) return 0;	

	// NOTE: The better approach of Tomar Möller in the intersection algorithm
	// uses a if statement wich implies conditional branching prediction misses
	// instead of this is preferable to perform the inverse multiplication of
	// fU and fV factors and compare against (0,1) range of values instead of
	// fU>0.0 and fu<fDet orfU<0.0 and fU >fDet when fDet is negative
	fInvDet = 1.0f / fDet;

	// calculate distance from vert0 to ray origin
	TVec.Assign(_ay.Origin);	TVec.Sub(_Tri.VXs[0]);

	// calculate U parameter and test bounds
	fU = TVec.fDotProd(PVec)*fInvDet;
	if (fU < -EPSILON || fU > ONE_PLUS_EPSILON) return 0;

	// prepare to test V parameter
	// QVec.CrossProd(TVec,e1);
	QVec.CrossProd(TVec,_Tri.e1);

	// calculate V parameter and test bounds
	fV = _ay.Dir.fDotProd(QVec)*fInvDet;
	if (fV < -EPSILON || fU + fV > ONE_PLUS_EPSILON) return 0;
	
	return(1);
}

int MATH_Utils::iTestRayTriIntersection (CRay& _ay, CTriangle& _Tri, CVect3& _Point)
{
  	if (iTestRayTriIntersection(_ay,_Tri))
	{
		// calculate t, ray intersects triangle
		fT = _Tri.e2.fDotProd(QVec)*fInvDet;

		_Point.LineEq(_ay.Origin,_ay.Dir,fT);
	   return 1;
	}
	else
		return(0);
}

int MATH_Utils::iTestSegTriIntersection (CRay& _ay, CTriangle& _Tri)
{
  	if (iTestRayTriIntersection (_ay, _Tri))
	{
		// calculate t, ray intersects triangle
		fT = _Tri.e2.fDotProd(QVec)*fInvDet;

		return(fT>=0.0f);				// above the point of origin
	}

	return(0);
}

int MATH_Utils::iTestSegTriIntersection (CRay& _ay, CTriangle& _Tri, CVect3& _Point)
{
  	if (iTestSegTriIntersection(_ay,_Tri))
	{
		_Point.LineEq(_ay.Origin,_ay.Dir,fT);
		return(1);
	}
	return(0);
}

float MATH_Utils::fGetT ()
{
  	return(fT);
}

int MATH_Utils::iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point, CVect3& _PPoint)
{
  	CRay	Ray;

	Ray.Origin.Assign(_Point);
	Ray.Dir.Assign   (_Tri.Normal);

	return ( iTestRayTriIntersection (Ray, _Tri,_PPoint) );
}

int MATH_Utils::iPointInsideTriangle (CTriangle& _Tri, CVect3& _Point)
{
  	CRay	Ray;

	Ray.Origin.Assign(_Point);
	Ray.Dir.Assign   (_Tri.Normal);
	
	return ( iTestRayTriIntersection (Ray,_Tri) );
}

int MATH_Utils::iTest3PlaneIntersection (CPlane& _oPlane0, CPlane& _oPlane1, CPlane& _oPlane2, CVect3& _oPoint)
{
  	float		fDet;
	CMatrix4x4	oMat;	
	CVect3		a,b,c,p;

	// Setup matrix
	oMat.SetRowVector(0,_oPlane0.Normal().x,_oPlane0.Normal().y,_oPlane0.Normal().z,-1.0f*_oPlane0.D());
	oMat.SetRowVector(1,_oPlane1.Normal().x,_oPlane1.Normal().y,_oPlane1.Normal().z,-1.0f*_oPlane1.D());
	oMat.SetRowVector(2,_oPlane2.Normal().x,_oPlane2.Normal().y,_oPlane2.Normal().z,-1.0f*_oPlane2.D());
	oMat.SetRowVector(3,0.0f,0.0f,0.0f,1.0f);
	
	// Compute matrix determinant
	fDet = oMat.f3ColDeterminant(0,1,2);
	
	// Planes are linear dependent
	if (MATH_Common::fAbs(fDet) < _EPSILON_) return(0);


	a.CrossProd(_oPlane1.Normal(),_oPlane2.Normal());
	a.Scale(-1.0f*_oPlane0.D());
	
	b.CrossProd(_oPlane2.Normal(),_oPlane0.Normal());
	b.Scale(-1.0f*_oPlane1.D());

	c.CrossProd(_oPlane0.Normal(),_oPlane1.Normal());
	c.Scale(-1.0f*_oPlane2.D());

	// Setup intersection point
	_oPoint.Assign(a);
	_oPoint.Add   (b);
	_oPoint.Add   (c);
	_oPoint.Scale (1.0f / fDet);

	return(1);

}

int MATH_Utils::iTest2PlaneIntersection (CPlane& _oPlane0, CPlane& _oPlane1, CRay& _oRay)
{
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

    pt0.x = 0.0f;
    pt0.y = (d * plane2.n.GetZ() - n.GetZ() * plane2.d) / demn;
    pt0.z = (n.GetY() * plane2.d - plane2.n.GetY() * d) / demn;
}
  else if (dy >= dx && dy >= dz) {
    ASSERT(!EQUAL4(m.GetY(), 0.0f));
    demn = n.GetZ() * plane2.n.GetX() - n.GetX() * plane2.n.GetZ();
    ASSERT(demn != 0.0f);

    pt0.x = (n.GetZ() * plane2.d - plane2.n.GetZ() * d) / demn;
    pt0.y = 0.0f;
    pt0.z = (plane2.n.GetX() * d - n.GetX() * plane2.d) / demn;
}
  else { // m.GetZ() != 0.0f
    // Sanity.
    ASSERT(dz >= dx && dz >= dy);
    ASSERT(!EQUAL4(m.GetZ(), 0.0f));

    demn = n.GetY() * plane2.n.GetX() - n.GetX() * plane2.n.GetY();
    ASSERT(demn != 0.0f);  // Sanity Check.

    pt0.x = (n.GetY() * plane2.d - plane2.n.GetY() * d) / demn;
    pt0.y = (plane2.n.GetX() * d - n.GetX() * plane2.d) / demn;
    pt0.z = 0.0f;
}

  l.NewLine(pt0, m);
  return true;
  */
	return(0);
}

int MATH_Utils::iTestRayAABBIntersection (CRay& _oRay, CVect3& _oMaxs, CVect3& _oMins)
{
  	
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
		if (_oRay.Origin.v(i) < _oMins.v(i))
		{
			cQuadrant[i] = Q_LEFT;
			oCPlane.v(i) = _oMins.v(i);
			bInside		 = false;
		}
   else if (_oRay.Origin.v(i) > _oMaxs.v(i))
		{
			cQuadrant[i]  = Q_RIGHT;
			oCPlane.v(i)  = _oMaxs.v(i);
			bInside		  = false;
		}
	else{
			cQuadrant[i]  = Q_MIDDLE;			
		}
	}

	// Ray origin inside bounding box
	if (bInside)
	{
		// IntersectionPoint = _oRay.Origin;
		return(1);
	}
	
	// Compute T distances to candidate planes
	for (i=0;i<3;i++)
	{
		if ((cQuadrant[i] != Q_MIDDLE) && (_oRay.Dir.v(i) != 0.0f))
			oMaxT.v(i) = (oCPlane.v(i) - _oRay.Origin.v(i)) / _oRay.Dir.v(i);
		else
			oMaxT.v(i) = -1.0f;
	}

	// Get largest maxT for final choice of intersection	
	iWhichPlane = 0;
	for (i=1;i<3;i++)
		if (oMaxT.v(iWhichPlane) < oMaxT.v(iWhichPlane))
			iWhichPlane = i;
	
	// Check final candidate actually inside box
	if (oMaxT.v(iWhichPlane)<0.0f) return (0);
	
	CVect3 _oPoint;
	for (i=0;i<3;i++)
	{
		if (iWhichPlane != i)
		{			
			_oPoint.v(i) = _oRay.Origin.v(i) + oMaxT.v(iWhichPlane) * _oRay.Dir.v(i);

			if ((_oPoint.v(i) < _oMins.v(i)) || (_oPoint.v(i) > _oMaxs.v(i))) 
				return(0);
		}
		else
		{
			_oPoint.v(i) = oCPlane.v(i);	
		}
	}

	return(1);
	
	#undef Q_RIGHT
	#undef Q_LEFT
	#undef Q_MIDDLE
}

// Additional Declarations
    


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0

	// Point belongs the triangle iff:
	//	Point is contained in the triangle
	//	Point/TrianglePlane distance = 0

	if (_Tri


#endif
