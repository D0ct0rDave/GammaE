// -----------------------------------------------------------------------------
#ifndef CActorH
#define CActorH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Special/Game/Ents/CVisEntity.h"
#include "Loop/Special/Game/Ents/CEntCollision.h"

// -----------------------------------------------------------------------------
// Movement flags

#define MF_UP		0x01
#define MF_LEFT		0x02
#define MF_RIGHT	0x04
#define MF_DOWN		0x08
#define MF_ALL		(MF_UP | MF_LEFT | MF_RIGHT | MF_DOWN)

// -----------------------------------------------------------------------------
typedef struct TStateCfg{

	bool  bCycl;
	int   iAnim;
};

#define MAX_ANIM_STATES 10
// -----------------------------------------------------------------------------
class CActor : public CVisEntity
{
public:
		 CActor();
		~CActor();

		// AI/Think
		virtual void Init(MTH_CPoint3& _oPos,char* _szModel,char* _szActorName,bool _bAddEntity = false);
		virtual void Think();

		virtual bool bCheckNewPos(float _fDeltaT,unsigned int _uiCollEnts);
		virtual unsigned int uiCheckMovements(unsigned int _uiTestMVFlags,float _fXOfs,float _fZOfs,unsigned int _uiCollEnts);
		virtual void Restart();

		void SetActorState(int  _iState);

protected:

		void SetAnimPars(int _iState,bool _bCycle,int _iAnimState);

public:
		float			m_fOrAngle;		// Entity orientation angle
		float			m_fRollAngle;	// Entity roll angle
		MTH_CAverager   m_oAvg;

		bool			m_bColl;
		TCollisionInfo* m_poCI;

		// Actor animaiton states
		int				m_iAnimState;
		int				m_iOldAnimState;

		int				m_iBaseState;				// Offset between entity and animation state
		TStateCfg		m_oASt[MAX_ANIM_STATES];
		MTH_CPoint3		m_oSpd;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------