// -----------------------------------------------------------------------------
#include "CGenericExplosion.h"
#include "antares.h"
#include "sfx.h"
// -----------------------------------------------------------------------------

const uint MAX_DEBRIS_TYPES = 3;
static uint gsuiDebrisTypes[MAX_DEBRIS_TYPES] = {
	13,14,15,
};

const uint MAX_SMOKES_TYPES = 6;
static uint gsuiSmokesTypes[MAX_SMOKES_TYPES] = {
	7,8,9,10,11,12
};

const uint MAX_CORE_EXPLOSION_TYPES = 2;
static uint gsuiCoreExplosionTypes[MAX_CORE_EXPLOSION_TYPES] = {
	19,20,
};

static const uint MAX_DEBRIS_ELEMS_INT = 8;
// -----------------------------------------------------------------------------
const float MIN_DEBRIS_TIME = 0.1f;
const float MAX_DEBRIS_TIME = 0.5f;

const float MIN_DEBRIS_SPEED = 100.0f;
const float MAX_DEBRIS_SPEED = 200.0f;
// -----------------------------------------------------------------------------
CGenericExplosion::CGenericExplosion()
{
	m_fTime = 0.0f;
	m_fOTime= 0.0f;
	m_oPos.Set(0,0,0);
	m_oOPos.Set(0,0,0);
}
// -----------------------------------------------------------------------------
CGenericExplosion::~CGenericExplosion()
{
}
// -----------------------------------------------------------------------------
void CGenericExplosion::Init(MTH_CPoint3& _oPos)
{
	// CSFXObjectFactory::poGetInstance("GenericEnemyExplosion");
	m_oPos = _oPos;
	m_fTime = fInterpol(MIN_DEBRIS_TIME,MAX_DEBRIS_TIME,fRand());

	// Core element
	m_uiNumElems = iRand(MAX_DEBRIS_ELEMS_INT) + 1;
	m_oEl[0].m_uiDebris = CPSysMgr::iAddPSys(gsuiCoreExplosionTypes[ iRand(MAX_CORE_EXPLOSION_TYPES) ],_oPos,-1.0f);
	m_oEl[0].m_uiSmoke  = 0;
	m_oEl[0].m_fLinearSpd = 0.0f;
	m_oEl[0].m_oDir.Set(0,0,0);
	m_oEl[0].m_oPos = m_oPos;

	// Elements of explosion		
	for (uint i=1;i<m_uiNumElems;i++)
	{
		m_oEl[i].m_uiDebris = CPSysMgr::iAddPSys(gsuiDebrisTypes[ iRand(MAX_DEBRIS_TYPES) ],_oPos,-1.0f);
		m_oEl[i].m_uiSmoke  = CPSysMgr::iAddPSys(gsuiSmokesTypes[ iRand(MAX_SMOKES_TYPES) ],_oPos,-1.0f);

		m_oEl[i].m_oDir.x = fSRand();
		m_oEl[i].m_oDir.y = fSRand();
		m_oEl[i].m_oDir.z = fSRand();
		m_oEl[i].m_oDir.Unit();
		
		m_oEl[i].m_fLinearSpd = fInterpol(MIN_DEBRIS_SPEED,MAX_DEBRIS_SPEED,fRand());
		
		m_oEl[i].m_oPos = m_oPos;
	}
}
// -----------------------------------------------------------------------------
void CGenericExplosion::Finish()
{
	
}
// -----------------------------------------------------------------------------
void CGenericExplosion::Think(float _fDeltaT)
{
	if (m_fTime > 0.0f)
	{
		m_fTime -= _fDeltaT;
	
		// If time has 
		if (m_fTime <=0.0f)
		{
			for (uint i=0;i<m_uiNumElems;i++)
			{
				CPSysMgr::DeletePSys(m_oEl[i].m_uiSmoke );
				CPSysMgr::DeletePSys(m_oEl[i].m_uiDebris);
			}

			m_fTime = 0.0f;
		}
		else
		{
			for (uint i=0;i<m_uiNumElems;i++)
			{
				m_oEl[i].m_oPos += m_oEl[i].m_oDir*m_oEl[i].m_fLinearSpd*_fDeltaT;
				
				// Update everything
				CPSysMgr::UpdatePSys(m_oEl[i].m_uiSmoke, m_oEl[i].m_oPos);
				CPSysMgr::UpdatePSys(m_oEl[i].m_uiDebris,m_oEl[i].m_oPos);
			}
		}
	}	
}
// -----------------------------------------------------------------------------
void CGenericExplosion::Render()
{

}
// -----------------------------------------------------------------------------
bool CGenericExplosion::bAlive()
{
	return(m_fTime>0.0f);
}
// -----------------------------------------------------------------------------