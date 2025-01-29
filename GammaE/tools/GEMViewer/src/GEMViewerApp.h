//---------------------------------------------------------------------------
//
// Name:        GEMViewerApp.h
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __CGEMVIEWERGUIApp_h__
#define __CGEMVIEWERGUIApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif
 
#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class CGEMViewerGUIApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
