//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("GammaE_Octree.res");
USEFORM("GUIMain.cpp", Form1);
USELIB("..\..\..\libs\FileLib\Lib\Borland\FileLib.lib");
USELIB("..\..\..\libs\TexLib\Lib\Borland\TexLIB.lib");
USELIB("..\..\Borland\GammaE_E3D.lib");
USELIB("..\..\Borland\GammaE_Math.lib");
USELIB("..\..\Borland\GammaE_Misc.lib");
USELIB("..\..\Borland\GammaE_FileSys.lib");
USELIB("..\..\Borland\GammaE_Mem.lib");
USEUNIT("GUINodes.cpp");
USELIB("..\..\Borland\GammaE_Scene.lib");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
