//---------------------------------------------------------------------------
#include <conio.h>     //цветной ввод вывод
#include <string.h>    //Работа со строками
#include <dos.h>       //Здесь обявлена функмия delay
#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
   char string[]="PROGRMMIRUNG";
   int len=strlen(string); //Длина строки
   textcolor(15);          //Белый цвет
   do {
     gotoxy(1,2);          //В точку 1,2
     cprintf(string);      //Вывод
     char b=string[0];
     for(int i=1; i<len; i++) string[i-1]=string[i];
     string[len-1]=b;
     sleep(1);             //Заморозка 1 с
   } while(!kbhit());      //Пока не нажали клавишу
   getch();
   return 0;
}
//---------------------------------------------------------------------------
 