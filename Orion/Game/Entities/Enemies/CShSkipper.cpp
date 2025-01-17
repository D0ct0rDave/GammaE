#include "Game/Entities/Enemies/CShSkipper.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Entities/Projectile/CProjectile.h"
#include "Game/Entities/PowerUp/CPowerUp.h"
#include "Game/Scene/Models/COrionObjBookmark.h"
#include "Game/Collision/CTRNUtils.h"

#define		DEF_ACCEL		100.0f
#define		DEF_DECCEL	   -300.0f
#define		MAX_SPEED		 50.0f
#define		DEF_DYAW		 50.0f
#define		DEF_DPITCH		 50.0f
#define		INITIAL_ENERGY	  0.01f
#define		INITIAL_SHIELD	  0.0f

#define		EXPLOSION_TIME	  2.0f

// -------------------------------------------------------------------------
CShSkipper::CShSkipper()
{	
	CVect3 oCenter(0,0,0);
	SetShipProps(DEF_ACCEL,DEF_DECCEL,MAX_SPEED,DEF_DYAW,DEF_DPITCH,INITIAL_ENERGY,INITIAL_SHIELD);
	Setup(OETI_ENEMY,OETI_ENEMY_SKIPPER,OOBE_PERSECUTOR,oCenter);

	iSpawnFlags = 0;

	if ( (1.0f - MATH_Common::fRand()) < 0.2f)
		iSpawnFlags = 0x00000001;

	fShotTime	= 0;
}

CShSkipper::~CShSkipper()
{
}
// -------------------------------------------------------------------------
void CShSkipper::Think(float _fDelta)
{
	switch (eState)
	{
		case OOST_SPAWN:
		{
			eState  = OOST_ALIVE;
			bActive = true;
		}
		break;

		case OOST_ALIVE:
		{		
			fTime += gfDeltaT;
			poTarget   = gpoPlayer;

			// Forward
			iMFlags    = MFLAG_FW;


			float fCosAngle = poTransf->roDir().DotProd(poTarget->poTransf->roDir());
			float fHeight	= CTRNUtils::fGetHeight(oCol.oPos);			
			
			if ( (oCol.oPos.Z() > fHeight + 15.0f) && (fCosAngle > -0.707f))
			{
				iMFlags |= MFLAG_YL;
			}
	   else if ( (oCol.oPos.Z() < fHeight + 15.0f) && (fCosAngle < 0.707f))
			{
				iMFlags |= MFLAG_YR;
			}			

			// Control shot time		
			fShotTime += _fDelta;
			if (fShotTime >= 3.0f)
			{
				fShotTime -= 3.0f;
				Fire();
			}

			// Control inactivity zone
			if (
				(poTransf->roPos().SqDistance(poTarget->poTransf->roPos()) > (500.0f*500.0f))
			   )
			{
				eState  = OOST_EXPLODING;
				fTime   = EXPLOSION_TIME;
				poTarget= NULL;
			}
		}
		break;
		
		case OOST_BEGINEXPLOSION:
		{
			eState  = OOST_EXPLODING;
			fTime   = EXPLOSION_TIME;
			poTarget= NULL;
		}
		break;

		case OOST_EXPLODING:
		{
			fTime -= _fDelta;
 			if (fTime <= 0.0f)
			{
				fTime   = 0.0f;
				eState  = OOST_DEAD;
				bActive = false;
				
				// spawn a powerup
				if (iSpawnFlags)
				{
					CPowerUp *poPowUp = (CPowerUp *)goPowerUpMgr.poGet();
					if (poPowUp)
					{
						poPowUp->SetupPowerUp(0,poTransf->roPos(),NULL);
						goWorldEntList.poEnt.iAdd(poPowUp);
					}
				}
			}
		}
		break;
		case OOST_DEAD:
		{
			bActive = false;
		}
		break;
	}
}
// -------------------------------------------------------------------------
void CShSkipper::Fire ()
{
	CProjectile *poProj = (CProjectile*)goProjectilMgr.poGet();
	CVect3 oDir;

	oDir.Assign(poTarget->poTransf->roPos());
	oDir.Sub(poTransf->roPos());
	oDir.Normalize();

	poProj->Init(OETI_PROJ_ELASER,poTransf->roPos(),oDir,fSpeed,this);
	poProj->poTarget = poTarget;
	goWorldEntList.poEnt.iAdd(poProj);
}
// -------------------------------------------------------------------------	
