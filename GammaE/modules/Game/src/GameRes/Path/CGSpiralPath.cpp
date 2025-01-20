// -----------------------------------------------------------------------------
#include "CGSpiralPath.h"
// -----------------------------------------------------------------------------
const CVect3& CGSpiralPath::oPos(float _fFact)
{
	CVect3 oP;
	CVect3 oCenter,oRadius,oPhase;

	oCenter.LineEq(m_oPars.m_oInitialPos   ,m_oPars.m_oSpeed       ,_fFact);
	oRadius.LineEq(m_oPars.m_oInitialRadius,m_oPars.m_oRadiusSpeed ,_fFact);
	oPhase.LineEq (m_oPars.m_oInitialPhase ,m_oPars.m_oAngularSpeed,_fFact);

	oP.x = oCenter.x + oRadius.x * MATH_Common::fSin(oPhase.x);
	oP.y = oCenter.y + oRadius.y * MATH_Common::fCos(oPhase.y);
	oP.z = oCenter.z + oRadius.z * MATH_Common::fCos(oPhase.z);

	return(oP);
}
// -----------------------------------------------------------------------------