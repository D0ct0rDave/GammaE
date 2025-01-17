// ----------------------------------------------------------------------------
#ifndef WinEventTranslatorH
#define WinEventTranslatorH

// ----------------------------------------------------------------------------
// Event handlers translators
// ----------------------------------------------------------------------------

void WinEvent_KeyDown  (int Key);
void WinEvent_KeyUp    (int Key);
void WinEvent_KeyPress (int Key);

void WinEvent_MouseDown(unsigned int x,unsigned int y,unsigned int button);
void WinEvent_MouseUp  (unsigned int x,unsigned int y,unsigned int button);
void WinEvent_MouseMove(unsigned int x,unsigned int y,bool  PushedButtons);

// ----------------------------------------------------------------------------
#endif
// ----------------------------------------------------------------------------