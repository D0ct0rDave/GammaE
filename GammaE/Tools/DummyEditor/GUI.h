//---------------------------------------------------------------------------
#ifndef GUIH
#define GUIH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ComCtrls.hpp>

#include "Math/GammaE_Math.h"
#include "CDummyTypes.h"
#include "CDummyRedistributor.h"
//---------------------------------------------------------------------------
class TGUIMain : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *LoadTerrainScene1;
    TMenuItem *SaveDummyInfoFilr1;
    TMenuItem *N1;
    TMenuItem *Quit1;
    TMenuItem *Help1;
    TMenuItem *About1;
    TImage *im_Background;
    TBitBtn *bt_AddDT;
    TBitBtn *bt_DeleteDT;
    TStringGrid *sg_DInsts;
    TBitBtn *bt_EditDT;
    TBitBtn *bt_RedistDT;
    TSaveDialog *dlg_Save;
    TOpenDialog *dlg_Load;
    TCheckBox *cb_DrawSectors;
    TPaintBox *pb_Dsp;
    TStatusBar *StatusBar1;
    TStringGrid *sg_DTypes;
    TMenuItem *N2;
    TMenuItem *LoadDummyInfoFile1;
    TMenuItem *N3;
    TMenuItem *Savedummyscene1;
    void __fastcall bt_AddDTClick(TObject *Sender);
    void __fastcall bt_DeleteDTClick(TObject *Sender);
    void __fastcall bt_EditDTClick(TObject *Sender);
    void __fastcall Quit1Click(TObject *Sender);
    void __fastcall LoadTerrainScene1Click(TObject *Sender);
    void __fastcall pb_DspPaint(TObject *Sender);
    void __fastcall cb_DrawSectorsClick(TObject *Sender);
    void __fastcall sg_DTypesDblClick(TObject *Sender);
    void __fastcall bt_RedistDTClick(TObject *Sender);
    void __fastcall sg_DTypesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
    void __fastcall SaveDummyInfoFilr1Click(TObject *Sender);
    void __fastcall LoadDummyInfoFile1Click(TObject *Sender);
    void __fastcall Savedummyscene1Click(TObject *Sender);

private:	// User declarations
    void __fastcall ShowDummyTypesList();
    void __fastcall ShowDummyInstanceList(CDummyList *_poDList);
    void __fastcall EnableAll();
    void __fastcall DisableAll();
    void __fastcall ComputeMeasures();
    void __fastcall SetupTerrainDisplay();

    void __fastcall DrawSectors();

    Graphics::TBitmap   *m_poAuxBmp;
    int                  m_iTX;
    int                  m_iTY;
    int                  m_iXOfs;
    int                  m_iYOfs;
    float                m_fXScale;
    float                m_fYScale;

    void __fastcall ShowDummy(CVect3 Pos,TColor Color);
    void __fastcall ShowDummyInstances(CDummyList *_poDList);

    void DestroyAll();

public:		// User declarations
    __fastcall TGUIMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGUIMain *GUIMain;
//---------------------------------------------------------------------------
#endif
