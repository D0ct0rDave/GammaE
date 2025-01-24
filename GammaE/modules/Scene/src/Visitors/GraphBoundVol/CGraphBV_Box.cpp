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
#include <assert.h>

// CGraphBV_Box
#include "BoundingVolume\GraphBoundVol\CGraphBV_Box.h"
static CVect3 oXAxis(1.0f,0.0f,0.0f);
static CVect3 oYAxis(0.0f,1.0f,0.0f);
static CVect3 oZAxis(0.0f,0.0f,1.0f);

// Class CGraphBV_Box

CGraphBV_Box::CGraphBV_Box()
{
    eTypeID = eGraphBV_Box;
}

CGraphBV_Box::~CGraphBV_Box()
{
}

void CGraphBV_Box::Transform (CMatrix4x4& M)
{
    unsigned int cV;
    CVect3 Mins,Maxs;

    Mins.V3( 1e10f, 1e10f, 1e10f);
    Maxs.V3(-1e10f,-1e10f,-1e10f);

    for ( cV = 0; cV < 8; cV++ )
    {
        // Transform current Bounding box point
        M.TransformPoint(Vol.m_oPoints[cV]);

        if ( Vol.m_oPoints[cV].x > Maxs.x ) Maxs.x = Vol.m_oPoints[cV].x;
        if ( Vol.m_oPoints[cV].x < Mins.x ) Mins.x = Vol.m_oPoints[cV].x;
        if ( Vol.m_oPoints[cV].y > Maxs.y ) Maxs.y = Vol.m_oPoints[cV].y;
        if ( Vol.m_oPoints[cV].y < Mins.y ) Mins.y = Vol.m_oPoints[cV].y;
        if ( Vol.m_oPoints[cV].z > Maxs.z ) Maxs.z = Vol.m_oPoints[cV].z;
        if ( Vol.m_oPoints[cV].z < Mins.z ) Mins.z = Vol.m_oPoints[cV].z;
    }

    // Recompute bounding box
    Vol.Init(Maxs,Mins);
    ComputeAll();
}

void CGraphBV_Box::Compute (CVect3* VXs, int iNumVXs)
{
    unsigned short cV;
    CVect3 Mins,Maxs;

    Mins.V3( 1e10f, 1e10f, 1e10f);
    Maxs.V3(-1e10f,-1e10f,-1e10f);

    for ( cV = 0; cV < iNumVXs; cV++ )
    {
        if ( VXs[cV].x > Maxs.x ) Maxs.x = VXs[cV].x;
        if ( VXs[cV].x < Mins.x ) Mins.x = VXs[cV].x;
        if ( VXs[cV].y > Maxs.y ) Maxs.y = VXs[cV].y;
        if ( VXs[cV].y < Mins.y ) Mins.y = VXs[cV].y;
        if ( VXs[cV].z > Maxs.z ) Maxs.z = VXs[cV].z;
        if ( VXs[cV].z < Mins.z ) Mins.z = VXs[cV].z;
    }

    Vol.Init(Maxs,Mins);
    ComputeAll();
}

float CGraphBV_Box::GetRange (int iAxis)
{
    assert( ( (iAxis >= 0) && (iAxis <= 2) ) && "Incorrect axis" );
    return (oExtents.v(iAxis) * 2);
}

CVect3 & CGraphBV_Box::GetCenter ()
{
    return(oCenter);
}

int CGraphBV_Box::TestFrustum (CE3D_Frustum& _Frustum)
{
    return ( _Frustum.TestBBox(Vol.m_oMaxs,Vol.m_oMins) );
}

void CGraphBV_Box::Init (CVect3 Max, CVect3 Min)
{
    Vol.Init(Max,Min);
    ComputeAll();
}

CBoundingBox* CGraphBV_Box::pGetBox ()
{
    return (&Vol);
}

int CGraphBV_Box::TestInside (CVect3& _Pos)
{
    return ( _Pos.bInside( Vol.m_oMaxs,Vol.m_oMins ) );
}

CVect3 & CGraphBV_Box::GetExtents ()
{
    return(oExtents);
}

CVect3 & CGraphBV_Box::GetAxis (int _iAxis)
{
    assert( ( (_iAxis >= 0) && (_iAxis <= 2) ) && "Incorrect axis" );

    switch ( _iAxis )
    {
        case 0: return(oXAxis);

        case 1: return(oYAxis);

        case 2: return(oZAxis);
    }
    return(oXAxis);
}

CVect3 & CGraphBV_Box::oGetMax ()
{
    return(Vol.m_oMaxs);
}

CVect3 & CGraphBV_Box::oGetMin ()
{
    return(Vol.m_oMins);
}

void CGraphBV_Box::ComputeAll ()
{
    // Compute extents
    oExtents.Assign(Vol.m_oMaxs);
    oExtents.Sub   (Vol.m_oMins);
    oExtents.Scale (0.5f);

    // Compute Center
    oCenter.Assign(Vol.m_oMaxs);
    oCenter.Add   (Vol.m_oMins);
    oCenter.Scale (0.5f);
}

// Additional Declarations
