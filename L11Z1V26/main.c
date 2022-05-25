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
//��� Builder
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
//���� ������
/*  0 - ��� ������
	1 - ������� ������ ������
    2 - ���� ������ �������
    3 - ����� ������ �������
	4 - ����� ������� �������
	5 - ���� �������
	6 - ����� ������� �������
*/

//�������������� �� ��������� Windows � ��������� DOS
char * WinToDos(char *source)
{
    char *result=calloc(strlen(source),sizeof(char));
    int i;   
	for( i=0; i<strlen(source); i++){
		if(source[i]>='�'&&source[i]<='�') 
			result[i]=source[i]-0x40;
		else if(source[i]>='�'&&source[i]<='�')
			result[i]=source[i]-0x10;
		else result[i]=source[i];
	}
	result[strlen(source)]=0;
	return(result);
}//WinToDos
//��������������� ����
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
//���������� ���� � ������� � ������� ��.��.����
//� ����������� �������� �� ������������
Data ScanData(void)
{
	register int i=0,f=0;
	register int key;
	Data data;
	
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
			case 2:
			    if(key>='0'&&key<='9')
				{
					string[i]=key;
					i++;
					_cprintf("%c",key);
				}
				if(i==4)
				{
					f=3;
					string[i]=0;
					data.year=atoi(string);
					_cprintf(WinToDos("�."));
				}
				break;
			case 1:
				if(key>='0'&&key<='9')
				{
					string[i]=key;
					i++;
					_cprintf("%c",key);
				}
				if(i==2)
				{
					f=2;
					string[i]=0;
					i=0;
					data.mont=atoi(string);
					_cprintf(".");
				}
				break;
			case 0:
				if(key>='0'&&key<='9')
				{
					string[i]=key;
					i++;
					_cprintf("%c",key);
				}
				if(i==2)
				{
					f=1;
					string[i]=0;
					i=0;
					data.day=atoi(string);
					_cprintf(".");
				}
				break;

		}
		if(key=='\n'||key=='\r') break;
		if(key==27) {i=0; break;}
		
	}while(1);
    string[i]=0;
    data.errorcode=0;
	if(!i) data.errorcode=1;
	
	fflush(stdout);
	fflush(stdin);
    if(f<2)
	{
		data.day=0;
		data.mont=0;
		data.year=0;
		data.errorcode=5;
	}
	else
	{
		if(data.day<1)  data.errorcode=2;
		switch(data.mont)
		{
			case 1:
			  if(data.day>31) data.errorcode=2;
			  break;
			case 2:
			  if(data.day>29&&(data.year%4)==0&&
				(data.year%1000)!=0) data.errorcode=2;
			  if(data.day>28&&(data.year%4)!=0)
				data.errorcode=2;
			  break;
			case 3:
			  if(data.day>31) data.errorcode=2;
			  break;
			case 4:
			  if(data.day>30) data.errorcode=2;
			  break;
			case 5:
			  if(data.day>31) data.errorcode=2;
			  break;
			case 6:
			  if(data.day>30) data.errorcode=2;
			  break;
			case 7:
			  if(data.day>31) data.errorcode=2;
			  break;
			case 8:
			  if(data.day>31) data.errorcode=2;
			  break;
			case 9:
			  if(data.day>30) data.errorcode=2;
			  break;
			case 10:
			  if(data.day>31) data.errorcode=2;
			  break;
			case 11:
			  if(data.day>30) data.errorcode=2;
			  break;
			case 12:
			  if(data.day>31) data.errorcode=2;
			  break;
			default:
              data.errorcode=3;
              break;	
		}//switch
	}//else
	return data;
}
//���������� � ����� ������
int Add(Naklad data)
{
	Naklad *tmp=malloc(sizeof(Naklad));
	if(!tmp)
	{
		_cputs(WinToDos("���-�� � ������� ���� �����."));
		return 0;
	}//if
	if(head==NULL)
	{
		head=malloc(sizeof(Naklad));
		if(!head)
		{
			_cputs(WinToDos("���-�� � ������� ���� �����."));
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
             _cputs(WinToDos("���-�� � ������� ���� �����."));
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
		curr=tmp;
		free(curr);
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
		_cputs(WinToDos("� ������ ��� ���������"));
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
	_cputs(WinToDos("---- ����� ������ ----\n"));
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
		_cputs(WinToDos("���-�� � ������� ���� �����."));
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
/* 1 -- �����������
   0 -- ��������
*/
void AddUpor(char naprav,Naklad data)
{
    Naklad *tmp;
	curr=head;
	if(!curr) { Add(data); return;}
	if(naprav) while(curr->next!=NULL&&curr->number<data.number) curr=curr->next;
	if(!naprav) while(curr->next!=NULL&&curr->number>data.number) curr=curr->next;
    if(!curr->next)
	{
		Add(data);
		if(naprav) 
		{
			if(curr->prev->number>curr->number)
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
			if(curr->prev->number<curr->number)
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
			_cputs(WinToDos("���-�� � ������� ���� �����"));
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

int main(int argc, char *argv[])
{
    Naklad tmp;
	Data data;
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
	_cprintf(WinToDos("������������ ������ #11 ������ #1 ������� #26"));
	i=1;
  	_gotoxy(1,25);
  	_textbackground(0);
  	_cprintf(WinToDos("������� ����������� (V-����������� U-��������)"));
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
	i=1;
    while(i)
    {
	  error:
		_gotoxy(1,25);
		_textbackground(0);
		_clreol();
		_cprintf(WinToDos("������ �����: �����: \"����.�����.���\", �����, ���"));
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
				_cputs(WinToDos("������: ���� ������ �������"));
				_sleep(3);
				goto error;
			case 3: 
				_cputs(WinToDos("������: ����� ������ �������"));
				_sleep(3);
				goto error;
			case 4: 
				_cputs(WinToDos("������: ����� ������� �������"));
				_sleep(3);
				goto error;
			case 1:
			case 5: 
				_cputs(WinToDos("���� �������"));
				i=0;
				break;
			case 6:
				_cputs(WinToDos("������: ����� ������� �������"));
				_sleep(3);
				goto error; 
			default:
				_cputs(WinToDos("������: � ������� GetString ��������� ����������� ������. ���������� ����� �������"));
				return 1;
		}
		if(tmp.day>0)
		  AddUpor(naprav,tmp);
		print();
		  
    }
	_gotoxy(1,25);
	_textbackground(0);
	_clreol();
	_cputs(WinToDos("�������� ���������"));
	_sleep(1);
	i=1;
	while(i)
	{
		_gotoxy(1,25);
		_textbackground(0);
		_clreol();
		_cputs(WinToDos("������� ���� � �������: ��.��.����"));
		data=ScanData();
		_gotoxy(1,25);
		_textbackground(0);
		_clreol();
		switch(data.errorcode)
		{
			case 0:
				i=0; 
				break;
			case 2: 
				_cputs(WinToDos("������: ���� ������ �������"));
				break;
			case 3: 
				_cputs(WinToDos("������: ����� ������ �������"));
				break;
			case 1:
			case 5: 
				_cputs(WinToDos("���� �������"));
				break;
			default:
				_cputs(WinToDos("������: � ������� ScanData ��������� ����������� ������. ���������� ����� �������"));
				return 1;

		}
		_sleep(3);
	}
	_textbackground(1);
	for(i=2; i<24; i++)
	{
		_gotoxy(1,i);
		_clreol();
	}
    DeleteData(data.day,data.mont,data.year);
	print();
	Destory();
	_textbackground(1);
	_gotoxy(1,23);
     
	return 0;
}//main

