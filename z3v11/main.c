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
// Остальное аналогично
int main(int argc, char *argv[])
{
  /* TODO: Enter code here */
  int i=0;
  double x,eps;
  scanf("%lf %lf",&x,&eps);
  double summ=0.0,fact=1.0;
  do {
    fact*=2*i+1;
    summ+=pow(-1,i)*pow(x,2*i+1)/fact;
    i++;
  }while(summ>eps);
  printf("%lf %lf\n",summ,sin(x));
  return 0;
}

