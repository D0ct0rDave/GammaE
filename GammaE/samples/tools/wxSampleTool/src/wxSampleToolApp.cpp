//---------------------------------------------------------------------------
//
// Name:        GTSViewerApp.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#include "wxSampleToolGUI.h"
#include "wxSampleToolApp.h"

IMPLEMENT_APP(wxSampleToolApp)

bool wxSampleToolApp::OnInit()
{
    wxSampleToolGUI* frame = new wxSampleToolGUI(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int wxSampleToolApp::OnExit()
{
	return 0;
}
