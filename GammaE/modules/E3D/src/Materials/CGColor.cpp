//-----------------------------------------------------------------------------
#include "CGColor.h"
#include "GammaE_Math.h"
//-----------------------------------------------------------------------------
void CGColor::Lerp(const CGColor& _oIni,const CGColor& _oEnd,float _fFact)
{
	r = MATH_Common::fLerp(_oIni.r,_oEnd.r,_fFact);
	g = MATH_Common::fLerp(_oIni.g,_oEnd.g,_fFact);
	b = MATH_Common::fLerp(_oIni.b,_oEnd.b,_fFact);
	a = MATH_Common::fLerp(_oIni.a,_oEnd.a,_fFact);
}
//-----------------------------------------------------------------------------

