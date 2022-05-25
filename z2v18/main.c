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
// Варианты 20 23 аналогично
int main(int argc, char *argv[])
{
  /* TODO: Enter code here */
  int code;  // Номер команды
  scanf("%d",&code);
  double a, r1,r2,s;
  switch(code) {
  case 1:
    scanf("%lf\n",&a);
    s=0.25*a*a*sqrt(3);   // s=0.5*a*b*sin(C) 
    r2=0.25*a*sqrt(3);    // r2=a*sin(A)/2
    r1=2*s/(3*a);         // r1=2*s/(a+b+c) 
    break;
  case 2:
    scanf("%lf\n",&r1);
    r2=0.25*r1*8;         // r1=4*r2*sin(0.5*A)*sin(0.5*B)*sin(0.5*C)
    a=r2*sqrt(3);         // Из теоремы синусов
    s=3*r*a/2;            // r1=2*s/(a+b+c)   
    break;
  case 3:
    scanf("%lf\n",&r2);
    a=r2*sqrt(3);          // Из теоремы синусов
    s=pow(a,3.0)/(4*r2);   // r2=abc/(4s)
    r1=2*s/(3*a);          // r1=2*s/(a+b+c)
    break;
  case 4:
    scanf("%lf\n",&s);
    a=sqrt(4*s/sqrt(3));   // s=0.5*a*b*sin(C) 
    r2=a/sqrt(3);          // Из теоремы синусов
    r1=2*s/(3*a);          // r1=2*s/(a+b+c)
    break;
  } 
  printf("%lf %lf %lf %lf\n",a,r1,r2,s);
  return 0;
}

