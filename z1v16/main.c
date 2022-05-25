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

#include <stdio.h> // ���� /�����
#include <math.h>  // �������������� �������
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
// ��������� �������� ����������.
int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
  double x,y,z;  // ���������, �������� �������
  scanf("%lf %lf\n",&x,&y); // ���� x y
  if(y==0) z=0;             // ���� y=0 �� z=0
  else if(x==0)  z=pow(y,3.0); //����� ���� x=0 ��
                               //�� z=y^3
  // ����� ���� x/y<0
  else if(x/y<0) z=log(fabs(x/y))+pow(x*x+y,3.0);
  // � ��������� ������
  else if(x/y>0) z=log(x/y)+pow(x*x+y,3.0);
  printf("%0.3lf\n",z);// �����
  return 0;
}

