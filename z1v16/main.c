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

#include <stdio.h> // Ввод /вывод
#include <math.h>  // Математические функции
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
// Остальные варианты аналогично.
int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
  double x,y,z;  // Аргументы, значение функции
  scanf("%lf %lf\n",&x,&y); // Ввод x y
  if(y==0) z=0;             // Если y=0 то z=0
  else if(x==0)  z=pow(y,3.0); //иначе если x=0 то
                               //то z=y^3
  // Иначе если x/y<0
  else if(x/y<0) z=log(fabs(x/y))+pow(x*x+y,3.0);
  // в противном случае
  else if(x/y>0) z=log(x/y)+pow(x*x+y,3.0);
  printf("%0.3lf\n",z);// вывод
  return 0;
}

