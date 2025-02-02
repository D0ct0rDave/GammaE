//-----------------------------------------------------------------------------
#ifndef CGGEntityCollisionMgrH
#define CGGEntityCollisionMgrH
//-----------------------------------------------------------------------------
#include "GammaE.h"
#include "CGColliderInstance.h"
#include "CGColliderPrimitive.h"
class CGGameEntity;
//-----------------------------------------------------------------------------
class CGCollisionInfo
{
	public:	

		/// Entity who produced the collision
		CGGameEntity*			m_poEnt;

		/// Collider part of the entity where the collision was detected
		CGColliderPrimitive*	m_poCP;

		/// Minimum time of collision
		float					m_fU;

		/// Minimum point of collision
		CGVect3					m_oP;
};
//-----------------------------------------------------------------------------
DECLARE_SINGLETON(CGGEntityCollisionMgr)
{
	public:
		/// Performs an update step on the collision system for the entities already registered
		void Update(float _fDeltaT);
		
		/// Tests the source entity against all the other registered entities
		CGCollisionInfo*  poCheckCollision(CGGameEntity* _poSrcEnt);

		/// Performs a collision test between a particle and the registered entities in the system
		CGCollisionInfo*  poCheckParticleCollision(const CGVect3& _roPos,const CGVect3& _roOldPos,CGGameEntity* _poParent);
	
	protected:
		
		/// Performs a collision test between two collider instances
		CGCollisionInfo*  poCheckCollision(CGColliderInstance* _poSrcCI,CGColliderInstance* _poDstCI);

		/// Performs a collision test between two collider primitives
		CGCollisionInfo*  poCheckCollision(CGColliderPrimitive* _poSrcCol,float _fSrcScale,CGColliderPrimitive* _poDstCol,float _fDstScale);

		/// Performs a collision test between a sphere and a detination collider primitive
		CGCollisionInfo*  poCheckCollision(const CGVect3& _oSrcPos,float _fSrcRadius,CGColliderPrimitive* _poDstCol,float _fDstScale);

		/// Performs a collision test between a particle and the a specific registered entity
		CGCollisionInfo*  poCheckParticleCollision(CGColliderInstance* _poEnt);

		/// Performs a collision test between a particle and the a specific collider primitive
		CGCollisionInfo*  poCheckParticleCollision(CGColliderPrimitive* _poCT,float _fScale);
};
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------