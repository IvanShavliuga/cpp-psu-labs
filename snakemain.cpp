//---------------------------------------------------------------------------
#include <conio.h>
#pragma hdrstop

//---------------------------------------------------------------------------
/*Змейка
  Разработал Иванов И.С. (152-53-52, izmeritel5@rambler.ru)*/
#pragma argsused
const int length     = 5;  //Длина змеи
const int width      = 10; //Ширина игрового поля
const int height     = 10; //Высота поля
const int color      = 10;  //Цвет змеи

int main(int argc, char* argv[])
{
  int SnakePoint[length];  //Координаты каждой части тела змеи
  int SnakeNaprav[length];/*Смещения каждой части тела змеи
                             -10 -- влево
                             10  -- вправо
                             -1  -- вверх  - Обращаяйся к разработчикам
                             1   -- вниз   - компьютеров
  			     0   -- стоим*/
  int key;                 //Код клавиши
  // Вывод приветствия -- Сам!!!
  // ...
  // Инициализация
  for(int i=0; i<length;i++){
    SnakePoint[i]=i;       //координаты частей тела змеи 0,0 0,1 .. 0,length-1
    SnakeNaprav[i]=1;      //Напрвление вниз
  }
  SnakeNaprav[length-1]=0;
  for(int i=0; i<height;i++)
    for(int j=0;j<width;j++)

  do {//Играем
    int x,y;
    clrscr();              //Очистка экрана
    //Рисуем змею
    for(int i=0; i<length;i++){
      //В SnakePoint -- двузначное число, причем
      //десятки -- абсцисса
      //еденицы -- ордината
      x=SnakePoint[i]/10;
      y=SnakePoint[i]%10;
      gotoxy(x+1,y+1);
      textcolor(color);    //Устанавливаем цвет
      cprintf("*");        //Это и есть часть тела змеи -- '*'
    }
    //Далее опрашивам клавиатуру
    key=getch();
    //И че же ты нажал?
    switch(key){
    case 75:               //Если влево
      SnakeNaprav[length-1]=-10; //Вспомни числовую прямую
      break;
    case 77:               //Вправо
      SnakeNaprav[length-1]=10; //Вспомни числовую прямую !!!
      break;
    case 72:               //Вверх
      SnakeNaprav[length-1]=-1; //см. выше
      break;
    case 80:               //Вниз
      SnakeNaprav[length-1]=1; //см. выше!!!
      break;
    }
    int pol=1; //Есть куда ползти
    for(int i=length-1; i>=0;i--){
      for(int j=0; j<length; j++)             //Наступаем на хвост ?
        if((SnakePoint[i]+SnakeNaprav[i]==SnakePoint[j]+SnakeNaprav[j])&&
           (i!=j)) {pol=0;break;}
      x=(SnakePoint[i]+SnakeNaprav[i])/10+1;  //В компе в текстовом реиме ДОС
      y=(SnakePoint[i]+SnakeNaprav[i])%10+1;  //координаты начинаются с 1
      if((x<=0)||(x>=width)||(y<=0)||(y>=height))
          pol=0;   //Выход за границы поля
      if(pol==0) break;   //Нельзя ползти
    }
    if(pol==1){
      //Поползли!
      for(int i=length-1; i>=0;i--)
        SnakePoint[i]+=SnakeNaprav[i];   //координаты частей тела змеи
      for(int i=0; i<length-1;i++)
        SnakeNaprav[i]=SnakeNaprav[i+1]; //Двигаемся за следующей
    }

  }while(key!=27);         //Пока не нажмем Esc=27
  return 0;
}
//---------------------------------------------------------------------------

