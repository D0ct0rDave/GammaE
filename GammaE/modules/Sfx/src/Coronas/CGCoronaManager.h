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
#ifndef CGCoronaManager_h
#define CGCoronaManager_h 1
// ----------------------------------------------------------------------------
#include "GammaE_Scene.h"
#include "CGCoronaInstance.h"
#include "CGCoronaGenerator.h"
#include "CGCoronaGenWH.h"
#include "SfxObject/CGSFXObjectManager.h"
// ----------------------------------------------------------------------------
DECLARE_SFXOBJECTMANAGER(CGCoronaManager,CGCoronaInstance,CGCoronaGenerator,CGCoronaGenWH){
};

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
