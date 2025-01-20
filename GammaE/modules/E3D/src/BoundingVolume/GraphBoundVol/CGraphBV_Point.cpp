//## begin module%3C4D994901BD.cm preserve=no
//## end module%3C4D994901BD.cm

//## begin module%3C4D994901BD.cp preserve=no
//## end module%3C4D994901BD.cp

//## Module: CGraphBV_Point%3C4D994901BD; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Point.cpp

//## begin module%3C4D994901BD.additionalIncludes preserve=no
//## end module%3C4D994901BD.additionalIncludes

//## begin module%3C4D994901BD.includes preserve=yes
//## end module%3C4D994901BD.includes

// CGraphBV_Point
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Point.h"
//## begin module%3C4D994901BD.additionalDeclarations preserve=yes
//## end module%3C4D994901BD.additionalDeclarations


// Class CGraphBV_Point 


CGraphBV_Point::CGraphBV_Point()
  //## begin CGraphBV_Point::CGraphBV_Point%.hasinit preserve=no
  //## end CGraphBV_Point::CGraphBV_Point%.hasinit
  //## begin CGraphBV_Point::CGraphBV_Point%.initialization preserve=yes
  //## end CGraphBV_Point::CGraphBV_Point%.initialization
{
  //## begin CGraphBV_Point::CGraphBV_Point%.body preserve=yes
  	eTypeID = eGraphBV_Point;
  //## end CGraphBV_Point::CGraphBV_Point%.body
}


CGraphBV_Point::~CGraphBV_Point()
{
  //## begin CGraphBV_Point::~CGraphBV_Point%.body preserve=yes
  //## end CGraphBV_Point::~CGraphBV_Point%.body
}



//## Other Operations (implementation)
void CGraphBV_Point::Transform (CMatrix4x4& M)
{
  //## begin CGraphBV_Point::Transform%1011722634.body preserve=yes
	M.TransformPoint(Point);
  //## end CGraphBV_Point::Transform%1011722634.body
}

void CGraphBV_Point::Compute (CVect3* VXs, int iNumVXs)
{
  //## begin CGraphBV_Point::Compute%1011722635.body preserve=yes
	if (iNumVXs<=0) return;

	Point.V3(0.0f,0.0f,0.0f);
	for (int iVX=0;iVX<iNumVXs;iVX++)
		Point.Add(VXs[iVX]);

	Point.Scale(1.0f / (float)iNumVXs);
  //## end CGraphBV_Point::Compute%1011722635.body
}

CVect3 & CGraphBV_Point::GetCenter ()
{
  //## begin CGraphBV_Point::GetCenter%1011722636.body preserve=yes
	return (Point);
  //## end CGraphBV_Point::GetCenter%1011722636.body
}

float CGraphBV_Point::GetRange (int iAxis)
{
  //## begin CGraphBV_Point::GetRange%1011722637.body preserve=yes
	return(0.0f);
  //## end CGraphBV_Point::GetRange%1011722637.body
}

int CGraphBV_Point::TestFrustum (CE3D_Frustum& _Frustum)
{
  //## begin CGraphBV_Point::TestFrustum%1011722638.body preserve=yes
	return (_Frustum.TestPoint(Point));
  //## end CGraphBV_Point::TestFrustum%1011722638.body
}

void CGraphBV_Point::Init (CVect3 Max, CVect3 Min)
{
  //## begin CGraphBV_Point::Init%1011722639.body preserve=yes
	Point.Assign(Max);
	Point.Add(Min);
	Point.Scale(0.5f);
  //## end CGraphBV_Point::Init%1011722639.body
}

int CGraphBV_Point::TestInside (CVect3& _Pos)
{
  //## begin CGraphBV_Point::TestInside%1011722640.body preserve=yes
	return (_Pos.Equal(Point));
  //## end CGraphBV_Point::TestInside%1011722640.body
}

CVect3 * CGraphBV_Point::pGetPoint ()
{
  //## begin CGraphBV_Point::pGetPoint%1011722641.body preserve=yes
	return(&Point);
  //## end CGraphBV_Point::pGetPoint%1011722641.body
}

// Additional Declarations
  //## begin CGraphBV_Point%3C4D994901BD.declarations preserve=yes
  //## end CGraphBV_Point%3C4D994901BD.declarations

//## begin module%3C4D994901BD.epilog preserve=yes
//## end module%3C4D994901BD.epilog
