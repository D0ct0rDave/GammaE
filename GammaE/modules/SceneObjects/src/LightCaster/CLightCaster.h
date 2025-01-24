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

#ifndef CLightCaster_h
#define CLightCaster_h 1

// CGSceneLeaf
#include "Scene\CGSceneLeaf.h"

class CLightCaster : public CGSceneLeaf
{
    public:
        CLightCaster();

        ~CLightCaster();

        void SetupLight(CVect3& _oLightPos, CVect3 _oLightDir);

        // Additional Public Declarations

    protected:
        // Additional Protected Declarations

    private:
        // Additional Private Declarations

    private:   // Additional Implementation Declarations
};

// Class CLightCaster

#endif
