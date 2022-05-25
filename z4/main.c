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
    _cprintf("Laba 4 Zadatha 4 Variant 1");
    _clreol();
    _textcolor(15);
    _textbackground(4);
    _gotoxy(1,25);
    _clreol();
    _cprintf("Ivanov 06-IT-2  ");
    _textbackground(1);
    _gotoxy(1,2);
    _textcolor(14);
    int m, n;
    _cprintf("Vvedite rasmernost matrizy: ");
    _textcolor(15);
    _cscanf("%d %d",&n,&m);
    _textcolor(14);
    _gotoxy(1,3);
    _cprintf("Vvedite matrizu: ");
    _gotoxy(1,4);
    _textcolor(15);
    int a[m*n], b[n][m];
    unsigned int px=1,py=1,i=0;
    for(int y=0; y<n; y++) {
        _textcolor(y%2+11);
        for(int x=0; x<m; x++) {
            _gotoxy(x*5,y+4);
            _cscanf("%d",&b[y][x]);
            a[i]=b[y][x];
            i++;
        }
        _cprintf("\n");
    }
	for(i=0; i<n*m;i++){
		for(int j=i; j<n*m; j++){
			if(a[i]>a[j]){
				int buf=a[i];
				a[i]=a[j];
				a[j]=buf;
			}
		}
	}
	
	i=0;
    do {
        for(int x=px-1; x<=m-px; x++,i++){
            if(i>=n*m) break;
            b[py-1][x]=a[i];
        }
        for(int y=py; y<=n-py; y++,i++){
            if(i>=n*m) break;
            b[y][m-px]=a[i];
        }
        
        px++;
        for(int x=m-px; x>=px-1; x--,i++){
            if(i>=n*m) break;
            b[n-py][x]=a[i];
        }
        py++;
        for(int y=n-py+1; y>=py-1; y--,i++){
            if(i>=n*m) break;
            b[y][px-2]=a[i];
        }
    }while((px<m)&&(py<n)||(i<n*m));

    for(int y=0; y<n; y++) {
        _textcolor(y%2+11);
        for(int x=0; x<m; x++){
           _cprintf("%d\t",b[y][x]);
        }
        _cprintf("\n");
    }
    _textcolor(15);
     _gotoxy(1,24);
    return 0;
}

