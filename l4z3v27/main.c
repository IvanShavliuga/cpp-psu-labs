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
    //Суммировние столбцов   
    int summ[m]; //массив для сумм
    for(int j=0; j<n; j++){
        summ[j]=0;
        for(int i=0; i<m; i++) 
            summ[j]+=a[i][j];
    }//for
    //Сортировка
    for(int j=0; j<n; j++){
        for(int i=j; i<n;i++){
            if(summ[i]<summ[j]){
                for(int k=0; k<m; k++){
                    double b=a[k][i];
                    a[k][i]=a[k][j];
                    a[k][j]=b;
                }
            }
        }
    }
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++) printf("%d ",a[j][i]);
        printf("\n");
    }//for
    
    return 0;
}

