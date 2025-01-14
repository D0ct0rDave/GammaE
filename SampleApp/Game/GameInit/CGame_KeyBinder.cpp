//## begin module%3BDC909002FF.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3BDC909002FF.cm

//## begin module%3BDC909002FF.cp preserve=no
//## end module%3BDC909002FF.cp

//## Module: CGame_KeyBinder%3BDC909002FF; Pseudo Package body
//## Source file: i:\Projects\GammaE\Game\GameInit\CGame_KeyBinder.cpp

//## begin module%3BDC909002FF.additionalIncludes preserve=no
//## end module%3BDC909002FF.additionalIncludes

//## begin module%3BDC909002FF.includes preserve=yes
#include <stdlib.h>
#include <string.h>

#include "Input/Commands/GammaE_Commands.h"
#include "Input/CommandBinder/CommandBinder.h"
//## end module%3BDC909002FF.includes

// CGame_KeyBinder
#include "Game\GameInit\CGame_KeyBinder.h"
//## begin module%3BDC909002FF.additionalDeclarations preserve=yes
//## end module%3BDC909002FF.additionalDeclarations


// Class CGame_KeyBinder 



CGame_KeyBinder::CGame_KeyBinder()
  //## begin CGame_KeyBinder::CGame_KeyBinder%.hasinit preserve=no
  //## end CGame_KeyBinder::CGame_KeyBinder%.hasinit
  //## begin CGame_KeyBinder::CGame_KeyBinder%.initialization preserve=yes
  //## end CGame_KeyBinder::CGame_KeyBinder%.initialization
{
  //## begin CGame_KeyBinder::CGame_KeyBinder%.body preserve=yes
	
	// ---------------------------------------------------
	// Key bindings
	// ---------------------------------------------------
	KeyBindings.Init(256);
	KeyBindings.AddVar("UP"    ,(void *)38);
	KeyBindings.AddVar("DOWN"  ,(void *)40);
	KeyBindings.AddVar("LEFT"  ,(void *)37);
	KeyBindings.AddVar("RIGHT" ,(void *)39);
	KeyBindings.AddVar("TAB"   ,(void *) 9);
	KeyBindings.AddVar("ENTER" ,(void *)13);
	KeyBindings.AddVar("ESCAPE",(void *)27);
	KeyBindings.AddVar("SPACE" ,(void *)32);
	KeyBindings.AddVar("BACKSPACE",(void *)8);
	KeyBindings.AddVar("F1",(void *)112);
	KeyBindings.AddVar("F2",(void *)113);
	KeyBindings.AddVar("F3",(void *)114);
	KeyBindings.AddVar("F4",(void *)115);
	KeyBindings.AddVar("F5",(void *)116);
	KeyBindings.AddVar("F6",(void *)117);
	KeyBindings.AddVar("F7",(void *)118);
	KeyBindings.AddVar("F8",(void *)119);
	KeyBindings.AddVar("F9",(void *)120);
	KeyBindings.AddVar("F10",(void *)121);	// no chuta!!!!
	KeyBindings.AddVar("F11",(void *)122);
	KeyBindings.AddVar("F12",(void *)123);	
	KeyBindings.AddVar("º",  (void *)220);
	KeyBindings.AddVar("~",  (void *)220);	// tecla º,ª,\
	
	KeyBindings.AddVar("A",(void *)'A');
	KeyBindings.AddVar("B",(void *)'B');
	KeyBindings.AddVar("C",(void *)'C');
	KeyBindings.AddVar("D",(void *)'D');
	KeyBindings.AddVar("E",(void *)'E');
	KeyBindings.AddVar("F",(void *)'F');
	KeyBindings.AddVar("G",(void *)'G');
	KeyBindings.AddVar("H",(void *)'H');
	KeyBindings.AddVar("I",(void *)'I');
	KeyBindings.AddVar("J",(void *)'J');
	KeyBindings.AddVar("K",(void *)'K');
	KeyBindings.AddVar("L",(void *)'L');
	KeyBindings.AddVar("M",(void *)'M');
	KeyBindings.AddVar("N",(void *)'N');
	KeyBindings.AddVar("O",(void *)'O');
	KeyBindings.AddVar("P",(void *)'P');
	KeyBindings.AddVar("Q",(void *)'Q');
	KeyBindings.AddVar("R",(void *)'R');
	KeyBindings.AddVar("S",(void *)'S');
	KeyBindings.AddVar("T",(void *)'T');
	KeyBindings.AddVar("U",(void *)'U');
	KeyBindings.AddVar("V",(void *)'V');
	KeyBindings.AddVar("W",(void *)'W');
	KeyBindings.AddVar("X",(void *)'X');
	KeyBindings.AddVar("Y",(void *)'Y');
	KeyBindings.AddVar("Z",(void *)'Z');
	
	KeyBindings.AddVar("0",(void *)'0');
	KeyBindings.AddVar("1",(void *)'1');
	KeyBindings.AddVar("2",(void *)'2');
	KeyBindings.AddVar("3",(void *)'3');
	KeyBindings.AddVar("4",(void *)'4');
	KeyBindings.AddVar("5",(void *)'5');
	KeyBindings.AddVar("6",(void *)'6');
	KeyBindings.AddVar("7",(void *)'7');
	KeyBindings.AddVar("8",(void *)'8');
	KeyBindings.AddVar("9",(void *)'9');
	
	
	KeyBindings.AddVar("MOUSE",(void *)0);
	KeyBindings.AddVar("BUTTON0",(void*)CmdBinder_MOUSE_BUTTON0);
	KeyBindings.AddVar("BUTTON1",(void*)CmdBinder_MOUSE_BUTTON1);

	// ---------------------------------------------------
	// Command bindings
	// ---------------------------------------------------
	CmdBindings.Init(256);
	CmdBindings.AddVar("CamForward" ,(void *)KCMD_CAMFORWARD);
	CmdBindings.AddVar("CamBack"	,(void *)KCMD_CAMBACKWARD);
	CmdBindings.AddVar("CamLeft"	,(void *)KCMD_CAMLEFT);
	CmdBindings.AddVar("CamRight"	,(void *)KCMD_CAMRIGHT);
	CmdBindings.AddVar("CamUp"		,(void *)KCMD_CAMUP);
	CmdBindings.AddVar("CamDown"	,(void *)KCMD_CAMDOWN);

	CmdBindings.AddVar("Forward"	,(void *)KCMD_FORWARD);
	CmdBindings.AddVar("Back"		,(void *)KCMD_BACKWARD);
	CmdBindings.AddVar("Left"		,(void *)KCMD_LEFT);
	CmdBindings.AddVar("Right"		,(void *)KCMD_RIGHT);
	CmdBindings.AddVar("Up"			,(void *)KCMD_UP);
	CmdBindings.AddVar("Down"		,(void *)KCMD_DOWN);

	CmdBindings.AddVar("TurnUp"		,(void *)KCMD_TURNUP);
	CmdBindings.AddVar("TurnDown"	,(void *)KCMD_TURNDOWN);
	CmdBindings.AddVar("TurnLeft"	,(void *)KCMD_TURNLEFT);
	CmdBindings.AddVar("TurnRight"	,(void *)KCMD_TURNRIGHT);
	
	CmdBindings.AddVar("Attack" ,(void *)KCMD_BUTTON0);
	CmdBindings.AddVar("Attack2",(void *)KCMD_BUTTON1);
	CmdBindings.AddVar("Jump"	,(void *)KCMD_JUMP);
	CmdBindings.AddVar("GenMove",(void *)KCMD_GENMOVE);
	CmdBindings.AddVar("Exit",	 (void *)KCMD_EXIT);


	CmdBindings.AddVar("Func1",(void *)KCMD_FUNC1);
	CmdBindings.AddVar("Func2",(void *)KCMD_FUNC2);
	CmdBindings.AddVar("Func3",(void *)KCMD_FUNC3);
	CmdBindings.AddVar("Func4",(void *)KCMD_FUNC4);
	CmdBindings.AddVar("Func5",(void *)KCMD_FUNC5);
	CmdBindings.AddVar("Func6",(void *)KCMD_FUNC6);
	CmdBindings.AddVar("Func7",(void *)KCMD_FUNC7);
	CmdBindings.AddVar("Func8",(void *)KCMD_FUNC8);
	CmdBindings.AddVar("Func9",(void *)KCMD_FUNC9);
	CmdBindings.AddVar("Func0",(void *)KCMD_FUNC0);


	CmdBindings.AddVar("ToggleConsole",(void *)KCMD_TOGGLECONSOLE);
	CmdBindings.AddVar("Screenshot",(void *)KCMD_SCREENSHOT);
	// ---------------------------------------------------

  //## end CGame_KeyBinder::CGame_KeyBinder%.body
}


CGame_KeyBinder::~CGame_KeyBinder()
{
  //## begin CGame_KeyBinder::~CGame_KeyBinder%.body preserve=yes
  //## end CGame_KeyBinder::~CGame_KeyBinder%.body
}



//## Other Operations (implementation)
bool CGame_KeyBinder::Init (char *_szFilename)
{
  //## begin CGame_KeyBinder::Init%1004309119.body preserve=yes
	char	*StrBuff = ParseUtils_ReadFile(_szFilename);
	char	*StrPos  = StrBuff;
	char	*Token;
	unsigned int		uiKey;
	KEYCommand_Type	eCmd;

	if (! StrBuff) return (false);

	CmdBinder_InitBindTable();

	while (StrPos)
	{
		Token = ParseUtils_ParseToken(StrPos);

		if (! strcmp(Token,"bind"))
		{			
			Token  = ParseUtils_ParseToken(StrPos);

			uiKey = (unsigned int)KeyBindings.pGetVar(Token);

			Token  = ParseUtils_ParseToken(StrPos);

			eCmd = (KEYCommand_Type)((unsigned int)CmdBindings.pGetVar(Token));

			// Bind key to command
			if ((eCmd) && (uiKey))
				CmdBinder_BindKey(uiKey,eCmd);
		}
   else if(! strcmp(Token,"//"))
		{
			StrPos = ParseUtils_SkipLine(StrPos);
		}
	}

	free(StrBuff);	
	return (true);
	
  //## end CGame_KeyBinder::Init%1004309119.body
}

// Additional Declarations
  //## begin CGame_KeyBinder%3BDC909002FF.declarations preserve=yes
  //## end CGame_KeyBinder%3BDC909002FF.declarations

//## begin module%3BDC909002FF.epilog preserve=yes
//## end module%3BDC909002FF.epilog
