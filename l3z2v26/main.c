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
#include <math.h>
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
    int year; //���
    scanf("%d",&year);
    year-=1984; // 1984 -- ������ �������
    int color = abs(year/12); // ������
    switch(color){
    case 0:  printf("������� ");   break;
    case 1:  printf("������� ");   break;
    case 2:  printf("������ ");    break;
    case 3:  printf("����� ");     break;
    case 4:  printf("������ ");    break;
    }
    int zver=abs(year%12); //��� �����
    switch(zver){
    case 0:  printf("�����\n");    break;
    case 1:  printf("������\n");   break;
    case 2:  printf("�����\n");    break;
    case 3:  printf("�����\n");    break;
    case 4:  printf("�������\n");  break;
    case 5:  printf("����\n");     break;
    case 6:  printf("������\n");   break;
    case 7:  printf("����\n");     break;
    case 8:  printf("��������\n"); break;
    case 9:  printf("������\n");   break;
    case 10: printf("������ \n");  break;
    case 11: printf("������\n");   break;
    }

    return 0;
}

