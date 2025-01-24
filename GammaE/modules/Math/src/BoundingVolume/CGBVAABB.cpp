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
#include "CGBVAABB.h"
// ----------------------------------------------------------------------------
CGBVAABB::CGBVAABB()
{
    m_eType = BVT_AABB;
}
// ----------------------------------------------------------------------------
void CGBVAABB::Init (const CGVect3& _oMax, const CGVect3& _oMin)
{
    m_oMins.Assign(_oMin);
    m_oMaxs.Assign(_oMax);

    // Look up table
    m_oPoints[0].Set( m_oMaxs.x,m_oMaxs.y,m_oMaxs.z );       // 000
    m_oPoints[1].Set( m_oMaxs.x,m_oMaxs.y,m_oMins.z );       // 001
    m_oPoints[2].Set( m_oMaxs.x,m_oMins.y,m_oMaxs.z );       // 010
    m_oPoints[3].Set( m_oMaxs.x,m_oMins.y,m_oMins.z );       // 011
    m_oPoints[4].Set( m_oMins.x,m_oMaxs.y,m_oMaxs.z );       // 100
    m_oPoints[5].Set( m_oMins.x,m_oMaxs.y,m_oMins.z );       // 101
    m_oPoints[6].Set( m_oMins.x,m_oMins.y,m_oMaxs.z );       // 110
    m_oPoints[7].Set( m_oMins.x,m_oMins.y,m_oMins.z );       // 111
}
// ----------------------------------------------------------------------------
