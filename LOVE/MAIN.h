//---------------------------------------------------------------------------

#ifndef MAINH
#define MAINH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "trayicon.h"
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include "CCALENDR.h"
#include <Grids.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImageList *ImageList1;
        TTrayIcon *TrayIcon1;
        TLabel *Label1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TTimer *Timer1;
        TCCalendar *Date;
        TMenuItem *N4;
        TTimer *Timer2;
        TTimer *Timer3;
        void __fastcall Label1DblClick(TObject *Sender);
        void __fastcall Label1Click(TObject *Sender);
        void __fastcall TrayIcon1Click(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        AnsiString name,hello;
        
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
