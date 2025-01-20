// -----------------------------------------------------------------------------
#include "CBullet.h"
#include "EntityIDs.h"
#include "sfx.h"
// -----------------------------------------------------------------------------
CBullet::CBullet()
{
	m_iType    = ENT_BULLET;
}
// -----------------------------------------------------------------------------
void CBullet::Think()
{
}
// -----------------------------------------------------------------------------
void CBullet::Restart(CEntity* _poParent,MTH_CPoint3& _oPos,MTH_CPoint3& _oDir,float _fSpd)
{
	m_fTime		= 0.0f;
	m_poParent	= _poParent;
	m_oPos		= _oPos;
	m_oDir		= _oDir;
	m_uiFX		= 0;

//	m_poBV      = pNew CBVSphere;
	Enable();
}
// -----------------------------------------------------------------------------