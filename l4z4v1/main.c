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

int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
    int n,m;
    printf("Rasmery matricy: ");
    scanf("%d %d",&n,&m);
    if((n<=0)||(m<=0)){printf("\nError input\n"); return 2;}
    if((n<=0)||(m<=0)){printf("\nError input\n"); return 2;}
    int a[n][m];
    printf("Vvedite matrizy:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(scanf("%d",&a[i][j])<1){printf("\nError input\n");return 2;}
        }//for j
    }//for i
    int buf[n*m],res[n][m];
    int bufi=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            int min=a[i][j];
            for(int p=i; p<n; p++){
                for(int k=j; k<m;k++){
                    if(a[p][k]<min) min=a[p][k];
                } //for k
            }//for p
            buf[bufi]=min;
            bufi++;
        }//for j
    }//for i
    printf("\n");
    //Обнуляем res
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) res[i][j]=0;
    int i=0;
    int px=0,py=0;
    // N-Y M-X
    while((px<=m)&&(py<=n)){
        for(int j=px; j<m-px; j++){
            res[py][j]=buf[i];
            i++;
            if(i>=m*n) break;
        }
        for(int j=py+1; j<n-py; j++){
            res[j][m-px-1]=buf[i];
            i++;
            if(i>=m*n) break;
        }
        px++;
        for(int j=m-px-1; j>=px; j--){
            res[n-py-1][j]=buf[i];
            i++;
            if(i>=m*n) break;
        }
        py++;
        for(int j=n-py; j>=py; j--){
            res[j][px-1]=buf[i];
            i++;
            if(i>n*m) break;
        }
    }//while
    for(int i=0; i<n; i++){
        for(int j=0; j<m;j++) printf("%d\t",res[i][j]);
        printf("\n");
    }//for i
    return 0;
}

