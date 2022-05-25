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
#include <stdlib.h>
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
    char strings[25][80];
    //����,�����,��� ���,������,�������
    int day,mont,year,hour,minute,second;
    int n;//���-�� �����    
    //���� �����
    int i;
    for(i=0;i<25; i++){
        gets(strings[i]);
        if(strings[i][0]==0) break;
        sscanf(strings[i],"%d.%d.%d %d:%d:%d",
            &day,&mont,&year,&hour,&minute,&second);
        //���������� ����
        if((hour>23)||(minute>59)||(second>59)||
            (day>31)||(mont>12)){
            puts("ERROR");
            return 0;
        }
        if( ((day>28)&&(mont==2)) ||(( 
            (mont==4)||(mont==6)||(mont==9)
            ||(mont==11))&&day>30)){
            puts("ERROR");
            return 0;
        }  
        //������ ��� � ���� �������,
        //����� � ���������� �����������
        //2006.12.3 12:45:56 > 2005.12.4 12:45:56
        //� �� 4.12.2005 > 3.12.2006 12:45:56
        sprintf(strings[i],"%d.%d.%d %d:%d:%d",
          year,mont,day,hour,minute,second);
      
    }//for
    n=i;
    //��������� ������
    for(i=0; i<n; i++){
        for(int j=i; j<n;j++){
            if(strcmp(strings[i],strings[j])>0){
                char buf[80];
                strcpy(buf,strings[i]);
                strcpy(strings[i],strings[j]);
                strcpy(strings[j],buf);
            }//if
        }//for
    }//for
    //������ ����� ������ ��� � ���� �������
    //(���� ����� ������� � ������� �.�.� �:�:�)
    for(int i=0; i<n;i++){
        sscanf(strings[i],"%d.%d.%d %d:%d:%d",
            &year,&day,&mont,&hour,&minute,&second);
        sprintf(strings[i],"%d.%d.%d %d:%d:%d",
          day,mont,year,hour,minute,second);
    }
    //�����
    for(i=0; i<n;i++) 
        puts(strings[i]);

    return 0;
}

