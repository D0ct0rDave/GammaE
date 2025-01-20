// ----------------------------------------------------------------------
#include "CGMHMinimap.h"
#include "Loop/Game/CGameGlobals.h"
// ----------------------------------------------------------------------
CGMHMinimap::CGMHMinimap()
{
}
// -----------------------------------------------------------------------------
void CGMHMinimap::Init(CGMHLevel* _poLevel,CHUDScene*  _poHScn)
{
	m_poLevel = _poLevel;
	m_poHScn  = _poHScn;
	
	if (! m_poLevel->m_poMinimap) return;

	
	// Minimap
	m_poMiniMap = pNew CHUDIcon;
	m_poMiniMap->m_fColor[0]	= 1.0f;
	m_poMiniMap->m_fColor[1]	= 1.0f;
	m_poMiniMap->m_fColor[2]	= 1.0f;
	m_poMiniMap->m_fColor[3]	= 0.75f;
	m_poMiniMap->m_fScale		= 0.5f;
	m_poMiniMap->m_fSeqTime		= 0.0f;
	m_poMiniMap->m_fXPos		= 0.6f;
	m_poMiniMap->m_fYPos		= -0.5f;
	m_poMiniMap->m_poTex		= m_poLevel->m_poMinimap;
	m_poMiniMap->m_uiXFrames	= 1;
	m_poMiniMap->m_uiYFrames	= 1;
	m_poMiniMap->Enable();
	m_poMiniMap->Init();
	m_poHScn->iAddObj(m_poMiniMap);

	// For each rock in the map, create an icon
	/*
	int ic;

	m_poRIcos = pNew CHUDIcon[m_poLevel->m_oSV.m_uiTotalRocks];
	for (ic=0;ic<m_poLevel->m_oSV.m_uiTotalRocks;ic++)
	{
		m_poRIcos[ic].m_fColor[0]		= m_poRIcos[ic].m_fColor[1] = m_poRIcos[ic].m_fColor[2] = m_poRIcos[ic].m_fColor[3] = 1.0f;
		m_poRIcos[ic].m_fScale			= 1.0f;
		m_poRIcos[ic].m_fSeqTime		= 0.0f;
		m_poRIcos[ic].m_fXPos			= 0.0f;
		m_poRIcos[ic].m_fYPos			= 0.0f;
		m_poRIcos[ic].m_poTex			= CDMCTexMgr::poLoad("data/GameMode/History/HUD/Textures/MiniMap/ic_rock.tga");
		m_poRIcos[ic].m_uiXFrames		= 1;
		m_poRIcos[ic].m_uiYFrames		= 1;
		m_poRIcos[ic].Init();
		m_poRIcos[ic].Enable();
		
		m_poHScn->iAddObj( &m_poRIcos[ic] );
	}
	*/

	// Goal
	/*
	m_poGIco = pNew CHUDIcon;	
	m_poGIco->m_fColor[0]		= m_poGIco->m_fColor[1] = m_poGIco->m_fColor[2] = m_poGIco->m_fColor[3] = 1.0f;
	m_poGIco->m_fScale			= 1.0f;
	m_poGIco->m_fSeqTime		= 0.0f;
	m_poGIco->m_fXPos			= 0.0f;
	m_poGIco->m_fYPos			= 0.0f;
	m_poGIco->m_poTex			= CDMCTexMgr::poLoad("data/GameMode/History/HUD/Textures/MiniMap/ic_goal.tga");
	m_poGIco->m_uiXFrames		= 1;
	m_poGIco->m_uiYFrames		= 1;
	m_poGIco->Init();
	m_poGIco->Enable();
	m_poHScn->iAddObj(m_poGIco  );
	*/
	m_bEnableGoal = false;


	// Player: should be the last icon to be added
	m_poPIco = pNew CHUDIcon;
	m_poPIco->m_fColor[0]		= m_poPIco->m_fColor[1] = m_poPIco->m_fColor[2] = m_poPIco->m_fColor[3] = 1.0f;
	m_poPIco->m_fScale			= 1.0f;
	m_poPIco->m_fSeqTime		= 0.0f;
	m_poPIco->m_fXPos			= 0.0f;
	m_poPIco->m_fYPos			= 0.0f;
	m_poPIco->m_poTex			= CDMCTexMgr::poLoad("data/GameMode/History/HUD/Textures/MiniMap/ic_player.tga");
	m_poPIco->m_uiXFrames		= 1;
	m_poPIco->m_uiYFrames		= 1;
	m_poPIco->Init();
	m_poPIco->Enable();
	m_poHScn->iAddObj(m_poPIco	);

	// Precomputed variables
	/*
	if (! bIsPowerOf2(m_poLevel->m_poMap->m_iCols))
		m_fPseudoXTiles = 1 << (iLog2(m_poLevel->m_poMap->m_iCols)+1);
	else
		m_fPseudoXTiles = m_poLevel->m_poMap->m_iCols;

	if (! bIsPowerOf2(m_poLevel->m_poMap->m_iRows))
		m_fPseudoZTiles = 1 << (iLog2(m_poLevel->m_poMap->m_iRows)+1);
	else
		m_fPseudoZTiles = m_poLevel->m_poMap->m_iRows;
	*/
}
// --------------------------------------------------------
void CGMHMinimap::Finish()
{
}
// --------------------------------------------------------
void CGMHMinimap::Reset()
{
}
// --------------------------------------------------------
MTH_CPoint3 CGMHMinimap::oGetMiniMapPos(MTH_CPoint3& _oWorldPos)
{
	if (! m_poMiniMap) return(MTH_CPoint3 (0,0,0));

	// Player position en tanto por 1
	float fPXPos = _oWorldPos.x;/* / (0.5f*m_fPseudoXTiles*TILE_BLOCK_WIDTH );*/
	float fPZPos = _oWorldPos.z;/* / (0.5f*m_fPseudoZTiles*TILE_BLOCK_HEIGHT);*/

	// Get minimap icon coords
	MTH_CPoint3 oPos;
	oPos.x = m_poMiniMap->m_fXPos + ( fPXPos * m_poMiniMap->m_fXScale * m_poMiniMap->m_fScale);
	oPos.y = m_poMiniMap->m_fYPos - ( fPZPos * m_poMiniMap->m_fYScale * m_poMiniMap->m_fScale);	
	
	return(oPos);
}
// --------------------------------------------------------
void CGMHMinimap::Think(float _fDeltaT)
{
	if (! m_poMiniMap) return;

	// Obtener las coordenadas del icono del jugador en espacio de minimapa
	MTH_CPoint3 oMPos;

	// Player position
	oMPos = oGetMiniMapPos(gpoPlayer[0]->m_oPos);
	m_poPIco->m_fXPos		= oMPos.x;
	m_poPIco->m_fYPos		= oMPos.y;
	
	// Rock positions
	/*
	for (int ic=0;ic<m_poLevel->m_oSV.m_uiTotalRocks;ic++)
	{
		if (m_poLevel->m_poRocks[ic].m_bVisible)
		{
			oMPos = oGetMiniMapPos(m_poLevel->m_poRocks[ic].m_oPos);

			m_poRIcos[ic].m_fXPos = oMPos.x;
			m_poRIcos[ic].m_fYPos = oMPos.y;

			m_poRIcos[ic].Enable();
		}
		else
		{
			m_poRIcos[ic].Disable();
		}
	}
	
	// Goal
	if (m_bEnableGoal)
	{
		m_poGIco->Enable();
	
		oMPos = oGetMiniMapPos(m_poLevel->m_poGoal->m_oPos);

		m_poGIco->m_fXPos = oMPos.x;
		m_poGIco->m_fYPos = oMPos.y;

		m_poGIco->m_fScale = 1.0f + fSin(gfGlobalTime*1.0f*_2PI_)*0.05f;
	}
	else
		m_poGIco->Disable();
	*/
}
// --------------------------------------------------------