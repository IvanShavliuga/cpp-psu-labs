//---------------------------------------------------------------------------

#ifndef generatorH
#define generatorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CSPIN.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TCSpinEdit *CSpinEdit1;
        TLabel *Label1;
        TCSpinEdit *CSpinEdit2;
        TLabel *Label2;
        TCSpinEdit *CSpinEdit3;
        TLabel *Label3;
        TLabel *Label4;
        TCSpinEdit *CSpinEdit4;
        TComboBox *ComboBox1;
        TLabel *Label5;
        TLabel *Label6;
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
