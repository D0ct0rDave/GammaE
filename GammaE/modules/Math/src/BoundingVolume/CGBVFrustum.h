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
#ifndef CGBVFrustumH
#define CGBVFrustumH
// ----------------------------------------------------------------------------
#include "CGBoundingVolume.h"
#include "Plane/CGPlane.h"
#include "Vector/CGVect3.h"
// ----------------------------------------------------------------------------
class CGBVFrustum : public CGBoundingVolume
{
    public:
        // / Default contructor for the class
        CGBVFrustum();

        // / Initializes the frustum
        void Init(const CGMatrix4x4& _oTransf,float _fVFov,float _fHFov,float _fNear,float _fFar);

        // / Retrieves the given plane
        const CGPlane& oGetPlane(uint _uiPlane) const
        {
            return(m_oPlane[_uiPlane]);
        }

        // / Returns the volume occupied by the bounding volume
        virtual float fGetVolume()
        {
            // Too lazy, to be honest ...
            return(0.0f);
        }

        /*
           // DMC TO BE INVESTIGATED: Is this useful
           /// Copies the contents of a given frustum to this one
           void Copy(const CGBVFrustum& _oFrustum);

           /// Transform the frustum according to a given transformation matrix
           void Transform(const CGMatrix4x4& _oTransf);
         */

    protected:

        CGPlane m_oPlane[6];
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
