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
#ifndef CGPathH
#define CGPathH
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGPath
{
    public:
        // / Retrieves the position of the path for a given factor between  (0..1)
        virtual const CGVect3& oPos(float _fFact) = 0;

        // / Time to traverse the full path
        virtual float fTime() = 0;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
