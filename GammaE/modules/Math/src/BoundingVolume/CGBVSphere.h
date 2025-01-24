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
#ifndef CGBVSphereH
#define CGBVSphereH
// ----------------------------------------------------------------------------
#include "CGBoundingVolume.h"
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
// y
// |
// |
// |
// Center----- x
// /
// /
// z
// ----------------------------------------------------------------------------
class CGBVSphere : public CGBoundingVolume
{
    public:
        // / Default contructor for the class
        CGBVSphere();

        // / Initialize the sphere
        void Init(const CGVect3& _oCenter, float _fRadius);

        // / Retrieve the radius
        float fGetRadius() const
        {
            return(m_fRadius);
        }

        // / Retrieve the center
        const CGVect3& oGetCenter() const
        {
            return(m_oCenter);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume()
        {
            return( (4.0f / 3.0f) * _PI_ * _P3_(m_fRadius) );
        }

    protected:

        CGVect3 m_oCenter;
        float m_fRadius;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
