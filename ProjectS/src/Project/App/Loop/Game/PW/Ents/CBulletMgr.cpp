#include <stdlib.h>	// for NULL definition
#include "CBulletMgr.h"
#include "sfx.h"
#include "CEntCollision.h"
#include "Loop/Special/Game/CGameGlobals.h"
#include "Common/GameGlobals.h"
#include "Loop/Special/Game/Ents/Enemies/CEnemy.h"
// -----------------------------------------------------------------------------
TBulletType goBulletType[MAX_BULLET_TYPES] = {

	{ 20.0f,500.0f},	// Es un laser sencillo
	{ 5.0f, 100.0f},	// Es un laser articulado

	{ 0.5f,  0.1f},		// Napalm up
	{ 0.5f,  0.1f},		// Napalm down

	/*
	{25.0f, 0.1f,-1,-1,22,6, 6,1},		// Es un laser articulado
	{25.0f, 0.1f,-1,-1,23,6, 6,1},		// Es un laser articulado	
	{25.0f, 0.1f,-1,-1,24,6, 6,1},		// Es un laser articulado	
	{25.0f, 0.1f,-1,-1,25,6, 6,1},		// Es un laser articulado	
	{25.0f, 0.1f,-1,-1,27,6, 6,1},		// Es un laser articulado			
	*/
};

#define WEAP_PLASMA_FLARETYPE		1
#define WEAP_PLASMA_FLARECMPS		1
#define WEAP_PLASMA_EXPLOSIONPSYS	18
#define WEAP_PLASMA_DAMAGE			1

#define WEAP_LASER_FLARETYPE		6
#define WEAP_LASER_FLARECMPS		6
#define WEAP_LASER_EXPLOSIONPSYS	10
#define WEAP_LASER_DAMAGE			2

#define WEAP_NAPALM_FLARETYPE		22
#define WEAP_NAPALM_PSYSTYPE		50
#define WEAP_NAPALM_UPSPD			8.0f
#define WEAP_NAPALM_EXPLOSIONPSYS	6
#define WEAP_NAPALM_DAMAGE			20

/*
SFX:
PSYS:
15 - Un fueguete mu majo
16 - Un fuego peque�o (tipo lanza llamas)
17 - otro igual
21 - Un humillo que empieza transparente y termina opaco
31 - Humo blanco muy grande
32 - un humillo amarillo negruzco 
33 - 32 pero mas grande
34 - Humillo parpadeante
35 - Humillo blanquecino termina opaco
36 - Explosion grande
39 - Humillo vertical
45 - Humillo blanco grande
48 - Humillo blanco grande
*/
// -----------------------------------------------------------------------------
TBullet  CBulletMgr::m_oList[MAX_BULLETS];
int 	 CBulletMgr::m_iNumBullets  = 0;
// -----------------------------------------------------------------------------
void CBulletMgr::Reset()
{
	// Delete all entities
	int iBul;
	for (iBul=0;iBul<MAX_BULLETS;iBul++)	
	{
		m_oList[iBul].m_iType = -1;
		m_oList[iBul].m_iState= ENTSTATE_INACTIVE;
	}

	m_iNumBullets = 0;
}
// -----------------------------------------------------------------------------
void CBulletMgr::Think(float _fDeltaT)
{
	// Perform a full step
	for (int iBul=0;iBul<MAX_BULLETS;iBul++)
	{
		if (m_oList[iBul].m_iState != ENTSTATE_INACTIVE)
		{
			BulletThink( &m_oList[iBul], _fDeltaT );
		}
 	}

 	// Check Collisions
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink(TBullet* _poBullet,float _fDeltaT)
{
	switch (_poBullet->m_iType)
	{
		// Plasma
		case 0:
		BulletThink_Plasma(_fDeltaT,_poBullet);
		break;

		// Laser
		case 1:
		BulletThink_Laser(_fDeltaT,_poBullet);
		break;

		// Napalm
		case 2:
		case 3:
		BulletThink_Napalm(_fDeltaT,_poBullet);
		break;
	}
}
// -----------------------------------------------------------------------------
bool bBulletDead(float _fDeltaT,TBullet* _poBullet,TCollisionInfo* *_poCI)
{
	MTH_CPoint3 oPos(_poBullet->m_fTCOfs,_poBullet->m_fHeight,0.0f);
	*_poCI = CEntCollision::poCheckParticleCollision(oPos,_poBullet->m_oOPos,ENT_WORLD | ENT_USER_00);


	if (*_poCI)
	{
		*_poCI = CEntCollision::poCheckParticleCollision(oPos,_poBullet->m_oOPos,ENT_WORLD | ENT_USER_00);
	}

	float fTimeToCrossScreen = 1.25f * STD_SCR_WIDTH / goBulletType[_poBullet->m_iType].m_fSpeed;
 
	return ((*_poCI) || (_poBullet->m_fTime > fTimeToCrossScreen));
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink_Laser (float _fDeltaT,TBullet* _poBullet)
{
	// Check bullet collision
	TCollisionInfo* poCI;

	if (bBulletDead(_fDeltaT,_poBullet,&poCI))
	{
		if (poCI)
		{
			MTH_CPoint3 oDir = _poBullet->m_oPos - _poBullet->m_oOPos;

			// Add special FX to denote bullet with world collision
			MTH_CPoint3 oCP = _poBullet->m_oOPos + oDir*poCI->fU0;
			CPSysMgr::iAddSHPSys(WEAP_LASER_EXPLOSIONPSYS,oSFXPos(oCP),0.5f,2000.0f);

			if (poCI->poEnt->m_iType == ENT_USER_00)
			{
				CEnemy* poEnemy = (CEnemy*)poCI->poEnt;

				if (poEnemy->bDamage(1.0f))
					poCI->poEnt->Kill();
			}
		}

		for (int j=0;j<WEAP_LASER_FLARECMPS;j++)
			CFlareMgr::DeleteFlare(_poBullet->m_iFl[j]);

		// Disable bullet
		_poBullet->m_iState = ENTSTATE_INACTIVE;
		_poBullet->m_iType  = -1;				
	}
	else
	{
		// World position
		_poBullet->m_fTCOfs += goBulletType[_poBullet->m_iType].m_fSpeed * _fDeltaT;

		// Update position
		_poBullet->m_oOPos  = _poBullet->m_oPos;
		_poBullet->m_oPos   = oWorldPos(_poBullet->m_fTCOfs,_poBullet->m_fHeight); // _poBullet->m_oDir * goBulletType[_poBullet->m_iType].m_fSpeed * _fDeltaT;
		_poBullet->m_fTime += _fDeltaT;

		// World position
		float fFact = 1.0f / WEAP_LASER_FLARECMPS;

		// Update flare trail
		for (int j=0;j<WEAP_LASER_FLARECMPS;j++)
		{
			float fJFact = (j*fFact);
			float fVal   = fJFact*fJFact*fJFact;

			MTH_CPoint3 oDir,oPos,oOPos;
			oDir   = _poBullet->m_oPos - _poBullet->m_oOPos;
			oOPos  = _poBullet->m_oPos + oDir * 10.0f;

			oPos.x = _poBullet->m_oPos.x;
			oPos.y = fInterpol(oOPos.y,_poBullet->m_oPos.y,fVal);
			oPos.z = fInterpol(oOPos.z,_poBullet->m_oPos.z,fVal);

			CFlareMgr::UpdateFlare(_poBullet->m_iFl[j], oSFXPos(oPos));
		}
	}
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink_Plasma(float _fDeltaT,TBullet* _poBullet)
{
	// Check bullet collision
	TCollisionInfo* poCI;

	if (bBulletDead(_fDeltaT,_poBullet,&poCI))
	{
		if (poCI)
		{
			MTH_CPoint3 oDir = _poBullet->m_oPos - _poBullet->m_oOPos;

			// Add special FX to denote bullet with world collision
			MTH_CPoint3 oCP = _poBullet->m_oOPos + oDir*poCI->fU0;
			CPSysMgr::iAddSHPSys(WEAP_PLASMA_EXPLOSIONPSYS,oSFXPos(oCP),0.5f,2000.0f);

			if (poCI->poEnt->m_iType == ENT_USER_00)
			{
				CEnemy* poEnemy = (CEnemy*)poCI->poEnt;

				if (poEnemy->bDamage(1.0f))
					poCI->poEnt->Kill();
			}
		}

		for (int j=0;j<WEAP_PLASMA_FLARECMPS;j++)
			CFlareMgr::DeleteFlare(_poBullet->m_iFl[j]);

		// Disable bullet
		_poBullet->m_iState = ENTSTATE_INACTIVE;
		_poBullet->m_iType  = -1;				
	}
	else
	{
		// World position
		_poBullet->m_fTCOfs += goBulletType[_poBullet->m_iType].m_fSpeed * _fDeltaT;

		// Update position
		_poBullet->m_oOPos  = _poBullet->m_oPos;
		_poBullet->m_oPos   = oWorldPos(_poBullet->m_fTCOfs,_poBullet->m_fHeight); // _poBullet->m_oDir * goBulletType[_poBullet->m_iType].m_fSpeed * _fDeltaT;
		_poBullet->m_fTime += _fDeltaT;

		// World position
		float fFact = 1.0f / WEAP_PLASMA_FLARECMPS;

		// Update flare trail
		for (int j=0;j<WEAP_PLASMA_FLARECMPS;j++)
		{
			float fJFact = (j*fFact);
			float fVal   = fJFact*fJFact*fJFact;

			MTH_CPoint3 oDir,oPos,oOPos;
			oDir   = _poBullet->m_oPos - _poBullet->m_oOPos;
			oOPos  = _poBullet->m_oPos + oDir * 10.0f;

			oPos.x = _poBullet->m_oPos.x;
			oPos.y = fInterpol(oOPos.y,_poBullet->m_oPos.y,fVal);
			oPos.z = fInterpol(oOPos.z,_poBullet->m_oPos.z,fVal);

			CFlareMgr::UpdateFlare(_poBullet->m_iFl[j], oSFXPos(oPos));
		}
	}
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink_Napalm(float _fDeltaT,TBullet* _poBullet)
{
	// Check bullet collision
	TCollisionInfo* poCI;

	if (bBulletDead(_fDeltaT,_poBullet,&poCI))
	{
		if (poCI)
		{
			MTH_CPoint3 oDir = _poBullet->m_oPos - _poBullet->m_oOPos;

			// Add special FX to denote bullet with world collision
			MTH_CPoint3 oCP = _poBullet->m_oOPos + oDir*poCI->fU0;
			CPSysMgr::iAddSHPSys(WEAP_NAPALM_EXPLOSIONPSYS,oSFXPos(oCP),0.5f,2000.0f);

			if (poCI->poEnt->m_iType == ENT_USER_00)
			{
				poCI->poEnt->Kill();
			}
		}

		CFlareMgr::DeleteFlare(_poBullet->m_iFl[0]);
		CPSysMgr::DeletePSys  (_poBullet->m_iPS[0]);

		// Disable bullet
		_poBullet->m_iState = ENTSTATE_INACTIVE;
		_poBullet->m_iType  = -1;				
	}
	else
	{
		if (_poBullet->m_fTime < 2.0f)
			_poBullet->m_iState = 0;
		else
			_poBullet->m_iState = 1;
		
		float fCFactor = 1.0;
				
		switch (_poBullet->m_iState)
		{
			// Going up/down
			case 0:
			{
				// World position
				_poBullet->m_fTCOfs += gfMapCursorDelta;

				if (_poBullet->m_iType == 2)
					_poBullet->m_fHeight += WEAP_NAPALM_UPSPD*_fDeltaT;
				else
					_poBullet->m_fHeight -= WEAP_NAPALM_UPSPD*_fDeltaT;
			}
			break;
			
			case 1:
			{
				// World position
				_poBullet->m_fTCOfs += goBulletType[_poBullet->m_iType].m_fSpeed * _fDeltaT;

				if (_poBullet->m_fHeight > 0.0f)
					_poBullet->m_fHeight -= WEAP_NAPALM_UPSPD*_fDeltaT;
				else
					_poBullet->m_fHeight += WEAP_NAPALM_UPSPD*_fDeltaT;
				
				fCFactor = WEAP_NAPALM_UPSPD / goBulletType[_poBullet->m_iType].m_fSpeed;
			}
			break;
		}

		// Update position
		_poBullet->m_oOPos  = _poBullet->m_oPos;
		_poBullet->m_oPos   = oWorldPos(_poBullet->m_fTCOfs,_poBullet->m_fHeight); // _poBullet->m_oDir * goBulletType[_poBullet->m_iType].m_fSpeed * _fDeltaT;
		_poBullet->m_fTime += _fDeltaT;

		CFlareMgr::UpdateFlare(_poBullet->m_iFl[0], oSFXPos(_poBullet->m_oPos));
		CPSysMgr::UpdatePSys  (_poBullet->m_iPS[0], oSFXPos(_poBullet->m_oPos));
		CPSysMgr::SetCFactor  (_poBullet->m_iPS[0], fCFactor);
	}
}
// -----------------------------------------------------------------------------
TBullet *CBulletMgr::poGetFreeBullet()
{
	// handle circular queue
	int iTestBullets = 0;

	do
	{	
		if (m_oList[m_iNumBullets].m_iState == ENTSTATE_INACTIVE)
			return ( &m_oList[m_iNumBullets] );

		m_iNumBullets = (m_iNumBullets+1) % MAX_BULLETS;
		iTestBullets++;

	}while (iTestBullets < MAX_BULLETS);

	return(NULL);
}
// -----------------------------------------------------------------------------
void CBulletMgr::FillBullet (TBullet* _poBullet,int _iType,float _fTCOfs,float _fHeight,CEntity* _poParent)
{
	// World position
	_poBullet->m_fTCOfs		= _fTCOfs;
	_poBullet->m_fHeight	= _fHeight;

	_poBullet->m_iState	    = ENTSTATE_ALIVE;
	_poBullet->m_fTime		= 0.0f;
	_poBullet->m_iType		= _iType;
	_poBullet->m_oPos		= oWorldPos(_poBullet->m_fTCOfs,_poBullet->m_fHeight);
	_poBullet->m_oOPos		= _poBullet->m_oPos;
	_poBullet->m_oDir		= _poBullet->m_oPos;
	_poBullet->m_poParent	= _poParent;

	int j;
	for (int j=0;j<MAX_FXELEMS;j++)
	{
		_poBullet->m_iPS[j] = -1;
		_poBullet->m_iFl[j] = -1;
	}

	switch (_iType)
	{
		// Plasma
		case 0:
		{
			for (int j=0;j<WEAP_PLASMA_FLARECMPS;j++)
				_poBullet->m_iFl[j] = CFlareMgr::iAddFlare(WEAP_PLASMA_FLARETYPE,_poBullet->m_oPos,-1.0f);
		}
		break;

		// Laser
		case 1:
		{
			for (int j=0;j<WEAP_LASER_FLARECMPS;j++)
				_poBullet->m_iFl[j] = CFlareMgr::iAddFlare(WEAP_LASER_FLARETYPE,_poBullet->m_oPos,-1.0f);
		}
		break;

		// Napalm (up)
		case 2:
		{
			_poBullet->m_iFl[0] = CFlareMgr::iAddFlare(WEAP_NAPALM_FLARETYPE,_poBullet->m_oPos,-1.0f);
			_poBullet->m_iPS[0] = CPSysMgr::iAddPSys(WEAP_NAPALM_PSYSTYPE,_poBullet->m_oPos,-1.0f);
		}
		break;

		// Napalm (down)
		case 3:
		{
			_poBullet->m_iFl[0] = CFlareMgr::iAddFlare(WEAP_NAPALM_FLARETYPE,_poBullet->m_oPos,-1.0f);
			_poBullet->m_iPS[0] = CPSysMgr::iAddPSys(WEAP_NAPALM_PSYSTYPE,_poBullet->m_oPos,-1.0f);
		}
		break;
	}
}
// -----------------------------------------------------------------------------
int CBulletMgr::iAddBullet(int _iType,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,CEntity* _poParent)
{
	switch (_iType)
	{
		// Plasma
		case 0:		
		{
			TBullet* poBullet = poGetFreeBullet();
			FillBullet(poBullet,_iType,_oPos.x,_oPos.y,_poParent);
		}
		break;

		// Laser
		case 1:
		{
			TBullet* poBullet = poGetFreeBullet();
			FillBullet(poBullet,_iType,_oPos.x,_oPos.y,_poParent);
		}
		break;

		// Napalm
		case 2:
		{
			// One up
			TBullet* poBullet = poGetFreeBullet();
			FillBullet(poBullet,2,_oPos.x,_oPos.y,_poParent);

			// One down
			poBullet = poGetFreeBullet();
			FillBullet(poBullet,3,_oPos.x,_oPos.y,_poParent);
		}
		break;
	}

	return (1);
}
// -----------------------------------------------------------------------------
TBulletType& CBulletMgr::oGetBulletType(int _iType)
{
	return ( goBulletType[_iType] );
}
// -----------------------------------------------------------------------------