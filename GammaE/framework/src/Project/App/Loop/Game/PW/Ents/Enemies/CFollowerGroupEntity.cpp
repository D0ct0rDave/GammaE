// -----------------------------------------------------------------------------
#include "CFollowerGroupEntity.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"
// -----------------------------------------------------------------------------
CFollowerGroupEntity::CFollowerGroupEntity()
{
}
// -----------------------------------------------------------------------------
CFollowerGroupEntity::~CFollowerGroupEntity()
{
}
// -----------------------------------------------------------------------------
void CFollowerGroupEntity::Init(char* _szGraphicRes,unsigned int _uiNum,char*_szFilename)
{	
	CFollowerEntity::Init(_szFilename);
	CGroupManager::Init((MTH_CPoint3 &)MTH_CPoint3::oZero(),_uiNum,_szGraphicRes);
}
// -----------------------------------------------------------------------------