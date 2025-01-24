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
#include "Entities/CommandInterpreter/CGGameApplication.h"
#include "Entities/CGGameEntityMgr.h"
#include "Entities/CGGEntityRenderMgr.h"
#include "GameRes/Graphic/CGGraphicInstance.h"
// -----------------------------------------------------------------------------
CGGameApplication::CGGameApplication()
{
    m_fSize = 0.0f;
    m_fSecs = 0.5f;
    m_eGAState = GAPPST_CLOSED;
    // -----------------------------------------------------------------------------

    m_sLine = "";
    m_sLastCommand = "";
}
// -----------------------------------------------------------------------------
CGGameApplication::~CGGameApplication()
{
}
// -----------------------------------------------------------------------------
void CGGameApplication::Init()
{
    CGGameEntityMgr::I()->uiRegister( this );
}
// -----------------------------------------------------------------------------
void CGGameApplication::Think (float _fDeltaT)
{
    if ( m_eGAState == GAPPST_CLOSED ) return;

    // -----------------------------------------------------------------------------
    switch ( m_eGAState )
    {
        case GAPPST_OPENING:    m_fSize += (CGRenderer::I()->REStats.DTime / m_fSecs);
        if ( m_fSize >= 1.0f )
        {
            FullOpen();
        }
        break;

        case GAPPST_CLOSING:    m_fSize -= (CGRenderer::I()->REStats.DTime / m_fSecs);
        if ( m_fSize <= 0.0f )
        {
            FullClose();
        }
        break;
    }
}
// -----------------------------------------------------------------------------
void CGGameApplication::Toggle()
{
    if ( (m_eGAState == GAPPST_OPENING) || (m_eGAState == GAPPST_OPEN) )
        m_eGAState = GAPPST_CLOSING;
    else
        m_eGAState = GAPPST_OPENING;

    if ( poGraphicInstance() )
        poGraphicInstance()->Visible(true);
}
// -----------------------------------------------------------------------------
void CGGameApplication::ReceiveChar(int _iKey)
{
    if ( _iKey != 13 )
    {
        if ( _iKey == 8 )
        {
            if ( m_sLine.uiLen() )
                m_sLine = m_sLine.SubString(0,m_sLine.uiLen() - 1);
        }
        else
        if ( _iKey == '\t' )
        {
            m_sLine = m_sLastCommand;
        }
        else
        {
            m_sLine += CGString( (char)_iKey );
        }
    }
    else
    {
        m_sLastCommand = m_sLine;
        m_sLine = "";

        Exec( m_sLastCommand );
    }
}
// -----------------------------------------------------------------------------
void CGGameApplication::FullOpen()
{
    m_eGAState = GAPPST_OPEN;
    m_fSize = 1.0f;

    if ( poGraphicInstance() )
        poGraphicInstance()->Visible(true);
}
// -----------------------------------------------------------------------------
void CGGameApplication::FullClose()
{
    m_eGAState = GAPPST_CLOSED;
    m_fSize = 0.0f;

    if ( poGraphicInstance() )
        poGraphicInstance()->Visible(false);
}
// -----------------------------------------------------------------------------
void CGGameApplication::Exec(const CGString& _sCommand)
{
}
// -----------------------------------------------------------------------------
