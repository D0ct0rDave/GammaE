//-----------------------------------------------------------------------------
/*! \class CGColliderInstance
 *  \brief A component that stores the collider information of the instance of a resource
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
//-----------------------------------------------------------------------------

#ifndef CGColliderInstanceH
#define CGColliderInstanceH
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "CGColliderPrimitive.h"
#include "CGColliderResource.h"
// -----------------------------------------------------------------------------
class CGColliderInstance
{
	public:
		/// Creates an instance of a given resource
		CGColliderInstance(const CGString& _sResource);
		
		/// Creates an instance of a given resource
		CGColliderInstance(CGColliderResource* _poResource) { m_poResource = _poResource; };
		
		/// Initializes the instance with the given resource
		void Init(const CGString& _sResource);

		/// The scale of this instance
		float				m_fScale;

		/// The position of the entity this frame
		CGVect3				m_oPos;
		
		/// The previous position of the entity
		CGVect3				m_oOldPos;

		/// Collision information
		CGColliderResource*	m_poResource;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
