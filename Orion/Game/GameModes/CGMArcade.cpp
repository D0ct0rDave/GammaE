// --------------------------------------------------------------
//
// --------------------------------------------------------------
#include "CGMArcade.h"
#include "Game/GameGlobals/GameGlobals.h"

#include "Game/Collision/CTRNUtils.h"
// --------------------------------------------------------------
const float fMiniMapSize = 96.0f;
const float fMiniMapMargin = 15.0f;
const float fMiniMapTX = fMiniMapSize/640.0f;
const float fMiniMapTY = fMiniMapSize/480.0f;
const float fMiniMapCX = (640.0f - fMiniMapSize - fMiniMapMargin)/640.0f*1.333f; 
const float fMiniMapCY = fMiniMapMargin/480.0f; 

const float fEBarTX = 154.0f/640.0f;
const float fEBarTY =  34.0f/480.0f;
const float fEBarCX =  12.0f/640.0f;
const float fEBarCY = 24.0f/480.0f;
const float fEBarWidth = 8.0f/34.0f;
const float fSBarOfs   =26.0f/34.0f;

const float fEBFrameTX = 256.0f/640.0f;
const float fEBFrameTY =  64.0f/480.0f;
const float fEBFrameCX =   8.0f/640.0f;
const float fEBFrameCY = 12.0f/480.0f;

const float fScoreFontSize = 32.0f/480.0f;
const float fScoreCX =   8.0f/640.0f;
const float fScoreCY =  64.0f/480.0f;

const float fWSelTX =	512.0f / 640.0f;
const float fWSelTY =    32.0f / 480.0f;
const float fWSelCX =   (640.0f-512.0f)*0.5f*1.33f / 640.0f;
const float fWSelCY =   440.0f / 480.0f;

const float fPWIconTX	=  64.0f / 640.0f;
const float fPWIconTY	=  64.0f / 480.0f;
const float fPWIconCX	=  1.33f*(320.0f-64.0f-8.0f) / 640.0f;
const float fPWIconCY	= 380.0f / 480.0f;

const float fSWIconTX	=  64.0f / 640.0f;
const float fSWIconTY	=  64.0f / 480.0f;
const float fSWIconCX	=  1.33f*(320.0f+8.0f) / 640.0f;
const float fSWIconCY	= 380.0f / 480.0f;

const float fAmmoFontSize = 8.0f/480.0f;
const float fPAmmoCX =  fPWIconCX + 1.333f * 16.0f/640.0f;
const float fPAmmoCY =  fPWIconCY + 38.0f/480.0f;
const float fSAmmoCX =  fSWIconCX + 1.333f * 16.0f/640.0f;
const float fSAmmoCY =  fSWIconCY + 38.0f/480.0f;
// --------------------------------------------------------------



// --------------------------------------------------------------
CGMArcade::CGMArcade()
{
	
}
// --------------------------------------------------------------
CGMArcade::~CGMArcade()
{
	
}
// --------------------------------------------------------------
void CGMArcade::Init()
{
	CE3D_Shader *poShader,*poFontShader,*poAmmoFontShader;
	// 
	int iNumSecs = goTL.HF->iGetSecsPerRow() * goTL.HF->iGetSecsPerCol();
	pbVisitedSecs = mNew bool [iNumSecs];
	memset(pbVisitedSecs,0,iNumSecs*sizeof(bool));

	// --------------
	// Create HUD elements
	// --------------	
	goHUD.Invalidate();

		// --------------
		// Create Minimap
		// --------------

			// Mesh
			poMiniMapMesh = mNew CMesh;
			poMiniMapMesh->Init(iNumSecs*4,
							iNumSecs,
							E3D_MESH_NIQUADS,
							MESH_FIELD_VERTEXS | MESH_FIELD_UVCOORDS | MESH_FIELD_COLORS);

			int		cI,cJ,iQuad;
			float	fStepU = 1.0f / (float)goTL.HF->iGetSecsPerRow();
			float	fStepV = 1.0f / (float)goTL.HF->iGetSecsPerCol();

			for (cJ=0;cJ<goTL.HF->iGetSecsPerCol();cJ++)
				for (cI=0;cI<goTL.HF->iGetSecsPerRow();cI++)
				{
					iQuad = cJ*goTL.HF->iGetSecsPerCol() + cI;
					
					poMiniMapMesh->VXs[iQuad*4+0].V3(cI  ,cJ  ,0.0f);
					poMiniMapMesh->VXs[iQuad*4+1].V3(cI  ,cJ+1,0.0f);
					poMiniMapMesh->VXs[iQuad*4+2].V3(cI+1,cJ+1,0.0f);
					poMiniMapMesh->VXs[iQuad*4+3].V3(cI+1,cJ  ,0.0f);
				
					poMiniMapMesh->UVs[iQuad*4+0].V2(fStepU*(cI  ),fStepV*(cJ  ));
					poMiniMapMesh->UVs[iQuad*4+1].V2(fStepU*(cI  ),fStepV*(cJ+1));
					poMiniMapMesh->UVs[iQuad*4+2].V2(fStepU*(cI+1),fStepV*(cJ+1));
					poMiniMapMesh->UVs[iQuad*4+3].V2(fStepU*(cI+1),fStepV*(cJ  ));

					poMiniMapMesh->VCs[iQuad*4+0].V4(0.5f,0.5f,0.5f,0.95f);
					poMiniMapMesh->VCs[iQuad*4+1].V4(0.5f,0.5f,0.5f,0.95f);
					poMiniMapMesh->VCs[iQuad*4+2].V4(0.5f,0.5f,0.5f,0.95f);
					poMiniMapMesh->VCs[iQuad*4+3].V4(0.5f,0.5f,0.5f,0.95f);
				}

			// Shader
			poMiniMapSh = CE3D_ShaderWH::poCreateShader(CMapCFG::szMiniMapFile);
			CE3D_ShIns_BlendOp	*poShInst = mNew CE3D_ShIns_BlendOp;
			poShInst->SeteBOpType(eSIBOp_Alpha);
			poMiniMapSh->PushInstruction(poShInst);

			// Leaf node
			poMiniMap = mNew CObject3D_Leaf;
			poMiniMap->SetMesh(poMiniMapMesh);
			poMiniMap->SetShader(poMiniMapSh);
			poMiniMap->ComputeBoundVol();

			// Set MiniMap position and size
			goHUD.AddObject(poMiniMap,fMiniMapCX,fMiniMapCY,fMiniMapTX,fMiniMapTY);

		// ------------------------
		// Create energy/shield HUD
		// ------------------------
			poEnergyBarMesh = mNew CMesh;
			poEnergyBarMesh->Init(2*4,
								  2,
								  E3D_MESH_NIQUADS,
								  MESH_FIELD_VERTEXS | MESH_FIELD_COLORS);

			TFColor oEnergyBarColor = {1.0f,1.0f,1.0f,1.0f};
			poEnergyBarSh = CE3D_ShaderUtils::poGenerateShaderFromColor(oEnergyBarColor,"EnergyBarColor");


			// EnergyBar
			poEnergyBarMesh->VXs[0].V3(0.0f,0.0f		,0.0f);
			poEnergyBarMesh->VXs[1].V3(0.0f,fEBarWidth	,0.0f);
			poEnergyBarMesh->VXs[2].V3(1.0f,fEBarWidth	,0.0f);
			poEnergyBarMesh->VXs[3].V3(1.0f,0.0f		,0.0f);

			poEnergyBarMesh->VCs[0].V4(1.0f,0.0f,0.0f,1.0f);
			poEnergyBarMesh->VCs[1].V4(1.0f,0.0f,0.0f,1.0f);
			poEnergyBarMesh->VCs[2].V4(1.0f,1.0f,0.0f,1.0f);
			poEnergyBarMesh->VCs[3].V4(1.0f,1.0f,0.0f,1.0f);

			// ShieldBar
			poEnergyBarMesh->VXs[4].V3(0.0f,fSBarOfs,0.0f);
			poEnergyBarMesh->VXs[5].V3(0.0f,1.0f	,0.0f);
			poEnergyBarMesh->VXs[6].V3(1.0f,1.0f	,0.0f);
			poEnergyBarMesh->VXs[7].V3(1.0f,fSBarOfs,0.0f);

			poEnergyBarMesh->VCs[4].V4(0.0f,0.0f,1.0f,1.0f);
			poEnergyBarMesh->VCs[5].V4(0.0f,0.0f,1.0f,1.0f);
			poEnergyBarMesh->VCs[6].V4(0.0f,1.0f,0.0f,1.0f);
			poEnergyBarMesh->VCs[7].V4(0.0f,1.0f,0.0f,1.0f);

			poEnergyBar = mNew CObject3D_Leaf;
			poEnergyBar->SetMesh  (poEnergyBarMesh);
			poEnergyBar->SetShader(poEnergyBarSh);
			poEnergyBar->ComputeBoundVol();


			// Set EnergyBar position and size				
			goHUD.AddObject(poEnergyBar,fEBarCX,fEBarCY,fEBarTX,fEBarTY);

			// Energy bar frame
			poShader = CE3D_ShaderWH::poCreateShader("base/gamemodes/arcade/ebar.tga");
			poShInst = mNew CE3D_ShIns_BlendOp;
			poShInst->SeteBOpType(eSIBOp_AlphaAdd);
			poShader->PushInstruction(poShInst);

			poEBFrame = mNew CHUDIcon;
			poEBFrame->SetIcon(poShader);

			// Set energy bar frame position and size
			goHUD.AddObject(poEBFrame,fEBFrameCX,fEBFrameCY,fEBFrameTX,fEBFrameTY);
		
		// ------------------------
		// Create score label
		// ------------------------
			poScore = mNew CHUDLabel;
		
			poFontShader = CE3D_ShaderWH::poCreateShader("base/textures/fonts/ScoreFont.tga");
			poShInst = mNew CE3D_ShIns_BlendOp;
			poShInst->SeteBOpType(eSIBOp_Alpha);
			poFontShader->PushInstruction(poShInst);
			
			TFColor oScoreColor ={1.0f,1.0f,0.75f,1.0f};
			poScore->SetFont(poFontShader);
			poScore->SetColor(oScoreColor);

			// Set EnergyBar position and size				
			goHUD.AddObject(poScore,fScoreCX,fScoreCY,8*fScoreFontSize,fScoreFontSize);

		// ------------------------
		// Create weapon selection mesh
		// ------------------------
			
			// WS Mesh
			TFColor		oWSColor = {1.0f,1.0f,1.0f,1.0f};
			poWSMesh = mNew CMesh();
			poWSMesh->Init(5*4,
						   5,
						   E3D_MESH_NIQUADS,
						   MESH_FIELD_VERTEXS | MESH_FIELD_COLORS | MESH_FIELD_UVCOORDS);

			float fU1,fU2;
			float fStep = 1.0f/5.0f; //96.0f/512.0f;
			for (cI=0;cI<5;cI++)
			{
				fU1 =     cI*fStep;
				fU2 = (cI+1)*fStep;

				poWSMesh->VXs[cI*4+0].V3(fU1,0.0f,0.0f);
				poWSMesh->VXs[cI*4+1].V3(fU1,1.0f,0.0f);
				poWSMesh->VXs[cI*4+2].V3(fU2,1.0f,0.0f);
				poWSMesh->VXs[cI*4+3].V3(fU2,0.0f,0.0f);

				poWSMesh->UVs[cI*4+0].V2(fU1,0.0f);
				poWSMesh->UVs[cI*4+1].V2(fU1,1.0f);
				poWSMesh->UVs[cI*4+2].V2(fU2,1.0f);
				poWSMesh->UVs[cI*4+3].V2(fU2,0.0f);

				poWSMesh->VCs[cI*4+0].V4(1.0f,1.0f,1.0f,1.0f);
				poWSMesh->VCs[cI*4+1].V4(1.0f,1.0f,1.0f,1.0f);
				poWSMesh->VCs[cI*4+2].V4(1.0f,1.0f,1.0f,1.0f);
				poWSMesh->VCs[cI*4+3].V4(1.0f,1.0f,1.0f,1.0f);
			}

			// WS Shader
			poShader = CE3D_ShaderWH::poCreateShader("base/gamemodes/arcade/weapsel.tga");
			poShInst = mNew CE3D_ShIns_BlendOp;
			poShInst->SeteBOpType(eSIBOp_Alpha);
			poShader->PushInstruction(poShInst);

			// WS Leaf node
			CObject3D_Leaf *poLeaf = mNew CObject3D_Leaf;
			poLeaf->SetMesh  (poWSMesh);
			poLeaf->SetShader(poShader);
			poLeaf->ComputeBoundVol();

			// Set energy bar frame position and size
			goHUD.AddObject(poLeaf,fWSelCX ,fWSelCY ,fWSelTX ,fWSelTY );

		// ------------------------
		// Create selected primary weapon icon and label
		// ------------------------
			
			char *poWeapIconFileName[9] =
			{
				"base/gamemodes/arcade/ic_blaster.tga",
				"base/gamemodes/arcade/ic_laser.tga",
				"base/gamemodes/arcade/ic_hblaster.tga",
				"base/gamemodes/arcade/ic_chaingun.tga",
				"base/gamemodes/arcade/ic_railgun.tga",
				"base/gamemodes/arcade/ic_BFG.tga",
				"base/gamemodes/arcade/ic_homming.tga",
				"base/gamemodes/arcade/ic_napalm.tga",				
				"base/gamemodes/arcade/ic_concussion.tga"
			};

			// Shaders
			for (cI=0;cI<9;cI++)
			{
				poShInst = mNew CE3D_ShIns_BlendOp;
				poShInst->SeteBOpType(eSIBOp_Alpha);
			
				poWeapIcon[cI] = CE3D_ShaderWH::poCreateShader( poWeapIconFileName[cI] );
				poWeapIcon[cI]->PushInstruction(poShInst);
			}

			poPWIcon = mNew CHUDIcon;
			poPWIcon->SetIcon(poWeapIcon[0]);
			
			poSWIcon = mNew CHUDIcon;
			poSWIcon->SetIcon(poWeapIcon[6]);

			TFColor oAmmoColor ={0.0f,1.0f,0.0f,1.0f};

			poAmmoFontShader = CE3D_ShaderWH::poCreateShader("base/textures/fonts/AmmoFont2.tga");
			poShInst = mNew CE3D_ShIns_BlendOp;
			poShInst->SeteBOpType(eSIBOp_Alpha);
			poAmmoFontShader->PushInstruction(poShInst);

			poPWLabel = mNew CHUDLabel;
			poPWLabel->SetFont (poAmmoFontShader);
			poPWLabel->SetColor(oAmmoColor);

			poSWLabel = mNew CHUDLabel;
			poSWLabel->SetFont(poAmmoFontShader);
			poSWLabel->SetColor(oAmmoColor);


			// Set weap selection icon position and size
			goHUD.AddObject(poPWIcon,fPWIconCX,fPWIconCY,fPWIconTX,fPWIconTY);
			goHUD.AddObject(poSWIcon,fSWIconCX,fSWIconCY,fSWIconTX,fSWIconTY);

			goHUD.AddObject(poPWLabel,fPAmmoCX,fPAmmoCY,3*fAmmoFontSize,fAmmoFontSize);
			goHUD.AddObject(poSWLabel,fSAmmoCX,fSAmmoCY,3*fAmmoFontSize,fAmmoFontSize);
}
// --------------------------------------------------------------
void CGMArcade::UpdateMiniMapCell(int _iCellX,int _iCellY,TFColor _oColor)
{
	int cI,cJ,iIniX,iIniY,iEndX,iEndY,iCell;

	if (_iCellX>0) iIniX = _iCellX-1; else iIniX = _iCellX;
	if (_iCellX<goTL.HF->iGetSecsPerRow()-1) iEndX = _iCellX+1; else iEndX= goTL.HF->iGetSecsPerRow()-1;

	if (_iCellY>0) iIniY = _iCellY-1; else iIniY = _iCellY;
	if (_iCellY<goTL.HF->iGetSecsPerCol()-1) iEndY = _iCellY+1; else iEndY = goTL.HF->iGetSecsPerCol()-1;

	for (cJ=iIniY;cJ<iEndY;cJ++)
		for (cI=iIniX;cI<iEndX;cI++)		
		{
			iCell = cJ*goTL.HF->iGetSecsPerRow() + cI;

			poMiniMapMesh->VCs[iCell*4+0].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
			poMiniMapMesh->VCs[iCell*4+1].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
			poMiniMapMesh->VCs[iCell*4+2].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
			poMiniMapMesh->VCs[iCell*4+3].V4(_oColor.r,_oColor.g,_oColor.b,_oColor.a);
		}
}


int iOldXSect,iOldYSect,iOldSect = -1;

void CGMArcade::UpdateMiniMap()
{
	// Get sector		
	int		iSect,iXSect,iYSect;
	
	iSect = CTRNUtils::iGetSector(gpoPlayer->poTransf->roPos(),iXSect,iYSect);
	pbVisitedSecs[iSect] = true;

	if (iSect != iOldSect)
	{
		if (iOldSect != -1)
		{
			TFColor oColor = {1.0f,1.0f,1.0f,0.95f};
			UpdateMiniMapCell(iOldXSect,iOldYSect,oColor);
		}	
	}
	
	TFColor oCurColor = {1.0f,0.0f,0.25f,1.0f};
	UpdateMiniMapCell(iXSect,iYSect,oCurColor);

	iOldSect  = iSect;
	iOldXSect = iXSect;
	iOldYSect = iYSect;
}
// --------------------------------------------------------------
void CGMArcade::UpdateEnergyBars()
{
	float fEn = gpoPlayer->fEnergy;
	float fSh = gpoPlayer->fShield;

	// ----------------------------------
	// We only modify the right side rect
	// ----------------------------------

	// EnergyBar
	poEnergyBarMesh->VXs[2].V3(fEn ,fEBarWidth	,0.0f);
	poEnergyBarMesh->VXs[3].V3(fEn ,0.0f		,0.0f);
	
	poEnergyBarMesh->VCs[2].V4(1.0f,fEn ,0.0f,1.0f);	
	poEnergyBarMesh->VCs[3].V4(1.0f,fEn ,0.0f,1.0f);

	// ShieldBar
	poEnergyBarMesh->VXs[6].V3(fSh,1.0f	,0.0f);
	poEnergyBarMesh->VXs[7].V3(fSh,fSBarOfs,0.0f);

	poEnergyBarMesh->VCs[6].V4(0.0f,fSh ,1.0f - fSh,1.0f);
	poEnergyBarMesh->VCs[7].V4(0.0f,fSh ,1.0f - fSh,1.0f);	
}
// --------------------------------------------------------------
void CGMArcade::UpdateScore()
{
	char szScore[16];
	sprintf(szScore,"%d        ",gpoPlayer->iScore);	szScore[8] = 0;
	poScore->SetText(szScore);
}
// --------------------------------------------------------------
void CGMArcade::SetOption(int _iOpt,bool _bDisabled,bool _bSelected)
{
	CVect4 *poVC = poWSMesh->VCs + 4*_iOpt;
	
	static TFColor oDS = {0.4f ,0.4f ,0.0f ,1.0f };
	static TFColor oES = {1.0f ,1.0f ,0.0f ,1.0f };
	static TFColor oDN = {0.4f ,0.4f ,0.4f ,1.0f };
	static TFColor oEN = {1.0f ,1.0f ,1.0f ,1.0f };
	
	#define SetOptionColor(C)\
		poVC[0].V4(C.r,C.g,C.b,C.a);\
		poVC[1].V4(C.r,C.g,C.b,C.a);\
		poVC[2].V4(C.r,C.g,C.b,C.a);\
		poVC[3].V4(C.r,C.g,C.b,C.a);\

		if (_bDisabled)
		{
			if (_bSelected)
			{
				SetOptionColor(oDS);
			}
			else
			{
				SetOptionColor(oDN);
			}
		}
		else
		{
			if (_bSelected)
			{
				SetOptionColor(oES);
			}
			else
			{
				SetOptionColor(oEN);
			}
		}

	#undef SetOptionColor
}
// --------------------------------------------------------------
void CGMArcade::UpdateWeaponSelector()
{
	// Ammo for laser and hyperblaster
	SetOption(0,
		(gpoPlayer->sAmmo[1]<0) &&
		(gpoPlayer->sAmmo[2]<0),
		(gpoPlayer->iOpt==0));

	// Ammo for homming, napalm, concussion
	SetOption(1,
		(gpoPlayer->sAmmo[6]<0) &&
		(gpoPlayer->sAmmo[7]<0) &&
		(gpoPlayer->sAmmo[8]<0),
		(gpoPlayer->iOpt==1));	

	// ammo for chaingun
	SetOption(2,
		(gpoPlayer->sAmmo[3]<0),
		(gpoPlayer->iOpt==2));

	// ammo for Rail & BFG
	SetOption(3,
		(gpoPlayer->sAmmo[4]<0) &&
		(gpoPlayer->sAmmo[5]<0),
		(gpoPlayer->iOpt==3));

	// Ammo pack
	SetOption(4,
		(gpoPlayer->sAmmo[1]<0) &&
		(gpoPlayer->sAmmo[2]<0) &&
		(gpoPlayer->sAmmo[3]<0) &&
		(gpoPlayer->sAmmo[4]<0) &&
		(gpoPlayer->sAmmo[5]<0) &&
		(gpoPlayer->sAmmo[6]<0) &&
		(gpoPlayer->sAmmo[7]<0) &&
		(gpoPlayer->sAmmo[8]<0),
		(gpoPlayer->iOpt==4));
}
// --------------------------------------------------------------
void CGMArcade::UpdateSelectedWeapons()
{
	// ----------------
	// Primary weapon
	// ----------------
		// Update weapon icon
		poPWIcon->SetIcon( poWeapIcon[gpoPlayer->iPWIdx] );	

		char szStr[16];
		
		// Update ammo label
		if (gpoPlayer->sAmmo[gpoPlayer->iPWIdx] == -1)
			sprintf(szStr,"?  ");	
		else	
			sprintf(szStr,"%d  ",gpoPlayer->sAmmo[gpoPlayer->iPWIdx]);
		szStr[4] = 0;

		poPWLabel->SetText(szStr);
	
	// ----------------
	// Secondary weapon
	// ----------------
		if (gpoPlayer->iSWIdx == -1) 
		{
			poSWIcon->Disable();
			return;
		}
		else
			poSWIcon->Enable();

		// Update weapon icon
		poSWIcon->SetIcon( poWeapIcon[gpoPlayer->iSWIdx] );

		// Update ammo labels
		if (gpoPlayer->sAmmo[gpoPlayer->iSWIdx] == -1)
			sprintf(szStr,"?  ");
		else
			sprintf(szStr,"%d"  ,gpoPlayer->sAmmo[gpoPlayer->iSWIdx]);
		szStr[4] = 0;

		poSWLabel->SetText(szStr);
}
// --------------------------------------------------------------
void CGMArcade::UpdateHUD()
{
	UpdateMiniMap();
	UpdateEnergyBars();

	UpdateScore();
	UpdateWeaponSelector();
	UpdateSelectedWeapons();
}
// --------------------------------------------------------------
void CGMArcade::Loop()
{
	UpdateHUD();
	oSpawner.Loop();
}
// --------------------------------------------------------------