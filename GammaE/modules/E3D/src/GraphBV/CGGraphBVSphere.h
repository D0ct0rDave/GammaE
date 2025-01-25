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

        virtual void Transform(const CGMatrix4x4& _oM);

        virtual void Compute(CGVect3* _poVXs, uint _uiNumVXs);

        virtual float GetRange(char _cAxis) const;

        virtual const CGVect3 & GetCenter() const;

        virtual int TestFrustum(const CGBVFrustum& _oFrustum);

        virtual void Init(const CGVect3& _oMax, const CGVect3& _oMin);

        virtual int TestInside(const CGVect3& _oPos);

        virtual EGBoundingVolumeType eGetTypeID() const;

        virtual void Copy(const CGGraphBV& _oSrc);

        CGBVSphere* poGetSphere();

    private:
        // Data Members for Associations
        CGBVSphere m_oVol;

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        CGVect3 oExtents;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGBVSphere

#endif
