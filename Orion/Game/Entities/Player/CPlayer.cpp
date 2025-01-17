// ----------------------------------------------------------------------------
#include "Game\Entities\Player\CPlayer.h"
#include "Game/GameGlobals/GameGlobals.h"
#include "Game/Entities/Projectile/CProjectile.h"

#define		DEF_ACCEL		100.0f
#define		DEF_DECCEL	   -300.0f
#define		MAX_SPEED		 50.0f
#define		DEF_DYAW		  2.5f
#define		DEF_DPITCH		  2.5f
#define		INITIAL_ENERGY	  1.0f
#define		INITIAL_SHIELD	    0
// ----------------------------------------------------------------------------
CPlayer::CPlayer()
{
	SetShipProps(DEF_ACCEL,DEF_DECCEL,MAX_SPEED,DEF_DYAW,DEF_DPITCH,INITIAL_ENERGY,INITIAL_SHIELD);

	strcpy(szName,"UnamedPlayer");
	iScore		= 0;
	fTime		= 0;
	uiWeapFlags = 0;
	iOpt		= -1;
	bActive		= true;
	fPShotTime  = 0.0f;
	fSShotTime  = 0.0f;

	iPWIdx		=  0;
	iSWIdx		=  6;

	for (int iW=0;iW<9;iW++)
		sAmmo[iW] = -1;
	
	sAmmo[0] = -1;		// Infinite ammo for blaster
	
	// <WARNING: Debug code>
	// sAmmo[1] = -1;
	// sAmmo[2] = -1;
	// sAmmo[3] = -1;
	// sAmmo[4] = -1;
	// sAmmo[5] = -1;
	
	
	// sAmmo[6] = -1;
	// sAmmo[7] = -1;
	// sAmmo[8] = -1;
}
// ----------------------------------------------------------------------------
CPlayer::~CPlayer()
{
	
}
// ----------------------------------------------------------------------------
void CPlayer::InitPlayer(char *_szPlayerName,int _iPlayerIdx,int _iModelIdx,CVect3 &_roCenter)
{
	strcpy(szName,_szPlayerName);
	Setup(OETI_PLAYER,_iPlayerIdx,_iModelIdx,_roCenter);
}
// ----------------------------------------------------------------------------
/*
#define OETI_PROJ_BLASTER				0
#define OETI_PROJ_LASER					1
#define OETI_PROJ_HYPERBLASTER			2

#define OETI_PROJ_HOMMINGMISSILE		3
#define OETI_PROJ_NAPALMMISSILE			4
#define OETI_PROJ_CONCUSSIONMISSILE		5

#define OETI_PROJ_MINGUN				6
#define OETI_PROJ_CHAINMINGUN			7

#define OETI_PROJ_PLASMA				8
#define OETI_PROJ_RAILGUN				9
#define OETI_PROJ_BFG					10
*/
// ----------------------------------------------------------------------------
void CPlayer::Fire ()
{
	if (iPWIdx==-1)			 return;	// Player doesn't have any primary weapon??
	if (sAmmo[iPWIdx]==0)	 return;	// Do we have ammonition ?
	if (fPShotTime>0.0f)	 return;	//
	
	
	// Control ammo
	if (sAmmo[iPWIdx] != -1) 
		sAmmo[iPWIdx]--;	

	// Update shot time
	fPShotTime = (1.0f / goProjProps[iPWIdx].fProjPerSec);


	// Create the current projectile
	CProjectile *poProj = (CProjectile*)goProjectilMgr.poGet();
	poProj->Init(iPWIdx,poTransf->roPos(),poTransf->roDir(),fSpeed,this);

	goWorldEntList.poEnt.iAdd(poProj);
}
// ----------------------------------------------------------------------------
void CPlayer::FireSec ()
{
	if (iSWIdx==-1)			return;		// Player doesn't have any secondary weapon
	if (sAmmo[iSWIdx]==0)	return;		// Do we have ammonition ?
	if (fSShotTime>0.0f)	return;

	// Control ammo
	if (sAmmo[iSWIdx] != -1) 
		sAmmo[iSWIdx]--;	

	// Update shot time
	fSShotTime = (1.0f / goProjProps[iSWIdx].fProjPerSec);
	
	// Create the current projectile
	CProjectile *poProj = (CProjectile*)goProjectilMgr.poGet();	
	poProj->Init(iSWIdx,poTransf->roPos(),poTransf->roDir(),fSpeed,this);
	
	goWorldEntList.poEnt.iAdd(poProj);
}
// ----------------------------------------------------------------------------
void CPlayer::Select  ()
{
	if (iOpt==-1) return;
	
	bool bUsed = false;

	switch (iOpt)
	{
		case 0:	// Laser-HyperBlaster
				if (sAmmo[1]>=0)	{	sAmmo[1] += goProjProps[1].iAmmoPack;	bUsed=true;	}
				if (sAmmo[2]>=0)	{	sAmmo[2] += goProjProps[2].iAmmoPack;	bUsed=true;	}
		break;
		
		case 1:	// Missile
				if (sAmmo[6]>=0)	{	sAmmo[6] += goProjProps[6].iAmmoPack;	bUsed=true;	}
				if (sAmmo[7]>=0)	{	sAmmo[7] += goProjProps[7].iAmmoPack;	bUsed=true;	}
				if (sAmmo[8]>=0)	{	sAmmo[8] += goProjProps[8].iAmmoPack;	bUsed=true;	}
		break;
		
		case 2:	// Chaingun
				if (sAmmo[3]>=0)	{	sAmmo[3] += goProjProps[3].iAmmoPack;	bUsed=true;	}
		break;
		
		case 3:	// Rail/BFG
				if (sAmmo[4]>=0)	{	sAmmo[4] += goProjProps[4].iAmmoPack;	bUsed=true;	}
				if (sAmmo[5]>=0)	{	sAmmo[5] += goProjProps[5].iAmmoPack;	bUsed=true;	}
		break;
		
		case 4:	// Ammo pack		
				if (sAmmo[1]>=0)	{	sAmmo[1] += goProjProps[1].iAmmoPack;	bUsed=true;	}
				if (sAmmo[2]>=0)	{	sAmmo[2] += goProjProps[2].iAmmoPack;	bUsed=true;	}
				if (sAmmo[3]>=0)	{	sAmmo[3] += goProjProps[3].iAmmoPack;	bUsed=true;	}
				if (sAmmo[4]>=0)	{	sAmmo[4] += goProjProps[4].iAmmoPack;	bUsed=true;	}
				if (sAmmo[5]>=0)	{	sAmmo[5] += goProjProps[5].iAmmoPack;	bUsed=true;	}
				if (sAmmo[6]>=0)	{	sAmmo[6] += goProjProps[6].iAmmoPack;	bUsed=true;	}
				if (sAmmo[7]>=0)	{	sAmmo[7] += goProjProps[7].iAmmoPack;	bUsed=true;	}
				if (sAmmo[8]>=0)	{	sAmmo[8] += goProjProps[8].iAmmoPack;	bUsed=true;	}				
		break;
	}
	
	if (bUsed) iOpt = -1;
}
// ----------------------------------------------------------------------------
void CPlayer::ChangeWeapon(int _iWeapon)
{
/*
#define		MFLAG_SEL_BLAST		0x00010000
#define		MFLAG_SEL_LASER		0x00020000
#define		MFLAG_SEL_HBLAST	0x00040000
#define		MFLAG_SEL_HOMMING	0x00080000
#define		MFLAG_SEL_NAPALM	0x00100000
#define		MFLAG_SEL_CONC		0x00200000
#define		MFLAG_SEL_MINIGUN	0x00400000
#define		MFLAG_SEL_CHAIGUN	0x00800000
#define		MFLAG_SEL_PLASMA	0x01000000
#define		MFLAG_SEL_RAIL		0x02000000
#define		MFLAG_SEL_BFG		0x04000000

*/
	int iOldPW = iPWIdx;
	int iOldSW = iSWIdx;

	// Primary weapons
	 if (_iWeapon & MFLAG_SEL_BLAST)
		iPWIdx = 0;
else if (_iWeapon & MFLAG_SEL_LASER)
		iPWIdx = 1;
else if (_iWeapon & MFLAG_SEL_HBLAST)
		iPWIdx = 2;
else if (_iWeapon & MFLAG_SEL_CHAINGUN)
		iPWIdx = 3;
else if (_iWeapon & MFLAG_SEL_RAIL)
		iPWIdx = 4;
else if (_iWeapon & MFLAG_SEL_BFG)
		iPWIdx = 5;

	// Control if we have this weapon
	if (sAmmo[iPWIdx] == -2) iPWIdx = iOldPW;


	// Secondary weapons
	 if (_iWeapon & MFLAG_SEL_HOMMING)
		iSWIdx = 6;
else if (_iWeapon & MFLAG_SEL_NAPALM)
		iSWIdx = 7;
else if (_iWeapon & MFLAG_SEL_CONC)
		iSWIdx = 8;

	// Control if we have this weapon
	if (sAmmo[iSWIdx] == -2) iSWIdx = iOldSW; 
}	
// ----------------------------------------------------------------------------
void CPlayer::ControlCmds (int _iCmd, bool _bEnabled, float _fValue)
{
	switch (_iCmd)
	{
		case PC_Forward:if (_bEnabled)
							iMFlags |= MFLAG_FW;
						else
							iMFlags &= ~MFLAG_FW;
						break;

		case PC_Backward:if (_bEnabled)
							iMFlags |= MFLAG_BK;
						else
							iMFlags &= ~MFLAG_BK;
						break;

		case PC_TurnUp: if (_bEnabled)
						{
							iMFlags |= MFLAG_PU;
							fDPitch = _fValue*DEF_DPITCH;
						}
						else
							iMFlags &= ~MFLAG_PU;
						break;

		case PC_TurnDown:if (_bEnabled)
						{
							iMFlags |= MFLAG_PD;
							fDPitch = _fValue*DEF_DPITCH;
						}
						else
							iMFlags &= ~MFLAG_PD;
						
						
						break;

		case PC_TurnLeft:	if (_bEnabled)
						{
							iMFlags |= MFLAG_YL;
							fDYaw = _fValue*DEF_DYAW;
						}
						else
							iMFlags &= ~MFLAG_YL;
						break;

		case PC_TurnRight:	if (_bEnabled)
						{
							iMFlags |= MFLAG_YR;
							fDYaw = _fValue*DEF_DYAW;
						}
						else
							iMFlags &= ~MFLAG_YR;						
						break;

		case PC_Roll:		/*
							if (_bEnabled)
							{
								fRoll += 2.0f*_fValue;
								SetAngles(fRoll,fYaw,0.0f);
							}
							*/
							break;
		case PC_Yaw:		/*
							if (bEnabled)
							{
								fYaw += fValue;
								SetAngles(fRoll,fYaw);
							}
							*/
							break;

		case PC_ShotPrim:	if (_bEnabled)
								iMFlags |= MFLAG_ATTACK1;
							else
								iMFlags &= ~MFLAG_ATTACK1;
							break;		
		case PC_ShotSec:	if (_bEnabled)
								iMFlags |= MFLAG_ATTACK2;
							else
								iMFlags &= ~MFLAG_ATTACK2;
							break;
		case PC_Select:		if (_bEnabled)
								iMFlags |= MFLAG_SELECT;
							else
								iMFlags &= ~MFLAG_SELECT;
							break;

		case	PC_SelW0:
		case	PC_SelW1:
		case	PC_SelW2:
		case 	PC_SelW3:
		case	PC_SelW4:
		case	PC_SelW5:
		case	PC_SelW6:
		case	PC_SelW7:
		case	PC_SelW8:	int iFlag;
							iFlag = 1 << (_iCmd - PC_SelW0 + 16);

							if (_bEnabled)
								iMFlags |= iFlag;
							else
								iMFlags &= ~iFlag;
		break;
	}
}
// ----------------------------------------------------------------------------
void CPlayer::Think(float _fDelta)
{
	// Handle primary weapon shot time
	if (fPShotTime > 0.0f)
	{
		fPShotTime -= _fDelta;
		if (fPShotTime <0.0f) fPShotTime = 0.0f;
	}
	
	// Handle secondary weapon shot time
	if (fSShotTime > 0.0f)
	{
		fSShotTime -= _fDelta;
		if (fSShotTime <0.0f) fSShotTime = 0.0f;
	}

	// Call parent function handler
	CShip::Think(_fDelta);
}
// ----------------------------------------------------------------------------
void CPlayer::ProcessCmds (float _fDelta)
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
		fYaw   = -fDYaw;
		iSpin  = 1;
	}

	if (iMFlags & MFLAG_PU)
	{
		fPitch = fDPitch;
		iSpin  = 1;
	}

	if (iMFlags & MFLAG_PD)
	{
		fPitch = -fDPitch;
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

	// ---------------------------------
	if (iMFlags & MFLAG_ATTACK1)
		Fire();

	if (iMFlags & MFLAG_ATTACK2)
		FireSec();

	if (iMFlags & MFLAG_SELECT)
		Select();

	if (iMFlags & 0xffff0000)
		ChangeWeapon(iMFlags);
}
// ----------------------------------------------------------------------------
void CPlayer::NotifyTargetCollision(COrionEnt *_poTarget)
{
	switch (_poTarget->iEntTypeID)
	{
		case OETI_ENEMY:
		{
			switch (_poTarget->iEntSubType)
			{
				case OETI_ENEMY_PERSECUTOR: this->iScore += 150;	break;
				case OETI_ENEMY_ROLLER:		this->iScore += 200;	break;
				case OETI_ENEMY_SKIPPER:	this->iScore += 250;	break;
			}
		}
		break;

		case OETI_POWERUP:
		{
			switch (_poTarget->iEntSubType)
			{
				case OETI_POWERUP_LASER:
				case OETI_POWERUP_HYPERBLASTER:
				case OETI_POWERUP_CHAINGUN:
				case OETI_POWERUP_RAILGUN:
				case OETI_POWERUP_BFG:
				case OETI_POWERUP_HOMMINGMISSILE:
				case OETI_POWERUP_NAPALMMISSILE:
				case OETI_POWERUP_CONCUSSIONMISSILE:
				{
					int iPType = _poTarget->iEntSubType;

					// Increase an ammo pack
					sAmmo[iPType] += goProjProps[iPType].iAmmoPack;

					// Control limit
					if (sAmmo[iPType] > goProjProps[iPType].iMaxAmmo)
						sAmmo[iPType] = goProjProps[iPType].iMaxAmmo;
				}
				break;

				case OETI_POWERUP_OPTION:
				{
					iOpt = (iOpt+1) % 5;				// Next powerup option
				}
				break;
			}

			_poTarget->eState = OOST_DEAD;		// The powerup must disapear
		}
		break;
	}
}
// ----------------------------------------------------------------------------
