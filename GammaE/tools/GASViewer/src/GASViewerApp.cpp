//---------------------------------------------------------------------------
//
// Name:        GASViewerApp.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#include "GASViewerApp.h"
#include "FGASViewerGUI.h"

IMPLEMENT_APP(CGASViewerGUIApp)

bool CGASViewerGUIApp::OnInit()
{
	// Install all possible image handlers
    wxInitAllImageHandlers();

    CGASViewerGUI* frame = new CGASViewerGUI(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int CGASViewerGUIApp::OnExit()
{
	return 0;
}
