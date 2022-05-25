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
    int n;
    scanf("%d",&n);
    double a[n][n],b[n][n],r[n][n];
    //���� ������ j=������ i=�������
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++) scanf("%lf",&a[j][i]);
    }//for
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++) scanf("%lf",&b[j][i]);
    }//for
    //��������
    for(int j=0; j<n; j++){
        for(int i=0;i<n;i++){
            r[j][i]=0;
            for(int t=0;t<n;t++) 
                r[j][i]+=a[j][t]*b[t][i];
        }
    }
    //��������. ���������? (��. "�����")
    int f=1; //1-�� 0-���
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++) {
            if((r[i][j]!=0)&&(i!=j)){f=0;break;}
            if(r[i][j]!=1&&i==j){f=0;break;}
        }

    }
    printf("%d\n",f); 
    
    return 0;
}

