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

#ifndef SCNUt_ComputeBoundingBox_h
#define SCNUt_ComputeBoundingBox_h 1

// CGBVAABB
#include "GammaE_E3D.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"

class SCNUt_ComputeBoundingBox
{
    public:
        SCNUt_ComputeBoundingBox();

        ~SCNUt_ComputeBoundingBox();

        CGBVAABB* poComputeBoundingBox(SCNUt_TriScene* _poScene);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_ComputeBoundingBox

#endif
