//-----------------------------------------------------------------------------
#include "CGameCamera.h"
#include "App/Loop/Game/CGameGlobals.h"
#include "CPlayer.h"
//-----------------------------------------------------------------------------
CGameCamera::CGameCamera()
{

}
//-----------------------------------------------------------------------------
CGameCamera::~CGameCamera()
{

}
//-----------------------------------------------------------------------------
void CGameCamera::Init()
{
	gameGlobals.m_oPerspCam.SetPos( 0, 0, 0);

	CGVect3 oUp(0,1,0);
	CGVect3 oDir(0, 0, -1);
	CGVect3 oSide;
	oSide.CrossProd(oDir, oUp);
    gameGlobals.m_oPerspCam.SetVectors(oDir, oUp, oSide);

	gameGlobals.m_oPerspPrj.ePrjType	= E3D_PT_Perspective;
	gameGlobals.m_oPerspPrj.fFOV		= 45.0f;
	gameGlobals.m_oPerspPrj.fNear		= 1.0f;
	gameGlobals.m_oPerspPrj.fFar		= 2000.0f;

	gameGlobals.m_oCamera.SetViewport (&gameGlobals.m_oViewport);
	gameGlobals.m_oCamera.SetCamera   (&gameGlobals.m_oPerspCam);
	gameGlobals.m_oCamera.SetProjector(&gameGlobals.m_oPerspPrj);
	
	CGGameEntityMgr::I()->uiRegister(this);

	// Set graphic instance ... (invisible)
	GraphicInstance( mNew CGGraphicInstance() );	
	poGraphicInstance()->Pos( gameGlobals.m_oPerspCam.oGetPos() );

	// Set logic component
	// Logic( mNew CGScriptInstance( SCRIPT_PATH + "/" + sClass()+".lua" ) );
	
	// Add smoother for camera movement
	uiAddUserData(mNew CGSmoother(0.125));
	// Add smoother for camera movement
	uiAddUserData(mNew CGSmoother(0.125));
	// Add smoother for camera movement
	uiAddUserData(mNew CGSmoother(0.0125));
}
//-----------------------------------------------------------------------------
void CGameCamera::UpdatePos(const CGVect3& _oNewPos)
{
	CGGameEntity::UpdatePos(_oNewPos);
	gameGlobals.m_oPerspCam.SetPos(_oNewPos);
}
//-----------------------------------------------------------------------------
void CGameCamera::Think(float _fDeltaT)
{
	CGVect3 oOffset(3.0f,2.0f,0.0f);
	CGVect3 oPlayerPos = gameGlobals.m_poPlayer->poGraphicInstance()->oPos();

	gameGlobals.m_oPerspCam.SetPos(oPlayerPos.x + oOffset.x, oPlayerPos.y + oOffset.y, 10.0f);
	
	CGVect3 oTargetPos = gameGlobals.m_oPerspCam.oGetPos();
	oTargetPos.z = 0.0f;

	gameGlobals.m_oPerspCam.LookAt( oTargetPos );

	CGGameEntity::Think(_fDeltaT);
}
//-----------------------------------------------------------------------------

