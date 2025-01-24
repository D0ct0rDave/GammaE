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

#ifndef SCNUt_PlanarMapper_h
#define SCNUt_PlanarMapper_h 1

// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_TransformTriScene
#include "TransfTriScn\SCNUt_TransformTriScene.h"
// SCNUt_ComputeBoundingBox
#include "ScnBBoxGen\SCNUt_ComputeBoundingBox.h"

class SCNUt_PlanarMapper
{
    public:
        SCNUt_PlanarMapper();

        ~SCNUt_PlanarMapper();

        void PlanarMap(SCNUt_TriScene& _oTriScn);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_PlanarMapper

#endif
