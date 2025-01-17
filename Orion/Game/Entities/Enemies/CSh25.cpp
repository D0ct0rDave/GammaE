#include "Game/Entities/Enemies/CSh25.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Entities/Projectile/CProjectile.h"


#define		DEF_ACCEL		100.0f
#define		DEF_DECCEL	   -300.0f
#define		MAX_SPEED		  1.5f
#define		DEF_DYAW		  1.0f
#define		DEF_DPITCH		  0.5f
#define		INITIAL_ENERGY	100
#define		INITIAL_SHIELD	  0

#define		STATE_ALERT		0
#define		STATE_ATTACK	1

// #define 
CSh25::CSh25()
{	
	SetShipProps(DEF_ACCEL,DEF_DECCEL,MAX_SPEED,DEF_DYAW,DEF_DPITCH,INITIAL_ENERGY,INITIAL_SHIELD);

	fMinHeight =   2.5f;
	fMaxHeight = 150.0f;
	iEntTypeID = OETI_ENEMY;
}

CSh25::~CSh25()
{
}

// -------------------------------------------------------------------------
void CSh25::Think(float _fDelta)
{
	/*
	switch (iState)
	{
		case STATE_ALERT:
		{			
			if (gpoPlayer->oCol.oPos.Distance(oCol.oPos) < 100.0f)
			{
				iState   = STATE_ATTACK;
				poTarget = gpoPlayer;
			}
			else
				NavigateAlert(_fDelta);
		}
		break;

		case STATE_ATTACK:
		{			
			if (gpoPlayer->oCol.oPos.Distance(oCol.oPos) > 150.0f)
			{
				iState   = STATE_ALERT;
				poTarget = NULL;
			}
			else
				NavigateAttacking(_fDelta);
		}
		break;
	}
	*/
	HandleHeight(_fDelta);
}

// -------------------------------------------------------------------------
void CSh25::NavigateAttacking(float _fDelta)
{
	CVect3 oTSVec;		// Target/Self vect
	CVect3 oTSDDiff;	// TSVec - Dir Difference
	
	oTSVec.Assign(gpoPlayer->oCol.oPos);
	oTSVec.Sub(oCol.oPos);
	//oTSVec.Normalize();
	CVect3 oCross; 
	oCross.CrossProd(oTSVec,poTransf->roDir());

	oTSDDiff.Assign(oTSVec);
	oTSDDiff.Sub (poTransf->roDir());


	if (oCross.Z() < 0.0f)
	{
		// Yaw to the right	
		iMFlags |= MFLAG_YR;
	}
else if (oCross.Z() > 0.0f)
	{
		// Yaw to the right	
		iMFlags |= MFLAG_YL;
	}

	if (oTSDDiff.Z() > 0.0f)
	{
		iMFlags |= MFLAG_PU;
	}
else if (oTSDDiff.Z() < 0.0f)
	{
		iMFlags |= MFLAG_PD;
	}
}
// -------------------------------------------------------------------------

void CSh25::NavigateAlert(float _fDelta)
{
	int iSecsPerRow = goTL.HF->iGetSecsPerRow();
	int iSecsPerCol = goTL.HF->iGetSecsPerCol();
	
	int   iXSect,iYSect;	

	iXSect = oCol.oPos.X() / goTL.fSectorSize;
	iYSect = oCol.oPos.Y() / goTL.fSectorSize;
	
	iMFlags = 0;

	if (iXSect<=0)
		iMFlags |= MFLAG_YR;

	if (iXSect>=iSecsPerRow-1)
		iMFlags |= MFLAG_YL;

	if (iYSect<=0)
		iMFlags |= MFLAG_YR;

	if (iYSect>=iSecsPerRow-1)
		iMFlags |= MFLAG_YL;

	iMFlags |= MFLAG_FW;
	
	HandleHeight(_fDelta);
}

// -------------------------------------------------------------------------

void CSh25::Fire ()
{
	CProjectile *poProj = (CProjectile*)goProjectilMgr.poGet();

	poProj->Init(0,poTransf->roPos(),poTransf->roDir(),fSpeed,this);
	goWorldEntList.poEnt.iAdd(poProj);
}

// -------------------------------------------------------------------------	
void CSh25::HandleHeight(float _fDelta)
{
	CVect3 oNextPos;
	oNextPos.Assign( poTransf->roDir() );
	oNextPos.Scale ( fSpeed*_fDelta );

	oNextPos.Add(poTransf->roPos() );

	float fNextHeight = goTRNTriListGen.GetHeight(oNextPos.X(),oNextPos.Y());

	if (oNextPos.Z() < fNextHeight  + fMinHeight )
	{
		// Rise ship
		iMFlags |= MFLAG_PU;
	}
else if( oNextPos.Z() > fNextHeight + fMaxHeight )
	{
		// Low ship	
		iMFlags |= MFLAG_PD;
	}
else if (poTransf->roDir().Z() > 0.0f)
	{
		// Low ship	
		iMFlags |= MFLAG_PD;
	}
else if (poTransf->roDir().Z() < 0.0f)
	{
		// Rise ship
		iMFlags |= MFLAG_PU;
	}
}
// -------------------------------------------------------------------------