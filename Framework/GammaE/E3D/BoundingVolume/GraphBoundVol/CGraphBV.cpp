//## begin module%3B706099014A.cm preserve=no
//## end module%3B706099014A.cm

//## begin module%3B706099014A.cp preserve=no
//## end module%3B706099014A.cp

//## Module: CGraphBV%3B706099014A; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV.cpp

//## begin module%3B706099014A.additionalIncludes preserve=no
//## end module%3B706099014A.additionalIncludes

//## begin module%3B706099014A.includes preserve=yes
//## end module%3B706099014A.includes

// CGraphBV
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV.h"
//## begin module%3B706099014A.additionalDeclarations preserve=yes
CVect3 oCenter,oExtents,oMax,oMin;
//## end module%3B706099014A.additionalDeclarations


// Class CGraphBV 


CGraphBV::CGraphBV()
  //## begin CGraphBV::CGraphBV%.hasinit preserve=no
  //## end CGraphBV::CGraphBV%.hasinit
  //## begin CGraphBV::CGraphBV%.initialization preserve=yes
  //## end CGraphBV::CGraphBV%.initialization
{
  //## begin CGraphBV::CGraphBV%.body preserve=yes
	eTypeID = eGraphBV;
  //## end CGraphBV::CGraphBV%.body
}


CGraphBV::~CGraphBV()
{
  //## begin CGraphBV::~CGraphBV%.body preserve=yes
  //## end CGraphBV::~CGraphBV%.body
}



//## Other Operations (implementation)
void CGraphBV::Transform (CMatrix4x4& M)
{
  //## begin CGraphBV::Transform%997221287.body preserve=yes
  //## end CGraphBV::Transform%997221287.body
}

void CGraphBV::Compute (CVect3* VXs, int iNumVXs)
{
  //## begin CGraphBV::Compute%997221288.body preserve=yes
  //## end CGraphBV::Compute%997221288.body
}

float CGraphBV::GetRange (int iAxis)
{
  //## begin CGraphBV::GetRange%997221289.body preserve=yes
  	return(0);
  //## end CGraphBV::GetRange%997221289.body
}

CVect3 & CGraphBV::GetCenter ()
{
  //## begin CGraphBV::GetCenter%997221290.body preserve=yes
	return(oMax);
  //## end CGraphBV::GetCenter%997221290.body
}

int CGraphBV::TestFrustum (CE3D_Frustum& _Frustum)
{
  //## begin CGraphBV::TestFrustum%997221291.body preserve=yes
	return(1);
  //## end CGraphBV::TestFrustum%997221291.body
}

void CGraphBV::Init (CVect3 Max, CVect3 Min)
{
  //## begin CGraphBV::Init%997221305.body preserve=yes
  //## end CGraphBV::Init%997221305.body
}

void CGraphBV::Copy (CGraphBV* Src)
{
  //## begin CGraphBV::Copy%997314338.body preserve=yes
	Init(Src->roGetMax(),Src->roGetMin());
  //## end CGraphBV::Copy%997314338.body
}

int CGraphBV::TestInside (CVect3& _Pos)
{
  //## begin CGraphBV::TestInside%1006904827.body preserve=yes
	return(0);
  //## end CGraphBV::TestInside%1006904827.body
}

CVect3 & CGraphBV::GetExtents ()
{
  //## begin CGraphBV::GetExtents%1008030327.body preserve=yes
	oExtents.V3(GetRange(0),GetRange(1),GetRange(2));
	oExtents.Scale(0.5f);

	return(oExtents);
  //## end CGraphBV::GetExtents%1008030327.body
}

CVect3 & CGraphBV::roGetMax ()
{
  //## begin CGraphBV::roGetMax%1021629966.body preserve=yes
	oMax.Assign(GetCenter());
	oMax.Add(GetExtents());
	return(oMax);
  //## end CGraphBV::roGetMax%1021629966.body
}

CVect3 & CGraphBV::roGetMin ()
{
  //## begin CGraphBV::roGetMin%1021629967.body preserve=yes
	oMin.Assign(GetCenter());
	oMin.Sub(GetExtents());
	return(oMin);
  //## end CGraphBV::roGetMin%1021629967.body
}

// Additional Declarations
  //## begin CGraphBV%3B706099014A.declarations preserve=yes
  //## end CGraphBV%3B706099014A.declarations

//## begin module%3B706099014A.epilog preserve=yes
//## end module%3B706099014A.epilog
