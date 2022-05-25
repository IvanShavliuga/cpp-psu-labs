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
    int m,n;
    scanf("%d %d",&n,&m);
    int a[n][m];
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++) scanf("%d",&a[j][i]);
    }//for
    //����������� �����   
    int summ[m]; //������ ��� ����
    for(int j=0; j<n; j++){
        summ[j]=0;
        for(int i=0; i<m; i++) 
            summ[j]+=a[j][i];
    }//for
    //��������
    int r=0;//������� ������� � 0-� (����� i-�� =  
            //����� 0-��)
    for(int i=1; i<m; i++){
        if(summ[0]==summ[i]) r++; 
    }//for
    printf("%d\n",r);
    return 0;
}

