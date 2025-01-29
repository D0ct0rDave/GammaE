//---------------------------------------------------------------------------
//
// Name:        GEMViewerApp.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#include "GEMViewerApp.h"
#include "FGEMViewerGUI.h"

IMPLEMENT_APP(CGEMViewerGUIApp)

bool CGEMViewerGUIApp::OnInit()
{
    CGEMViewerGUI* frame = new CGEMViewerGUI(NULL);
    SetTopWindow(frame);
		
	frame->LoadGEMFile( wxString(argv[1]) );
    frame->Show();
    return true;
}
 
int CGEMViewerGUIApp::OnExit()
{
	return 0;
}
