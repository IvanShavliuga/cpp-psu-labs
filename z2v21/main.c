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
// ¬ариант 22 аналогично
int main(int argc, char *argv[])
{
  /* TODO: Enter code here */
  int n1,n2;
  char c,r;
  scanf("%c %d %d",c,&n1,&n2);
  switch(n1){
  case -1:
    switch(c) {
    case 'с': r='з'; break;
    case 'з': r='ю'; break;
    case 'ю': r='в'; break;
    case 'в': r='с'; break;
    }
    break;
  case 2:
    switch(c) {
    case 'с': r='ю'; break;
    case 'з': r='в'; break;
    case 'ю': r='с'; break;
    case 'в': r='з'; break;
    }
    break;
  case 1:
    switch(c) {
    case 'с': r='в'; break;
    case 'з': r='с'; break;
    case 'ю': r='з'; break;
    case 'в': r='ю'; break;
    }
    break; 

  }
  switch(n2){
  case -1:
    switch(r) {
    case 'с': r='з'; break;
    case 'з': r='ю'; break;
    case 'ю': r='в'; break;
    case 'в': r='с'; break;
    }
    break;
  case 2:
    switch(c) {
    case 'с': r='ю'; break;
    case 'з': r='в'; break;
    case 'ю': r='с'; break;
    case 'в': r='з'; break;
    }
    break;
  case 1:
    switch(c) {
    case 'с': r='в'; break;
    case 'з': r='с'; break;
    case 'ю': r='з'; break;
    case 'в': r='ю'; break;
    }
    break; 

  }
  printf("%c",r);
  return 0;
}

