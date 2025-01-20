//-----------------------------------------------------------------------------
#include "CSmoother.h"
#include "MATH_Common.h"
//-----------------------------------------------------------------------------
void CSmoother::Init(float _fSmoothFact)
{
	m_fAccum = 0.0f;
	m_fSmoothFact = MATH_Common::fClamp(0.0f,1.0f,_fSmoothFact);
}
//-----------------------------------------------------------------------------
float CSmoother::fValue(float _fInputVal)
{
	if (m_fSmoothFact > 100.0f)
	{	
		int A = 0;
	}

	if (m_fAccum > 100.0f)
	{	
		int A = 0;
	}
	// float fNewVal = MATH_Common::fClamp(0.0f,1.0f,_fInputVal);
	
	float fRet = MATH_Common::fLerp(m_fAccum,_fInputVal,m_fSmoothFact);
	m_fAccum = (m_fAccum + fRet) * 0.5f;

	return(fRet);
}
//-----------------------------------------------------------------------------