// ----------------------------------------------------------------------------
//
// Name:        FGUI.cpp
// Author:      PepeMagnifico
// Created:     12/09/2009 0:41:29
// Description: CGUI class implementation
//
// ----------------------------------------------------------------------------

#include "FGUI.h"
#include "CLoop.h"
#include "CGlobals.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

// ----------------------------------------------------------------------------
// CGUI
// ----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(CGUI,wxFrame)
	////Manual Code Start
	EVT_IDLE(CGUI::OnIdle)
	////Manual Code End
	
	EVT_CLOSE(CGUI::OnClose)
	EVT_COMBOBOX(ID_CB_PSGLIST,CGUI::WxComboBox1Selected)
	EVT_MENU(ID_MNU_NEWPAKZFILE_1002, CGUI::Mnunewpakzfile1002Click)
	EVT_MENU(ID_MNU_LOADPAKZFILE_1005, CGUI::Mnuloadpakzfile1005Click)
	EVT_MENU(ID_MNU_SAVEPAKZFILE_1004, CGUI::Mnusavepakzfile1004Click)
	EVT_COLOURPICKER_CHANGED(ID_CP_FCOLOR,CGUI::cp_FColorColourChanged)
	EVT_COLOURPICKER_CHANGED(ID_CP_ICOLOR,CGUI::cp_IColorColourChanged)
	EVT_SLIDER(ID_SLD_IRENERGY,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IENERGY,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FRRADIUS,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IRRADIUS,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FRADIUS,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IRADIUS,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FANGLE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IANGLE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IRANGLE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FRANGLE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FRSIZE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IRSIZE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FSIZE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_ISIZE,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FCRAND,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_ICRAND,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_FALPHA,CGUI::sld_FAlphaSlider)
	EVT_SLIDER(ID_SLD_IR,CGUI::sld_FAlphaSlider)
END_EVENT_TABLE()
////Event Table End
// ----------------------------------------------------------------------------
const float PSYSGEN_ENERGY_MULT = 10.0f;
const float PSYSGEN_SIZE_MULT   = 5.0f;
const float PSYSGEN_RADIUS_MULT = 10.0f;
// ----------------------------------------------------------------------------
CGUI::CGUI(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}
// ----------------------------------------------------------------------------
CGUI::~CGUI()
{
}
// ----------------------------------------------------------------------------
void CGUI::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(871, 621));
	WxPanel1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	pn_Display = new wxPanel(WxPanel1, ID_PN_DISPLAY, wxPoint(26, 33), wxSize(443, 443));
	pn_Display->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IAlpha = new wxSlider(WxPanel1, ID_SLD_IR, 0, 0, 255, wxPoint(587, 118), wxSize(195, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IAlpha"));
	sld_IAlpha->SetRange(0,255);
	sld_IAlpha->SetValue(0);
	sld_IAlpha->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FAlpha = new wxSlider(WxPanel1, ID_SLD_FALPHA, 0, 0, 255, wxPoint(587, 163), wxSize(196, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FAlpha"));
	sld_FAlpha->SetRange(0,255);
	sld_FAlpha->SetValue(0);
	sld_FAlpha->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, wxT("RGB Color"), wxPoint(543, 102), wxDefaultSize, 0, wxT("WxStaticText1"));
	WxStaticText1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText2 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT2, wxT("Alpha Value"), wxPoint(639, 102), wxDefaultSize, 0, wxT("WxStaticText2"));
	WxStaticText2->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	Initial = new wxStaticText(WxPanel1, ID_INITIAL, wxT("Initial"), wxPoint(495, 144), wxDefaultSize, 0, wxT("Initial"));
	Initial->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText3 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT3, wxT("Final"), wxPoint(495, 186), wxDefaultSize, 0, wxT("WxStaticText3"));
	WxStaticText3->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_ICRand = new wxSlider(WxPanel1, ID_SLD_ICRAND, 0, 0, 100, wxPoint(789, 118), wxSize(58, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_ICRand"));
	sld_ICRand->SetRange(0,100);
	sld_ICRand->SetValue(0);
	sld_ICRand->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FCRand = new wxSlider(WxPanel1, ID_SLD_FCRAND, 0, 0, 100, wxPoint(789, 163), wxSize(58, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FCRand"));
	sld_FCRand->SetRange(0,100);
	sld_FCRand->SetValue(0);
	sld_FCRand->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText4 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT4, wxT("Randomness"), wxPoint(797, 102), wxDefaultSize, 0, wxT("WxStaticText4"));
	WxStaticText4->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_ISize = new wxSlider(WxPanel1, ID_SLD_ISIZE, 0, 0, 255, wxPoint(535, 251), wxSize(195, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_ISize"));
	sld_ISize->SetRange(0,255);
	sld_ISize->SetValue(0);
	sld_ISize->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FSize = new wxSlider(WxPanel1, ID_SLD_FSIZE, 0, 0, 255, wxPoint(535, 296), wxSize(197, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FSize"));
	sld_FSize->SetRange(0,255);
	sld_FSize->SetValue(0);
	sld_FSize->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IRSize = new wxSlider(WxPanel1, ID_SLD_IRSIZE, 0, 0, 100, wxPoint(737, 251), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IRSize"));
	sld_IRSize->SetRange(0,100);
	sld_IRSize->SetValue(0);
	sld_IRSize->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FRSize = new wxSlider(WxPanel1, ID_SLD_FRSIZE, 0, 0, 100, wxPoint(737, 296), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FRSize"));
	sld_FRSize->SetRange(0,100);
	sld_FRSize->SetValue(0);
	sld_FRSize->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText5 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT5, wxT("Randomness"), wxPoint(749, 233), wxDefaultSize, 0, wxT("WxStaticText5"));
	WxStaticText5->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText6 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT6, wxT("Size"), wxPoint(495, 233), wxDefaultSize, 0, wxT("WxStaticText6"));
	WxStaticText6->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText7 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT7, wxT("Final"), wxPoint(495, 313), wxDefaultSize, 0, wxT("WxStaticText7"));
	WxStaticText7->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText8 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT8, wxT("Initial"), wxPoint(495, 270), wxDefaultSize, 0, wxT("WxStaticText8"));
	WxStaticText8->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FRAngle = new wxSlider(WxPanel1, ID_SLD_FRANGLE, 0, 0, 100, wxPoint(737, 552), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FRAngle"));
	sld_FRAngle->SetRange(0,100);
	sld_FRAngle->SetValue(0);
	sld_FRAngle->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IRAngle = new wxSlider(WxPanel1, ID_SLD_IRANGLE, 0, 0, 100, wxPoint(737, 507), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IRAngle"));
	sld_IRAngle->SetRange(0,100);
	sld_IRAngle->SetValue(0);
	sld_IRAngle->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText9 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT9, wxT("Randomness"), wxPoint(749, 489), wxDefaultSize, 0, wxT("WxStaticText9"));
	WxStaticText9->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText10 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT10, wxT("Angle"), wxPoint(495, 489), wxDefaultSize, 0, wxT("WxStaticText10"));
	WxStaticText10->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IAngle = new wxSlider(WxPanel1, ID_SLD_IANGLE, 0, 0, 255, wxPoint(535, 507), wxSize(195, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IAngle"));
	sld_IAngle->SetRange(0,255);
	sld_IAngle->SetValue(0);
	sld_IAngle->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FAngle = new wxSlider(WxPanel1, ID_SLD_FANGLE, 0, 0, 255, wxPoint(535, 552), wxSize(197, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FAngle"));
	sld_FAngle->SetRange(0,255);
	sld_FAngle->SetValue(0);
	sld_FAngle->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText11 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT11, wxT("Final"), wxPoint(495, 569), wxDefaultSize, 0, wxT("WxStaticText11"));
	WxStaticText11->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText12 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT12, wxT("Initial"), wxPoint(495, 526), wxDefaultSize, 0, wxT("WxStaticText12"));
	WxStaticText12->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText13 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT13, wxT("Radius"), wxPoint(495, 361), wxDefaultSize, 0, wxT("WxStaticText13"));
	WxStaticText13->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IRadius = new wxSlider(WxPanel1, ID_SLD_IRADIUS, 0, 0, 255, wxPoint(535, 379), wxSize(195, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IRadius"));
	sld_IRadius->SetRange(0,255);
	sld_IRadius->SetValue(0);
	sld_IRadius->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FRadius = new wxSlider(WxPanel1, ID_SLD_FRADIUS, 0, 0, 255, wxPoint(535, 424), wxSize(197, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FRadius"));
	sld_FRadius->SetRange(0,255);
	sld_FRadius->SetValue(0);
	sld_FRadius->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText14 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT14, wxT("Final"), wxPoint(495, 441), wxDefaultSize, 0, wxT("WxStaticText14"));
	WxStaticText14->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText15 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT15, wxT("Initial"), wxPoint(495, 398), wxDefaultSize, 0, wxT("WxStaticText15"));
	WxStaticText15->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText16 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT16, wxT("Randomness"), wxPoint(749, 361), wxDefaultSize, 0, wxT("WxStaticText16"));
	WxStaticText16->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IRRadius = new wxSlider(WxPanel1, ID_SLD_IRRADIUS, 0, 0, 100, wxPoint(737, 379), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IRRadius"));
	sld_IRRadius->SetRange(0,100);
	sld_IRRadius->SetValue(0);
	sld_IRRadius->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_FRRadius = new wxSlider(WxPanel1, ID_SLD_FRRADIUS, 0, 0, 100, wxPoint(737, 424), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_FRRadius"));
	sld_FRRadius->SetRange(0,100);
	sld_FRRadius->SetValue(0);
	sld_FRRadius->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText17 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT17, wxT("Initial"), wxPoint(495, 62), wxDefaultSize, 0, wxT("WxStaticText17"));
	WxStaticText17->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IEnergy = new wxSlider(WxPanel1, ID_SLD_IENERGY, 0, 0, 255, wxPoint(535, 43), wxSize(195, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IEnergy"));
	sld_IEnergy->SetRange(0,255);
	sld_IEnergy->SetValue(0);
	sld_IEnergy->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText18 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT18, wxT("Energy"), wxPoint(495, 25), wxDefaultSize, 0, wxT("WxStaticText18"));
	WxStaticText18->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticText19 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT19, wxT("Randomness"), wxPoint(749, 25), wxDefaultSize, 0, wxT("WxStaticText19"));
	WxStaticText19->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	sld_IREnergy = new wxSlider(WxPanel1, ID_SLD_IRENERGY, 0, 0, 100, wxPoint(737, 43), wxSize(113, 40), wxSL_HORIZONTAL | wxSL_LABELS | wxSL_SELRANGE , wxDefaultValidator, wxT("sld_IREnergy"));
	sld_IREnergy->SetRange(0,100);
	sld_IREnergy->SetValue(0);
	sld_IREnergy->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	cp_IColor = new wxColourPickerCtrl(WxPanel1, ID_CP_ICOLOR, wxColour(255,0,255), wxPoint(544, 136), wxSize(24, 24), wxCLRP_DEFAULT_STYLE, wxDefaultValidator, wxT("cp_IColor"));
	cp_IColor->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	cp_FColor = new wxColourPickerCtrl(WxPanel1, ID_CP_FCOLOR, wxColour(255,255,0), wxPoint(544, 176), wxSize(24, 24), wxCLRP_DEFAULT_STYLE, wxDefaultValidator, wxT("cp_FColor"));
	cp_FColor->SetBackgroundColour(wxColour(192,192,192));
	cp_FColor->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine1 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE1, wxPoint(480, 352), wxSize(390, -1), wxLI_HORIZONTAL);
	WxStaticLine1->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine2 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE2, wxPoint(480, 480), wxSize(390, -1), wxLI_HORIZONTAL);
	WxStaticLine2->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine3 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE3, wxPoint(480, 224), wxSize(390, -1), wxLI_HORIZONTAL);
	WxStaticLine3->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	WxStaticLine4 = new wxStaticLine(WxPanel1, ID_WXSTATICLINE4, wxPoint(480, 88), wxSize(390, -1), wxLI_HORIZONTAL);
	WxStaticLine4->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	dlg_Open =  new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("*.PAK"), wxOPEN);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILE_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_FILE_1001_Mnu_Obj->Append(ID_MNU_NEWPAKZFILE_1002, wxT("New PAKZ File"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILE_1001_Mnu_Obj->Append(ID_MNU_LOADPAKZFILE_1005, wxT("Load PAKZ File"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILE_1001_Mnu_Obj->Append(ID_MNU_SAVEPAKZFILE_1004, wxT("Save PAKZ File"), wxT(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILE_1001_Mnu_Obj, wxT("File"));
	SetMenuBar(WxMenuBar1);

	dlg_SelectIColor =  new wxColourDialog(this);

	dlg_SelectFColor =  new wxColourDialog(this);

	wxArrayString arrayStringFor_cb_PSGList;
	cb_PSGList = new wxComboBox(WxPanel1, ID_CB_PSGLIST, wxT(""), wxPoint(24, 488), wxSize(345, 22), arrayStringFor_cb_PSGList, 0, wxDefaultValidator, wxT("cb_PSGList"));
	cb_PSGList->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

	SetTitle(wxT("PAKZ File Mgr"));
	SetIcon(wxNullIcon);
	SetSize(8,8,887,657);
	
	////GUI Items Creation End
	CLoop::Init((void*)pn_Display->GetHandle());

	// Retrieve list of current particle system generators
	SetupPSGList();

	// Set controls using current particle system generator values	
	SetupControls();
}
// ----------------------------------------------------------------------------
void CGUI::OnClose(wxCloseEvent& event)
{
	Destroy();
}
// ----------------------------------------------------------------------------
/*
 * Mnunewpakzfile1002Click
 */
void CGUI::Mnunewpakzfile1002Click(wxCommandEvent& event)
{
	// insert your code here
}
// ----------------------------------------------------------------------------
/*
 * Mnuloadpakzfile1003Click
 */
void CGUI::Mnuloadpakzfile1003Click(wxCommandEvent& event)
{
	// insert your code here
}
// ----------------------------------------------------------------------------
/*
 * Mnusavepakzfile1004Click
 */
void CGUI::Mnusavepakzfile1004Click(wxCommandEvent& event)
{
	// insert your code here
}
// ----------------------------------------------------------------------------
/*
 * Mnuloadpakzfile1005Click
 */
void CGUI::Mnuloadpakzfile1005Click(wxCommandEvent& event)
{
	// insert your code here
}
// ----------------------------------------------------------------------------
void CGUI::OnIdle(wxIdleEvent& event)
{
	// insert your code here
	CLoop::Loop();
	event.RequestMore();
}
// ----------------------------------------------------------------------------
// Builds the list of currently available particle system generators
// ----------------------------------------------------------------------------
void CGUI::SetupPSGList()
{
	cb_PSGList->Clear();

	for (uint i=0;i<CGPSysGenWH::I()->uiNumElems();i++)
	{
		CGParticleSystemGenerator* poPSG = CGPSysGenWH::I()->poGet(i);
		CGString sName = CGPSysGenWH::I()->sGetName(poPSG);
	
		cb_PSGList->Insert( wxString( sName.szString(), wxConvUTF8 ),i );
	}
}
// ----------------------------------------------------------------------------
void CGUI::SetupControls()
{
	// Energy
	sld_IEnergy->SetValue( sld_IEnergy->GetMax() * (globals.m_poPSGQ->fGetInitialEnergy()/PSYSGEN_ENERGY_MULT));
	sld_IREnergy->SetValue(sld_IREnergy->GetMax() * globals.m_poPSGQ->fGetInitialEnergyRnds());

	// Colors and alphas
	CGColor oIColor = globals.m_poPSGQ->oGetInitialColor();
	wxColour oInitialColor(oIColor.r*255.0f,oIColor.g*255.0f,oIColor.b*255.0f);
	cp_IColor->SetColour(oInitialColor);
	sld_IAlpha->SetValue(oIColor.a * sld_IAlpha->GetMax());

	CGColor oFColor = globals.m_poPSGQ->oGetFinalColor();
	wxColour oFinalColor(oFColor.r*255.0f,oFColor.g*255.0f,oFColor.b*255.0f);
	cp_FColor->SetColour(oFinalColor);
	sld_FAlpha->SetValue(oFColor.a * sld_FAlpha->GetMax());
	
	sld_ICRand->SetValue(globals.m_poPSGQ->fGetInitialColorRnds()*sld_ICRand->GetMax());
	sld_FCRand->SetValue(globals.m_poPSGQ->fGetFinalColorRnds()*sld_FCRand->GetMax());

	// Size
	sld_ISize->SetValue(sld_ISize->GetMax() * (globals.m_poPSGQ->fGetInitialSize()/PSYSGEN_SIZE_MULT));
	sld_FSize->SetValue(sld_FSize->GetMax() * (globals.m_poPSGQ->fGetFinalSize()/PSYSGEN_SIZE_MULT));
	sld_IRSize->SetValue(sld_IRSize->GetMax() * globals.m_poPSGQ->fGetInitialSizeRnds());
	sld_FRSize->SetValue(sld_FRSize->GetMax() * globals.m_poPSGQ->fGetFinalSizeRnds());

	// Angle
	sld_IAngle->SetValue(sld_IAngle->GetMax() * (globals.m_poPSGQ->fGetInitialAngle()/_2PI_));
	sld_FAngle->SetValue(sld_FAngle->GetMax() * (globals.m_poPSGQ->fGetFinalAngle()/_2PI_));
	sld_IRAngle->SetValue(sld_IRAngle->GetMax() * globals.m_poPSGQ->fGetInitialAngleRnds());
	sld_FRAngle->SetValue(sld_FRAngle->GetMax() * globals.m_poPSGQ->fGetFinalAngleRnds());

	// Radius
	sld_IRadius->SetValue(sld_IRadius->GetMax() * (globals.m_poPSGQ->fGetInnerRadius()/PSYSGEN_RADIUS_MULT));
	sld_FRadius->SetValue(sld_FRadius->GetMax() * (globals.m_poPSGQ->fGetOuterRadius()/PSYSGEN_RADIUS_MULT));
	sld_IRRadius->SetValue(sld_IRRadius->GetMax() * globals.m_poPSGQ->fGetInnerRadiusRnds());
	sld_FRRadius->SetValue(sld_FRRadius->GetMax() * globals.m_poPSGQ->fGetOuterRadiusRnds());

}
// ----------------------------------------------------------------------------
void CGUI::SetupParticleSystem()
{
	// Energy
	float fIEnergy  = PSYSGEN_ENERGY_MULT*(float)sld_IEnergy->GetValue() / (float)sld_IEnergy->GetMax();
	float fIREnergy = (float)sld_IREnergy->GetValue() / (float)sld_IREnergy->GetMax();
	globals.m_poPSGQ->SetEnergyFact(fIEnergy,fIREnergy);

	// Colors and alphas
	float fIAlpha = (float)sld_IAlpha->GetValue() / (float)sld_IAlpha->GetMax();
	wxColour oInitialColor = cp_IColor->GetColour();
	CGColor  oIColor(oInitialColor.Red()/255.0f,oInitialColor.Green()/255.0f,oInitialColor.Blue()/255.0f,fIAlpha);

	float fFAlpha = (float)sld_FAlpha->GetValue() / (float)sld_FAlpha->GetMax();
	wxColour oFinalColor = cp_FColor->GetColour();
	CGColor oFColor(oFinalColor.Red()/255.0f,oFinalColor.Green()/255.0f,oFinalColor.Blue()/255.0f,fFAlpha);

	float fIRFactor = (float)sld_ICRand->GetValue() / (float)sld_ICRand->GetMax();
	float fFRFactor = (float)sld_FCRand->GetValue() / (float)sld_FCRand->GetMax();

	globals.m_poPSGQ->SetColorsPars(oIColor,oFColor,fIRFactor,fFRFactor);

	// Size
	float fISize  = PSYSGEN_SIZE_MULT * (float)sld_ISize->GetValue() / (float)sld_ISize->GetMax();
	float fFSize  = PSYSGEN_SIZE_MULT * (float)sld_FSize->GetValue() / (float)sld_FSize->GetMax();
	float fIRSize = (float)sld_IRSize->GetValue() / (float)sld_IRSize->GetMax();
	float fFRSize = (float)sld_FRSize->GetValue() / (float)sld_FRSize->GetMax();

	globals.m_poPSGQ->SetSizePars(fISize,fFSize,fIRSize,fFRSize);

	// Angle
	float fIAngle  = _2PI_ * (float)sld_IAngle->GetValue() / (float)sld_IAngle->GetMax();
	float fFAngle  = _2PI_ * (float)sld_FAngle->GetValue() / (float)sld_FAngle->GetMax();
	float fIRAngle = (float)sld_IRAngle->GetValue() / (float)sld_IRAngle->GetMax();
	float fFRAngle = (float)sld_FRAngle->GetValue() / (float)sld_FRAngle->GetMax();

	globals.m_poPSGQ->SetAnglePars(fIAngle,fFAngle,fIRAngle,fFRAngle);

	// Radius
	float fIRadius  = PSYSGEN_RADIUS_MULT * (float)sld_IRadius->GetValue() / (float)sld_IRadius->GetMax();
	float fFRadius  = PSYSGEN_RADIUS_MULT * (float)sld_FRadius->GetValue() / (float)sld_FRadius->GetMax();
	float fIRRadius = (float)sld_IRRadius->GetValue() / (float)sld_IRRadius->GetMax();
	float fFRRadius = (float)sld_FRRadius->GetValue() / (float)sld_FRRadius->GetMax();

	globals.m_poPSGQ->SetRadiusPars(fIRadius,fFRadius,fIRRadius,fFRRadius);
}
// ----------------------------------------------------------------------------
/*
 * sld_FAlphaSlider
 */
void CGUI::sld_FAlphaSlider(wxCommandEvent& event)
{
	// insert your code here
	SetupParticleSystem();
}
// ----------------------------------------------------------------------------

/*
 * cp_FColorColourChanged
 */
void CGUI::cp_FColorColourChanged(wxColourPickerEvent& event)
{
	// insert your code here
	SetupParticleSystem();
}
// ----------------------------------------------------------------------------
/*
 * cp_IColorColourChanged
 */
void CGUI::cp_IColorColourChanged(wxColourPickerEvent& event)
{
	// insert your code here
	SetupParticleSystem();
}
// ----------------------------------------------------------------------------
/*
 * WxComboBox1Selected
 */
void CGUI::WxComboBox1Selected(wxCommandEvent& event )
{
	// insert your code here

	// Retrieve the current particle system generator and setup window controls with its current values
	CGPSGGenericQuad* poSelPSG = (CGPSGGenericQuad*)CGPSysGenWH::I()->poFind( cb_PSGList->GetValue().c_str() );	
	
	// Ñapa ...
	*globals.m_poPSGQ = *poSelPSG;

	SetupControls();
}
// ----------------------------------------------------------------------------
