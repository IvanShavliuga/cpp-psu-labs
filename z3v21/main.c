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
  double a,b;
  int n;
  scanf("%lf %lf %d",&a,&b,&n);
  double h=(b-a)/n;
  double s=0.0;
  for(int k=1; k<n; k++) {
    double x=a+k*h;
    s+=3*x*x-1;
  }
  s+=(3*a*a-2+3*b*b)/2;
  s*=h;
  return 0;
}

