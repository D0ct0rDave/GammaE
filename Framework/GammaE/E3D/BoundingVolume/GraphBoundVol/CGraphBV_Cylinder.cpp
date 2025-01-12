//## begin module%3B70658502F8.cm preserve=no
//## end module%3B70658502F8.cm

//## begin module%3B70658502F8.cp preserve=no
//## end module%3B70658502F8.cp

//## Module: CGraphBV_Cylinder%3B70658502F8; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.cpp

//## begin module%3B70658502F8.additionalIncludes preserve=no
//## end module%3B70658502F8.additionalIncludes

//## begin module%3B70658502F8.includes preserve=yes
//## end module%3B70658502F8.includes

// CGraphBV_Cylinder
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Cylinder.h"
//## begin module%3B70658502F8.additionalDeclarations preserve=yes
//## end module%3B70658502F8.additionalDeclarations


// Class CGraphBV_Cylinder 


CGraphBV_Cylinder::CGraphBV_Cylinder()
  //## begin CGraphBV_Cylinder::CGraphBV_Cylinder%.hasinit preserve=no
  //## end CGraphBV_Cylinder::CGraphBV_Cylinder%.hasinit
  //## begin CGraphBV_Cylinder::CGraphBV_Cylinder%.initialization preserve=yes
  //## end CGraphBV_Cylinder::CGraphBV_Cylinder%.initialization
{
  //## begin CGraphBV_Cylinder::CGraphBV_Cylinder%.body preserve=yes
  //## end CGraphBV_Cylinder::CGraphBV_Cylinder%.body
}


CGraphBV_Cylinder::~CGraphBV_Cylinder()
{
  //## begin CGraphBV_Cylinder::~CGraphBV_Cylinder%.body preserve=yes
  //## end CGraphBV_Cylinder::~CGraphBV_Cylinder%.body
}



//## Other Operations (implementation)
void CGraphBV_Cylinder::Transform (CMatrix4x4& M)
{
  //## begin CGraphBV_Cylinder::Transform%997221297.body preserve=yes
  //## end CGraphBV_Cylinder::Transform%997221297.body
}

void CGraphBV_Cylinder::Compute (CVect3* VXs, int iNumVXs)
{
  //## begin CGraphBV_Cylinder::Compute%997221298.body preserve=yes
  //## end CGraphBV_Cylinder::Compute%997221298.body
}

float CGraphBV_Cylinder::GetRange (int iAxis)
{
  //## begin CGraphBV_Cylinder::GetRange%997221299.body preserve=yes
	switch (iAxis)
	{
		case 0:	return (Vol.Radius);
		case 1: return (Vol.Radius);
		case 2:	return (Vol.Height);
	}
	
	return(0);
  //## end CGraphBV_Cylinder::GetRange%997221299.body
}

CVect3 & CGraphBV_Cylinder::GetCenter ()
{
  //## begin CGraphBV_Cylinder::GetCenter%997221300.body preserve=yes
	return Vol.Center;
  //## end CGraphBV_Cylinder::GetCenter%997221300.body
}

int CGraphBV_Cylinder::TestFrustum (CE3D_Frustum& _Frustum)
{
  //## begin CGraphBV_Cylinder::TestFrustum%997221301.body preserve=yes
	return(1);
  //## end CGraphBV_Cylinder::TestFrustum%997221301.body
}

void CGraphBV_Cylinder::Init (CVect3 Max, CVect3 Min)
{
  //## begin CGraphBV_Cylinder::Init%997221307.body preserve=yes
	Vol.Init(Max,Min);
  //## end CGraphBV_Cylinder::Init%997221307.body
}

CBoundingCylinder * CGraphBV_Cylinder::pGetCylinder ()
{
  //## begin CGraphBV_Cylinder::pGetCylinder%1000933014.body preserve=yes
	return (&Vol);
  //## end CGraphBV_Cylinder::pGetCylinder%1000933014.body
}

int CGraphBV_Cylinder::TestInside (CVect3& _Pos)
{
  //## begin CGraphBV_Cylinder::TestInside%1006904824.body preserve=yes
	return(0);
  //## end CGraphBV_Cylinder::TestInside%1006904824.body
}

// Additional Declarations
  //## begin CGraphBV_Cylinder%3B70658502F8.declarations preserve=yes
  //## end CGraphBV_Cylinder%3B70658502F8.declarations

//## begin module%3B70658502F8.epilog preserve=yes
//## end module%3B70658502F8.epilog
