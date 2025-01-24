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
// e---f
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

        // / Initializes the AABB
        void Init(const CGVect3& _oMax, const CGVect3& _oMin);

        // / Retrieves the maximums of the AABB
        const CGVect3& oGetMax() const
        {
            return (m_oMaxs);
        }

        // / Retrieves the minimums of the AABB
        const CGVect3& oGetMin() const
        {
            return (m_oMins);
        }

        // / Retrieve the array of points belonging to the AABB
        const CGVect3* poGetPoints()
        {
            return (m_oPoints);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume()
        {
            float fWidth = m_oMaxs.x - m_oMins.x;
            float fHeight = m_oMaxs.y - m_oMins.y;
            float fDepth = m_oMaxs.z - m_oMins.z;

            return(fWidth * fHeight * fDepth);
        }

    protected:

        CGVect3 m_oMaxs;
        CGVect3 m_oMins;
        CGVect3 m_oPoints[8];
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
