// --------------------------------------------------------------
#include "Game/Scene/LoadScr/CLoadScr.h"
#include "Game/GameModes/CMapCFG.h"
#include <string.h>
// --------------------------------------------------------------
const float fMapNameFontXSize =  16.0f/640.0f;
const float fMapNameFontYSize =  18.0f/480.0f;
const float fMapNameCX        =  64.0f/640.0f;
const float fMapNameCY        =  32.0f/480.0f;

const float fDescFontXSize	  =  10.0f/640.0f;
const float fDescFontYSize	  =  10.0f/480.0f;
const float fDescCX			  =  64.0f/640.0f;
const float fDescCY			  =     80/480.0f;

const float fMapIconTX	=     323.0f / 512.0f;
const float fMapIconTY	=     206.0f / 512.0f;
const float fMapIconCX	= 1.33*93.0f / 512.0f;
const float fMapIconCY	=      200.f / 512.0f;

const float fPKFontXSize	 =    10.0f/480.0f;
const float fPKFontYSize	 =    20.0f/480.0f;
const float fPKCX			 =   520.0f/640.0f;
const float fPKCY			 =   420.0f/480.0f;

TFColor oPKColors[2] = {
						{1.0f,0.0f,0.0f,0.5f},
						{1.0f,1.0f,0.0f,1.0f}
						};

// --------------------------------------------------------------
CLoadScr::CLoadScr()
{
}
// --------------------------------------------------------------
CLoadScr::~CLoadScr()
{
}
// --------------------------------------------------------------
void CLoadScr::Init()
{
	// Setup viewing objects
		// Viewport
		oLSCRHUDViewport.ScrCX = 0.0f;
		oLSCRHUDViewport.ScrCY = 0.0f;
		oLSCRHUDViewport.ScrTX = 1.0f;
		oLSCRHUDViewport.ScrTY = 1.0f;

		// Ortho projector
		oLSCROrthoPrj.ePrjType	= eE3DPrjType_Orthogonal;
		oLSCROrthoPrj.fFOV		= 90.0f;
		oLSCROrthoPrj.fNear		= 1.0f;
		oLSCROrthoPrj.fFar		= 1000.0f;
		
		// Ortho camera
		oLSCROrthoCam.Pos.V3 ( 0, 0,100);
		oLSCROrthoCam.Side.V3(-1, 0,  0);
		oLSCROrthoCam.Up.V3  ( 0, 1,  0);
		oLSCROrthoCam.Dir.V3 ( 0, 0, -1);

		// LoadingScreen camera object
		oLSCRCam.Init(1);
		oLSCRCam.SetCamera   (&oLSCROrthoCam);
		oLSCRCam.SetProjector(&oLSCROrthoPrj);
		oLSCRCam.SetViewport (&oLSCRHUDViewport );
		oLSCRCam.iAddObject	 (&oLSCRHUD);


	// Loading screen HUD
		oLSCRHUD.Init(10);
	// ------------------------
	// Create HUD objects
	// ------------------------		
	CE3D_Shader			*poFontShader;
	CE3D_Shader			*poShader;
	CE3D_ShIns_BlendOp	*poShInst;

		// Create the BGR picture
		poShader = CE3D_ShaderWH::poCreateShader("base/textures/Misc/lscrbgr.tga");
		poBgrPic = mNew CHUDIcon;
		poBgrPic->SetIcon(poShader);
		oLSCRHUD.AddObject(poBgrPic,0,0,1,1);

		// Create MapName label
		poMapName = mNew CHUDLabel;

		poFontShader = CE3D_ShaderWH::poCreateShader("base/textures/fonts/SecFont.tga");
		poShInst = mNew CE3D_ShIns_BlendOp;
		poShInst->SeteBOpType(eSIBOp_Add);
		poFontShader->PushInstruction(poShInst);

		TFColor oMapNameColor ={1.0f,1.0f,0.5f,1.0f};
		poMapName->SetFont (poFontShader);
		poMapName->SetColor(oMapNameColor);
		poMapName->SetText (CMapCFG::szMapName);

		oLSCRHUD.AddObject(poMapName,fMapNameCX,fMapNameCY,fMapNameFontXSize*strlen(CMapCFG::szMapName),fMapNameFontYSize);

		// Create Description labels
		poDesc    = mNew CHUDLabel *[CMapCFG::oDescription.iNumElems()];

		TFColor oDescColor = {0.8f,0.8f,0.8f,1.0f};
		for (int i=0;i<CMapCFG::oDescription.iNumElems();i++)
		{
			poDesc[i] = mNew CHUDLabel;

			poDesc[i]->SetFont (poFontShader);
			poDesc[i]->SetColor(oDescColor);
			poDesc[i]->SetText (CMapCFG::oDescription[i].szLine);

			oLSCRHUD.AddObject(poDesc[i],
							    fDescCX,
								fDescCY+i*fDescFontYSize,
								fDescFontXSize*strlen(CMapCFG::oDescription[i].szLine),
								fDescFontYSize);

		}
		
		// Create the Map picture
		poShader = CE3D_ShaderWH::poCreateShader(CMapCFG::szImgFile);
		poMapImg = mNew CHUDIcon;
		poMapImg->SetIcon(poShader);
		oLSCRHUD.AddObject(poMapImg,fMapIconCX,fMapIconCY,fMapIconTX,fMapIconTY);

		// Create press any key label
		poPK = mNew CHUDLabel;		
		
		TFColor oPKColor ={1.0f,1.0f,0.0f,0.0f};
		poPK->SetFont (poFontShader);
		poPK->SetColor(oPKColor);
		poPK->SetText ("Press shot button");
		poPK->Disable();

		oLSCRHUD.AddObject(poPK,fPKCX,fPKCY,fPKFontXSize*17,fPKFontYSize);
}
// --------------------------------------------------------------
void CLoadScr::Render()
{
	// Update text color	
	TFColor oColor;
	float fFact = gpoE3DRenderer->REStats.fTotalTime - 
				  (int)gpoE3DRenderer->REStats.fTotalTime;

	if (fFact > 0.5f)
		fFact = (1.0f - fFact)*2.0f;
	else
		fFact = fFact*2.0f;

	oColor.r = MMath_Lerp(fFact, oPKColors[0].r, oPKColors[1].r);
	oColor.g = MMath_Lerp(fFact, oPKColors[0].g, oPKColors[1].g);
	oColor.b = MMath_Lerp(fFact, oPKColors[0].b, oPKColors[1].b);
	oColor.a = MMath_Lerp(fFact, oPKColors[0].a, oPKColors[1].a);

	poPK->SetColor(oColor);

	// Render
	gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);
	gpoE3DRenderer->BeginRender();

		oLSCRCam.Render();

	gpoE3DRenderer->EndRender();
}
// --------------------------------------------------------------
void CLoadScr::SetPercentage(float _fFact)
{
	if (_fFact == 100)
		poPK->Enable();

}
// --------------------------------------------------------------