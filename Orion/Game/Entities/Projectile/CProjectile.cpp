#include "CProjectile.h"

#include "Game/Scene/Models/COrionObjBookmark.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Collision/COrionCollision.h"
#include "Game/Entities/CShip.h"

// -------------------------------------------------------------------------
TProjectileProps goProjProps[11] =
{
	{ OOBE_BLASTER,	150.0f,   0.07f,  50.0f,  2.5f ,  -1,  0},		// blaster
	{ OOBE_LASER,	300.0f,   0.10f,  50.0f,  2.0f ,  15,100},		// laser
	{ OOBE_BLASTER,	250.0f,   0.05f,  50.0f,  8.0f ,  25,200},		// hyperblaster
 	{ OOBE_BLASTER,	350.0f,   0.05f,  50.0f, 50.0f ,  50,300},		// chain gun
	{ OOBE_BLASTER,	1000.0f,  0.50f,  25.0f,  0.5f ,   5, 10},		// rail gun
	{ OOBE_BLASTER,	100.0f,   0.75f, 200.0f,  0.3f ,   2,  5},		// BFG

	{ OOBE_MISSILE,	100.0f,   0.30f, 200.0f,  4.0f ,  10, 25},		// homming missile
	{ OOBE_BARREL,	 10.0f,   0.70f, 100.0f,  2.0f ,   5, 20},		// napalm missile
	{ OOBE_MISSILE,	200.0f,   0.25f, 100.0f,  4.0f ,   8, 30},		// concusion missile 

	// Enemy projectiles
	{ OOBE_ELASER,	300.0f,   0.10f,  50.0f,  2.0f ,  15,100},		// enemy laser
	{ OOBE_PLASMA,	250.0f,   0.05f,  50.0f,  8.0f ,  25,200},		// plasma
};
// -------------------------------------------------------------------------
#define MAX_LIFE				10.0f			// 10 segunditos...
#define	EXPLOSION_TIME			5.0f

static CObject3D_Node oNode;
// -------------------------------------------------------------------------
#define SIZE	2.0f

CProjectile::CProjectile()
{
	// Link collision object bounding volume to Transform object bounding volume
	// Depending on the type of projectile, the transform object will be usless, but
	// its bounding volume it's always used.
	
	poTransf   = mNew CObject3D_Transf;
	oCol.poBV  = poTransf->poGetBoundVol();

	CVect3 oMax,oMin;
	oMax.V3( SIZE, SIZE, SIZE);
	oMax.V3(-SIZE,-SIZE,-SIZE);
	oCol.poBV->Init(oMax,oMin);
	
	iEntTypeID = OETI_PROJECTILE;
}

CProjectile::~CProjectile()
{
}
// -------------------------------------------------------------------------
void CProjectile::Init(int _iType,CVect3 &_roPos,CVect3 &_roDir,float _fSpeed,COrionEnt *_poParent)
{	
	fSpeed   = _fSpeed;

	iEntSubType = _iType;
	poParent    = _poParent;
	eState	    = OOST_SPAWN;	
	fLife	    = MAX_LIFE;
	bActive     = true;
	
	// Initially without target
	poTarget    = NULL;

	// Setup initial posisition
	oCol.oPos.Assign   (_roPos);
	oCol.oOldPos.Assign(_roPos);

	// <WARNING: DO NOT USE   Setup()  FOR SETTING PROJECTILE TYPE AND MODEL!>
	fSpeed = goProjProps[iEntSubType].fSpeed;
	oSpeed.Assign(_roDir);
	oSpeed.Scale (fSpeed);

	// Setup object and reference system
	CVect3 oNewUp(0.0f,0.0f,1.0f);
	CVect3 oNewSide;
	oNewSide.CrossProd(_roDir,oNewUp);	
	oNewUp.CrossProd  (_roDir,oNewSide);
	
	iModelIdx = goProjProps[iEntSubType].iModel;
	poTransf->SetObject( COrionObjBookmark::gObjBookmark[iModelIdx]->poModel );
	poTransf->SetPos (_roPos);
	poTransf->SetDir (_roDir);
	poTransf->SetSide(oNewSide);
	poTransf->SetUp  (oNewUp);
}
// -------------------------------------------------------------------------
void CProjectile::CheckForTarget()
{
	// Look in a determinate radius for a given target, and setup the nearest target
	// if it was found
	COrionEnt*	*poEnt;	
	
	float fSqActRad  = goProjProps[iEntSubType].fActionRadius;
	fSqActRad *= fSqActRad;
	
	float fMinSqDist = 1e6f;	
	poTarget = NULL;

	for (int iEnt=0;iEnt<goWorldEntList.poEnt.iMaxElems();iEnt++)
	{
		poEnt = goWorldEntList.poEnt.poElem(iEnt);

		if (poEnt)
		{
			if (! (*poEnt)->bActive)						continue;
			if (
					((*poEnt)->iEntTypeID != OETI_PLAYER) &&
					((*poEnt)->iEntTypeID != OETI_ENEMY)
			   )											continue;			
			if ((*poEnt) == poParent)						continue;
			
			if ( (*poEnt)->eState != OOST_ALIVE)			continue;
			
			// Look if it falls inside the action radius
			float fSqDist = (*poEnt)->poTransf->roPos().SqDistance( poTransf->roPos() );
			
			if (fSqDist < fSqActRad)
			{
				if (fSqDist < fMinSqDist)
				{
					poTarget = (*poEnt);
					fMinSqDist = fSqDist;
				}
			}
		}
	}
}
// -------------------------------------------------------------------------
void CProjectile::ToTheTarget()
{
	if (! poTarget) return;

	CVect3 oIdealDir,oNewDir,oNewSide,oNewUp(0.0f,0.0f,1.0f);
	oIdealDir.Assign(poTarget->poTransf->roPos());
	oIdealDir.Sub   ( poTransf->roPos() );
	oIdealDir.Normalize();

	oNewDir.Interpolate(poTransf->roDir(),oIdealDir,0.05f);	// correction factor

	oNewSide.CrossProd(oNewDir,oNewUp);	
	oNewUp.CrossProd  (oNewDir,oNewSide);

	poTransf->SetDir (oNewDir);
	poTransf->SetSide(oNewSide);
	poTransf->SetUp  (oNewUp);

	oSpeed.Assign(oNewDir);
	oSpeed.Scale(fSpeed);
}
// -------------------------------------------------------------------------
void CProjectile::Think(float _fDelta)
{
	switch (eState)
	{
		// -----------------------------------------------------------------
		case OOST_SPAWN:
		{
			switch (iEntSubType)
			{
				case OETI_PROJ_LASER:
				case OETI_PROJ_ELASER:
				case OETI_PROJ_PLASMA:
				goSndRenderer.poAddOmniEmiter(&goSound[GAMESND_LBlaster],1.0f);
				break;

				case OETI_PROJ_NAPALMMISSILE:
				goSndRenderer.poAddOmniEmiter(&goSound[GAMESND_LBlaster],1.0f);
				break;

				case OETI_PROJ_HOMMINGMISSILE:
				goSndRenderer.poAddOmniEmiter(&goSound[GAMESND_LBlaster],1.0f);
				break;
			}

			eState  = OOST_ALIVE;
			bActive = true;
		};

		// -----------------------------------------------------------------
		case OOST_ALIVE:
		{
			// Decrease projectile life time
			fLife -= _fDelta;

			// Check for projectile life
			if (fLife <= 0.0f)
			{
				// Explode this projectile
				eState = OOST_BEGINEXPLOSION;			
				return;
			}

			// Autoguided projectiles
			CheckForTarget();
			if (poTarget) ToTheTarget();

			// Update collision object
			oCol.oOldPos.Assign(oCol.oPos);
			poTransf->SetPos(oCol.oOldPos);			

			// Update some variables
			switch (iEntSubType)
			{
				case OETI_PROJ_LASER:
				break;

				case OETI_PROJ_NAPALMMISSILE:
				{
					// v = v0 + at
					oSpeed.SetZ  (oSpeed.Z() - 9.8f*_fDelta);			// add gravity
				}
				break;
			}

			CVect3 oIncPos;
			// Update next object position
			oIncPos.Assign(oSpeed);
			oIncPos.Scale (_fDelta);			// meters this frame

			CVect3 oNewPos;
			oNewPos.Assign(poTransf->roPos());
			oNewPos.Add(oIncPos);
			poTransf->SetPos(oNewPos);			

			oCol.oPos.Assign(oNewPos);
		}
		break;

		// -----------------------------------------------------------------
		case OOST_BEGINEXPLOSION:
		{
			// El proyectil tiene que explotar (entre otras cosas)
			eState = OOST_EXPLODING;
			fLife  = EXPLOSION_TIME;

			// Add sound
			goSndRenderer.poAddOmniEmiter(&goSound[GAMESND_EBlaster],1.0f);
		}
		break;
		// -----------------------------------------------------------------
		case OOST_EXPLODING:
		{
			// Decrease projectile life time
			fLife -= _fDelta;

			// Check for explosion time
			if (fLife <= 0.0f)
			{
				eState = OOST_DEAD;
				bActive = false;
			}
		}
		break;

		// -----------------------------------------------------------------
		case OOST_DEAD:
		{
		}
		break;
	}
}
// -------------------------------------------------------------------------
void CProjectile::Interact(float _fDelta)
{	
}
// -------------------------------------------------------------------------