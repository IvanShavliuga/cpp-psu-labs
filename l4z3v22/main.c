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
    int m,n;  //Размерность 1-ой матрицы
    int p,k;  //Размерность 2-ой матрицы
    scanf("%d %d %d %d",&m,&n,&p,&k);
    //Можно перемножить матрицы? (см. "вышку")
    if(n!=p) return 0; //Выход
    double a[m][n], b[p][k],//Вводимые матрицы
        r[m][k];  //Результирующая матрица
    //Ввод матриц j=строка i=столбец
    for(int j=0; j<m; j++){
        for(int i=0; i<n; i++) scanf("%lf",&a[j][i]);
    }//for
    for(int j=0; j<p; j++){
        for(int i=0; i<k; i++) scanf("%lf",&b[j][i]);
    }//for
    //Умножаем
    for(int j=0; j<m; j++){
        for(int i=0;i<k;i++){
            r[j][i]=0;
            for(int t=0;t<n;t++) 
                r[j][i]+=a[j][t]*b[t][i];
        }
    }
    //Проверка. Симметричная?
    int f=1; //1-да 0-нет
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

