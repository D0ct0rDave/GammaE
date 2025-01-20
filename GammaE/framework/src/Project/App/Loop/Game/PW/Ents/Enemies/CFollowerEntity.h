// -----------------------------------------------------------------------------
#ifndef CFollowerEntityH
#define CFollowerEntityH

// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/CEntity.h"

class CFollowerEntity : public virtual CEntity
{
public:	
		 CFollowerEntity();
		~CFollowerEntity();

		void Init(char* _szFilename);
		void ParsePath(char*_szFilename);
protected:
		MEM_DynamicArray<MTH_CPoint3>	m_oPoints;
		MTH_CCurve						m_oCurve;
		float							m_fPathTime;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
