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
    int n;            //Размерность массива
    scanf("%d",&n);   //Ввод размрности
    double a[n];      //Массив данных
    //Ввод элементов массива
    for(int i=0; i<n; i++) scanf("%lf",&a[i]);
    int minindex1=0,  //Номер 1-го минимума
        maxindex1=0;  //Номер 1-го максимума
    double max1=a[0], //Первый максимум
        min1=a[0];    //Первый минимум
    for(int i=1; i<n;i++){ //поиск 1-го минимума и 
                           //максимума
        if(a[i]<min1) {min1=a[i];minindex1=i;} //min
        if(a[i]>max1) {max1=a[i];maxindex1=i;} //max
    }
    int minindex2,    //Номер 2-го минимума
        maxindex2;    //Номер 2-го максимума
    double max2,      //2-й максимум
        min2;         //2-й минимум
    //А ВДРУГ 0-Й ЭЛЕМЕНТ ПЕРВЫЙ МИН./МАКС.?
    //тогда 2-й минимум 1-й элемент
    if(minindex1==0) minindex2=1; 
    else             minindex2=0;
    //2-й максимум 1-й элемент
    if(maxindex1==0) maxindex2=1;
    else             maxindex2=0;
    max2=a[maxindex2];
    min2=a[minindex2];
    for(int i=1; i<n;i++){ //поиск 2-го минимума и 
                           //максимума
        if(a[i]<min2&&minindex1!=i) //Первый минимум?
            {min2=a[i];minindex2=i;} //нет -- min
        if(a[i]>max2&&maxindex1!=i) //Первый макс.?
            {max2=a[i];maxindex2=i;} //нет -- max
    }
    //ТЕПЕРЬ 3-Й МИН.
    int minindex3=2;    //Номер 3-го минимума
    double min3=a[2]; //3-й минимум
    for(int i=0; i<n;i++){ //поиск 3-го минимума
        if(a[i]<min3&&minindex1!=i&&minindex2!=i) 
            {min3=a[i];minindex3=i;} //min
        
    }
    printf("%lf\n",min3+max2);
    //Если мин. и макс соседи, что заменить нулями?
    if(abs(maxindex2-minindex3)>1){
        //Поиск участка сортировки
        //мин идет раньше макс. или наоборот
        int start=(minindex3>maxindex2)?(maxindex2):
                   (minindex3);
        int end  =(minindex3<maxindex2)?(maxindex2):
                   (minindex3);
        //сортировка
        for(int i=start+1;i<end;i++){
            for(int j=i; j<end;j++){
                if(a[j]<a[i]){
                    double b=a[j];
                    a[j]=a[i];
                    a[i]=b;
                }
            }
        }
    }
    //Вывод элементов массива
    for(int i=0; i<n; i++) printf("%.3lf ",a[i]);
    printf("\n");
    return 0;
}

