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

#ifndef CGraphBVCylinderH
#define CGraphBVCylinderH 1
// -----------------------------------------------------------------------------
#include "GraphBV\CGGraphBV.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGGraphBVCylinder : public CGGraphBV
{
    public:

        void Init(const CGVect3& _oCenter, float _fRadius, float _fHeight);
        
        virtual void Copy(const CGGraphBV& _oSrc);

        virtual void Transform(const CGMatrix4x4& _oM);

        virtual void Compute(CGVect3* _poVXs, uint _uiNumVXs);

        virtual float GetRange(char _cAxis) const;

        virtual const CGVect3 & oGetCenter() const;

        virtual int TestFrustum(const CGBVFrustum& _Frustum) const;

        virtual int TestInside(const CGVect3& _oPos) const;
        
        virtual EGBoundingVolumeType eGetTypeID() const;

        const CGBVCylinder& GetCylinder() const;

        virtual const CGBoundingVolume& oGetBV() const;
private:
        CGBVCylinder m_oVol;
};
// -----------------------------------------------------------------------------
// Class CGraphBV_Cylinder
// -----------------------------------------------------------------------------
#endif
