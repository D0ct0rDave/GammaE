//-----------------------------------------------------------------------------
#ifndef CEnemyGroupH
#define CEnemyGroupH
//-----------------------------------------------------------------------------
#include "GammaE.h"
#include "CEnemy.h"
//-----------------------------------------------------------------------------
class CEnemyGroup : public CEnemy
{
	public:
		PUBLISH_GAMEENTITY_CLASSNAME;

		CEnemyGroup();

		/// Initializes the enemy group
		virtual void Init(unsigned int _uiNumElems,float _fSpawnTime,float _fEnergy,const CVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,const CGString& _sPath);

		/// Performs an update step for he whole group
		virtual void Think(float _fDeltaT);

		/// Resets the entity to its initial state
		virtual void Reset();

	protected:

		// List of entities in this group
		CGDynArray<CEnemy*>		m_oEntLst;
		
		// Time between succesive spawns
		float							m_fSpawnTime;
		
		/// Number Entities spawned
		uint							m_uiSpawnedEnts;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------