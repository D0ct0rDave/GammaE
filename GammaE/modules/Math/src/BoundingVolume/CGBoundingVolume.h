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
#ifndef CBoundingVolumeH
#define CBoundingVolumeH
// ----------------------------------------------------------------------------
#include "GBoundingVolumeType.h"
// ----------------------------------------------------------------------------
class CGBoundingVolume
{
    public:
        // / Default contructor for the class
        CGBoundingVolume();

        // / Retrieves the type of this bounding volume object
        EGBoundingVolumeType eGetType() const
        {
            return(m_eType);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume() const = 0;

    protected:
        EGBoundingVolumeType m_eType;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
