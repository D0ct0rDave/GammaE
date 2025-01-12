//## begin module%3B7061E0019A.cm preserve=no
//## end module%3B7061E0019A.cm

//## begin module%3B7061E0019A.cp preserve=no
//## end module%3B7061E0019A.cp

//## Module: CGraphBV_Box%3B7061E0019A; Pseudo Package body
//## Source file: i:\Projects\GammaE\E3D\BoundingVolume\GraphBoundVol\CGraphBV_Box.cpp

//## begin module%3B7061E0019A.additionalIncludes preserve=no
//## end module%3B7061E0019A.additionalIncludes

//## begin module%3B7061E0019A.includes preserve=yes
#include <assert.h>
//## end module%3B7061E0019A.includes

// CGraphBV_Box
#include "E3D\BoundingVolume\GraphBoundVol\CGraphBV_Box.h"
//## begin module%3B7061E0019A.additionalDeclarations preserve=yes
static CVect3 oXAxis(1.0f,0.0f,0.0f);
static CVect3 oYAxis(0.0f,1.0f,0.0f);
static CVect3 oZAxis(0.0f,0.0f,1.0f);
//## end module%3B7061E0019A.additionalDeclarations


// Class CGraphBV_Box 




CGraphBV_Box::CGraphBV_Box()
  //## begin CGraphBV_Box::CGraphBV_Box%.hasinit preserve=no
  //## end CGraphBV_Box::CGraphBV_Box%.hasinit
  //## begin CGraphBV_Box::CGraphBV_Box%.initialization preserve=yes
  //## end CGraphBV_Box::CGraphBV_Box%.initialization
{
  //## begin CGraphBV_Box::CGraphBV_Box%.body preserve=yes
	eTypeID = eGraphBV_Box;
  //## end CGraphBV_Box::CGraphBV_Box%.body
}


CGraphBV_Box::~CGraphBV_Box()
{
  //## begin CGraphBV_Box::~CGraphBV_Box%.body preserve=yes
  //## end CGraphBV_Box::~CGraphBV_Box%.body
}



//## Other Operations (implementation)
void CGraphBV_Box::Transform (CMatrix4x4& M)
{
  //## begin CGraphBV_Box::Transform%997221292.body preserve=yes
	unsigned int cV;
	CVect3 Mins,Maxs;

    Mins.V3( 1000000000, 1000000000, 1000000000);
    Maxs.V3(-1000000000,-1000000000,-1000000000);

 	for (cV=0;cV<8;cV++)
    {
		// Transform current Bounding box point
		M.TransformPoint(Vol.Points[cV]);

    	if ( Vol.Points[cV].X() > Maxs.X() ) Maxs.SetX( Vol.Points[cV].X() );
        if ( Vol.Points[cV].X() < Mins.X() ) Mins.SetX( Vol.Points[cV].X() );
    	if ( Vol.Points[cV].Y() > Maxs.Y() ) Maxs.SetY( Vol.Points[cV].Y() );
        if ( Vol.Points[cV].Y() < Mins.Y() ) Mins.SetY( Vol.Points[cV].Y() );
    	if ( Vol.Points[cV].Z() > Maxs.Z() ) Maxs.SetZ( Vol.Points[cV].Z() );
        if ( Vol.Points[cV].Z() < Mins.Z() ) Mins.SetZ( Vol.Points[cV].Z() );
    }
    	
	// Recompute bounding box
    Vol.Init(Maxs,Mins);	
	ComputeAll();
  //## end CGraphBV_Box::Transform%997221292.body
}

void CGraphBV_Box::Compute (CVect3* VXs, int iNumVXs)
{
  //## begin CGraphBV_Box::Compute%997221293.body preserve=yes
  	unsigned short cV;	
	CVect3 Mins,Maxs;

    Mins.V3( 1000000000, 1000000000, 1000000000);
    Maxs.V3(-1000000000,-1000000000,-1000000000);

 	for (cV=0;cV<iNumVXs;cV++)
    {
    	if ( VXs[cV].X() > Maxs.X() ) Maxs.SetX( VXs[cV].X() );
        if ( VXs[cV].X() < Mins.X() ) Mins.SetX( VXs[cV].X() );
    	if ( VXs[cV].Y() > Maxs.Y() ) Maxs.SetY( VXs[cV].Y() );
        if ( VXs[cV].Y() < Mins.Y() ) Mins.SetY( VXs[cV].Y() );
    	if ( VXs[cV].Z() > Maxs.Z() ) Maxs.SetZ( VXs[cV].Z() );
        if ( VXs[cV].Z() < Mins.Z() ) Mins.SetZ( VXs[cV].Z() );
    }

	Vol.Init(Maxs,Mins);   
	ComputeAll();
  //## end CGraphBV_Box::Compute%997221293.body
}

float CGraphBV_Box::GetRange (int iAxis)
{
  //## begin CGraphBV_Box::GetRange%997221294.body preserve=yes
	assert( ((iAxis>=0) && (iAxis<=2)) && "Incorrect axis");
	return (oExtents.v[iAxis]*2);
  //## end CGraphBV_Box::GetRange%997221294.body
}

CVect3 & CGraphBV_Box::GetCenter ()
{
  //## begin CGraphBV_Box::GetCenter%997221295.body preserve=yes
	return(oCenter);
  //## end CGraphBV_Box::GetCenter%997221295.body
}

int CGraphBV_Box::TestFrustum (CE3D_Frustum& _Frustum)
{
  //## begin CGraphBV_Box::TestFrustum%997221296.body preserve=yes
	return (_Frustum.TestBBox(Vol.Maxs,Vol.Mins) );
  //## end CGraphBV_Box::TestFrustum%997221296.body
}

void CGraphBV_Box::Init (CVect3 Max, CVect3 Min)
{
  //## begin CGraphBV_Box::Init%997221308.body preserve=yes
	Vol.Init(Max,Min);
	ComputeAll();
  //## end CGraphBV_Box::Init%997221308.body
}

CBoundingBox * CGraphBV_Box::pGetBox ()
{
  //## begin CGraphBV_Box::pGetBox%1000933015.body preserve=yes
	return (&Vol);
  //## end CGraphBV_Box::pGetBox%1000933015.body
}

int CGraphBV_Box::TestInside (CVect3& _Pos)
{
  //## begin CGraphBV_Box::TestInside%1006904825.body preserve=yes
	return ( _Pos.Inside( Vol.Maxs,Vol.Mins ));
  //## end CGraphBV_Box::TestInside%1006904825.body
}

CVect3 & CGraphBV_Box::GetExtents ()
{
  //## begin CGraphBV_Box::GetExtents%1008030326.body preserve=yes
	return(oExtents);
  //## end CGraphBV_Box::GetExtents%1008030326.body
}

CVect3 & CGraphBV_Box::GetAxis (int _iAxis)
{
  //## begin CGraphBV_Box::GetAxis%1009321160.body preserve=yes
	assert( ((_iAxis>=0) && (_iAxis<=2)) && "Incorrect axis");

	switch (_iAxis)
	{
		case 0:	return(oXAxis);
		case 1:	return(oYAxis);
		case 2:	return(oZAxis);
	}
	return(oXAxis);
  //## end CGraphBV_Box::GetAxis%1009321160.body
}

CVect3 & CGraphBV_Box::roGetMax ()
{
  //## begin CGraphBV_Box::roGetMax%1021629968.body preserve=yes
	return( Vol.Maxs );
  //## end CGraphBV_Box::roGetMax%1021629968.body
}

CVect3 & CGraphBV_Box::roGetMin ()
{
  //## begin CGraphBV_Box::roGetMin%1021629969.body preserve=yes
	return( Vol.Mins );
  //## end CGraphBV_Box::roGetMin%1021629969.body
}

void CGraphBV_Box::ComputeAll ()
{
  //## begin CGraphBV_Box::ComputeAll%1021629970.body preserve=yes
  	
	// Compute extents
	oExtents.Assign(Vol.Maxs);
	oExtents.Sub   (Vol.Mins);
	oExtents.Scale (0.5f);

	// Compute Center
	oCenter.Assign(Vol.Maxs);
	oCenter.Add   (Vol.Mins);
	oCenter.Scale (0.5f);
  //## end CGraphBV_Box::ComputeAll%1021629970.body
}

// Additional Declarations
  //## begin CGraphBV_Box%3B7061E0019A.declarations preserve=yes
  //## end CGraphBV_Box%3B7061E0019A.declarations

//## begin module%3B7061E0019A.epilog preserve=yes
//## end module%3B7061E0019A.epilog
