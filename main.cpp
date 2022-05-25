//---------------------------------------------------------------------------
#include <conio.h>            // Работа с цветом в МС-ДОС
#pragma hdrstop
const char commands[5][30]={  // Пункты меню
 "Файл","Правка","Вид","Справка","Выход" 
};
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
  int key,select;    // key --код клавиши select - номер выбранного
                     // пукта
start:
  key=0;
  clrscr();          // Очистка экрана
  textcolor(15);     // Заголовок меню
  cprintf("Меню:");
  select=0;          // Курсор вверху
  while(key!=13) { // Пока не нажали пробел или Enter
    /* Вывод пукнтов меню */
    textcolor(14);
    for(int i=0; i<5; i++) {
      gotoxy(1,i+2);
      cprintf(commands[i]);
    }
    /* Вывод выбранного пункта отдельным цветом */
    textcolor(13);
    gotoxy(1,select+2);
    cprintf(commands[select]);
    key=getch();     // Нажимаем клавишу
    switch(key) {
      case 72: // Вверх  72=Up 
        if(select>0) select--;
        break;
      case 80: // Вниз   80=Down
        if(select<5) select++;
        break;
      case 27: // Выход  27=Esc
        return 1;
    }
  } 
  /*Обработка select
  Выполнение пунтов меню*/
  switch(select) {
    case 0:
    case 1:
    case 2:
      // САМОСТОЯТЕЛЬНОЕ подключение функций
      getch();
      goto start;
    case 3:
      // Справка
      textcolor(15);
      gotoxy(1,10);
      cprintf("  ----- Помощь ----- \r\n");  
      cprintf("Up            - вверх\r\n");
      cprintf("Down          - вниз\r\n");
      cprintf("Пробел, Enter - ввод\r\n");
      cprintf("Esc           - выход\r\n");
      getch();
      goto start;
    case 4://Выход
      return 0;
  }
  return 0;
}
//---------------------------------------------------------------------------
 