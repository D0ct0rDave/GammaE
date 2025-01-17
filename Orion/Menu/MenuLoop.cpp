// ------------------------------------------------------------------------------
#include "MenuLoop.h"
#include "Menu/MenuGlobals/MenuGlobals.h"
#include "Input/CGame_KeyBinder.h"
#include "Input/CommandDispatcher/ClientCmdDispatcher.h"

#include "Menu/CMenuTextGrid.h"

// ------------------------------------------------------------------------------
float		fFadeText	= 1.0f;
float		fAccDelta	= 0.0f;
float		fCurAlpha   = 0.0f;
bool		bFinishMenu = false;

bool		bPageFadeOutIn = false;
bool		bTextFadeOutIn = false;
bool		bLaunchBGM  = true;
// ------------------------------------------------------------------------------
typedef enum eMENUOpType{
	MENUOT_ENABLED,
	MENUOT_DISABLED,
	MENUOT_COMMENT,
	MENUOT_NUM_OTS
};

typedef struct{
	char			szText[32];
	eMENUOpType		eOpType;
}TMenuOptions;

typedef struct{
	
	CDynArray <TMenuOptions> oOpts;
	int		iFont;
	int		iCurSel;

}TPageOptions;

#define		MAX_MENU_PAGES	32

CHeadUpDisplay			oMENUHud  [MAX_MENU_PAGES];
TPageOptions			oMENUPOpts[MAX_MENU_PAGES];

CMenuTextGrid			*poMENUTxtGrid;
CObject3D_Leaf			*poMENUTxtLeaf;
// ------------------------------------------------------------------------------
enum MENUSHADERS{
	MENUSH_Fade,
	MENUSH_Stars,
	MENUSH_Title,
	MENUSH_MainBack,
	MENUSH_PrimFont,
	MENUSH_SecFont,
	MENUSH_NUM_SHADERS,
};

CE3D_Shader				*poMENUShader[1024];

CE3D_Viewport			oMENUViewport;
CE3D_Camera				oMENUPerspCam;
CE3D_Projector			oMENUPerspPrj;
CE3D_Camera				oMENUOrthoCam;
CE3D_Projector			oMENUOrthoPrj;

CMesh					*poMENUBckMesh;
CObject3D_Leaf			*poMENUBckLeaf;

CSkyDome				*poMENUSky;

#define			MAX_FLARES		16
CLensFlare				*poMENULF[MAX_FLARES];
// ------------------------------------------------------------------------------
#define MENUBGM

enum MENUSOUNDS{
	MENUSND_Intro,

	MENUSND_Move,
	MENUSND_Select,
	MENUSND_Back,
	MENUSND_Exit,
	MENUSH_NUM_SOUNDS
};

CSoundReceiver			oMENUSndRcv;
CSound					oMENUSound[100];
CSoundEmiter			*poMENUBGMEmiter;
// ------------------------------------------------------------------------------
CChrono oMENUChrono;
// ------------------------------------------------------------------------------
typedef enum eMENUFadeState{
	MENUFST_FADEIN,
	MENUFST_FADEOUT,
	MENUFST_IDLE,
	MENUFST_FADETEXTIN,
	MENUFST_FADETEXTOUT,
	MENUFST_FADETOBLACK,
	MENUFST_NUM_FSTS
};

CMesh			*poMENUFadeMesh;
eMENUFadeState	eFadeState	     = MENUFST_FADEIN;
eMENUFadeState	eGlobalFadeState = MENUFST_FADEIN;

#ifdef MENUBGM
	float			fFadeMult		= 1.0f / 3.0f;
#else
	float			fFadeMult		= 1.0f / 0.5f;
#endif

float			fScrFade		= 1.0f;
/********************************************************************************

*********************************************************************************/
eMENUState		eMenuState      = MENUST_MAIN;
eMENUState		eMenuNextState  = MENUST_MAIN;
// ------------------------------------------------------------------------------
unsigned int uiMenuCMDs;

#define MENUCMD_UP	0x01
#define MENUCMD_DN	0x02
#define MENUCMD_LF	0x04
#define MENUCMD_RT	0x08

void MenuLoop_SetupKeyBindings()
{
	CGame_KeyBinder KeyBinder;
	KeyBinder.Init("base/menukeys.cfg");
}

void MenuLoop_OnUp(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;

	if (Enabled)
	{
		int iNewSel = oMENUPOpts[eMenuState].iCurSel - 1;
		if (iNewSel<0)
			iNewSel = oMENUPOpts[eMenuState].oOpts.iNumElems()- 1;

		do{
			if (! oMENUPOpts[eMenuState].oOpts[iNewSel].eOpType == MENUOT_ENABLED)
				iNewSel--;

			if (iNewSel<0) 
				iNewSel = oMENUPOpts[eMenuState].oOpts.iNumElems() - 1;
		
		}while(oMENUPOpts[eMenuState].oOpts[iNewSel].eOpType != MENUOT_ENABLED);
		
		// Set new active option
		oMENUPOpts[eMenuState].iCurSel = iNewSel;

		// Send sound
		goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Move],1.0f);
	}
}

void MenuLoop_OnDown (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;

	if (Enabled)
	{
		int iNewSel = oMENUPOpts[eMenuState].iCurSel + 1;
		if (iNewSel >= oMENUPOpts[eMenuState].oOpts.iNumElems())
			iNewSel = 0;

		do 
		{
			if (! oMENUPOpts[eMenuState].oOpts[iNewSel].eOpType == MENUOT_ENABLED)
				iNewSel++;
			if (iNewSel >= oMENUPOpts[eMenuState].oOpts.iNumElems())
				iNewSel = 0;
		}while(oMENUPOpts[eMenuState].oOpts[iNewSel].eOpType != MENUOT_ENABLED);
		
		// Set new active option
		oMENUPOpts[eMenuState].iCurSel = iNewSel;
		
		// Send sound
		goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Move],1.0f);

	}
}

void MenuLoop_OnLeft (unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;
	if (Enabled) uiMenuCMDs |= MENUCMD_LF; else uiMenuCMDs &= ~MENUCMD_LF;
}

void MenuLoop_OnRight(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;
	if (Enabled) uiMenuCMDs |= MENUCMD_RT; else uiMenuCMDs &= ~MENUCMD_RT;
}

void MenuLoop_OnSelect(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;
	bool bSound = false;

	switch (eMenuState)
	{
		// MAIN MENU
		case MENUST_MAIN:
		{
			switch(oMENUPOpts[eMenuState].iCurSel)
			{
				case 0:
				{
					eMenuNextState  = MENUST_MISSION;
					
					fFadeMult       = 1.0f/0.5f;
					eFadeState		= MENUFST_FADETEXTOUT;
					eGlobalFadeState= MENUFST_FADETEXTOUT;
					bSound		    = true;
				}
				break;

				case 1:
				{
					eMenuNextState  = MENUST_LOADGAME;	
					bSound		    = true;
				}
				break;

				case 2:
				{
					eMenuNextState  = MENUST_CREDITS;	
					bSound		    = true;
				}
				break;

				case 4:
				{
					eMenuNextState  = MENUST_QUIT;

					fFadeMult       = 1.0f/0.5f;
					eFadeState		= MENUFST_FADETEXTOUT;
					eGlobalFadeState= MENUFST_FADETEXTOUT;
					bSound		    = true;
				}
				break;
			}
		}
		break;

		// QUIT MENU
		case MENUST_QUIT:
		{
			switch(oMENUPOpts[eMenuState].iCurSel)
			{
				case 1:
				{
					bFinishMenu     = true;
					fFadeMult       = 1.0f/2.0f;
					eFadeState		= MENUFST_FADEOUT;
					eGlobalFadeState= MENUFST_FADETOBLACK;
					eMenuNextState  = MENUST_QUIT;					
					goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Exit],1.0f);
					bSound		    = false;					
				}
				break;

				case 2:
				{
					fFadeMult       = 1.0f/0.5f;
					eGlobalFadeState= MENUFST_FADETEXTOUT;
					eFadeState		= MENUFST_FADETEXTOUT;
					eMenuNextState  = MENUST_MAIN;	
					bSound		    = true;
				}
				break;
			}
		}
		break;

		// MISSION MENU
		case MENUST_MISSION:
		{
			bFinishMenu     = true;
			fFadeMult       = 1.0f/2.0f;
			eFadeState		= MENUFST_FADEOUT;
			eGlobalFadeState= MENUFST_FADETOBLACK;
			eMenuNextState  = MENUST_MISSION;					
			goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Exit],1.0f);
			bSound		    = false;

			switch(oMENUPOpts[eMenuState].iCurSel)
			{
				case 1:
				strcpy(gszMapFileName,"base/gamemodes/arcade/missions/vhunt.cfg");
				break;
				case 2:
				strcpy(gszMapFileName,"base/gamemodes/arcade/missions/canions.cfg");
				break;
				case 3:
				strcpy(gszMapFileName,"base/gamemodes/arcade/missions/warehouse.cfg");
				break;
			}
		}
		break;
	}
	
	if (bSound)
		goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Select],1.0f);
}

void MenuLoop_OnButton1(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;
}

void MenuLoop_OnMouseMove(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;
}

void MenuLoop_OnExit(unsigned int Enabled,unsigned int Par1,unsigned int Par2)
{
	if (eGlobalFadeState != MENUFST_IDLE) return;
	
	bool bSound = false;
	switch (eMenuState)
	{
		case MENUST_MAIN:
		{		
		}
		break;
		
		case MENUST_CREDITS:
		{		
			fFadeMult       = 1.0f/0.5f;
			eFadeState		= MENUFST_FADETEXTOUT;
			eGlobalFadeState= MENUFST_FADETEXTOUT;
			eMenuNextState  = MENUST_MAIN;
			bSound          = true;
		}
		break;
		
		case MENUST_QUIT:
		{		
			fFadeMult       = 1.0f/0.5f;
			eFadeState		= MENUFST_FADETEXTOUT;
			eGlobalFadeState= MENUFST_FADETEXTOUT;
			eMenuNextState  = MENUST_MAIN;	
			bSound          = true;
		}
		break;
	}
	if (bSound)
		goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Back],1.0f);
}
// ----------------------------------------------------------------------------
extern void AppLoop_Screenshot   (unsigned int Enabled,unsigned int Par1,unsigned int Par2);
// ----------------------------------------------------------------------------
void MenuLoop_SetupCallbackFuncs()
{	
	ClientCmdDispatcher_SetDispatchCallback(KCMD_UP         ,MenuLoop_OnUp   );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_DOWN       ,MenuLoop_OnDown );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_LEFT       ,MenuLoop_OnLeft );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_RIGHT      ,MenuLoop_OnRight);

	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON0	,MenuLoop_OnSelect   );
	
	ClientCmdDispatcher_SetDispatchCallback(KCMD_BUTTON1	,MenuLoop_OnButton1  );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_GENMOVE	,MenuLoop_OnMouseMove);	
	ClientCmdDispatcher_SetDispatchCallback(KCMD_EXIT		,MenuLoop_OnExit     );
	ClientCmdDispatcher_SetDispatchCallback(KCMD_SCREENSHOT	,AppLoop_Screenshot );
}

/********************************************************************************

*********************************************************************************/
void MenuLoop_CreateFlares()
{
	const	float	fRad = 1000.0f;
	CVect3			SunPos;
	float			fRho;
	float			fPhi;
	float			fX,fY,fZ;
	float			fCosR,fSinR,fCosP,fSinP;	


	// Setup materials
	CE3D_Shader *pMatA,*pMatB,*pMatC;		
	pMatA = CE3D_ShaderWH::poCreateShader("FlareSpark"); 
	pMatB = CE3D_ShaderWH::poCreateShader("FlareGlow"); 
	pMatC = CE3D_ShaderWH::poCreateShader("FlareGlow2"); 


	// Setup Lens Flare
	for (int iL=0;iL<MAX_FLARES;iL++)
	{	
		fRho = MATH_Common::fRand()*_2PI_;
		fPhi = MATH_Common::fRand()* _PI_;
		
		fCosR = cosf(fRho);
		fSinR = sinf(fRho);
		fSinP = cosf(fPhi);
		fCosP = sinf(fPhi);

		fX = fRad*(fCosR * fCosP);
		fY = fRad*(fCosR * fSinP);
		fZ = fRad*(fSinR);
		
		SunPos.V3(fX,fY,fZ);
		
		// Create and setup flare
		poMENULF[iL] = mNew CLensFlare;
		poMENULF[iL]->InitLensFlare(8,SunPos);

		// Setup colors
		CVect4 ColA,ColB,ColC,ColD,ColE;
		float fA = MATH_Common::fRand()*0.5f;
		float fB = MATH_Common::fRand();
		float fC = MATH_Common::fRand();
		float fD = MATH_Common::fRand();

		ColA.V4(1.0f,1.0f,fA+0.5f,1.0f);	
		ColB.V4(fB  ,0.0f,1.0f   ,1.0f);	
		ColC.V4(0.0f,fC  ,fD     ,0.35f);
		ColD.V4(1.0f,0.0f,fA     ,0.5f);
		ColE.V4(fB  ,fC  ,0.0f   ,0.25f);

		poMENULF[iL]->SetupFlareElem(0,0.075*MATH_Common::fRand() + 0.015f,-0.7 ,ColD,pMatB);
		poMENULF[iL]->SetupFlareElem(1,0.15 *MATH_Common::fRand() + 0.05f ,-0.5 ,ColB,pMatA);
		poMENULF[iL]->SetupFlareElem(2,0.7  *MATH_Common::fRand() + 0.1f  , 0   ,ColA,pMatA);
		poMENULF[iL]->SetupFlareElem(3,0.11 *MATH_Common::fRand() + 0.05f , 0.15,ColB,pMatA);
		poMENULF[iL]->SetupFlareElem(4,0.02 *MATH_Common::fRand() + 0.01f , 0.2 ,ColC,pMatB);
		poMENULF[iL]->SetupFlareElem(5,0.11 *MATH_Common::fRand() + 0.05f , 0.5 ,ColC,pMatA);
		poMENULF[iL]->SetupFlareElem(6,0.11 *MATH_Common::fRand() + 0.05f , 0.7 ,ColE,pMatA);
		poMENULF[iL]->SetupFlareElem(7,0.15 *MATH_Common::fRand() + 0.07f , 1.2 ,ColD,pMatB);
	}
}
// ------------------------------------------------------------------------------
void MenuLoop_LoadModels()
{
	CGraphBV_Manager::SetBVMode(eGraphBV_Box);

	poMENUBckMesh = mNew CMesh_Rect();
	poMENUBckLeaf = mNew CObject3D_Leaf;

	poMENUBckLeaf->SetMesh  (poMENUBckMesh);
	poMENUBckLeaf->SetShader(poMENUShader[MENUSH_Title]);
	poMENUBckLeaf->ComputeBoundVol();

	// Text grid mesh for displaying options
	poMENUTxtGrid = mNew CMenuTextGrid();
	poMENUTxtGrid->Init(16,128);

	poMENUTxtLeaf = mNew CObject3D_Leaf;
	poMENUTxtLeaf->SetMesh(poMENUTxtGrid);
	
	// Setup fade mesh
	poMENUFadeMesh = mNew CMesh_Rect();
	mDel (poMENUFadeMesh->VCs);
	poMENUFadeMesh->VCs = NULL;


	// Setup sky dome
	CVect3 oOrigin(0.0f,0.0f,0.0f);
	CVect3 oAxis  (0.0f,0.0f,1.0f);
	
	poMENUSky = mNew CSkyDome;
	poMENUSky->SetPosition(oOrigin);
	poMENUSky->SetAxis    (oAxis);
	poMENUSky->SetRadius  (1500.0f);
	poMENUSky->CreateDome(false,16,16,0,16,8,8);
	poMENUSky->SetShader( poMENUShader[MENUSH_Stars] );	

	MenuLoop_CreateFlares();
}
// ------------------------------------------------------------------------------
void MenuLoop_LoadTextures()
{
	CE3D_ShaderDefWH::iAddShaderFile("base/menushaders.txt");	
	
	// Setup fade shader
	poMENUShader[MENUSH_Fade]       = mNew CE3D_Shader;
	CE3D_ShIns_Color	*poShInsCol = mNew CE3D_ShIns_Color;
	poMENUShader[MENUSH_Fade]->AddInstruction(poShInsCol);

	// Load other shaders
	poMENUShader[MENUSH_Stars]    = CE3D_ShaderWH::poCreateShader("Stars");	
	poMENUShader[MENUSH_Title]    = CE3D_ShaderWH::poCreateShader("MenuTitle");		
	poMENUShader[MENUSH_MainBack] = CE3D_ShaderWH::poCreateShader("MenuBack");
	poMENUShader[MENUSH_PrimFont] = CE3D_ShaderWH::poCreateShader("PrimFont");
	poMENUShader[MENUSH_SecFont ] = CE3D_ShaderWH::poCreateShader("SecFont");
}
/********************************************************************************

*********************************************************************************/
inline void AddOption(int _iPage,eMENUOpType _eOpType,char *_szText)
{
	TMenuOptions oMOpt;
	strcpy(oMOpt.szText,_szText);
	oMOpt.eOpType = _eOpType;
	oMENUPOpts[_iPage].oOpts.iAdd(oMOpt);
}

void MenuLoop_SetupPages()
{
	// -----------------------
	// Main Page
	// -----------------------
	oMENUHud[MENUST_MAIN].Init(4);

	AddOption(MENUST_MAIN,MENUOT_ENABLED,	"New game");
	AddOption(MENUST_MAIN,MENUOT_DISABLED,	"Load game");
	AddOption(MENUST_MAIN,MENUOT_DISABLED,	"Credits");
	AddOption(MENUST_MAIN,MENUOT_DISABLED,	"");
	AddOption(MENUST_MAIN,MENUOT_ENABLED,	"Quit");

	oMENUPOpts[MENUST_MAIN].iFont   = MENUSH_PrimFont,
	oMENUPOpts[MENUST_MAIN].iCurSel = 0;

	oMENUHud[MENUST_MAIN].AddObject(poMENUBckLeaf,0.0f      ,0.0f,1.0f,0.5f);
	oMENUHud[MENUST_MAIN].AddObject(poMENUTxtLeaf,0.25f*1.33,0.5f,0.5f,0.4f);	

	// -----------------------
	// Quit page
	// -----------------------
	oMENUHud[MENUST_QUIT].Init(4);
	AddOption(MENUST_QUIT,MENUOT_COMMENT,"Are you sure?");
	AddOption(MENUST_QUIT,MENUOT_ENABLED,"Yes");
	AddOption(MENUST_QUIT,MENUOT_ENABLED,"No");

	oMENUPOpts[MENUST_QUIT].iFont   = MENUSH_PrimFont,
	oMENUPOpts[MENUST_QUIT].iCurSel = 1;

	oMENUHud[MENUST_QUIT].AddObject(poMENUBckLeaf,0.0f      ,0.0f,1.0f,0.5f);
	oMENUHud[MENUST_QUIT].AddObject(poMENUTxtLeaf,0.25f*1.33,0.5f,0.5f,0.4f);

	// -----------------------
	// Map page
	// -----------------------
	oMENUHud[MENUST_MISSION].Init(4);
	AddOption(MENUST_MISSION,MENUOT_COMMENT,"Select mission");
	AddOption(MENUST_MISSION,MENUOT_ENABLED,"Vampire Hunt");
	AddOption(MENUST_MISSION,MENUOT_ENABLED,"Canions of Thorm");
	AddOption(MENUST_MISSION,MENUOT_ENABLED,"The warehouse");

	oMENUPOpts[MENUST_MISSION].iFont   = MENUSH_PrimFont,
	oMENUPOpts[MENUST_MISSION].iCurSel = 1;

	oMENUHud[MENUST_MISSION].AddObject(poMENUBckLeaf,0.0f      ,0.0f,1.0f,0.5f);
	oMENUHud[MENUST_MISSION].AddObject(poMENUTxtLeaf,0.25f*1.33,0.5f,0.5f,0.4f);
}
/********************************************************************************

*********************************************************************************/
void MenuLoop_LoadBGM()
{
	int iSmp,iSmpLoop;
	iSmp     = CSampleWH::iLoadSample("base/sound/menu/bgm00.wav");
	iSmpLoop = CSampleWH::iLoadSample("base/sound/menu/bgm00Loop.wav");

	if ((iSmp == -1) || (iSmpLoop == -1))
	{
		CONPrintf("Unable to open BGM.\n");
		return;
	}

	oMENUSound[MENUSND_Intro].iAddLayer(false,CSampleWH::poGetSample(iSmp    ));
	oMENUSound[MENUSND_Intro].iAddLayer(true ,CSampleWH::poGetSample(iSmpLoop));

	CSoundWH::iAddSound(&oMENUSound[MENUSND_Intro],"BGM");	
}

void MenuLoop_LoadSound(char *_szSound,int _iSnd)
{
	int iSmp;
	iSmp = CSampleWH::iLoadSample(_szSound);

	if (iSmp == -1)
	{
		CONPrintf("Unable to load %s.\n",_szSound);
		return;
	}

	oMENUSound[_iSnd].iAddLayer(false,CSampleWH::poGetSample(iSmp));
	CSoundWH::iAddSound(&oMENUSound[_iSnd],_szSound);	
}

void MenuLoop_LoadSounds()
{
	#ifdef MENUBGM
	MenuLoop_LoadBGM();
	#endif

	MenuLoop_LoadSound("base/sound/menu/secret.wav",MENUSND_Exit);
	MenuLoop_LoadSound("base/sound/menu/menu1.wav" ,MENUSND_Move);
	MenuLoop_LoadSound("base/sound/menu/menu2.wav" ,MENUSND_Select);
	MenuLoop_LoadSound("base/sound/menu/menu3.wav" ,MENUSND_Back);
}

void MenuLoop_SetupSound()
{
	MenuLoop_LoadSounds();
	goSndRenderer.SetReceiver(&oMENUSndRcv);
}
/********************************************************************************

*********************************************************************************/
void MenuLoop_Init()
{
	oMENUViewport.ScrCX = 0.0f;
    oMENUViewport.ScrCY = 0.0f;
    oMENUViewport.ScrTX = 1.0f;
    oMENUViewport.ScrTY = 1.0f;
 
    // La orientacion de la cámara se determina utilizando 3 vectores
    // que son los ejes locales de la cámara
	// PerspCam.Pos.V3 ( 4, 10,270);
	oMENUPerspCam.Pos.V3 ( 0.0f,-8.0f,8.0f);

    oMENUPerspCam.Up.V3  ( 0, 0,   1);
	oMENUPerspCam.Dir.V3 ( 0, 1,   0);	oMENUPerspCam.Dir.Normalize();
	oMENUPerspCam.Side.CrossProd(oMENUPerspCam.Dir,oMENUPerspCam.Up);	

	oMENUPerspPrj.ePrjType = eE3DPrjType_Perspective;
	oMENUPerspPrj.fFOV     = 45.0f;
    oMENUPerspPrj.fNear    = 1.0f;
    oMENUPerspPrj.fFar     = 2000.0f;
		
	// -------------------------------
	// Orthographic projection camnera
	// -------------------------------		
	oMENUOrthoPrj.ePrjType	= eE3DPrjType_Orthogonal;
	oMENUOrthoPrj.fFOV		= 90.0f;
	oMENUOrthoPrj.fNear		= 1.0f;
	oMENUOrthoPrj.fFar		= 1000.0f;
	
	oMENUOrthoCam.Pos.V3 ( 0, 0, 100);
	oMENUOrthoCam.Side.V3(-1, 0,   0);
    oMENUOrthoCam.Up.V3  ( 0, 1,   0);
    oMENUOrthoCam.Dir.V3 ( 0, 0,  -1);

    gpoE3DRenderer->SetViewport (&oMENUViewport);
    gpoE3DRenderer->SetCamera   (&oMENUOrthoCam);
	gpoE3DRenderer->SetProjector(&oMENUOrthoPrj);

    gpoE3DRenderer->DisableFrustumCulling();
	gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);	

	MenuLoop_LoadTextures();
	MenuLoop_LoadModels();
	MenuLoop_SetupPages();

	MenuLoop_LoadSounds();

	MenuLoop_SetupKeyBindings();
	MenuLoop_SetupCallbackFuncs();
}
/********************************************************************************

*********************************************************************************/
void MenuLoop_Destroy()
{
}
/********************************************************************************

*********************************************************************************/
void MenuLoop_UpdateOptions(TPageOptions *_poOpts)
{
	TFColor	oSelColor      = {1.0f,1.0f,0.0f,1.0f};	
	TFColor	oEnabledColor  = {1.0f,1.0f,1.0f,1.0f};
	TFColor	oDisabledColor = {0.5f,0.5f,0.5f,0.75f};	
	TFColor	oCommentColor  = {0.5f,0.5f,1.0f,1.0f};


	// Setup font
	poMENUTxtLeaf->SetShader( poMENUShader[_poOpts->iFont] );

	poMENUTxtGrid->Reset();
	for (int iOpt=0;iOpt<_poOpts->oOpts.iNumElems();iOpt++)
	{
		switch (_poOpts->oOpts[iOpt].eOpType)
		{
			case MENUOT_ENABLED:
			{
				poMENUTxtGrid->WriteText( _poOpts->oOpts[iOpt].szText,
										 (iOpt == _poOpts->iCurSel)?oSelColor:oEnabledColor,
										 (iOpt == _poOpts->iCurSel)?fCurAlpha*fFadeText:fFadeText);
			}
			break;

			case MENUOT_DISABLED:
			poMENUTxtGrid->WriteText( _poOpts->oOpts[iOpt].szText,oDisabledColor,fFadeText);
			break;

			case MENUOT_COMMENT:
			poMENUTxtGrid->WriteText( _poOpts->oOpts[iOpt].szText,oCommentColor,fFadeText);
			break;
		}
	}

	poMENUTxtLeaf->ComputeBoundVol();
}

void MenuLoop_UpdatePage(TPageOptions *_poPOpts)
{
	fAccDelta += gfDeltaT;
	if (fAccDelta > 2.0f) fAccDelta -= 2.0f;

	if (fAccDelta < 1.0f)
		fCurAlpha = fAccDelta;
	else
		fCurAlpha = 2.0f - fAccDelta;

	MenuLoop_UpdateOptions(_poPOpts);	
}
/********************************************************************************

*********************************************************************************/
void MenuLoop_FadeOutScreen()
{
	if (fScrFade<1.0f)
	{
		fScrFade += gfDeltaT * fFadeMult;
		if (fScrFade >= 1.0f)
		{	
			fScrFade       = 1.0f;
			eFadeState = MENUFST_IDLE;
		}

		CE3D_ShIns_Color *poCol = (CE3D_ShIns_Color *)poMENUShader[MENUSH_Fade]->pGetInstruction(0);
		poCol->oColor.SetColor(0.0f,0.0f,0.0f,fScrFade);
	}

	gpoE3DRenderer->RenderMesh(poMENUFadeMesh,poMENUShader[MENUSH_Fade]);
}

void MenuLoop_FadeInScreen()
{
	if (fScrFade>0.0f)
	{
		fScrFade -= gfDeltaT * fFadeMult;
		if (fScrFade<=0.0f)
		{	
			fScrFade = 0.0f;
			eFadeState = MENUFST_IDLE;
		}

		CE3D_ShIns_Color *poCol = (CE3D_ShIns_Color *)poMENUShader[MENUSH_Fade]->pGetInstruction(0);
		poCol->oColor.SetColor(0.0f,0.0f,0.0f,fScrFade);
	}

	gpoE3DRenderer->RenderMesh(poMENUFadeMesh,poMENUShader[MENUSH_Fade]);
}

void MenuLoop_FadeOutText()
{
	if (fFadeText>0.0f)
	{
		fFadeText -= gfDeltaT * fFadeMult;
		if (fFadeText<=0.0f)
		{	
			fFadeText  = 0.0f;
			eFadeState = MENUFST_IDLE;
		}
	}
}

void MenuLoop_FadeInText()
{
	if (fFadeText<1.0f)
	{
		fFadeText += gfDeltaT * fFadeMult;
		if (fFadeText >= 1.0f)
		{	
			fFadeText  = 1.0f;
			eFadeState = MENUFST_IDLE;
		}
	}
}
/********************************************************************************

*********************************************************************************/
float fRho = 0.0f;
float fPhi = 0.0f;

void MenuLoop_RenderBackground()
{
	// Rotate camera
	CVect3 oOrigin(0.0f,0.0f,0.0f);

	fRho += gfDeltaT*0.05f;		if (fRho > _2PI_) fRho -= _2PI_;
	fPhi += gfDeltaT*0.025f;	if (fPhi > _2PI_) fPhi -= _2PI_;

	float fCosR = cosf(fRho);
	float fSinR = sinf(fRho);

	float fSinP = cosf(fPhi);
	float fCosP = sinf(fPhi);

	const float fRad = 1.0f;

	float fX = fRad*(fCosR * fCosP);
	float fY = fRad*(fCosR * fSinP);
	float fZ = fRad*(fSinR);

	// oMENUPerspCam.SetPos(fX,fY,fZ);
	// oMENUPerspCam.LookAt(oOrigin);

	oMENUPerspCam.SetPos(0.0f,0.0f,0.0f);
	oMENUPerspCam.SetDir(fRho,fPhi,0.0f);

    // gpoE3DRenderer->SetViewport (&oMENUViewport);
    gpoE3DRenderer->SetCamera(&oMENUPerspCam);
	gpoE3DRenderer->SetProjector(&oMENUPerspPrj);

	poMENUSky->Render();
	for (int iL=0;iL<MAX_FLARES;iL++)
		poMENULF[iL]->Render();

	// Restore orthographic camera
	gpoE3DRenderer->SetCamera(&oMENUOrthoCam);
	gpoE3DRenderer->SetProjector(&oMENUOrthoPrj);
}
/********************************************************************************

*********************************************************************************/
void MenuLoop_RenderMenu()
{
	// gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);
	gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);
	gpoE3DRenderer->BeginRender ();

		MenuLoop_RenderBackground();

		MenuLoop_UpdatePage( &oMENUPOpts[eMenuState]);
		oMENUHud[eMenuState].Render();

		// Screen or text fading
		switch (eFadeState)
		{
			case MENUFST_FADEIN:		MenuLoop_FadeInScreen();	break;
			case MENUFST_FADEOUT:		MenuLoop_FadeOutScreen();	break;
			case MENUFST_FADETEXTIN:	MenuLoop_FadeInText();		break;
			case MENUFST_FADETEXTOUT:	MenuLoop_FadeOutText();		break;
		}

	gpoE3DRenderer->EndRender();
}
// ------------------------------------------------------------------------------
void MenuLoop_HandleStateMachine()
{
	// bChangingMenuPage
	switch (eGlobalFadeState)
	{
		case MENUFST_FADEOUT:
		{
			if (eFadeState==MENUFST_IDLE)
			{
				// Fade out complete
				eFadeState = MENUFST_FADEIN;
				eMenuState    = eMenuNextState;
				eGlobalFadeState = MENUFST_FADEIN;
			}
		}
		break;

		case MENUFST_FADEIN:
		{
			if (eFadeState==MENUFST_IDLE)
			{
				// Fade in complete
				eGlobalFadeState = MENUFST_IDLE;
			}
		}
		break;

		case MENUFST_FADETEXTOUT:
		{
			if (eFadeState==MENUFST_IDLE)
			{
				// Fade out complete
				eFadeState = MENUFST_FADETEXTIN;
				eMenuState    = eMenuNextState;
				eGlobalFadeState = MENUFST_FADETEXTIN;
			}
		}
		break;

		case MENUFST_FADETEXTIN:
		{
			if (eFadeState==MENUFST_IDLE)
			{
				// Fade in complete
				eGlobalFadeState = MENUFST_IDLE;
			}
		}
		break;

		case MENUFST_FADETOBLACK:
		{			
			if (eFadeState==MENUFST_IDLE)
			{
				// Fade out complete
				bFinishMenu   = true;
				eMenuState    = eMenuNextState;
			}

			// Fade out sound also
			if (poMENUBGMEmiter->fVol>0.0f)
				poMENUBGMEmiter->fVol -= gfDeltaT*0.5f;
		}
		break;
	}
}
// ------------------------------------------------------------------------------
bool MenuLoop_OnIdle()
{
	// Posibly launched several times
	if (bLaunchBGM)
	{
		#ifdef MENUBGM
		poMENUBGMEmiter = goSndRenderer.poAddOmniEmiter(&oMENUSound[MENUSND_Intro],0.5f);
		#endif
		bLaunchBGM = false;
	}

	MenuLoop_HandleStateMachine();

	oMENUChrono.Reset();
	oMENUChrono.Start();

		MenuLoop_RenderMenu();
		goSndRenderer.Render(gfDeltaT);

	oMENUChrono.Stop();
	gfDeltaT  = oMENUChrono.ElapsedTime();

	return (bFinishMenu && (eFadeState == MENUFST_IDLE));
}
// ------------------------------------------------------------------------------