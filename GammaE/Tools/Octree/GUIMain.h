//---------------------------------------------------------------------------

#ifndef GUIMainH
#define GUIMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *File1;
    TMenuItem *Load1;
    TOpenDialog *dlg_Load;
    TMenuItem *N1;
    TMenuItem *N3;
    TMenuItem *Quit1;
    TSaveDialog *dlg_Save;
    TTreeView *tv_Scene;
    TPageControl *PageControl1;
    TTabSheet *ts_Scene;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TBitBtn *BitBtn1;
    TBitBtn *BitBtn2;
    TBitBtn *BitBtn3;
    TTrackBar *tb_MaxTrisPerNode;
    TLabel *Label1;
    TLabel *lb_MTPN;
    TMenuItem *SaveGEMScene1;
    TImageList *ImageList1;
    TGroupBox *GroupBox1;
    TLabel *Label3;
    TLabel *lb_Dims;
    TTrackBar *tb_Size;
    TLabel *Label2;
    TLabel *lb_Size;
    TButton *Button1;
    void __fastcall Load1Click(TObject *Sender);
    void __fastcall SaveCompactMesh1Click(TObject *Sender);
    void __fastcall BitBtn3Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall SaveGEMScene1Click(TObject *Sender);
    void __fastcall FormDestroy(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall tb_SizeChange(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);

private:	// User declarations
      void __fastcall SetupControls();
      void __fastcall SetupResizer();

public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
