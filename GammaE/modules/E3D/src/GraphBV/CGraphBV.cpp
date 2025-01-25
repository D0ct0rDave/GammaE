// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// CGBoundingVolume
#include "BoundingVolume\GraphBoundVol\CGBoundingVolume.h"
CGVect3 oCenter,oExtents,oMax,oMin;

// Class CGBoundingVolume

CGBoundingVolume::CGBoundingVolume()
{
    eTypeID = eGraphBV;
}

CGBoundingVolume::~CGBoundingVolume()
{
}

void CGBoundingVolume::Transform (CGMatrix4x4& M)
{
}

void CGBoundingVolume::Compute (CGVect3* VXs, int iNumVXs)
{
}

float CGBoundingVolume::GetRange (int iAxis)
{
    return(0);
}

CGVect3 & CGBoundingVolume::GetCenter ()
{
    return(oMax);
}

int CGBoundingVolume::TestFrustum (CE3D_Frustum& _Frustum)
{
    return(1);
}

void CGBoundingVolume::Init (CGVect3 Max, CGVect3 Min)
{
}

void CGBoundingVolume::Copy (CGBoundingVolume* Src)
{
    Init( Src->oGetMax(),Src->oGetMin() );
}

int CGBoundingVolume::TestInside (CGVect3& _Pos)
{
    return(0);
}

CGVect3 & CGBoundingVolume::GetExtents ()
{
    oExtents.Set( GetRange(0),GetRange(1),GetRange(2) );
    oExtents.Scale(0.5f);

    return(oExtents);
}

CGVect3 & CGBoundingVolume::oGetMax ()
{
    oMax.Assign( GetCenter() );
    oMax.Add( GetExtents() );
    return(oMax);
}

CGVect3 & CGBoundingVolume::oGetMin ()
{
    oMin.Assign( GetCenter() );
    oMin.Sub( GetExtents() );
    return(oMin);
}

// Additional Declarations
