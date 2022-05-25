//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "generator.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
#include <ActnCtrls.hpp>
#include <ActnList.hpp>
#include <ActnMan.hpp>
#include <StdActns.hpp> 
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include "about.h"
#define  MaxLength 1000
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *File1;
        TMenuItem *New1;
        TMenuItem *Open1;
        TMenuItem *Save1;
        TMenuItem *N1;
        TMenuItem *Exit1;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *N5;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TMemo *Memo1;
        TMemo *Memo2;
        TMemo *Memo3;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TMemo *Memo4;
        TMemo *Memo5;
        TMemo *Memo6;
        TMemo *Memo7;
        TMemo *Memo8;
        TMemo *Memo9;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *N2;
        TMenuItem *Edit1;
        TMenuItem *Paste1;
        TMenuItem *Copy1;
        TMenuItem *Cut1;
        TMenuItem *N8;
        TMenuItem *Undo1;
        TMenuItem *N6;
        TMenuItem *N7;
        TActionManager *ActionManager1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TEditSelectAll *EditSelectAll1;
        TEditUndo *EditUndo1;
        TImageList *ImageList1;
        TActionList *ActionList1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TToolButton *ToolButton14;
        TToolButton *ToolButton15;
        TMenuItem *N9;
        TMenuItem *N10;
        TToolButton *ToolButton16;
        TToolButton *ToolButton17;
        void __fastcall Memo1Change(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Memo5Change(TObject *Sender);
        void __fastcall Memo4Change(TObject *Sender);
        void __fastcall New1Click(TObject *Sender);
        void __fastcall Exit1Click(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall Open1Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall Save1Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
       // void __fastcall N4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        AnsiString Dvoid(AnsiString string);
        AnsiString Dec(AnsiString string);
        AnsiString GetGamma(int len);
        int A, C,X0,M;
        unsigned long  dlina;
        char  alfavit;
        AnsiString gamma;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
