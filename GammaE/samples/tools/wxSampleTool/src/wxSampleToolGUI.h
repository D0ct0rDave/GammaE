//---------------------------------------------------------------------------
//
// Name:        FGTSViewerGUI.h
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: CGTSViewerGUI class declaration
//
//---------------------------------------------------------------------------

#ifndef __wxSampleToolGUI_h__
#define __wxSampleToolGUI_h___h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/filedlg.h>
#include <wx/timer.h>
#include <wx/menu.h>
#include <wx/statbmp.h>
#include <wx/button.h>
#include <wx/statusbr.h>
////Header Include End

////Dialog Style Start
#undef wxSampleToolGUI_STYLE
#define wxSampleToolGUI_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class wxSampleToolGUI : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		wxSampleToolGUI(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("GTSViewer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxSampleToolGUI_STYLE);
		virtual ~wxSampleToolGUI();
	void Mnuopengtsfile1001Click(wxCommandEvent& event);
	void Mnusavegemfile1002Click(wxCommandEvent& event);
	void Mnuquit1004Click(wxCommandEvent& event);
	void Mnufile1005Click(wxCommandEvent& event);
	void Mnuopengtsfile1005Click(wxCommandEvent& event);
		void WxTimer1Timer(wxTimerEvent& event);
	void Mnuopengtsfile1005Click1(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *dlg_OpenGTS;
		wxMenuBar *WxMenuBar1;
		wxStaticBitmap *dsp;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxStatusBar *WxStatusBar1;
		////GUI Control Declaration End
		
	private:
		// void OnPaint(wxPaintEvent& WXUNUSED(event) );
    
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXTIMER1 = 1005,
			ID_MNU_FILEMENU_1001 = 1001,
			ID_MNU___1003 = 1003,
			ID_MNU_QUIT_1004 = 1004,
			
			ID_DSP = 1008,
			ID_WXBUTTON2 = 1007,
			ID_WXBUTTON1 = 1006,
			ID_WXSTATUSBAR1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();		
		void OnIdle(wxIdleEvent& event);
		
};

#endif

