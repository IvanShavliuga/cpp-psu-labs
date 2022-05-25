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
    int a[n];       //массив исходных данных
    for(int i=0; i<n;i++) scanf("%d",&a[i]);
    //Вывод
    for(int i=0; i<n;i++) printf("%d ",a[i]);
    printf("\n");
    
    return 0;
}

