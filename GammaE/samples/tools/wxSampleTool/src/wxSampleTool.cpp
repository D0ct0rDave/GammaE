//---------------------------------------------------------------------------
//
// Name:        GTSViewerApp.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#include "wxTest.h"
#include "FGTSViewerGUI.h"

IMPLEMENT_APP(wxTestApp)

bool wxTestApp::OnInit()
{
    wxTest* frame = new wxTest(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int wxTestApp::OnExit()
{
	return 0;
}
