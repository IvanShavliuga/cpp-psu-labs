/****************************************************************************
 *                                                                          *
 * File    : main.c                                                            *
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
// ������� 22 ����������
int main(int argc, char *argv[])
{
  /* TODO: Enter code here */
  int n1,n2;
  char c,r;
  scanf("%c %d %d",c,&n1,&n2);
  switch(n1){
  case -1:
    switch(c) {
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    }
    break;
  case 2:
    switch(c) {
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    }
    break;
  case 1:
    switch(c) {
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    }
    break; 

  }
  switch(n2){
  case -1:
    switch(r) {
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    }
    break;
  case 2:
    switch(c) {
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    }
    break;
  case 1:
    switch(c) {
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    case '�': r='�'; break;
    }
    break; 

  }
  printf("%c",r);
  return 0;
}

