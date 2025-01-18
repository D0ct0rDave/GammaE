// ----------------------------------------------------------------------------
// Global module defines
// ----------------------------------------------------------------------------
#define _USE_SOUND_
#define _USE_TERRAIN_
#define _USE_SHADOWCAST_

#define _USE_LENSFLARE_
// #define _USE_DUMMIES_
// #define _USE_DETAILER_
#define _USE_CONSOLE_

bool	bFinishGame;
float	fFinishTime;
// ----------------------------------------------------------------------------
// Includes necesarios para el programa
// ----------------------------------------------------------------------------
#include "Game/GameGlobals/GameGlobals.h"
#include "GameLoop.h"
#include "GammaE.h"

#include "Input/CommandBinder/CommandBinder.h"
#include "Input/CommandDispatcher/ClientCmdDispatcher.h"
#include "Input/CGame_KeyBinder.h"
#include "Input/Commands/Orion_Commands.h"

// DEBUG_CODE
// #include "Entities/Player/ePlayerCommands.h"
#include "Scene/ProcTex.h"

#include "Game/Scene/Models/COrionObjBookmark.h"

#include "Game/Scene/CFlareMgr.h"
#include "Game/Scene/CPSysMgr.h"

#include "Game/Entities/Enemies/CSh25.h"
#include "Game/Entities/Projectile/CProjectile.h"
#include "Game/Entities/PowerUp/CPowerUp.h"
#include "Game/Entities/GameCamera/CGameCamera.h"
#include "Game/Entities/GameHUD/CGameHUD.h"
#include "Game/Entities/World/CWorldEnt.h"

#include "Game/Entities/World/CWSndPlayer.h"
#include "Game/Collision/CTRNUtils.h"
#include "Game/Collision/COrionCollision.h"

// ----------------------------------------------------------------------------
// Game Mode
// ----------------------------------------------------------------------------
#include "Game/GameModes/CGameMode.h"
#include "Game/GameModes/CGMArcade.h"

CGameMode *poGameMode;
// ----------------------------------------------------------------------------
#ifdef _BORLANDC_
	#include <dir.h>
#else
	#ifdef _MBCS
	#include <direct.h>
	#endif
#endif

#define CMF_FORWARD		0x0001
#define CMF_BACKWARD	0x0002
#define CMF_UP			0x0004
#define CMF_DOWN		0x0008
#define CMF_LEFT		0x0010
#define CMF_RIGHT		0x0020

// ----------------------------------------------------------------------------
// Variables utilizadas por el programa
// ----------------------------------------------------------------------------
CMesh_Rect				*Rect;
CObject3D_Leaf			*SuperBoxLeaf;
CObject3D_Node			*SuperBox;
CParticleSystem		    *PS;

CE3D_Viewport		   oGAMEViewport;
CE3D_Camera			   oGAMEPerspCam;
CE3D_Projector		   oGAMEPerspPrj;

CE3D_Viewport		   oGAMEHUDViewport;
CE3D_Camera			   oGAMEOrthoCam;
CE3D_Projector		   oGAMEOrthoPrj;

char				   *szCmdLine;

CObject3D_Reflector	   *Reflector;

// ----------------------------------------------------------------------------
// Dummies
// ----------------------------------------------------------------------------
CObject3D			*poDummyScene;

// ----------------------------------------------------------------------------
// Terrain
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Personaje 
// ----------------------------------------------------------------------------
CObject3D_AnimCfgGen	*MD2Model;

// ----------------------------------------------------------------------------
unsigned int CameraMovementFlags = 0;
// ----------------------------------------------------------------------------
bool			bMouseDown = false;

int				iMouseDiffX=0;
int				iMouseDiffY=0;
int				iOldMouseX = 0;
int				iOldMouseY = 0;
int				iMouseX    = 0;
int				iMouseY    = 0;

bool			bFreeCam = false;

float		 fOldPitch = 0;
float		 fPitch    = 0;
float		 fOldYaw   = 0;
float		 fYaw      = 0;
CVect3		 CamDir;
CVect3		 CamUp;
CVect3		 CamSide;


CVect3		oSunDir;
CVect3		oSunPos;


// ----------------------------------------------------------------------------
// Console variables
// ----------------------------------------------------------------------------
CGameHUD	goGHUD;
CConsole	*Console;
CE3D_Shader	*MBack  = NULL;
CE3D_Shader	*MFont  = NULL; 

// ----------------------------------------------------------------------------
// Sound variables
// ----------------------------------------------------------------------------
static bool				gbLaunchBGM = false;
CSoundEmiter			*poGAMEBGMEmiter = NULL;
CWSndPlayer				oWSP;			// World sound player

// ----------------------------------------------------------------------------
// Loading screen
// ----------------------------------------------------------------------------
#include "Game/Scene/LoadScr/CLoadScr.h"
CLoadScr	*gpoLoadScr;
bool		bLoading;
bool		bLoadReady;
/******************************************************************************
*******************************************************************************
BEGIN: HANDLE INPUT
*******************************************************************************
******************************************************************************/

// Function prototypes
void GameLoop_FinishLoad();

void GameLoop_OnCamForward  (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnCamBackward (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnCamUp       (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnCamDown     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnCamLeft     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnCamRight    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void GameLoop_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void GameLoop_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void GameLoop_OnSelW0	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW1	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW2	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW3	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW4	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW5	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW6	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW7	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW8	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW9	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelW10	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void GameLoop_OnExit	    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnAttack      (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnAttack2     (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnSelect		(unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnMouseMove   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
void GameLoop_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

void GameLoop_ToggleConsole(unsigned int Enabled,unsigned int Par1,unsigned int Par2);
extern void AppLoop_Screenshot    (unsigned int Enabled,unsigned int Par1,unsigned int Par2);

// ----------------------------------------------------------------------------
void GameLoop_SetupKeyBindings()
{
	CGame_KeyBinder KeyBinder;
	KeyBinder.Init("base/config.cfg");
}
// ----------------------------------------------------------------------------
void GameLoop_SetupCallbackFuncs()
{	
	// Camera commands
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMFORWARD ,GameLoop_OnCamForward  );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMBACKWARD,GameLoop_OnCamBackward );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMUP      ,GameLoop_OnCamUp       );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMDOWN    ,GameLoop_OnCamDown     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMLEFT    ,GameLoop_OnCamLeft     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_CAMRIGHT   ,GameLoop_OnCamRight    );

	// Player commands
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FORWARD    ,GameLoop_OnWalkForward );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_BACKWARD   ,GameLoop_OnWalkBackward);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_UP         ,GameLoop_OnWalkUp      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_DOWN       ,GameLoop_OnWalkDown    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_LEFT       ,GameLoop_OnWalkLeft    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_RIGHT      ,GameLoop_OnWalkRight   );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNUP		,GameLoop_OnTurnUp      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNDOWN	,GameLoop_OnTurnDown    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNLEFT	,GameLoop_OnTurnLeft    );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TURNRIGHT	,GameLoop_OnTurnRight   );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELECT		,GameLoop_OnSelect		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW0		,GameLoop_OnSelW0		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW1		,GameLoop_OnSelW1		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW2		,GameLoop_OnSelW2		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW3		,GameLoop_OnSelW3		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW4		,GameLoop_OnSelW4		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW5		,GameLoop_OnSelW5		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW6		,GameLoop_OnSelW6		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW7		,GameLoop_OnSelW7		);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SELW8		,GameLoop_OnSelW8		);

	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON0	,GameLoop_OnAttack      );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON1	,GameLoop_OnAttack2     );

	ClientCmdDispatcher_SetDispatchCallback(KCMD_GENMOVE	,GameLoop_OnMouseMove   );	

	ClientCmdDispatcher_SetDispatchCallback(KCMD_JUMP		,GameLoop_OnJump        );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FUNC1		,GameLoop_OnShowNormals );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_FUNC2		,GameLoop_OnShowBBoxes  );
	

	ClientCmdDispatcher_SetDispatchCallback(KCMD_EXIT		,GameLoop_OnExit        );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_TOGGLECONSOLE,GameLoop_ToggleConsole);
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SCREENSHOT	,AppLoop_Screenshot	    );
}
// ----------------------------------------------------------------------------
// Camera event handlers
// ----------------------------------------------------------------------------
void GameLoop_OnCamForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
		CameraMovementFlags |= CMF_FORWARD;
	else
		CameraMovementFlags &= ~CMF_FORWARD;
}

void GameLoop_OnCamBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{

	if (Enabled)
		CameraMovementFlags |= CMF_BACKWARD;
	else
		CameraMovementFlags &= ~CMF_BACKWARD;

}

void GameLoop_OnCamUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	

	if (Enabled)
		CameraMovementFlags |= CMF_UP;
	else
		CameraMovementFlags &= ~CMF_UP;

}

void GameLoop_OnCamDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{

	if (Enabled)
		CameraMovementFlags |= CMF_DOWN;
	else
		CameraMovementFlags &= ~CMF_DOWN;

}

void GameLoop_OnCamLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{

	if (Enabled)
		CameraMovementFlags |= CMF_LEFT;
	else
		CameraMovementFlags &= ~CMF_LEFT;

}

void GameLoop_OnCamRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	

	if (Enabled)
		CameraMovementFlags |= CMF_RIGHT;
	else
		CameraMovementFlags &= ~CMF_RIGHT;	

}

// ----------------------------------------------------------------------------
// Player event handlers
// ----------------------------------------------------------------------------
void GameLoop_OnWalkForward (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{		
	gpoPlayer->ControlCmds(PC_Forward,Enabled,1.0f);
}

void GameLoop_OnWalkBackward(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Backward,Enabled,-1.0f);
}

void GameLoop_OnWalkUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Up,Enabled,1.0f);
}

void GameLoop_OnWalkDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Down,Enabled,-1.0f);
}

void GameLoop_OnWalkLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Left,Enabled,1.0f);
}

void GameLoop_OnWalkRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Right,Enabled,-1.0f);
}

void GameLoop_OnJump        (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Jump,Enabled,1.0f);
}
// ----------------------------------------------------------------------------
void GameLoop_OnTurnUp      (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_TurnUp,Enabled,-1.0f);
}	
void GameLoop_OnTurnDown    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_TurnDown,Enabled, 1.0f);
}
void GameLoop_OnTurnLeft    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_TurnLeft,Enabled,-1.0f);
}
void GameLoop_OnTurnRight   (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_TurnRight,Enabled, 1.0f);
}

void GameLoop_ToggleConsole(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled) goGHUD.Toggle();
}
// ----------------------------------------------------------------------------
void GameLoop_OnShowNormals (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		if(goRenderer.UsingNormalRender())
			goRenderer.DisableNormalRender();
		else
			goRenderer.EnableNormalRender();
	}
}
// ----------------------------------------------------------------------------
void GameLoop_OnShowBBoxes  (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (Enabled)
	{
		if(goRenderer.UsingBBoxRender())
			goRenderer.DisableBBoxRender();
		else
			goRenderer.EnableBBoxRender();
	}
}
// ----------------------------------------------------------------------------
void GameLoop_OnAttack(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if ((bLoading) && (bLoadReady))
		GameLoop_FinishLoad();
	else
		gpoPlayer->ControlCmds(PC_ShotPrim,Enabled,5.0f);
}

void GameLoop_OnAttack2(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_ShotSec,Enabled,5.0f);
}

void GameLoop_OnSelect(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_Select,Enabled,0);
}

// ----------------------------------------------------------------------------
// Weapon selection callbacks
// ----------------------------------------------------------------------------
void GameLoop_OnSelW0(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW0,Enabled,0.0f);
}
void GameLoop_OnSelW1(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW1,Enabled,0.0f);
}
void GameLoop_OnSelW2(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW2,Enabled,0.0f);
}
void GameLoop_OnSelW3(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW3,Enabled,0.0f);
}
void GameLoop_OnSelW4(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW4,Enabled,0.0f);
}
void GameLoop_OnSelW5(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW5,Enabled,0.0f);
}
void GameLoop_OnSelW6(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW6,Enabled,0.0f);
}
void GameLoop_OnSelW7(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW7,Enabled,0.0f);
}
void GameLoop_OnSelW8(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	gpoPlayer->ControlCmds(PC_SelW8,Enabled,0.0f);
}
// ----------------------------------------------------------------------------
void GameLoop_OnExit(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	bFinishGame = true;	
}
// ----------------------------------------------------------------------------
void GameLoop_OnMouseMove    (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{	
	/*
	#define CAM_ANGLE_SCALE	2.0f

	int iXDiff = iOldMouseX - (int)iMouseX;
	int iYDiff = (int)iMouseY - iOldMouseY;

	float dPitch = ((float)iYDiff/(float)guiScrHeight) * _PI_ / CAM_ANGLE_SCALE;
	float dYaw   = ((float)iXDiff/(float)guiScrWidth ) * _PI_ / CAM_ANGLE_SCALE;

	fPitch =  fOldPitch + dPitch;
	fYaw   =  fOldYaw   + dYaw;
	
	// Setup previous camera vector
	// Establecer los nuevos ejes: Transformarlos con los nuevos ángulos incrementados		
	CMatrix4x4 R;
	R.LoadIdentity();
	R.RotateFromArbitraryAxis( dPitch,gpoPlayer->poTransf->roSide().X(),gpoPlayer->poTransf->roSide().Y(),gpoPlayer->poTransf->roSide().Z() );
	R.TransformVector(gpoPlayer->poTransf->roUp() );
	R.TransformVector(gpoPlayer->poTransf->roDir() );
	
	CVect3 oNewSide;
	oNewSide.CrossProd(gpoPlayer->poTransf->roDir(),gpoPlayer->poTransf->roUp());
	gpoPlayer->poTransf->SetSide(oNewSide);

	R.LoadIdentity();
    R.RotateFromArbitraryAxis( dYaw,gpoPlayer->poTransf->roUp().X(),gpoPlayer->poTransf->roUp().Y(),gpoPlayer->poTransf->roUp().Z() );
	R.TransformVector(gpoPlayer->poTransf->roSide());
    R.TransformVector(gpoPlayer->poTransf->roDir() );
	*/
	iMouseDiffX = Par1;
	iMouseDiffY = Par2;
}
// ----------------------------------------------------------------------------
void GameLoop_ControlCommands()
{
	if (! bFreeCam)
	{		
		const float iYEpsilon = 5;
		
		if ( (iMouseDiffY < -iYEpsilon) || (iMouseDiffY > iYEpsilon) )
		{
			const float fYAngleScale = 16.0f;
			int   iMidY  = guiScrHeight >> 1;
			float fdPitch  = (iMouseDiffY / (float)iMidY) * _PI_ / fYAngleScale;

			if (fdPitch > 0.0f)
				// As if player does DOWN command
				gpoPlayer->ControlCmds(PC_TurnDown,1,-fdPitch);
			else
				// As if player does UP command
				gpoPlayer->ControlCmds(PC_TurnUp  ,1, fdPitch);
		}
		else
		{
			gpoPlayer->ControlCmds(PC_TurnUp  ,0,0.0f);
			gpoPlayer->ControlCmds(PC_TurnDown,0,0.0f);
		}
		
		const float iXEpsilon = 5;
	
		if ( (iMouseDiffX < -iXEpsilon) || (iMouseDiffX > iXEpsilon) )
		{
			const float fXAngleScale = 16.0f;
			int   iMidX  = guiScrWidth >> 1;
			float fdYaw  = (iMouseDiffX / (float)iMidX) * _PI_ / fXAngleScale;

			if (fdYaw > 0.0f)
				// As if player does RIGHT command
				gpoPlayer->ControlCmds(PC_TurnRight,1, fdYaw);
			else
				// As if player does LEFT command
				gpoPlayer->ControlCmds(PC_TurnLeft ,1,-fdYaw);
		}
		else
		{
			gpoPlayer->ControlCmds(PC_TurnLeft ,0,0.0f);
			gpoPlayer->ControlCmds(PC_TurnRight,0,0.0f);
		}

		iOldMouseX = iMouseX;
		iOldMouseY = iMouseY;

		/*
		const float fXAngleScale = 2.0f;
		int   iXDiff  = iMouseX - iOldMouseX;
		int   iMidX   = guiScrWidth >> 1;
		float fdPitch = (iXDiff / (float)iMidX) * _PI_ / fXAngleScale;
		
		if ((fdPitch < -0.01f) || (fdPitch > 0.01f))
		{			
			if (fdPitch > 0.0f)
			{
				// As if player does LEFT command
				gpoPlayer->ControlCmds(PC_TurnLeft,1,fdPitch);
			}
			else
			{
				// As if player does RIGHT command
				gpoPlayer->ControlCmds(PC_TurnRight,1,-fdPitch);
			}
		}
		else
		{
			gpoPlayer->ControlCmds(PC_TurnLeft ,0,0.0f);
			gpoPlayer->ControlCmds(PC_TurnRight,0,0.0f);
		}
		*/
	}
	else
	{
		// Computo del vector de incremento
		static float	fInc = 64.0f;
		CVect3	Inc;

		Inc.V3(0,0,0);

		if (CameraMovementFlags & CMF_FORWARD ) Inc.Add(oGAMEPerspCam.Dir );
		if (CameraMovementFlags & CMF_BACKWARD) Inc.Sub(oGAMEPerspCam.Dir );
		if (CameraMovementFlags & CMF_UP      ) Inc.Add(oGAMEPerspCam.Up  );
		if (CameraMovementFlags & CMF_DOWN    ) Inc.Sub(oGAMEPerspCam.Up  );
		if (CameraMovementFlags & CMF_LEFT    ) Inc.Sub(oGAMEPerspCam.Side);
		if (CameraMovementFlags & CMF_RIGHT   ) Inc.Add(oGAMEPerspCam.Side);

		Inc.Scale(fInc*gfDeltaT);

		if(Inc.Module()>0)
		{
			// Incremento de la posicion de la cámara
			oGAMEPerspCam.Pos.Add(Inc); 
		}
	}
}
/******************************************************************************
*******************************************************************************
END: HANDLE INPUT
*******************************************************************************
******************************************************************************/


void GameLoop_InitEntities();

// ----------------------------------------------------------------------------
CChrono MainChrono;

// ----------------------------------------------------------------------------
int GameLoop_AddSound(bool _bLoop,int iIdx,char *_szFilename)
{
	int iSmp = CSampleWH::iLoadSample(_szFilename);
	if (iSmp == -1) return(0);
	goSound[iIdx].iAddLayer(_bLoop,CSampleWH::poGetSample(iSmp));
	CSoundWH::iAddSound(&goSound[iIdx],_szFilename);
	return(1);
}

void GameLoop_LoadSounds()
{
	#ifdef _USE_SOUND_	
	gbLaunchBGM = GameLoop_AddSound(true,GAMESND_BGM,CMapCFG::szBGMFile);

	GameLoop_AddSound(false,GAMESND_LBlaster,"base/sound/weapons/laser2.WAV");
	GameLoop_AddSound(false,GAMESND_EBlaster,"base/sound/weapons/explod1.WAV");
	
	goSndRcv.Pos.V3(0,0,0);
	goSndRcv.Speed.V3(0,0,0);
	
	goSndRenderer.SetReceiver(&goSndRcv);	
	#endif	
}

void GameLoop_RenderSound()
{
	// RenderSound
	#ifdef _USE_SOUND_

	if (gbLaunchBGM)
	{
		poGAMEBGMEmiter = goSndRenderer.poAddOmniEmiter( &goSound[GAMESND_BGM],0.5f );
		gbLaunchBGM = false;
	}

	goSndRcv.Pos.Assign (oGAMEPerspCam.Pos );
	goSndRcv.Dir.Assign (oGAMEPerspCam.Dir );
	goSndRcv.Up.Assign  (oGAMEPerspCam.Up  );
	goSndRcv.Side.Assign(oGAMEPerspCam.Side);

	goSndRenderer.Render(gfDeltaT);
	#endif
}
// ----------------------------------------------------------------------------
// 
// ----------------------------------------------------------------------------
void GameLoop_RenderProcTex(void *Par)
{
	int a=a+1;
}

void GameLoop_LoadMaterials()
{	
	// Add shader extensions
	ProcTex_Init();

	CE3D_ShaderDefWH::Invalidate();
	CE3D_ShaderWH::Invalidate();

	CE3D_ShaderExtDB::AddExtension("PROCTEX_1",ProcTex_Think);
	CE3D_ShaderDefWH::iAddShaderFile("base/Shaders.txt");
}
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
void GameLoop_SetupTerrain(char *_szTerrainScene)
{
	#ifdef _USE_TERRAIN_		

		// -- Creating / Loading		
		gpoTerrain = (CTerrainCircuit *)goTL.Load(_szTerrainScene);
		gpoTerrain->ComputeBoundVol();
		
		// Initialize terrain utils
		CTRNUtils::Init();

		// Setup terrain collision object	
		int iNumSectors = goTL.HF->iGetSecsPerRow() * goTL.HF->iGetSecsPerCol();

		// Terrain triangle list generator
		goTL.HF->SetVGenMethod(eGM_Linear);
		goTRNTriListGen.Init(goTL.HF->iGetSecsPerRow(),
							 goTL.HF->iGetSecsPerCol(),
							 goTL.iSectorRes,
							 goTL.fSectorSize);
		

		for (int i=0;i<iNumSectors;i++)
			goTRNTriListGen.SetSector(i,(CHFSector*)goTL.HF->GetSector(i));
		
		// Create and initialize the terrain triangle list
		goTRNTriList.Init(2048);


		// Setup terrain collision tester
		goTRNMeshTest.Init(goTL.HF,goTL.iSectorRes,goTL.fSectorSize);
		
		// ------------------
		// Get background
		// ------------------
		gpoBackground = mNew CObject3D_Transf;
		gpoBackground->SetObject(goTL.SkyDome);
		// gpoBackground->SetPos(

		// ------------------
		// Setup fog
		// ------------------
		CVect3 FogColor(goTL.EnvPars.fFogColor[0],		
						goTL.EnvPars.fFogColor[1],
						goTL.EnvPars.fFogColor[2]);		
		

		//	goTL.EnvPars.iFogType = 0;		
		switch (goTL.EnvPars.iFogType)
		{
			case 0:	goRenderer.SetFogPars(eE3D_FM_None,0,0,0,NULL);
					break;
			case 1:	goRenderer.SetFogPars(eE3D_FM_Linear,
					goTL.EnvPars.fFogNear,
					goTL.EnvPars.fFogFar,
					goTL.EnvPars.fFogDens,
					(TFColor*)goTL.EnvPars.fFogColor);
					break;
			case 2: goRenderer.SetFogPars(eE3D_FM_Exp,
					goTL.EnvPars.fFogNear,
					goTL.EnvPars.fFogFar,
					goTL.EnvPars.fFogDens,
					(TFColor*)goTL.EnvPars.fFogColor);
					break;
			case 3:	goRenderer.SetFogPars(eE3D_FM_Exp2,
					goTL.EnvPars.fFogNear,
					goTL.EnvPars.fFogFar,
					goTL.EnvPars.fFogDens,
					(TFColor*)goTL.EnvPars.fFogColor);
					break;
		}

		// Set sun properties
		float sphi=sin(goTL.EnvPars.fLightPhiAngle*_PI_OVER_180_);
		float cphi=cos(goTL.EnvPars.fLightPhiAngle*_PI_OVER_180_);
		float srho=sin(goTL.EnvPars.fLightRhoAngle*_PI_OVER_180_);
		float crho=cos(goTL.EnvPars.fLightRhoAngle*_PI_OVER_180_);
		
		oSunDir.V3(cphi*crho,-sphi*crho,srho);
		oSunPos.Assign(oSunDir);
		oSunPos.Scale(1000.0f);



		oGAMEPerspPrj.fFar = goTL.EnvPars.fCamFar;

		// Create world limit box
		CVect3 oCenter(goTL.HF->iGetSecsPerRow()*goTL.fSectorSize*0.5f,
						  goTL.HF->iGetSecsPerCol()*goTL.fSectorSize*0.5f,
						  0.0f);
		CVect3 oScale(goTL.HF->iGetSecsPerRow()*goTL.fSectorSize*0.9f,
						  goTL.HF->iGetSecsPerCol()*goTL.fSectorSize*0.9f,
							1000.0f);
		CMatrix4x4 oMat;
		oMat.LoadIdentity();
		oMat.Scale(oScale);
		// oMat.Translate(oCenter);
		
		CMesh	*poMesh = (CMesh_Box *)mNew CMesh_Box();
		MeshTransform_Transform(*poMesh,oMat);
						
		gpoWLLeaf = mNew CObject3D_Leaf;
		gpoWLLeaf->SetMesh( poMesh );		gpoWLLeaf->SetShader(NULL);
		gpoWLLeaf->ComputeBoundVol();

		gpoWorldLimit = mNew CObject3D_Mux;
		gpoWorldLimit->Init(1);
		gpoWorldLimit->iAddObject( gpoWLLeaf );
		gpoWorldLimit->Select(0);		

		/*
		gpoWLCol = mNew CCOL_Collider;
		gpoWLCol->Init(0,NULL,NULL,
					  eCOL_CT_Static,eCOL_TT_Tris,eCOL_TT_BV,
					  gpoWorldLimit,
					  250,10);

		gpoWLCol->Pos.V3   (0.0f,0.0f,0.0f);
		gpoWLCol->OldPos.V3(0.0f,0.0f,0.0f);
		gpoWLCol->Speed.V3 (0.0f,0.0f,0.0f);
		*/

		// -- Adding to scene
		// gameScene.AddSceneObject(SkyDome);
		/*		
		CObject3D_Node *poNode = mNew CObject3D_Node;
		CVect3 oPos(goTL.EnvPars.fXOfs,goTL.EnvPars.fYOfs,0.0f);
		
		poNode->SetPos(oPos);
		poNode->Init(2);
		poNode->iAddObject(Terrain);		
		poNode->ComputeBoundVol();
		*/
		// gameBackgroundMgr->SetBackground(SkyDome);
		
		// -- Collisions
		/*
		CCOL_Collider *poTerrainCollider = mNew CCOL_Collider;
	
		poTerrainCollider->Init(0,
								&goTRNTriListGen,
								&goTRNMeshTest,
								eCOL_CT_Static,
								eCOL_TT_Tris,
								eCOL_TT_BV,
								gpoTerrain,
								250,10);

		gCollisionSystem.iAddObject(poTerrainCollider);
		*/
	#endif
}
// ----------------------------------------------------------------------------
void GameLoop_SetupDummies(char *_szDummieScene)
{
	#ifdef _USE_DUMMIES_
			
		// -- Creating / Loading			
		/*
		CLoaderGEM oGEMLoader;
		poDummyScene = (CObject3D_Gen*)oGEMLoader.pLoad(_szDummieScene);
		*/
		
		// GameDum_Loader oDumLoader;
		// poDummyScene  = oDumLoader.pLoad("I:/Projects/GammaE/Dummies.dnf");
		
		/*
		SCNUt_SceneCompiler oScnComp;
		oScnComp.CompileScene(poDummyScene);
		*/

		// -- Adding to scene
		// gCamera.AddSceneObject(poDummyScene);

	#endif	
}
// ----------------------------------------------------------------------------
void GameLoop_SetupLensFlare()
{
	#ifdef _USE_LENSFLARE_
/*
		// -- Creating / Loading
		// Setup materials
		CE3D_Shader *pMatA,*pMatB,*pMatC;
		
		pMatA = CE3D_ShaderWH::poCreateShader("FlareSpark"); 
		pMatB = CE3D_ShaderWH::poCreateShader("FlareGlow"); 
		pMatC = CE3D_ShaderWH::poCreateShader("FlareGlow2"); 

		// Setup colors
		CVect4 ColA,ColB,ColC,ColD,ColE;
		
		ColA.V4(1.0f,1.0f,1.0f  ,1.0f);	 // white
		ColB.V4(0.52f,0.0f,1.0f ,1.0f);	 // purple
		ColC.V4(0.0f,1.0f,0.776f,0.35f); // aqua
		ColD.V4(1.0f,0.0f,0.0f  ,0.5f);  // lime
		ColE.V4(0.8f,1.0f,0.0f  ,0.25f); // red

		gpoLensFlare = mNew CLensFlare();		
		gpoLensFlare->InitLensFlare(8,oSunPos);
		gpoLensFlare->SetupFlareElem(0,0.0075 ,-0.7 ,ColD,pMatB);
		gpoLensFlare->SetupFlareElem(1,0.015  ,-0.5 ,ColB,pMatA);
		gpoLensFlare->SetupFlareElem(2,0.07   , 0   ,ColA,pMatA);
		gpoLensFlare->SetupFlareElem(3,0.011  , 0.15,ColB,pMatA);
		gpoLensFlare->SetupFlareElem(4,0.002  , 0.2 ,ColC,pMatB);
		gpoLensFlare->SetupFlareElem(5,0.011  , 0.5 ,ColC,pMatA);
		gpoLensFlare->SetupFlareElem(6,0.011  , 0.7 ,ColE,pMatA);
		gpoLensFlare->SetupFlareElem(7,0.015  , 1.2 ,ColD,pMatB);

*/	
		CE3D_Shader *poMats[4];
		
		
		poMats[0] = CE3D_ShaderWH::poCreateShader("FlareSpark");
		poMats[1] = CE3D_ShaderWH::poCreateShader("FlareHalo");
		poMats[2] = CE3D_ShaderWH::poCreateShader("FlareBloom");
		poMats[3] = CE3D_ShaderWH::poCreateShader("FlareGlow");
		/*
		poMats[0] = CE3D_ShaderWH::poCreateShader("FlareHalo");
		poMats[1] = CE3D_ShaderWH::poCreateShader("FlareHalo");
		poMats[2] = CE3D_ShaderWH::poCreateShader("FlareBloom");
		poMats[3] = CE3D_ShaderWH::poCreateShader("FlareBloom");
		*/

	typedef struct{		
		float fDist;
		float fSize;
		int   iTex;
		float fR;
		float fG;
		float fB;
		float fA;
	}TFlareElem;

	#define FLARE_ELEMS 14
	TFlareElem oFElems[FLARE_ELEMS] = {
		{   0, 50, 0, 128, 128,	128, 0},
		{  30,	6, 3,   0, 	 0,  80, 0},
		{  40, 11, 3,   8,	 0,	 64, 0},
		{  45,	8, 3,   8,	 8,	 48, 0},
		{  65,	8, 3,  16,  16,	 24, 0},
		{  90, 10, 3,  24,	24,	  0, 0},
		{ 110, 15, 3,  32,	16,	  0, 0},
		{  60,	2, 2,  12,	12,	128, 0},
		{  80,	4, 2, 128, 128,  64, 0},
		{ 135,	3, 2, 128, 128, 128, 0},
		{- 40,	3, 1,   0,   8,  32, 0},
		{ 100, 25, 1,  16,	16,	 32, 0},
		{ 150, 25, 1,  24,	24,	 24, 0},
		{ 180, 40, 1,  32,	32,	 16, 0}
	};
	CVect4 oCol;
	gpoLensFlare = mNew CLensFlare();		
	gpoLensFlare->InitLensFlare(FLARE_ELEMS,oSunPos);

	for (int i=0;i<FLARE_ELEMS;i++)
	{
		oCol.V4(oFElems[i].fR/256.0f,oFElems[i].fG/256.0f,oFElems[i].fB/256.0f,oFElems[i].fA/256.0f);
		
		gpoLensFlare->SetupFlareElem(i,
									oFElems[i].fSize/100.0f,
									oFElems[i].fDist/100.0f,
									oCol,
									poMats[oFElems[i].iTex]);
	}
	#endif
}
// ----------------------------------------------------------------------------
void GameLoop_SetupDetailer()
{
	#ifdef _USE_DETAILER_
		
		// -- Creating / Loading
		poDetailer = mNew CDetailer();
		poDetailer->Init(5000);

		// -- Adding to scene
		gCamera.AddSceneObject(poDetailer);		

		// -- Setting entities	
		GDCam.SetDetailer(poDetailer);		
		GDCam.SetCamera	 (&PerspCam);	
		WorldEntities.iAddEntity(&GDCam);

	#endif
}
// ----------------------------------------------------------------------------
void GameLoop_SetupConsole()
{
	#ifdef _USE_CONSOLE_
		#define BASE_SIZE	20

		// -- Creating / Loading
		CGraphBV_Manager::SetBVMode(eGraphBV_Box);
		Console = mNew CConsole();
		CE3D_Shader *MBack  = CE3D_ShaderWH::poCreateShader("ConsoleBackground");
		CE3D_Shader *MFont  = CE3D_ShaderWH::poCreateShader("ConsoleFont");
		Console->Init(1.0f,0.5,3*BASE_SIZE,BASE_SIZE,MBack,MFont);	
		Console->ComputeBoundVol();

		// -- Adding to scene
		goHUDMgr.SetHUD(Console);

		// -- Setting entities
		goGHUD.SetConsole(Console);
		goGHUD.Toggle();
	#endif
}
// ----------------------------------------------------------------------------
void GameLoop_SetupShadowCaster()
{
	#ifdef _USE_SHADOWCAST_
		goShadowCaster.Init(128);
	#endif
}
// ----------------------------------------------------------------------------
void GameLoop_LoadModels()
{
	// ------------------------------------------------
	// Scene engine
	// ------------------------------------------------
	// ------------------------------------------------
	// Game Map
	// ------------------------------------------------	
	GameLoop_SetupTerrain(CMapCFG::szTrnFile);	

	/*
	#ifdef _USE_DUMMIES_
		GameLoop_SetupDummies("base/data/maps/Canions/dummies5.gem");
	#endif
	*/
	
	#ifdef _USE_LENSFLARE_
		GameLoop_SetupLensFlare();
	#endif
	
	#ifdef _USE_DETAILER_
		GameLoop_SetupDetailer();
	#endif

	#ifdef _USE_SHADOWCAST_
		GameLoop_SetupShadowCaster();
	#endif

	COrionObjBookmark::LoadObjects(CMapCFG::szMeshFile);
	gpoStWorld = COrionObjBookmark::gObjBookmark[OOBE_MAP]->poModel;

	CFlareMgr::Init();
	CPSysMgr::Init();
}
// ----------------------------------------------------------------------------
void GameLoop_LoadScene()
{	
	GameLoop_LoadModels();	
}
// ----------------------------------------------------------------------------
void GameLoop_DestroyMaterials()
{
	// MipMapWH.InvalidateWarehouse();
    // TexObjWH.InvalidateWarehouse();
    CE3D_ShaderWH::Invalidate();    

	ProcTex_Finish();
}
// ----------------------------------------------------------------------------
void GameLoop_DestroyModels()
{
	//mDel (SuperBox);
}
// ----------------------------------------------------------------------------
void GameLoop_DestroyScene()
{
	GameLoop_DestroyMaterials();
	GameLoop_DestroyModels();
}
// ----------------------------------------------------------------------------
void GameLoop_Init()
{
	// -------------------------------
	// Read map configuration file
	// -------------------------------
	CMapCFG::bLoadMapCFG(gszMapFileName);

	// -------------------------------
	// Initialize Input System
	// -------------------------------
	GameLoop_SetupKeyBindings();
	GameLoop_SetupCallbackFuncs();

	// -------------------------------
	// Perspective projection camera
	// -------------------------------
	oGAMEViewport.ScrCX = 0.0f;
    oGAMEViewport.ScrCY = 0.0f;
    oGAMEViewport.ScrTX = 1.0f;
    oGAMEViewport.ScrTY = 1.0f;

    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	oGAMEPerspCam.Pos.V3 ( 0.0f,-8.0f,8.0f);

    oGAMEPerspCam.Up.V3  ( 0, 0,   1);
	oGAMEPerspCam.Dir.V3 ( 0, 1,   0);	oGAMEPerspCam.Dir.Normalize();
	oGAMEPerspCam.Side.CrossProd(oGAMEPerspCam.Dir,oGAMEPerspCam.Up);	

	oGAMEPerspPrj.ePrjType = eE3DPrjType_Perspective;
	oGAMEPerspPrj.fFOV     = 45.0f;
    oGAMEPerspPrj.fNear    = 1.0f;
    oGAMEPerspPrj.fFar     = 2000.0f;

	goCamera.Init	     (100);
	goCamera.SetCamera   (&oGAMEPerspCam);
	goCamera.SetProjector(&oGAMEPerspPrj);
	goCamera.SetViewport (&oGAMEViewport);
	
	// -------------------------------
	// Orthographic projection camera
	// -------------------------------		
	oGAMEHUDViewport.ScrCX = 0.0f;
    oGAMEHUDViewport.ScrCY = 0.0f;
    oGAMEHUDViewport.ScrTX = 1.0f;
    oGAMEHUDViewport.ScrTY = 1.0f;

	oGAMEOrthoPrj.ePrjType	= eE3DPrjType_Orthogonal;
	oGAMEOrthoPrj.fFOV		= 90.0f;
	oGAMEOrthoPrj.fNear		= 1.0f;
	oGAMEOrthoPrj.fFar		= 1000.0f;

	oGAMEOrthoCam.Pos.V3 ( 0, 0,100);
	oGAMEOrthoCam.Side.V3(-1, 0,  0);
    oGAMEOrthoCam.Up.V3  ( 0, 1,  0);
    oGAMEOrthoCam.Dir.V3 ( 0, 0, -1);

	goHUD.Init(10);
	goHUDCam.Init(10);
	goHUDCam.SetCamera	 (&oGAMEOrthoCam);
	goHUDCam.SetProjector(&oGAMEOrthoPrj);
	goHUDCam.SetViewport (&oGAMEHUDViewport);
	goHUDCam.iAddObject  (&goHUD);	

    gpoE3DRenderer->DisableFrustumCulling();
	gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);

	// -------------------------------
	// Loading screen
	// -------------------------------
	GameLoop_LoadMaterials();

	gpoLoadScr	= mNew CLoadScr;
	gpoLoadScr->Init();
	gpoLoadScr->Render();
	bLoading   = true;
	bLoadReady = false;

    /*
	CVect3 Position(1,1,1);
    CLight_Directional *Light = mNew CLight_Directional();

    Light->SetParameters(Position);
    Light->AmbientColor.r = 0.25;	Light->AmbientColor.g = 0.25;  Light->AmbientColor.b = 0.25;
	Light->DiffuseColor.r = 1;		Light->DiffuseColor.g = 1;	   Light->DiffuseColor.b = 1;

	gpoE3DRenderer->AddLight(Light);
	gpoE3DRenderer->AddLight((CLight *)Light);
	*/


	// ------------------------
	// Loading stuff
	// ------------------------
		GameLoop_LoadSounds();			// Sound initialization stuff

		GameLoop_LoadScene();
		GameLoop_InitEntities();
	
	// -----------------------
	// Init Game Mode
	// -----------------------
	poGameMode = mNew CGMArcade;
	poGameMode->Init();

	bFinishGame = false;
	fFinishTime = 5.0f;
	
	gpoLoadScr->SetPercentage(100);
	bLoadReady = true;
}
// ----------------------------------------------------------------------------
void GameLoop_FinishLoad()
{
	bLoading = false;
	// mDel gpoLoadScr;
}
// ----------------------------------------------------------------------------
void GameLoop_Destroy()
{
	GameLoop_DestroyScene();	
}
// ----------------------------------------------------------------------------
bool GameLoop_OnIdle()
{
	MainChrono.Reset();
	MainChrono.Start();

	if (bLoading)
	{
		gpoLoadScr->Render();		
	}
	else
	{
		// Input data
		GameLoop_ControlCommands();

		// Think Entities
		goGameEnt.Think(gfDeltaT);

		// Collisions
		COrionCOL::HandleCollisions();
		
		// Render Sound
		GameLoop_RenderSound();

		// Render game scene	
		CGameScene::Render();

		// GameMode Loop
		poGameMode->Loop();
	}



	MainChrono.Stop();
	gfDeltaT  = MainChrono.ElapsedTime();
	
	if (gpoPlayer->eState == OOST_DEAD)
	{
		fFinishTime	-= gfDeltaT;
		if (fFinishTime <= 0.0f)
			return(true);
	}
	else
		return( bFinishGame);
}	
// ----------------------------------------------------------------------------
void GameLoop_InitEntities()
{
	goWorldEntList.Init(1024);
	goCollisionSystem.Init(1024);

	// ------------------------------------------------
	// Entity system / Setup game entities
	// ------------------------------------------------
	gpoCameraEnt = mNew CGameCamera;
	gpoCameraEnt->SetCamera(&oGAMEPerspCam);	

	goGHUD.SetCamera(&oGAMEPerspCam);

	goGameEnt.Init(10);
	goGameEnt.poEnt.iAdd(&goWorldEntList);
 	goGameEnt.poEnt.iAdd(gpoCameraEnt);		// Add the camera entity
	goGameEnt.poEnt.iAdd(&goGHUD);
	
	#ifdef _USE_CONSOLE_
		GameLoop_SetupConsole();
	#endif

	// -----------------------
	// Orion World Entity?
	// -----------------------
	gpoWorldEnt = mNew CWorldEnt;
	goWorldEntList.poEnt.iAdd(gpoWorldEnt);
	
	// -----------------------
	// Setup world sound player
	// -----------------------
	oWSP.Setup(CMapCFG::szSndPlayFile);
	goGameEnt.poEnt.iAdd( (CGameEntity*)&oWSP );

	// ------------------
	// Setup player
	// ------------------
	// Set player spawn point
	CVect3 oCenter;
	oCenter.Assign(CMapCFG::oPlayerSpawn);
	oCenter.SetZ( CTRNUtils::fGetHeight(oCenter) + 10.0f);
	
	gpoPlayer = mNew CPlayer;		
	gpoPlayer->Setup(OETI_PLAYER,1,OOBE_SPYDA,oCenter);	

	gpoPlayerNode = gpoPlayer->poTransf;
	goWorldEntList.poEnt.iAdd(gpoPlayer);

	oGAMEPerspCam.Pos.Assign(oCenter);

	// -----------------------
	// Setup resource managers
	// -----------------------
	goProjectilMgr.Setup(mNew CProjectile[4000],4000,sizeof(CProjectile));
	goPowerUpMgr.Setup  (mNew CPowerUp    [256], 256,sizeof(CPowerUp));

	// -----------------------
	// Create initial powerups
	// -----------------------
	for (int iP=0;iP<CMapCFG::oPWSpawnInfo.iNumElems();iP++)
	{
		TPowerUpSpawnInfo	*poPUInfo = &CMapCFG::oPWSpawnInfo[iP];
		
		if ((poPUInfo->iType>= 0) && (poPUInfo->iType< 9))
		{
			oCenter.Assign(poPUInfo->oPos);
			oCenter.SetZ( CTRNUtils::fGetHeight(oCenter) + 25.0f);

			CPowerUp *poPowerUp = (CPowerUp *)goPowerUpMgr.poGet();
			poPowerUp->SetupPowerUp(poPUInfo->iType,oCenter,NULL);

			goWorldEntList.poEnt.iAdd(poPowerUp);
		}
	}
}
// ----------------------------------------------------------------------------