//---------------------------------------------------------------------------
//
// Name:        FGUI.h
// Author:      PepeMagnifico
// Created:     12/09/2009 0:41:29
// Description: CGUI class declaration
//
//---------------------------------------------------------------------------

#ifndef __CGUI_h__
#define __CGUI_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif
//---------------------------------------------------------------------------
//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/combobox.h>
#include <wx/colordlg.h>
#include <wx/menu.h>
#include <wx/filedlg.h>
#include <wx/statline.h>
#include <wx/clrpicker.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/panel.h>
////Header Include End
//---------------------------------------------------------------------------
////Dialog Style Start
#undef CGUI_STYLE
#define CGUI_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
//---------------------------------------------------------------------------
class CGUI : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:

		CGUI(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("PAKZ File Mgr"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = CGUI_STYLE);
		virtual ~CGUI();
		void Mnunewpakzfile1002Click(wxCommandEvent& event);
		void Mnuloadpakzfile1003Click(wxCommandEvent& event);
		void Mnusavepakzfile1004Click(wxCommandEvent& event);
		void Mnuloadpakzfile1005Click(wxCommandEvent& event);
		void sld_FAlphaSlider(wxCommandEvent& event);
		void cp_FColorColourChanged(wxColourPickerEvent& event);
		void cp_IColorColourChanged(wxColourPickerEvent& event);
		void WxComboBox1Selected(wxCommandEvent& event );
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxComboBox *cb_PSGList;
		wxColourDialog *dlg_SelectFColor;
		wxColourDialog *dlg_SelectIColor;
		wxMenuBar *WxMenuBar1;
		wxFileDialog *dlg_Open;
		wxStaticLine *WxStaticLine4;
		wxStaticLine *WxStaticLine3;
		wxStaticLine *WxStaticLine2;
		wxStaticLine *WxStaticLine1;
		wxColourPickerCtrl *cp_FColor;
		wxColourPickerCtrl *cp_IColor;
		wxSlider *sld_IREnergy;
		wxStaticText *WxStaticText19;
		wxStaticText *WxStaticText18;
		wxSlider *sld_IEnergy;
		wxStaticText *WxStaticText17;
		wxSlider *sld_FRRadius;
		wxSlider *sld_IRRadius;
		wxStaticText *WxStaticText16;
		wxStaticText *WxStaticText15;
		wxStaticText *WxStaticText14;
		wxSlider *sld_FRadius;
		wxSlider *sld_IRadius;
		wxStaticText *WxStaticText13;
		wxStaticText *WxStaticText12;
		wxStaticText *WxStaticText11;
		wxSlider *sld_FAngle;
		wxSlider *sld_IAngle;
		wxStaticText *WxStaticText10;
		wxStaticText *WxStaticText9;
		wxSlider *sld_IRAngle;
		wxSlider *sld_FRAngle;
		wxStaticText *WxStaticText8;
		wxStaticText *WxStaticText7;
		wxStaticText *WxStaticText6;
		wxStaticText *WxStaticText5;
		wxSlider *sld_FRSize;
		wxSlider *sld_IRSize;
		wxSlider *sld_FSize;
		wxSlider *sld_ISize;
		wxStaticText *WxStaticText4;
		wxSlider *sld_FCRand;
		wxSlider *sld_ICRand;
		wxStaticText *WxStaticText3;
		wxStaticText *Initial;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText1;
		wxSlider *sld_FAlpha;
		wxSlider *sld_IAlpha;
		wxPanel *pn_Display;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_CB_PSGLIST = 1149,
			ID_MNU_FILE_1001 = 1001,
			ID_MNU_NEWPAKZFILE_1002 = 1002,
			ID_MNU_LOADPAKZFILE_1005 = 1005,
			ID_MNU_SAVEPAKZFILE_1004 = 1004,
			
			ID_WXSTATICLINE4 = 1148,
			ID_WXSTATICLINE3 = 1147,
			ID_WXSTATICLINE2 = 1146,
			ID_WXSTATICLINE1 = 1145,
			ID_CP_FCOLOR = 1144,
			ID_CP_ICOLOR = 1143,
			ID_SLD_IRENERGY = 1142,
			ID_WXSTATICTEXT19 = 1141,
			ID_WXSTATICTEXT18 = 1140,
			ID_SLD_IENERGY = 1139,
			ID_WXSTATICTEXT17 = 1138,
			ID_SLD_FRRADIUS = 1127,
			ID_SLD_IRRADIUS = 1126,
			ID_WXSTATICTEXT16 = 1125,
			ID_WXSTATICTEXT15 = 1124,
			ID_WXSTATICTEXT14 = 1123,
			ID_SLD_FRADIUS = 1122,
			ID_SLD_IRADIUS = 1121,
			ID_WXSTATICTEXT13 = 1120,
			ID_WXSTATICTEXT12 = 1091,
			ID_WXSTATICTEXT11 = 1090,
			ID_SLD_FANGLE = 1089,
			ID_SLD_IANGLE = 1088,
			ID_WXSTATICTEXT10 = 1087,
			ID_WXSTATICTEXT9 = 1086,
			ID_SLD_IRANGLE = 1085,
			ID_SLD_FRANGLE = 1084,
			ID_WXSTATICTEXT8 = 1055,
			ID_WXSTATICTEXT7 = 1054,
			ID_WXSTATICTEXT6 = 1052,
			ID_WXSTATICTEXT5 = 1051,
			ID_SLD_FRSIZE = 1050,
			ID_SLD_IRSIZE = 1049,
			ID_SLD_FSIZE = 1048,
			ID_SLD_ISIZE = 1047,
			ID_WXSTATICTEXT4 = 1029,
			ID_SLD_FCRAND = 1028,
			ID_SLD_ICRAND = 1027,
			ID_WXSTATICTEXT3 = 1026,
			ID_INITIAL = 1025,
			ID_WXSTATICTEXT2 = 1024,
			ID_WXSTATICTEXT1 = 1023,
			ID_SLD_FALPHA = 1013,
			ID_SLD_IR = 1012,
			ID_PN_DISPLAY = 1010,
			ID_WXPANEL1 = 1009,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:

		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		void OnIdle(wxIdleEvent& event);
		void SetupPSGList();
		void SetupControls();
		void SetupParticleSystem();
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
