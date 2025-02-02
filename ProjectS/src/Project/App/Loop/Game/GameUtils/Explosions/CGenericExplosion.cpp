// -----------------------------------------------------------------------------
#include "CGenericExplosion.h"

// -----------------------------------------------------------------------------
const uint MAX_DEBRIS_TYPES = 3;
static CGString gssDebrisTypes[MAX_DEBRIS_TYPES] =
{
	"psystype13",
	"psystype14",
	"psystype15"
};

const uint MAX_SMOKES_TYPES = 6;
static CGString gssSmokesTypes[MAX_SMOKES_TYPES] = 
{
	"psystype7",
	"psystype8",
	"psystype9",
	"psystype10",
	"psystype11",
	"psystype12"
};

const uint MAX_CORE_EXPLOSION_TYPES = 2;
static CGString gssCoreExplosionTypes[MAX_CORE_EXPLOSION_TYPES] =
{
	"psystype19",	
	"psystype20",
};

static const uint MAX_DEBRIS_ELEMS_INT = 8;
// -----------------------------------------------------------------------------
const float MIN_DEBRIS_TIME = 0.1f;
const float MAX_DEBRIS_TIME = 0.5f;

const float MIN_DEBRIS_SPEED = 10.0f;
const float MAX_DEBRIS_SPEED = 20.0f;
// -----------------------------------------------------------------------------
CGenericExplosion::CGenericExplosion()
{
	m_fTime = 0.0f;
	m_fOTime= 0.0f;
	m_oPos  = CGVect3::oZero();
	m_oOPos = CGVect3::oZero();
}
// -----------------------------------------------------------------------------
CGenericExplosion::~CGenericExplosion()
{
}
// -----------------------------------------------------------------------------
void CGenericExplosion::Init(const CGVect3& _oPos)
{
	// CSFXObjectFactory::poGetInstance("GenericEnemyExplosion");
	m_oPos  = _oPos;
	m_fTime = Math::fLerp(MIN_DEBRIS_TIME,MAX_DEBRIS_TIME,Math::fRand());

	// Core element
	m_uiNumElems = Math::fRand() * MAX_DEBRIS_ELEMS_INT;
	m_oEl[0].m_poDebris = CGPSIManager::I()->poGet(gssCoreExplosionTypes[ (uint)(Math::fRand()*MAX_CORE_EXPLOSION_TYPES)],0.5f,_oPos);
	
	m_oEl[0].m_poSmoke  = 0;
	m_oEl[0].m_fLinearSpd = 0.0f;
	m_oEl[0].m_oDir = CGVect3::oZero();
	m_oEl[0].m_oPos = m_oPos;

	// Elements of explosion			
	for (uint i=1;i<m_uiNumElems;i++)
	{
		m_oEl[i].m_poDebris = CGPSIManager::I()->poGet(gssDebrisTypes[(uint)(Math::fRand()*MAX_DEBRIS_TYPES)],m_fTime,_oPos);
		m_oEl[i].m_poSmoke  = CGPSIManager::I()->poGet(gssSmokesTypes[(uint)(Math::fRand()*MAX_SMOKES_TYPES)],m_fTime,_oPos);

		m_oEl[i].m_oDir.x = Math::fSRand();
		m_oEl[i].m_oDir.y = Math::fSRand();
		m_oEl[i].m_oDir.z = Math::fSRand();
		m_oEl[i].m_oDir.Normalize();

		m_oEl[i].m_fLinearSpd = Math::fLerp(MIN_DEBRIS_SPEED,MAX_DEBRIS_SPEED,Math::fRand());
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
		if (m_fTime > 0.0f)
		{
			for (uint i=0;i<m_uiNumElems;i++)
			{
				m_oEl[i].m_oPos.LineEq(m_oEl[i].m_oPos,m_oEl[i].m_oDir,m_oEl[i].m_fLinearSpd*_fDeltaT);

				// Update everything
				if (m_oEl[i].m_poDebris)
					m_oEl[i].m_poDebris->SetPos( m_oEl[i].m_oPos );
				if (m_oEl[i].m_poSmoke)
					m_oEl[i].m_poSmoke ->SetPos( m_oEl[i].m_oPos );
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