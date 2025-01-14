//---------------------------------------------------------------------------
#ifdef USE_PRECOMPILED_HEADERS
    #include "DED_PrecompiledHeaders.h"
    #pragma hdrstop
#endif

#include <vcl.h>
//---------------------------------------------------------------------------
#include "GUI_SelDumType.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGUI_SelDType *GUI_SelDType;
#define DUMMY_DIST_DIVISOR  2.0f
//---------------------------------------------------------------------------
bool Dlg_SelectDummyModel(CDummyList &Data)
{
    // Setup control initial values
    GUI_SelDType->ed_DummyModel->Text = Data.DummyModel;
    GUI_SelDType->tb_DProb->Position = (1.0f - Data.fProb) * (float)GUI_SelDType->tb_DProb->Max;
    GUI_SelDType->lb_DAlg->ItemIndex = Data.iAlgType;
    GUI_SelDType->tb_DScale->Position = (log(Data.fScale) / log(2.0f)) + 1;
    GUI_SelDType->tb_DIters->Position = GUI_SelDType->tb_DIters->Max - Data.iIters;

    GUI_SelDType->ShowModal();

    if (GUI_SelDType->ModalResult == mrOk)
    {
        // Copy-back the parameters to the Data struct
        Data.DummyModel = GUI_SelDType->ed_DummyModel->Text;
        Data.iAlgType   = GUI_SelDType->lb_DAlg->ItemIndex;
        Data.iIters     = GUI_SelDType->tb_DIters->Max - GUI_SelDType->tb_DIters->Position;
        Data.fProb      = 1.0f - ((float)GUI_SelDType->tb_DProb->Position/(float)GUI_SelDType->tb_DProb->Max);
        Data.fScale     = (float)(1 << GUI_SelDType->tb_DScale->Position);

        return true;
    }
    else
        return false;
}
//---------------------------------------------------------------------------
__fastcall TGUI_SelDType::TGUI_SelDType(TComponent* Owner)   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGUI_SelDType::SpeedButton1Click(TObject *Sender)
{
    if (dlg_SelDModel->Execute())
        ed_DummyModel->Text = dlg_SelDModel->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TGUI_SelDType::tb_DScaleChange(TObject *Sender)
{
    lb_DScale->Caption = IntToStr( 1 << tb_DScale->Position);
}
//---------------------------------------------------------------------------
void __fastcall TGUI_SelDType::tb_DProbChange(TObject *Sender)
{
    lb_DProb->Caption = FormatFloat("0.00",1.0f - ((float)GUI_SelDType->tb_DProb->Position/(float)GUI_SelDType->tb_DProb->Max) );
}
//---------------------------------------------------------------------------
void __fastcall TGUI_SelDType::tb_DItersChange(TObject *Sender)
{
    lb_DIters->Caption = IntToStr(tb_DIters->Max - tb_DIters->Position);
}
//---------------------------------------------------------------------------

