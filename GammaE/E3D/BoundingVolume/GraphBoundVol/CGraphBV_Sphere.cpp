//## begin module%3B7060AD0140.cm preserve=no
//## end module%3B7060AD0140.cm

//## begin module%3B7060AD0140.cp preserve=no
//## end module%3B7060AD0140.cp

//## Module: CGraphBV_Sphere%3B7060AD0140; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Sphere.cpp

//## begin module%3B7060AD0140.additionalIncludes preserve=no
//## end module%3B7060AD0140.additionalIncludes

//## begin module%3B7060AD0140.includes preserve=yes
//## end module%3B7060AD0140.includes

// CGraphBV_Sphere
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Sphere.h"
//## begin module%3B7060AD0140.additionalDeclarations preserve=yes
//## end module%3B7060AD0140.additionalDeclarations


// Class CGraphBV_Sphere 



CGraphBV_Sphere::CGraphBV_Sphere()
  //## begin CGraphBV_Sphere::CGraphBV_Sphere%.hasinit preserve=no
  //## end CGraphBV_Sphere::CGraphBV_Sphere%.hasinit
  //## begin CGraphBV_Sphere::CGraphBV_Sphere%.initialization preserve=yes
  //## end CGraphBV_Sphere::CGraphBV_Sphere%.initialization
{
  //## begin CGraphBV_Sphere::CGraphBV_Sphere%.body preserve=yes
	eTypeID = eGraphBV_Sphere;
  //## end CGraphBV_Sphere::CGraphBV_Sphere%.body
}


CGraphBV_Sphere::~CGraphBV_Sphere()
{
  //## begin CGraphBV_Sphere::~CGraphBV_Sphere%.body preserve=yes
  //## end CGraphBV_Sphere::~CGraphBV_Sphere%.body
}



//## Other Operations (implementation)
void CGraphBV_Sphere::Transform (CMatrix4x4& M)
{
  //## begin CGraphBV_Sphere::Transform%997221281.body preserve=yes
	M.TransformPoint(Vol.Center);
  //## end CGraphBV_Sphere::Transform%997221281.body
}

void CGraphBV_Sphere::Compute (CVect3* VXs, int iNumVXs)
{
  //## begin CGraphBV_Sphere::Compute%997221282.body preserve=yes
	if (! iNumVXs) return;

  	int		cV;
	float	fSqRad;
	CVect3	oCenter;
	float	fRadius;
	
	// Compute center as the average of the input points		
	oCenter.V3(0.0f,0.0f,0.0f);

	for (cV=0;cV<iNumVXs;cV++)
		oCenter.Add(VXs[cV]);

	oCenter.Scale(1.0f / (float)iNumVXs);

	// Compute sphere radius
	fRadius = 0.0f;
 	for (cV=0;cV<iNumVXs;cV++)
    {
		fSqRad = oCenter.SqDistance(VXs[cV]);
		if (fSqRad > fRadius)
			fRadius = fSqRad;
    }

	fRadius = MATH_Common::fSqrt(fRadius);
	
	// Initialize bounding volume
	Vol.Init(oCenter,fRadius);
  //## end CGraphBV_Sphere::Compute%997221282.body
}

float CGraphBV_Sphere::GetRange (int iAxis)
{
  //## begin CGraphBV_Sphere::GetRange%997221283.body preserve=yes
	return( Vol.Radius*2 );
  //## end CGraphBV_Sphere::GetRange%997221283.body
}

CVect3 & CGraphBV_Sphere::GetCenter ()
{
  //## begin CGraphBV_Sphere::GetCenter%997221284.body preserve=yes
	return (Vol.Center);
  //## end CGraphBV_Sphere::GetCenter%997221284.body
}

int CGraphBV_Sphere::TestFrustum (CE3D_Frustum& _Frustum)
{
  //## begin CGraphBV_Sphere::TestFrustum%997221285.body preserve=yes
	return (_Frustum.TestSphere(Vol.Radius,Vol.Center) );
  //## end CGraphBV_Sphere::TestFrustum%997221285.body
}

void CGraphBV_Sphere::Init (CVect3 Max, CVect3 Min)
{
  //## begin CGraphBV_Sphere::Init%997221306.body preserve=yes
	Vol.Init(Max,Min);
  //## end CGraphBV_Sphere::Init%997221306.body
}

CBoundingSphere * CGraphBV_Sphere::pGetSphere ()
{
  //## begin CGraphBV_Sphere::pGetSphere%1000933016.body preserve=yes
	return (&Vol);
  //## end CGraphBV_Sphere::pGetSphere%1000933016.body
}

int CGraphBV_Sphere::TestInside (CVect3& _Pos)
{
  //## begin CGraphBV_Sphere::TestInside%1006904826.body preserve=yes
	CVect3	RelSphPos;

	RelSphPos.Assign(_Pos);
	RelSphPos.Sub   (Vol.Center);

	return ( RelSphPos.SqDistance(Vol.Center) <= Vol.Radius*Vol.Radius );
  //## end CGraphBV_Sphere::TestInside%1006904826.body
}

void CGraphBV_Sphere::Copy (CGraphBV* Src)
{
  //## begin CGraphBV_Sphere::Copy%1020117913.body preserve=yes
	Vol.Init( Src->GetCenter(),Src->GetExtents().Module() );
  //## end CGraphBV_Sphere::Copy%1020117913.body
}

// Additional Declarations
  //## begin CGraphBV_Sphere%3B7060AD0140.declarations preserve=yes
  //## end CGraphBV_Sphere%3B7060AD0140.declarations

//## begin module%3B7060AD0140.epilog preserve=yes
//## end module%3B7060AD0140.epilog
