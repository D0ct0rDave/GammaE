//---------------------------------------------------------------------------
//
// Name:        FGASViewerGUI.h
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: CGASViewerGUI class declaration
//
//---------------------------------------------------------------------------

#ifndef __CGASVIEWERGUI_h__
#define __CGASVIEWERGUI_h__

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
#include <wx/radiobox.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/timer.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/statbmp.h>
////Header Include End

////Dialog Style Start
#undef CGASViewerGUI_STYLE
#define CGASViewerGUI_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class CGASViewerGUI : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		CGASViewerGUI(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("GASViewer"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = CGASViewerGUI_STYLE);
		virtual ~CGASViewerGUI();
		void MnuopenGASfile1001Click(wxCommandEvent& event);
		void Mnusavegemfile1002Click(wxCommandEvent& event);
		void Mnuquit1004Click(wxCommandEvent& event);
		void Mnufile1005Click(wxCommandEvent& event);
		void MnuopenGTSfile1005Click(wxCommandEvent& event);
		void MnuopenGASfile1006Click(wxCommandEvent& event);
		void WxTimer1Timer(wxTimerEvent& event);
		void Mnuloadgemfile1009Click(wxCommandEvent& event);
		void cb_MaterialListSelected(wxCommandEvent& event );
		void WxstaticClick(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxRadioBox *rb_UnitSys;
		wxButton *WxButton1;
		wxStaticText *WxStaticText3;
		wxComboBox *cb_MaterialList;
		wxStaticBox *WxStaticBox4;
		wxFileDialog *dlg_SaveGEM;
		wxTimer *WxTimer1;
		wxFileDialog *dlg_OpenGAS;
		wxFileDialog *dlg_OpenGTS;
		wxMenuBar *WxMenuBar1;
		wxFileDialog *dlg_LoadGEM;
		wxStaticBox *WxStaticBox3;
		wxTextCtrl *ed_Info;
		wxStaticBox *WxStaticBox2;
		wxStaticBox *WxStaticBox1;
		wxStaticBitmap *dsp;
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
			ID_RB_UNITSYS = 1057,
			ID_WXBUTTON1 = 1056,
			ID_WXSTATICTEXT3 = 1055,
			ID_CB_MATERIALLIST = 1054,
			ID_WXSTATICBOX4 = 1050,
			ID_WXTIMER1 = 1005,
			ID_MNU_FILEMENU_1001 = 1001,
			ID_MNU_OPENGASFILE_1006 = 1006,
			ID_MNU_OPENGTSFILE_1005 = 1005,
			ID_MNU_LOADGEMFILE_1009 = 1009,
			ID_MNU_SAVEGEMFILE_1002 = 1002,
			ID_MNU_QUIT_1004 = 1004,
			
			ID_WXSTATICBOX3 = 1028,
			ID_ED_INFO = 1027,
			ID_WXSTATICBOX2 = 1026,
			ID_WXSTATICBOX1 = 1024,
			ID_DSP = 1008,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();		
		void OnIdle(wxIdleEvent& event);
		void ShowInfo();
		
};

#endif
