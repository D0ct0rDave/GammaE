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
// -----------------------------------------------------------------------------
#include "CGSpiralPath.h"
// -----------------------------------------------------------------------------
const CVect3& CGSpiralPath::oPos(float _fFact)
{
    CVect3 oP;
    CVect3 oCenter,oRadius,oPhase;

    oCenter.LineEq(m_oPars.m_oInitialPos,m_oPars.m_oSpeed,_fFact);
    oRadius.LineEq(m_oPars.m_oInitialRadius,m_oPars.m_oRadiusSpeed,_fFact);
    oPhase.LineEq (m_oPars.m_oInitialPhase,m_oPars.m_oAngularSpeed,_fFact);

    oP.x = oCenter.x + oRadius.x* MATH_fSin(oPhase.x);
    oP.y = oCenter.y + oRadius.y* MATH_fCos(oPhase.y);
    oP.z = oCenter.z + oRadius.z* MATH_fCos(oPhase.z);

    return(oP);
}
// -----------------------------------------------------------------------------
