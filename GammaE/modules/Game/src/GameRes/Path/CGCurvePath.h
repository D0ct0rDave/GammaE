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
#ifndef CGCurvePathH
#define CGCurvePathH
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
#include "CGPath.h"
// -----------------------------------------------------------------------------
class CGCurvePath : public CGPath
{
    public:
        // / Retrieves the position of the path for a given factor between  (0..1)
        virtual const CGVect3& oPos(float _fFact);

        // / Initializes the path with the given curve
        void Init(CGCurve* _poCurve);

        // / Retrieves the time of the path
        float fTime()
        {
            return(m_fPathTime);
        }

    protected:
        CGCurve* m_poCurve;
        float m_fPathTime;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
