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
    char strings[20][80], //исходные данные
         name[20][80];    //Имя массивов
    double values[15];//Значения элементов массивов     
    int n,v;//Кол-во имен,чисел для одного имени
    //ввод строк
    int i;
    for(i=0;i<20; i++){
        gets(strings[i]);
        if(strings[i][0]==0) break; //Пустая строка ?
    }//for
    n=i;
    //Теперь "расчлиняем" строки на имена массивов
    //и их значения
    for(int i=0;i<n; i++){
        //Поиск строки "=" (см. лекции по С)
        char * str=strstr(strings[i],"=");
        //Узнать позицию символа '=' в строке
        int posravno=str-strings[i];
        //Узнаем имя массива
        strncpy(name[i],strings[i],posravno);
        name[i][posravno]=0; //Конец строки
        //Перейдем на 2 позиции вправо в строке str
        str+=2;  // символы '=' и '[' нам не нужны
        //Ищем числа в i-ой строке
        for(int j=0; j<15; j++){
            char *buf=strpbrk(str,",]");
            if(buf==NULL) //Если символ ',' ']'
            {//не найден, то конец цикла
                v=j;
                break;
            }//if
            int pos=buf-str;
            //Узнаем элемент массива как строку
            strncpy(buf,str,pos);
            //Переводим в число
            values[j]=atof(buf);
            // символы ' ' и ',' 
            //нам не нужны (поэтому 2) не нужно
            //Уже и это число в buf (pos - поэтому) 
            str+=pos+2; 
        }//for
        //Тут же сортируем
        for(int j=0; j<v; j++){
            for(int p=j; p<v;p++){
                if(values[j]>values[p]){
                    double b=values[p];
                    values[p]=values[j];
                    values[j]=b;
                }//if
            }//for
        }//for
        //и опять записываем в строку
        sprintf(strings[i],"%s=[",name[i]);
        for(int j=0; j<v;j++){
            char buf[40];
            //последнее число?
            if(j<v-1) //Нет пишем ", "
                sprintf(buf,"%0.1lf, \0",values[j]);
            else      //Да  пишем "]"
                sprintf(buf,"%0.1lf]\0",values[j]);
            //Добавляем к исходной строке
            strcat(strings[i],buf);
        }//for
    }//for
    //Теперь сортировка имен
    //По возрастанию (strcmp(name[i],name[j])>0)
    //для убывания (strcmp(name[i],name[j])<0)
    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            //name[i]>name[j]
            if(strcmp(name[i],name[j])>0){
                char buf[80];
                //Переставляем исходные строки
                strcpy(buf,strings[i]);
                strcpy(strings[i],strings[j]);
                strcpy(strings[j],buf);
                //Переставляем имена
                strcpy(buf,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],buf);
            }//if
        }//for
    }//for
    for(int i=0; i<n; i++) puts(strings[i]);
    return 0;
}

