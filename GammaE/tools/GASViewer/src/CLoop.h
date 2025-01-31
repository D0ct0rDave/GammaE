//---------------------------------------------------------------------------
//
// Name:        CLoop.h
// Author:      PepeMagnifico
// Created:     13/04/2009 12:12:10
// Description: 
//
//---------------------------------------------------------------------------
#ifndef CLoopH
#define CLoopH
//---------------------------------------------------------------------------
#include "GammaE.h"
//---------------------------------------------------------------------------
class CLoop
{
	public:
		static void Init(void* _hWnd);
		static void Update(float _fDeltaT);
		static void Render();
		static void Loop();
		
		static void LoadGAS(char* _szFilename,char* _szDirectory);
		static void LoadGTS(char* _szFilename,char* _szDirectory);
		static void LoadGEM(char* _szFilename);
		static void SaveGEM(char* _szFilename);

	public:
		static CGSceneNode*		m_poScene;
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
