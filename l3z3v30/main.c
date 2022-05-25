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
    double a,b,u,v;
    int n;
    //Ввод данных
    scanf("%lf %lf %d",&u,&v,&n);
    //Инициализация
    a=u;
    b=v;
    double summ=0,//Сумма
        fact=1;   //Фактариал
    for(int i=1; i<n; i++){
        //Текущее значение суммы
        summ+=a*b/(fact*(fact+1));
        //Вычислям фактариал 
        fact*=i;
        //Переменная в которой хранится значение
        //переменной a[i-1], чтобы вычеслить потом
        //Значение переменной b=2*a[i-1]+b
        double buf=a;
        a=2*b+a;
        b=2*buf+b;
    }   //Конец цикла
    printf("%lf\n",summ); //Вывод результата
    return 0; // Все
}

