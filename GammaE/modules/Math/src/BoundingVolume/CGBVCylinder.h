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
#ifndef CGBVCylinderH
#define CGBVCylinderH
// ----------------------------------------------------------------------------
#include "CGBoundingVolume.h"
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
class CGBVCylinder : public CGBoundingVolume
{
    public:

        // / Default contructor for the class
        CGBVCylinder();

        // / Initialize the cylinder
        void Init(const CGVect3& _oCenter, float _fRadius, float _fHeight);

        // / Retrieve the cylinder center
        const CGVect3& oGetCenter() const
        {
            return(m_oCenter);
        }

        // / Retrieve the cylinder radius
        float fGetRadius() const
        {
            return(m_fRadius);
        }

        // / Retrieve the cylinder height
        float fGetHeight() const
        {
            return(m_fHeight);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume() const
        {
            return(_2PI_ * m_fRadius * m_fRadius * m_fHeight);
        }

    protected:

        CGVect3 m_oCenter;
        float m_fRadius;
        float m_fHeight;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
