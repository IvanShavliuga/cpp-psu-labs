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
    int n,m;
    scanf("%d %d",&n,&m);
    double a[n][m],   //Матрица
        b[m],r[m];    //Вводимый и результирующий векторы
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++) scanf("%lf",&a[j][i]);
    }//for
    for(int i=0; i<m; i++) scanf("%lf",&b[i]);
    printf("\n");
    //Умножение матрицы на вектор (см. "Вышку" за 1-й 
    //семестр)
    for(int j=0; j<n; j++){
        r[j]=0;  //Обнуление перед умножением
        for(int i=0; i<m; i++){
            r[j]+=a[j][i]*b[i];
        } 
    }

    for(int i=0; i<n; i++) printf("%lf ",r[i]);
    printf("\n");
    return 0;
}

