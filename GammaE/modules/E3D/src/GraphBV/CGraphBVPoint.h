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

#ifndef CGraphBV_Point_h
#define CGraphBV_Point_h 1

// CGBoundingVolume
#include "BoundingVolume\GraphBoundVol\CGBoundingVolume.h"

class CGraphBV_Point : public CGBoundingVolume
{
    public:
        CGraphBV_Point();

        ~CGraphBV_Point();

        virtual void Transform(CGMatrix4x4& M);

        virtual void Compute(CGVect3* VXs, int iNumVXs);

        virtual CGVect3 & GetCenter();

        virtual float GetRange(int iAxis);

        virtual int TestFrustum(CE3D_Frustum& _Frustum);

        virtual void Init(CGVect3 Max, CGVect3 Min);

        virtual int TestInside(CGVect3& _Pos);

        CGVect3* pGetPoint();

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Data Members for Class Attributes

        CGVect3 Point;

        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGraphBV_Point

#endif
