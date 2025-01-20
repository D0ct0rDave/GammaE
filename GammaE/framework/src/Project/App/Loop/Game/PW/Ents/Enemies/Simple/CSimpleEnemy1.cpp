// ----------------------------------------------------------------------
#include "CSimpleEnemy1.h"

// ----------------------------------------------------------------------
#include "Loop/Game/CGame.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/3DObjWH/C3DObjWH.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/EntRend/CEntRend.h"

#include "antares.h"
#include "sfx.h"
// ----------------------------------------------------------------------
#define MODELNAME	"data/models/enemies/simple/simpleenemy1/enemy1.GEO"

#define MIN_ENTITYSPEED 0.005f
#define MAX_ENTITYSPEED 0.025f
// ----------------------------------------------------------------------
CSimpleEnemy1::CSimpleEnemy1()
{
	m_iType  = ENT_USER_00;
}
// ----------------------------------------------------------------------
void CSimpleEnemy1::Init(MTH_CPoint3 _oPos,float _fCursor,float _fHeight,int _iSubType)
{
	m_poGI = pNew GEOM_Instance;
	m_poGI->Init( C3DObjWH::poGetObj(MODELNAME) );

	m_uiFX  = CFlareMgr::iAddFlare(7,_oPos,-1.0f);

	// Get radius
	m_poBV = pNew CBVSphere;
	((CBVSphere*)m_poBV)->m_fRadius = fMin(fMin ((m_poGI->m_poModel->m_fBBXMax - m_poGI->m_poModel->m_fBBXMin)*0.5f,
												 (m_poGI->m_poModel->m_fBBYMax - m_poGI->m_poModel->m_fBBYMin)*0.5f),
					  	                         (m_poGI->m_poModel->m_fBBZMax - m_poGI->m_poModel->m_fBBZMin)*0.5f);
	Restart(_oPos,_fCursor,_fHeight,_iSubType);

	// Add entity to the entity manager
	CEntityMgr::iAddEntity(this);

	// Add to render entities
	m_iRI = CEntRend::iAdd(this);

	SetVisible(true);
	m_eState = ENTSTATE_ALIVE;
}
// ----------------------------------------------------------------------
void CSimpleEnemy1::Restart(MTH_CPoint3 _oPos,float _fCursor,float _fHeight,int _iSubType)
{
	// Get random speed
	m_fSpd = fInterpol( MIN_ENTITYSPEED,MAX_ENTITYSPEED,fRand() );

	// Enemy cursor
	m_fCursor = _fCursor;
	
	// if (fRand() > 0.5f) _fHeight = 1.0f; else _fHeight = -1.0f;

	float fMaxRad;
	if (_fHeight > 0.0f)
		fMaxRad = gpoMap->m_oHFRP.m_fRadius - CHeightField::fHeight(0.0f,_fCursor)*gpoMap->m_oHFRP.m_fHScale - ((CBVSphere*)m_poBV)->m_fRadius;
	else
		fMaxRad = gpoMap->m_oHFRP.m_fRadius - CHeightField::fHeight(1.0f,_fCursor)*gpoMap->m_oHFRP.m_fHScale - ((CBVSphere*)m_poBV)->m_fRadius;
	
	m_fHeight = _fHeight*fMaxRad;

	// Compute first position
	m_oOPos = m_oPos;
	ComputePositions();	
	
	ShowEnable();
}
// ----------------------------------------------------------------------
void CSimpleEnemy1::Think()
{
	if (m_eState == ENTSTATE_DEAD)
	{
		HideDisable();
		return;
	}

	m_fCursor -= m_fSpd*m_fDeltaT;

	if (m_fCursor < (gfMapCursor - 0.04f))
	{
		HideDisable();
	}
	else
	{
		ComputePositions();
	}
}
// ----------------------------------------------------------------------
void CSimpleEnemy1::SetVisible(bool _bVisible)
{
	// Hide SFX
	if (_bVisible)
		CFlareMgr::Enable(m_uiFX);
	else
		CFlareMgr::Disable(m_uiFX);

	CVisEntity::SetVisible(_bVisible);
}
// ----------------------------------------------------------------------
void CSimpleEnemy1::ComputePositions()
{
	m_oOPos = m_oPos;
	m_oPos  = oWorldPos(m_fCursor,m_fHeight);

	MTH_CMat4x4 oRS = gpoMap->m_oPath.oGetRefSys(m_fCursor);
	oRS.SetPosition(m_oPos);

	// Concatenation of matrices
	m_poGI->SetMatrix(oRS);

	// Update FX position
	float fRadius = m_poGI->m_poModel->m_fBBYMax + 0.5f;
	#define FREQ 100.0f
	MTH_CPoint3 oFXPos,oLFXPos = m_oPos + MTH_CPoint3(fRadius*fCos(m_fCursor*_2PI_*FREQ),fRadius*fSin(m_fCursor*_2PI_*FREQ),0.0f);
	oRS.MultVec3(oLFXPos,oFXPos);
	CFlareMgr::UpdateFlare(m_uiFX,oFXPos);
}
// ----------------------------------------------------------------------