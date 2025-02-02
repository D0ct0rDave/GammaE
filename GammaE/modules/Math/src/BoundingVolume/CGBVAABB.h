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
#ifndef CGBVAABBH
#define CGBVAABBH
// ----------------------------------------------------------------------------
#include "CGBoundingVolume.h"
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
//   e---f
// / |  /|
// a-g-b-h
// |/  |/
// c---d
// ----------------------------------------------------------------------------

class CGBVAABB : public CGBoundingVolume
{
    public:

        // / Default contructor for the class
        CGBVAABB();

        // / Copy contructor
        CGBVAABB(const CGBVAABB& _oVol);

        // / Initializes the AABB
        void Init(const CGVect3& _oMax, const CGVect3& _oMin);

        // / Retrieves the maximums of the AABB
        const CGVect3& oGetMax() const
        {
            return (m_oMax);
        }

        // / Retrieves the minimums of the AABB
        const CGVect3& oGetMin() const
        {
            return (m_oMin);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume() const
        {
            float fWidth = oGetMax().x - oGetMin().x;
            float fHeight = oGetMax().y - oGetMin().y;
            float fDepth = oGetMax().z - oGetMin().z;

            return(fWidth * fHeight * fDepth);
        }

    protected:

        CGVect3 m_oMax;
        CGVect3 m_oMin;
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
