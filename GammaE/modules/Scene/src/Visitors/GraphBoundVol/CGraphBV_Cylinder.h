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

// CGraphBV
#include "BoundingVolume\GraphBoundVol\CGraphBV.h"
// CBoundingCylinder
#include "BoundingVolume\CBoundingCylinder.h"

class CGraphBV_Cylinder : public CGraphBV
{
    public:
        CGraphBV_Cylinder();

        ~CGraphBV_Cylinder();

        virtual void Transform(CMatrix4x4& M);

        virtual void Compute(CVect3* VXs, int iNumVXs);

        virtual float GetRange(int iAxis);

        virtual CVect3 & GetCenter();

        virtual int TestFrustum(CE3D_Frustum& _Frustum);

        virtual void Init(CVect3 Max, CVect3 Min);

        CBoundingCylinder* pGetCylinder();

        virtual int TestInside(CVect3& _Pos);

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
