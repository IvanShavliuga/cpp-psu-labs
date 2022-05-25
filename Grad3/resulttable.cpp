//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "resulttable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TResults *Results;
//---------------------------------------------------------------------------
__fastcall TResults::TResults(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TResults::CreateTable()
{
	Count=10;
	for(int i=0; i<Count; i++){
            scores[i]=0;
            names[i]="-----";
	}
	SelectIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TResults::LoadTable(AnsiString FileName)
{
	if(!FileExists(FileName))
        {
            int h=FileOpen(FileName,fmOpenRead);
            FileRead(h,Count,1);
            for(int i=0; i<Count;i++){
                FileRead(h,scores[i],1);
                FileRead(h,names[i],1);
            }
            SelectIndex=0;
            FileClose(h);
        } else            /
            CreateTable();
}
//---------------------------------------------------------------------------
