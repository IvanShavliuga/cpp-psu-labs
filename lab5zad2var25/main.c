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
	char strings[15][80],res[15][80], slovar[50][80];
	puts("Vvedite predlogenia:");
	int n;//кол-во Введенных предложений
	for(n=0; n<15; n++){
		gets(strings[n]);
		if(strings[n][0]==0) break;
	}
	puts("Vvedite slovar:");
	//Ввод словаря
	int m; //Кол-во введенных слов в словаре
	for(m=0;m<50;m++){
		gets(slovar[m]);
		if(slovar[m][0]==0) break;
	}
	puts("Result:");
	for(int i=0; i<n; i++){
		char buf[80]; //Буффер для работы с strings[i]
		int len=0;    //Длина текущего слова
		//Обнуление результата 
		res[i][0]=0;
	next:
		//strings[i] не надо портить
		strcpy(buf,strings[i]);
		//устанавливаем конец строки
		buf[strlen(strings[i])]=0;
		//Поиск текущего слова
		char *slovo=strtok(buf," ,.!?");
		if(slovo==NULL) continue;
		int f=0; //Флаг: есть ли слово в словаре
				 //0 -- нет
		for(int j=0; j<m;j++){
			if(strcmp(slovo,slovar[j])==0) {
				f=1;
				break;
			}
		}
		//Преобразование к верхнему регистру
		if(f==0) _strupr(slovo);
		//Записываем в strings[i] резльтат 
		len=strlen(slovo);//Вычисление длины
		strcat(res[i],slovo);
		strcat(res[i]," ");
		//Указатель на strings[i]
		char *ukaz=strings[i];//=="Слово1 слово2 ..."
		//Переход к следующему слову
		ukaz+=len;     //=="Слово2 слово3 ..."
		if(ukaz!=NULL) {
			strcpy(strings[i],ukaz+1);
			goto next;
		}
		
	}
	for(int i=0; i<n;i++) puts(res[i]);
    return 0;
}

