// -----------------------------------------------------------------------------
#ifndef CColliderRendererH
#define CColliderRendererH

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include "GammaE.h"
#include "Collision/CGColliderPrimitive.h"
// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------
DECLARE_INHERITANT_SINGLETON(CColliderRenderer,public,CGSceneSwitch)
{
	public:
		CColliderRenderer();

		/// Rendering process for any of the colliders
		virtual void Render();
	
	protected:

		/// Renders a specific collider
		void RenderCollider(CGColliderPrimitive* _poCT,const CGVect3& _oOffset,float _fScale);
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
