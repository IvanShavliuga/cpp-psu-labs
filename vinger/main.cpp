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

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        AnsiString g,r,w,b;
        int i;
        char q[256], p[256],n;
        r=LabeledEdit1->Text;
        g=LabeledEdit2->Text;
        r=r.UpperCase();
        g=g.UpperCase();
        LabeledEdit1->Text=r;
        sprintf(q,"%s",r.c_str());
        sprintf(p,"%s",g.c_str());
        w="";
        for(i=0; i<r.Length(); i++)
        {
           p[i]-='А';
           n=q[i]+p[i];
           w=w+b.sprintf("%c",n);
        }
        w=w.UpperCase();

        LabeledEdit3->Text=w;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        LabeledEdit2->Text="амброзияамброзия";
        LabeledEdit1->Text="прилетаюседьмого";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
        AnsiString g,r,w,b;
        int i;
        char q[256], p[256],n;
        r=LabeledEdit3->Text;
        g=LabeledEdit2->Text;
        r=r.LowerCase();
        g=g.LowerCase();
        LabeledEdit1->Text=r;
        sprintf(q,"%s",r.c_str());
        sprintf(p,"%s",g.c_str());
        w="";
        for(i=0; i<r.Length(); i++)
        {
           p[i]-='а';
           n=q[i]-p[i];
           w=w+b.sprintf("%c",n);
        }
        w=w.UpperCase();

        LabeledEdit1->Text=w;
}
//---------------------------------------------------------------------------
