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

#ifndef CGGraphBVAABBH
#define CGGraphBVAABBH
// -----------------------------------------------------------------------------

#include "GraphBV\CGGraphBV.h"
#include "GammaE_Math.h"
// -----------------------------------------------------------------------------

class CGGraphBVAABB : public CGGraphBV
{
    public:

        void Init(const CGVect3& _oMax, const CGVect3&  _oMin);

        virtual void Copy(const CGGraphBV& _oSrc);

        virtual void Compute(CGVect3* _poVXs, uint _uiNumVXs);

        virtual void Transform(const CGMatrix4x4& _oM);

        virtual float GetRange(char _cAxis) const;

        virtual const CGVect3& oGetCenter() const;

        virtual int TestFrustum(const CGBVFrustum& _oFrustum) const;

        virtual EGBoundingVolumeType eGetTypeID() const;

        virtual int TestInside(const CGVect3& _Pos) const;

        virtual const CGBoundingVolume& oGetBV() const;

        virtual const CGVect3& GetExtents() const;

        virtual const CGVect3 & oGetMax() const;

        virtual const CGVect3 & oGetMin() const;

        const CGVect3& GetAxis(char _cAxis) const;

        const CGBVAABB& oGetBox() const;
        
        const CGVect3* poGetPoints() const;

protected:
        CGBVAABB m_oVol;

        void ComputeAll();

        CGVect3 m_oExtents;
        CGVect3 m_oCenter;
        CGVect3 m_oAxis[3];

        CGVect3 m_oPoints[8];
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
