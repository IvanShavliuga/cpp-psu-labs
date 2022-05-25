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
    int a[n],       //������ �������� ������
        plus[n],    //������ ��� ������������
        minus[n];   //������ ��� ������������
    for(int i=0; i<n;i++) scanf("%d",&a[i]);
    int p=0,m=0;    //������� ��� plus,minus
    for(int i=0; i<n;i++){
        if(a[i]>0) {plus[p]=a[i];p++;} //������������?
        if(a[i]<0) {minus[m]=a[i];m++;}//�������������?
    }
    //������ �����
    for(int i=0; i<n-p-m; i++) a[i]=0;
    //������ �������������
    int j=0;
    for(int i=n-p-m; i<n-m; i++) 
        {a[i]=plus[j];j++;}
     //������ �������������
    j=0;
    for(int i=n-m; i<n; i++) 
        {a[i]=minus[j];j++;}
    //�����
    for(int i=0; i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

