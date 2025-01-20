//-----------------------------------------------------------------------------
#include "CGGameEntity.h"

#include "GameRes/Graphic/CGGraphicInstance.h"
#include "GameRes/Script/CGScriptInstance.h"
#include "GammaE_Collision.h"
//-----------------------------------------------------------------------------
CGString CGGameEntity::sClass()
{
	return ("Unknown Entity");
}
//-----------------------------------------------------------------------------
uint CGGameEntity::uiClass()
{
	static uint uiClassID = uiCRCGenerate( sClass().szString(),sClass().uiLen());
	return ( uiClassID );
}
//-----------------------------------------------------------------------------
CGGameEntity::CGGameEntity() : m_eState(ENTSTATE_NONE), m_uiID(0), m_fTime(0.0f), m_fOTime(0.0f), m_fTimeMult(1.0f), m_poGraph(NULL), m_poCol(NULL), m_poLogic(NULL), m_poLogger(NULL), m_oColor(1,1,1,1)
{
	static uint gsuiID = 0;	

	// Generate a unique identifier	
	m_uiID = gsuiID++;
}
//-----------------------------------------------------------------------------
CGGameEntity::~CGGameEntity()
{
}
//-----------------------------------------------------------------------------
void CGGameEntity::PreThink(float _fDeltaT)
{
	// Perform some actions previous to the game logic step
	m_fOTime   = m_fTime;
	m_fDeltaT  = _fDeltaT * m_fTimeMult;
	m_fTime   += m_fDeltaT;
}
//-----------------------------------------------------------------------------
void CGGameEntity::Think(float _fDeltaT)
{
	// Set the logger for this entity
	if (m_poLogger)
		CGStandardLC::I()->SetLogger( m_poLogger );

	// Execute script logic
	if (m_poLogic)
		m_poLogic->Think(_fDeltaT,this);

	// Update graphics
	if (m_poGraph)
	{
		m_poGraph->SetColor(m_oColor);
		m_poGraph->Update(_fDeltaT);
	}

	// Restore logger
	if (m_poLogger)
		CGStandardLC::I()->SetLogger( NULL );
}
//-----------------------------------------------------------------------------
void CGGameEntity::SwitchToState(TEntityState _eNewState)
{
	OnExitState(m_eState);
	OnEnterState(_eNewState);

	m_eState = _eNewState;
}
//-----------------------------------------------------------------------------
void CGGameEntity::OnEnterState(TEntityState _eState)
{

}
//-----------------------------------------------------------------------------
void CGGameEntity::OnExitState(TEntityState _eState)
{

}
//-----------------------------------------------------------------------------
void CGGameEntity::UpdatePos(const CVect3& _oNewPos)
{
	if (m_poGraph)
	{
		m_poGraph->Pos(_oNewPos);
	}
	/*
	
	DMC: puesto que en paranoid world utilizamos otro tipo de colisionables
	de momento dejamos comentado este código a la espera de una solución decente.

	if (m_poCol)
	{
		m_poCol->OldPos = m_poCol->Pos;
		m_poCol->Pos    = _oNewPos;
	}
	*/
}
//-----------------------------------------------------------------------------
void CGGameEntity::Spawn()
{
	Reset();
	SwitchToState(ENTSTATE_ALIVE);
	Enable();
	if (m_poGraph)	
		m_poGraph->Visible(true);
}
//-----------------------------------------------------------------------------
void CGGameEntity::Reset()
{
	Time(0);
	SwitchToState(ENTSTATE_IDLE);
	Disable();

	if (m_poGraph)	
		m_poGraph->Visible(false);
}
//-----------------------------------------------------------------------------
