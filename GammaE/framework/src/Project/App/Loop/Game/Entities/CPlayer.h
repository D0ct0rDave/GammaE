// -----------------------------------------------------------------------------
#ifndef CPlayerH
#define CPlayerH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
typedef struct{

	int		m_iLevel;				// Level of upgrade
	int		m_iAmmo;				// Ammo
	float	m_fShotTime;			// Shot time
	float	m_fMaxShotTime;			// Shot time

}TWeaponData;

#define MAX_WEAPONS	3
// -----------------------------------------------------------------------------
class CPlayer : public CGGameEntity
{
public:	
		 CPlayer();
		~CPlayer();

		// AI/Think
		virtual void Init(CVect3& _oPos,int _iPlayerID);
		virtual void Think(float _fDeltaT);

		virtual void CheckNewPos(float _fDeltaT);
		virtual void CheckEntityCollisions();

		// Player Actions and Commands
		virtual void DisruptPlayer(float _fStrengh);

public:
		int				m_iPlayerID;

		float			m_fOrAngle;		// Entity orientation angle
		float			m_fRollAngle;	// Entity roll angle
		// MTH_CAverager   m_oRollAvg;

		bool			m_bColl;
		// TCollisionInfo* m_poCI;

		CVect3		m_oVMovX;
		CVect3		m_oVMovZ;
// 
		float			m_fPolvilloTime;
		float			m_fLCOfs;		// Local Curve Offset
		
		CVect3		m_oLOfs;
		CVect3		m_oLAngles;
		
		CVect3		m_oLocal;	
		TWeaponData		m_oWD[MAX_WEAPONS];
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------