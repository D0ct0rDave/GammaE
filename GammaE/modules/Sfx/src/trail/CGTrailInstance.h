// ----------------------------------------------------------------------------
#ifndef CGTrailInstance_h
#define CGTrailInstance_h 1
// ----------------------------------------------------------------------------
#include "BillBoard/CGBillboardRenderer.h"
// ----------------------------------------------------------------------------
// CObject3D_Node
#include "CGTrail.h"
#include "CGTrailGenerator.h"
// ----------------------------------------------------------------------------
class CGTrailInstance
{
	public:
		/// Initializes the instance associated to a given generator
		CGTrailInstance(CGTrailGenerator* _poTG);

		/// Reinitializes the trail instance
		void Reinit();

		/// Updates the trail with a new position
		void SetPos(const CVect3& _oNewPos);

		/// Updates the trail
		void Update();

	// --------------
	// BEGIN: These functions should only be accessible by the trail system generator

		/// Retrieves the particle pool associated to this instance
		CGTrail* poGetTrailData() const { return(m_poInstanceData); };

	// END:
	// --------------
	protected:
		CGTrail*			m_poInstanceData;
		CGTrailGenerator*	m_poTG;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
