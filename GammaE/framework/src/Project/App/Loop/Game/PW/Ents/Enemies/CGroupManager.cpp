#include "CGroupManager.h"

#include "antares.h"
#include "sfx.h"

#include "Game/CGameGlobals.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"
#include "Game/Ents/CEntCollision.h"

// -----------------------------------------------------------------------------
CGroupManager::CGroupManager()
{
	m_iType = ENT_GROUP;
}
// -----------------------------------------------------------------------------
CGroupManager::~CGroupManager()
{
}
// -----------------------------------------------------------------------------
void CGroupManager::Init(MTH_CPoint3& _oPos,unsigned int _uiNumElems,char* _szGraphicRes)
{
	// Create frame and setup startup position
	m_oIniPos   = _oPos;
	m_oIniPos.z = -900.0f;
	m_oPos      = m_oIniPos;
	m_oOPos     = m_oIniPos;

	// 
	CreateGroup(_uiNumElems,_szGraphicRes);
}
// -----------------------------------------------------------------------------
void CGroupManager::CreateGroup(unsigned int _uiNumElems,char* _szGraphicRes)
{
	for (int i=0;i<_uiNumElems;i++)
	{
		CEnemy* poEnt	= pNew CEnemy;
		poEnt->m_poGI	= pNew CGraphicInstance(_szGraphicRes);

		// Build bounding volume
		poEnt->BuildBV();

		// Hide entity
		poEnt->HideDisable();

		// Add entity to the list
		m_oEntLst.iAdd(poEnt);
	}
}
// -----------------------------------------------------------------------------