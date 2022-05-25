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
#include <string.h>
#include <stdlib.h>

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
    char strings[15][80], //Массив строк
        predlog[30][70];  //Массив предложений
    int lengths[30];      //Длины предложений
    int n,v;//Кол-во имен,предложений
    //ввод строк
    int i;
    for(i=0;i<20; i++){
        gets(strings[i]); //Ввод
        if(strings[i][0]==0) break; //Пустая строка ?
    }
    n=i;
    v=0;
    //Обнуление предложений
    for(i=0; i<30; i++) predlog[i][0]=0;
    //Поиск предложений
    for(int i=0; i<n; i++){
        char *buf;
        strcpy(buf,strings[i]);
        while(buf!=NULL){
            //Найти символ '.' '!' '?'
            buf=strpbrk(buf,".?!");
            //Узнать длину строки
            int len=strlen(buf);
            //Если длина строки > 70
            if(len>70){
                puts("\nERROR\n");
                return 1;//Выход с ошибкой
            }
            //Символы окончания строки "!.?"
            //В следующим предложении не нужны
            //buf++;
            //Теперь найденое в массив
            strncat(predlog[v],buf,len+1);
            //Можно сразу и вывести
            puts(predlog[v]);
            v++;
            buf+=len;
        }
        //Массив не резиновый
        if(v>=30){
            puts("\nERROR\n");
            return 1;//Выход с ошибкой
        }//if
        //Остатки  уже следующее предложение
        strcat(predlog[v],buf);
    }//for
    return 0;
}

