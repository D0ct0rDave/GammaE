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
void CGGraphBVAABB::Init(const CGVect3& _oMax, const CGVect3& _oMin)
{
    m_oVol.Init(_oMax, _oMin);
    ComputeAll();
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::Copy(const CGGraphBV& _oSrc)
{
    if (_oSrc.eGetTypeID() == eGetTypeID())
    {
        const CGGraphBVAABB& oSrc = (CGGraphBVAABB&)_oSrc;
        Init(oSrc.oGetMax(), oSrc.oGetMin());
    }
    else
    {
        Init(_oSrc.oGetMax(), _oSrc.oGetMin());
    }
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::Compute(CGVect3* _poVXs, uint _uiNumVXs)
{
    CGVect3 oMins, oMaxs;

    oMins.Set( 1e10f,  1e10f,  1e10f);
    oMaxs.Set(-1e10f, -1e10f, -1e10f);

    for (uint cV = 0; cV < _uiNumVXs; cV++)
    {
        if (_poVXs[cV].x > oMaxs.x) oMaxs.x = _poVXs[cV].x;
        if (_poVXs[cV].x < oMins.x) oMins.x = _poVXs[cV].x;
        if (_poVXs[cV].y > oMaxs.y) oMaxs.y = _poVXs[cV].y;
        if (_poVXs[cV].y < oMins.y) oMins.y = _poVXs[cV].y;
        if (_poVXs[cV].z > oMaxs.z) oMaxs.z = _poVXs[cV].z;
        if (_poVXs[cV].z < oMins.z) oMins.z = _poVXs[cV].z;
    }

    m_oVol.Init(oMaxs, oMins);
    ComputeAll();
}
// ----------------------------------------------------------------------------
void CGGraphBVAABB::Transform(const CGMatrix4x4& _roM)
{
    CGVect3 oMins, oMaxs;

    oMins.Set( 1e10f, 1e10f, 1e10f);
    oMaxs.Set(-1e10f,-1e10f,-1e10f);

    for (uint cV = 0; cV < 8; cV++ )
    {
        // Transform current Bounding box point
        CGVect3 vertex = m_oPoints[cV];
        _roM.TransformPoint(&vertex);

        if (vertex.x > oMaxs.x ) oMaxs.x = vertex.x;
        if (vertex.x < oMins.x ) oMins.x = vertex.x;
        if (vertex.y > oMaxs.y ) oMaxs.y = vertex.y;
        if (vertex.y < oMins.y ) oMins.y = vertex.y;
        if (vertex.z > oMaxs.z ) oMaxs.z = vertex.z;
        if (vertex.z < oMins.z ) oMins.z = vertex.z;
    }

    // Recompute bounding box
    m_oVol.Init(oMaxs, oMins);
    ComputeAll();
}

// ----------------------------------------------------------------------------
float CGGraphBVAABB::GetRange(char _cAxis) const 
{
    assert( ( (_cAxis >= 0) && (_cAxis <= 2) ) && "Incorrect axis" );
    return (m_oExtents.v(_cAxis) * 2);
}
// ----------------------------------------------------------------------------
const CGVect3 & CGGraphBVAABB::oGetCenter() const
{
    return(m_oCenter);
}
// ----------------------------------------------------------------------------
int CGGraphBVAABB::TestFrustum(const CGBVFrustum& _oFrustum) const
{
    // / Test the intersection of a given bounding volume against a given frustum
    bool bIntersect = Math::bBVIntersectFrustum(m_oVol, _oFrustum);

    return bIntersect?1:0;
}

// ----------------------------------------------------------------------------
int CGGraphBVAABB::TestInside (const CGVect3& _oPos) const
{
    return (_oPos.bInside( m_oVol.oGetMax(), m_oVol.oGetMin()));
}
// ----------------------------------------------------------------------------
const CGBVAABB& CGGraphBVAABB::oGetBox() const
{
    return m_oVol;
}
// ----------------------------------------------------------------------------
const CGBoundingVolume& CGGraphBVAABB::oGetBV() const
{
    return m_oVol;
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

    switch (_cAxis)
    {
        case 0: 
        case 'x':return(m_oAxis[0]);

        case 1: 
        case 'y':return(m_oAxis[1]);

        case 2: 
        case 'z':return(m_oAxis[2]);
    }

    return(m_oAxis[0]);
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
void CGGraphBVAABB::ComputeAll()
{
    // Compute extents
    m_oExtents.Assign(m_oVol.oGetMax());
    m_oExtents.Sub   (m_oVol.oGetMin());
    m_oExtents.Scale (0.5f);

    // Compute Center
    m_oCenter.Assign(m_oVol.oGetMax());
    m_oCenter.Add   (m_oVol.oGetMin());
    m_oCenter.Scale (0.5f);

    CGVect3 oMaxs = m_oVol.oGetMax();
    CGVect3 oMins = m_oVol.oGetMin();

    // Look up table
    m_oPoints[0].Set(oMaxs.x, oMaxs.y, oMaxs.z);       // 000
    m_oPoints[1].Set(oMaxs.x, oMaxs.y, oMins.z);       // 001
    m_oPoints[2].Set(oMaxs.x, oMins.y, oMaxs.z);       // 010
    m_oPoints[3].Set(oMaxs.x, oMins.y, oMins.z);       // 011
    m_oPoints[4].Set(oMins.x, oMaxs.y, oMaxs.z);       // 100
    m_oPoints[5].Set(oMins.x, oMaxs.y, oMins.z);       // 101
    m_oPoints[6].Set(oMins.x, oMins.y, oMaxs.z);       // 110
    m_oPoints[7].Set(oMins.x, oMins.y, oMins.z);       // 111

    m_oAxis[0].Assign(CGVect3::oX());
    m_oAxis[0].Scale(m_oExtents.x);

    m_oAxis[1].Assign(CGVect3::oY());
    m_oAxis[1].Scale(m_oExtents.y);

    m_oAxis[2].Assign(CGVect3::oZ());
    m_oAxis[2].Scale(m_oExtents.z);
}
// ----------------------------------------------------------------------------
const CGVect3* CGGraphBVAABB::poGetPoints() const
{
    return(m_oPoints);
}
// ----------------------------------------------------------------------------
