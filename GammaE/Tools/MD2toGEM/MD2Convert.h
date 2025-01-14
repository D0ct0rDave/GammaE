//---------------------------------------------------------------------------

#ifndef MD2ConvertH
#define MD2ConvertH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *LoadMD2model1;
    TMenuItem *Loadtexture1;
    TMenuItem *N1;
    TMenuItem *SaveGEMmodel1;
    TMenuItem *N2;
    TMenuItem *Quit1;
    TPaintBox *pb_Dsp;
    TTimer *RTimer;
    TSaveDialog *dlg_Save;
    TOpenDialog *dlg_Load;
    TMenuItem *LoadMD2Player1;
    TOpenDialog *dlg_LoadTex;
    void __fastcall pb_DspPaint(TObject *Sender);
    void __fastcall LoadMD2model1Click(TObject *Sender);
    void __fastcall LoadMD2Player1Click(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Loadtexture1Click(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall SaveGEMmodel1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
