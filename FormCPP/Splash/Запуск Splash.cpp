//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USEFORM("richabt.cpp", Form2);
USEFORM("romain.cpp", MainForm);
USEFORM("splash.cpp", SplashForm);
#include "splash.h"

//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {        SplashForm = new TSplashForm(Application);
                 SplashForm->Show();
                 SplashForm->Update();
                 SplashForm->ProgressBar1->Position=0;
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 SplashForm->ProgressBar1->Position=30;
                 Application->CreateForm(__classid(TForm2), &Form2);
                 SplashForm->ProgressBar1->Position=60;
                 Application->CreateForm(__classid(TSplashForm), &SplashForm);
                 SplashForm->ProgressBar1->Position=100;
                 SplashForm->Hide();
                 SplashForm->Close();
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
