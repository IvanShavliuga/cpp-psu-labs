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
    double a,b,u,v;
    int n;
    //���� ������
    scanf("%lf %lf %d",&u,&v,&n);
    //�������������
    a=u;
    b=v;
    double summ=0,//�����
        fact=1;   //���������
    for(int i=1; i<n; i++){
        //������� �������� �����
        summ+=a*b/(fact*(fact+1));
        //�������� ��������� 
        fact*=i;
        //���������� � ������� �������� ��������
        //���������� a[i-1], ����� ��������� �����
        //�������� ���������� b=2*a[i-1]+b
        double buf=a;
        a=2*b+a;
        b=2*buf+b;
    }   //����� �����
    printf("%lf\n",summ); //����� ����������
    return 0; // ���
}

