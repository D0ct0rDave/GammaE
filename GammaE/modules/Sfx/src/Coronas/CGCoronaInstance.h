// ----------------------------------------------------------------------------
#ifndef CGCoronaInstance_h
#define CGCoronaInstance_h 1
// ----------------------------------------------------------------------------
#include "CGCorona.h"
#include "CGCoronaGenerator.h"
// ----------------------------------------------------------------------------
class CGCoronaInstance : public CObject3D_Transf
{
	public:
		/// Initializes the instance associated to a given generator
		CGCoronaInstance(CGCoronaGenerator* _poTG);

		/// Updates the corona with a new position
		void SetPos(const CVect3& _oNewPos);

		/// Updates the corona
		virtual void Render();

	// --------------
	// BEGIN: These functions should only be accessible by the corona system generator

		/// Reinitializes the corona instance
		void Reinit();

		/// Retrieves the particle pool associated to this instance
		CGCorona* poGetCoronaData() const { return(m_poInstanceData); };

	// END:
	// --------------
	protected:
		CGCorona*			m_poInstanceData;
		CGCoronaGenerator*	m_poTG;
};
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
