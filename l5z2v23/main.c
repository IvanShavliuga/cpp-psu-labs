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
    char strings[20][80], //�������� ������
         name[20][80];    //��� ��������
    double values[15];//�������� ��������� ��������     
    int n,v;//���-�� ����,����� ��� ������ �����
    //���� �����
    int i;
    for(i=0;i<20; i++){
        gets(strings[i]);
        if(strings[i][0]==0) break; //������ ������ ?
    }//for
    n=i;
    //������ "����������" ������ �� ����� ��������
    //� �� ��������
    for(int i=0;i<n; i++){
        //����� ������ "=" (��. ������ �� �)
        char * str=strstr(strings[i],"=");
        //������ ������� ������� '=' � ������
        int posravno=str-strings[i];
        //������ ��� �������
        strncpy(name[i],strings[i],posravno);
        name[i][posravno]=0; //����� ������
        //�������� �� 2 ������� ������ � ������ str
        str+=2;  // ������� '=' � '[' ��� �� �����
        //���� ����� � i-�� ������
        for(int j=0; j<15; j++){
            char *buf=strpbrk(str,",]");
            if(buf==NULL) //���� ������ ',' ']'
            {//�� ������, �� ����� �����
                v=j;
                break;
            }//if
            int pos=buf-str;
            //������ ������� ������� ��� ������
            strncpy(buf,str,pos);
            //��������� � �����
            values[j]=atof(buf);
            // ������� ' ' � ',' 
            //��� �� ����� (������� 2) �� �����
            //��� � ��� ����� � buf (pos - �������) 
            str+=pos+2; 
        }//for
        //��� �� ���������
        for(int j=0; j<v; j++){
            for(int p=j; p<v;p++){
                if(values[j]>values[p]){
                    double b=values[p];
                    values[p]=values[j];
                    values[j]=b;
                }//if
            }//for
        }//for
        //� ����� ���������� � ������
        sprintf(strings[i],"%s=[",name[i]);
        for(int j=0; j<v;j++){
            char buf[40];
            //��������� �����?
            if(j<v-1) //��� ����� ", "
                sprintf(buf,"%0.1lf, \0",values[j]);
            else      //��  ����� "]"
                sprintf(buf,"%0.1lf]\0",values[j]);
            //��������� � �������� ������
            strcat(strings[i],buf);
        }//for
    }//for
    //������ ���������� ����
    //�� ����������� (strcmp(name[i],name[j])>0)
    //��� �������� (strcmp(name[i],name[j])<0)
    for(int i=0; i<n; i++){
        for(int j=i;j<n;j++){
            //name[i]>name[j]
            if(strcmp(name[i],name[j])>0){
                char buf[80];
                //������������ �������� ������
                strcpy(buf,strings[i]);
                strcpy(strings[i],strings[j]);
                strcpy(strings[j],buf);
                //������������ �����
                strcpy(buf,name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j],buf);
            }//if
        }//for
    }//for
    for(int i=0; i<n; i++) puts(strings[i]);
    return 0;
}

