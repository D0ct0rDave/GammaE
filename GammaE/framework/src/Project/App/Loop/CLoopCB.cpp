// ----------------------------------------------------------------------------
#include "CLoopCB.h"
#include "GammaE.h"
#include "CLoopGlobals.h"

#include "Game/CGame.h"
#include <FreeImage.h>

// ----------------------------------------------------------------------------
// Camera event handlers
// ----------------------------------------------------------------------------
void CLoopCB_OnCamForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnCamBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnCamUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
}

void CLoopCB_OnCamDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnCamLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnCamRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
}
// ----------------------------------------------------------------------------
// Player event handlers
// ----------------------------------------------------------------------------
void CLoopCB_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}	
void CLoopCB_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}
void CLoopCB_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}
void CLoopCB_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}

void CLoopCB_ToggleConsole(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		loopGlobals.m_oCI.Toggle();
}
// ----------------------------------------------------------------------------
void CLoopCB_Screenshot(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
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
		
		FIBITMAP *bitmap = FreeImage_Allocate(uiScrWidth,uiScrHeight,32,0x000000ff,0x0000ff00,0x00ff0000);
		if (bitmap == NULL) return;

		void* data = FreeImage_GetBits(bitmap);
		CGRenderer::I()->ReadBuffer(0,0,uiScrWidth,uiScrHeight,eE3D_RB_Front,data);
		// CGRenderer::I()->ReadBuffer(0,0,uiScrWidth,uiScrHeight,eE3D_RB_Z,(void *)Tex.data);		

		static int iIdx = 0;
		char szStr[MAX_CARS];
		sprintf(szStr,"screenshot%04d.png",iIdx); iIdx++;

		FreeImage_Save(FIF_PNG,bitmap,szStr,0);
		
		FreeImage_Unload(bitmap);
	}
}
// ----------------------------------------------------------------------------
void CLoopCB_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
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
void CLoopCB_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
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
void CLoopCB_OnAttack       (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_OnAttack2(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}
// ----------------------------------------------------------------------------
void CLoopCB_OnMouseMove    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
}
// ----------------------------------------------------------------------------
bool CLoopCB_bFinnishApp()
{
	return(loopGlobals.m_bFinnishApplication);
}
// ----------------------------------------------------------------------------
void CLoopCB_OnExit	       (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	loopGlobals.m_bFinnishApplication = true;
}
// ----------------------------------------------------------------------------
void CLoopCB_ReloadMaterials(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	CMipMapWH::I()->Invalidate();
	CTexObjWH::I()->Invalidate();

	CE3D_ShaderDefFileWH::I()->Reload();
	CE3D_ShaderWH::I()->Invalidate();
}
// ----------------------------------------------------------------------------
void CLoopCB_ControlCommands()
{
	
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
void CLoopCB_KeyPress(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if ((Enabled) && (loopGlobals.m_oCI.eGameAppState() == GAPPST_OPEN))
		loopGlobals.m_oCI.ReceiveChar( gsKeys2CharTable[Par2 & 0xff] );		
}
// ----------------------------------------------------------------------------
void CLoopCB_Shuffle(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
	}
}
// ----------------------------------------------------------------------------
void CLoopCB::Init()
{
	CGCommandBindingLoader oLd;
	oLd.Init("data/config.cfg");

	// Camera commands
	CGCommandDispatcher::I()->RegisterCommandCallback("CamForward",CLoopCB_OnCamForward  );
	CGCommandDispatcher::I()->RegisterCommandCallback("CamBackward",CLoopCB_OnCamBackward );
	CGCommandDispatcher::I()->RegisterCommandCallback("CamUp",CLoopCB_OnCamUp       );
	CGCommandDispatcher::I()->RegisterCommandCallback("CamDown",CLoopCB_OnCamDown     );
	CGCommandDispatcher::I()->RegisterCommandCallback("CamLeft",CLoopCB_OnCamLeft     );
	CGCommandDispatcher::I()->RegisterCommandCallback("CamRight",CLoopCB_OnCamRight    );

	// Player commands
	CGCommandDispatcher::I()->RegisterCommandCallback("WalkForward",CLoopCB_OnWalkForward );
	CGCommandDispatcher::I()->RegisterCommandCallback("WalkBackward",CLoopCB_OnWalkBackward);
	CGCommandDispatcher::I()->RegisterCommandCallback("WalkUp",CLoopCB_OnWalkUp      );
	CGCommandDispatcher::I()->RegisterCommandCallback("WalkDown",CLoopCB_OnWalkDown    );
	CGCommandDispatcher::I()->RegisterCommandCallback("WalkLeft",CLoopCB_OnWalkLeft    );
	CGCommandDispatcher::I()->RegisterCommandCallback("WalkRight",CLoopCB_OnWalkRight   );

	CGCommandDispatcher::I()->RegisterCommandCallback("TurnUp",CLoopCB_OnTurnUp      );
	CGCommandDispatcher::I()->RegisterCommandCallback("TurnDown",CLoopCB_OnTurnDown    );
	CGCommandDispatcher::I()->RegisterCommandCallback("TurnLeft",CLoopCB_OnTurnLeft    );
	CGCommandDispatcher::I()->RegisterCommandCallback("TurnRight",CLoopCB_OnTurnRight   );
	CGCommandDispatcher::I()->RegisterCommandCallback("ReloadMaterials",CLoopCB_ReloadMaterials);

	CGCommandDispatcher::I()->RegisterCommandCallback("Attack2",CLoopCB_OnAttack2     );

	CGCommandDispatcher::I()->RegisterCommandCallback("Attack",CLoopCB_OnAttack      );
	CGCommandDispatcher::I()->RegisterCommandCallback("MouseMove",CLoopCB_OnMouseMove   );

	CGCommandDispatcher::I()->RegisterCommandCallback("Jump",CLoopCB_OnJump        );
	CGCommandDispatcher::I()->RegisterCommandCallback("ShowNormals",CLoopCB_OnShowNormals );
	CGCommandDispatcher::I()->RegisterCommandCallback("ShowBBoxes",CLoopCB_OnShowBBoxes  );

	CGCommandDispatcher::I()->RegisterCommandCallback("Exit",CLoopCB_OnExit        );
	CGCommandDispatcher::I()->RegisterCommandCallback("ToggleConsole",CLoopCB_ToggleConsole);
	CGCommandDispatcher::I()->RegisterCommandCallback("Screenshot",CLoopCB_Screenshot	   );
	
	CGCommandDispatcher::I()->RegisterCommandCallback("Shuffle",CLoopCB_Shuffle	   );
	CGCommandDispatcher::I()->RegisterCommandCallback("KeyPress",CLoopCB_KeyPress      );
}
// ----------------------------------------------------------------------------