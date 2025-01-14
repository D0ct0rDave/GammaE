//---------------------------------------------------------------------------
#ifdef USE_PRECOMPILED_HEADERS
    #include "DED_PrecompiledHeaders.h"
    #pragma hdrstop
#endif

#include <vcl.h>
//---------------------------------------------------------------------------
USERES("DummyEditor.res");
USEFORM("GUI.cpp", GUIMain);
USEUNIT("CDummyList.cpp");
USEUNIT("CDummyTypes.cpp");
USEUNIT("CDummyInstance.cpp");
USEFORM("GUI_SelDumType.cpp", GUI_SelDType);
USELIB("..\TerrainEditor\TerrPrjLib\Lib\Borland\TerrPrj.lib");
USELIB("..\..\..\libs\TexLib\Lib\Borland\TexLIB.lib");
USELIB("..\..\..\libs\FileLib\Lib\Borland\FileLib.lib");
USEUNIT("CDummyRedistributor.cpp");
USELIB("..\..\..\libs\TerrainGenerationLib\Lib\Borland\TerrainGeneration.lib");
USELIB("..\..\..\libs\MathGLib\lib\Borland\MathG.lib");
USEUNIT("DummyInfoFile.cpp");
USELIB("..\..\Borland\GammaE_E3D.lib");
USELIB("..\..\Borland\GammaE_Math.lib");
USELIB("..\..\Borland\GammaE_Misc.lib");
USELIB("..\..\Borland\GammaE_Scene.lib");
USELIB("..\..\Borland\GammaE_TerrainData.lib");
USELIB("..\..\Borland\GammaE_FileSys.lib");
USELIB("..\..\Borland\GammaE_Mem.lib");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "GammaE Dummy Editor v1.0";
         Application->CreateForm(__classid(TGUIMain), &GUIMain);
         Application->CreateForm(__classid(TGUI_SelDType), &GUI_SelDType);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
