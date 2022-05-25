//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include "about.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TImage *Image2;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Label5Click(TObject *Sender);
        void __fastcall Label4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        int buffer[10][10],next[5];
        Graphics::TBitmap* bitmaps[8];
        int Sluch(int A,int C,int X,int M)
        {
           return (A*X+C)%M;
        }
        NewBuf()
        {
           int x, y;
           randomize();
           for(y=0; y<10; y++)
           {
              for(x=0; x<10; x++)
                buffer[y][x]=0;
           }
        }
        Draw()
        {
           int x, y;
           for(y=0; y<10; y++)
           {
              for(x=0; x<10; x++)
                Image1->Canvas->Draw(32*x,32*y,bitmaps[buffer[y][x]]);
           }

        }
        NewNext()
        {
           int x;
           Image2->Canvas->Pen->Color=clBlack;
           Image2->Canvas->Pen->Width=5;
           Image2->Canvas->MoveTo(0,3);
           Image2->Canvas->LineTo(160,3);
           Image2->Canvas->MoveTo(0,42-3);
           Image2->Canvas->LineTo(160,42-3);

           for(x=0; x<5; x++)
           {
                next[x]=random(7)+1;
                Image2->Canvas->Draw(32*x,5,bitmaps[next[x]]);
           }
        }
        
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
