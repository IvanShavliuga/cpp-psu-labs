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

int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
  int day,mont;
  scanf("%d %d\n",&day,&mont);
  switch(mont) {
    case 1:
    case 3:     
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:   
       if(day==31) {mont++; day=0;}
       break;
    case 2: 
       if(day==28) {mont++; day=0;}
       break;
    default:
       if(day==30) {mont++;day=0;}
       break;
  }
  day++;
  if(mont>12) mont=1;
  printf("%d %d",day,mont);
  return 0;
}

