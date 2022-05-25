
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
unsigned int increment;
//��������� "���������"
typedef struct Processor
{
	char company[10]; //�������������
	char model[15];   //������
	long  herz;       //�������� �������
	char number[10];  //���������� �����
} Processor;
//�������������� �� ������ � ��������� "���������"
Processor StringToProcessor(char *string)
{
	Processor proc; //������� ���������
	int len;		//������� �������-�����������
	//����������-������ ��� ������ ����� � ������
	char *buf=calloc(strlen(string),sizeof(char));
	//��������� �������
	_strnset(buf,0,strlen(string));
	//��������� ���� ������ ��������� proc
    _strnset(proc.company,0,10);
	_strnset(proc.model,0,15);
	_strnset(proc.number,0,10);
	proc.herz=0; //0 - ������, �������� ������
	//����� ������� �����������
	buf=strchr(string,' ');
	//��� ��� -- ������ � �����
	if(buf==NULL) return proc;
	//��������� ������� �������-�����������,
	//� ������ � ��� � ����� �����
	len=buf-string;
	//��������: ������ ����� ��������� �����?
    if(len>10) len=10; //�������� ������
	//�������� len ���� � proc.company
	strncpy(proc.company,string,len);
	proc.company[len]=0;
	//������� �� ��������� ������
	buf++;
	//����������� buf � string
	strcpy(string,buf);
	//����� ���� �����������
	buf=strchr(string,' ');
	//��� ��� -- ������ � �����
	if(buf==NULL) return proc;
	//��������� ������� �������-�����������,
	len=buf-string;
	//��������: ������ ����� ��������� �����?
    if(len>15) len=15; //�������� ������
	//�������� len ���� � proc.company
	strncpy(proc.model,string,len);
	proc.model[len]=0;
	//������� �� ��������� ������
	buf++;
	//���� �������
	//����������� buf � string
	strcpy(string,buf);
	//����� ���� �����������
	buf=strchr(string,' ');
	//��� ��� -- ������ � �����
	if(buf==NULL) return proc;
	//��������� ������� �������-�����������,
	len=buf-string;
	//������
	char *b=calloc(len,sizeof(char));
	//�������� � ������ �������� ��������
	strncpy(b,string,len);
	//���� ������ "MHz"
	char *c=strstr(b,"MHz");
	if(c==NULL) return proc; //��� -- ������
	len=c-b; //������� ������ "Mhz"
	// �������� ������
	b[len]=0;
	//����������� � �����
	proc.herz=atol(b);
	//���������� �����������
	buf++;
	//��������� ����� ����������� ����� (������)
	len=strlen(buf);
	//��������: ������ ����� ������
	if(len!=10) {proc.herz=0; return proc;}
	//�������� ��� � proc.number
	strcpy(proc.number,buf);
	//�������������� � �������� ��������
	_strupr(proc.number);
	//��������: � ����� �����������������?
	_strupr(proc.number);
	for(int i=0; i<10; i++){
		if(proc.number[i]>'9')
		    if(proc.number[i]<'A'||proc.number[i]>'F')  { proc.herz=0; return proc;}
		if(proc.number[i]<'0'){proc.herz=0; return proc;}
	}
	free(b);
	free(buf); //������������ ������ ��� ������
	return proc;
}
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
}
//�������� �����
int LineFind(Processor proc[],int count,char number[10])
{
	int res=-1; //����� �� �������
	if(count<=0) return res;
	for(int i=0; i<count;i++)
	{
		if(strcmp(proc[i].number,number)==0) { res=i; break;}
		increment++;
	}
	return res;
} 
//�������� �����
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
	puts(WinToDos("������������ ������ 10\n"
			      "������� 5 ������� 1\n"
				  "�����: ������ �. �. 06-��-2"));
	while(1)
	{
		puts(WinToDos("������� ����� �������:"));
		gets(string);
		count=atoi(string);
		if(count>0) break;
	}
	proc=calloc(count,sizeof(Processor));
	puts(WinToDos("������� ������ � �������:"));
	puts(WinToDos("������������� ������ �������MHz �����"));
    for(int i=0; i<count; i++)
	{
		while(cikl)
		{
			printf("%d. ",i+1);
			gets(string);
			tmp=StringToProcessor(string);
			if(tmp.herz==0) puts(WinToDos("������ ��� ����� ������"));
			else if(LineFind(proc,i+1,tmp.number)>=0)
				puts(WinToDos("������ � ����� ������� ��� ����������"));
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
		if(alg==-1) puts(WinToDos("������: ��������� �������� ������ ������� �������"));
	}
	while(1)
	{
		puts(WinToDos("������� �����:"));
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
				puts(WinToDos("������� ����� ��������� ������ (0-�������� 1-��������)"));
				scanf("%d",&alg);
				fflush(stdin);
			}
			int r;
			if(alg==0) r=LineFind(proc,count,string);
			else if(alg==1) r=BSearch(proc,count,string);
			else { puts(WinToDos("������ �����")); break;}
			if(r==-1) puts(WinToDos("��������� � ����� ������� �� ������"));
			else
				printf("%s\n%s %s %dMHz %s\n",WinToDos("������ ��������� � ������:"),
					                        proc[r].company,
											proc[r].model,
											proc[r].herz,
											proc[r].number);
			alg=-1;
			puts(WinToDos("���-�� ��������:"));
			printf("%d\n",increment);
		}//if
		else if(strlen(string)==0) break; //�����
		else puts(WinToDos("������ ��� ����� ������"));
	}//while
	free(string);	
	
	return 0;
}

