// -----------------------------------------------------------------------------
/*! \class
 *  \brief
 *  \author David M&aacute;rquez de la Cruz
 *  \version 1.5
 *  \date 1999-2009
 *  \par Copyright (c) 1999 David M&aacute;rquez de la Cruz
 *  \par GammaE License
 */
// ----------------------------------------------------------------------------
#include <windows.h>

#include "CApplication.h"
#include "Loop/CLoop.h"

#include "GammaE.h"

// ----------------------------------------------------------------------------
typedef struct TApplicationGlobals
{
    HWND m_hWnd;

    uint m_uiScrWidth;
    uint m_uiScrHeight;
    bool m_bFinish;
    CGChrono m_oChrono;
}TApplicationGlobals;

TApplicationGlobals appGlobals;
// ----------------------------------------------------------------------------
void CApplication::OnCreate(void* _pParam,char* pszCmdLine)
{
    #ifdef WIN32
    // Get system properties
    appGlobals.m_hWnd = (HWND)_pParam;
    RECT Rect;
    GetWindowRect(appGlobals.m_hWnd,&Rect);
    appGlobals.m_uiScrWidth = Rect.right - Rect.left;
    appGlobals.m_uiScrHeight = Rect.bottom - Rect.top;
    #endif

    // Initialize graphic system
    CGRenderer::I()->bInit(appGlobals.m_hWnd,E3D_RENDERER_OP_DBUFFER,appGlobals.m_uiScrWidth,appGlobals.m_uiScrHeight,32);

    // Init Main Game Entry Point
    CLoop::Init();
}
// ----------------------------------------------------------------------------
void CApplication::OnDestroy(void* _pParam)
{
    CLoop::Finish();
}
// ----------------------------------------------------------------------------
void CApplication::OnIdle()
{
    appGlobals.m_oChrono.Stop();
    float fDeltaT = appGlobals.m_oChrono.dElapsedTime();
    appGlobals.m_oChrono.Reset();
    appGlobals.m_oChrono.Start();

    appGlobals.m_bFinish = CLoop::bLoop(fDeltaT);
}
// ----------------------------------------------------------------------------
void CApplication::OnResize(unsigned int _uiNewWidth,unsigned int _uiNewHeight)
{
    appGlobals.m_uiScrWidth = _uiNewWidth;
    appGlobals.m_uiScrHeight = _uiNewHeight;

    CGRenderer::I()->SetScreenSize(appGlobals.m_uiScrWidth,appGlobals.m_uiScrHeight);
}
// ----------------------------------------------------------------------------
bool CApplication::bFinishApp()
{
    return(appGlobals.m_bFinish);
}
// ----------------------------------------------------------------------------
