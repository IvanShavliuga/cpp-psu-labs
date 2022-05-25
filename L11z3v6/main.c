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
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Для Builder
/*
#define _cputs(s)           cputs(s)
#define _textcolor(c)       textcolor(c)
#define _textbackground(c)  textbackground(c)
#define _cprintf(...)       cprintf(...)
#define _gotoxy(x,y)        gotoxy(x,y)
#define _strnset(s,n,c)     strnset(s,n,c)
#define _clrscr()           clrscr()
#define _clreol()           clreol()
*/
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
typedef struct {
	int day, mont, year,errorcode;	
}Data;
typedef struct _Naklad {
	int    number;
	int    day, mont, year;
	int    errorcode;
    double summ;
	char   FIO[21];
	struct _Naklad *next,*prev;
} Naklad;

Naklad *curr=NULL, *head=NULL;
//Коды ошибок
/*  0 - нет ошибки
	1 - введена пустая строка
    2 - день введен неверно
    3 - месяц введен неверно
	4 - сумма слишком большая
	5 - ввод прерван
	6 - номер слишком длинный
*/

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
}//WinToDos
//Форматированный ввод
Naklad GetString(void)
{
	register int i=0,f=0,j=0;
	register int key;
	Naklad tmp;
	
	char *string=calloc(256,1);
	_strnset(string,0,256);
	_gotoxy(1,24);
	_textbackground(2);
	_clreol();
	fflush(stdin);
	fflush(stdout);
	_ungetch(' ');
	do{ 
		key=_getch();
		switch(f)
		{
			case 9:
				if(j<20)
				{
					_cprintf("%c",key);
					tmp.FIO[j]=key;
					i++;
					j++;
				}
				else 
				{
					fflush(stdout);
					fflush(stdin);
					return tmp;
				}
				break;
			case 8:
				_ungetch(' ');
				f=9;
				break;
			case 7:
				if(key>='0'&&key<='9')
				{
					_cprintf("%c",key);
				    string[i]=key;
					i++;
			    }
				if(key=='.'&&j==0)
				{
					_cprintf(".");
					string[i]='.';
					i++;
					j=1;
				}
				if(i>10) 
				{
					tmp.errorcode=4;
					return tmp;
				}
				if(key==',')
				{
					f=8;
					j=0;
					_ungetch(',');
					_cprintf(",");
					string[i]=0;
					tmp.summ=atof(string);
				}
				break;
			case 6:
				f=7;
				_cprintf(" ");
				break;
			case 5:
				_ungetch(',');
				_cprintf(",");
				f=6;
				j=0;
				break;
			case 4:
				if(key>='0'&&key<='9')
				{
					_cprintf("%c",key);
				    string[i]=key;
					i++;
					j++;
			    }
				if(j>=4) 
				{
					f=5;
					j=0;
					_cprintf("\"");
					_ungetch('\"');
					string[i]=0;
					i=0;
					tmp.year=atoi(string);
				}
				break;
			case 3:
				if(key>='0'&&key<='9')
				{
					_cprintf("%c",key);
				    string[i]=key;
					i++;
					j++;
			    }
				if(j>=2) 
				{
					f=4;
					j=0;
					_cprintf(".");
					_ungetch('.');
					string[i]=0;
					i=0;
					tmp.mont=atoi(string);
				}
				break;
			case 2:
				if(key>='0'&&key<='9')
				{
					_cprintf("%c",key);
				    string[i]=key;
					i++;
					j++;
			    }
				if(j>=2) 
				{
					f=3;
					j=0;
					_cprintf(".");
					_ungetch('.');
					string[i]=0;
					i=0;
					tmp.day=atoi(string);
				}
				break;
			case 1:
				_cprintf("%c",key);
				_cprintf("\"");
				_ungetch('\"');
				f=2;
				break;
			case 0:
				if(key>='0'&&key<='9')
				{
					string[i]=key;
					i++;
					_cprintf("%c",key);
				}
				if(i>5)
				{
					tmp.errorcode=6;
					return tmp;
				}
				if(key==':')
				{
					f=1;
					string[i]=0;
					i=0;
					tmp.number=atoi(string);
					_cprintf(":");
					_ungetch(' ');
				}
				break;

		}
		if(key=='\n'||key=='\r') break;
		if(key==27) {i=0; break;}
		
	}while(1);
    string[i]=0;
    tmp.errorcode=0;
	if(!i) tmp.errorcode=1;
	
	fflush(stdout);
	fflush(stdin);
    if(f<9)
	{
		tmp.FIO[0]=0;
		tmp.day=0;
		tmp.mont=0;
		tmp.year=0;
		tmp.number=0;
		tmp.summ=0.0;
		tmp.errorcode=5;
	}
	else
	{
		if(tmp.day<1)  tmp.errorcode=2;
		switch(tmp.mont)
		{
			case 1:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			case 2:
			  if(tmp.day>29&&(tmp.year%4)==0&&
				(tmp.year%1000)!=0) tmp.errorcode=2;
			  if(tmp.day>28&&(tmp.year%4)!=0)
				tmp.errorcode=2;
			  break;
			case 3:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			case 4:
			  if(tmp.day>30) tmp.errorcode=2;
			  break;
			case 5:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			case 6:
			  if(tmp.day>30) tmp.errorcode=2;
			  break;
			case 7:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			case 8:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			case 9:
			  if(tmp.day>30) tmp.errorcode=2;
			  break;
			case 10:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			case 11:
			  if(tmp.day>30) tmp.errorcode=2;
			  break;
			case 12:
			  if(tmp.day>31) tmp.errorcode=2;
			  break;
			default:
              tmp.errorcode=3;
              break;	
		}//switch
	}//else
	return tmp;
}
//1  first>last
//-1 first<last
//0  first=last
int divdate(Data first,Data last)
{
	if(first.year==last.year&&
		first.mont==last.mont&&
		first.mont==last.mont)
		return 0;
	if(first.year>last.year)
		return 1;
	if(first.year<last.year)
		return -1;
	if(first.year==last.year&&
		first.mont>last.mont)
		return 1;
	if(first.year==last.year&&
		first.mont<first.mont)
		return -1;
	if(first.year==last.year&&
		first.mont==last.mont&&
		first.day>last.day)
		return 1;
	if(first.year==last.year&&
		first.mont==last.mont&&
		first.day<last.day)
		return -1;
}
Data CreateData(int day, int mont, int year)
{
	Data data;
	data.day=day;
	data.mont=mont;
	data.year=year;
	return data;
}
//Добавление в конец списка
int Add(Naklad data)
{
	Naklad *tmp=malloc(sizeof(Naklad));
	if(!tmp)
	{
		_cputs(WinToDos("Что-то с памятью моей стало."));
		return 0;
	}//if
	if(head==NULL)
	{
		head=malloc(sizeof(Naklad));
		if(!head)
		{
			_cputs(WinToDos("Что-то с памятью моей стало."));
			return 0;
		}//if

		head->number=data.number;
		head->day   =data.day;
		head->mont  =data.mont;
		head->year  =data.year;
		head->summ  =data.summ;
		_strnset(head->FIO,0,20);
		strcpy(head->FIO,data.FIO);
		head->prev=NULL;
		head->next=NULL;
		curr=head;
		return 1;
	}//if
        if(!curr)
        {
           curr=malloc(sizeof(Naklad));
           if(!curr){
             _cputs(WinToDos("Что-то с памятью моей стало."));
             return 0;
           }
           curr->next=NULL;
        }
	while(curr->next!=NULL) curr=curr->next;
	tmp->number=data.number;
	tmp->day   =data.day;
	tmp->mont  =data.mont;
	tmp->year  =data.year;
	tmp->summ  =data.summ;
	_strnset(tmp->FIO,0,20);
	strcpy(tmp->FIO,data.FIO);
	tmp->prev=curr;
	tmp->next=NULL;
	curr->next=tmp;
	curr=curr->next;
        return 1;
}//Add

void Delete(void)
{
	if(!curr)
	{
		return;
	}
	Naklad *tmp=curr->next;
	if(!curr->prev)
	{
		tmp=curr;
		curr=curr->next;
		head=curr;
		curr->prev=NULL;
		tmp->next=NULL;
		free(tmp);
		return;
	}
	if(!curr->next)
	{
		tmp=curr->prev;
		curr->prev->next=NULL;
		curr->prev=NULL;
		free(curr);
		curr=tmp;
		return;
	}
	curr->prev->next=curr->next;
	curr->next->prev=curr->prev;
	free(curr);
	if(!tmp)
	{
		curr->prev=NULL;
		curr->next=NULL;
		curr=NULL;
	}
	curr=tmp;
	
}
void print(void)
{
	Naklad *tmp=curr;
	curr=head;
	fflush(stdout);
    _gotoxy(1,2);
	if(!head)
	{
		_textbackground(1);
		_cputs(WinToDos("В списке нет элементов"));
		return;
	}
	while(curr!=NULL)
	{
		_textbackground(1);
		_clreol();
		if(tmp==curr) _textbackground(5);
		else          _textbackground(1);
		_cprintf("\b\t %d %d.%d.%d %lf %s\r\n",
			curr->number,curr->day,curr->mont,curr->year,
			curr->summ,curr->FIO);
		curr=curr->next;
	}
	_textbackground(1);
	_cputs(WinToDos("---- Конец списка ----\n"));
	curr=tmp;
}
void Destory(void)
{
	curr=head;
	while(head!=NULL)
	{
		head=curr->next;
		free(curr);
		curr=head;
	}
	curr=NULL;
	head=NULL;
}
void Insert(Naklad data)
{
	Naklad *tmp=malloc(sizeof(Naklad));
	if(!tmp)
	{
		_cputs(WinToDos("Что-то с памятью моей стало."));
		return;
	}//if
	tmp->number=data.number;
	tmp->day   =data.day;
	tmp->mont  =data.mont;
	tmp->year  =data.year;
	tmp->summ  =data.summ;
	_strnset(tmp->FIO,0,20);
	strcpy(tmp->FIO,data.FIO);
	tmp->prev=curr->prev;
	tmp->next=curr;
	curr->prev->next=tmp;
	curr->prev=tmp;
}
/* 1 -- возрастание
   0 -- убывание
*/
void AddUpor(char naprav,char pole,Naklad data)
{
    Naklad *tmp;
	curr=head;
	if(!curr) { Add(data); return;}
	if(pole==1){
		if(naprav) while(curr->next!=NULL&&curr->number<data.number) curr=curr->next;
		if(!naprav) while(curr->next!=NULL&&curr->number>data.number) curr=curr->next;
 	} 
	if(pole==2){
		if(naprav) while(curr->next!=NULL&&divdate(CreateData(curr->day,curr->mont,curr->year),CreateData(data.day,data.mont,data.year))==-1) curr=curr->next;
		if(!naprav) while(curr->next!=NULL&&divdate(CreateData(curr->day,curr->mont,curr->year),CreateData(data.day,data.mont,data.year))==1) curr=curr->next;
 	}   
	if(pole==3){
		if(naprav) while(curr->next!=NULL&&curr->summ<data.summ) curr=curr->next;
		if(!naprav) while(curr->next!=NULL&&curr->summ>data.summ) curr=curr->next;
 	}  
	if(pole==4){
		if(naprav) while(curr->next!=NULL&&_stricmp(curr->FIO,data.FIO)<0) curr=curr->next;
		if(!naprav) while(curr->next!=NULL&&_stricmp(curr->FIO,data.FIO)>0) curr=curr->next;
 	}  
	if(!curr->next)
	{
		Add(data);
		if(naprav) 
		{
			if((curr->prev->number>curr->number&&pole==1)||
			   (divdate(CreateData(curr->prev->day,curr->prev->mont,curr->prev->year),CreateData(curr->day,curr->mont,curr->year))==1&&pole==2)||
			   (curr->prev->summ>curr->summ&&pole==3)||
			   (_stricmp(curr->prev->FIO,curr->FIO)>0&&pole==4) )
			{
				if(!curr->prev->prev)
				{
					tmp=curr->prev;
					curr->prev->next=NULL;
					curr->prev=NULL;
					curr->next=tmp;
					tmp->prev=curr;
					head=tmp->prev;
					return;
				}
				tmp=curr;
				curr=curr->prev;
				curr->prev->next=tmp;
				tmp->next=curr;
				curr->next=NULL;
				curr->prev=tmp;
				tmp->prev=curr->prev->next;
				
			}	
		}
		if(!naprav) 
		{
			if((curr->prev->number<curr->number&&pole==1)||
			   (divdate(CreateData(curr->prev->day,curr->prev->mont,curr->prev->year),CreateData(curr->day,curr->mont,curr->year))==-1&&pole==2)||
			   (curr->prev->summ<curr->summ&&pole==3)||
			   (_stricmp(curr->prev->FIO,curr->FIO)<0&&pole==4) )
			{
				if(!curr->prev->prev)
				{
					tmp=curr->prev;
					curr->prev->next=NULL;
					curr->prev=NULL;
					curr->next=tmp;
					tmp->prev=curr;
					head=tmp->prev;
					return;
				}
				tmp=curr;
				curr=curr->prev;
				curr->prev->next=tmp;
				tmp->next=curr;
				curr->next=NULL;
				curr->prev=tmp;
				tmp->prev=curr->prev->next;
				
			}	
		}
		
		return;
	}
	
	if(!curr->prev)
    {
		tmp=malloc(sizeof(Naklad));
		if(!tmp)
		{
			_cputs(WinToDos("Что-то с памятью моей стало"));
			return;
		}
		strcpy(tmp->FIO,data.FIO);
		tmp->number=data.number;
		tmp->day=data.day;
		tmp->mont=data.mont;
		tmp->year=data.year;
		tmp->summ=data.summ;
		tmp->prev=NULL;
		tmp->next=head;
		head->prev=tmp;
		head=tmp;
		curr=head;
		return;
    }
	Insert(data);

}
void DeleteData(int day,int mont, int year)
{
	curr=head;
	if(!curr) return;
	do
	{
	  try:
		if(!curr) return;
		if(curr->year<year)
		{
			Delete();
			if(!curr)return;
			else if(curr->prev) curr=curr->prev;
			else          goto try;
			
		}
		if(curr->year==year)
		{
			if(curr->mont<mont)
			{
				Delete();
				if(!curr) return;
				else if(curr->prev) curr=curr->prev;
				else            goto try;				
			}
			if(curr->mont==mont)
			{
				if(curr->day<day) 
				{
					Delete();
					if(!curr) return;
					else if(curr->prev) curr=curr->prev;
					else            goto try;
					
				}
			}
		}
		if(!curr->next) return;
		curr=curr->next;
	}while(curr);
}
void IV2(int laba, int zadanie, int variant)
{
	char string[256];
	sprintf(string,"Лабораторная работа #%d Задача #%d Вариант #%d",laba,zadanie,variant);
	_textbackground(1);
	_clrscr();
	_textbackground(4);
	_gotoxy(1,1);
	_clreol();
	_gotoxy(1,25);
	_textbackground(0);
	_clreol();
	_gotoxy(1,24);
	_textbackground(2);
	_clreol();
	_textcolor(15);
	_gotoxy(1,1);
	_textbackground(4);
	_cprintf(WinToDos(string));
	_textbackground(1);
	_gotoxy(1,2);
}
char * ErrorCodeToString(int code)
{
	switch(code)
	{
		case 0: return NULL;
		case 1: return "ввод прерван\0";
		case 2: return "день введен неверно\0";
		case 3: return "месяц введен неверно\0";
		case 4: return "сумма слишком большая\0";
		case 5: return "ввод прерван\0";
		case 6: return "номер слишком длинный\0";
	}
	return NULL;
}
void Exchange(void)
{
  Naklad *tmp = curr->next;
  curr->next = tmp->next;
  tmp->prev = curr->prev;
  if(curr->next != NULL) curr->next->prev = curr;
  if(tmp->prev != NULL) tmp->prev->next = tmp;
  tmp->next   = curr;
  curr->prev = tmp;
  if(curr == head) head = tmp;
}
void SortBub(char n,char pole)
{
  if(!head) return;
  int Flag = 1;
  while(Flag){
    Flag = 0;
    curr = head;
    while(curr->next){
      if((n==1)&&((curr->number > curr->next->number&&pole==1)||
					(divdate(CreateData(curr->day,curr->mont,curr->year),CreateData(curr->next->day,curr->next->mont,curr->next->year))==1&&pole==2)||
					(curr->summ>curr->next->summ&&pole==3)||
					(_stricmp(curr->FIO,curr->next->FIO)>0&&pole==4))){
        Exchange();
        Flag = 1;
      }
	  else if((n==0)&&((curr->number < curr->next->number&&pole==1)||
					(divdate(CreateData(curr->day,curr->mont,curr->year),CreateData(curr->next->day,curr->next->mont,curr->next->year))==-1&&pole==2)||
					(curr->summ<curr->next->summ&&pole==3)||
					(_stricmp(curr->FIO,curr->next->FIO)<0&&pole==4))){
      
		Exchange();
        Flag = 1;
	  }
	  else curr = curr->next;
    }
  }
}


int main(int argc, char *argv[])
{
    Naklad tmp;
	int key,i;
	char sort=0,naprav=1,pole=1;
	IV2(11,3,6);
	while(1)
	{
		_gotoxy(1,25);
		_textbackground(0);
		_clreol();
		_cputs(WinToDos("F1 - добавить F2 - удалить F3 - упорядочить F4 - вывод Esc - выход"));
		key=_getch();
		if(key==27) {Destory();_gotoxy(1,24); exit(0);}
		if(key==0)
		{
			switch(_getch())
			{
				case 59:
					_gotoxy(1,25);
					_clreol();
					_cputs(WinToDos("Добавление элемента в список"));
					_sleep(1);
					_gotoxy(1,25);
					_clreol();
					_cputs(WinToDos("Введите данные в формате: номер: \"день.месяц.год\", сумма, ФИО"));
					tmp=GetString();
					_gotoxy(1,25);
					_textbackground(1);
					_clreol();
					if(!tmp.errorcode) 
					{
						if(!sort) 
							if(!Add(tmp))
							{
								_cputs(WinToDos("Не хватает памяти"));
								_sleep(1);
							}
						if(sort)
							AddUpor(naprav,pole,tmp);
					}
					else
					{
						_cputs(WinToDos(ErrorCodeToString(tmp.errorcode)));
						_sleep(1);
					}	
					break;
				case 60:
					_gotoxy(1,25);
					_clreol();
					_cputs(WinToDos("Удаление текущего элемента из списка"));
					_sleep(1);
					Delete();
					break;
				case 61:
					_gotoxy(1,25);
					_clreol();
					_cputs(WinToDos("Сортировка списка"));
					_sleep(1);
					_gotoxy(1,25);
					_clreol();
					_cputs(WinToDos("Введите направление сортировки (v-возрастание u-убывание)"));
					i=1;
					while(i)
					{
						switch(_getch())
						{
       						case 'U':
							case 'u':
           						naprav=0;
								i=0;
             			        break;
            				case 'V':
            				case 'v':
              					naprav=1;
								i=0;
           			            break;  	
						}
					}	
					_gotoxy(1,25);
					_clreol();
					_cputs(WinToDos("Введите номер поля"));
					i=1;
					while(i)
					{
						key=_getch();
						if(key>='1'&&key<='4'){
							pole=key-'0';
							i=0;
						}
					}
					SortBub(naprav,pole);
					sort=1;
					break;
				case 62:
					_textbackground(1);
					for(i=2; i<24; i++)
					{
						_gotoxy(1,i);
						_clreol();
					}
					print();
					break;
			}//switch
			_gotoxy(1,24);
			_textbackground(2);
			_clreol();
		}//if
	}//while
	_gotoxy(1,24);
  	return 0;
}//main

