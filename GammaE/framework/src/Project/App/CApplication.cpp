// ----------------------------------------------------------------------------
#include "CApplication.h"
#include "GammaE.h"

#include "Loop/CLoop.h"
// ----------------------------------------------------------------------------

typedef struct TApplicationGlobals
{
	HWND	m_hWnd;

	uint	m_uiScrWidth;
	uint	m_uiScrHeight;
	bool	m_bFinish;
	CGChrono	m_oChrono;
	
}TApplicationGlobals;

TApplicationGlobals appGlobals;
// ----------------------------------------------------------------------------
void CApplication::OnCreate(void *_pParam,char *pszCmdLine)
{
	// Register application settings
	Register();
	
	#ifdef WIN32
	// Get system properties
	appGlobals.m_hWnd = (HWND)_pParam;
	RECT Rect;
	GetWindowRect(appGlobals.m_hWnd,&Rect);
	appGlobals.m_uiScrWidth  = Rect.right - Rect.left;
	appGlobals.m_uiScrHeight = Rect.bottom - Rect.top;
	#endif

	// Initialize graphic system
    CGRenderer::I()->Init(appGlobals.m_hWnd,E3D_RENDERER_OP_DBUFFER,appGlobals.m_uiScrWidth ,appGlobals.m_uiScrHeight,32);

	CMipMapWH::I()->Init(256);
	CTexObjWH::I()->Init(256);	
	
	CE3D_ShaderWH::I()->Init(1024);
	CE3D_ShaderDefWH::I()->Init(1024);
	CE3D_ShaderDefFileWH::I()->Init(16);

	CHUDFontWH::I()->Init(16);
	
	// Initialize networking capabilities
	CNETSystem::Init();

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
	float fDeltaT  = appGlobals.m_oChrono.dElapsedTime();
	appGlobals.m_oChrono.Reset();
	appGlobals.m_oChrono.Start();

	appGlobals.m_bFinish = CLoop::bLoop(fDeltaT);
}
// ----------------------------------------------------------------------------
void CApplication::OnResize(unsigned int _uiNewWidth,unsigned int _uiNewHeight)
{
	appGlobals.m_uiScrWidth  = _uiNewWidth;
	appGlobals.m_uiScrHeight = _uiNewHeight;	

	CGRenderer::I()->SetScreenSize(appGlobals.m_uiScrWidth,appGlobals.m_uiScrHeight);
}
// ----------------------------------------------------------------------------
void CApplication::OnButtonDown  (unsigned int _uiButton)
{
	int iCmd = CGCommandBinder::I()->iBindedCommand(_uiButton);
	if (iCmd == -1) return;

	CGCommandDispatcher::I()->DispatchCommand(iCmd,1,0,_uiButton);
}
// ----------------------------------------------------------------------------
void CApplication::OnButtonUp    (unsigned int _uiButton)
{
	int iCmd = CGCommandBinder::I()->iBindedCommand(_uiButton);
	if (iCmd == -1) return;

	CGCommandDispatcher::I()->DispatchCommand(iCmd,0,0,_uiButton);
}
// ----------------------------------------------------------------------------
void CApplication::OnButtonPress (unsigned int _uiButton)
{

}
// ----------------------------------------------------------------------------
void CApplication::OnCursorMove	(unsigned int _uiX,unsigned int _uiY,bool _bPushedButtons)
{
	int iCmd = CGCommandBinder::I()->iBindedCommand(0);
	if (iCmd == -1) return;

	CGCommandDispatcher::I()->DispatchCommand(iCmd,_bPushedButtons?1:0,_uiX,_uiY);
}
// ----------------------------------------------------------------------------
bool CApplication::bFinishApp()
{
	return(appGlobals.m_bFinish);
}
// ----------------------------------------------------------------------------
void CApplication::Register()
{
	// ---------------------------------------------------
	// Register Input Names
	// ---------------------------------------------------
	CGInputRegistry::I()->Register("UP",		38);
	CGInputRegistry::I()->Register("DOWN",		40);
	CGInputRegistry::I()->Register("LEFT",		37);
	CGInputRegistry::I()->Register("RIGHT",		39);
	CGInputRegistry::I()->Register("TAB",		9);
	CGInputRegistry::I()->Register("ENTER" ,	13);
	CGInputRegistry::I()->Register("ESCAPE",	27);
	CGInputRegistry::I()->Register("SPACE",		32);
	CGInputRegistry::I()->Register("BACKSPACE",	8);
	CGInputRegistry::I()->Register("CTRL",		17);
	CGInputRegistry::I()->Register("F1",		112);
	CGInputRegistry::I()->Register("F2",		113);
	CGInputRegistry::I()->Register("F3",		114);
	CGInputRegistry::I()->Register("F4",		115);
	CGInputRegistry::I()->Register("F5",		116);
	CGInputRegistry::I()->Register("F6",		117);
	CGInputRegistry::I()->Register("F7",		118);
	CGInputRegistry::I()->Register("F8",		119);
	CGInputRegistry::I()->Register("F9",		120);
	CGInputRegistry::I()->Register("F10",		121);	// no chuta!!!!
	CGInputRegistry::I()->Register("F11",		122);
	CGInputRegistry::I()->Register("F12",		123);	
	CGInputRegistry::I()->Register("º",  		220);
	CGInputRegistry::I()->Register("~",  		220);	// tecla º,ª y contrabarra
	CGInputRegistry::I()->Register(".",  		190);
	CGInputRegistry::I()->Register("/",  		111);
	CGInputRegistry::I()->Register("A",			'A');
	CGInputRegistry::I()->Register("B",			'B');
	CGInputRegistry::I()->Register("C",			'C');
	CGInputRegistry::I()->Register("D",			'D');
	CGInputRegistry::I()->Register("E",			'E');
	CGInputRegistry::I()->Register("F",			'F');
	CGInputRegistry::I()->Register("G",			'G');
	CGInputRegistry::I()->Register("H",			'H');
	CGInputRegistry::I()->Register("I",			'I');
	CGInputRegistry::I()->Register("J",			'J');
	CGInputRegistry::I()->Register("K",			'K');
	CGInputRegistry::I()->Register("L",			'L');
	CGInputRegistry::I()->Register("M",			'M');
	CGInputRegistry::I()->Register("N",			'N');
	CGInputRegistry::I()->Register("O",			'O');
	CGInputRegistry::I()->Register("P",			'P');
	CGInputRegistry::I()->Register("Q",			'Q');
	CGInputRegistry::I()->Register("R",			'R');
	CGInputRegistry::I()->Register("S",			'S');
	CGInputRegistry::I()->Register("T",			'T');
	CGInputRegistry::I()->Register("U",			'U');
	CGInputRegistry::I()->Register("V",			'V');
	CGInputRegistry::I()->Register("W",			'W');
	CGInputRegistry::I()->Register("X",			'X');
	CGInputRegistry::I()->Register("Y",			'Y');
	CGInputRegistry::I()->Register("Z",			'Z');

	CGInputRegistry::I()->Register("0",			'0');
	CGInputRegistry::I()->Register("1",			'1');
	CGInputRegistry::I()->Register("2",			'2');
	CGInputRegistry::I()->Register("3",			'3');
	CGInputRegistry::I()->Register("4",			'4');
	CGInputRegistry::I()->Register("5",			'5');
	CGInputRegistry::I()->Register("6",			'6');
	CGInputRegistry::I()->Register("7",			'7');
	CGInputRegistry::I()->Register("8",			'8');
	CGInputRegistry::I()->Register("9",			'9');

	CGInputRegistry::I()->Register("MOUSE",	0);
//	CGInputRegistry::I()->Register("BUTTON0",	CmdBinder_MOUSE_BUTTON0);
//	CGInputRegistry::I()->Register("BUTTON1",	CmdBinder_MOUSE_BUTTON1);

	// ---------------------------------------------------
	// Register our application commands.
	// ---------------------------------------------------
	CGCommandRegistry::I()->Register("CamForward");
	CGCommandRegistry::I()->Register("CamBack");
	CGCommandRegistry::I()->Register("CamLeft");
	CGCommandRegistry::I()->Register("CamRight");
	CGCommandRegistry::I()->Register("CamUp");
	CGCommandRegistry::I()->Register("CamDown");

	CGCommandRegistry::I()->Register("Forward");
	CGCommandRegistry::I()->Register("Back");
	CGCommandRegistry::I()->Register("Left");
	CGCommandRegistry::I()->Register("Right");
	CGCommandRegistry::I()->Register("Up");
	CGCommandRegistry::I()->Register("Down");

	CGCommandRegistry::I()->Register("TurnUp");
	CGCommandRegistry::I()->Register("TurnDown");
	CGCommandRegistry::I()->Register("TurnLeft");
	CGCommandRegistry::I()->Register("TurnRight");
	
	CGCommandRegistry::I()->Register("Attack");
	CGCommandRegistry::I()->Register("Attack2");
	CGCommandRegistry::I()->Register("Jump");
	CGCommandRegistry::I()->Register("GenMove");
	CGCommandRegistry::I()->Register("Exit");
	CGCommandRegistry::I()->Register("KeyPress");
	
	CGCommandRegistry::I()->Register("Func0");
	CGCommandRegistry::I()->Register("Func1");
	CGCommandRegistry::I()->Register("Func2");
	CGCommandRegistry::I()->Register("Func3");
	CGCommandRegistry::I()->Register("Func4");
	CGCommandRegistry::I()->Register("Func5");
	CGCommandRegistry::I()->Register("Func6");
	CGCommandRegistry::I()->Register("Func7");
	CGCommandRegistry::I()->Register("Func8");
	CGCommandRegistry::I()->Register("Func9");

	CGCommandRegistry::I()->Register("ToggleConsole");
	CGCommandRegistry::I()->Register("Screenshot");
	CGCommandRegistry::I()->Register("ReloadMaterials");
}
// ----------------------------------------------------------------------------