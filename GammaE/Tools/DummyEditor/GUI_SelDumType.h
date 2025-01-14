//---------------------------------------------------------------------------
#ifndef GUI_SelDumTypeH
#define GUI_SelDumTypeH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#include "CDummyList.h"
//---------------------------------------------------------------------------
bool Dlg_SelectDummyModel(CDummyList &Data);

class TGUI_SelDType : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TEdit *ed_DummyModel;
    TSpeedButton *SpeedButton1;
    TOpenDialog *dlg_SelDModel;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TTrackBar *tb_DProb;
    TLabel *Label2;
    TLabel *lb_DProb;
    TLabel *Label4;
    TTrackBar *tb_DScale;
    TLabel *lb_DScale;
    TListBox *lb_DAlg;
    TLabel *Label6;
    TLabel *Label3;
    TLabel *lb_DIters;
    TTrackBar *tb_DIters;
    void __fastcall SpeedButton1Click(TObject *Sender);
    void __fastcall tb_DScaleChange(TObject *Sender);
    void __fastcall tb_DProbChange(TObject *Sender);
    void __fastcall tb_DItersChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TGUI_SelDType(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGUI_SelDType *GUI_SelDType;
//---------------------------------------------------------------------------
#endif
