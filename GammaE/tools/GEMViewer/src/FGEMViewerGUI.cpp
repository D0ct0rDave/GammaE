//---------------------------------------------------------------------------
//
// Name:        FGEMViewerGUI.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: CGEMViewerGUI class implementation
//
//---------------------------------------------------------------------------

#include "FGEMViewerGUI.h"
#include "CLoop.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
#include "Images/Self_CGEMViewerGUI_XPM.xpm"
////Header Include End

//----------------------------------------------------------------------------
// CGEMViewerGUI
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(CGEMViewerGUI,wxFrame)
	////Manual Code Start
	EVT_IDLE(CGEMViewerGUI::OnIdle)
	////Manual Code End
	
	EVT_CLOSE(CGEMViewerGUI::OnClose)
END_EVENT_TABLE()
////Event Table End

CGEMViewerGUI::CGEMViewerGUI(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

CGEMViewerGUI::~CGEMViewerGUI()
{
}

void CGEMViewerGUI::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	dsp = new wxStaticBitmap(this, ID_DSP, wxNullBitmap, wxPoint(16, 8), wxSize(640, 480) );
	dsp->Enable(false);
	dsp->SetBackgroundColour(*wxGREEN);

	SetTitle(wxT("GEMViewer"));
	SetIcon(Self_CGEMViewerGUI_XPM);
	SetSize(8,8,677,534);
	Center();
	
	////GUI Items Creation End
	CLoop::Init((void*)dsp->GetHandle());	
}

void CGEMViewerGUI::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * MnuopenGEMfile1005Click
 */
 /*
void CGEMViewerGUI::MnuopenGEMfile1005Click(wxCommandEvent& event)
{
	// insert your code here
	if (dlg_OpenGEM->ShowModal() == wxID_OK)
	{
		wxString wxsFilename = dlg_OpenGEM->GetFilename();
		wxString wxsDirectory = dlg_OpenGEM->GetDirectory();
		
		// wxString wxsFullFilename = wxsDirectory + "\\" + wxsFilename;
		
		CLoop::LoadGEM( (char*)wxsFilename.c_str(),(char*)wxsDirectory.c_str() );
	}	
}
*/
/*
http://www.gamedev.net/community/forums/topic.asp?topic_id=452969

Reply Quoting This MessageEdit Message gjaegy    Member since: 6/3/2004  From: Mulhouse, France
Posted - 6/23/2007 11:42:14 AM
you can use the idle event:

EVT_IDLE(gjWindowRender::OnIdle)

then:
void WindowRender::OnIdle(wxIdleEvent& event)
{
	UpdateAndRender();
	event.RequestMore();
}

RequestMore() means, once all windows messages have been processed by wxWidgets it will generate an idle event again, and so on.
*/

void CGEMViewerGUI::OnIdle(wxIdleEvent& event)
{
	// insert your code here
	CLoop::Loop();
	event.RequestMore();
}

void CGEMViewerGUI::LoadGEMFile(wxString _szFilename)
{
	CLoop::LoadGEM( (char*)_szFilename.c_str() );
};
