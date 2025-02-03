//---------------------------------------------------------------------------
//
// Name:        GTSViewerApp.h
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __wxSampleToolApp_h__
#define __wxSampleToolApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class wxSampleToolApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
