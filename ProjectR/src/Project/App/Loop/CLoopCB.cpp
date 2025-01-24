// ----------------------------------------------------------------------------
#include "CLoopCB.h"
#include "GammaE.h"
#include "CLoopGlobals.h"
#include "Game/CGameGlobals.h"

#include "Game/CGame.h"
#include <FreeImage.h>
#include "Game/Entities/CGameFlow.h"
#include "Game/GameUtils/CColliderRenderer.h"
// ----------------------------------------------------------------------------
// Camera event handlers
// ----------------------------------------------------------------------------
void CLoopCB_OnCamForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}

void CLoopCB_OnCamBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}

void CLoopCB_OnCamUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{	
}

void CLoopCB_OnCamDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}

void CLoopCB_OnCamLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}

void CLoopCB_OnCamRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{	
}
// ----------------------------------------------------------------------------
// Player event handlers
// ----------------------------------------------------------------------------
void CLoopCB_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{	
}

void CLoopCB_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}

void CLoopCB_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	CGInputHandler* poInput = (CGInputHandler*)CGGameRegistry::I()->oGetVar("PlayerInput");
	poInput->SetValue("up",Enabled?1.0f:0.0f);
}

void CLoopCB_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	CGInputHandler* poInput = (CGInputHandler*)CGGameRegistry::I()->oGetVar("PlayerInput");
	poInput->SetValue("down",Enabled?1.0f:0.0f);
}

void CLoopCB_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	CGInputHandler* poInput = (CGInputHandler*)CGGameRegistry::I()->oGetVar("PlayerInput");
	poInput->SetValue("left",Enabled?1.0f:0.0f);
}

void CLoopCB_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	CGInputHandler* poInput = (CGInputHandler*)CGGameRegistry::I()->oGetVar("PlayerInput");
	poInput->SetValue("right",Enabled?1.0f:0.0f);
}

void CLoopCB_OnAttack       (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	CGInputHandler* poInput = (CGInputHandler*)CGGameRegistry::I()->oGetVar("PlayerInput");
	poInput->SetValue("fire",Enabled?1.0f:0.0f);
}

void CLoopCB_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{

}

void CLoopCB_OnAttack2(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{

}
// ----------------------------------------------------------------------------
void CLoopCB_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}	
void CLoopCB_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
void CLoopCB_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
void CLoopCB_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}

void CLoopCB_ToggleConsole(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (Enabled)
		loopGlobals.m_oCI.Toggle();
}
// ----------------------------------------------------------------------------
void CLoopCB_Screenshot(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (Enabled)
	{
		/*
		if (! CGRenderer::I()->UsingFlatRendering())
			CGRenderer::I()->EnableFlatRendering();
		else
			CGRenderer::I()->DisableFlatRendering();
		*/	
		
		uint uiScrWidth  = CGRenderer::I()->iGetScrTX();
		uint uiScrHeight = CGRenderer::I()->iGetScrTY();

		FIBITMAP *bitmap = FreeImage_Allocate(uiScrWidth,uiScrHeight,32, 0x000000ff, 0x0000ff00, 0x00ff0000);
		if (bitmap == NULL) return;

		BYTE* data = FreeImage_GetBits(bitmap);
		CGRenderer::I()->ReadBuffer(0,0,uiScrWidth,uiScrHeight,E3D_RB_Front,(void*)data);

		{
			// Swap R&B channels
			FIBITMAP* rChannel = FreeImage_GetChannel(bitmap, FREE_IMAGE_COLOR_CHANNEL::FICC_RED);
			FIBITMAP* bChannel = FreeImage_GetChannel(bitmap, FREE_IMAGE_COLOR_CHANNEL::FICC_BLUE);

			if ((rChannel != NULL) && (bChannel != NULL))
			{
				FreeImage_SetChannel(bitmap, bChannel, FREE_IMAGE_COLOR_CHANNEL::FICC_RED);
				FreeImage_SetChannel(bitmap, rChannel, FREE_IMAGE_COLOR_CHANNEL::FICC_BLUE);
			}

			if (rChannel != NULL) FreeImage_Unload(rChannel);
			if (bChannel != NULL) FreeImage_Unload(bChannel);
		}
		// CGRenderer::I()->ReadBuffer(0,0,uiScrWidth,uiScrHeight,E3D_RB_Z,(void *)Tex.data);		

		static int iIdx = 0;
		char szStr[MAX_CARS];
		sprintf(szStr,"screenshot%04d.png",iIdx); iIdx++;
		FreeImage_Save(FIF_PNG, bitmap, szStr,0);

		FreeImage_Unload(bitmap);
	}
}
// ----------------------------------------------------------------------------
void CLoopCB_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	/*
	if (Enabled)
	{
		if(gRenderer.UsingNormalRender())
			gRenderer.DisableNormalRender();
		else
			gRenderer.EnableNormalRender();
	}
	*/
}		
// ----------------------------------------------------------------------------
void CLoopCB_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	/*
	if (Enabled)
	{
		if(gRenderer.UsingBBoxRender())
			gRenderer.DisableBBoxRender();
		else
			gRenderer.EnableBBoxRender();
	}
	*/
}
// ----------------------------------------------------------------------------
void CLoopCB_OnMouseMove    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (! Enabled) return;

	CGTrailInstance* poTrail = (CGTrailInstance*)CGGameRegistry::I()->oGetVar("Trail");
	if (poTrail)
	{
		CVect3 oPos;
		oPos.x = (float)Par1 / (float)CGRenderer::I()->iGetScrTX();
		oPos.y = 1.0f - ((float)Par2 / (float)CGRenderer::I()->iGetScrTY());
		oPos.z = -10.0f;

		poTrail->SetPos(oPos);
	}
}
// ----------------------------------------------------------------------------
bool CLoopCB_bFinnishApp()
{
	return(loopGlobals.m_bFinnishApplication);
}
// ----------------------------------------------------------------------------
void CLoopCB_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	loopGlobals.m_bFinnishApplication = true;
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadMaterials(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (! Enabled) return;
	
	CMipMapWH::I()->Invalidate();
	CTexObjWH::I()->Invalidate();

	CE3D_ShaderDefFileWH::I()->Reload();
	CE3D_ShaderWH::I()->Invalidate();
	CGProgramWH::I()->Reload();
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadScripts(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (! Enabled) return;

	CGScriptResourceWH::I()->Reload();
	
	// Show also console output
	loopGlobals.m_oCI.Exec("LOG");
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadPSysDefs(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (! Enabled) return;
	CGPSGDefFileWH::I()->Reload();
}
// ----------------------------------------------------------------------------
void CLoopCB_ReinitGameflow(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	CGGameEntity* poGF = (CGGameEntity*)CGGameRegistry::I()->oGetVar("GameFlow");

	if (poGF)
		((CGameFlow*)poGF)->Reinit();
}
// ----------------------------------------------------------------------------
void CLoopCB_ShowCollisionBVs(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (Enabled)
	{
		if (CColliderRenderer::I()->bEnabled())
			CColliderRenderer::I()->Disable();
		else
			CColliderRenderer::I()->Enable();			
	}
}
// ----------------------------------------------------------------------------
static char gsKeys2CharTable[256] = {
	  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,
	 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,

	' ','!','"','#','$','%','&',' ','(',')','*','+',',','-','.','/',
	'0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?',
	'@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
	'P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_',
	'`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','/',	// changed o to /
	'p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','',

	'€','','‚','ƒ','„','…','†','‡','ˆ','‰','Š','‹','Œ','','Ž','',
	'','‘','’','“','”','•','–','—','˜','™','š','›','œ','','ž','Ÿ',
	' ','¡','¢','£','¤','¥','¦','§','¨','©','ª','«','¬','­','®','¯',
	'°','±','²','³','´','µ','¶','·','¸','¹','º','»','¼','½','.','¿',	// changed ¾ by .
	'À','Á','Â','Ã','Ä','Å','Æ','Ç','È','É','Ê','Ë','Ì','Í','Î','Ï',
	'Ð','Ñ','Ò','Ó','Ô','Õ','Ö','×','Ø','Ù','Ú','Û','Ü','Ý','Þ','ß',
	'à','á','â','ã','ä','å','æ','ç','è','é','ê','ë','ì','í','î','ï',
	'ð','ñ','ò','ó','ô','õ','ö','÷','ø','ù','ú','û','ü','ý','þ','ÿ',
};
// ----------------------------------------------------------------------------
void CLoopCB_KeyPress(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if ((Enabled) && (loopGlobals.m_oCI.eGameAppState() == GAPPST_OPEN))
		loopGlobals.m_oCI.ReceiveChar( gsKeys2CharTable[Par2 & 0xff] );		
}
// ----------------------------------------------------------------------------
void CLoopCB_StopTime(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (Enabled)
	{
		if (loopGlobals.m_fTimeMult>0)
			loopGlobals.m_fTimeMult = 0.0f;
		else
			loopGlobals.m_fTimeMult = 1.0f;
	}
}
// ----------------------------------------------------------------------------
void CLoopCB_Command(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	// Show also console output
	loopGlobals.m_oCI.Exec(_sCmdPars);
}
// ----------------------------------------------------------------------------
void CLoopCB::Init()
{
	// ---------------------------------------------------
	// Register our application commands.
	// ---------------------------------------------------
	CGCommandRegistry::I()->RegisterCommand("CamForward",CLoopCB_OnCamForward  );
	CGCommandRegistry::I()->RegisterCommand("CamBackward",CLoopCB_OnCamBackward );
	CGCommandRegistry::I()->RegisterCommand("CamUp",CLoopCB_OnCamUp       );
	CGCommandRegistry::I()->RegisterCommand("CamDown",CLoopCB_OnCamDown     );
	CGCommandRegistry::I()->RegisterCommand("CamLeft",CLoopCB_OnCamLeft     );
	CGCommandRegistry::I()->RegisterCommand("CamRight",CLoopCB_OnCamRight    );

	// Player commands
	CGCommandRegistry::I()->RegisterCommand("WalkForward",CLoopCB_OnWalkForward );
	CGCommandRegistry::I()->RegisterCommand("WalkBackward",CLoopCB_OnWalkBackward);
	CGCommandRegistry::I()->RegisterCommand("WalkUp",CLoopCB_OnWalkUp      );
	CGCommandRegistry::I()->RegisterCommand("WalkDown",CLoopCB_OnWalkDown    );
	CGCommandRegistry::I()->RegisterCommand("WalkLeft",CLoopCB_OnWalkLeft    );
	CGCommandRegistry::I()->RegisterCommand("WalkRight",CLoopCB_OnWalkRight   );

	CGCommandRegistry::I()->RegisterCommand("TurnUp",CLoopCB_OnTurnUp      );
	CGCommandRegistry::I()->RegisterCommand("TurnDown",CLoopCB_OnTurnDown    );
	CGCommandRegistry::I()->RegisterCommand("TurnLeft",CLoopCB_OnTurnLeft    );
	CGCommandRegistry::I()->RegisterCommand("TurnRight",CLoopCB_OnTurnRight   );
	CGCommandRegistry::I()->RegisterCommand("ReloadMaterials",CLoopCB_ReloadMaterials);
	CGCommandRegistry::I()->RegisterCommand("ReloadScripts",CLoopCB_ReloadScripts);
	CGCommandRegistry::I()->RegisterCommand("ReloadPSysDefs",CLoopCB_ReloadPSysDefs);
	CGCommandRegistry::I()->RegisterCommand("ReinitGameflow",CLoopCB_ReinitGameflow);

	CGCommandRegistry::I()->RegisterCommand("Attack2",CLoopCB_OnAttack2     );

	CGCommandRegistry::I()->RegisterCommand("Attack",CLoopCB_OnAttack      );
	CGCommandRegistry::I()->RegisterCommand("MouseMove",CLoopCB_OnMouseMove   );

	CGCommandRegistry::I()->RegisterCommand("Jump",CLoopCB_OnJump        );
	CGCommandRegistry::I()->RegisterCommand("ShowNormals",CLoopCB_OnShowNormals );
	CGCommandRegistry::I()->RegisterCommand("ShowBBoxes",CLoopCB_OnShowBBoxes  );

	CGCommandRegistry::I()->RegisterCommand("Exit",CLoopCB_OnExit        );
	CGCommandRegistry::I()->RegisterCommand("ToggleConsole",CLoopCB_ToggleConsole);
	CGCommandRegistry::I()->RegisterCommand("Screenshot",CLoopCB_Screenshot	   );
	
	CGCommandRegistry::I()->RegisterCommand("KeyPress",CLoopCB_KeyPress      );
	CGCommandRegistry::I()->RegisterCommand("Command",CLoopCB_Command       );
	CGCommandRegistry::I()->RegisterCommand("ShowCollisionBV",CLoopCB_ShowCollisionBVs);
	CGCommandRegistry::I()->RegisterCommand("StopTime",CLoopCB_StopTime);
	
	

	// Now load binding information from config file
	// CGCommandBindingLoader oLd;
	// oLd.Init("data/config.cfg");
}
// ----------------------------------------------------------------------------
