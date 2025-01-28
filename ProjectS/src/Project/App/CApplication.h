//---------------------------------------------------------------------------
//
// Name:        CApplication.h
// Author:      PepeMagnifico
// Created:     27/04/2009 19:49:10
// Description: 
//
//---------------------------------------------------------------------------
#ifndef CApplicationH
#define CApplicationH
//---------------------------------------------------------------------------
class CApplication
{
	public:
		static void OnCreate(void *_pParam,char *pszCmdLine);
		static void OnDestroy(void *_pParam);
		static bool bFinishApp();

		static void OnIdle();
		static void OnResize(unsigned int _uiNewWidth,unsigned int _uiNewHeight);

		static void OnButtonDown  (unsigned int _uiButton);
		static void OnButtonUp    (unsigned int _uiButton);
		static void OnButtonPress (unsigned int _uiButton);
		static void OnCursorMove	(unsigned int _uiX,unsigned int _uiY,bool _bPushedButtons);

	protected:
		static void Register();
};
//---------------------------------------------------------------------------
#endif
//---------------------------------------------------------------------------
