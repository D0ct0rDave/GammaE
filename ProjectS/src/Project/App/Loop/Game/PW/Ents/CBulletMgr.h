// -----------------------------------------------------------------------------
#ifndef CBulletMgrH
#define CBulletMgrH
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Special/Game/Ents/CEntity.h"
// -----------------------------------------------------------------------------
#define MAX_BULLET_TYPES	7

typedef struct TBulletType {
	float m_fFreq;		// Number of bullets per second
	float m_fSpeed;
};
// -----------------------------------------------------------------------------
#define 	MAX_BULLETS		128
#define		MAX_FXELEMS		100

typedef struct TBullet{

	int				m_iState;
	int				m_iType;
	float			m_fTime;
	MTH_CPoint3		m_oPos;
	MTH_CPoint3		m_oOPos;
	MTH_CPoint3		m_oDir;
	CEntity*		m_poParent;

	float			m_fHeight;
	float			m_fTCOfs;

	// Graphic elements
	int				m_iPS[MAX_FXELEMS];	// Particle System
	int				m_iFl[MAX_FXELEMS];	// Flare trail
};
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
		static void BulletThink(TBullet* _poBullet,float _fDeltaT);
		static void BulletThink_Laser (float _fDeltaT,TBullet* _poBullet);
		static void BulletThink_Plasma(float _fDeltaT,TBullet* _poBullet);
		static void BulletThink_Napalm(float _fDeltaT,TBullet* _poBullet);

		static TBullet *poGetFreeBullet();		
		static void FillBullet (TBullet* _poBullet,int _iType,float _fTCOfs,float _fHeight,CEntity* _poParent);
		
		// Circular queue
		static TBullet  m_oList[MAX_BULLETS];
		static int 		m_iNumBullets;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------