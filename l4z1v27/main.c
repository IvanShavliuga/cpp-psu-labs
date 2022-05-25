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
    int n;          //Размерность
    scanf("%d",&n); //Ввод n
    int a[n],       //массив исходных данных
        plus[n],    //массив для полоительных
        minus[n];   //массив для отрицатеьных
    for(int i=0; i<n;i++) scanf("%d",&a[i]);
    int p=0,m=0;//индексы для plus,minus
    for(int i=0; i<n;i++){
        if(a[i]>0) {plus[p]=a[i];p++;} //Полоительный?
        if(a[i]<0) {minus[m]=a[i];m++;}//Отрицательный?

    }
    //Запись нулей
    for(int i=0; i<n; i++) a[i]=0;
    //Запись отрицательных
    int j=0;
    for(int i=0; i<m; i++) 
        {a[i]=minus[j];j++;}
    //Запись положительных
    j=0;
    for(int i=m; i<m+p; i++) 
        {a[i]=plus[j];j++;}
    //Вывод
    for(int i=0; i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

