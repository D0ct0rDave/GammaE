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

#ifndef CCOL_ST_Tris_h
#define CCOL_ST_Tris_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// GammaE_Math
#include "GammaE_Math.h"

class CCOL_ST_Tris
{
    public:
        CCOL_ST_Tris();

        ~CCOL_ST_Tris();

        static int iTestCollision(CVect3* _pVXs, CVect3* _pVNs, int _iNumTris, CGraphBV* _BV, CVect3& _Pos);

        static int iTestCollisionSphere(float _fRad, CVect3& _Center);

        static int iTestCollisionBox(CVect3& _Maxs, CVect3& _Mins);

        static int iTestCollisionRay(CRay& _ay);

        static int iTestTriangleSphere(CVect3* _pVXs, float _fRad, CVect3& _Center);

        static int iTestTriangleBox(CVect3* _pVXs, CVect3& _Maxs, CVect3& _Mins);

        static int iTestTriangleRay(CVect3* _pVXs, CRay& _ay);

        // Data Members for Class Attributes

        static int Tri;

        // Additional Public Declarations

    protected:
        // Data Members for Class Attributes

        static CVect3* pVX;

        static CVect3* pVN;

        static int iNumTris;

        static CVect3 Pos;

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_ST_Tris

#endif
