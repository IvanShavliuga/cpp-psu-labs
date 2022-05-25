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
    double a[n];      //Массив данных
    //Ввод элементов массива
    for(int i=0; i<n; i++) scanf("%lf",&a[i]);
    //Сортировка по убыванию
    for(int i=0; i<n; i+=2)
        for(int j=i; j<n; j+=2)
            if(a[j]<a[i]){
                double b=a[j];
                a[j]=a[i];
                a[i]=b;
            }
    //Сортировка по возрастанию
    for(int i=1; i<n; i+=2)
        for(int j=i; j<n; j+=2)
            if(a[j]>a[i]){
                double b=a[j];
                a[j]=a[i];
                a[i]=b;
            }
    //Ввод элементов массива
    for(int i=0; i<n; i++) printf("%.3lf ",a[i]);
    printf("\n");
    
    return 0;
}

