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
class CPlayer : public CGLiveGameEntity
{
public:	
		PUBLISH_GAMEENTITY_CLASSNAME();

		 CPlayer();
		~CPlayer();

		// AI/Think
		virtual void Init(const CVect3& _oPos,int _iPlayerID);
		virtual void Think(float _fDeltaT);

		virtual void UpdatePos(const CVect3& _oNewPos);
		virtual void CheckEntityCollisions();

		virtual void Kill();
		
		void ShuffleModels();

public:
		bool			m_bJumping;
		CVect3			m_oJumpDir;
		float			m_fJumpSpd;
		
		int				m_iPlayerID;
		TWeaponData		m_oWD[MAX_WEAPONS];		
		CBoundingBox	m_oBox[9];
		CBoundingBox*	m_oActiveCols[9];
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------