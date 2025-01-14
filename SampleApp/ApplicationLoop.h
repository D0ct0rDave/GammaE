// ----------------------------------------------------------------------------
#ifndef ApplicationLoopH 
#define ApplicationLoopH 
// ----------------------------------------------------------------------------
bool AppLoop_bFinnishApp();

void AppLoop_OnCreate (void *uiWinHandler,unsigned int uiWndWidth,unsigned int uiWndHeight,char *pszCmdLine);
void AppLoop_OnResize (unsigned int uiWndWidth,unsigned int uiWndHeight);
void AppLoop_OnDestroy(void *uiWinHandler);
void AppLoop_OnIdle   ();
// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------
