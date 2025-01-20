// -----------------------------------------------------------------------------
#ifndef CPlayerH
#define CPlayerH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CActor.h"
#include "Game/Ents/CEntCollision.h"
// -----------------------------------------------------------------------------
typedef struct{

	int		m_iLevel;				// Level of upgrade
	int		m_iAmmo;				// Ammo
	float	m_fShotTime;			// Shot time
	float	m_fMaxShotTime;			// Shot time

}TWeaponData;

#define MAX_WEAPONS	3
// -----------------------------------------------------------------------------
class CPlayer : public CVisEntity
{
public:	
		 CPlayer();
		~CPlayer();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos,int _iPlayerID);
		virtual void Think(float _fDeltaT);

		virtual void CheckNewPos(float _fDeltaT);
		virtual void CheckEntityCollisions();

		// Player Actions and Commands
		virtual void DisruptPlayer(float _fStrengh);

public:
		int				m_iPlayerID;

		float			m_fOrAngle;		// Entity orientation angle
		float			m_fRollAngle;	// Entity roll angle
		MTH_CAverager   m_oRollAvg;

		bool			m_bColl;
		TCollisionInfo* m_poCI;

		MTH_CPoint3		m_oVMovX;
		MTH_CPoint3		m_oVMovZ;
// 
		float			m_fPolvilloTime;
		float			m_fLCOfs;		// Local Curve Offset
		
		MTH_CPoint3		m_oLOfs;
		MTH_CPoint3		m_oLAngles;
		
		MTH_CPoint3		m_oLocal;	
		TWeaponData		m_oWD[MAX_WEAPONS];
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------