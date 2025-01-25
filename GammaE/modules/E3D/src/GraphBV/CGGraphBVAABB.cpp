// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <assert.h>
#include "GraphBV\CGGraphBVAABB.h"
// ----------------------------------------------------------------------------
EGBoundingVolumeType CGGraphBVAABB::eGetTypeID() const
{
    return EGBoundingVolumeType::BVT_AABB;
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::Transform(const CGMatrix4x4& _roM)
{
    unsigned int cV;
    CGVect3 Mins,Maxs;

    Mins.Set( 1e10f, 1e10f, 1e10f);
    Maxs.Set(-1e10f,-1e10f,-1e10f);

    const CGVect3* poPoints = m_oVol.poGetPoints();

    for ( cV = 0; cV < 8; cV++ )
    {
        // Transform current Bounding box point
        CGVect3 vertex = poPoints[cV];
        _roM.TransformPoint(&vertex);

        if (vertex.x > Maxs.x ) Maxs.x = vertex.x;
        if (vertex.x < Mins.x ) Mins.x = vertex.x;
        if (vertex.y > Maxs.y ) Maxs.y = vertex.y;
        if (vertex.y < Mins.y ) Mins.y = vertex.y;
        if (vertex.z > Maxs.z ) Maxs.z = vertex.z;
        if (vertex.z < Mins.z ) Mins.z = vertex.z;
    }

    // Recompute bounding box
    m_oVol.Init(Maxs,Mins);
    ComputeAll();
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::Compute (CGVect3* _poVXs, uint _uiNumVXs)
{
    unsigned short cV;
    CGVect3 Mins,Maxs;

    Mins.Set( 1e10f, 1e10f, 1e10f);
    Maxs.Set(-1e10f,-1e10f,-1e10f);

    for ( cV = 0; cV < _uiNumVXs; cV++ )
    {
        if (_poVXs[cV].x > Maxs.x ) Maxs.x = _poVXs[cV].x;
        if (_poVXs[cV].x < Mins.x ) Mins.x = _poVXs[cV].x;
        if (_poVXs[cV].y > Maxs.y ) Maxs.y = _poVXs[cV].y;
        if (_poVXs[cV].y < Mins.y ) Mins.y = _poVXs[cV].y;
        if (_poVXs[cV].z > Maxs.z ) Maxs.z = _poVXs[cV].z;
        if (_poVXs[cV].z < Mins.z ) Mins.z = _poVXs[cV].z;
    }

    m_oVol.Init(Maxs,Mins);
    ComputeAll();
}
// ----------------------------------------------------------------------------
float CGGraphBVAABB::GetRange(char _cAxis) const 
{
    assert( ( (_cAxis >= 0) && (_cAxis <= 2) ) && "Incorrect axis" );
    return (m_oExtents.v(_cAxis) * 2);
}
// ----------------------------------------------------------------------------
const CGVect3 & CGGraphBVAABB::GetCenter() const
{
    return(m_oCenter);
}
// ----------------------------------------------------------------------------
int CGGraphBVAABB::TestFrustum(const CGBVFrustum& _oFrustum)
{
    // / Test the intersection of a given bounding volume against a given frustum
    bool bIntersect = Math::bBVIntersectFrustum(m_oVol, _oFrustum);

    return bIntersect?1:0;
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::Init (const CGVect3& _oMax, const CGVect3& _oMin)
{
    m_oVol.Init(_oMax, _oMin);
    ComputeAll();
}
// ----------------------------------------------------------------------------
CGBVAABB* CGGraphBVAABB::pGetBox ()
{
    return (&m_oVol);
}
// ----------------------------------------------------------------------------
int CGGraphBVAABB::TestInside (const CGVect3& _oPos)
{
    return (_oPos.bInside( m_oVol.oGetMax(), m_oVol.oGetMin()));
}
// ----------------------------------------------------------------------------
const CGVect3 & CGGraphBVAABB::GetExtents () const
{
    return(m_oExtents);
}
// ----------------------------------------------------------------------------
const CGVect3& CGGraphBVAABB::GetAxis(char _cAxis) const
{
    assert( ((_cAxis >= 0) && (_cAxis <= 2)) && "Incorrect axis" );

    static CGVect3 oXAxis(1.0f, 0.0f, 0.0f);
    static CGVect3 oYAxis(0.0f, 1.0f, 0.0f);
    static CGVect3 oZAxis(0.0f, 0.0f, 1.0f);

    switch (_cAxis)
    {
        case 0: 
        case 'x':return(oXAxis);

        case 1: 
        case 'y':return(oYAxis);

        case 2: 
        case 'z':return(oZAxis);
    }

    return(oXAxis);
}
// ----------------------------------------------------------------------------
const CGVect3& CGGraphBVAABB::oGetMax() const
{
    return(m_oVol.oGetMax());
}
// ----------------------------------------------------------------------------
const CGVect3 & CGGraphBVAABB::oGetMin() const
{
    return(m_oVol.oGetMin());
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::ComputeAll ()
{
    // Compute extents
    m_oExtents.Assign(m_oVol.oGetMax());
    m_oExtents.Sub   (m_oVol.oGetMin());
    m_oExtents.Scale (0.5f);

    // Compute Center
    m_oCenter.Assign(m_oVol.oGetMax());
    m_oCenter.Add   (m_oVol.oGetMin());
    m_oCenter.Scale (0.5f);
}
// ----------------------------------------------------------------------------
