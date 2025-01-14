//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("MD2Conv.res");
USEFORM("MD2Convert.cpp", Form2);
USELIB("..\..\Borland\GammaE_E3D.lib");
USELIB("..\..\Borland\GammaE_FileSys.lib");
USELIB("..\..\Borland\GammaE_Math.lib");
USELIB("..\..\Borland\GammaE_Mem.lib");
USELIB("..\..\Borland\GammaE_Misc.lib");
USELIB("..\..\Borland\GammaE_Scene.lib");
USELIB("..\..\Borland\GammaE_TerrainData.lib");
USELIB("..\..\..\libs\TexLib\Lib\Borland\TexLIB.lib");
USEUNIT("..\..\Input\CommandBinder\CommandBinder.cpp");
USEUNIT("..\..\Input\CommandDispatcher\ClientCmdDispatcher.cpp");
USEUNIT("..\..\Input\CommandDispatcher\CmdDispatcher.cpp");
USEUNIT("..\..\Input\CommandDispatcher\ServerCmdDispatcher.cpp");
USE("..\..\Input\Commands\GammaE_Commands.h", File);
USE("..\..\Input\Events\GammaE_Event.h", File);
USEUNIT("..\..\Game\GameInit\CGame_KeyBinder.cpp");
USE("..\..\Game\GameInit\CGame_KeyBinder.h", File);
USEUNIT("..\..\WinEventTranslator.cpp");
USE("..\..\WinEventTranslator.h", File);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm2), &Form2);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
