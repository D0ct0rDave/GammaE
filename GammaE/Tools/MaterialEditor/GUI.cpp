//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "GUI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
#include "E3D/GammaE_E3D.h"

TShaderWarehouse			ShaderWH;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner): TForm(Owner)
{
	ShaderWH.AddShaderFile("Shaders.txt");
}
//---------------------------------------------------------------------------


