//---------------------------------------------------------------------------
//
// Name:        FGTSViewerGUI.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: CGTSViewerGUI class implementation
//
//---------------------------------------------------------------------------

#include "FGTSViewerGUI.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// CGTSViewerGUI
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(wxTestGUI,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(wxTestGUI::OnClose)
	EVT_TIMER(ID_WXTIMER1,wxTestGUI::WxTimer1Timer)
	EVT_MENU(ID_MNU_QUIT_1004, wxTestGUI::Mnuquit1004Click)
END_EVENT_TABLE()
////Event Table End

wxTestGUI::wxTestGUI(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

wxTestGUI::~wxTestGUI()
{
}

void wxTestGUI::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1, wxDOUBLE_BORDER | wxSTATIC_BORDER);
	WxStatusBar1->SetFieldsCount(1);
	WxStatusBar1->SetStatusText(wxT("Filename:"),0);
	int WxStatusBar1_Widths[1];
	WxStatusBar1_Widths[0] = -1;
	WxStatusBar1->SetStatusWidths(1,WxStatusBar1_Widths);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("WxButton1"), wxPoint(222,510), wxSize(120,39), 0, wxDefaultValidator, wxT("WxButton1"));
	WxButton1->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxButton2 = new wxButton(this, ID_WXBUTTON2, wxT("WxButton1"), wxPoint(371,511), wxSize(120,39), 0, wxDefaultValidator, wxT("WxButton2"));
	WxButton2->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	dsp = new wxStaticBitmap(this, ID_DSP, wxNullBitmap, wxPoint(48,12), wxSize(640,480) );
	dsp->Enable(false);
	dsp->SetBackgroundColour(*wxGREEN);
	dsp->SetFont(wxFont(8, wxSWISS, wxNORMAL,wxNORMAL, false, wxT("Tahoma")));

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILEMENU_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU___1003, wxT("-"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU_QUIT_1004, wxT("Quit"), wxT(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILEMENU_1001_Mnu_Obj, wxT("File"));
	SetMenuBar(WxMenuBar1);

	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this, ID_WXTIMER1);
	WxTimer1->Start(100);

	dlg_OpenGTS =  new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("*.gt;*.*"), wxOPEN);

	SetStatusBar(WxStatusBar1);
	SetTitle(wxT("GTSViewer"));
	SetIcon(wxNullIcon);
	SetSize(8,8,739,612);
	Center();
	
	////GUI Items Creation End
}

void wxTestGUI::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Mnuopengtsfile1001Click
 */
void wxTestGUI::Mnuopengtsfile1001Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnusavegemfile1002Click
 */
void wxTestGUI::Mnusavegemfile1002Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnuquit1004Click
 */
void wxTestGUI::Mnuquit1004Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnufile1005Click
 */
void wxTestGUI::Mnufile1005Click(wxCommandEvent& event)
{
	// insert your code here

}

/*
 * Mnuopengtsfile1005Click
 */
void wxTestGUI::Mnuopengtsfile1005Click(wxCommandEvent& event)
{
	// insert your code here
	if (dlg_OpenGTS->ShowModal() == wxID_OK)
	{
		wxString wxsFilename = dlg_OpenGTS->GetFilename();
		wxString wxsDirectory = dlg_OpenGTS->GetDirectory();
		
		// wxString wxsFullFilename = wxsDirectory + "\\" + wxsFilename;
		
	}	
}

/*
 * WxTimer1Timer
 */
void wxTestGUI::WxTimer1Timer(wxTimerEvent& event)
{
	// insert your code here
}

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

void wxTestGUI::OnIdle(wxIdleEvent& event)
{
	// insert your code here
	event.RequestMore();
}
