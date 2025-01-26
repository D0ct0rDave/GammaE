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
CGBVAABB::CGBVAABB(const CGBVAABB& _oVol)
{
    CGBVAABB();
    Init(_oVol.oGetMax(), _oVol.oGetMin());
}
// ----------------------------------------------------------------------------
void CGBVAABB::Init (const CGVect3& _oMax, const CGVect3& _oMin)
{
    m_oMins.Assign(_oMin);
    m_oMaxs.Assign(_oMax);
}
// ----------------------------------------------------------------------------
