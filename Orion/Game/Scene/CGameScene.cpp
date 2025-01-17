//## begin module%3B65CB11028A.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3B65CB11028A.cm

//## begin module%3B65CB11028A.cp preserve=no
//## end module%3B65CB11028A.cp

//## Module: CGameScene%3B65CB11028A; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameScene\CGameScene.cpp

//## begin module%3B65CB11028A.additionalIncludes preserve=no
//## end module%3B65CB11028A.additionalIncludes

//## begin module%3B65CB11028A.includes preserve=yes
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Scene/Models/COrionObjBookmark.h"
#include "Game/Scene/CFlareMgr.h"
#include "Game/Scene/CPSysMgr.h"

#include "Game/Entities/Projectile/CProjectile.h"

#include "Game/Collision/CTRNUtils.h"

#include "Game/Scene/SFX/TRN/CTRNNeighs.h"
#include "Game/Scene/SFX/CTRNShadow.h"

#define		SCNSFX_PSYS_SNOWFALLING		0
#define		SCNSFX_PSYS_EXPLOSION		1
#define		SCNSFX_PSYS_DAMAGE			2
#define		SCNSFX_PSYS_NUCLEARFIRE		3
#define		SCNSFX_PSYS_REACTOR			4
#define		SCNSFX_PSYS_RAINHARD		5
#define		SCNSFX_PSYS_RAINSOFT		6
//## end module%3B65CB11028A.includes

// CGameScene
#include "CGameScene.h"

// for map picture screenshots
// #define	TAKE_MAPPICS

//## begin module%3B65CB11028A.additionalDeclarations preserve=yes
//## end module%3B65CB11028A.additionalDeclarations


// Class CGameScene 




CGameScene::CGameScene()
  //## begin CGameScene::CGameScene%.hasinit preserve=no
  //## end CGameScene::CGameScene%.hasinit
  //## begin CGameScene::CGameScene%.initialization preserve=yes
  //## end CGameScene::CGameScene%.initialization
{
  //## begin CGameScene::CGameScene%.body preserve=yes  	
	//## end CGameScene::CGameScene%.body
}


CGameScene::~CGameScene()
{
  //## begin CGameScene::~CGameScene%.body preserve=yes
  //## end CGameScene::~CGameScene%.body
}


/**************************************************************************
	Add simple particle system
**************************************************************************/
void AddParticleSystem(int _iType,COrionEnt *_poParent,CVect3 &_roPos,CVect3 &_roDir)
{
	// Add the particle system to the manager
	CPSysMgr::AddPSys(_iType,(void*)_poParent,0,_roPos,_roDir);
}

/**************************************************************************
	Add simple flare
**************************************************************************/
void AddFlare(int _iType,COrionEnt *_poParent,CVect3 &_roPos,CVect3 &_roDir)
{
	// Add the flare to the manager
	CFlareMgr::AddFlare(_iType,(void*)_poParent,0,_roPos,_roDir,2.5f);
}

/**************************************************************************
	Add control point effects
**************************************************************************/
void AddControlPointSFX(TOrionObj *_poObj,COrionEnt *_poParent)
{
	TControlPoint	*poCP;
	CVect3			oWorldFPos,oWorldFDir;

	for (int iCP=0;iCP<_poObj->oCPs.iNumElems();iCP++)
	{
		poCP = &_poObj->oCPs[iCP];

		// Flares
		switch (poCP->ucCPType)
		{
			// Reactor flares
			case 0:
			{
				// Get Flare World Pos
				oWorldFPos.Assign(poCP->oPos);
				_poParent->poTransf->roTransf().TransformPoint(oWorldFPos);
				
				// Get Flare World Dir
				oWorldFDir.Assign(_poParent->poTransf->roDir());
				if (poCP->ucDir) oWorldFDir.Scale(-1.0f);	// Back dir		

				// Add the flare to the manager
				float fFlareSize = 2.5f + MATH_Common::fRand()*0.125f;

				if (_poParent == gpoPlayer)
					fFlareSize += gpoPlayer->fSpeed/50.0f - 1.5f;

				CFlareMgr::AddFlare(poCP->ucSubType,(void*)_poParent,iCP,oWorldFPos,oWorldFDir,fFlareSize);

				
				// Particle systems
				if (poCP->ucSubType==0)
				{
					// Get PSys World Pos
					oWorldFPos.Assign(poCP->oPos);
					_poParent->poTransf->roTransf().TransformPoint(oWorldFPos);
			
					// Get World Speed
					oWorldFDir.Assign(_poParent->poTransf->roDir());
					if (poCP->ucDir) oWorldFDir.Scale(-1.0f);	// Back dir		

					// Add the particle system to the manager
					CPSysMgr::AddPSys(SCNSFX_PSYS_REACTOR,(void*)_poParent,iCP,oWorldFPos,oWorldFDir);
				}
			}
			break;
			
			case 1:
			{
				// Get Flare World Pos
				oWorldFPos.Assign(poCP->oPos);
				_poParent->poTransf->roTransf().TransformPoint(oWorldFPos);
				
				// Get Flare World Dir
				oWorldFDir.Assign(_poParent->poTransf->roDir());
				if (poCP->ucDir==1) oWorldFDir.Scale(-1.0f);	// Back dir		

				// Add the flare to the manager
				CFlareMgr::AddFlare(poCP->ucSubType,(void*)_poParent,iCP,oWorldFPos,oWorldFDir,2.5f);
			}
			break;
			
			case 2:
			{
				// Get Flare World Pos
				oWorldFPos.Assign(poCP->oPos);
				_poParent->poTransf->roTransf().TransformPoint(oWorldFPos);

				// always face the camera
				oWorldFDir.Assign(goCamera.poGetCamera()->Dir);

				// Add the flare to the manager
				float fSizeMult;

				if (poCP->ucSubType == 12)
					fSizeMult = 4.0f*MATH_Common::fRand();
				else
					fSizeMult = 1.0f;
				
				CFlareMgr::AddFlare(poCP->ucSubType,
								    (void*)_poParent,
									iCP,
									oWorldFPos,
									oWorldFDir,	
									fSizeMult * 4.0f);
			}
			break;
		}
	}
}

/**************************************************************************
	Preprocess objects for further rendering
**************************************************************************/
void CGameScene::PreRender()
{
	// Recorrer la lista de naves y separar geometría, sistemas de partículas, flares, etc...

	// ------------------------------------------------------------------------------
	// BEGIN: FLARES & PSYS
	// ------------------------------------------------------------------------------
	CVect3		oDir;
	int			iModelIdx;
	TOrionObj	*poObj;

	// Add ship flares and particle systems	
	COrionEnt*	*poEnt;
	for (int iElem=0;iElem<goWorldEntList.poEnt.iMaxElems();iElem++)
	{
		poEnt = goWorldEntList.poEnt.poElem(iElem);

		if (poEnt)
		{
			// If this entity is not active...
			if (! (*poEnt)->bActive) continue;

			switch ((*poEnt)->iEntTypeID)
			{
				#ifndef TAKE_MAPPICS

				case OETI_PROJECTILE:
				case OETI_ENEMY:
				case OETI_PLAYER:
				{
					oDir.Assign((*poEnt)->poTransf->roDir());
					oDir.Scale(-1.0f);					// Reverse direction

					switch ((*poEnt)->eState)
					{
						case OOST_ALIVE:
						{
							iModelIdx = (*poEnt)->iModelIdx;
							poObj     = COrionObjBookmark::gObjBookmark[iModelIdx];
							
							// Add ship control points
							AddControlPointSFX(poObj,*poEnt);
					
							if (
								((*poEnt)->iEntTypeID == OETI_ENEMY) ||
								((*poEnt)->iEntTypeID == OETI_PLAYER)
								)
							{
								CShip *poShip = (CShip*)*poEnt;

								if ( poShip->fEnergy < 0.5f )
									AddParticleSystem(SCNSFX_PSYS_DAMAGE,poShip,poShip->oCol.oPos,oDir);
							}
						}
						break;

						case OOST_EXPLODING:
						{			
							// En funcion del tipo de nave, unos efectos u otros
							AddParticleSystem(SCNSFX_PSYS_EXPLOSION,*poEnt,(*poEnt)->oCol.oPos,oDir);
						}
						break;
					}									
				}
				break;
				#endif

				case OETI_WORLD:
					iModelIdx = (*poEnt)->iModelIdx;
					poObj     = COrionObjBookmark::gObjBookmark[iModelIdx];
						
					// Add ship control points
					AddControlPointSFX(poObj,*poEnt);
				break;

			} // End of switch
		}	// End if poEnt
	}	// End for iEnt
	// ------------------------------------------------------------------------------
	// END: FLARES & PSYS
	// ------------------------------------------------------------------------------

}


//## Other Operations (implementation)
void CGameScene::Render ()
{
  //## begin CGameScene::Render%997655866.body preserve=yes
	PreRender();

	CTRNShadow::Setup(gpoPlayerNode);
	
	gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);
	gpoE3DRenderer->BeginRender();
		
		// Camera viewpoint
		goCamera.PreRender();

			RenderBackground();

			// Render terrain
			goRenderer.EnableFrustumCulling();
				gpoTerrain->Render();
			goRenderer.DisableFrustumCulling();

			// Render shadow
			goRenderer.DisableFrustumCulling();
			gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);	

			if (gpoPlayer->eState == OOST_ALIVE)	// Only if player is alive
				CTRNShadow::Render();

				// gpoWorldLimit->Render();

				goRenderer.EnableFrustumCulling();
				gpoE3DRenderer->SetZPars(eE3D_ZTF_LEqual,eE3D_ZW_Enable);		

				RenderShips();

				// Render dynamic objects
				// goDynObjs.Render();

			goRenderer.DisableFrustumCulling();
		
			// RenderProjectiles();
			
			RenderEvFX();
			
			// Flare manager
			CFlareMgr::Render();
			
			// Particle system manager
			CPSysMgr::Render();
		
		goCamera.PostRender();
		
		// Render HUD
		goHUDMgr.Render();

		gpoE3DRenderer->SetZPars(eE3D_ZTF_None,eE3D_ZW_Disable);
		goHUDCam.Render();
		gpoE3DRenderer->SetZPars(eE3D_ZTF_Last,eE3D_ZW_Last);

				

	gpoE3DRenderer->EndRender();
  //## end CGameScene::Render%997655866.body
}

// Additional Declarations
  //## begin CGameScene%3B65CB11028A.declarations preserve=yes
void CGameScene::RenderBackground()
{
	CVect3	oNewPos;
	oNewPos.Assign(goCamera.poGetCamera()->Pos);
	oNewPos.SetZ( 0.0f );

	gpoBackground->SetPos( oNewPos );
	gpoBackground->Render();
}
// ------------------------------------------------------------------------------
void CGameScene::RenderProjectiles()
{
/*
	COrionEnt*	*poEnt;
	CProjectile	*poPrj;

	for (int iPrj=0;iPrj<goWorldEntList.poEnt.iMaxElems();iPrj++)
	{
		poEnt = goWorldEntList.poEnt.poElem(iPrj);

		if (poEnt)
		{
			if ((*poEnt)->iEntTypeID == OETI_PROJECTILE)
			{
				CProjectile *poPrj;
				poPrj = (CProjectile*)*poEnt;

				if (poPrj->eState == PROJSTATE_ALIVE)
					poPrj->poTransf->Render();
			}
		}
	}
*/
}
// ------------------------------------------------------------------------------
void CGameScene::RenderShips()
{	
	CE3D_Light	oLight;

	extern CVect3		oSunDir;
	extern CVect3		oSunPos;

	// Setup light properties
	oLight.oLitAmb.r = goTL.EnvPars.fLightAmbColor[0];
	oLight.oLitAmb.g = goTL.EnvPars.fLightAmbColor[1];
	oLight.oLitAmb.b = goTL.EnvPars.fLightAmbColor[2];
	oLight.oLitAmb.a = 1.0f;

	oLight.oLitDiff.r = goTL.EnvPars.fLightDiffColor[0];
	oLight.oLitDiff.g = goTL.EnvPars.fLightDiffColor[1];
	oLight.oLitDiff.b = goTL.EnvPars.fLightDiffColor[2];
	oLight.oLitDiff.a = 1.0f;

	oLight.eType    = LT_Directional;
	oLight.oPos.Assign(oSunPos);
	oLight.oDir.Assign(oSunDir);

	gpoE3DRenderer->SetupLight(0,oLight);
	gpoE3DRenderer->SetLight(0,true);

	gpoE3DRenderer->EnableDefferredMode();

		for (int iPrj=0;iPrj<goWorldEntList.poEnt.iMaxElems();iPrj++)
		{			
			COrionEnt*	*poEnt;
			poEnt = goWorldEntList.poEnt.poElem(iPrj);

			if (!  poEnt)							continue;
			if (! *poEnt)							continue;
			if ((*poEnt)->eState != OOST_ALIVE)		continue;
			
			#ifdef TAKE_MAPPICS
			if ((*poEnt)->iEntTypeID != OETI_WORLD) continue; 
			#endif
	
			if (
				((*poEnt)->iEntTypeID == OETI_PROJECTILE) ||
				((*poEnt)->iEntTypeID == OETI_WORLD)
			   )
			{
				gpoE3DRenderer->SetLight(0,false);
			}
			else
				gpoE3DRenderer->SetLight(0,true);

			(*poEnt)->poTransf->Render();
		}

	gpoE3DRenderer->SetLight(0,false);
	gpoE3DRenderer->DisableDefferredMode();
}
// ------------------------------------------------------------------------------
void CGameScene::RenderEvFX()
{
	// <WARNING: Debug code>
	// return;

	CVect3 oPos(0.0f,0.0f,0.0f);
	CVect3 oDir(0.0f,0.0f,1.0f);


	switch (goTL.EnvPars.iEnvType)
	{
		case 1:	// soft rain
		case 2:	// hard rain
				// Add the particle system to the manager				
				oPos.Assign( goCamera.poGetCamera()->Pos );
				oPos.SetZ(oPos.Z() + 400.0f);
				CPSysMgr::AddPSys(SCNSFX_PSYS_RAINHARD,(void*)&goTL,0,oPos,oDir);
				break;

		case 3: // soft snow
		case 4: // hard snow

				// Add the particle system to the manager				
				oPos.Assign( goCamera.poGetCamera()->Pos );
				oPos.SetZ(oPos.Z() + 400.0f);
				CPSysMgr::AddPSys(SCNSFX_PSYS_SNOWFALLING,(void*)&goTL,0,oPos,oDir);
				break;
		case 5:	// Lens flare
				if (gpoLensFlare)
				{
					goRenderer.SetFogPars(eE3D_FM_None,0,0,0,NULL);
						gpoLensFlare->Render();
					goRenderer.SetFogPars(eE3D_FM_Last,0,0,0,NULL);		
				}
				break;
		default:
				break;
	}
}
// ------------------------------------------------------------------------------
  //## end CGameScene%3B65CB11028A.declarations

//## begin module%3B65CB11028A.epilog preserve=yes
//## end module%3B65CB11028A.epilog

