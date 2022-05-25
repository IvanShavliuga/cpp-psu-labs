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
    char strings[15][80], //������ �����
        predlog[30][70];  //������ �����������
    int lengths[30];      //����� �����������
    int n,v;//���-�� ����,�����������
    //���� �����
    int i;
    for(i=0;i<20; i++){
        gets(strings[i]); //����
        if(strings[i][0]==0) break; //������ ������ ?
    }
    n=i;
    v=0;
    //��������� �����������
    for(i=0; i<30; i++) predlog[i][0]=0;
    //����� �����������
    for(int i=0; i<n; i++){
        char *buf;
        strcpy(buf,strings[i]);
        while(buf!=NULL){
            //����� ������ '.' '!' '?'
            buf=strpbrk(buf,".?!");
            //������ ����� ������
            int len=strlen(buf);
            //���� ����� ������ > 70
            if(len>70){
                puts("\nERROR\n");
                return 1;//����� � �������
            }
            //������� ��������� ������ "!.?"
            //� ��������� ����������� �� �����
            //buf++;
            //������ �������� � ������
            strncat(predlog[v],buf,len+1);
            //����� ����� � �������
            puts(predlog[v]);
            v++;
            buf+=len;
        }
        //������ �� ���������
        if(v>=30){
            puts("\nERROR\n");
            return 1;//����� � �������
        }//if
        //�������  ��� ��������� �����������
        strcat(predlog[v],buf);
    }//for
    return 0;
}

