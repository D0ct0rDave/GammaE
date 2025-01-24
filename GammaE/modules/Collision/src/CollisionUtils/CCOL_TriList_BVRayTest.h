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
#ifndef CCOL_TriList_BVRayTest_h
#define CCOL_TriList_BVRayTest_h 1

// GammaE_E3D
#include "GammaE_E3D.h"
// GammaE_Math
#include "GammaE_Math.h"
// CCOL_TriList
#include "COL_TriList\CCOL_TriList.h"

class CCOL_TriList_BVRayTest
{
    public:
        CCOL_TriList_BVRayTest();

        ~CCOL_TriList_BVRayTest();

        static void Test(CVect3& _Center, CCOL_TriList& _TriList, int _iRayMask, float* _pa6fDists, int* _pa6iTris);

        // Additional Public Declarations

    protected:

        static float fGetRayTriListMinDist(CRay& _ay, CCOL_TriList& _TriList, CVect3& _Point, int& _iIdx);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_TriList_BVRayTest
#endif
