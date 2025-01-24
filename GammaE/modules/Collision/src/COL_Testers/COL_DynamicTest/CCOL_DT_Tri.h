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

#ifndef CCOL_DT_Tri_h
#define CCOL_DT_Tri_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"

class CCOL_DT_Tri
{
    public:
        CCOL_DT_Tri();

        ~CCOL_DT_Tri();

        static float fTestSphere(CGraphBV_Sphere& _Sphere, CTriangle& _Tri);

        static float fTestBox(CGraphBV_Box& _Box, CTriangle& _Tri);

        static float fTestPoint(CVect3& _oPoint, CTriangle& _Tri);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_DT_Tri

#endif
