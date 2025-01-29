//---------------------------------------------------------------------------
//
// Name:        GTSViewerApp.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#include "GTSViewerApp.h"
#include "FGTSViewerGUI.h"

IMPLEMENT_APP(CGTSViewerGUIApp)

bool CGTSViewerGUIApp::OnInit()
{
    CGTSViewerGUI* frame = new CGTSViewerGUI(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int CGTSViewerGUIApp::OnExit()
{
	return 0;
}
