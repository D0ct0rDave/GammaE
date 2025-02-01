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
class CLoop
{
	public:
		static void Init(void* _hWnd);
		static void Update(float _fDeltaT);
		static void Render();
		static void Loop();
		
		static void LoadGTS(char* _szFilename,char* _szDirectory);
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
