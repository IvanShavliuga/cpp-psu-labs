
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned int increment;
//Структура "Процессор"
typedef struct Processor
{
	char company[10]; //Производитель
	char model[15];   //Модель
	long  herz;       //Тактовая частота
	char number[10];  //Порядковый номер
} Processor;
//Преобразование из строки в структуру "Процессор"
Processor StringToProcessor(char *string)
{
	Processor proc; //Искомая структура
	int len;		//Позиция символа-разделителя
	//Переменная-буффер для поиска слова в строке
	char *buf=calloc(strlen(string),sizeof(char));
	//Обнуление буффера
	_strnset(buf,0,strlen(string));
	//Обнуление всех данных структуры proc
    _strnset(proc.company,0,10);
	_strnset(proc.model,0,15);
	_strnset(proc.number,0,10);
	proc.herz=0; //0 - ошибка, неверный формат
	//Поиск символа разделителя
	buf=strchr(string,' ');
	//Его нет -- ошибка и выход
	if(buf==NULL) return proc;
	//Вычисляем позицию символа-разделителя,
	//а вместе с тем и длину слова
	len=buf-string;
	//Проверка: какова длина найденого слова?
    if(len>10) len=10; //Обрезаем лишнее
	//Копируем len байт в proc.company
	strncpy(proc.company,string,len);
	proc.company[len]=0;
	//Переход на следующий символ
	buf++;
	//Копирование buf в string
	strcpy(string,buf);
	//Снова ищем разделитель
	buf=strchr(string,' ');
	//Его нет -- ошибка и выход
	if(buf==NULL) return proc;
	//Вычисляем позицию символа-разделителя,
	len=buf-string;
	//Проверка: какова длина найденого слова?
    if(len>15) len=15; //Обрезаем лишнее
	//Копируем len байт в proc.company
	strncpy(proc.model,string,len);
	proc.model[len]=0;
	//Переход на следующий символ
	buf++;
	//Ищем частоту
	//Копирование buf в string
	strcpy(string,buf);
	//Снова ищем разделитель
	buf=strchr(string,' ');
	//Его нет -- ошибка и выход
	if(buf==NULL) return proc;
	//Вычисляем позицию символа-разделителя,
	len=buf-string;
	//Буффер
	char *b=calloc(len,sizeof(char));
	//Копируем в буффер найденое значение
	strncpy(b,string,len);
	//Ищем строку "MHz"
	char *c=strstr(b,"MHz");
	if(c==NULL) return proc; //Нет -- ошибка
	len=c-b; //Позиция строки "Mhz"
	// Обрезаем строку
	b[len]=0;
	//Преобразуем в число
	proc.herz=atol(b);
	//Пропускаем разделитель
	buf++;
	//Вычисляем длину оставшегося слова (номера)
	len=strlen(buf);
	//Проверка: какова длина номера
	if(len!=10) {proc.herz=0; return proc;}
	//Копируем его в proc.number
	strcpy(proc.number,buf);
	//Преобразование к верхнему регистру
	_strupr(proc.number);
	//Проверка: а номер шестнадцатиричный?
	_strupr(proc.number);
	for(int i=0; i<10; i++){
		if(proc.number[i]>'9')
		    if(proc.number[i]<'A'||proc.number[i]>'F')  { proc.herz=0; return proc;}
		if(proc.number[i]<'0'){proc.herz=0; return proc;}
	}
	free(b);
	free(buf); //Освобождение памяти под буффер
	return proc;
}
//Преобразование из кодировки Windows в кодировку DOS
char * WinToDos(char *source)
{
    char *result=calloc(strlen(source),sizeof(char));
    int i;   
	for( i=0; i<strlen(source); i++){
		if(source[i]>='А'&&source[i]<='п') 
			result[i]=source[i]-0x40;
		else if(source[i]>='р'&&source[i]<='я')
			result[i]=source[i]-0x10;
		else result[i]=source[i];
	}
	result[strlen(source)]=0;
	return(result);
}
//Линейный поиск
int LineFind(Processor proc[],int count,char number[10])
{
	int res=-1; //Слово не найдено
	if(count<=0) return res;
	for(int i=0; i<count;i++)
	{
		if(strcmp(proc[i].number,number)==0) { res=i; break;}
		increment++;
	}
	return res;
} 
//Бинарный поиск
int _BSearch(Processor *p,int lo,int hi, char str[10])
{
 	int mid;
	if((hi-lo)<=1) 
		return -1;
 	mid = (lo+hi)/2;
	increment++;
	if(strcmp(p[mid].number,str)==0) 
		return mid;
   	else if(strcmp(p[mid].number,str)>0) 
		return _BSearch(p,lo,mid,str);
    else 
		return _BSearch(p,mid,hi,str);
}
int BSearch(Processor *p,int n,char str[10])
{
	increment++; 
	if(strcmp(p[0].number,str)==0) 
	{
		return 0;
	}
	increment++;
	if(strcmp(p[n-1].number,str)==0) return n-1;
 	return _BSearch(p,0,n-1,str);
}

int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
	Processor *proc,tmp;
	int count,cikl=1;
	int alg=-1;
	char *string=calloc(1024,sizeof(char));
	increment=0;
	puts(WinToDos("Лабораторная работа 10\n"
			      "Вариант 5 Задание 1\n"
				  "Автор: Иванов И. С. 06-ИТ-2"));
	while(1)
	{
		puts(WinToDos("Введите число записей:"));
		gets(string);
		count=atoi(string);
		if(count>0) break;
	}
	proc=calloc(count,sizeof(Processor));
	puts(WinToDos("Введите запись в формате:"));
	puts(WinToDos("производитель модель частотаMHz номер"));
    for(int i=0; i<count; i++)
	{
		while(cikl)
		{
			printf("%d. ",i+1);
			gets(string);
			tmp=StringToProcessor(string);
			if(tmp.herz==0) puts(WinToDos("Ошибка при вводе данных"));
			else if(LineFind(proc,i+1,tmp.number)>=0)
				puts(WinToDos("Запись с таким номером уже существует"));
			else
			{ 	
				proc[i]=tmp;
				cikl=0;
			}//else
		}//while
		cikl=1;
	}//for
	if(argc==2)
	{
		if(_stricmp(argv[1],"a:linear")) alg=0;
		else if(_stricmp(argv[1],"a:binary")) alg=1;
		else alg=-1;
		if(alg==-1) puts(WinToDos("Ошибка: параметры командой строки введены неверно"));
	}
	while(1)
	{
		puts(WinToDos("Введите номер:"));
		gets(string);
		_strupr(string);
		for(cikl=0;cikl<strlen(string);cikl++)
		{
			if(string[cikl]>'9')
				if(string[cikl]<'A'&&string[cikl]>'F')
				{
				    string[1]=0;
					break;
			    }
			if(string[cikl]<'0') {
			    string[1]=0;
				break;
			}
	    }
		if(strlen(string)==10)
		{
			if(alg==-1){
				puts(WinToDos("Введите номер алгоритма поиска (0-линейный 1-бинарный)"));
				scanf("%d",&alg);
				fflush(stdin);
			}
			int r;
			if(alg==0) r=LineFind(proc,count,string);
			else if(alg==1) r=BSearch(proc,count,string);
			else { puts(WinToDos("Ошибка ввода")); break;}
			if(r==-1) puts(WinToDos("Процессор с таким номером не найден"));
			else
				printf("%s\n%s %s %dMHz %s\n",WinToDos("Запись находится в списке:"),
					                        proc[r].company,
											proc[r].model,
											proc[r].herz,
											proc[r].number);
			alg=-1;
			puts(WinToDos("Кол-во итераций:"));
			printf("%d\n",increment);
		}//if
		else if(strlen(string)==0) break; //Выход
		else puts(WinToDos("Ошибка при вводе данных"));
	}//while
	free(string);	
	
	return 0;
}

