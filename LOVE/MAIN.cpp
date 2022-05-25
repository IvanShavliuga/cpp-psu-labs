//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MAIN.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma link "CCALENDR"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1DblClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Label1Click(TObject *Sender)
{
        Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
        Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
        name.SetLength(name.Length()-1);
        name=InputBox("Имя","Введите имя:",name)+"!";
        int t=FileCreate("love.dat");
        FileWrite(t, name.c_str(), 256);
        FileWrite(t, hello.c_str(), 256);
        FileClose(t);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        int t;
        AnsiString str;
        
        if(FileExists("love.dat")!=true)
        {
          name="Милая!\0";
          hello="Я тебя люблю!\0";
          t=FileCreate("love.dat");
          FileWrite(t, name.c_str(), 256);
          FileWrite(t, hello.c_str(), 256);
          FileClose(t);

        }
        else
        {
          char s[256];
          t=FileOpen("love.dat",fmOpenRead);
          FileRead(t, s, 256);
          name.sprintf(s);
          FileRead(t, s, 256);
          hello.sprintf(s);
          FileClose(t);
        }
        Timer3->Enabled=true;
        Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
        hello.SetLength(hello.Length()-1);
        hello=InputBox("Приветствие","Введите приветствие:",hello)+"!";
        int t=FileCreate("love.dat");
        FileWrite(t, name.c_str(), 256);
        FileWrite(t, hello.c_str(), 256);
        FileClose(t);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
        Timer3->Enabled=true;
        Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
        Timer3->Enabled=false;
        Hide();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
        AnsiString str;
        str.sprintf("%d.%d.%dг",Date->Day,Date->Month,Date->Year);
        TrayIcon1->Hint=str;
        Label1->Caption=str+" "+name+" "+hello;
        if(Date->Day==31 && Date->Month==12) Label1->Caption=name+" С наступающим новым годом!";
        if(Date->Day== 1 && Date->Month== 1) Label1->Caption=name+" С новым годом!";
        if(Date->Day==25 && Date->Month==12) Label1->Caption=name+" С катоическим рождеством!";
        if(Date->Day== 7 && Date->Month== 1) Label1->Caption=name+" С православным рождеством!";
        if(Date->Day==14 && Date->Month== 1) Label1->Caption=name+" Со старым новым годом!";
        if(Date->Day==14 && Date->Month== 2) Label1->Caption=name+" С днем Святого Валентина!";
        if(Date->Day==23 && Date->Month== 2) Label1->Caption=name+" С днем защитника отечества!";
        if(Date->Day== 8 && Date->Month== 3) Label1->Caption=name+" Со всемирным днем женщин!";
        if(Date->Day== 1 && Date->Month== 4) Label1->Caption=name+" С днем дурака!";
        if(Date->Day== 1 && Date->Month== 5) Label1->Caption=name+" С днем весны!";
        if(Date->Day== 9 && Date->Month== 5) Label1->Caption=name+" С днем Победы!";
        if(Date->Day== 3 && Date->Month== 7) Label1->Caption=name+" С днем независимости!";
        if(Date->Day== 1 && Date->Month== 9) Label1->Caption=name+" С днем знаний!";
        if(Date->Day== 7 && Date->Month==11) Label1->Caption=name+" С днем революции!";

}
//---------------------------------------------------------------------------


