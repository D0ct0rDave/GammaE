// ----------------------------------------------------------------------
#include "CBigEgg.h"

// ----------------------------------------------------------------------
#include "Game/CGame.h"
#include "Game/CGameGlobals.h"
#include "Game/Ents/CEntityMgr.h"
#include "Game/GameGraphics/CEntRend.h"

#include "antares.h"
#include "sfx.h"
// ----------------------------------------------------------------------
#define MODELNAME	"data/models/enemies/simple/egg/egg.g"
// ----------------------------------------------------------------------
CBigEgg::CBigEgg()
{
	m_iType  = ENT_USER_00;
}
// ----------------------------------------------------------------------
void CBigEgg::Init(MTH_CPoint3& _oPos,float _fScale)
{
	// Load model
	m_poGI = pNew CGraphicInstance( "Egg" );

	// Setup startup position
	m_oPos    = _oPos;
	m_oOPos   = m_oPos;	
	m_poGI->Pos(m_oPos);
	m_poGI->Scale(-1.0f*_fScale);

	// Add entity to the entity manager	
	CEntityMgr::iAddEntity(this);

	// Add to render entities
	CEntRend::iAdd(this);

	// Get radius
	BuildBV();
	
	// Set visible
	Visible(true);

	// Set local position
	m_fAngle = 0.0f;
	m_fPhase = 0.0f;

	// Setup global variable
	Enable();
}
// ----------------------------------------------------------------------
const float SPIN_ANGLE_FREQ		= 10.0f;
const float BOUNCE_FREQ			= 0.5f;
const float DISPLACEMENT_SPEED	= 40.0f;

void CBigEgg::Think(float _fDeltaT)
{
	// Control angle
	m_fAngle = (m_fTime*SPIN_ANGLE_FREQ*_2PI_);
	m_poGI->Yaw(m_fAngle);
	
	// Control vertical displacement
	// m_oPos.y = m_oIniPos.y + fSin(m_fTime*BOUNCE_FREQ*_2PI_);
	
	// Control horizontal displacement
	m_oPos.x -= (DISPLACEMENT_SPEED*_fDeltaT);
	
	// Update position
	Pos(m_oPos);
}
// ----------------------------------------------------------------------
bool CBigEgg::bDamage(float _fEnergy)
{
return(true);
}
// ----------------------------------------------------------------------