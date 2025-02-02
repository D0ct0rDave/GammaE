// -----------------------------------------------------------------------------
#ifndef CGColliderResourceH
#define CGColliderResourceH
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "CGColliderPrimitive.h"
// -----------------------------------------------------------------------------
class CGColliderResource : public CGResource
{
	public:
		
		/// Stores an specific text ID for this collider
		CGString			m_sID;
	
		/// The entity type represented for this collider
		uint				m_uiEntType;

		/// The mask to select which entities to test
		uint				m_uiTestMask;

		/// Collision information
		CGColliderPrimitive*		m_poCT;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
