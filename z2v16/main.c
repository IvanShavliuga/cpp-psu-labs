/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/
//Типовые варианты аналогично
int main(int argc, char *argv[])
{
  /* TODO: Enter code here */
  char a,b,c; // Сотни десятки еденицы
  scanf("%c%c%c",&a,&b,&c);
  switch(a){
  case '1' printf("Сто "); break;
  case '2' printf("Двести "); break;
  case '3' printf("Тристо "); break;
  case '4' printf("Четыресто "); break;
  case '5' printf("Пятьсот "); break;
  case '6' printf("Шестьсот "); break;
  case '7' printf("Семьсот "); break;
  case '8' printf("Восемьсот "); break;
  case '9' printf("Девятьсот "); break;
  }
  switch(b){
  case '1' 
    switch(c){
    case '0': printf("десять\n "); return 0;
    case '1' printf("одиннадцать\n "); return 0;
    case '2' printf("двенадцать \n"); return 0;
    case '3' printf("тринадцать\n "); return 0;
    case '4' printf("четырнадцать\n "); return 0;
    case '5' printf("пятнадцать \n"); return 0;
    case '6' printf("шестнадцать\n"); return 0;
    case '7' printf("семнадцать \n"); return 0;
    case '8' printf("восемнадцать \n"); return 0;
    case '9' printf("девятнадцать\n"); return 0;
    }
    break;
  case '2' printf("двадцать "); break;
  case '3' printf("тридцать "); break;
  case '4' printf("сорок "); break;
  case '5' printf("пятьдесят "); break;
  case '6' printf("шестьдесят "); break;
  case '7' printf("семьдесят "); break;
  case '8' printf("восемьдесят "); break;
  case '9' printf("девяносто "); break;
  }
  switch(c){
  case '1' printf("один "); break;
  case '2' printf("два "); break;
  case '3' printf("три "); break;
  case '4' printf("четыре "); break;
  case '5' printf("пять "); break;
  case '6' printf("шесть"); break;
  case '7' printf("семь "); break;
  case '8' printf("восемь "); break;
  case '9' printf("девять"); break;
  }
  printf("\n");
  return 0;
}

