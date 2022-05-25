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
    double a[n],plus[n];    //массив исходных данных
    for(int i=0; i<n;i++) scanf("%lf",&a[i]);
    int j=0; //Заносим положительные элементы в
    for(int i=0; i<n;i++)//отдельный массив
        if(a[i]>0)  {plus[j]=a[i];j++;}
    //Сортировка положительных
    for(int t=0; t<j; t++){
        for(int i=t;i<j;i++){
            if(plus[i]>plus[t]){
                double b=plus[i];
                plus[i]=plus[t];
                plus[t]=b;
            }//if
               
            
        }//for
    }//for
    //Запись отсортированных в исходный массив
    int t=0;
    for(int i=0; i<n;i++)
        if(a[i]>0) {a[i]=plus[t];t++;}
    //Вывод
    for(int i=0; i<n;i++) printf("%0.2lf ",a[i]);
    printf("\n");    
    return 0;
}

