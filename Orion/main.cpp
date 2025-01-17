// ----------------------------------------------------------------------------
#include <windows.h>

#include "AppLoop.h"
#include "Input/WinEventTranslator.h"


// ----------------------------------------------------------------------------
// #define FULLSCREEN
#ifndef FULLSCREEN
	int			iFullScreen = 0;
	int		WND_WIDTH		= 800;
	int		WND_HEIGHT		= 600;
#else
	int			iFullScreen = 1;
	int		WND_WIDTH		= 1024;
	int		WND_HEIGHT		= 768;
#endif

int		WND_XCENTER		= WND_WIDTH  / 2;
int		WND_YCENTER		= WND_HEIGHT / 2;

HINSTANCE	WinhInstance;
HWND		mainhWnd;

bool		bFinnishApp = false;
char*		CmdLine = NULL;


#define WINDOW_CLASS_NAME	"Orion"
#define WINDOW_STYLE		WS_OVERLAPPED|WS_BORDER|WS_CAPTION|WS_VISIBLE

// ----------------------------------------------------------------------------
bool bTimerCreated= false;
void CreateTimer()
{
	// set a timer to go off 30 times a second
    // at every timer message the input device will be read	
	UINT uiID = SetTimer(mainhWnd, 0,1000/30,NULL);
	bTimerCreated= true;
}

void DestroyTimer()
{	
	KillTimer( mainhWnd, 0 );
	bTimerCreated= false;
}
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
							// using window commands not Orion commands
							AppLoop_OnDestroy((void *) hwnd);
							bFinnishApp       = true;
							DestroyTimer();
							break;

			case WM_SIZE:	
							WND_WIDTH   = LOWORD(lParam);
							WND_HEIGHT  = HIWORD(lParam);
							WND_XCENTER = WND_WIDTH/2;
							WND_YCENTER = WND_HEIGHT/2;

							AppLoop_OnResize(WND_WIDTH,WND_HEIGHT);
							SetCursorPos (WND_XCENTER, WND_YCENTER);
							break;

			case WM_PAINT:	AppLoop_OnIdle();							
							break;

			case WM_KEYDOWN:WinEvent_KeyDown  (wParam & 0x000000ff);	
							break;

			case WM_KEYUP:	WinEvent_KeyUp    (wParam & 0x000000ff);
							break;

			case WM_MOUSEMOVE:	
							break;
			
			case WM_LBUTTONUP:	WinEvent_MouseUp  ( LOWORD(lParam), HIWORD(lParam),0); break;
			case WM_RBUTTONUP:	WinEvent_MouseUp  ( LOWORD(lParam), HIWORD(lParam),1); break;
			case WM_MBUTTONUP:	WinEvent_MouseUp  ( LOWORD(lParam), HIWORD(lParam),2); break;

			case WM_LBUTTONDOWN:WinEvent_MouseDown( LOWORD(lParam), HIWORD(lParam),0); break;
			case WM_RBUTTONDOWN:WinEvent_MouseDown( LOWORD(lParam), HIWORD(lParam),1); break;
			case WM_MBUTTONDOWN:WinEvent_MouseDown( LOWORD(lParam), HIWORD(lParam),2); break;

			case WM_TIMER:	
							// update the input device every timer message
							POINT oMousePos;
							if (GetCursorPos (&oMousePos))
							{
								int		idX,idY;
														
								idX = oMousePos.x - WND_XCENTER;
								idY = WND_YCENTER - oMousePos.y;



								WinEvent_MouseMove( idX,idY,
													wParam & (MK_LBUTTON | MK_MBUTTON | MK_RBUTTON) );

								// Ensure there is enough room to move: From Quake2 "win32\in_win.c"
								SetCursorPos (WND_XCENTER, WND_YCENTER);
							}
							break;
				
		default:				
			return(DefWindowProc(hwnd, message, wParam, lParam));
	  } 
  

	  return(1);
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
							"Orion",
							iStyleBits,
							iX,iY,iW,iH,
							NULL,
							NULL,
							hInstance,
							NULL);

     ShowWindow ( mainhWnd, SW_SHOW );
     UpdateWindow ( mainhWnd );	

	 // Hide mouse cursor
	 ShowCursor(false);
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
	// CreateTimer();

		//-------------------------------------------------------
		// GUARRING CODE: En el puto windows no me chutan los timers
		//-------------------------------------------------------
		DWORD oIni,oNow;
		oIni = GetTickCount();	
		//-------------------------------------------------------

		// main message loop		
		while ( ! bFinnishApp )
		{
			if (! PeekMessage(&msg, mainhWnd, 0, 0, PM_REMOVE)) break;
				
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if ( AppLoop_bFinishApp() ) DestroyWindow(mainhWnd);
			
			
			//-------------------------------------------------------
			// GUARRING CODE: En el puto windows no me chutan los timers
			//-------------------------------------------------------
			oNow = GetTickCount();
			if (oNow - oIni > (1000/30)) 
			{
				oIni = oNow;
				SendMessage(mainhWnd,WM_TIMER,0,0);
			}
			//-------------------------------------------------------
		}

	// DestroyTimer();
	if (CmdLine) delete []CmdLine;
	return 1;
}
// ----------------------------------------------------------------------------