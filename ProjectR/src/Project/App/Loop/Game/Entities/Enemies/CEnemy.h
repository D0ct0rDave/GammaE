// -----------------------------------------------------------------------------
#ifndef CEnemyH
#define CEnemyH
// -----------------------------------------------------------------------------
#include "GammaE.h"
// -----------------------------------------------------------------------------
class CEnemy : public CGLiveGameEntity
{
	public:
		PUBLISH_GAMEENTITY_CLASSNAME;

		 CEnemy();
		~CEnemy();
		
		/// Special Initialization of the enemy entity
		virtual void Init(float _fEnergy,const CVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,const CGString& _sPath,float _fScale);
		virtual void Init(float _fEnergy,const CVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,CGPath* _poPath,float _fScale);

		/// Performs an update of the position of the entity during the given time step
		virtual void Move(float _fDeltaT);

		// Updates the position of the entity
		virtual void UpdatePos(const CVect3& _oNewPos);
		
		/// Returns the path (if any) this entity will use to perform its movement
		CGPath* poGetPath() { return(m_poPath); };

		/// Sets the path this entity will use to perform its movement
		void SetPath(CGPath* _poPath)
		{
			m_poPath = _poPath;
		};

		/// Resets the entity to its initial state
		virtual void Reset();

		/// Performs an logic step for the entity
		virtual void Think(float _fDeltaT);
		
		/// Resets the entity to its initial state
		virtual void Kill();

	protected:
		
		/// Retrieves the enemy position at a given moment on time
		CVect3 oGetPos(float _fTime);

		/// Whether the enemy movement is performed using a predefined path
		CGPath*		m_poPath;

		// Game entity idx
		uint		m_uiGID;

		/// Offset Position
		CVect3		m_oOffsetPos;
		
		/// Initial energy of this entity
		float		m_fInitialEnergy;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
