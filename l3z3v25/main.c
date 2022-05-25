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
//����� ��������
int main(int argc, char *argv[])
{
    /* TODO: Enter code here */
    long int n,k,count=0;      
    scanf("%ld %ld",&n,&k);
    printf("Please wait...\n");
    //����� �� 1 �� 10^n 
    for(long int i=1; i<pow(10,n); i++){
        //����� ����, ������� �����
        long int summ=0,p=i; 
        for(long int j=0; j<=i;j++){
            summ+=p%10;   //��������� �����
            printf("\rj=%ld\ti=%ld",j,i);
            p/=10; //��������� ������
        }
        //����� ����� � �������� �����
        if(summ==k) count++; 
    }
    printf("\n%ld\n",count);
    return 0;
}

