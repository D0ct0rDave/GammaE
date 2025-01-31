//---------------------------------------------------------------------------
//
// Name:        FGASViewerGUI.cpp
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: CGASViewerGUI class implementation
//
//---------------------------------------------------------------------------

#include "FGASViewerGUI.h"
#include "CLoop.h"

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// CGASViewerGUI
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(CGASViewerGUI,wxFrame)
	////Manual Code Start
	EVT_IDLE(CGASViewerGUI::OnIdle)
	////Manual Code End
	
	EVT_CLOSE(CGASViewerGUI::OnClose)
	EVT_BUTTON(ID_WXBUTTON1,CGASViewerGUI::WxButton1Click)
	EVT_COMBOBOX(ID_CB_MATERIALLIST,CGASViewerGUI::cb_MaterialListSelected)
	EVT_TIMER(ID_WXTIMER1,CGASViewerGUI::WxTimer1Timer)
	EVT_MENU(ID_MNU_OPENGASFILE_1006, CGASViewerGUI::MnuopenGASfile1006Click)
	EVT_MENU(ID_MNU_OPENGTSFILE_1005, CGASViewerGUI::MnuopenGTSfile1005Click)
	EVT_MENU(ID_MNU_LOADGEMFILE_1009, CGASViewerGUI::Mnuloadgemfile1009Click)
	EVT_MENU(ID_MNU_SAVEGEMFILE_1002, CGASViewerGUI::Mnusavegemfile1002Click)
	EVT_MENU(ID_MNU_QUIT_1004, CGASViewerGUI::Mnuquit1004Click)
END_EVENT_TABLE()
////Event Table End

CGASViewerGUI::CGASViewerGUI(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

CGASViewerGUI::~CGASViewerGUI()
{
}

void CGASViewerGUI::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxArrayString arrayStringFor_rb_UnitSys;
	arrayStringFor_rb_UnitSys.Add(wxT("Meters"));
	arrayStringFor_rb_UnitSys.Add(wxT("Centimeters"));
	rb_UnitSys = new wxRadioBox(this, ID_RB_UNITSYS, wxT("Unit System:"), wxPoint(840, 192), wxSize(193, 81), arrayStringFor_rb_UnitSys, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, wxT("rb_UnitSys"));
	rb_UnitSys->SetSelection(0);

	WxButton1 = new wxButton(this, ID_WXBUTTON1, wxT("Load Texture"), wxPoint(824, 48), wxSize(227, 25), 0, wxDefaultValidator, wxT("WxButton1"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, wxT("Select Predefined Material:"), wxPoint(824, 88), wxDefaultSize, 0, wxT("WxStaticText3"));

	wxArrayString arrayStringFor_cb_MaterialList;
	cb_MaterialList = new wxComboBox(this, ID_CB_MATERIALLIST, wxT(""), wxPoint(824, 112), wxSize(225, 23), arrayStringFor_cb_MaterialList, 0, wxDefaultValidator, wxT("cb_MaterialList"));

	WxStaticBox4 = new wxStaticBox(this, ID_WXSTATICBOX4, wxT("Materials:"), wxPoint(808, 16), wxSize(257, 145));

	dlg_SaveGEM =  new wxFileDialog(this, wxT("Save GEM File:"), wxT(""), wxT(""), wxT("*.gem"), wxSAVE);

	WxTimer1 = new wxTimer();
	WxTimer1->SetOwner(this, ID_WXTIMER1);
	WxTimer1->Start(100);

	dlg_OpenGAS =  new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("*.gas"), wxOPEN);
	dlg_OpenGTS =  new wxFileDialog(this, wxT("Choose a file"), wxT(""), wxT(""), wxT("*.gts"), wxOPEN);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILEMENU_1001_Mnu_Obj = new wxMenu(0);
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU_OPENGASFILE_1006, wxT("Open GAS File"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU_OPENGTSFILE_1005, wxT("Open GTS File"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILEMENU_1001_Mnu_Obj->AppendSeparator();
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU_LOADGEMFILE_1009, wxT("Load GEM File"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU_SAVEGEMFILE_1002, wxT("Save GEM File"), wxT(""), wxITEM_NORMAL);
	ID_MNU_FILEMENU_1001_Mnu_Obj->AppendSeparator();
	ID_MNU_FILEMENU_1001_Mnu_Obj->Append(ID_MNU_QUIT_1004, wxT("Quit"), wxT(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILEMENU_1001_Mnu_Obj, wxT("File"));
	SetMenuBar(WxMenuBar1);

	dlg_LoadGEM =  new wxFileDialog(this, wxT("Load GEM file"), wxT(""), wxT(""), wxT("*.gem"), wxOPEN);

	WxStaticBox3 = new wxStaticBox(this, ID_WXSTATICBOX3, wxT("WxStaticBox3"), wxPoint(840, -152), wxSize(257, 145));

	ed_Info = new wxTextCtrl(this, ID_ED_INFO, wxT(""), wxPoint(824, 352), wxSize(225, 161), wxTE_READONLY | wxTE_MULTILINE, wxDefaultValidator, wxT("ed_Info"));

	WxStaticBox2 = new wxStaticBox(this, ID_WXSTATICBOX2, wxT("Info:"), wxPoint(808, 304), wxSize(257, 265));

	WxStaticBox1 = new wxStaticBox(this, ID_WXSTATICBOX1, wxT("Misc:"), wxPoint(808, 168), wxSize(257, 121));

	dsp = new wxStaticBitmap(this, ID_DSP, wxNullBitmap, wxPoint(39, 14), wxSize(739, 554) );
	dsp->Enable(false);
	dsp->SetBackgroundColour(*wxGREEN);

	SetTitle(wxT("GASViewer"));
	SetIcon(wxNullIcon);
	SetSize(8,8,1096,643);
	Center();
	
	////GUI Items Creation End
	CLoop::Init((void*)dsp->GetHandle());
	
	// Build shader list	
	cb_MaterialList->Clear();
	for (uint i=0;i<CGShaderDefWH::I()->uiNumElems();i++)
	{
		CGTextResource* poShader = CGShaderDefWH::I()->poGet(i);
		CGString sName = CGShaderDefWH::I()->sGetName(poShader);
	
		cb_MaterialList->Insert( wxString( sName.szString(), wxConvUTF8 ),i );
	}
}

void CGASViewerGUI::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * Mnusavegemfile1002Click
 */
void CGASViewerGUI::Mnusavegemfile1002Click(wxCommandEvent& event)
{
	// insert your code here
	
	// insert your code here
	if (dlg_SaveGEM->ShowModal() == wxID_OK)
	{
		wxString wxsFilename  = dlg_SaveGEM->GetFilename();
		wxString wxsDirectory = dlg_SaveGEM->GetDirectory();

		wxString wxsFullFilename = wxsDirectory + wxT("\\") + wxsFilename;
		
		// wxString wxsFullFilename = wxsDirectory + "\\" + wxsFilename;		
		CLoop::SaveGEM( (char*)wxsFullFilename.char_str() );
	}
}

/*
 * Mnuquit1004Click
 */
void CGASViewerGUI::Mnuquit1004Click(wxCommandEvent& event)
{
	// insert your code here
	exit(0);
}

/*
 * Mnufile1005Click
 */
void CGASViewerGUI::Mnufile1005Click(wxCommandEvent& event)
{
	// insert your code here

}

/*
 * MnuopenGASfile1005Click
 */
void CGASViewerGUI::MnuopenGASfile1006Click(wxCommandEvent& event)
{
	// insert your code here
	if (dlg_OpenGAS->ShowModal() == wxID_OK)
	{
		wxString wxsFilename = dlg_OpenGAS->GetFilename();
		wxString wxsDirectory = dlg_OpenGAS->GetDirectory();
		
		wxString wxsFullFilename = wxsDirectory + wxT("\\") + wxsFilename;

		CLoop::LoadGAS( (char*)wxsFullFilename.char_str(),(char*)wxsDirectory.char_str() );
		ShowInfo();
	}
}

/*
 * MnuopenGTSfile1005Click
 */
void CGASViewerGUI::MnuopenGTSfile1005Click(wxCommandEvent& event)
{
	// insert your code here
	if (dlg_OpenGTS->ShowModal() == wxID_OK)
	{
		wxString wxsFilename = dlg_OpenGTS->GetFilename();
		wxString wxsDirectory = dlg_OpenGTS->GetDirectory();
		
		wxString wxsFullFilename = wxsDirectory + wxT("\\") + wxsFilename;

		CLoop::LoadGTS( (char*)wxsFullFilename.char_str(),(char*)wxsDirectory.char_str() );
	}
}

/*
 * Mnuloadgemfile1009Click
 */
void CGASViewerGUI::Mnuloadgemfile1009Click(wxCommandEvent& event)
{
	// insert your code here
	if (dlg_LoadGEM->ShowModal() == wxID_OK)
	{
		wxString wxsFilename = dlg_LoadGEM->GetFilename();
		wxString wxsDirectory = dlg_LoadGEM->GetDirectory();
		
		wxString wxsFullFilename = wxsDirectory + wxT("\\") + wxsFilename;
		
		CLoop::LoadGEM( (char*)wxsFullFilename.char_str());
		ShowInfo();
	}	
}

/*
 * WxstaticClick
 */
void CGASViewerGUI::WxstaticClick(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * WxTimer1Timer
 */
void CGASViewerGUI::WxTimer1Timer(wxTimerEvent& event)
{
	// insert your code here
//	CLoop::Loop();
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

void CGASViewerGUI::OnIdle(wxIdleEvent& event)
{
	// insert your code here
	CLoop::Loop();
	event.RequestMore();
}

void CGASViewerGUI::ShowInfo()
{
	if ((CLoop::m_poScene== NULL) || CLoop::m_poScene->eGetNodeType() != ESceneNodeType::SNT_AnimActionSet) return;

	CGSceneAnimMesh* poAM = (CGSceneAnimMesh*) ((CGSceneAnimActionSet*)CLoop::m_poScene)->poGetAnimObj();
	// CObject3D_Leaf* poLeaf = ((CObject3D_AnimMesh*) poAM)->GetLeaf();

	// Fill info panel
	CGGraphBV* poBV = poAM->poGetBV();
	CGVect3 oMaxs = poBV->oGetMax();
	CGVect3 oMins = poBV->oGetMin();
	CGVect3 oExtents = poBV->GetExtents();
	CGVect3 oCenter = poBV->oGetCenter();

	char szStr[1024];
	sprintf(szStr,"Number of animaton frames: \n"
				  "%d\n"
				  "Number of vertexs: \n"
				  "%d\n"
				  "Bounding Volume`max/mins: \n"
				  "(%.3f,%.3f,%.3f) - (%.3f,%.3f,%.3f)\n"
				  "Bounding Volume center: \n"
				  "(%.3f,%.3f,%.3f)\n"
				  "Bounding Volume Extents: \n"
				  "(%.3f,%.3f,%.3f)\n",
				  poAM->uiGetNumStates(),
				  poAM->uiGetNumFrameVXs(),
				  oMins.x,oMins.y,oMins.z,
				  oMaxs.x,oMaxs.y,oMaxs.z,
				  oCenter.x,oCenter.y,oCenter.z,
				  oExtents.x,oExtents.y,oExtents.z);

	// wxChar* c = wxTRANSLATE(szStr);
	wxString s( szStr, wxConvUTF8 );

	ed_Info->Clear();
	ed_Info->WriteText( s );
}

/*
 * cb_MaterialListSelected
 */
void CGASViewerGUI::cb_MaterialListSelected(wxCommandEvent& event )
{
	// insert your code here
	CGShader* poShader = CGShaderWH::I()->poCreateShader( cb_MaterialList->GetValue().char_str() );

	if (poShader)
	{
		SCNUt_ShaderAssigner oSA;
		oSA.AssignShader(poShader,CLoop::m_poScene);
	}
}

/*
 * WxButton1Click
 */
void CGASViewerGUI::WxButton1Click(wxCommandEvent& event)
{
	// insert your code here
	wxFileDialog dlgLoadTexture(
    this,
    wxT("Choose Image"),
    ::wxGetWorkingDirectory(),
    wxT(""),
	wxT("Image Files ") + wxImage::GetImageExtWildcard(),
    wxOPEN );

	// insert your code here
	if (dlgLoadTexture.ShowModal() == wxID_OK)
	{
		wxString wxsFilename = dlgLoadTexture.GetFilename();
		wxString wxsDirectory = dlgLoadTexture.GetDirectory();
		wxString wxsFullFilename = wxsDirectory + wxT("\\") + wxsFilename;

		CGShader* poShader = CGShaderWH::I()->poCreateShader( wxsFullFilename.char_str() );

		if (poShader)
		{
			SCNUt_ShaderAssigner oSA;
			oSA.AssignShader(poShader,CLoop::m_poScene);
		}

		// wxString wxsFullFilename = wxsDirectory + "\\" + wxsFilename;		
		// CLoop::LoadGTS( (char*)wxsFilename.c_str(),(char*)wxsDirectory.c_str() );
	}
}
