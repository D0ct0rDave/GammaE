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
        virtual void Transform(const CGMatrix4x4& _oM);

        virtual void Compute(CGVect3* _poVXs, uint _uiNumVXs);

        virtual float GetRange(char _cAxis) const;

        virtual const CGVect3& GetCenter() const;

        virtual int TestFrustum(const CGBVFrustum& _oFrustum);

        virtual void Init(const CGVect3& _oMax, const CGVect3&  _oMin);
        
        virtual EGBoundingVolumeType eGetTypeID() const;

        virtual int TestInside(const CGVect3& _Pos);

        virtual const CGVect3& GetExtents() const;

        virtual const CGVect3 & oGetMax() const;

        virtual const CGVect3 & oGetMin() const;

        const CGVect3& GetAxis(char _cAxis) const;

        CGBVAABB* pGetBox();

protected:
        CGBVAABB m_oVol;

        void ComputeAll();

        CGVect3 m_oExtents;
        CGVect3 m_oCenter;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
