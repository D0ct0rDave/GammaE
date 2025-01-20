#include <stdlib.h>	// for NULL definition
#include "CBulletMgr.h"
#include "sfx.h"
// #include "CEntCollision.h"
#include "Game/CGameGlobals.h"
#include "Common/GameGlobals.h"
#include "Game/Ents/CEntity.h"
#include "Game/Ents/Enemies/CEnemy.h"
#include "Game/GameGraphics/SFX/CSFXLaserManager.h"
#include "Game/GameUtils/CExplosionMgr.h"
#include "Game/GameUtils/CGameMsgMgr.h"
#include "Game/GameMessages.h"

// -----------------------------------------------------------------------------

TBulletType goBulletType[MAX_BULLET_TYPES] = {

	{20.0f, 500.0f, 0.0f, 2.0f},		// Es un laser sencillo
	{1.0f/2.5f, 300.0f, 2.0f, 5.0f},	// 

	{ 0.5f,   0.1f, 0.0f, 5.0f},		// Napalm up
	{ 0.5f,   0.1f, 0.0f, 5.0f},		// Napalm down

	/*
	{25.0f, 0.1f,-1,-1,22,6, 6,1},		// Es un laser articulado
	{25.0f, 0.1f,-1,-1,23,6, 6,1},		// Es un laser articulado
	{25.0f, 0.1f,-1,-1,24,6, 6,1},		// Es un laser articulado
	{25.0f, 0.1f,-1,-1,25,6, 6,1},		// Es un laser articulado
	{25.0f, 0.1f,-1,-1,27,6, 6,1},		// Es un laser articulado
	*/
};

#define WEAP_PLASMA_FLARETYPE		1
#define WEAP_PLASMA_EXPLOSIONPSYS	18
#define WEAP_PLASMA_DAMAGE			1

#define WEAP_LASER_TYPE				0

#define WEAP_NAPALM_FLARETYPE		22
#define WEAP_NAPALM_PSYSTYPE		50
#define WEAP_NAPALM_UPSPD			8.0f
#define WEAP_NAPALM_EXPLOSIONPSYS	6
#define WEAP_NAPALM_DAMAGE			20

/*
SFX:
PSYS:
15 - Un fueguete mu majo
16 - Un fuego pequeño (tipo lanza llamas)
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
CBullet  CBulletMgr::m_oList[MAX_BULLETS];
int 	 CBulletMgr::m_iNumBullets  = 0;
// -----------------------------------------------------------------------------
void CBulletMgr::Reset()
{
	// Delete all entities
	int iBul;
	for (iBul=0;iBul<MAX_BULLETS;iBul++)	
		m_oList[iBul].m_eState= ENTSTATE_INACTIVE;

	m_iNumBullets = 0;
}
// -----------------------------------------------------------------------------
void CBulletMgr::Think(float _fDeltaT)
{
	// Perform a full step
	for (int iBul=0;iBul<MAX_BULLETS;iBul++)
	{
		if (m_oList[iBul].m_eState != ENTSTATE_INACTIVE)
		{
			BulletThink( &m_oList[iBul], _fDeltaT );
		}
 	}

 	// Check Collisions
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink(CBullet* _poBullet,float _fDeltaT)
{
	switch (_poBullet->m_iSubType)
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
bool bBulletDead(float _fDeltaT,CBullet* _poBullet,TCollisionInfo* *_poCI)
{
	*_poCI = CEntCollision::poCheckParticleCollision(_poBullet->m_oPos,_poBullet->m_oOPos,ENT_WORLD | ENT_USER_00);
	return ((*_poCI) || (_poBullet->m_fTime > goBulletType[_poBullet->m_iSubType].m_fLifeTime));
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink_Laser (float _fDeltaT,CBullet* _poBullet)
{
	// Check bullet collision
	TCollisionInfo* poCI;

	if (bBulletDead(_fDeltaT,_poBullet,&poCI))
	{
		if (poCI)
			CGameMsgMgr::SendMessage(GMSG_COLLISION,_poBullet,poCI);

		// Kill fx
		CSFXLaserManager::DeleteLaser(_poBullet->m_uiFX);

		// Disable bullet
		_poBullet->m_eState = ENTSTATE_INACTIVE;
	}
	else
	{
		CVisEntity* poParent = (CVisEntity*)_poBullet->m_poParent;
		MTH_CPoint3 oFPos  = poParent->m_poGI->poGraphicResource()->oGetCP("CP_Laser");
		MTH_CMat4x4& oMat = poParent->m_poGI->roTransform();

		MTH_CPoint3 oWFPos;
		roMat.MultVec3(oFPos,oWFPos);

		// Update position
		if (_poBullet->m_fTime< goBulletType[_poBullet->m_iSubType].m_fOwningTime)
		{
			_poBullet->m_oOPos = oWFPos;

			_poBullet->m_oPos.x += _poBullet->m_oDir.x * goBulletType[_poBullet->m_iSubType].m_fSpeed * _fDeltaT;
			_poBullet->m_oPos.y  = _poBullet->m_oOPos.y;
		}
		else
		{
			MTH_CPoint3 oDisplacement = _poBullet->m_oDir * goBulletType[_poBullet->m_iSubType].m_fSpeed * _fDeltaT;

			_poBullet->m_oOPos += oDisplacement;
			_poBullet->m_oPos  += oDisplacement;
		}

		_poBullet->m_fTime += _fDeltaT;

		CSFXLaserManager::UpdateLaser(_poBullet->m_uiFX,_poBullet->m_oOPos,_poBullet->m_oPos);
	}
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink_Plasma(float _fDeltaT,CBullet* _poBullet)
{
	// Check bullet collision
	TCollisionInfo* poCI;

	if (bBulletDead(_fDeltaT,_poBullet,&poCI))
	{
		if (poCI)
			CGameMsgMgr::SendMessage(GMSG_COLLISION,_poBullet,poCI);

		CFlareMgr::DeleteFlare(_poBullet->m_uiFX);

		// Disable bullet
		_poBullet->m_eState		= ENTSTATE_INACTIVE;
	}
	else
	{
		// Update position
		_poBullet->m_oOPos  = _poBullet->m_oPos;
		_poBullet->m_oPos  += _poBullet->m_oDir * goBulletType[_poBullet->m_iSubType].m_fSpeed * _fDeltaT;		
		_poBullet->m_fTime += _fDeltaT;

		// Update flare
		CFlareMgr::UpdateFlare(_poBullet->m_uiFX, _poBullet->m_oPos);
	}
}
// -----------------------------------------------------------------------------
void CBulletMgr::BulletThink_Napalm(float _fDeltaT,CBullet* _poBullet)
{
	/*
	// Check bullet collision
	TCollisionInfo* poCI;

	if (bBulletDead(_fDeltaT,_poBullet,&poCI))
	{
		if (poCI)
		{
			MTH_CPoint3 oDir = _poBullet->m_oPos - _poBullet->m_oOPos;

			// Add special FX to denote bullet with world collision
			MTH_CPoint3 oCP = _poBullet->m_oOPos + oDir*poCI->fU0;
			CPSysMgr::iAddSHPSys(WEAP_NAPALM_EXPLOSIONPSYS,oCP,0.5f,2000.0f);

			if (poCI->poEnt->m_iSubType == ENT_USER_00)
			{
				poCI->poEnt->Kill();
			}
		}

		CFlareMgr::DeleteFlare(_poBullet->m_iFl[0]);
		CPSysMgr::DeletePSys  (_poBullet->m_iPS[0]);

		// Disable bullet
		_poBullet->m_eState = ENTSTATE_INACTIVE;
	}
	else
	{
		float fCFactor = 1.0;

		switch (_poBullet->m_eState)
		{
			// Going up/down
			case 0:
			{
				// World position
				_poBullet->m_fTCOfs += gfMapCursorDelta;

				if (_poBullet->m_iSubType == 2)
					_poBullet->m_fHeight += WEAP_NAPALM_UPSPD*_fDeltaT;
				else
					_poBullet->m_fHeight -= WEAP_NAPALM_UPSPD*_fDeltaT;
			}
			break;
			
			case 1:
			{
				// World position
				_poBullet->m_fTCOfs += goBulletType[_poBullet->m_iSubType].m_fSpeed * _fDeltaT;

				if (_poBullet->m_fHeight > 0.0f)
					_poBullet->m_fHeight -= WEAP_NAPALM_UPSPD*_fDeltaT;
				else
					_poBullet->m_fHeight += WEAP_NAPALM_UPSPD*_fDeltaT;
				
				fCFactor = WEAP_NAPALM_UPSPD / goBulletType[_poBullet->m_iSubType].m_fSpeed;
			}
			break;
		}

		// Update position
		_poBullet->m_oOPos  = _poBullet->m_oPos;
		_poBullet->m_oPos   = oWorldPos(_poBullet->m_fTCOfs,_poBullet->m_fHeight); // _poBullet->m_oDir * goBulletType[_poBullet->m_iSubType].m_fSpeed * _fDeltaT;
		_poBullet->m_fTime += _fDeltaT;

		CFlareMgr::UpdateFlare(_poBullet->m_iFl[0], _poBullet->m_oPos);
		CPSysMgr::UpdatePSys  (_poBullet->m_iPS[0], _poBullet->m_oPos);
		CPSysMgr::SetCFactor  (_poBullet->m_iPS[0], fCFactor);
	}
	*/
}
// -----------------------------------------------------------------------------
CBullet *CBulletMgr::poGetFreeBullet()
{
	// handle circular queue
	int iTestBullets = 0;

	do
	{	
		if (m_oList[m_iNumBullets].m_eState == ENTSTATE_INACTIVE)
			return ( &m_oList[m_iNumBullets] );

		m_iNumBullets = (m_iNumBullets+1) % MAX_BULLETS;
		iTestBullets++;

	}while (iTestBullets < MAX_BULLETS);

	return(NULL);
}
// -----------------------------------------------------------------------------
void CBulletMgr::FillBullet (CBullet* _poBullet,int _iType,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,CEntity* _poParent)
{
	// World position
	_poBullet->m_eState	    = ENTSTATE_ALIVE;
	_poBullet->m_fTime		= 0.0f;
	_poBullet->m_iSubType	= _iType;
	_poBullet->m_oPos		= _oPos;
	_poBullet->m_oOPos		= _oPos;
	_poBullet->m_oDir		= _oDir;
	_poBullet->m_poParent	= _poParent;
	_poBullet->m_uiFX		= 0;

	switch (_iType)
	{
		// Plasma
		case BULLET_PLASMA:
		{
			_poBullet->m_uiFX = CFlareMgr::iAddFlare(WEAP_PLASMA_FLARETYPE,_poBullet->m_oPos,-1.0f);
		}
		break;

		// Laser
		case BULLET_LASER:
		{
			_poBullet->m_uiFX = CSFXLaserManager::uiAddLaser(WEAP_LASER_TYPE);
		}
		break;
		
		/*
		// Napalm (up)
		case BULLET_PLASMA:
		{
			_poBullet->m_iFl[0] = CFlareMgr::iAddFlare(WEAP_NAPALM_FLARETYPE,_poBullet->m_oPos,-1.0f);
			_poBullet->m_iPS[0] = CPSysMgr::iAddPSys(WEAP_NAPALM_PSYSTYPE,_poBullet->m_oPos,-1.0f);
		}
		break;

		// Napalm (down)
		case BULLET_NAPALM:
		{
			_poBullet->m_iFl[0] = CFlareMgr::iAddFlare(WEAP_NAPALM_FLARETYPE,_poBullet->m_oPos,-1.0f);
			_poBullet->m_iPS[0] = CPSysMgr::iAddPSys(WEAP_NAPALM_PSYSTYPE,_poBullet->m_oPos,-1.0f);
		}
		break;
		*/
	}
}
// -----------------------------------------------------------------------------
int CBulletMgr::iAddBullet(int _iType,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,CEntity* _poParent)
{
	switch (_iType)
	{
		// Plasma
		case BULLET_PLASMA:		
		{
			CBullet* poBullet = poGetFreeBullet();
			FillBullet(poBullet,_iType,_oPos,_oDir,_poParent);
			CGameMsgMgr::SendMessage(GMSG_SPAWN,poBullet,NULL);
		}
		break;

		// Laser
		case BULLET_LASER:
		{
			CBullet* poBullet = poGetFreeBullet();
			FillBullet(poBullet,_iType,_oPos,_oDir,_poParent);
			CGameMsgMgr::SendMessage(GMSG_SPAWN,poBullet,NULL);
		}
		break;

		// Napalm
		case BULLET_NAPALM:
		{
			// One up
			CBullet* poBullet = poGetFreeBullet();
			FillBullet(poBullet,2,_oPos,_oDir,_poParent);

			// One down
			poBullet = poGetFreeBullet();
			FillBullet(poBullet,3,_oPos,_oDir,_poParent);
			
			CGameMsgMgr::SendMessage(GMSG_SPAWN,poBullet,NULL);
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