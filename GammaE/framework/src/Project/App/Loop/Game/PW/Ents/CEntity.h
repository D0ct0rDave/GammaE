// -----------------------------------------------------------------------------
#ifndef CEntityH
#define CEntityH
// -----------------------------------------------------------------------------

typedef enum TEntityState{

	ENTSTATE_NONE,
	ENTSTATE_DEAD,
	ENTSTATE_INACTIVE,
	ENTSTATE_ALIVE,
	ENTSTATE_IDLE,
	ENTSTATE_NUMSTATES,
};

// -----------------------------------------------------------------------------

class CEntity
{
public:	
		 CEntity();
		~CEntity();

		virtual void PreThink(float _fDeltaT);
		virtual void Think(float _fDeltaT);

		void SwitchToState(TEntityState _eNewState);
		virtual void OnEnterState(TEntityState _eState);
		virtual void OnExitState(TEntityState _eState);

		virtual void Kill();
		virtual void Enable();
		virtual void Disable();

public:
		// Status
		int 				m_iType;
		int					m_iSubType;

		TEntityState		m_eState;

		float				m_fTime;
		float				m_fOTime;
		float				m_fDeltaT;
		float				m_fTimeMult;
};

// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
