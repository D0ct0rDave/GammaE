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

#ifndef CCOL_DT_ColTester_h
#define CCOL_DT_ColTester_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Box
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"
// CCOL_DT_Point
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Point.h"
// CCOL_DT_Tri
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Tri.h"
// CCOL_DT_Sphere
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Sphere.h"

class CCOL_DT_ColTester
{
    public:
        CCOL_DT_ColTester();

        ~CCOL_DT_ColTester();

        static float fTestCollision(CGraphBV* SrcObj, CGraphBV* DstObj);

        static float fTestPlane(CGraphBV* _SrcObj, CPlane& Plane);

        static float fTestTriangle(CGraphBV* _SrcObj, CTriangle& _Tri);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_DT_ColTester

#endif
