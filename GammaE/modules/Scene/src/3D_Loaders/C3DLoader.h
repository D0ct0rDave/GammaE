// ----------------------------------------------------------------------------
/*! \class C3DLoader
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef C3DLoaderH
#define C3DLoaderH
// ----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class C3DLoader
{
    public:
        C3DLoader();
        ~C3DLoader();

        virtual CGSceneNode* poLoad(const CGString& _sFilename) = 0;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
