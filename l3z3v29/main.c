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
    long int n,k,count=0;      
    scanf("%ld %ld",&n,&k);
    for(long int i=0; i<pow(10,n); i++){
        int c=0,p=i,v=2;
        for(long int j=0; j<i;j++){
            int b=p%v;
            v*=2;
            printf("%d",b);
            if(b==0) c++;
        }
        if(c==k) count++;
        printf("\r");
    }
    printf("%ld\n",count);
    return 0;
}

