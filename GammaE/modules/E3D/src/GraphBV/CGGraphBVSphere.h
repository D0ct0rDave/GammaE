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

#ifndef CGGraphBVSphereh
#define CGGraphBVSphereh 1
// -----------------------------------------------------------------------------
#include "GraphBV\CGGraphBV.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------
class CGGraphBVSphere : public CGGraphBV
{
    public:

        void Init(const CGVect3& _oCenter, float _fRadius);
        
        virtual void Compute(CGVect3* _poVXs, uint _uiNumVXs);
                
        virtual void Transform(const CGMatrix4x4& _oM);

        virtual float GetRange(char _cAxis) const;

        virtual const CGVect3 & oGetCenter() const;

        virtual int TestFrustum(const CGBVFrustum& _oFrustum) const;

        virtual int TestInside(const CGVect3& _oPos) const;

        virtual EGBoundingVolumeType eGetTypeID() const;

        virtual const CGBoundingVolume& oGetBV() const;

        const CGBVSphere& oGetSphere() const;

    private:
        // Data Members for Associations
        CGBVSphere m_oVol;
};

// Class CGBVSphere

#endif
