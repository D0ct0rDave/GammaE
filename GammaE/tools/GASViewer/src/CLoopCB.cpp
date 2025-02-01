// ----------------------------------------------------------------------------
#include "CLoopCB.h"
#include "GammaE.h"
// #include "CLoopGlobals.h"
// #include "Game/CGameGlobals.h"

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
}
// ----------------------------------------------------------------------------
void CLoopCB_Screenshot(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (Enabled)
	{
		if (CGRenderer::I()->bIsUsingNormalRender())
		{
			CGRenderer::I()->DisableNormalRender();
		}
		else
		{
			CGRenderer::I()->EnableNormalRender();
		}
	}
}
// ----------------------------------------------------------------------------
void CLoopCB_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (Enabled)
	{
		if (CGRenderer::I()->bIsUsingBBRender())
		{
			CGRenderer::I()->DisableBVRender();
		}
		else
		{
			CGRenderer::I()->EnableBVRender();
		}
	}
}
// ----------------------------------------------------------------------------
void CLoopCB_OnMouseMove    (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
bool CLoopCB_bFinnishApp()
{
	return(false);
}
// ----------------------------------------------------------------------------
void CLoopCB_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadMaterials(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	if (! Enabled) return;
	
	CGMipMapWH::I()->Invalidate();
	CGTexObjWH::I()->Invalidate();

	CGShaderDefFileWH::I()->Reload();
	CGShaderWH::I()->Invalidate();
	CGProgramWH::I()->Reload();
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadScripts(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadPSysDefs(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_ReinitGameflow(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_ShowCollisionBVs(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
	/*
	if (Enabled)
	{
		if (CColliderRenderer::I()->bEnabled())
			CColliderRenderer::I()->Disable();
		else
			CColliderRenderer::I()->Enable();			
	}
	*/
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
}
// ----------------------------------------------------------------------------
void CLoopCB_StopTime(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_Command(unsigned int Enabled,unsigned int Par1,unsigned int Par2, const CGString& _sCmdPars)
{
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
	CGCommandBindingLoader oLd;
	oLd.Init("data/config.cfg");
}
// ----------------------------------------------------------------------------
