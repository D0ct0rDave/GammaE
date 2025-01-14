//---------------------------------------------------------------------------

#ifndef GUIH
#define GUIH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TMainMenu *MainMenu1;
    TMemo *Memo1;
    TListBox *ListBox1;
    TLabel *Label1;
    TLabel *Label2;
    TRadioGroup *RadioGroup1;
    TMenuItem *Files1;
    TMenuItem *Addshaders1;
    TMenuItem *LoadMaterials1;
    TMenuItem *SaveMaterials1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *Quit1;
    TMenuItem *Help1;
    TMenuItem *About1;
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
