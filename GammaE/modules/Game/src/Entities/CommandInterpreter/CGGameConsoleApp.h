//-----------------------------------------------------------------------------
#ifndef CGameConsoleApp_h
#define CGameConsoleApp_h 1
//-----------------------------------------------------------------------------
#include "GammaE_SceneObjects.h"
#include "CGGameApplication.h"
//-----------------------------------------------------------------------------
class CGGameConsoleApp : public CGGameApplication
{
  public:
		PUBLISH_GAMEENTITY_CLASSNAME;
		
		CGGameConsoleApp();
		~CGGameConsoleApp();

		virtual void Init();
		virtual void Init(int _iCols,int _iRows);
		virtual void Print(const char *_szFmt,...);
		virtual void Type(char _char);

		void NewLine();
		void DumpData();
		void Cls();

		virtual void Think(float _fDeltaT);

  protected:
      CConsole* poConsole;

      char*m_pucBuff;
      int m_iCurX;
      int m_iCurY;
      int m_iRows;
      int m_iCols;
};

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
