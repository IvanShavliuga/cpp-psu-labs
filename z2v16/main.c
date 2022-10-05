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
//������� �������� ����������
int main(int argc, char *argv[])
{
  /* TODO: Enter code here */
  char a,b,c; // ����� ������� �������
  scanf("%c%c%c",&a,&b,&c);
  switch(a){
  case '1': printf("��� "); break;
  case '2': printf("������ "); break;
  case '3': printf("������ "); break;
  case '4': printf("��������� "); break;
  case '5': printf("������� "); break;
  case '6': printf("�������� "); break;
  case '7': printf("������� "); break;
  case '8': printf("��������� "); break;
  case '9': printf("��������� "); break;
  }
  switch(b){
  case '1': 
    switch(c){
    case '0': printf("������\n "); return 0;
    case '1': printf("�����������\n "); return 0;
    case '2': printf("���������� \n"); return 0;
    case '3': printf("����������\n "); return 0;
    case '4': printf("������������\n "); return 0;
    case '5': printf("���������� \n"); return 0;
    case '6': printf("�����������\n"); return 0;
    case '7': printf("���������� \n"); return 0;
    case '8': printf("������������ \n"); return 0;
    case '9': printf("������������\n"); return 0;
    }
    break;
  case '2': printf("�������� "); break;
  case '3': printf("�������� "); break;
  case '4': printf("����� "); break;
  case '5': printf("��������� "); break;
  case '6': printf("���������� "); break;
  case '7': printf("��������� "); break;
  case '8': printf("����������� "); break;
  case '9': printf("��������� "); break;
  }
  switch(c){
  case '1': printf("���� "); break;
  case '2': printf("��� "); break;
  case '3': printf("��� "); break;
  case '4': printf("������ "); break;
  case '5': printf("���� "); break;
  case '6': printf("�����"); break;
  case '7': printf("���� "); break;
  case '8': printf("������ "); break;
  case '9': printf("������"); break;
  }
  printf("\n");
  return 0;
}

