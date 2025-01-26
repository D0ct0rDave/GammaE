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
#ifndef CGBVPointH
#define CGBVPointH
// ----------------------------------------------------------------------------
#include "CGBoundingVolume.h"
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
// y
// |
// Center·- x
// /
// z
// ----------------------------------------------------------------------------
class CGBVPoint : public CGBoundingVolume
{
    public:

        // / Default contructor for the class
        CGBVPoint();

        // / Initialize the sphere
        void Init(const CGVect3& _oCenter)
        {
            m_oCenter = _oCenter;
        }

        // / Retrieve the center
        const CGVect3& oGetCenter() const
        {
            return(m_oCenter);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume() const
        {
            return(0.0f);
        }

    protected:

        CGVect3 m_oCenter;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
