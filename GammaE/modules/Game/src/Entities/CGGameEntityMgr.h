//-----------------------------------------------------------------------------
#ifndef CGGameEntityMgr_h
#define CGGameEntityMgr_h 1
//-----------------------------------------------------------------------------
#include "GammaE_Misc.h"
#include "CGGameEntity.h"
//-----------------------------------------------------------------------------
DECLARE_SINGLETON(CGGameEntityMgr)
{
  public:
		/// Registers the given game entity and returns its index
		uint uiRegister(CGGameEntity* _poEntity);
		
		/// Removes the given game entity
		void Remove(CGGameEntity* _poEntity);
		
		/// Removes the entity associated by its index
		void Remove(uint _uiEntityIdx);

		/// Returns the number of registered entities
		uint uiNumEntities();

		/// Retrieves an entity by its index
		CGGameEntity* poGetEntity(uint _uiEntityIdx);
		
		/// Retrieves an entity by its global uid
		CGGameEntity* poGetEntity(const CGString& _sEntity);

		virtual void Think (float _fDeltaT);

  protected:
	    CGLookupArray<CGGameEntity*> m_oEL;
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
