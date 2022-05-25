//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        int i;
        AnsiString str;
        for(i=0; i<8; i++)
        {
           str.sprintf("%d.bmp",i);
           bitmaps[i] = new Graphics::TBitmap;
           bitmaps[i]->LoadFromFile(str);

        }
        NewBuf();
        Draw();
        NewNext();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        NewBuf();
        NewNext();
        Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label5Click(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label4Click(TObject *Sender)
{
        Form2->ShowModal();        
}
//---------------------------------------------------------------------------
