#include <stdio.h>
#include <conio.h>
#include <stdarg.h>
#include <string.h>
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
    gotoxy(1,1);
    clreol();
    for( i=0; i<c; i++){//Вывод меню
      gotoxy(x,1);
      if(select==i) printf(" *%s* ",menu[i]); //Курсор здесь
      else          printf("  %s  ",menu[i]);
      
      x+=strlen(menu[i])+3;
    }
    key=getch();
    switch(key){
      case '4': //Влево
	select--;
	if(select<0) select=c-1;
	break;
      case '6': //Вправо
	select++;
	if(select>c-1) select=0;
	break;
      case '5':
        return select;
    }
  }while(key!=27); //Пока не нажали Esc
  gotoxy(1,2);
  return select;
}
void hexcode(char str[],int len)
{
	printf("\n");
	for(int i=0; i<len; i++) 	printf("%2x ",str[i]);
	printf("\t%s\n",str);
	return;
}
//Преобразование из кодировки Windows в кодировку DOS
char * WinToDos(char *source)
{
    char *result;   
	for(int i=0; i<strlen(source); i++){
		if(source[i]>='А'&&source[i]<='п') 
			result[i]=source[i]-0x40;
		else if(source[i]>='р'&&source[i]<='я')
			result[i]=source[i]-0x10;
		else result[i]=source[i];
	}
	result[strlen(source)]=0;
	return(result);
}
