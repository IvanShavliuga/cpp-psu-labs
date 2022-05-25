#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
#include <string.h>
/*Функция вывода IvOkna для DOS
  caption -- заголовок окна
  status  -- строка состояния
*/
void IvOkno(char *caption,char *status)
{
    textbackground(1);
    clrscr();
    textcolor(15);
    textbackground(4);
    gotoxy(1,1);
    cprintf(caption);
    clreol();
    textcolor(15);
    textbackground(4);
    gotoxy(1,25);
    clreol();
    cprintf(status);
    textbackground(1);
    gotoxy(1,2);
    textcolor(14);
    textcolor(15);
    gotoxy(1,2);
}
/*Функция вывода горизонтального меню
  c -- количество пунктов (небольше 10)
  ... -- пункты меню
*/
int gmenu(int c, ...)
{
  char menu[10][30];  //Команды меню
  int key; //Код введеной клавиши
  int select=0; //Выбранное меню
  int i;
  va_list ap;
  va_start(ap,c);
  if(c>10) c=10;
  for( i=0; i<c; i++){
    strcpy(menu[i],va_arg(ap,char *));
  }
  va_end(ap);
  do{
    //Поехали!!
    int x=1;    //Абсцисса пункта меню

    textbackground(7);
    gotoxy(1,2);
    clreol();
    for( i=0; i<c; i++){//Вывод меню
      if(select==i) textbackground(2); //Курсор здесь
      else          textbackground(7);
      textcolor(0);
      gotoxy(x,2);
      cprintf("%s",menu[i]);
      textcolor(4);
      gotoxy(x,2);
      cprintf("%c",menu[i][0]);
      x+=strlen(menu[i]);
    }
    key=getch();
    switch(key){
      case 75: //Влево
        select--;
        if(select<0) select=c-1;
        break;
      case 77: //Вправо
        select++;
        if(select>c-1) select=0;
        break;
      case 13:
        return select;
    }
    textbackground(0);
    textcolor(15);
  }while(key!=27); //Пока не нажали Esc
  gotoxy(1,3);
  return select;
}
 