// -----------------------------------------------------------------------------
#ifndef CFollowerEnemyH
#define CFollowerEnemyH

// -----------------------------------------------------------------------------
#include "antares.h"
#include "Loop/Special/Game/Ents/CVisEntity.h"
#include "Loop/Special/Game/Ents/Enemies/CEnemy.h"

class CFollowerEnemy : public CEntity
{
public:	
		 CFollowerEnemy();
		~CFollowerEnemy();
		
		void Init(int _iSubType,char* _szFilename);
		void ParsePath(char*_szFilename);
public:
		MEM_DynamicArray<MTH_CPoint3>	m_oPoints;
		MTH_CCurve						m_oCurve;
		float							m_fPathTime;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------
