// -----------------------------------------------------------------------------
#ifndef CGroupManagerH
#define CGroupManagerH
// -----------------------------------------------------------------------------
#include "antares.h"
#include "Game/Ents/Enemies/CEnemy.h"

class CGroupManager : public virtual CEntity
{
public:
		 CGroupManager();
		~CGroupManager();

		virtual void Init(MTH_CPoint3& _oPos,unsigned int _uiNumElems,char* _szGraphicRes);

protected:
		virtual void CreateGroup(unsigned int _uiNumElems,char* _szGraphicRes);

		MTH_CPoint3						m_oIniPos;
		MTH_CPoint3						m_oPos;
		MTH_CPoint3						m_oOPos;
		MTH_CPoint3						m_oSpd;

		MEM_DynamicArray <CEnemy*>		m_oEntLst;
};
// -----------------------------------------------------------------------------
#endif
// -----------------------------------------------------------------------------