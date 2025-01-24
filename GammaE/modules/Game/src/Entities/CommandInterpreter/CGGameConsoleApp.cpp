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
#include "CGGameConsoleApp.h"
#include "GameRes/Graphic/CGGraphicInstance.h"
// -----------------------------------------------------------------------------
#define MAX_CONSOLE_ROWS        40
#define MAX_CONSOLE_COLS        80
// -----------------------------------------------------------------------------
CGGameConsoleApp::CGGameConsoleApp()
{
}
// -----------------------------------------------------------------------------
CGGameConsoleApp::~CGGameConsoleApp()
{
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::Init()
{
    Init(MAX_CONSOLE_ROWS,MAX_CONSOLE_COLS);
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::Init(int _iCols,int _iRows)
{
    m_iCols = _iCols;
    m_iRows = _iRows;

    // -----------------------------------------------------------------------------
    CGraphBV_Manager::SetBVMode(eGraphBV_Box);
    poConsole = mNew CConsole();
    CE3D_Shader* poMBack = CE3D_ShaderWH::I()->poCreateShader("console_back_default");
    CE3D_Shader* poMFont = CE3D_ShaderWH::I()->poCreateShader("console_font_default");
    poConsole->Init(1.0f,1.0,m_iCols,m_iRows,poMBack,poMFont);
    poConsole->ComputeBoundVol();

    // Sets up the graphic instance for this entity
    GraphicInstance( mNew CGGraphicInstance( mNew CGGraphicResource(poConsole) ) );

    m_pucBuff = (char*)mAlloc(m_iCols * m_iRows);
    memset(m_pucBuff,' ',m_iCols * m_iRows);

    m_iCurX = 0;
    m_iCurY = 0;

    CGGameApplication::Init();

    FullOpen();
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::Print(const char* _szFmt,...)
{
    char szString[1024];

    va_list argptr;
    va_start(argptr,_szFmt);
    vsprintf(szString,_szFmt,argptr);
    va_end  (argptr);

    int iLen = strlen(szString);

    for ( int i = 0; i < iLen; i++ )
        Type(szString[i]);
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::Type(char _char)
{
    switch ( _char )
    {
        case '\n':
        {
            m_iCurX = 0;
            NewLine();
        }
        break;

        case '\r':
        {
            m_iCurX = 0;
        }
        break;

        case 8:
        {
            if ( m_iCurX > 0 ) m_iCurX--;

            m_pucBuff[m_iCurY * m_iCols + m_iCurX] = ' ';
            poConsole->SetChar(m_iCurX,m_iCurY,' ');
        }
        break;

        default:
        {
            m_pucBuff[m_iCurY * m_iCols + m_iCurX] = _char;
            poConsole->SetChar(m_iCurX,m_iCurY,_char);

            m_iCurX++;
            if ( m_iCurX == m_iCols )
            {
                m_iCurX = 0;
                NewLine();
            }
        }
        break;
    }
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::NewLine()
{
    if ( m_iCurY == (m_iRows - 1) )
    {
        int r;
        for ( r = 1; r < m_iRows; r++ )
        {
            memcpy(m_pucBuff + (r - 1) * m_iCols,
                   m_pucBuff + (r) * m_iCols,
                   m_iCols);
        }

        // -----------------------------------------------------------------------------
        memset(m_pucBuff + (r - 1) * m_iCols,' ',m_iCols);

        // -----------------------------------------------------------------------------
        DumpData();
    }
    else
        m_iCurY++;
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::DumpData()
{
    for ( int r = 0; r < m_iRows; r++ )
        for ( int c = 0; c < m_iCols; c++ )
            poConsole->SetChar(c,r,m_pucBuff[r * m_iCols + c]);
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::Cls()
{
    memset(m_pucBuff,' ',m_iCols * m_iRows);
    DumpData();
    m_iCurX = 0;
    m_iCurY = 0;
}
// -----------------------------------------------------------------------------
void CGGameConsoleApp::Think(float _fDeltaT)
{
    CGGameApplication::Think(_fDeltaT);
    poConsole->Resize(1.0f,m_fSize);
}
// -----------------------------------------------------------------------------
