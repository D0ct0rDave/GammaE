//---------------------------------------------------------------------------
//
// Name:        ParticleEditor.h
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------
#ifndef Globals_h
#define Globals_h
//---------------------------------------------------------------------------
#include "GammaE.h"
//---------------------------------------------------------------------------
typedef struct TGlobals
{

	CGPSGGenericQuad*	m_poPSGQ;

	HWND				m_hWnd;
	uint				m_uiScrWidth;
	uint				m_uiScrHeight;
	float				m_fTime;
	CGChrono			m_oChrono;

}TGlobals;


extern TGlobals globals;
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
