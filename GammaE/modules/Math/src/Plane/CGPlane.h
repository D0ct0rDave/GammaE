// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (_oP3) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGPlaneH
#define CGPlaneH
// ----------------------------------------------------------------------------
#include "Vector\CGVect3.h"
#include "Matrix\CGMatrix4x4.h"
#include "GammaE_Misc.h"
// ----------------------------------------------------------------------------
class CGPlane
{
    public:

        void SetNormal(const CGVect3& _oNormal);

        void SetD(float _fD);

        void SetOrigin(const CGVect3& _oOrigin);

        void GenerateFromVectors(const CGVect3 _oVDir1, const CGVect3 _oVDir2, const CGVect3 _oVOrigin);

        void GenerateFromPoints(const CGVect3& _oP1, const CGVect3& _oP2, const CGVect3& _oP3);

        void GeneratePlaneFromFields(const CGVect3& _oVOrigin, const CGVect3& _oVNormal);

        float fGetDistanceToPoint(const CGVect3& _oPoint) const;

        bool bCoplanar(const CGPlane& _oPlane) const;

        const CGVect3 &oGetNormal() const;

        const CGVect3 &oGetOrigin() const;

        float fGetD() const;

        void Transform(const CGMatrix4x4& _oTransf);

        CGVect3 oProjectPoint(const CGVect3& _oPoint) const;

        uint uiPlaneType() const;

    private:

        float m_fPlaneD;

        CGVect3 m_oPlaneOrigin;

        CGVect3 m_oPlaneNormal;
};

// ----------------------------------------------------------------------------
inline void CGPlane::SetNormal (const CGVect3& _oNormal)
{
    m_oPlaneNormal.Assign(_oNormal);
}

inline void CGPlane::SetD (float _fD)
{
    m_fPlaneD = _fD;
}

inline void CGPlane::SetOrigin (const CGVect3& _oOrigin)
{
    m_oPlaneOrigin.Assign(_oOrigin);
}

inline const CGVect3 & CGPlane::oGetNormal () const
{
    return (m_oPlaneNormal);
}

inline const CGVect3 & CGPlane::oGetOrigin () const
{
    return (m_oPlaneOrigin);
}

inline float CGPlane::fGetD () const
{
    return (m_fPlaneD);
}
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
