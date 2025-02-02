// ----------------------------------------------------------------------------
/*! \class C3DSaver
 *  \brief Base class to save a scene graph hierarchy in a given format.
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#ifndef C3DSaverH
#define C3DSaverH
// ----------------------------------------------------------------------------
#include "GammaE_E3D.h"
#include "CGSceneNode.h"
// ----------------------------------------------------------------------------
class C3DSaver : public CGSceneVisitor
{
    public:
        virtual bool bSave(const CGString& _sFilename, CGSceneNode* _poObj) = 0;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
