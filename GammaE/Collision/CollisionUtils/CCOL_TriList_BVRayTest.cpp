//## begin module%3C16A0340259.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3C16A0340259.cm

//## begin module%3C16A0340259.cp preserve=no
//## end module%3C16A0340259.cp

//## Module: CCOL_TriList_BVRayTest%3C16A0340259; Pseudo Package body
//## Source file: i:\Projects\GammaE\Collision\CollisionUtils\CCOL_TriList_BVRayTest.cpp

//## begin module%3C16A0340259.additionalIncludes preserve=no
//## end module%3C16A0340259.additionalIncludes

//## begin module%3C16A0340259.includes preserve=yes
//## end module%3C16A0340259.includes

// CCOL_TriList_BVRayTest
#include "Collision\CollisionUtils\CCOL_TriList_BVRayTest.h"
//## begin module%3C16A0340259.additionalDeclarations preserve=yes
//## end module%3C16A0340259.additionalDeclarations


// Class CCOL_TriList_BVRayTest 

CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest()
  //## begin CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest%.hasinit preserve=no
  //## end CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest%.hasinit
  //## begin CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest%.initialization preserve=yes
  //## end CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest%.initialization
{
  //## begin CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest%.body preserve=yes
  //## end CCOL_TriList_BVRayTest::CCOL_TriList_BVRayTest%.body
}


CCOL_TriList_BVRayTest::~CCOL_TriList_BVRayTest()
{
  //## begin CCOL_TriList_BVRayTest::~CCOL_TriList_BVRayTest%.body preserve=yes
  //## end CCOL_TriList_BVRayTest::~CCOL_TriList_BVRayTest%.body
}



//## Other Operations (implementation)
void CCOL_TriList_BVRayTest::Test (CVect3& _Center, CCOL_TriList& _TriList, int _iRayMask, float* _pa6fDists, int* _pa6iTris)
{
  //## begin CCOL_TriList_BVRayTest::Test%1008112117.body preserve=yes
	CRay	Ray;
	int		iAxis;
	CVect3		Axis[6] = {	CVect3( 1.0f,0.0f,0.0f),
							CVect3(-1.0f,0.0f,0.0f),
							CVect3(0.0f, 1.0f,0.0f),
							CVect3(0.0f,-1.0f,0.0f),
							CVect3(0.0f,0.0f, 1.0f),
							CVect3(0.0f,0.0f,-1.0f)};
	
	// Init ray origin as the center ob the BV object
	Ray.Origin.Assign(_Center);

	for (iAxis=0;iAxis<6;iAxis++)
	{
		// Init as non colliding axis
		_pa6iTris [iAxis] = -1;
		_pa6fDists[iAxis] = -1.0f;

		// Need to test this axis?
		if (_iRayMask & (1<< iAxis))
		{
			// Assign axis direction
			Ray.Dir.Assign(Axis[iAxis]);

			// Get the minimum distance of the triangle and the tris
			_pa6fDists[iAxis] = fGetRayTriListMinDist(Ray,_TriList,Ray.Origin,_pa6iTris[iAxis]);
			
			if (_pa6iTris[iAxis] != -1)
				_pa6fDists[iAxis] = MATH_Common::fSqrt(_pa6fDists[iAxis]);
		}
	}
  //## end CCOL_TriList_BVRayTest::Test%1008112117.body
}

float CCOL_TriList_BVRayTest::fGetRayTriListMinDist (CRay& _Ray, CCOL_TriList& _TriList, CVect3& _Point, int& _iIdx)
{
  //## begin CCOL_TriList_BVRayTest::fGetRayTriListMinDist%1008112120.body preserve=yes
	
	// <UNMAINTAINED>
	CTriangle	Tri;
	
	CVect3		IPoint;			// Intersection point	
	int			iTri;	
	float		fDist;
	float		fMinDist;

	_iIdx	 = -1;
	fMinDist = 1e6;
	for (iTri=0;iTri<_TriList.iNumTris;iTri++)
	{
		Tri.Init(&_TriList.poVXs[3*iTri], _TriList.poVNs[iTri] );
		Tri.ComputeAll();

		if (MATH_Utils::iTestSegTriIntersection(_Ray,Tri,IPoint))
		{
			fDist = _Ray.Origin.SqDistance(IPoint);
			if (fDist<fMinDist)
			{
				fMinDist = fDist;
				_iIdx	 = iTri;
			}
		}
	}
	
	return(fMinDist);
  //## end CCOL_TriList_BVRayTest::fGetRayTriListMinDist%1008112120.body
}

// Additional Declarations
  //## begin CCOL_TriList_BVRayTest%3C16A0340259.declarations preserve=yes
  //## end CCOL_TriList_BVRayTest%3C16A0340259.declarations

//## begin module%3C16A0340259.epilog preserve=yes
//## end module%3C16A0340259.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CCOL_TriList_BVRayTest::TestBox%1008112118.body preserve=no
	int		iCorner;
	int		iTest;

	CRay	Ray;	
	CVect3  *Corner;
	CVect3	Center;
	CVect3	Extents;	

	Center	= _pBV.GetCenter();
	Extents = _pBV.GetExtents();
	Extents.Scale(0.5f);

	Ray.Origin.Assign(Center);
	Ray.Origin.V3 (Center.X() - Extents.X(),Center.Y() - Extents.Y(),Center.Z() - Extents.Z());
	
	iTest  = 0;
	Corner = _pBV.Vol.Points;
	for (iCorner=0;iCorner<8;iCorner++)
	{		
		Ray.Origin.Assign(*Corner);

		// Test in X direction
		Ray.Dir.V3(1.0f,0.0f,0.0f);
		_pa24fDists[iTest] = fGetRayTriListMinDist(Ray,_TriList,*Corner,_pa24iTris[iTest]);
		iTest++;

		Ray.Dir.V3(0.0f,1.0f,0.0f);
		_pa24fDists[iTest] = fGetRayTriListMinDist(Ray,_TriList,*Corner,_pa24iTris[iTest]);
		iTest++;

		Ray.Dir.V3(0.0f,0.0f,1.0f);	
		_pa24fDists[iTest] = fGetRayTriListMinDist(Ray,_TriList,*Corner,_pa24iTris[iTest]);
		iTest++;

		Corner++;
	}

//## end CCOL_TriList_BVRayTest::TestBox%1008112118.body

//## begin CCOL_TriList_BVRayTest::fGetAxisCoord%1008534193.body preserve=no
//## end CCOL_TriList_BVRayTest::fGetSignedDist%1008550246.body

#endif
