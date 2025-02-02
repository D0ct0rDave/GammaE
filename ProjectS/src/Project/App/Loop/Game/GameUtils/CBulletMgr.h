// -----------------------------------------------------------------------------
#ifndef CBulletMgrH
#define CBulletMgrH
// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "GammaE.h"
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
	CGVect3			m_oPos;
	CGVect3			m_oOPos;
	CGVect3			m_oDir;
	CGGameEntity*	m_poParent;

	// Graphic elements
	handler			m_hPS[MAX_FXELEMS];	// Particle System
	handler			m_hFl[MAX_FXELEMS];	// Flare trail
};
// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
class CBulletMgr
{
	public:
		static void Init();
		static void Reset();
		static void Think(float _fDeltaT);
		static int  iAddBullet(int _iType,const CGVect3& _oPos,const CGVect3& _oDir,CGGameEntity* _poParent);
		static TBulletType& oGetBulletType(int _iType);
		
	public:
		static void BulletThink(TBullet* _poBullet,float _fDeltaT);
		static void BulletThink_Laser (float _fDeltaT,TBullet* _poBullet);
		static void BulletThink_Plasma(float _fDeltaT,TBullet* _poBullet);
		static void BulletThink_Napalm(float _fDeltaT,TBullet* _poBullet);

		static TBullet *poGetFreeBullet();		
		static void FillBullet (TBullet* _poBullet,int _iType,const CGVect3& _oPos,CGGameEntity* _poParent);
		
		// Circular queue
		static CGCircularArray<TBullet> m_oList;
};
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------