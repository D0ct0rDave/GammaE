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
#ifndef GGameH
#define GGameH
// -----------------------------------------------------------------------------

#include "Entities/CGGameEntity.h"
#include "Entities/CGGameEntityMgr.h"
#include "Entities/CGLiveGameEntity.h"
#include "Entities/CGGEntityRenderMgr.h"

#include "Entities/CommandInterpreter/CGGameApplication.h"
#include "Entities/CommandInterpreter/CGGameConsoleApp.h"
#include "Entities/CommandInterpreter/CGGameCommandInterpreter.h"
#include "Entities/CommandInterpreter/CGGCICommand.h"
#include "Entities/CGGEntityStateRegistry.h"

#include "Entities/CommandInterpreter/ExtendedCI/CGGameExtendedCI.h"
#include "Entities/CommandInterpreter/ExtendedCI/CGGCIExtendedCommands.h"
#include "Entities/EntitySpawner/CGGameEntitySpawner.h"

#include "MessageMgr/CGGameMessageMgr.h"
#include "Game/CGGameBase.h"
#include "Game/CGGameMode.h"

#include "GameRes/Graphic/CGGraphicResource.h"
#include "GameRes/Graphic/CGGraphicInstance.h"
#include "GameRes/Graphic/CGGraphicResourceWH.h"

#include "GameRes/Script/CGScriptResource.h"
#include "GameRes/Script/CGScriptResourceWH.h"
#include "GameRes/Script/CGScriptingSystem.h"
#include "GameRes/Script/CGScriptInstance.h"

#include "GameRes/Input/CGInputHandler.h"
#include "GameRegistry/CGGameRegistry.h"

#include "GameRes/Path/CGPath.h"
#include "GameRes/Path/CGSpiralPath.h"
#include "GameRes/Path/CGCurvePath.h"
#include "GameRes/Path/CGPathResource.h"
#include "GameRes/Path/CGPathResourceWH.h"
#include "GameRes/Path/CGPathDefinitionFileWH.h"

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
