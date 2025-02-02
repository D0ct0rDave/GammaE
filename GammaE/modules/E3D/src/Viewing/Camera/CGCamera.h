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
#ifndef CGCameraH
#define CGCameraH
// ----------------------------------------------------------------------------
#include "GammaE_Math.h"
// ----------------------------------------------------------------------------
class CGCamera
{
    public:

        // / Sets the position of the camera
        void SetPos(float _fX, float _fY, float _fZ);

        // / Sets the position of the camera
        void SetPos(const CGVect3& _oPos);

        // / Sets the orientation of the camera by its angles
        void SetDir(float _fPitch, float _fYaw, float _fRoll);

        // / Sets the orientation of the camera by its 3 vectors
        void SetVectors(const CGVect3& _oDir,const CGVect3& _oUp, const CGVect3& _oSide);

        // / Builds the direction vector using the current camera position and target
        void LookAt(const CGVect3& _oCenter);

        // / Retrieves the Position of the camera
        const CGVect3& oGetPos()
        {
            return(m_oPos);
        }

        // / Retrieves the "Dir" vector of the camera
        const CGVect3& oGetDir()
        {
            return(m_oDir);
        }

        // / Retrieves the "Side" vector of the camera
        const CGVect3& oGetSide()
        {
            return(m_oSide);
        }

        // / Retrieves the "Up" vector of the camera
        const CGVect3& oGetUp()
        {
            return(m_oUp);
        }

    protected:

        CGVect3 m_oPos;

        CGVect3 m_oDir;

        CGVect3 m_oSide;

        CGVect3 m_oUp;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
