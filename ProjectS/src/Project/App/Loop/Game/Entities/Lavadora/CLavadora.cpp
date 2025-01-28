//-----------------------------------------------------------------------------
#include "CLavadora.h"
#include "App/Loop/Game/CGameGlobals.h"
#include "Collision/CGGEntityCollisionMgr.h"
#include "Collision/CGColliderResourceWH.h"
#include "Collision/CGColliderInstance.h"
//-----------------------------------------------------------------------------
CLavadora::CLavadora()
{

}
//-----------------------------------------------------------------------------
CLavadora::~CLavadora()
{

}
//-----------------------------------------------------------------------------
void CLavadora::Init()
{
	// Load model
	CGGraphicInstance* poLavadora = mNew CGGraphicInstance("data/actors/lavadora.gem");

	CGVect3 oPos = gameGlobals.m_poPlayer->poGraphicInstance()->oPos();
	oPos.x += 3;
	oPos.y  = 0;

	poLavadora->Scale(0.01f);
	poLavadora->Pos( oPos );
	poLavadora->Pitch(_PI2_);
	poLavadora->Yaw(_PI_);
	poLavadora->Roll(_PI_);

	CGSceneAnimCfg* poAnimCfg = (CGSceneAnimCfg*)poLavadora->poGraphicResource()->poModel(); // CGModelWH::I()->poGetModel("data/actors/lavadora.gem");
	poAnimCfg->FrameAnim[0].FinalFrame   = 9;
	poAnimCfg->FrameAnim[0].InitialFrame = 0;
	uint uiFrames = (poAnimCfg->FrameAnim[0].FinalFrame -  poAnimCfg->FrameAnim[0].InitialFrame);
	poAnimCfg->FrameAnim[0].TotalTime = (poAnimCfg->FrameAnim[0].FinalFrame - poAnimCfg->FrameAnim[0].InitialFrame) / 30.0f;
	poAnimCfg->FrameAnim[0].FrameTime = poAnimCfg->FrameAnim[0].TotalTime / (float)uiFrames;

	poLavadora->poGraphicResource()->Model(poAnimCfg);
	GraphicInstance( poLavadora);	

	CGGameEntityMgr::I()->uiRegister(this);

	// Set logic component
	Logic( mNew CGScriptInstance( SCRIPT_PATH + "/" + sClass()+".lua" ) );

	// Create a collision structure
	CGColliderInstance* poCI = mNew CGColliderInstance("data/actors/lavadora.gem");
	poCI->m_fScale = 1.0f;
	poCI->m_oPos   = CGVect3::oZero();
	poCI->m_oOldPos= CGVect3::oZero();

	// Composite object
	Collider((CCOL_Collider*)poCI);

	// Setup this global variable
	CGGameRegistry::I()->uiAddVar( "Lavadora", this );

	// Setup initial state
	Reset();

	//
	Spawn();
	
	m_eState = ENTSTATE_ALIVE;
}
//-----------------------------------------------------------------------------
void CLavadora::UpdatePos(const CGVect3& _oNewPos)
{
	CGGameEntity::UpdatePos(_oNewPos);
	gameGlobals.m_oPerspCam.Pos = _oNewPos;
}
//-----------------------------------------------------------------------------
void CLavadora::Think(float _fDeltaT)
{
	CGVect3 oNewPos = poGraphicInstance()->oPos();
	oNewPos.y +=  -9.8f*_fDeltaT;
	
	if (oNewPos.y < GROUND_HEIGHT)
		oNewPos.y = GROUND_HEIGHT;	

	poGraphicInstance()->Pos(oNewPos);

	CGGameEntity::Think(_fDeltaT);
}
//-----------------------------------------------------------------------------

