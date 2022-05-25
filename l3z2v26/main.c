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
#include <math.h>
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

int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
    int year; //Год
    scanf("%d",&year);
    year-=1984; // 1984 -- назало овбзева
    int color = abs(year/12); // поджЁкл
    switch(color){
    case 0:  printf("зеленый ");   break;
    case 1:  printf("красный ");   break;
    case 2:  printf("желтый ");    break;
    case 3:  printf("белый ");     break;
    case 4:  printf("черный ");    break;
    }
    int zver=abs(year%12); //год зверя
    switch(zver){
    case 0:  printf("крысы\n");    break;
    case 1:  printf("коровы\n");   break;
    case 2:  printf("тигра\n");    break;
    case 3:  printf("зайца\n");    break;
    case 4:  printf("дракона\n");  break;
    case 5:  printf("змеи\n");     break;
    case 6:  printf("лошади\n");   break;
    case 7:  printf("овцы\n");     break;
    case 8:  printf("обезьяны\n"); break;
    case 9:  printf("курицы\n");   break;
    case 10: printf("собаки \n");  break;
    case 11: printf("свиньи\n");   break;
    }

    return 0;
}

