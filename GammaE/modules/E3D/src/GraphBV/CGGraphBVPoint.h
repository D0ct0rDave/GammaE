// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// %X% %Q% %Z% %W%

#ifndef CGraphBV_PointH
#define CGraphBV_PointH 1
// -----------------------------------------------------------------------------
#include "GraphBV\CGGraphBV.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGGraphBVPoint : public CGGraphBV
{
    public:

        virtual void Transform(const CGMatrix4x4& M);

        virtual void Compute(CGVect3* VXs, uint _uiNumVXs);

        virtual const CGVect3 & GetCenter() const;

        virtual float GetRange(char _cAxis) const;

        virtual int TestFrustum(const CGBVFrustum & _Frustum);

        virtual EGBoundingVolumeType eGetTypeID() const;

        virtual void Init(const CGVect3& _oMax, const CGVect3& _oMin);

        virtual int TestInside(const CGVect3& _oPos);

        CGBVPoint* poGetPoint();
private:
        CGBVPoint m_oVol;
};
// -----------------------------------------------------------------------------
// Class CGraphBV_Point

#endif
