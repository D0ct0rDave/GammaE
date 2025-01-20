//## begin module%3C1FBCC302E6.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C1FBCC302E6.cm

//## begin module%3C1FBCC302E6.cp preserve=no
//## end module%3C1FBCC302E6.cp

//## Module: CCOL_DT_Sphere%3C1FBCC302E6; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.cpp

//## begin module%3C1FBCC302E6.additionalIncludes preserve=no
//## end module%3C1FBCC302E6.additionalIncludes

//## begin module%3C1FBCC302E6.includes preserve=yes
//## end module%3C1FBCC302E6.includes

// CCOL_DT_Sphere
#include "Collision\COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h"
//## begin module%3C1FBCC302E6.additionalDeclarations preserve=yes


// Article by Miguel Gómez Gamasutra

inline bool bQuadraticFormula(float a,float b,float c,float &r1,float &r2)
{

	// ---------------------------------------------------
	// Valid solutions in a quadratic function:
	//         _________
	// -b +- \/b^2 - 4ac
	// -----------------
	//         2a
	// ---------------------------------------------------

	float q = b*b - 4*a*c;

	if (q >= 0)
	{
		float sq = MATH_Common::fSqrt(q);
		float  d = 1.0f / (2*a);
		
		r1 = (-b + sq)*d;
		r2 = (-b - sq)*d;

		return (true);
	}
	else
		return (false);
}

//## end module%3C1FBCC302E6.additionalDeclarations


// Class CCOL_DT_Sphere 

CCOL_DT_Sphere::CCOL_DT_Sphere()
  //## begin CCOL_DT_Sphere::CCOL_DT_Sphere%.hasinit preserve=no
  //## end CCOL_DT_Sphere::CCOL_DT_Sphere%.hasinit
  //## begin CCOL_DT_Sphere::CCOL_DT_Sphere%.initialization preserve=yes
  //## end CCOL_DT_Sphere::CCOL_DT_Sphere%.initialization
{
  //## begin CCOL_DT_Sphere::CCOL_DT_Sphere%.body preserve=yes
  //## end CCOL_DT_Sphere::CCOL_DT_Sphere%.body
}


CCOL_DT_Sphere::~CCOL_DT_Sphere()
{
  //## begin CCOL_DT_Sphere::~CCOL_DT_Sphere%.body preserve=yes
  //## end CCOL_DT_Sphere::~CCOL_DT_Sphere%.body
}



//## Other Operations (implementation)
float CCOL_DT_Sphere::fTestSphere (CVect3& _roSCenter, float _fSRadius, CVect3& _roDCenter, float _fDRadius)
{
  //## begin CCOL_DT_Sphere::fTestSphere%1008711896.body preserve=yes
	CVect3 vA;
	CVect3 vB;
	CVect3 BA;
	CVect3 vBA;

	float fRadiiSum;
	float fSqRadiiSum;
	float fSqDist;
	float a,b,c,u0,u1;

	// Radius of separation
	fRadiiSum	= _fSRadius + _fDRadius;
	fSqRadiiSum = fRadiiSum*fRadiiSum;

	// Relative position of B from A
	BA.Assign(_roDCenter);	BA.Sub(_roSCenter);
	
	// Squared distance between A and B
	fSqDist = BA.SqModule();				

	// Check if they are currently colliding at instant 0
	if (fSqDist <= fSqRadiiSum) 
		return (0.0f);				// Trivial rejection


	// Velocities
	vA.Assign(CCOL_ColState::SrcFPos);
	vA.Sub   (CCOL_ColState::SrcIPos);

	vB.Assign(CCOL_ColState::DstFPos);
	vB.Assign(CCOL_ColState::DstIPos);

	// Get relative speed of B from A
	vBA.Assign(CCOL_ColState::DSSp);
	vBA.Assign(vB);
	vBA.Sub   (vA);

	// u*u coheficient
	a = vBA.SqModule();
	if (! a) return(-1.0f);	// Objects are not moving

	// u coheficient
	b = 2*vBA.DotProd(BA);

	// constant term
	c = fSqDist - fSqRadiiSum;

	// Check for collision during dDelta
	if (bQuadraticFormula(a,b,c,u0,u1))
	{		
		if (u0 > u1)
		{
			if (u1 < 1.0f)
				return (u1);
			else
				return(-1.0f);
		}
		else
		{
			if (u0 < 1.0f)
				return (u0);
			else
				return(-1.0f);
		}
	}
	else
		return (-1.0f);
  //## end CCOL_DT_Sphere::fTestSphere%1008711896.body
}

float CCOL_DT_Sphere::fTestBox (CVect3& _roSCenter, float _fSRadius, CVect3& _roDMaxs, CVect3& _roDMins)
{
  //## begin CCOL_DT_Sphere::fTestBox%1008711897.body preserve=yes

	CVect3	DCenter;
	float	DRadius;

	DCenter.Assign(_roDMaxs);
	DCenter.Sub   (_roDMins);
	DRadius = DCenter.Module() * 0.5f;
	
	DCenter.Interpolate(_roDMins,_roDMaxs,0.5f);	
		
	return( fTestSphere(_roSCenter,_fSRadius,DCenter,DRadius) );
	
	/*
	if (CCOL_ST_Sphere::iTestBox(_roSCenter,_fSRadius,_roDMaxs,_roDMins)) return(0.0f);

	CVect3 vA;
	CVect3 vB;
	CVect3 BA;
	CVect3 vBA;

	float fRadiiSum;
	float fSqRadiiSum;
	float fSqDist;
	float a,b,c,u0,u1;

	CSegment oSeg;
	oSeg.Init(CCOL_ColState::SrcIPos,CCOL_ColState::SrcFPos);

	CVect3 BoxCenter;
	BoxCenter.Interpolate(_roDMins,_roDMaxs,0.5f);
	
	CVect3 SegCenter;
	SegCenter.Interpolate(CCOL_ColState::SrcIPos,
						  CCOL_ColState::SrcFPos,0.5f);

	CVect3 SegNormal;
	SegNormal.Orthogonal();
	
	CVect3 BSCenters;
	BSCenters.Assign( SegCenter );
	BSCenters.Sub   ( BoxCenter );

	// Relative position of B from A
	BA.Assign(_roDCenter);	BA.Sub(_roSCenter);

	// Squared distance between A and B
	fSqDist = BA.SqModule();				

	// Check if they are currently colliding at instant 0
	if (fSqDist <= fSqRadiiSum) 
		return (0.0f);				// Trivial rejection


	// Velocities
	vA.Assign(CCOL_ColState::SrcFPos);
	vA.Sub   (CCOL_ColState::SrcIPos);

	vB.Assign(CCOL_ColState::DstFPos);
	vB.Assign(CCOL_ColState::DstIPos);


	// Get relative speed of B from A
	vBA.Assign(CCOL_ColState::DSSp);
	vBA.Assign(vB);
	vBA.Sub   (vA);

	// u*u coheficient
	a = vBA.SqModule();
	if (! a) return(-1.0f);	// Objects are not moving
	*/
  //## end CCOL_DT_Sphere::fTestBox%1008711897.body
}

float CCOL_DT_Sphere::fTestPoint (CVect3& _roSCenter, float _fSRadius, CVect3& _roDPoint)
{
  //## begin CCOL_DT_Sphere::fTestPoint%1008711898.body preserve=yes
	CVect3	oIPos;
	CVect3	oSeg;
	float	a,b,c,u0,u1;
	float	fSqDist;
	float	fSqRadii;

	// Get initial position relative to the sphere
	oIPos.Assign(_roDPoint);
	oIPos.Sub   (_roSCenter);
	
	fSqDist		= oIPos.SqModule();
	fSqRadii	= _SQ_(_fSRadius);

	// Test for trivial rejection at instant 0
	c = fSqDist - fSqRadii;	// useful later
		
	if (c < 0.0f) // This means that the point is inside the sphere
		return(0.0f);

	// Get final position relative to sphere reference system
	oSeg.Assign(CCOL_ColState::DSSp);
	oSeg.Scale (CCOL_ColState::fDeltaT);

	a = oSeg.SqModule();

	b = 2*oSeg.DotProd(oIPos);
	
	// Check for collision during dDelta
	if (bQuadraticFormula(a,b,c,u0,u1))
	{
		if (u0 > u1)
			return (u1*CCOL_ColState::fDeltaT);
		else
			return (u0*CCOL_ColState::fDeltaT);
	}
	else
		return (-1.0f);
  //## end CCOL_DT_Sphere::fTestPoint%1008711898.body
}

// Additional Declarations
  //## begin CCOL_DT_Sphere%3C1FBCC302E6.declarations preserve=yes
  //## end CCOL_DT_Sphere%3C1FBCC302E6.declarations

//## begin module%3C1FBCC302E6.epilog preserve=yes
//## end module%3C1FBCC302E6.epilog
