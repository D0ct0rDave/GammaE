// -----------------------------------------------------------------------------
#include "CActor.h"
#include "Loop/Map/CMap.h"
#include "Loop/Game/CGameGlobals.h"
#include "Loop/Game/Ents/CEntityMgr.h"
#include "Loop/EntRend/CEntRend.h"
#include "Loop/Game/Ents/CEntCollision.h"
#include "Loop/Game/Ents/CRock.h"
#include "Loop/Shadow/CShadowMgr.h"
#include "Loop/Game/Ents/CActorMgr.h"
// -----------------------------------------------------------------------------
void CActor::SetActorState(int _iState)
{
	if (_iState != m_eState)
	{
		m_eState = (TEntityState)_iState;
		_iState  = (int)_iState - (int)m_iBaseState;

		m_poGI->m_poModel->AnimRestart();
		m_poGI->m_poModel->AnimStop();
		m_poGI->m_poModel->m_poSkeLst[0].bSetCurrAnim ( m_oASt[_iState].iAnim );
		m_poGI->m_poModel->m_poSkeLst[0].SetCyclicMode( m_oASt[_iState].bCycl );
		m_poGI->m_poModel->AnimPlay();

		// Tiempo de la animación
		m_fTime = m_poGI->m_poModel->m_poSkeLst[0].poGetAnim()->m_poSource->fGetTotalTime();
		
		m_iAnimState = _iState;
	}
}
// -----------------------------------------------------------------------------
void CActor::SetAnimPars(int _iState,bool _bCycle,int _iAnimState)
{
	m_oASt[_iState-(int)m_iBaseState].bCycl = _bCycle;
	m_oASt[_iState-(int)m_iBaseState].iAnim = _iAnimState;
}
// -----------------------------------------------------------------------------
CActor::CActor()
{
	m_bColl      = true;
	m_fRollAngle = 0.0f;
	m_poCI       = NULL;
}
// -----------------------------------------------------------------------------
CActor::~CActor()
{
}
// -----------------------------------------------------------------------------
#define SQ(a) ((a)*(a))
void CActor::Init(MTH_CPoint3& _oPos,char *_szModel,char* _szActorName,bool _bAddEntity)
{
	// Load model
	m_poGI = pNew GEOM_Instance( C3DObjWH::poGetObj( _szModel ) );

	// Setup startup position
	m_oIniPos = _oPos;
	m_oPos    = m_oIniPos;
	m_oOPos   = m_oIniPos;	
	m_poGI->SetPosition(_oPos);

	// Add entity to the entity manager
	if (_bAddEntity)
		CEntityMgr::iAddEntity(this);

	// Add to render entities
	m_iRI = CEntRend::iAdd(this);

	// Register actor
	CActorMgr::iRegister(_szActorName,this);

	// Get radius
/*
	m_fRadius = fMin(fMin ((m_poGI->m_poModel->m_fBBXMax - m_poGI->m_poModel->m_fBBXMin)*0.5f, 
					       (m_poGI->m_poModel->m_fBBYMax - m_poGI->m_poModel->m_fBBYMin)*0.5f),
					  	   (m_poGI->m_poModel->m_fBBZMax - m_poGI->m_poModel->m_fBBZMin)*0.5f);
*/

	// Register Actor shadow
	CShadowMgr::iAddEntity(this,NULL);

	// Set Actor Initital State
	SetActorState(m_iBaseState + 0);
	
	SetVisible(true);
}
// -----------------------------------------------------------------------------
bool CActor::bCheckNewPos(float _fDeltaT,unsigned int _uiCollEnts)
{
	MTH_CPoint3 oSpd = m_oSpd;
	float       fLen = oSpd.fGetLength();

	// If there has not been any movement return
	if (bEq(fLen,0.0f)) return(false);

	// Initialize collision info
	m_poCI = NULL;


	// -----------------------
	// Setup new player orientation
	// -----------------------	
	// Obtener ángulo de orientacion, en funcion de las entradas
	// Obtener matriz que rota ese angulo alrededor de (0,1,0)
	// colocar dicha matriz
	MTH_CPoint3 oDir = oSpd * (1.0f / fLen);
	m_fOrAngle = atan2(oDir.x,oDir.z);


	// -----------------------
	// Set new actor position
	// -----------------------

	// Decompose movement in 2 steps horizontal/vertical movement			
	{
		// Horizontal
		if (! bEq(oSpd.x,0.0f))
		{
			m_oPos.x = m_oOPos.x + oSpd.x*_fDeltaT;
	
			m_poCI = CEntCollision::poCheckCollision(this,_uiCollEnts);

			if ((m_poCI) && (m_bColl))
			{
				m_oPos.x = m_oOPos.x;
				oSpd.x   = 0.0f;
			}
		}

		// Vertical
		if (! bEq(oSpd.z,0.0f))
		{
			m_oPos.z = m_oOPos.z + oSpd.z*_fDeltaT;
		
			m_poCI = CEntCollision::poCheckCollision(this,_uiCollEnts);

			if ((m_poCI) && (m_bColl))
			{
				m_oPos.z = m_oOPos.z;
				oSpd.z   = 0.0f;
			}
		}
		
		// Height
		if (! bEq(oSpd.y,0.0f))
		{
			m_oPos.y = m_oOPos.y + oSpd.y*_fDeltaT;
		
			m_poCI = CEntCollision::poCheckCollision(this,_uiCollEnts);

			if ((m_poCI) && (m_bColl))
			{
				m_oPos.y = m_oOPos.y;
				oSpd.y   = 0.0f;
			}
		}
	}

	m_oSpd = oSpd;
	return( oSpd.fGetSqLenght() > 0.0f );
}
// -----------------------------------------------------------------------------
unsigned int CActor::uiCheckMovements(unsigned int _uiTestMVFlags,float _fXOfs,float _fZOfs,unsigned int _uiCollEnts)
{
	// Clear movement flags
	unsigned int uiNMFlags = 0;
	
	TCollisionInfo *poInfo;
	MTH_CPoint3 oCurPos = m_oPos;

		// moving horizontally
		if (_uiTestMVFlags & MF_LEFT)
		{
			m_oPos  += MTH_CPoint3(_fXOfs,0,0);
			poInfo   = CEntCollision::poCheckCollision(this,_uiCollEnts);
			m_oPos   = oCurPos;

			if (! poInfo) uiNMFlags |= MF_LEFT;
		}
		
		if (_uiTestMVFlags & MF_RIGHT)
		{
			m_oPos  -= MTH_CPoint3(_fXOfs,0,0);
			poInfo   = CEntCollision::poCheckCollision(this,_uiCollEnts);
			m_oPos   = oCurPos;

			if (! poInfo) uiNMFlags |= MF_RIGHT;
		}

		if (_uiTestMVFlags & MF_UP)
		{
			// moving vertically
			m_oPos  += MTH_CPoint3(0,0,_fZOfs);
			poInfo   = CEntCollision::poCheckCollision(this,_uiCollEnts);
			m_oPos   = oCurPos;
			
			if (! poInfo) uiNMFlags |= MF_UP;
		}
		
		if (_uiTestMVFlags & MF_DOWN)
		{
			m_oPos  -= MTH_CPoint3(0,0,_fZOfs);
			poInfo   = CEntCollision::poCheckCollision(this,_uiCollEnts);
			m_oPos   = oCurPos;

			if (! poInfo) uiNMFlags |= MF_DOWN;
		}

	return(uiNMFlags);
}
// -----------------------------------------------------------------------------
void CActor::Think()
{
	if ((m_eState == ENTSTATE_INACTIVE) || (m_eState == ENTSTATE_DEAD) || (m_eState == ENTSTATE_NONE)) return;

	// Setup orientation and position

	// Esto suaviza la animación del giro, a cambio, se produce una discontinuidad 
	// bastante grave al pasar de 0 a 2PI o similar.
	// float fAng = m_oAvg.fAverager(_fDeltaT,m_fOrAngle,0.125f);
	// m_poFrame->m_oMatrix.RotateY(m_fOrAngle*(180.0f/_PI_));
	
	m_poGI->SetAngles(0.0f,m_fOrAngle,m_fRollAngle);

	// Set new player position	
	m_poGI->SetPosition(m_oPos);
}
// -----------------------------------------------------------------------------
void CActor::Restart()
{			
	// Set player position.
	m_oPos    = m_oIniPos;
	m_oOPos	  = m_oIniPos;
	m_eState  = (TEntityState)m_iBaseState;	
}
// -----------------------------------------------------------------------------