// -----------------------------------------------------------------------------
#include "CEnemy.h"
#include "App/Loop/Game/Entities/EntityIDS.h"
#include "Collision/CGGEntityCollisionMgr.h"
#include "Collision/CGColliderResourceWH.h"
#include "Collision/CGColliderInstance.h"
#include "App/Loop/Game/GameUtils/Explosions/CExplosionMgr.h"
// -----------------------------------------------------------------------------
CEnemy::CEnemy()
{
}
// -----------------------------------------------------------------------------
CEnemy::~CEnemy()
{
}
// -----------------------------------------------------------------------------
void CEnemy::Init(float _fEnergy,const CVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,const CGString& _sPath,float _fScale)
{
	CGPathResource* poPathRes = NULL;
	if (_sPath != "")
		poPathRes = CGPathResourceWH::I()->poFind(_sPath);

	if (poPathRes != NULL)
		Init(_fEnergy,_oPos,_sAIScript,_sGraphicRes,poPathRes->poGetPath(),_fScale);
	else
		Init(_fEnergy,_oPos,_sAIScript,_sGraphicRes,NULL,_fScale);
}
// -----------------------------------------------------------------------------
void CEnemy::Init(float _fEnergy,const CVect3& _oPos,const CGString& _sAIScript,const CGString& _sGraphicRes,CGPath* _poPath,float _fScale)
{
	m_fInitialEnergy = _fEnergy;

	// Get the graphic instance	
	if (_sGraphicRes != "") 
	{
		GraphicInstance( mNew CGGraphicInstance( _sGraphicRes ) );
		poGraphicInstance()->Scale( _fScale );
	}

	// Get the IA instance
	if (_sAIScript != "") 
		Logic( mNew CGScriptInstance(_sAIScript) );

	// Set path...
	SetPath( _poPath );

	// Create a collision structure
	CGColliderInstance* poCI = mNew CGColliderInstance(_sGraphicRes);
	poCI->m_fScale = _fScale;
	poCI->m_oPos   = CVect3::oZero();
	poCI->m_oOldPos= CVect3::oZero();

	// Composite object
	Collider((CCOL_Collider*)poCI);

	// Initialize the entity
	m_oOffsetPos = _oPos;
	SetEnergy(_fEnergy);

	// Add entity to the entity manager
	m_uiGID = CGGameEntityMgr::I()->uiRegister(this);

	// 
	Reset();
}
// -----------------------------------------------------------------------------
CVect3 CEnemy::oGetPos(float _fTime)
{
	CVect3 oPos(0,0,0);

	if (m_poPath)
		oPos = m_poPath->oPos(_fTime);

	oPos.Add(m_oOffsetPos);
	
	// Paths are exported from path editor. Coordinates are in screen position.
	// Normalize position and scale appropriately.
	oPos.x = 1.3f * 7.5f * ((oPos.x/640.0f)*2.0f - 1.0f);
	oPos.y = 1.0f * 7.5f * ((oPos.y/480.0f)*2.0f - 1.0f);		
	oPos.z = 0.0f;
	
	return(oPos);
}
// -----------------------------------------------------------------------------
void CEnemy::Move(float _fDeltaT)
{
	// Deactivate it in case
	if (fTime() > m_poPath->fTime())
	{
		Reset();
	}
	else
	{
		UpdatePos( oGetPos( fTime() ) );
	}
}
// -----------------------------------------------------------------------------
void CEnemy::UpdatePos(const CVect3& _oNewPos)
{
	CGGameEntity::UpdatePos(_oNewPos);

	CGColliderInstance* poCol = (CGColliderInstance*)poCollider();
	poCol->m_oOldPos = poCol->m_oPos;
	poCol->m_oPos	 = _oNewPos;
}
// -----------------------------------------------------------------------------
void CEnemy::Reset()
{
	CGGameEntity::Reset();
	UpdatePos( oGetPos( 0.0f ) );
	SetEnergy(m_fInitialEnergy);
}
// -----------------------------------------------------------------------------
void CEnemy::Think(float _fDeltaT)
{
	CGGameEntity::Think(_fDeltaT);

	if (poGetPath())
		Move(_fDeltaT);
}
// -----------------------------------------------------------------------------
void CEnemy::Kill()
{
	CGColliderInstance* poCol = (CGColliderInstance*)poCollider();
	CExplosionMgr::AddExplosion(ET_ENEMYGENERIC,poCol->m_oPos);
}
// -----------------------------------------------------------------------------
