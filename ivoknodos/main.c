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
    _textbackground(1);
    _clrscr();
    _textcolor(15);
    _textbackground(4);
    _gotoxy(1,1);
    _cprintf("Laba 4 Zadatha 2 Variant 22");
    _clreol();
    _textcolor(15);
    _textbackground(4);
    _gotoxy(1,25);
    _clreol();
    _cprintf("Ivanov 06-IT-2  ");
    _textbackground(1);
    _gotoxy(1,2);
    _textcolor(14);
    _textcolor(15);
     _gotoxy(1,24);
    return 0;
}

