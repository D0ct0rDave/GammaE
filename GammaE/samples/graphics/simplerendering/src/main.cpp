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
#include <ddraw.h>

#include "App/CApplication.h"

#define APP_INI_FILE "./GammaE.ini"
// ----------------------------------------------------------------------------
HINSTANCE WinhInstance;
HWND mainhWnd;
bool bFinnishApp = false;
char* CmdLine = NULL;

int iFullScreen = 0;
int iWidth = 640;
int iHeight = 480;
char szApplicationName[1024];

#define WINDOW_CLASS_NAME   "GammaE"
#define WINDOW_STYLE        WS_OVERLAPPED | WS_BORDER | WS_CAPTION | WS_VISIBLE

void error(char* szMsg)
{
    // ::MessageBox(szMsg,szApplicationName);
    exit(0);
}
// ----------------------------------------------------------------------------
// event handler itself
// ----------------------------------------------------------------------------
LONG WINAPI WinProcInstance(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch ( message )
    {
        case WM_CREATE: CApplication::OnCreate( (void*) hwnd, CmdLine );
        break;

        case WM_DESTROY:     // Produced when the user closes the applicatoin
                             // using window commands not GammaE commands
        CApplication::OnDestroy( (void*) hwnd );
        bFinnishApp = true;
        break;

        case WM_SIZE:   CApplication::OnResize( LOWORD(lParam), HIWORD(lParam) );
        break;

        case WM_PAINT:  CApplication::OnIdle();
        break;

        /*
           HANDLE_MSG( hwnd, WM_SIZE,		  SysOnSize );
           HANDLE_MSG( hwnd, WM_KEYDOWN,     SysOnKeyDown );
         */

        default:
        return( DefWindowProc(hwnd, message, wParam, lParam) );
    }

    return(0);
}
// ----------------------------------------------------------------------------
LPDIRECTDRAW7 gpDD;
LPDIRECTDRAWSURFACE7 gpddsFrontBuffer;
LPDIRECTDRAWSURFACE7 gpddsBackBuffer;
// ----------------------------------------------------------------------------
void CreateFullScreenDisplay()
{
    HRESULT hr;

    // DDraw stuff begins here
    if ( FAILED( hr = DirectDrawCreateEx( NULL, (VOID* *)&gpDD,IID_IDirectDraw7, NULL ) ) )
        error("DirectDrawCreateEx");

    DWORD flags = DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN | DDSCL_ALLOWREBOOT;

    if ( FAILED( hr = gpDD->SetCooperativeLevel(mainhWnd, flags) ) )
        error("SetCooperativeLevel");

    if ( FAILED( hr = gpDD->SetDisplayMode(iWidth, iHeight, 32, 0, 0) ) )
        error("SetDisplayMode");

    // Create primary surface (with backbuffer attached)
    DDSURFACEDESC2 ddsd;
    ZeroMemory( &ddsd, sizeof(ddsd) );
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
    ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP | DDSCAPS_COMPLEX | DDSCAPS_3DDEVICE;
    ddsd.dwBackBufferCount = 1;

    if ( FAILED( hr = gpDD->CreateSurface( &ddsd, &gpddsFrontBuffer,NULL ) ) )
        error("CreateSurface");

    // Get a pointer to the back buffer
    DDSCAPS2 ddscaps;
    ZeroMemory( &ddscaps, sizeof(ddscaps) );
    ddscaps.dwCaps = DDSCAPS_BACKBUFFER;

    if ( FAILED( hr = gpddsFrontBuffer->GetAttachedSurface( &ddscaps,&gpddsBackBuffer ) ) )
        error("GetAttachedSurface");

    gpddsBackBuffer->AddRef();

    // Dirty trick to make display visible in some laptop displays
    ShowWindow(mainhWnd,SW_MINIMIZE);
    Sleep(250);
    ShowWindow(mainhWnd,SW_MAXIMIZE);
}
// ----------------------------------------------------------------------------
/* creates window */
// ----------------------------------------------------------------------------
void WindowSystemInit( HINSTANCE hInstance )
{
    WNDCLASS wc;
    int iExtStyle;
    int iStyleBits;
    RECT Rect;

    /* Register the frame class */
    wc.style = 0;
    wc.lpfnWndProc = (WNDPROC)WinProcInstance;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = 0;
    wc.hCursor = LoadCursor (NULL,IDC_ARROW);
    // wc.hbrBackground = (HBRUSH)(COLOR_GRAYTEXT);
    wc.hbrBackground = (HBRUSH)(BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = WINDOW_CLASS_NAME;

    if ( !RegisterClass (&wc) )
        exit(0);

    GetPrivateProfileString("General","AppName","GammaE",szApplicationName,64,APP_INI_FILE);
    iWidth = GetPrivateProfileInt("General","Width",iWidth,APP_INI_FILE);
    iHeight = GetPrivateProfileInt("General","Height",iHeight,APP_INI_FILE);
    iFullScreen = GetPrivateProfileInt("General","FullScreen",0,APP_INI_FILE);

    // Adjust to screen
    if ( iFullScreen )
    {
        mainhWnd = CreateWindowEx(NULL,  // WS_EX_CLIENTEDGE,
                                  WINDOW_CLASS_NAME, // pointer to registered class name
                                  szApplicationName,    // pointer to windows namew
                                  WS_POPUP | WS_VISIBLE, // WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_VISIBLE,
                                  0, 0,
                                  iWidth, iHeight,
                                  NULL,
                                  NULL,
                                  hInstance,
                                  NULL);

        CreateFullScreenDisplay();
        ShowCursor(false);
    }
    else
    {
        RECT rClient;
        rClient.left = 0;
        rClient.right = iWidth;
        rClient.top = 0;
        rClient.bottom = iHeight;
        ::AdjustWindowRect(&rClient, WS_POPUP | WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_VISIBLE, false);

        mainhWnd = CreateWindowEx(  WS_EX_APPWINDOW,        // WS_EX_CLIENTEDGE,
                                    WINDOW_CLASS_NAME,      // pointer to registered class name
                                    szApplicationName,      // pointer to windows name
                                    // /*WS_POPUP |*/ WS_VISIBLE /*  WS_OVERLAPPEDWINDOW  */| WS_SYSMENU
                                    // windows style
                                    WS_POPUP | WS_SYSMENU | WS_BORDER | WS_CAPTION | WS_VISIBLE,
                                    0, 0,
                                    rClient.right - rClient.left, rClient.bottom - rClient.top,
                                    NULL,
                                    NULL,
                                    hInstance,
                                    NULL);
    }

    ShowWindow ( mainhWnd, SW_SHOW );
    UpdateWindow ( mainhWnd );
}
// ----------------------------------------------------------------------------
/* main program entry point */
// ----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;

    if ( (lpCmdLine != NULL) && (lpCmdLine[0] != '\0') )
    {
        CmdLine = new char[strlen(lpCmdLine) + 1];
        strcpy(CmdLine,lpCmdLine);
    }

    WinhInstance = hInstance;

    WindowSystemInit( hInstance );

    // main message loop

    while ( !bFinnishApp )
    {
        if ( !PeekMessage(&msg, mainhWnd, 0, 0, PM_REMOVE) ) break;

        TranslateMessage(&msg);
        DispatchMessage(&msg);

        if ( CApplication::bFinishApp() )
            DestroyWindow(mainhWnd);
    }

    if ( CmdLine ) delete [] CmdLine;
    return(1);
}
// ----------------------------------------------------------------------------
