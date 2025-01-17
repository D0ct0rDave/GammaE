// ----------------------------------------------------------------------------
#include "Game\Entities\CShip.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Scene/Models/COrionObjBookmark.h"

#include "Game/Collision/COrionCollision.h"
// ----------------------------------------------------------------------------
#define		SHIP_EXPLOSIONTIME	5.0f
// ----------------------------------------------------------------------------
CShip::CShip()
{
	// Flags / estado , etc
	iMFlags = 0;	
}
// ----------------------------------------------------------------------------
CShip::~CShip()
{
}
// ----------------------------------------------------------------------------
void CShip::Think (float _fDelta)
{
	switch (eState)
	{
		case OOST_SPAWN:
		{
			eState  = OOST_ALIVE;
			bActive = true;
		}
		break;
		
		case OOST_BEGINEXPLOSION:
		{
			eState  = OOST_EXPLODING;
			fTime	= SHIP_EXPLOSIONTIME;
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
			}
		}

		case OOST_DEAD:
		{
			eState  = OOST_DEAD;
			bActive = false;
		}
		break;
	}
}
// ----------------------------------------------------------------------------
void CShip::ProcessCmds (float _fDelta)
{
	if (eState != OOST_ALIVE) return;

  	// Process input commands
	// La gravedad por un lado
	/*
	at.V3(0.0f,0.0f,GRAVITY.Z());
	at.Scale(_fDelta);
	at.SetZ(at.Z()*MAX_SPEED_Z + oColObj.Speed.Z());	
	AddForce(at);
	*/
	// ---------------------
	// Handle rotation angle
	// ---------------------
	float fYaw,fPitch;
	int   iSpin = 0;

	fYaw   = 0.0f;
	fPitch = 0.0f;

	if (iMFlags & MFLAG_YL)
	{
		fYaw  = fDYaw;
		iSpin = 1;
	}

	if (iMFlags & MFLAG_YR)
	{
		fYaw  -= fDYaw;
		iSpin  = 1;
	}

	if (iMFlags & MFLAG_PU)
	{
		fPitch = fDPitch;
		iSpin  = 1;
	}

	if (iMFlags & MFLAG_PD)
	{
		fPitch -= fDPitch;
		iSpin  = 1;
	}

	if (iSpin)
	{
		// Setup previous camera vector
		// Establecer los nuevos ejes: Transformarlos con los nuevos ángulos incrementados
		CMatrix4x4 R;
		R.LoadIdentity();
		R.RotateFromArbitraryAxis(	fPitch,
									poTransf->roSide().X(),
									poTransf->roSide().Y(),
									poTransf->roSide().Z());
		R.TransformVector(poTransf->roUp()  );
		R.TransformVector(poTransf->roDir() );

		poTransf->roSide().CrossProd(poTransf->roDir(),poTransf->roUp() );

		R.LoadIdentity();
		R.RotateFromArbitraryAxis( fYaw,poTransf->roUp().X() ,poTransf->roUp().Y() ,poTransf->roUp().Z() );
		R.TransformVector(poTransf->roSide());
		R.TransformVector(poTransf->roDir());
	}

	// --------------------
	// Handle Speed
	// --------------------
	float fNewSpeed;	
	fNewSpeed = fSpeed;

	if (iMFlags & MFLAG_FW)
		fNewSpeed += fAccel*_fDelta;
	
	if (iMFlags & MFLAG_BK)
		fNewSpeed += fDecel*_fDelta;

	if (fNewSpeed > fMaxSpeed) 
		fNewSpeed = fMaxSpeed;
else if (fNewSpeed<0.0f)
		fNewSpeed = 0.0f;
	
	fSpeed = fNewSpeed;
	
	CVect3 oNewSpeed;
	oNewSpeed.Assign(poTransf->roDir());
	oNewSpeed.Scale (fSpeed);					// Meters per second

	// ---------------------------------
	// Esto deberia estar en el interact
	// ---------------------------------
	CVect3 oIncPos;
	oIncPos.Assign(oNewSpeed);
	oIncPos.Scale (_fDelta);					// Meters this frame

	oCol.oOldPos.Assign(oCol.oPos);
	oCol.oPos.Add(oIncPos);

	poTransf->SetPos(oCol.oPos);
	
	// Transform of the bounding volume performed in previous step
	// oCol.poBV->Transform(poTransf->roTransf());
//	AddForce(oNewSpeed);
}
// ----------------------------------------------------------------------------
void CShip::Interact (float _fDelta)
{	

}
// ----------------------------------------------------------------------------
void CShip::ComputeCollisionResponse ()
{
}

// ----------------------------------------------------------------------------
void CShip::NotifyTargetCollision(COrionEnt *_poTarget)
{
}

void CShip::ReceiveImpact(float _fImpactFactor,COrionEnt *_poInflictor)
{	
	if (! bActive)				return;
	if (eState != OOST_ALIVE)	return;

	fEnergy -= (1.0 - fShield)*_fImpactFactor*0.1f;
	fShield -= _fImpactFactor*0.1f;
	
	if (fShield <= 0.0f)
		fShield = 0.0f;
	
	if (fEnergy <= 0.0f)
	{
		fEnergy = 0.0f;
		eState  = OOST_BEGINEXPLOSION;
	}
	else
	{		
		if (_poInflictor == NULL)
		{
			// _poInflictor == NULL: Impact from static scene and terrain


			// By the moment...
			CVect3 oNewDir(0.0f,0.0f,1.0f);			
			poTransf->SetDir(oNewDir);
			poTransf->roUp().CrossProd(poTransf->roDir(),poTransf->roSide());
		}
		else
		{	
			// Correct ship trajectory
			/*
			CVect3 oNewDir,oNewSide,oNewUp(0.0f,0.0f,1.0f);

			oNewDir.Assign( _poInflictor->poTransf->roDir() );
			oNewDir.Add   (poTransf->roDir());

			float fSpeedMod = oNewDir.Module();

			if (fSpeedMod)			
				oNewDir.Scale(1.0f / fSpeedMod);

			fSpeed = fSpeedMod;

			oNewUp  .CrossProd(poTransf->roSide(),oNewDir);
			oNewSide.CrossProd(oNewDir,oNewUp);

			// oNewSide.CrossProd(oNewDir,oNewUp);
			// oNewUp.CrossProd  (oNewDir,oNewUp);
			
			poTransf->SetDir ( oNewDir );
			poTransf->SetSide( oNewSide);
			poTransf->SetUp  ( oNewUp  );
			*/
		}
	}
}
// ----------------------------------------------------------------------------