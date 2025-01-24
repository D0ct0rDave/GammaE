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
// -----------------------------------------------------------------------------
#ifndef SCNUt_SceneBuilder_h
#define SCNUt_SceneBuilder_h 1
// -----------------------------------------------------------------------------
// CGSceneNode
#include "GammaE_Scene.h"
// SCNUt_TriScene
#include "SCNUt_TriScene.h"
// SCNUt_MaterialTable
#include "SCNUt_MaterialTable.h"
// SCNUt_MeshCompacter
#include "ScnMeshGen\SCNUt_MeshCompacter.h"
// SCNUt_TriSceneSeparator
#include "SeparateTriScene\SCNUt_TriSceneSeparator.h"
// -----------------------------------------------------------------------------
class SCNUt_SceneBuilder
{
    public:

        SCNUt_SceneBuilder();
        ~SCNUt_SceneBuilder();

        CGSceneNode* poBuildScene(SCNUt_TriScene& _oScene, SCNUt_MaterialTable &_oMatTable);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
