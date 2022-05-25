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
#include <conio.h>
#include <stdlib.h>
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
void print(void)
{
	Naklad *tmp=curr;
	curr=head;
	int i;
	fflush(stdout);
    for(i=0; i<20; i++)
	{
		_gotoxy(0,i+2);
		_textbackground(1);
		_clreol();
	}	
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
void GoToElem(int index)
{
	int i=0;
	Naklad *tmp=curr;
	curr=head;
	while(i<index)
	{
		if(curr->next==NULL) 
		{
			_cputs(WinToDos("Элемент с таким номером не обнаружен в списке\n"));
			curr=tmp;
			return;
		}
		curr=curr->next;
		i++;
	}
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
void Exchange(void)
{
  Naklad *tmp = curr->next;
  curr->next = tmp->next;
  tmp->prev = curr->prev;
  if(curr->next != NULL) curr->next->prev = curr;
  if(tmp->prev != NULL) tmp->prev->next = tmp;
  tmp->next = curr;
  curr->prev = tmp;
  if(curr == head) head = tmp;
}
void SortBub(char n)
{
  if(!head) return;
  int Flag = 1;
  while(Flag){
    Flag = 0;
    curr = head;
    while(curr->next){
      if(((n==1)&&(curr->number > curr->next->number))||((n==0)&&(curr->number<curr->next->number))){
        Exchange();
        Flag = 1;
       }else curr = curr->next;
    }
  }
}


int main(int argc, char *argv[])
{
    Naklad tmp;
	int i;
	char naprav=1;
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
	_cprintf(WinToDos("Лабораторная работа #11 Задача #2 Вариант #19"));
	i=1;
    while(i)
    {
	  error:
		_gotoxy(1,25);
		_textbackground(0);
		_clreol();
		_cprintf(WinToDos("ФОРМАТ ВВОДА: номер: \"день.месяц.год\", сумма, ФИО"));
		_textcolor(15);
		_textbackground(1);
    	_gotoxy(1,2);
		tmp=GetString();
		_textbackground(0);
		_gotoxy(1,25);
		_clreol();
		switch(tmp.errorcode)
		{
			case 0: 
				break;
			case 2: 
				_cputs(WinToDos("ОШИБКА: день введен неверно"));
				_sleep(1);
				goto error;
			case 3: 
				_cputs(WinToDos("ОШИБКА: месяц введен неверно"));
				_sleep(1);
				goto error;
			case 4: 
				_cputs(WinToDos("ОШИБКА: сумма слишком большая"));
				_sleep(1);
				goto error;
			case 1:
			case 5: 
				_cputs(WinToDos("ввод прерван"));
				i=0;
				break;
			case 6:
				_cputs(WinToDos("ОШИБКА: номер слишком длинный"));
				_sleep(1);
				goto error; 
			default:
				_cputs(WinToDos("ОШИБКА: в функции GetString произошла неопознаная ошибка. приложение будет закрыто"));
				return 1;
		}
		if(tmp.day>0)
		  Add(tmp);
		print();
		  
    }
	_gotoxy(1,25);
	_textbackground(0);
	_clreol();
	_cputs(WinToDos("Сортировка элементов"));
	_sleep(1);
	i=1;
  	_gotoxy(1,25);
  	_textbackground(0);
  	_cprintf(WinToDos("Введите направление (V-возрастание U-убывание)"));
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
	SortBub(naprav);
	print();
	Destory();
	_textbackground(1);
	_gotoxy(1,23);
     
	return 0;
}//main


