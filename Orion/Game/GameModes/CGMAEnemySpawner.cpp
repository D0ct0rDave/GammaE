// --------------------------------------------------------------
#include "CGMAEnemySpawner.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Collision/CTRNUtils.h"
#include "Game/Entities/Enemies/CShPersecutor.h"
#include "Game/Entities/Enemies/CShRoller.h"
#include "Game/Entities/Enemies/CShSkipper.h"

// --------------------------------------------------------------
#define		INTERSHIP_DISTANCE	5.0f
#define		SAFETIME			5.0f
// --------------------------------------------------------------
CGMAEnemySpawner::CGMAEnemySpawner()
{
	fGameTime = 0.0f;
}
// --------------------------------------------------------------
CGMAEnemySpawner::~CGMAEnemySpawner()
{
}
// --------------------------------------------------------------			
void CGMAEnemySpawner::Spawn(TEnemySpawnInfo &_roSpawnInfo)
{
	COrionEnt *poTarget = gpoPlayer;
	/*
	for (int i=0;i<0;i++)
	{
		oCenter.V3( MATH_Common::fRand()*fTerrainWidth,
					MATH_Common::fRand()*fTerrainHeight,
					100.0f + MATH_Common::fRand()*150.0f);

		CSh25 *poSh = mNew CSh25;		
		poSh->Setup(OETI_ENEMY_SHIP25,1,oCenter);
	
		goWorldEnt.poEnt.iAdd( poSh );
	}
	*/
	CVect3 oNewDir;
	CVect3 oNewSide;
	CVect3 oNewUp;

	CVect3 oCenter;

	
	
	for (int cI=0;cI<_roSpawnInfo.iNumSpawns;cI++)
	{
		CVect3	oCenter;
		CShip	*poSh;

		// Get ship position
		oCenter.LineEq( poTarget->poTransf->roPos(),poTarget->poTransf->roDir(),_roSpawnInfo.fSpawnDist);
		// oCenter.SetZ  ( poTarget->poTransf->roPos().Z() );

		// Setup enemy type
		switch(_roSpawnInfo.iEnemyType)
		{
			case 0:	poSh   = mNew CShPersecutor;	break;
			case 1:	poSh   = mNew CShRoller;		break;
			case 2:	poSh   = mNew CShSkipper;		break;
		}

		switch (_roSpawnInfo.iSpawnType)
		{
			case 0:	// Vertical			
			oCenter.LineEq( oCenter,poTarget->poTransf->roUp(),-cI*INTERSHIP_DISTANCE);
			break;

			case 1:	// Horizontal
			oCenter.LineEq( oCenter,poTarget->poTransf->roSide(),-cI*INTERSHIP_DISTANCE);
			break;

			case 2:	// Deep
			oCenter.LineEq( oCenter,poTarget->poTransf->roDir(),-cI*INTERSHIP_DISTANCE);
			break;

			case 3:	// Circle
			float	fAngle;
			CVect3	oCent;

			fAngle = ((float)cI/_roSpawnInfo.iNumSpawns)*_2PI_;
			oCent.LineEq( oCenter,poTarget->poTransf->roSide(),1.0f);
			oCent.Sub   (oCenter);
			
			oCenter.Scale(-1.0f);
			CMatrix4x4 oMat;
			oMat.LoadIdentity();	
			oMat.RotateAxis('z',fAngle);
			oCent.V3(0.0f,0.0f,2.0f);
			oMat.TransformPoint(oCent);

			// Sistema de coordenadas del target
			poTarget->poTransf->roTransf().TransformPoint(oCent);

			CVect3 oOffset;
			oOffset.Assign(poTarget->poTransf->roPos());
			oOffset.Sub   (oCent);

			oCenter.Add(oOffset);			
			break;
		}

		// Correct ship height
		float fMinHeight = CTRNUtils::fGetHeight(oCenter) + 2.0f;
		if (oCenter.Z() < fMinHeight) oCenter.SetZ( fMinHeight );

		// Compute ship axis
		oNewDir.Assign(poTarget->poTransf->roPos());
		oNewDir.Sub   (oCenter );
		oNewDir.Normalize();

		oNewUp.V3(0.0f,0.0f,1.0f);
		oNewSide.CrossProd(oNewDir,oNewUp  );
		oNewUp.CrossProd  (oNewDir,oNewSide);

		// Setup ship spawn properties		
		poSh->oCol.oPos.Assign(oCenter);
		poSh->oCol.oOldPos.Assign(oCenter);
		poSh->poTransf->SetPos (oCenter);
		poSh->poTransf->SetDir (oNewDir  );
		poSh->poTransf->SetSide(oNewSide );
		poSh->poTransf->SetUp  (oNewUp   );

		goWorldEntList.poEnt.iAdd( poSh );
	}
}
// --------------------------------------------------------------
void CGMAEnemySpawner::Loop()
{
	// <WARNING: Debug code>
	// return;

	fGameTime += gfDeltaT;
	if (fGameTime < SAFETIME)	return;

	for (int cI=0;cI<CMapCFG::oESpawnInfo.iNumElems();cI++)
	{
		TEnemySpawnInfo *poInfo = &CMapCFG::oESpawnInfo[cI];

		if (poInfo->fCurSpawnTime == 0.0f)
		{
			Spawn(*poInfo);

			// <WARNING: DEBUG CODE>
			// CMapCFG::oESpawnInfo[cI].fSpawnTime = 1e6f;
		}

		poInfo->fCurSpawnTime += gfDeltaT;

		if (poInfo->fCurSpawnTime >= poInfo->fSpawnTime)
			poInfo->fCurSpawnTime = 0.0f;
	}
}
// --------------------------------------------------------------