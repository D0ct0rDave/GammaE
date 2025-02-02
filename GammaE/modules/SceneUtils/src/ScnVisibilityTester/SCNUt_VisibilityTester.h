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

#ifndef SCNUt_VisibilityTester_h
#define SCNUt_VisibilityTester_h 1

// GammaE_Math
#include "GammaE_Math.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"

class SCNUt_VisibilityTester
{
    public:
        SCNUt_VisibilityTester();

        ~SCNUt_VisibilityTester();

        bool bIsVisible(SCNUt_TriScene* _poTScn, CGVect3& _oIni, CGVect3& _oEnd);

        // Additional Public Declarations

    protected:

        bool bRayToPos(CGRay& _oRay, CGVect3& _oPos, SCNUt_TriScene* _poTScn);

        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_VisibilityTester

#endif
