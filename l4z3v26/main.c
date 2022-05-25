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
    int a[n][n];
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++) scanf("%d",&a[j][i]);
    }//for
    printf("\n");
    //Сортировка
    for(int j=0; j<n-1; j++){//Ниже диагонали
        for(int i=0; i<n-j;i++){
            for(int k=i; k<n-j; k++){
                if(a[i+j][i]>a[k+j][k]){
                    int b=a[i+j][i];
                    a[i+j][i]=a[k+j][k];
                    a[k+j][k]=b;
                }//if
            }//for
        }//for
        
    }//for
    //Сортировка
    for(int j=0; j<n-1; j++){//Выше диагонали
        for(int i=0; i<n-j;i++){
            for(int k=i; k<n-j; k++){
                if(a[i][i+j]>a[k][k+j]){
                    int b=a[i][i+j];
                    a[i][i+j]=a[k][k+j];
                    a[k][k+j]=b;
                }//if
            }//for
        }//for
        
    }//for
    for(int j=0; j<n; j++){
        for(int i=0; i<n; i++) printf("%d ",a[j][i]);
        printf("\n");
    }//for 
    return 0;
}

