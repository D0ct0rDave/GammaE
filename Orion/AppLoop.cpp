// ----------------------------------------------------------------------------
#include "AppLoop.h"
#include "AppGlobals.h"
#include "Game/GameLoop.h"
#include "Menu/MenuLoop.h"
#include "Tex.h"

#ifdef _BORLANDC_
	#include <dir.h>
#else
	#ifdef _MBCS
	#include <direct.h>
	#endif
#endif

// ----------------------------------------------------------------------------
typedef enum eAppState {APPSTATE_NONE, APPSTATE_STARTMENU, APPSTATE_MENU, APPSTATE_ENDMENU, APPSTATE_STARTGAME,APPSTATE_GAME,APPSTATE_ENDGAME};

// ----------------------------------------------------------------------------
bool		bFinishApplication = false;
eAppState	AppState = APPSTATE_NONE;

// ----------------------------------------------------------------------------
bool AppLoop_bFinishApp()
{
	return(bFinishApplication);
}
// ----------------------------------------------------------------------------
void AppLoop_OnCreate (void *uiWinHandler,unsigned int uiWndWidth,unsigned int uiWndHeight,char *pszCmdLine)
{
	// Create app main objects, and initial menu objects
	// Set current working directory

	// Init 3D Rendeing system
	CE3D_ShaderWH::Init(1024);
	CE3D_ShaderDefWH::Init(1024);

	guiScrWidth  = uiWndWidth;
	guiScrHeight = uiWndHeight;

	gpoE3DRenderer = &goRenderer;
    gpoE3DRenderer->Init(uiWinHandler,E3D_RENDERER_OP_DBUFFER,guiScrWidth,guiScrHeight,32);

	// Init Sound System
	if (! goSndRenderer.Init(uiWinHandler,16,44100,1024))
		CONPrintf("Error intializing sound renderer. Start using no sound\n");

	CSampleWH::SetForcedParams(44100,16);
	CSampleWH::Init(256);
	CSoundWH::Init (256);

	strcpy(gszMapFileName,"base/gamemodes/arcade/missions/warehouse.cfg");
	// strcpy(gszMapFileName,"base/gamemodes/arcade/missions/vhunt.cfg");
	AppState = APPSTATE_STARTMENU;
	// AppState = APPSTATE_STARTGAME;
}

// ----------------------------------------------------------------------------
void AppLoop_OnResize (unsigned int uiWndWidth,unsigned int uiWndHeight)
{
	guiScrWidth  = uiWndWidth;
	guiScrHeight = uiWndHeight;	
	
	gpoE3DRenderer->SetScreenSize(guiScrWidth,guiScrHeight);	
}
// ----------------------------------------------------------------------------
void AppLoop_OnDestroy(void *uiWinHandler)
{	
	gpoE3DRenderer->Finish();
}
// ----------------------------------------------------------------------------
void AppLoop_OnIdle()
{
	switch (AppState)
	{
		case APPSTATE_STARTMENU:
		{
			// Init menu
			MenuLoop_Init();
			AppState = APPSTATE_MENU;
		}
		break;

		case APPSTATE_MENU:
		{
			if (MenuLoop_OnIdle())
			{
				if (eMenuState == MENUST_QUIT)
				{
					bFinishApplication = true;
					AppState = APPSTATE_NONE;
				}
				else {
					AppState = APPSTATE_ENDMENU;
				}
			}
		}
		break;

		case APPSTATE_ENDMENU:
		{
			MenuLoop_Destroy();
			AppState = APPSTATE_STARTGAME;
		}
		break;

		case APPSTATE_STARTGAME:
		{
			GameLoop_Init();
			AppState = APPSTATE_GAME;
		}
		break;

		case APPSTATE_GAME:
		{
			if (GameLoop_OnIdle())
			{
				AppState = APPSTATE_ENDGAME;
			}
		}
		break;

		case APPSTATE_ENDGAME:
		{
			GameLoop_Destroy();
			AppState = APPSTATE_STARTMENU;
		}
		break;
	}
}
// ----------------------------------------------------------------------------
void AppLoop_Screenshot(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		Texture* Tex = poCreateTexture(guiScrWidth, guiScrHeight,4);

		gpoE3DRenderer->ReadBuffer(0,0,guiScrWidth,guiScrHeight,eE3D_RB_Front,(void *)Tex->data);
		// gpoE3DRenderer->ReadBuffer(0,0,uiScrWidth,uiScrHeight,eE3D_RB_Z,(void *)Tex.data);

		FlipTextureVertical(Tex);
		SaveTexture("Screenshot.png",Tex);

		DestroyTexture(Tex);
	}
}
// ----------------------------------------------------------------------------