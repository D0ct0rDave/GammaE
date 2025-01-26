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

        static float fTestSphere(const CGGraphBVSphere& _oSphere, const CGTriangle& _oTri);

        static float fTestBox(const CGGraphBVAABB& _oBox, const CGTriangle& _oTri);

        static float fTestPoint(const CGVect3& _oPoint, const CGTriangle& _oTri);
};

// Class CCOL_DT_Tri

#endif
