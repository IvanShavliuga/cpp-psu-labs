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
        AnsiString r,w,b;
        int g,i;
        char q[256],n;
        r=LabeledEdit1->Text;
        g=LabeledEdit2->Text.ToInt();
        r=r.UpperCase();
        LabeledEdit1->Text=r;
        sprintf(q,"%s",r.c_str());
        w="";
        for(i=0; i<r.Length(); i++)
        {
           n=q[i]+g;
           if(q[i]+g=='ß'+1) n='_';
           if(q[i]+g>'ß'+1)  n=q[i]+g-1;
           if(q[i]=='_'||q[i]==' '||q[i]=='-')     n='À'+g-1;
           w=w+b.sprintf("%c",n);
        }
        w=w.UpperCase();

        LabeledEdit3->Text=w;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        AnsiString r,w;
        int i;
        w="";
        r="";
        for(i=0; i<32; i++)
          w=w+r.sprintf("%c",i+'À');
        w+='_';
        LabeledEdit1->Text=w;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
        AnsiString r,w,b;
        int g,i;
        char q[256],n;
        r=LabeledEdit3->Text;
        g=LabeledEdit2->Text.ToInt();
        r=r.LowerCase();
        LabeledEdit1->Text=r;
        sprintf(q,"%s",r.c_str());
        w="";
        for(i=0; i<r.Length(); i++)
        {
           n=q[i]-g;
           if(q[i]-g=='à'-1) n='_';
           if(q[i]-g<'à'-1)  n=q[i]-g+1;
           if(q[i]=='_'||q[i]==' '||q[i]=='-')     n='ÿ'-g+1;
           w=w+b.sprintf("%c",n);
        }
        w=w.UpperCase();

        LabeledEdit1->Text=w;
}
//---------------------------------------------------------------------------
