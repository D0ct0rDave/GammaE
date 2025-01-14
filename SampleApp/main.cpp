// ----------------------------------------------------------------------------
#include <windows.h>

#include "ApplicationLoop.h"
#include "WinEventTranslator.h"


// ----------------------------------------------------------------------------
#define		WND_WIDTH		640
#define		WND_HEIGHT		480

HINSTANCE	WinhInstance;
HWND		mainhWnd;
bool		bFinnishApp = false;
char*		CmdLine = NULL;

int			iFullScreen = 0;

#define WINDOW_CLASS_NAME	"GammaE"
#define WINDOW_STYLE		WS_OVERLAPPED|WS_BORDER|WS_CAPTION|WS_VISIBLE
// ----------------------------------------------------------------------------
// event handler itself
// ----------------------------------------------------------------------------
LONG WINAPI WinProcInstance(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	  switch (message)
	  {
			case WM_CREATE: AppLoop_OnCreate( (void *) hwnd, WND_WIDTH, WND_HEIGHT,CmdLine);
							break;

			case WM_DESTROY:// Produced when the user closes the applicatoin
							// using window commands not GammaE commands
							AppLoop_OnDestroy((void *) hwnd);
							bFinnishApp       = true;
							break;

			case WM_SIZE:	AppLoop_OnResize(LOWORD(lParam), HIWORD(lParam));
							break;

			case WM_PAINT:	AppLoop_OnIdle();
							break;

			case WM_KEYDOWN:WinEvent_KeyDown  (wParam & 0x000000ff);	
							break;

			case WM_KEYUP:	WinEvent_KeyUp    (wParam & 0x000000ff);
							break;

			case WM_MOUSEMOVE:	WinEvent_MouseMove( LOWORD(lParam), 
													HIWORD(lParam),
													wParam & (MK_LBUTTON | MK_MBUTTON | MK_RBUTTON) );
								break;
			
			case WM_LBUTTONUP:	WinEvent_MouseUp  ( LOWORD(lParam), HIWORD(lParam),0); break;
			case WM_RBUTTONUP:	WinEvent_MouseUp  ( LOWORD(lParam), HIWORD(lParam),1); break;
			case WM_MBUTTONUP:	WinEvent_MouseUp  ( LOWORD(lParam), HIWORD(lParam),2); break;

			case WM_LBUTTONDOWN:WinEvent_MouseDown( LOWORD(lParam), HIWORD(lParam),0); break;
			case WM_RBUTTONDOWN:WinEvent_MouseDown( LOWORD(lParam), HIWORD(lParam),1); break;
			case WM_MBUTTONDOWN:WinEvent_MouseDown( LOWORD(lParam), HIWORD(lParam),2); break;
/*
		HANDLE_MSG( hwnd, WM_SIZE,		  SysOnSize );     
		HANDLE_MSG( hwnd, WM_KEYDOWN,     SysOnKeyDown );
*/
		default:				
			return(DefWindowProc(hwnd, message, wParam, lParam));
	  } 
  

	  return(0);
}
// ----------------------------------------------------------------------------
/* creates window */
// ----------------------------------------------------------------------------
void WindowSystemInit( HINSTANCE hInstance )
{
	WNDCLASS	wc;
	int			iExtStyle;
	int			iStyleBits;
	RECT		Rect;
	int			iX,iY,iW,iH;

	/* Register the frame class */
    wc.style         = 0;
    wc.lpfnWndProc   = (WNDPROC)WinProcInstance;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = 0;
    wc.hCursor       = LoadCursor (NULL,IDC_ARROW);
	// wc.hbrBackground = (HBRUSH)(COLOR_GRAYTEXT);
	wc.hbrBackground = (HBRUSH)(BLACK_BRUSH);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = WINDOW_CLASS_NAME;

    if (!RegisterClass (&wc) ) 
		exit(0);
            	

	if (iFullScreen)
	{
		iExtStyle = WS_EX_TOPMOST;
		iStyleBits= WS_POPUP|WS_VISIBLE;
	}
	else
	{
		iExtStyle = 0;
		iStyleBits= WINDOW_STYLE;
	}

	// Adjust to screen
	Rect.left   = 0;
	Rect.top    = 0;
	Rect.right  = WND_WIDTH;
	Rect.bottom = WND_HEIGHT;
	
	AdjustWindowRect (&Rect, iStyleBits, FALSE);
	
	iW = Rect.right  - Rect.left;
	iH = Rect.bottom - Rect.top;

	if (iFullScreen)
	{
		iX = 0;
		iY = 0;
	}
	else
	{
		iX = 0;
		iY = 0;
	}

	mainhWnd = CreateWindowEx (
							iExtStyle, 
							WINDOW_CLASS_NAME,							
							"GammaE",
							iStyleBits,
							iX,iY,iW,iH,
							NULL,
							NULL,
							hInstance,
							NULL);

     ShowWindow ( mainhWnd, SW_SHOW );
     UpdateWindow ( mainhWnd );	
}
// ----------------------------------------------------------------------------
/* main program entry point */
// ----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG        msg;    

	if ((lpCmdLine != NULL) && (lpCmdLine[0] !='\0'))
	{
		CmdLine = new char[strlen(lpCmdLine)+1];
		strcpy(CmdLine,lpCmdLine);
	}

	WinhInstance = hInstance;

	WindowSystemInit( hInstance );
	
    // main message loop     
	
	while ( ! bFinnishApp )
	{
		if (! PeekMessage(&msg, mainhWnd, 0, 0, PM_REMOVE)) break;
			
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		if ( AppLoop_bFinnishApp() ) DestroyWindow(mainhWnd);
	}
	
	if (CmdLine) delete []CmdLine;
	return 1;
}
// ----------------------------------------------------------------------------