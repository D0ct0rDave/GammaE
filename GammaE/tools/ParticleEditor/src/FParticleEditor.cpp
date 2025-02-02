//---------------------------------------------------------------------------
//
// Name:        ParticleEditor.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#include "FParticleEditor.h"
#include "FGUI.h"

IMPLEMENT_APP(CParticleEditorApp)

bool CParticleEditorApp::OnInit()
{
    CGUI* frame = new CGUI(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int CParticleEditorApp::OnExit()
{
	return 0;
}
