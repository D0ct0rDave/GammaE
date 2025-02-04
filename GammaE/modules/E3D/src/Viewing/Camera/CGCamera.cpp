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
#include "Viewing\Camera\CGCamera.h"
// ----------------------------------------------------------------------------
void CGCamera::SetPos (float _fX, float _fY, float _fZ)
{
    m_oPos.Set(_fX,_fY,_fZ);
}
// ----------------------------------------------------------------------------
void CGCamera::SetPos(const CGVect3& _oPos)
{
    m_oPos = _oPos;
}
// ----------------------------------------------------------------------------
void CGCamera::SetDir (float _fPitch, float _fYaw, float _fRoll)
{
    float cosP,cosY,cosR;
    float sinP,sinY,sinR;

    cosP = Math::fCos(_fPitch);
    sinP = Math::fSin(_fPitch);
    cosY = Math::fCos(_fYaw);
    sinY = Math::fSin(_fYaw);
    cosR = Math::fCos(_fRoll);
    sinR = Math::fSin(_fRoll);

    // Forward vector
    m_oDir.x = sinY * cosP;
    m_oDir.y = sinP;
    m_oDir.z = cosP * (-cosY);

    // Up vector
    m_oUp.x = -cosY * sinR - sinY * sinP * cosR;
    m_oUp.y = cosP * cosR;
    m_oUp.z = -sinY * sinR - sinP * cosR * (-cosY);

    // Side vector
    m_oSide.CrossProd(m_oDir,m_oUp);
}
// ----------------------------------------------------------------------------
void CGCamera::SetVectors(const CGVect3& _oDir, const CGVect3& _oUp, const CGVect3& _oSide)
{
    m_oDir.Assign(_oDir);
    m_oUp.Assign(_oUp);
    m_oSide.Assign(_oSide);
}
// ----------------------------------------------------------------------------
void CGCamera::LookAt (const CGVect3& _oCenter)
{
    m_oDir.Assign(_oCenter);
    m_oDir.Sub(m_oPos);
    m_oDir.Normalize();

    m_oUp.Orthogonal(m_oDir);
    m_oSide.CrossProd(m_oDir, m_oUp);
    m_oUp.CrossProd(m_oSide, m_oDir);
}
// ----------------------------------------------------------------------------
