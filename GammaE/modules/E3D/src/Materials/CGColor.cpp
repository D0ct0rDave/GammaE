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
#include "CGColor.h"
#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
void CGColor::Lerp(const CGColor& _oIni,const CGColor& _oEnd,float _fFact)
{
    r = Math::fLerp(_oIni.r,_oEnd.r,_fFact);
    g = Math::fLerp(_oIni.g,_oEnd.g,_fFact);
    b = Math::fLerp(_oIni.b,_oEnd.b,_fFact);
    a = Math::fLerp(_oIni.a,_oEnd.a,_fFact);
}
// ----------------------------------------------------------------------------
