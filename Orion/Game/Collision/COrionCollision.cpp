#include "COrionCollision.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Entities/CShip.h"
#include "Game/Entities/Projectile/CProjectile.h"
#include "CTRNUtils.h"

#include "GammaE.h"

CCOL_MT_CommonMesh		COrionCOL::oStMeshTest;
CCOL_TriList			COrionCOL::oColTriList;

/********************************************************************

********************************************************************/
COrionCOL::COrionCOL()
{
	
}

COrionCOL::~COrionCOL()
{

}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObjTRN_Broad(COrionEnt *_poCol)
{
	int			cI,cJ,iIX,iIY,iFX,iFY,iSector;	

	CTRNUtils::iGetSector(_poCol->oCol.oOldPos,iIX,iIY);
	CTRNUtils::iGetSector(_poCol->oCol.oPos   ,iFX,iFY);
	CGraphBV	*poSectBVol;

	// Setup initial and final positions
	CCOL_ColState::SrcFPos.Assign(_poCol->oCol.oPos);
	CCOL_ColState::SrcIPos.Assign(_poCol->oCol.oOldPos);
	CCOL_ColState::DstFPos.V3(0.0f,0.0f,0.0f);
	CCOL_ColState::DstIPos.V3(0.0f,0.0f,0.0f);

	for (cJ=iIY;cJ<=iFY;cJ++)
		for (cI=iIX;cI<=iFX;cI++)
		{
			// Test against the terrain sector bounding boxes
			iSector		= cJ*goTL.HF->iGetSecsPerRow() + cI;
			poSectBVol	= gpoTerrain->poGetObject(iSector)->poGetBoundVol();

			if (CCOL_DT_ColTester::fTestCollision( _poCol->oCol.poBV,poSectBVol) >= 0.0f)
			{
				return(true);
			}
		}
		
	return(false);
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObjTRN_Fine (COrionEnt *_poCol)
{
	// Recorrido de Bresenham
	// Convertir coordinadas SrcIPos, SrcFPos a coordenadas de terreno
	// Trazar el recorrido del objeto sobre el terreno, pixel a pixel.
	
	// Para cada coordenada (bresenhan line) obtener el par de triángulos apropiado
	// y testear colision del objeto con ese par de triángulos.
	
	// si no hay colision, continuar trazando hasta llegar al límite. 

	// (limite de sector si puede ser).
	int			iIX,iIY,iFX,iFY,iXRange,iYRange,iSteps,iS;
	float		fXStep,fYStep,fZStep,fActX,fActY,fActZ,fCurZ;
	float		fHeight,fHalfZObj;	
	float		fColTime;
	float		fRatio  = goTL.fSectorSize / (float)goTL.iSectorRes;
	int			iTWidth = goTL.HF->iGetSecsPerRow()*goTL.fSectorSize;
	int			iTHeight= goTL.HF->iGetSecsPerCol()*goTL.fSectorSize;

	CVect3		oStep,oColPos;

	oStep.Assign(CCOL_ColState::SrcFPos);
	oStep.Sub   (CCOL_ColState::SrcIPos);
	
	if (oStep.X() > oStep.Y()) 
		iSteps = (oStep.X() / fRatio) +1;
	else
		iSteps = (oStep.Y() / fRatio) +1;
	
	// Loop throught all the traversed triangles
	oColPos.Assign(CCOL_ColState::SrcIPos);

	oStep.Scale( 1.0f / (float)iSteps);

	for (iS=0;iS<iSteps;iS++)
	{
		if (MATH_Common::bInRange(oColPos.X(),0,iTWidth ) && MATH_Common::bInRange(oColPos.Y(),0,iTHeight))
		{
			// Get height at position
			fCurZ = CTRNUtils::fGetHeight(oColPos);

			if (fCurZ +1.0f > oColPos.Z())
			{
				CCOL_ColState::fDeltaT = (float)iS*(gfDeltaT / (float)iSteps);
				return(true);
			}									
		}
		
		oColPos.Add(oStep);
	}

	_poCol->poInflictor = NULL;
	return (false);

/*
	CVect3	oDiff;
	CVect3	oCur;
	CVect3  oStep;
	float   fDist;
	float	fDiameter;
	int		iSteps;

	oDiff.Assign(poCol->oPos);
	oDiff.Sub   (poCol->oOldPos);

	fDist   = MATH_Common::fSqrt(oDiff.X()*oDiff.X() + oDiff.Y()*oDiff.Y());
	fDiameter = poCol->poBV->GetRange(0);

	iSteps = (fDist / fDiameter) + 1;

	oStep.Assign(oDiff);
	oStep.Scale(1.0f / iSteps);

	// Traverse distance with spheres
	oTriList.Reset();
	
	oCur.Assign(oStep);
	oCur.Scale (0.5f);
	oCur.Add   (poCol->oOldPos); // Posicion inicial = desplazar el circulo
								 // para que toque con la punta la primera 
								 // posicion

	while ( (oCur.X() != poCol->oPos.X()) && (oCur.Y() != poCol->oPos.Y()) )
	{
		goTRNTriListGen.GetTrisFromMesh(oTriList,NULL,0,oCur,fRadius);
		oCur.Add(oStep);
	}
*/
	// Testear colision contra los triangulos del terreno.
	return(false);
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObjST_Broad (COrionEnt *_poCol)
{
	// Setup initial and final positions
	CCOL_ColState::SrcFPos.Assign(_poCol->oCol.oPos);
	CCOL_ColState::SrcIPos.Assign(_poCol->oCol.oOldPos);
	CCOL_ColState::DstFPos.V3(0.0f,0.0f,0.0f);
	CCOL_ColState::DstIPos.V3(0.0f,0.0f,0.0f);

	CCOL_Scn_ColTester::SGrObj = _poCol->poTransf;
	CCOL_Scn_ColTester::DGrObj = gpoStWorld;	

	return( CCOL_Scn_ColTester::iTestObjects() );
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObjST_Fine  (COrionEnt *_poCol)
{
	if (! oColTriList.iMaxTris)
		oColTriList.Init(1000);

	oColTriList.Reset();
	for (int cM=0;cM<CCOL_Scn_ColTester::iNumColMeshes;cM++)
	{
		oStMeshTest.iTestCollision(
			CCOL_Scn_ColTester::ColMeshes[cM].poMesh,
			CCOL_Scn_ColTester::ColMeshes[cM].iMat,
			_poCol->oCol.poBV,oColTriList);
	}
	
	return(oColTriList.iNumTris>0);
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObjObj_Broad(COrionEnt *_poCol,COrionEnt *_poDst)
{
	CCOL_ColState::SrcFPos.Assign(_poCol->oCol.oPos);
	CCOL_ColState::SrcIPos.Assign(_poCol->oCol.oOldPos);
	CCOL_ColState::DstFPos.Assign(_poDst->oCol.oPos);
	CCOL_ColState::DstIPos.Assign(_poDst->oCol.oOldPos);

	return (CCOL_DT_ColTester::fTestCollision( _poCol->oCol.poBV,_poDst->oCol.poBV) >= 0.0f);
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObjObj_Fine (COrionEnt *_poCol,COrionEnt *_poDst)
{
	return(true);
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestObj2Entities(COrionEnt *_poCol)
{	
	COrionEnt*	*poEnt;	

	for (int iEnt=0;iEnt<goWorldEntList.poEnt.iMaxElems();iEnt++)
	{
		poEnt = goWorldEntList.poEnt.poElem(iEnt);

		if (poEnt)
		{
			if ( ! (*poEnt)->bActive )						continue;
			if ( (*poEnt)->eState  != OOST_ALIVE)			continue;	// Avoid checking against dead objects
			if ( (*poEnt) == _poCol)						continue;	// avoid self collision checking
			if ( (*poEnt)->poParent == _poCol)				continue;	// avoid checking against parent
			if ( (*poEnt) == _poCol->poParent)				continue;	// avoid checking against childs
			if ( (*poEnt)->poParent == _poCol->poParent)	continue;	// avoid checking against brothers
			
			// do not test against world (for the moment): this should be done with a finner test
			if ( (*poEnt)->iEntTypeID == OETI_WORLD)		continue;	
	
			if ( bTestObjObj_Broad(_poCol,*poEnt) )
			{
				if (bTestObjObj_Fine(_poCol,*poEnt) )
				{
					_poCol->poInflictor = *poEnt;
					return(true);
				}
			}
		}
	}
}
/********************************************************************

********************************************************************/
bool COrionCOL::bTestCollision(COrionEnt *_poCol)
{
	// Collision priority: Terrain > StaticScene > Entitites

	// Test terrain
	if (bTestObjTRN_Broad(_poCol))
		if (bTestObjTRN_Fine(_poCol)) 
			return(true);
	
	// Test StaticScene
	if (bTestObjST_Broad(_poCol))
		if (bTestObjST_Fine(_poCol))
			return(true);
	
	// Test Entities
	return (bTestObj2Entities(_poCol) );
}
/********************************************************************

********************************************************************/
void COrionCOL::HandlePlayerCollisions(CPlayer *_poPlayer)
{
	if (_poPlayer->eState != OOST_ALIVE) return;

	// Test terrain
	if (bTestObjTRN_Broad(_poPlayer))
		if (bTestObjTRN_Fine(_poPlayer)) 
			// Player received impact from terrain
			_poPlayer->ReceiveImpact(_poPlayer->fSpeed*0.1f,NULL);
	
	// Test StaticScene
	if (bTestObjST_Broad(_poPlayer))
		if (bTestObjST_Fine(_poPlayer))
			// Player received impact from terrain
			_poPlayer->ReceiveImpact(_poPlayer->fSpeed*0.1f,NULL);


	// Test player against other ships
	for (int iEnt=0;iEnt<goWorldEntList.poEnt.iMaxElems();iEnt++)
	{
		COrionEnt* *poEnt = goWorldEntList.poEnt.poElem(iEnt);

		if (! poEnt)									continue;			
		if (! (*poEnt)->bActive)						continue;
		if ( (*poEnt)->eState != OOST_ALIVE)			continue;
		if ( *poEnt == _poPlayer)						continue;
		if (   
				((*poEnt)->iEntTypeID != OETI_ENEMY)	&&
				((*poEnt)->iEntTypeID != OETI_PLAYER)   &&
				((*poEnt)->iEntTypeID != OETI_POWERUP) 
				// Projectiles had been tested before
		   )
			continue;

		if (bTestObjObj_Broad(_poPlayer,*poEnt))
		{
			if (bTestObjObj_Fine(_poPlayer,*poEnt))
			{
				if ((*poEnt)->iEntTypeID == OETI_POWERUP)
				{
					_poPlayer->NotifyTargetCollision(*poEnt);
				}
				else
				{						
					CShip *poShip = (CShip *)(*poEnt);
					float fImpFact = (_poPlayer->fSpeed+poShip->fSpeed)/100.0f;

					// Both, the player and the ship, receive an impact
					_poPlayer->ReceiveImpact(fImpFact,poShip);
					poShip->ReceiveImpact   (fImpFact,_poPlayer);

					
					/*
					// <WARNING: DEBUG CODE>
					_poPlayer->SetShipProps(0,0,0,0,0,1.0f,0.0f);
					poShip   ->SetShipProps(0,0,0,0,0,1.0f,0.0f);
					*/
					if (
						(poShip->eState != OOST_ALIVE) && (_poPlayer->eState == OOST_ALIVE)
					   )
					{
						// if the ship was destroyed and the player survived...
						_poPlayer->NotifyTargetCollision(poShip);	
					}
				}
			}
		}
	}

}
/********************************************************************

********************************************************************/
void COrionCOL::HandleCollisions()
{
	COrionEnt*	*poEnt;	
	CProjectile	*poPrj;
	CShip		*poShip;
	CShip		*poFireStarter;
	int			iEnt;
		
	// ----------------------------
	// Test projectile collisions
	// ----------------------------
	for (iEnt=0;iEnt<goWorldEntList.poEnt.iMaxElems();iEnt++)
	{
		poEnt = goWorldEntList.poEnt.poElem(iEnt);

		if (! poEnt)									continue;
		if (! (*poEnt)->bActive)						continue;
		if (! *poEnt)									continue;
		if (  (*poEnt)->iEntTypeID != OETI_PROJECTILE)	continue;		
		if (  (*poEnt)->eState != OOST_ALIVE)			continue;

		poPrj = (CProjectile*)*poEnt;

		if (bTestCollision(poPrj))
		{
			// si poEnt->poInflictor == NULL
			//		choque contra terreno / escena estatica
			// sino
			//		inflictor es la entidad que ha recibido el choque

			if (poPrj->poInflictor)
			{						
				if (
					(poPrj->poInflictor->iEntTypeID == OETI_ENEMY) ||
					(poPrj->poInflictor->iEntTypeID == OETI_PLAYER)
				   )
				{
					// Notify projectile impact
					CShip *poShip = (CShip *)poPrj->poInflictor;
					poShip->ReceiveImpact(goProjProps[poPrj->iEntSubType].fStrenght,poPrj);

					if (
						(poShip->fEnergy == 0.0f) &&
						((poPrj->poParent->iEntTypeID == OETI_ENEMY) ||
						 (poPrj->poParent->iEntTypeID == OETI_PLAYER))
					   )
					{
						// Notify impact to the parent					
						poFireStarter = (CShip *)poPrj->poParent;
						poFireStarter->NotifyTargetCollision(poShip);
					}
				}
			}

			poPrj->eState = OOST_BEGINEXPLOSION;
		}
	}

	// ----------------------------
	// Check player collisions
	// ----------------------------
	HandlePlayerCollisions(gpoPlayer);

	// ------------------------------------
	// Check enemy ships-terrain collisions	
	// ------------------------------------
	for (iEnt=0;iEnt<goWorldEntList.poEnt.iMaxElems();iEnt++)
	{
		poEnt = goWorldEntList.poEnt.poElem(iEnt);

		if (! poEnt)									continue;
		if (   (*poEnt)->iEntTypeID != OETI_ENEMY)		continue;
		if ( ! (*poEnt)->bActive)						continue;		

		poShip = (CShip *)(*poEnt);

		if (poShip->fEnergy == 0.0f)					continue;


		// Test terrain
		if (bTestObjTRN_Broad(poShip))
			if (bTestObjTRN_Fine(poShip)) 
				// Ship received impact from terrain
				poShip->ReceiveImpact(1.0f,NULL);

		// Test StaticScene
		if (bTestObjST_Broad(poShip))
			if (bTestObjST_Fine(poShip))
				// Ship received impact from terrain
				poShip->ReceiveImpact(1.0f,NULL);
	}
}
/********************************************************************

********************************************************************/