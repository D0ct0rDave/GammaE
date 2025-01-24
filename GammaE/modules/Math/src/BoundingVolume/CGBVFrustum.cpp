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
#include <math.h>
#include "CGBVFrustum.h"
#include "Other/GMathUtils.h"
// ----------------------------------------------------------------------------
CGBVFrustum::CGBVFrustum()
{
    m_eType = BVT_FRUSTUM;
}
// ----------------------------------------------------------------------------
void CGBVFrustum::Init(const CGMatrix4x4& _oTransf,float _fVFov,float _fHFov,float _fNear,float _fFar)
{
    const float FOVM = 0.5f;
    CGVect3 Origin,Normal;

    float CosVFov = Math::fCos(_fVFov * FOVM * _PI_OVER_180_);
    float SinVFov = Math::fSin(_fVFov * FOVM * _PI_OVER_180_);

    // OpenGL blue book -> XFov is YFov * AspectRatio -> see gluPerspective
    float CosHFov = Math::fCos(_fHFov * FOVM * _PI_OVER_180_);
    float SinHFov = Math::fSin(_fHFov * FOVM * _PI_OVER_180_);

    /*
     +z
     |
     |
     |
     |
     +x  ---------+------------ x-
                /|\
             --/-+-\-- Near m_oPlane
              /  |  \
       Left m_oPlane  /   |   \  Right m_oPlane
            /    |    \
           /	 |     \
        --/------+------\-- Far m_oPlane
     |
     |
                -z
     */

    // Near plane
    Origin.Set(0,0,-_fNear);
    Normal.Set(0,0, 1);
    m_oPlane[0].GeneratePlaneFromFields(Origin,Normal);

    // Far plane
    Origin.Set(0,0,-_fFar);
    Normal.Set(0,0,-1);
    m_oPlane[1].GeneratePlaneFromFields(Origin,Normal);

    Origin.Set(0,0,0);

    // Right plane
    Normal.Set( CosHFov,0,SinHFov);
    m_oPlane[2].GeneratePlaneFromFields(Origin,Normal);

    // Left plane
    Normal.Set(-CosHFov,0,SinHFov);
    m_oPlane[3].GeneratePlaneFromFields(Origin,Normal);

    // Upper plane
    Normal.Set(0, CosVFov,SinVFov);
    m_oPlane[4].GeneratePlaneFromFields(Origin,Normal);

    // Lower plane
    Normal.Set(0, -CosVFov,SinVFov);
    m_oPlane[5].GeneratePlaneFromFields(Origin,Normal);

    // Transform the planes to the given reference system
    m_oPlane[0].Transform(_oTransf);
    // Far plane
    m_oPlane[1].Transform(_oTransf);
    // Right plane
    m_oPlane[2].Transform(_oTransf);
    // Left plane
    m_oPlane[3].Transform(_oTransf);
    // Top plane
    m_oPlane[4].Transform(_oTransf);
    // Bottom plane
    m_oPlane[5].Transform(_oTransf);
}
// ----------------------------------------------------------------------------
