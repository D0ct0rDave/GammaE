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
#include "Segment\CGSegment.h"
// ----------------------------------------------------------------------------
CGVect3 CGSegment::ProjectPoint (CGVect3& _oPoint)
{
    float fLambda;
    CGVect3 c,qp,cp;

    cp.Assign(_oPoint);
    cp.Sub(oIni);

    qp.Assign(oEnd);
    qp.Sub(oIni);

    fLambda = cp.fDotProd(qp) / qp.fSqModule();

    if ( fLambda < 0.0f )
        fLambda = 0.0f;
    else
    {
        if ( fLambda > 1.0f )
            fLambda = 1.0f;
    }

    c.Interpolate(oIni,oEnd,fLambda);

    return(c);
}
// ----------------------------------------------------------------------------
