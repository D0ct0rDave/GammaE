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

#ifndef CCOL_DT_Box_h
#define CCOL_DT_Box_h 1

// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_ST_Box
#include "COL_Testers\COL_StaticTest\CCOL_ST_Box.h"

class CCOL_DT_Box
{
    public:
        CCOL_DT_Box();

        ~CCOL_DT_Box();

        static float fTestSphere(const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDCenter, float _fDRadius);

        static float fTestBox(const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDMaxs, const CGVect3& _oDMins);

        static float fTestPoint(const CGVect3& _oSMaxs, const CGVect3& _oSMins, const CGVect3& _oDPoint);

        // Additional Public Declarations
        static int CCOL_DT_Box::iGetCollisionAxis();

    private:   // Additional Implementation Declarations
        static int iColAxis;
};

// Class CCOL_DT_Box

inline int CCOL_DT_Box::iGetCollisionAxis()
{
    return(iColAxis);
}

#endif
