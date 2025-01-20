//---------------------------------------------------------------------------
//
// Name:        CLoop.h
// Author:      PepeMagnifico
// Created:     27/04/2009 17:56:10
// Description: 
//
//---------------------------------------------------------------------------
#ifndef CLoopH
#define CLoopH
//---------------------------------------------------------------------------
class CLoop
{
	public:
		static void Init();
		static void Finish();

		static bool bLoop(float _fDeltaT);
		static bool bUpdate(float _fDeltaT);
		static void Render();
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
