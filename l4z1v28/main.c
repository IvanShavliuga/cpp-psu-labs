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
    int n;          //�����������
    scanf("%d",&n); //���� n
    double a[n],plus[n];    //������ �������� ������
    for(int i=0; i<n;i++) scanf("%lf",&a[i]);
    int j=0; //������� ������������� �������� �
    for(int i=0; i<n;i++)//��������� ������
        if(a[i]>0)  {plus[j]=a[i];j++;}
    //���������� �������������
    for(int t=0; t<j; t++){
        for(int i=t;i<j;i++){
            if(plus[i]>plus[t]){
                double b=plus[i];
                plus[i]=plus[t];
                plus[t]=b;
            }//if
               
            
        }//for
    }//for
    //������ ��������������� � �������� ������
    int t=0;
    for(int i=0; i<n;i++)
        if(a[i]>0) {a[i]=plus[t];t++;}
    //�����
    for(int i=0; i<n;i++) printf("%0.2lf ",a[i]);
    printf("\n");    
    return 0;
}

