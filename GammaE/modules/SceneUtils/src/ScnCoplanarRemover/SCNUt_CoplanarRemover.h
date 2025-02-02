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

#ifndef SCNUt_CoplanarRemover_h
#define SCNUt_CoplanarRemover_h 1

// SCNUt_TriScene
#include "SCNUt_TriScene.h"

class SCNUt_CoplanarRemover
{
    public:
        SCNUt_CoplanarRemover();

        ~SCNUt_CoplanarRemover();

        SCNUt_TriScene* RemoveCoplanars(SCNUt_TriScene* _poScn);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:                    // Additional Implementation Declarations
};

// Class SCNUt_CoplanarRemover

#endif
