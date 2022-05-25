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
    int m,n;  //����������� 1-�� �������
    int p,k;  //����������� 2-�� �������
    scanf("%d %d %d %d",&m,&n,&p,&k);
    //����� ����������� �������? (��. "�����")
    if(n!=p) return 0; //�����
    double a[m][n], b[p][k],//�������� �������
        r[m][k];  //�������������� �������
    //���� ������ j=������ i=�������
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++) scanf("%lf",&a[j][i]);
    }//for
    for(int j=0; j<p; j++){
        for(int i=0; i<k; i++) scanf("%lf",&b[j][i]);
    }//for
    //��������
    for(int j=0; j<m; j++){
        for(int i=0;i<k;i++){
            r[j][i]=0;
            for(int t=0;t<n;t++) 
                r[j][i]+=a[j][t]*b[t][i];
        }
    }
    //��������. ������������?
    int f=1; //1-�� 0-���
    for(int j=0; j<m; j++){
        for(int i=0; i<k; i++) 
            if(r[i][j]!=r[j][i]){f=0;break;}
    }
    for(int j=0; j<m; j++){
        for(int i=0; i<k; i++) printf("%0.1lf ",r[j][i]);
    printf("\n");
    }//for
    printf("%d\n",f); 
    return 0;
}

