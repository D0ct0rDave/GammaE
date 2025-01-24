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
#include "CGGameCommandInterpreter.h"
#include "CGGCICommand.h"
#include "CGGCIStdCommands.h"
// -----------------------------------------------------------------------------
CGGameCommandInterpreter::CGGameCommandInterpreter()
{
    m_iLastCurX = 0;
    m_iLastCurY = 0;
    m_fTime = 0.0f;
    m_fDelayTime = 0.0f;
    m_eCIState = CIS_Running;
    m_sPrompt = "";

    RegisterCommand( mNew CGGCICommandHelp ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandExec ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandNop  ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandEcho ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandDelay( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandCls  ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandSet  ( (CGGameCommandInterpreter*)this ) );
    RegisterCommand( mNew CGGCICommandBind ( (CGGameCommandInterpreter*)this ) );
}
// -----------------------------------------------------------------------------
CGGameCommandInterpreter::~CGGameCommandInterpreter()
{
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::Think (float fDelta)
{
    if ( !poConsole ) return;
    CGGameConsoleApp::Think(fDelta);

    // if (eGameAppState() == GAPPST_CLOSED) return;

    switch ( m_eCIState )
    {
        case CIS_Running:
        {
            if ( m_oInstLst.uiNumElems() )
            {
                CGString oLine = m_oInstLst[0];
                m_oInstLst.Del(0);

                ProcessInstruction( (char*)oLine.szString() );
            }
            else
            {
                ShowPrompt();
                m_eCIState = CIS_Ready;
            }
        }
        break;

        case CIS_Delay:
        {
            m_fDelayTime -= fDelta;
            if ( m_fDelayTime <= 0.0f )
            {
                m_fDelayTime = 0.0f;
                m_eCIState = CIS_Running;
            }
        }
        break;

        case CIS_Ready:
        {
            if ( m_oInstLst.uiNumElems() )
                m_eCIState = CIS_Running;
        }
        break;
    }

    ShowCursor();
    m_fTime += fDelta;
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::ProcessInstruction(char* _szCmdLine)
{
    if ( _szCmdLine == NULL ) return;

    char* szToken = ParseUtils_ParseToken(_szCmdLine);

    bool bFound = false;
    for ( uint i = 0; i < m_poCmds.uiNumElems(); i++ )
    {
        if ( CGString(szToken) |= m_poCmds[i]->sCommand() )
        {
            m_eCIState = m_poCmds[i]->Exec( CGString(_szCmdLine) );
            bFound = true;
        }
    }

    if ( !bFound )
    {
        Print("Comando desconocido.\n"
              "Escribe HELP para obtener un listado completo de comandos válidos.\n\n");

        ShowPrompt();
        m_eCIState = CIS_Ready;
    }
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::ReceiveChar(int _iKey)
{
    /*
       if (m_eCIState == CIS_Ready)
       {
        CGGameConsoleApp::ReceiveChar(_iKey);
        CGGameConsoleApp::Type(_iKey);
       }
     */

    if ( m_eCIState == CIS_Ready )
    {
        CGGameConsoleApp::ReceiveChar(_iKey);
        int iCurIdx = m_sLine.uiLen();

        switch ( _iKey )
        {
            case  '\r':
            {
                poConsole->SetChar(m_iLastCurX,m_iLastCurY,' ');
                Type('\n');
            }
            break;

            case 8:
            {
                if ( iCurIdx > 0 )
                {
                    poConsole->SetChar(m_iLastCurX,m_iLastCurY,' ');

                    Type(8);
                }
            }
            break;

            case '\t':
            {
                while ( iCurIdx > 0 )
                {
                    poConsole->SetChar(m_iLastCurX,m_iLastCurY,' ');

                    Type(8);

                    iCurIdx--;
                }

                for ( int i = 0; i < m_sLastCommand.uiLen(); i++ )
                    Type(m_sLastCommand[i]);

                m_iLastCurX = m_iCurX;
                m_iLastCurY = m_iCurY;
            }
            break;

            default:
            {
                Type(_iKey);
                m_iLastCurX = m_iCurX;
                m_iLastCurY = m_iCurY;
            }
        }
    }
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::ShowCursor()
{
    if ( ( (int)m_fTime & 0x01 ) == 0 )
    {
        poConsole->SetChar(m_iLastCurX,m_iLastCurY,' ');
    }
    else
    {
        m_iLastCurX = m_iCurX;
        m_iLastCurY = m_iCurY;

        poConsole->SetChar(m_iCurX,m_iCurY,'_');
    }
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::ShowPrompt()
{
    if ( m_sPrompt.uiLen() > 0 )
        Print( m_sPrompt.szString() );
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::RegisterCommand(CGGCICommand* _poCmd)
{
    m_poCmds.uiAdd(_poCmd);
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::AddInstruction(const CGString& _oString)
{
    m_oInstLst.uiAdd(_oString);
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::SetDelayTime(float _fTime)
{
    m_fDelayTime = _fTime;
}
// -----------------------------------------------------------------------------
void CGGameCommandInterpreter::Exec(const CGString& _sCommand)
{
    m_oInstLst.uiAdd(_sCommand);
}
// -----------------------------------------------------------------------------
