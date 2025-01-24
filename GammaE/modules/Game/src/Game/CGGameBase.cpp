// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
#include "CGGameBase.h"
#include "Entities/CGGameEntityMgr.h"
// -----------------------------------------------------------------------------
CGGameBase::CGGameBase()
{
    m_uiGMode = 0;
    m_uiLevel = 0;
    m_uiSkill = 0;
    m_uiState = 0;
    m_uiFrame = 0;
    m_fTime = 0;
    m_poGM = NULL;
}
// -----------------------------------------------------------------------------
void CGGameBase::Init(uint _uiGMode,uint _uiLevel,uint _uiSkill)
{
    m_uiGMode = _uiGMode;
    m_uiLevel = _uiLevel;
    m_uiSkill = _uiSkill;
}
// -----------------------------------------------------------------------------
void CGGameBase::Finish()
{
    if ( m_poGM != NULL )
    {
        m_poGM->Finish();

        mDel m_poGM;
        m_poGM = NULL;
    }
}
// -----------------------------------------------------------------------------
void CGGameBase::Think(float& _fDeltaT)
{
    bool bGamePaused = false;

    if ( m_poGM )
        bGamePaused = (m_poGM->eState() == GM_STATE_PAUSED) || (m_poGM->eState() == GM_STATE_FINISH);

    if ( !bGamePaused )
    {
        CGGameEntityMgr::I()->Think(_fDeltaT);
    }

    if ( bGamePaused )
        _fDeltaT = 0.0f;

    if ( m_poGM )
        m_poGM->Think(_fDeltaT);
}
// -----------------------------------------------------------------------------
void CGGameBase::Render()
{
}
// -----------------------------------------------------------------------------
void CGGameBase::Reset()
{
}
// -----------------------------------------------------------------------------
