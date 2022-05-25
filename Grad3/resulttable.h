//---------------------------------------------------------------------------

#ifndef resulttableH
#define resulttableH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TResults : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TButton *Button1;
private:	// User declarations
	long scores[100];
        AnsiString names[100];
public:		// User declarations
	__fastcall TResults(TComponent* Owner);
        int SelectIndex,Count;
        void LoadTable(AnsiString FileName);
        void CreateTable();
        void SaveTable(AnsiString FileName);
        void DrawTable();

};
//---------------------------------------------------------------------------
extern PACKAGE TResults *Results;
//---------------------------------------------------------------------------
#endif
