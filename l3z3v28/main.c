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
    long int n,count;
    scanf("%ld",&n);
    count=0;
    for(long int i=1; i<n; i++){
        //Сумма пар чисел (1,2) (2,3)..(i,i+1)..(n-1,n)
        long int summ=i+i+1; 
        int prost=1; //Простое число? (1-да, 0-нет)
        //Алгоритм поиска простого числа
        for(long int j=2; j<summ; j++){
            if(summ%j==0) {prost=0; break;}
        }
        //Простое? Увеличиваем счетчик (count)
        if(prost==1) count++;
    }
    printf("%ld\n",count);
    return 0;
}

