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
	int n;//���-�� ��������� �����������
	for(n=0; n<15; n++){
		gets(strings[n]);
		if(strings[n][0]==0) break;
	}
	puts("Vvedite slovar:");
	//���� �������
	int m; //���-�� ��������� ���� � �������
	for(m=0;m<50;m++){
		gets(slovar[m]);
		if(slovar[m][0]==0) break;
	}
	puts("Result:");
	for(int i=0; i<n; i++){
		char buf[80]; //������ ��� ������ � strings[i]
		int len=0;    //����� �������� �����
		//��������� ���������� 
		res[i][0]=0;
	next:
		//strings[i] �� ���� �������
		strcpy(buf,strings[i]);
		//������������� ����� ������
		buf[strlen(strings[i])]=0;
		//����� �������� �����
		char *slovo=strtok(buf," ,.!?");
		if(slovo==NULL) continue;
		int f=0; //����: ���� �� ����� � �������
				 //0 -- ���
		for(int j=0; j<m;j++){
			if(strcmp(slovo,slovar[j])==0) {
				f=1;
				break;
			}
		}
		//�������������� � �������� ��������
		if(f==0) _strupr(slovo);
		//���������� � strings[i] �������� 
		len=strlen(slovo);//���������� �����
		strcat(res[i],slovo);
		strcat(res[i]," ");
		//��������� �� strings[i]
		char *ukaz=strings[i];//=="�����1 �����2 ..."
		//������� � ���������� �����
		ukaz+=len;     //=="�����2 �����3 ..."
		if(ukaz!=NULL) {
			strcpy(strings[i],ukaz+1);
			goto next;
		}
		
	}
	for(int i=0; i<n;i++) puts(res[i]);
    return 0;
}

