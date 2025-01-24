




// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
CVect3 oCenter,oExtents,oMax,oMin;


// Class CGraphBV 


CGraphBV::CGraphBV()
        {
  	eTypeID = eGraphBV;
}


CGraphBV::~CGraphBV()
{
}



void CGraphBV::Transform (CMatrix4x4& M)
{
}

void CGraphBV::Compute (CVect3* VXs, int iNumVXs)
{
}

float CGraphBV::GetRange (int iAxis)
{
    	return(0);
}

CVect3 & CGraphBV::GetCenter ()
{
  	return(oMax);
}

int CGraphBV::TestFrustum (CE3D_Frustum& _Frustum)
{
  	return(1);
}

void CGraphBV::Init (CVect3 Max, CVect3 Min)
{
}

void CGraphBV::Copy (CGraphBV* Src)
{
  	Init(Src->oGetMax(),Src->oGetMin());
}

int CGraphBV::TestInside (CVect3& _Pos)
{
  	return(0);
}

CVect3 & CGraphBV::GetExtents ()
{
  	oExtents.V3(GetRange(0),GetRange(1),GetRange(2));
	oExtents.Scale(0.5f);

	return(oExtents);
}

CVect3 & CGraphBV::oGetMax ()
{
  	oMax.Assign(GetCenter());
	oMax.Add(GetExtents());
	return(oMax);
}

CVect3 & CGraphBV::oGetMin ()
{
  	oMin.Assign(GetCenter());
	oMin.Sub(GetExtents());
	return(oMin);
}

// Additional Declarations
    
