//-----------------------------------------------------------------------------
#include "CGameCamera.h"
#include "App/Loop/Game/CGameGlobals.h"
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
	gameGlobals.m_oPerspCam.Pos.V3 ( 0, 0, 20.0f);
 
    gameGlobals.m_oPerspCam.Up.V3  ( 0, 1, 0);
    gameGlobals.m_oPerspCam.Dir.V3 ( 0, 0, -1);
    gameGlobals.m_oPerspCam.Side.CrossProd(gameGlobals.m_oPerspCam.Dir,gameGlobals.m_oPerspCam.Up); 

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
	poGraphicInstance()->Pos( gameGlobals.m_oPerspCam.Pos );

	// Set logic component
	Logic( mNew CGScriptInstance( SCRIPT_PATH + "/" + sClass()+".lua" ) );
	
	// Add smoother for camera movement
	uiAddUserData(mNew CSmoother(0.125));
	// Add smoother for camera movement
	uiAddUserData(mNew CSmoother(0.125));
	// Add smoother for camera movement
	uiAddUserData(mNew CSmoother(0.0125));
}
//-----------------------------------------------------------------------------
void CGameCamera::UpdatePos(const CVect3& _oNewPos)
{
	CGGameEntity::UpdatePos(_oNewPos);
	gameGlobals.m_oPerspCam.Pos = _oNewPos;
}
//-----------------------------------------------------------------------------
void CGameCamera::Think(float _fDeltaT)
{
	CGGameEntity::Think(_fDeltaT);
}
//-----------------------------------------------------------------------------

