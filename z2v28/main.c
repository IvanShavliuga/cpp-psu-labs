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
  char y1,y2;
  char x1,x2,fig;
  int r; //Результат 1-можно 0-нельзя
  scanf("%c %c%c-%c%c",&fig,&x1,&y1,&x2,&y2);
  switch(fig){
  case 'K':  //Конь
    if((abs(x2-x1)==1)&&(abs(y2-y1)==2)) r=1;
    else r=0;
    break;
  case 'C':  //Ладья
    if((abs(x2-x1)==0)||(abs(y2-y1)==0)) r=1;
    else r=0;
    break;
  case 'Q':  //Ферзь
    if((abs(x2-x1)==0)&&(abs(y2-y1)==0)||(abs(x2-x1)==abs(y2-y1)))                                
      r=1;
    else r=0;
    break;
  case 'O':  //Офицер
    if(abs(x2-x1)==abs(y2-y1)) r=1;
    else r=0;
    break;
  }
  printf("%d\n",r);
  return 0;
}

