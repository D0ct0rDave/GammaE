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
// ----------------------------------------------------------------------------
#ifndef SCNUt_AnimSceneLoader_h
#define SCNUt_AnimSceneLoader_h 1
// ----------------------------------------------------------------------------

#include "GammaE_Scene.h"
#include "SCNUt_TriScene.h"

// ----------------------------------------------------------------------------
class SCNUt_AnimSceneLoader
{
    public:
        SCNUt_AnimSceneLoader();
        ~SCNUt_AnimSceneLoader();

        CGSceneNode* poLoad(char* _szFilename);
        CGDynArray <CGString> m_oMaterials;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
