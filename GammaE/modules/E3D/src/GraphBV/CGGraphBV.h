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
#ifndef CGGraphBV_h
#define CGGraphBV_h 1
// -----------------------------------------------------------------------------
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGGraphBV
{
    public:
        virtual void Transform(const CGMatrix4x4& _oM) = 0;

        virtual void Compute(CGVect3* _poVXs, uint _uiNumVXs) = 0;

        virtual float GetRange(char _cAxis) const = 0;

        virtual const CGVect3 & oGetCenter() const = 0;

        virtual int TestFrustum(const CGBVFrustum& _oFrustum) const = 0;

        virtual EGBoundingVolumeType eGetTypeID() const = 0;

        virtual int TestInside(const CGVect3& _oPos) const = 0;

        virtual const CGBoundingVolume& oGetBV() const = 0;

        virtual const CGVect3& GetExtents() const;

        virtual const CGVect3& oGetMax() const;

        virtual const CGVect3& oGetMin() const;

};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
