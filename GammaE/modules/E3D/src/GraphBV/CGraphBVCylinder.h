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

#ifndef CGraphBV_Cylinder_h
#define CGraphBV_Cylinder_h 1

// CGBoundingVolume
#include "BoundingVolume\GraphBoundVol\CGBoundingVolume.h"
// CBoundingCylinder
#include "BoundingVolume\CBoundingCylinder.h"

class CGraphBV_Cylinder : public CGBoundingVolume
{
    public:
        CGraphBV_Cylinder();

        ~CGraphBV_Cylinder();

        virtual void Transform(CGMatrix4x4& M);

        virtual void Compute(CGVect3* VXs, int iNumVXs);

        virtual float GetRange(int iAxis);

        virtual CGVect3 & GetCenter();

        virtual int TestFrustum(CE3D_Frustum& _Frustum);

        virtual void Init(CGVect3 Max, CGVect3 Min);

        CBoundingCylinder* pGetCylinder();

        virtual int TestInside(CGVect3& _Pos);

        // Data Members for Associations

        CBoundingCylinder Vol;

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CGraphBV_Cylinder

#endif
