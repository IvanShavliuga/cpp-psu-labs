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
    double a[n][m];
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++) scanf("%lf",&a[j][i]);
    }//for
    //Поиск минимумов   
    double min[n]; //массив для минимумов
    for(int j=0; j<n; j++){
        min[j]=a[j][0];
        for(int i=1; i<m; i++) 
            if(a[j][i]<min[j]) min[j]=a[j][i];
    }//for
    //Сортировка
    for(int j=0; j<n; j++){
        for(int i=j; i<n;i++){
            if(min[i]>min[j]){
                for(int k=0; k<m; k++){
                    double b=a[i][k];
                    a[i][k]=a[j][k];
                    a[j][k]=b;
                }
            }
        }
    }
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++) printf("%0.2lf ",a[j][i]);
        printf("\n");
    }//for
    
    return 0;
}

