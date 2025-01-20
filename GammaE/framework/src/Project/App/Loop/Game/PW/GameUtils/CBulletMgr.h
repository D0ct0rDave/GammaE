// -----------------------------------------------------------------------------
#ifndef CBulletMgrH
#define CBulletMgrH
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CBullet.h"

// -----------------------------------------------------------------------------
#define MAX_BULLET_TYPES	7

typedef struct TBulletType {
	
	float m_fFreq;				// Number of bullets per second
	float m_fSpeed;				// Speed of the bullet
	float m_fOwningTime;		// Time since the bullet is fired that the parent entity can control it
	float m_fLifeTime;			// Life time for this bullet
};
// -----------------------------------------------------------------------------
#define 	MAX_BULLETS		128

#define		BULLET_PLASMA	0
#define		BULLET_LASER	1
#define		BULLET_NAPALM	2


// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
class CBulletMgr
{
	public:
		static void Reset();
		static void Think(float _fDeltaT);
		static int  iAddBullet(int _iType,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,CEntity* _poParent);
		static TBulletType& oGetBulletType(int _iType);
		
	public:
		static void BulletThink(CBullet* _poBullet,float _fDeltaT);
		static void BulletThink_Laser (float _fDeltaT,CBullet* _poBullet);
		static void BulletThink_Plasma(float _fDeltaT,CBullet* _poBullet);
		static void BulletThink_Napalm(float _fDeltaT,CBullet* _poBullet);

		static CBullet *poGetFreeBullet();
		static void FillBullet (CBullet* _poBullet,int _iType,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,CEntity* _poParent);
		
		// Circular queue
		static CBullet  m_oList[MAX_BULLETS];
		static int 		m_iNumBullets;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------