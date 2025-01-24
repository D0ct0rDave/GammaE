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

#ifndef CCOL_DT_Sphere_h
#define CCOL_DT_Sphere_h 1

// CCOL_ColState
#include "CollisionSystem\CCOL_ColState.h"
// CCOL_DT_Box
#include "COL_Testers\COL_DynamicTest\CCOL_DT_Box.h"

class CCOL_DT_Sphere
{
    public:
        CCOL_DT_Sphere();

        ~CCOL_DT_Sphere();

        static float fTestSphere(const CVect3& _oSCenter, float _fSRadius,const CVect3& _oDCenter, float _fDRadius);

        static float fTestBox(const CVect3& _oSCenter, float _fSRadius, const CVect3& _oDMaxs, const CVect3& _oDMins);

        static float fTestPoint(const CVect3& _oSCenter, float _fSRadius, const CVect3& _oDPoint);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CCOL_DT_Sphere

#endif
