// ----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef CGRendererH
#define CGRendererH
// ----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGE3DRenderer.h"
// ----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CGRenderer,public,CGE3DRenderer)
{
    public:
        static CGRenderer* I()
        {
            static CGRenderer* soInstance = (CGRenderer*)poCreateRenderer();
            return(soInstance);
        }

    private:
        static CGRenderer* poCreateRenderer();
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
