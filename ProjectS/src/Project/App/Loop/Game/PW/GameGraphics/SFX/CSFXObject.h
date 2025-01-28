#ifndef CSFXObjectH
#define CSFXObjectH

#include <stdlib.h>
#include "antares.h"

// ----------------------------------------------------------------------------
class CSFXObject
{
	public:
			 CSFXObject();
			virtual ~CSFXObject();

			virtual void Init(MTH_CPoint3 &_oPos);
			virtual void Init(MTH_CPoint3 &_oPos,MTH_CPoint3 &_oDir);

			virtual void Enable();
			virtual void Disable();
			virtual void Update(float _fDeltaT);
			virtual void Render();

			virtual void Dir(MTH_CPoint3 &_oDir);
			virtual void Pos(MTH_CPoint3 &_oPos);

	public:
			bool			m_bEnabled;

			MTH_CPoint3		m_oIPos;				// Initial position
			MTH_CPoint3		m_oIDir;				// Initial direction
			MTH_CPoint3		m_oPos;					// Current (world) position
			MTH_CPoint3		m_oDir;					// Current (world) direction

			bool			m_bDirectional;			// Is FX Object Directional
};


// ----------------------------------------------------------------------------
#endif
